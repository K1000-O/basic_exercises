#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

/**
 * @brief Structure of the player. Contains:
 *      - Name.
 *      - Number of identification.
 *      - Nº of wins.
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

/**
 * @brief Free the reserved memory for the player.
 * 
 * @param player player from we free the space.
 * @return status 
 */
status player_destroy(Player * player);

/**
 * @brief Getter of the player's mark.
 * 
 * @param player player to get the mark.
 * @return char 
 */
char player_getMark(Player * player);

/**
 * @brief Getter of the player's name.
 * 
 * @param player player to get the name.
 * @return char* 
 */
char* player_getName(Player * player);

/**
 * @brief Getter of the player's wins.
 * 
 * @param player player to get the number of wins.
 * @return int
 */
int player_getWins(Player * player);

/**
 * @brief Setter of the player wins.
 * 
 * @param player player who won.
 * @param wins number of wins.
 */
void player_setWins(Player * player, int wins);

#endif