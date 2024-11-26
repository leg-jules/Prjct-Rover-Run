#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

t_move *removeFromList(int *list, t_move value, int len_list){
    t_move *new_list = (t_move *)malloc((len_list-1)*sizeof(t_move));
    int index = 0;
    for(int i = 0; i < len_list; i++){
        if(list[i] != value){
            new_list[index] = list[i];
            index++;
        }
    }
    return new_list;
}

t_node *createNode(int val, int mvt, int nd_sons, int* avails, int depth) {
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));

    new_node->value = val;
    new_node->id_mouvement = mvt;
    new_node->ndSons = nd_sons;
    new_node->sons = (t_node **)malloc(nd_sons*sizeof(t_node *));
    t_move *new_avails = removeFromList(avails, val, nd_sons);//on enlève le mouvement du noeud actuel (son id_mouvement) à sa liste
    new_node->avails = new_avails; //tous les choix possibles qui dépend du noeud parent de ce nouveau noeud (si noeud = racine, initialisation du robot, liste complète)
    new_node->depth = depth;

    for(int i = 0; i < nd_sons; i++){
        new_node->sons[i]=NULL;
    }
    return new_node;
}

t_tree createNTree(t_node* node, int size, t_localisation loc, t_map map) {
    if (node->depth < 5) {
        int i;
        for (i = 0; i < node->ndSons; i++) {
            t_move *new_avails = removeFromList(node->avails, node->avails[i], node->ndSons);
            t_node *new_son = createNode(node->avails[i], node->avails[i], node->ndSons - 1 , new_avails, node->depth + 1);
            node->sons[i] = new_son;
            createNTree(new_son, node->depth + 1, loc, map);
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
    printf(" Valeur %d | tation \n", node->value);

    char new_prefix[256];
    int index = 0;


    for (int i = 0; prefix[i] != '\0'; i++) {
        new_prefix[index++] = prefix[i];
    }

    if (depth != 0) {
        new_prefix[index++] = '|';
        new_prefix[index++] = ' ';
        new_prefix[index++] = ' ';
        new_prefix[index++] = ' ';
    }

    new_prefix[index] = '\0';

    for (int i = 0; i < node->ndSons; i++) {
        printNode(node->sons[i], depth + 1, new_prefix);
    }
}

void printNTree(t_node *node, int depth) {
    printNode(node, depth, "");
}



//TROUVER VALEUR DU NODE MINIMUM DANS L'ARBRE POUR SAVOIR SI LA BASE ETE ATTEINTE

t_node* findMinimumNode(t_node* node) {
    if (node == NULL) return NULL;

    t_node* min_node = node;

    for (int i = 0; i < node->ndSons; i++) {
        t_node* child_min_node = findMinimumNode(node->sons[i]);
        if (child_min_node != NULL && child_min_node->value < min_node->value) {
            min_node = child_min_node;
        }
    }

    return min_node;
}

void minimumNode(t_tree tree) {
    if (tree.root == NULL) {
        printf("L'arbre est vide\n");
        return;
    }
    t_node* min_node = findMinimumNode(tree.root);
    if (min_node != NULL) {
        printf("La valeur minimale de l'arbre : %d\n", min_node->value);
    } else {
        printf("L'arbre est vide\n");
    }
}
