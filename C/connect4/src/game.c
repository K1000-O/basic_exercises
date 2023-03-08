/**
 * @file game.c
 * @author Camilo Jené Conde
 * @brief Juego de conecta 4.
 * Requisitos:
        - Tablero de 7x6 (7 en el eje "x" y 6 en el "y").
        - Fichas Rojas y Amarillas. La primera partida la comienza siempre la Roja (la segunda la Amarilla, la tercera la Roja...).
        - No hay que implementar una funcionalidad que te permita jugar contra la App. Se asume que jugarán dos personas reales alternándose.
        - Al seleccionar la columna se coloca la ficha en la parte inferior.
        - Guardar el número partidas ganadas de cada equipo mientras la App no se finaliza.
        - Dos botones para reiniciar la partida en marcha y para resetear el contador de victorias y derrotas.
        - Puedes añadirle todas las funcionalidades extra que consideres.
 * @version 0.2.0
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../includes/player.h"
#include "../includes/types.h"

#define WIDTH 7
#define HEIGHT 6

#define RED 'X'
#define WHITE 'O'

typedef struct {
    Player * player1;
    Player * player2;

    char board[HEIGHT][WIDTH];

    Bool gameEnded;
    int gameNumber;
} Game;

Game * game_create();
status game_destroy(Game * game);
status game_restartGame(Game * game);
Bool game_iniBoard(Game * game); 
Bool game_insertMove(Game * game, int decision, int player);
Bool game_checkWin(Game * game, Player * player, int decision);
Bool check(Game* game, Player * player, int x, int y, int contador, int condicion);
status board_print(FILE* pf, Game * game);

int main(int argv, char** args) {
    int decision = -1;
    int turno = 1;
    int playerTurn = -1;

    Game * game = game_create();
    if (!game) {
        return -1;
    }

    do {
        board_print(stdout, game);

        if (decision != -1) {
            fprintf(stdout, "\n>> Last decision: %d\n\n", decision);
        }

        playerTurn = (turno + game->gameNumber) % 2;
    
        fprintf(stdout, "Player %d choose:\n", playerTurn+1);
        fprintf(stdout, "Introduce una columna del 1 al %d, donde quieras colocar tu ficha.\nIntroduce '0' para salir.\n", WIDTH);
        
        scanf("%d", &decision);
        if (decision == 0) {break;}
        if (decision < 1 && decision > WIDTH) {continue;}
    
        if (playerTurn == 0) {
            if (game_insertMove(game, decision, 1)) {
                if (!game_checkWin(game, game->player1, decision-1))
                    turno++;
                else {
                    player_setWins(game->player1, player_getWins(game->player1)+1);
                    turno = game_restartGame(game);
                }
            }
        } else {
            if (game_insertMove(game, decision, 2)) {
                if (!game_checkWin(game, game->player2, decision-1))
                    turno++;
                else {
                    player_setWins(game->player2, player_getWins(game->player2)+1);
                    turno = game_restartGame(game);
                }
            }
        }

    } while(True);

    game_destroy(game);

    return 1;
}

Game * game_create() {
    Game * g = malloc (sizeof(Game));
    if (!g){
        fprintf(stderr, ">> game_create: error on the game creation.");
        return NULL;
    }

    g->player1 = player_create(0, "FirstPlayer", RED);
    g->player2 = player_create(1, "SecondPlayer", WHITE);
    if (!g->player1 || !g->player2) {
        fprintf(stderr, ">> game_create: error on the player insertion.");
        free(g);
        return NULL;
    }

    g->gameEnded = False;
    g->gameNumber = 1;

    /*
        Inicializamos los espacios en vacío.
    */
    game_iniBoard(g);
    
    return g;
}

status game_destroy(Game * game) {
    if (game) {
        player_destroy(game->player1);
        player_destroy(game->player2);
        
        free(game);
    }

    return OK;
}

Bool game_iniBoard(Game * game) {
    if (!game) {
        return False;
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            sprintf(&game->board[i][j], " ");
        }
    }

    return True;
}

status game_restartGame(Game * game) {
    game->gameNumber++;
    game_iniBoard(game);

    return OK;
}

Bool game_insertMove(Game * game, int decision, int player) {
    for (int i = HEIGHT-1; i >= 0; i--) {
        if (game->board[i][decision-1] != 'X' && game->board[i][decision-1] != 'O'){
            if (player == 1)
                game->board[i][decision-1] = player_getMark(game->player1);
            else if (player == 2)
                game->board[i][decision-1] = player_getMark(game->player2);

            return True;
        }
    }

    return False;
}

Bool game_checkWin(Game * game, Player * player, int decision) {
    int contador = 0;
    if (!game || !player)
        return False;

    for (int i = HEIGHT-1; i >= 0; i--) {
        if (game->board[i][decision] == player_getMark(player)) {
            for (int j = 0; j < 8; j++) {
                contador = 1;
                switch (j) {
                    case 0:
                        if (i-1 != -1 && decision-1 > -1) {
                            if (check(game, player, i-1, decision-1, contador, 0))
                                return True;
                            }

                            break;

                    case 1:
                        if (i-1 != -1) {
                            if (check(game, player, i-1, decision, contador, 1))
                                return True;
                            }

                            break;
                    
                    case 2:
                        if (i-1 != -1 && decision+1 < WIDTH) {
                            if (check(game, player, i-1, decision+1, contador, 2))
                                return True;
                            }

                            break;
                    
                    case 3:
                        if (decision+1 < WIDTH) {
                            if (check(game, player, i, decision+1, contador, 3))
                                return True;
                            }

                            break;
                    
                    case 4:
                        if (i+1 < HEIGHT && decision+1 < WIDTH) {
                            if (check(game, player, i+1, decision+1, contador, 4))
                                return True;
                            }

                            break;

                    case 5:
                        break; // No hace falta comprobarlo. El algoritmo lo hace de arriba a abajo.
                    
                    case 6:
                        if (i+1 < HEIGHT && decision-1 > -1) {
                            if (check(game, player, i+1, decision-1, contador, 6))
                                return True;
                            }

                            break;
                    
                    case 7:
                        if (decision-1 > -1) {
                            if (check(game, player, i, decision-1, contador, 7))
                                return True;
                            }

                            break;
                }
            }
        }
    }
    
    return False;
}

Bool check(Game* game, Player * player, int i, int decision, int contador, int condicion) {
    if (game->board[i][decision] == player_getMark(player)) contador++;
    else return False;

    if (contador == 4) return True;

    switch (condicion) {
        case 0:
            if (i-1 != -1 && decision-1 > -1) {
                if (check(game, player, i-1, decision-1, contador, 0))
                    return True;
            }

            break;

        case 1:
            if (i-1 != -1) {
                if (check(game, player, i-1, decision, contador, 1))
                    return True;
            }

            break;
        
        case 2:
            if (i-1 != -1 && decision+1 < WIDTH) {
                if (check(game, player, i-1, decision+1, contador, 2))
                    return True;
            }

            break;
        
        case 3:
            if (decision+1 < WIDTH) {
                if (check(game, player, i, decision+1, contador, 3))
                    return True;
            }

            break;
        
        case 4:
            if (i+1 < HEIGHT && decision+1 < WIDTH) {
                if (check(game, player, i+1, decision+1, contador, 4))
                    return True;
            }

            break;

        case 5:
            break; // No hace falta comprobarlo. El algoritmo lo hace de arriba a abajo.
        
        case 6:
            if (i+1 < HEIGHT && decision-1 > -1) {
                if (check(game, player, i+1, decision-1, contador, 6))
                    return True;
            }

            break;
        
        case 7:
            if (decision-1 > -1) {
                if (check(game, player, i, decision-1, contador, 7))
                    return True;
            }

            break;
    }

    return False;
}

status board_print(FILE* pf, Game * game) {
    if (!game->board || !pf) {
        fprintf(stderr, ">> board_print: error on the board data print.");
        return ERROR;
    }

    system("clear");

    fprintf(stdout, "Jugadores\tNombre\tVictorias\n");
    fprintf(stdout, "1\t%s\t%d\n", player_getName(game->player1), player_getWins(game->player1));
    fprintf(stdout, "2\t%s\t%d\n", player_getName(game->player2), player_getWins(game->player2));

    fprintf(stdout, "\n## GAME Nº %d ##\n", game->gameNumber);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(pf, "[%c]", game->board[i][j]);
        }
        fprintf(stdout, "\n");
    }

    return OK;
}