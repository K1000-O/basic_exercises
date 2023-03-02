/**
 * @file node.h
 * @author Camilo Jené Conde
 * @brief 
 * @version 0.1
 * @date 2023-03-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef NODE_H
#define NODE_H
#include "types.h"

/**
 * @brief Node structure. It receives two datas:
 *  1. The id of the node.
 *  2. The name of the node.
 * 
 */
typedef struct node Node;

/**
 * @brief Create a Node object
 * 
 * @author Camilo Jené Conde
 * 
 * @param id id of the new node.
 * @return Node*
 */
Node* node_create(int id);

/**
 * @brief Method that liberates all the reserved space of Node.
 * 
 * @param n node to free.
 * @return status 
 */
status node_destroy(Node * n);

/**
 * @brief set de name of the node.
 * 
 * @author Camilo Jené Conde
 * 
 * @param n node to work with.
 * @param name name to set
 * 
 * @return status 
 */
status node_setName(Node* n, char * name);

/**
 * @brief Meethod that prints the node info.
 * 
 * @author Camilo Jené Conde
 * 
 * @param pf file where we print the info.
 * @param n node to print.
 * @return int 
 */
int node_print(FILE * pf, Node * n);

#endif