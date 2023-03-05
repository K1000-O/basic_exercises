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
Bool game_insertMove(Game * game, int decision, int player);
status board_print(FILE* pf, Game * game);

int main(int argv, char** args) {
    int decision = -1;
    int turno = 1, i = -1;

    Game * game = game_create();
    if (!game) {
        return -1;
    }

    do {
        if (decision != -1) {
            fprintf(stdout, ">> Last decision: %d\n", decision);
        }

        board_print(stdout, game);
        fprintf(stdout, "Introduce una columna del 1 al %d, donde quieras colocar tu ficha.\nIntroduce '0' para salir.\n", WIDTH);
        
        scanf("%d", &decision);
        if (decision == 0) {break;}
        if (decision < 1 && decision > WIDTH) {continue;}
    
        if ((turno + game->gameNumber) % 2 == 1) {
            if (game_insertMove(game, decision, 1))
                turno++;
        } else {
            if (game_insertMove(game, decision, 2))
                turno++;
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
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            sprintf(&g->board[i][j], " ");
        }
    }
    
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

Bool check_win(char** board) {
    return True;
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

status board_print(FILE* pf, Game * game) {
    if (!game->board || !pf) {
        fprintf(stderr, ">> board_print: error on the board data print.");
        return ERROR;
    }

    system("clear");

    fprintf(stdout, "## GAME Nº %d ##\n", game->gameNumber);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(pf, "[%c]", game->board[i][j]);
        }
        fprintf(stdout, "\n");
    }

    return OK;
}