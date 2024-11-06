//
// Created by legal on 01/11/2024.
//

#include "tree.h"
#include <stdlib.h>

int moveToDoleft = 5;

t_node* createNode(int value, int depth, int nbSons){
    t_node *node = (t_node*)malloc(sizeof(t_node));
    node->value = value;
    node->depth = depth;
    node->nbSons = nbSons;
    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        node->sons[i] = NULL;
    }
    return node;
}

//fonction noeud----------------------------------------------------------------------------------------------------------------

void addChild(t_node *parent, t_node *child);
t_node *minCostWay(t_node *root, int *minCost);
void freeNode(t_node *root);
t_node printNode(t_node node);

//fonction arbre----------------------------------------------------------------------------------------------------------------

t_tree createTree(){
    t_tree tree;
    tree.root = NULL;
    return tree;
}

void freeTree(t_tree *tree);

void printTree(t_tree tree);