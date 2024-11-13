//
// Created by Kimberley on 11/13/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/**
 * @brief Function to create a node
 * @param val : the value contained in the node
 * @param nb_sons : the number of sons the node will have
 * @return pointer to the new node
 */
p_node createNode(int val, int nb_sons, int depth)
{
    p_node new_node;
    new_node = (p_node)malloc(sizeof (t_node));
    new_node->value = val;
    new_node->nbSons = nb_sons;
    new_node->depth = depth;
    new_node->sons = (p_node*)malloc(nb_sons*sizeof(t_node*));

    for (int i=0; i<nb_sons; i++)
    {
        new_node->sons[i] = NULL;
    }

    return new_node;
}

/**
 * @brief Function to create an empty tree
 * @return pointer to the empty tree
 */
p_tree createEmptyTree(){
    p_tree new_tree = (p_tree)malloc(sizeof(t_tree));
    new_tree->root = NULL;
    return new_tree;
}

void createTree(p_tree pt, int val, int nbSons, int depth, int moves) {
    p_node pn = createNode(val, nbSons, depth);
    pt->root = pn;
}