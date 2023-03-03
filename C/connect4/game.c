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
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "types.h"

#define WIDTH 7
#define HEIGHT 6

typedef struct {
    Player * player1; // Crear Player
    Player * player2;

    int p1Wins; // Puede ir en la estructura del player.
    int p2Wins;

    Bool gameEnded;
} Game;

int main(int argv, char** args) {
    char board[WIDTH][HEIGHT];

    return 1;
}

Game * game_create() {
    Game * g = malloc (sizeof(Game));
    if (!g){
        fprintf(stderr, ">> game_create: error on the game creation.");
        return NULL;
    }

    // Inicializar los valores del juego.

    return g;
}

status board_print(FILE* pf, char** board) {
    if (!board || !pf) {
        fprintf(stderr, ">> board_print: error on the board data print.");
        return ERROR;
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(pf, "[%c]", board[i][j]);
        }
    }

    return OK;
}