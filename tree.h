
#ifndef TREE_H
#define TREE_H

typedef struct s_node
{
    int value;
    int id_mouvement;
    int depth;
    struct s_node **sons; //tableau de pointeur
    int ndSons; //taille physique du tableau
    int *avails; //choix restants du noeud
}t_node;

int *removeFromList(int*, int, int);
t_node *createNode(int val, int mvt, int nd_sons, int* list_choix, int depth);



typedef struct n_tree {
    t_node* root;
} t_tree;

t_tree createNTree(t_node *node); // A modifier : Changer la fonction pour insertIntoNTree
void printNTree(t_tree tree);


#endif //TREE_H