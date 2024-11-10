//
// Created by legal on 01/11/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#define MAX_CHILDREN 5 //pour le moment, à mettre à 9 pour plus tard

typedef struct s_node { //noeud
    int value;
    int depth;
    int nbSons;
    int availableSons; //tab de possibilité
    struct s_node **sons; //changer max_children après
} t_node;

typedef struct tree { // arbre
    t_node *root;
} t_tree;

////fonctions de noeud

t_node* createNode(int value, int depth, int nbSons);

void freeNode(t_node *root);
//void addChild(t_node *parent, t_node *child);
//t_node *minCostWay(t_node *root, int *minCost);
//t_node printNode(t_node node);

////fonctions d'arbre
//t_tree createTree();

void freeTree(t_tree *tree);

int* availsMinParent(int* list, int size, int val);

//void printTree(t_tree tree);

#endif //UNTITLED1_TREE_H
