//
// Created by legal on 01/11/2024.
//

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void freeNode(t_node *root){
    if (root == NULL)
    {
        printf("Node is NULL\n");
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

t_node* createNode(int value, int depth, int nbSons, int* avails) {
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
    node->availableSons = new_avails;
    if (node->sons == NULL)    //libère l'espace si la création des fils échoue
    {
        free(node);
        return NULL;
    }
    for (int i = 0; i < nbSons; i++) {
        node->sons[i] = NULL;
    }
    for(int i = 0; i < nbSons; i++){
        printf("Node[] : %d\n",new_avails[i]);
    }
    return node;
}

t_tree createNTree(t_node* node) {

    if (node->depth < 5) {
        int i;
        for (i = 0; i < node->nbSons; i++) {
            printf("Node[] : %d\n",node->value);
            t_node *new_son = createNode(node->availableSons[i], node->depth + 1, node->nbSons, node->availableSons);
            node->sons[i] = new_son;
            createNTree(new_son);
        }
    }

    t_tree tree;
    tree.root = node;
    return tree;
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

//void printNTree(t_tree tree) {
//    if (tree.root == NULL) return;
//
//    printf("Node = %d\n",tree.root->value);
//
//    // Indenter en fonction de la profondeur actuelle
//    for (int i = 0; i < tree.root->depth; i++) {
//        printf("ball\n");
//        printf("    ");  // Ajoute 4 espaces pour chaque niveau de profondeur
//    }
//
//    // Afficher récursivement chaque enfant avec une profondeur augmentée
//    for (int i = 0; i < tree.root->nbSons; i++) {
//        t_tree new_tree;
//        new_tree.root = tree.root->sons[i];
//        printNTree(new_tree);
//    }
//}
void printNTree(t_tree tree) {
    if (tree.root == NULL) return;  // Si l'arbre est vide, ne rien afficher

    // Affiche le nœud courant
    printf("Node = %d\n", tree.root->value);

    // Vérifie s'il y a des enfants pour ce nœud
    if (tree.root->nbSons > 0) {
        printf("Children of %d: ", tree.root->value);
        for (int i = 0; i < tree.root->nbSons; i++) {
            printf("%d ", tree.root->sons[i]->value);
        }
        printf("\n");
    } else {
        printf("Leaf node: No children\n");
    }

    // Appelle récursivement cette fonction pour chaque enfant
    for (int i = 0; i < tree.root->nbSons; i++) {
        t_tree childTree;
        childTree.root = tree.root->sons[i];
        printNTree(childTree);  // Appelle récursive pour afficher les enfants
    }
}