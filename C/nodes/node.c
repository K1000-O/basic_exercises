#include "node.h"

struct node{
    int id;
    char* name;
};

Node * node_create(int id) {
    Node * n = malloc(sizeof(Node));

    if (!n)
        return NULL;

    n->id = id;
    n->name = (char*) calloc (32, sizeof(char)); /* calloc -> so it initializes and gives no error on test.*/

    if (!n->name) {
        free(n);
        return NULL;
    }

    return n;
}

status node_destroy(Node * n) {
    if (n) {
        free(n->name);
        free(n);
    }

    return OK;
}

status node_setName(Node* n, char* name) {
    if (!n)
        return ERROR;

    strcpy(n->name, name);

    return OK;
}

int node_print(FILE * pf, Node * n) {
    if (!pf || !n)
        return -1;

    return fprintf(pf, "[%d, %s]\n", n->id, n->name);
}

