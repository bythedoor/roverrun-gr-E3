//
// Created by Kimberley on 11/13/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include "node.h"

typedef  struct s_tree {
    p_node root;
} t_tree, *p_tree;

int** chooseRandMoves(int);

t_tree createEmptyTree();

void createTree(p_tree pt, int, int, int, int);

p_node findBestWay(p_tree, p_node);

void freeTree(p_tree);

#endif //UNTITLED1_TREE_H
