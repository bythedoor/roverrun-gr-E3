//
// Created by Kimberley on 11/13/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include "node.h"

typedef  struct s_tree {
    p_node root;
} t_tree, *p_tree;

int* chooseRandMoves(int);

t_tree createEmptyTree();

int isEmptyTree(p_tree);

void freeTree(p_tree);

void addNode(p_tree, int cost);

void createTree();

p_node findBestWay(p_tree, p_node);

#endif //UNTITLED1_TREE_H
