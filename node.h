//
// Created by Kimberley on 11/20/2024.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H

#include "moves.h"

typedef struct s_node {
    int cost; // Value of the current localisation
    int nbSons; // Number of sons the node can have
    int depth; // The current dept of the node
    t_localisation loc; // Position and orientation of the robot
    struct s_node *sons[9]; // Tab of all the sons addresses
    struct s_node *parent; // Address of the parent of the node
} t_node, *p_node;

p_node createNode(int);

#endif //UNTITLED1_NODE_H
