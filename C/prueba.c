#include "node.h"

status free_all(Node ** nT) {
    for (int i = 0; i < 5; i++) {
        node_destroy(nT[i]);
    }

    free(nT);

    return OK;
}

int main() {
    Node** nT = malloc(5*sizeof(Node*));

    for (int i = 0; i < 5; i++) {
        nT[i] = node_create(i);
    }

    for (int i = 0; i < 5; i++) {
        node_print(stdout, nT[i]);
    }

    return free_all(nT);
}