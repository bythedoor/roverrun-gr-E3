//
// Created by elias on 12/11/2024.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H
#include <stdio.h>
#include <stdlib.h>
#include "loc.h"

typedef struct s_node{
    int value;   //valeur du noeud cad la valeur de la case sur laquelle est le robot
    int depth;   //profondeur du noeud
    struct s_node **sons;
    int nbSons;  //nb de possibilités de mouvement suivant
    t_localisation localisation;
    struct s_node* parent;

}t_node;

t_node *createNode(int nb_sons, int depth, t_localisation localisation);

#endif //UNTITLED1_NODE_H
