//
// Created by Kimberley on 11/13/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include "moves.h"

typedef struct s_node {
    t_move value; // Value of the current localisation
    int nbSons;
    struct s_node **sons;
    int depth;
    t_localisation pos; // position and orientation of the robot
} t_node, *p_node;

typedef  struct s_tree {
    p_node root;
} t_tree, *p_tree;

p_node createNode(int, int, int);

p_tree createEmptyTree();

void createTree(p_tree pt, int, int, int, int);

int calcDepth(p_tree);

void freeTree(p_tree);

#endif //UNTITLED1_TREE_H
