
#ifndef NODE_H
#define NODE_H

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

#endif //NODE_H
