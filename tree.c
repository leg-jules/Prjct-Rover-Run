#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int *removeFromList(int *list, int val, int len_list){

    int* new_list = (int*)malloc(sizeof(int)*(len_list - 1));
    int i, j;
    j = 0;
    for (i = 0; i <= len_list; i++) {
        if (val != list[i]) {
            new_list[j] = list[i];
            j++;
        }
    }
    return new_list;
}


t_node *createNode(int val, int mvt, int nd_sons, int* list_choix, int depth) {
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));

    new_node->value = val;
    new_node->id_mouvement = mvt;
    new_node->ndSons = nd_sons;
    new_node->sons = (t_node **)malloc(nd_sons*sizeof(t_node *));
    int *new_avails = removeFromList(list_choix, val, nd_sons);//on enlève le mouvement du noeud actuel (son id_mouvement) à sa liste
    new_node->avails = new_avails; //tous les choix possibles qui dépend du noeud parent de ce nouveau noeud (si noeud = racine, initialisation du robot, liste complète)
    new_node->depth = depth;

    for(int i = 0; i < nd_sons; i++){
        new_node->sons[i]=NULL;
    }
    return new_node;
}




t_tree createNTree(t_node* node) {

    if (node->depth < 5) {
        int i;
        for (i = 0; i < node->ndSons; i++) {
            t_node *new_son = createNode(node->avails[i], node->avails[i], node->ndSons - 1 , node->avails, node->depth + 1);
            node->sons[i] = new_son;
            createNTree(new_son);
        }
    }

    t_tree tree;
    tree.root = node;
    return tree;
}



void printNode(t_node* node, int depth, char* prefix) {
    if (depth >= 4) return;

    printf("%s", prefix);
    printf("%s", (depth == 0) ? "" : "|");
    for (int i = 0; i < depth; i++) {
        printf("-");
    }
    printf(" Valeur du Node %d\n", node->value);

    char new_prefix[256];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, (depth == 0) ? "" : "|   ");

    for (int i = 0; i < node->ndSons; i++) {
        printNode(node->sons[i], depth + 1, new_prefix);
    }
}

void printNTree(t_tree tree) {
    if (tree.root == NULL) return;
    printNode(tree.root, 0, "");
}
