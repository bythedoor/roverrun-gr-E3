//
// Created by Kimberley on 11/20/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "node.h"


/**
 * @brief Function to create a node
 * @param val : the value contained in the node
 * @param nb_sons : the number of sons the node will have
 * @return pointer to the new node
 */
p_node createNode(int nb_sons, int depth, t_localisation localisation)
{
    p_node newNode = (p_node)malloc(sizeof(t_node));
    newNode->nbSons = 3;
    newNode->depth = 0;
    newNode->sons = (p_node)malloc(sizeof(p_node) * newNode->nbSons);
    newNode->parent = NULL;
    return newNode;
}

