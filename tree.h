//
// Created by legal on 01/11/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#define MAX_CHILDREN 4 //pour le moment, à mettre à 9 pour les 8 directions + la position actuelle mais plus tard

typedef struct s_treeNode {
    int Cost;
    struct s_treeNode *children[MAX_CHILDREN];
    int nbChildren;
} t_treeNode;

t_treeNode* createNode(int cost);
void addChild(t_treeNode *parent, t_treeNode *child);
t_treeNode *minCostWay(t_treeNode *root, int *minCost);
void freeTree(t_treeNode *root);

#endif //UNTITLED1_TREE_H
