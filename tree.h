
#ifndef TREE_H
#define TREE_H

#include "moves.h"
#include "loc.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
    int value;
    int id_mouvement;
    int depth;
    struct s_node **sons; //tableau de pointeur
    int ndSons; //taille physique du tableau
    t_move *avails; //choix restants du noeud
    t_localisation loc;
    struct s_node *parent;
    int tot_cost;
}t_node;

t_move *removeFromList(int *list, t_move value, int len_list);
t_node *createNode(int val, int mvt, int nd_sons, int* avails, int depth, t_localisation loc);


typedef struct n_tree {
    t_node *root;
} t_tree;

t_tree createNTree(t_node *node,int depth, t_localisation loc,
                       t_map); // A modifier : Changer la fonction pour insertIntoNTree
//void printNTree(t_tree tree);
void addChild(t_node *parent, t_node *child);

void printNTree(t_node *node, int level);

void exploreNTree(t_tree tree);
void findMinCostPath(t_node *node, int current_cost, int *min_cost, t_node **min_path, int *path_length,
                         t_node **current_path, t_move *current_moves, int depth);


#endif //TREE_H
