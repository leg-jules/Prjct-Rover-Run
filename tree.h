
#ifndef TREE_H
#define TREE_H
#include "node.h"

typedef struct n_tree {
    t_node* root;
} t_tree;


t_tree createNTree(t_node *node); // A modifier : Changer la fonction pour insertIntoNTree
void printNTree(t_tree tree);


#endif //TREE_H