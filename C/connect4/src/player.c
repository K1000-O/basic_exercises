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