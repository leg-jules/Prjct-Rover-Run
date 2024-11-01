//
// Created by legal on 01/11/2024.
//

#include "tree.h"

t_treeNode* createNode(int cost);
void addChild(t_treeNode *parent, t_treeNode *child);
t_treeNode *minCostWay(t_treeNode *root, int *minCost);
void freeTree(t_treeNode *root);

