
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


t_tree createNTree(t_node* node) {
    /**
     * @brief fonction récursive qui créée un arbre à partir du noeud racine
     * chaque nouveau étage de noeud possède une nouvelle liste avails qui correspond aux choix possibles
     * @param node : noeud
     * pour l'instant, les noeuds auront la valeur de l'id mouvement
     * créer à une depth plus grande que 3 fait cracher l'affichage :((
     */
     if (node->depth < 5) {
         int i;
         for (i = 0; i < node->ndSons; i++) {
             t_node *new_son = createNode(node->avails[i], node->avails[i], node->ndSons - 1 , node->avails, node->depth + 1);
             node->sons[i] = new_son;
             createNTree(new_son);
         }
     }

    t_tree tree;
    tree.root = node;
    return tree;
}

void printNTree(t_tree tree) {
    if (tree.root == NULL) return;

    printf("%d",tree.root->ndSons);

    // Indenter en fonction de la profondeur actuelle
    for (int i = 0; i < tree.root->depth; i++) {
        printf("    ");  // Ajoute 4 espaces pour chaque niveau de profondeur
    }

    // Afficher l'id_mouvement du nœud
    printf("Node ID: %d\n", tree.root->id_mouvement);

    // Afficher récursivement chaque enfant avec une profondeur augmentée
    for (int i = 0; i < tree.root->ndSons; i++) {
        t_tree new_tree;
        new_tree.root = tree.root->sons[i];
        printNTree(new_tree);
    }
}