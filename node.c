//
// Created by elias on 12/11/2024.
//
#include "node.h"

t_node *createNode(int nb_sons, int depth, t_localisation localisation){

    t_node *new_node;
    new_node = (t_node *)malloc(sizeof (t_node));
    new_node->nbSons = 0;
    new_node->sons = NULL;
    new_node->localisation = localisation;
    return new_node;
}
