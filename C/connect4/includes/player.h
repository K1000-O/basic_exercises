#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

/**
 * @brief Structure of the player. Contains:
 *      - Name.
 *      - Number of identification.
 *      - Nº of wins.
 * 
 */
typedef struct _Player Player;

/**
 * @brief Player constructor.
 * 
 * @param id id of the player.
 * @param name name of the player.
 * @return Player* 
 */
Player * player_create(int id, char* name, char mark);


#endif