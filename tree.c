#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//fonction pour enlever un élément d'une liste
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

//fonction pour créer un noeud
t_node *createNode(int val, int mvt, int nd_sons, int* avails, int depth, t_localisation loc){
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));

    new_node->value = val;
    new_node->id_mouvement = mvt;
    new_node->ndSons = nd_sons;
    new_node->sons = (t_node **)malloc(nd_sons*sizeof(t_node *));
    t_move *new_avails = removeFromList(avails, val, nd_sons);//on enlève le mouvement du noeud actuel (son id_mouvement) à sa liste
    new_node->avails = new_avails; //tous les choix possibles qui dépend du noeud parent de ce nouveau noeud (si noeud = racine, initialisation du robot, liste complète)
    new_node->depth = depth;
    new_node->loc = loc;

    for(int i = 0; i < nd_sons; i++){
        new_node->sons[i]=NULL;
    }
    return new_node;
}

//fonction pour créer un arbre n-aire
t_tree createNTree(t_node* node, int depth, t_localisation loc, t_map map) {
    if(node == NULL){
        printf("Node is NULL\n");
    };
    if (node->depth < 5) {
        for (int i = 0; i < node->ndSons; i++) {
            t_localisation new_loc = loc;
            switch (node->avails[i]) {
                case F_10:
                    break;
                case F_20:
                    break;
                case F_30:
                    break;
                case B_10:
                    break;
                case T_LEFT:
                    break;
                case T_RIGHT:
                    break;
                case U_TURN:
                    break;
            }
            t_move *new_avails = removeFromList(node->avails, node->avails[i], node->ndSons);
            t_node *new_son = createNode(node->avails[i], node->avails[i], node->ndSons - 1 , new_avails, node->depth + 1, loc);
            node->sons[i] = new_son;
            createNTree(new_son, node->depth + 1, loc, map);
        }
    }

    t_tree tree;
    tree.root = node;

    return tree;
}

//fonction pour ajouter un fils à un noeud
void printNode(t_node* node, int depth, char* prefix) {
    if (depth >= 4) return;

    printf("%s", prefix);
    printf("%s", (depth == 0) ? "" : "|");
    for (int i = 0; i < depth; i++) {
        printf("-");
    }
    printf(" Valeur : %d | Position : (%d, %d) | Orientation : %c \n",
           node->value, node->loc.pos.x, node->loc.pos.y, getOriAsString(node->loc.ori));


    char new_prefix[256];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, (depth == 0) ? "" : "|   ");

    for (int i = 0; i < node->ndSons; i++) {
        printNode(node->sons[i], depth + 1, new_prefix);
    }
}

//fonction pour afficher un arbre n-aire
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

//fonction pour trouver le noeud minimum de l'arbre
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
