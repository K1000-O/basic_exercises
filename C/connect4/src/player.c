/**
 * @file player.c
 * @author Camilo Jené Conde
 * @brief File that controls all the functionality given by the player to
 * the game.
 * @version 0.0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../includes/player.h"

#define TAM 32

struct _Player {
    char* name;
    int id;
    int wins;

    char mark;
};

Player * player_create(int id, char* name, char mark) {
    Player* p = malloc (sizeof(Player));
    if (!p) {
        fprintf(stderr, ">> player_create: error on the player creation,");
        return NULL;
    }

    p->id = id;
    p->name = name;
    p->wins = 0;
    p->mark = mark;

    return p;
}

status player_destroy(Player * player) {
    if (player){
        free(player);
    }

    return OK;
}

char player_getMark(Player * player) {
    return player->mark;
}

char* player_getName(Player * player) {
    return player->name;
}

int player_getWins(Player * player) {
    return player->wins;
}

void player_setWins(Player * player, int wins) {
    player->wins = wins;
}