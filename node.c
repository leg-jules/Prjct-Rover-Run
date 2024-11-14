
#include "node.h"
#include <stdlib.h>
#include "tree.h"




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

