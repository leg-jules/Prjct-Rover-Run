//
// Created by legal on 01/11/2024.
//

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int moveToDoleft = 5;

void freeNode(t_node *root){
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->nbSons; i++)
    {
        freeNode(root->sons[i]);
    }
    free(root->sons);
    free(root);
    printf("Node freed successfully \n");
}

int* availsMinParent(int* list, int size, int val) {
    int *newList = (int *) malloc(size * sizeof(int));
    if (newList == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        return NULL;
    }
    int j = 0;
    for (int i = 0;
         i < size;
         i++) {
        if (list[i] != val) {
            newList[j] = list[i];
            j++;
        }
    }
    return newList;
}

t_node* createNode(int value, int depth, int nbSons){
    t_node *node = (t_node*)malloc(sizeof(t_node));
    if (node == NULL) //libère l'espace si la création du noeud échoue
    {
        printf("Erreur d'allocation de mémoire\n");
        return NULL;
    }

    node->value = value;
    node->depth = depth;
    node->nbSons = nbSons;
    node->sons = (t_node**)malloc(nbSons * sizeof(t_node*));
    int* new_avails = availsMinParent(node->sons, nbSons, value);
    node->availableSons = *new_avails;
    if (node->sons == NULL)    //libère l'espace si la création des fils échoue
    {
        free(node);
        return NULL;
    }
    for (int i = 0; i < nbSons; i++) {
        node->sons[i] = NULL;
    }
    return node;
}

void freeTree(t_tree *tree) {
    if (tree == NULL) {
        printf("Tree is NULL\n");
        return;
    }
    else{
        freeNode(tree->root);
        free(tree);
        printf("Tree freed\n");
    }
    printf("Tree freed failed\n");
}
