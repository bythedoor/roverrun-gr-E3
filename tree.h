//
// Created by Kimberley on 11/13/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include "node.h"
#include "map.h"
#define MAX 100

typedef struct s_tree {
    p_node root;
} t_tree, *p_tree;

typedef struct s_queue_tab
{
    t_node *values[MAX];
    int first, last;
} t_queue_tab;

int* chooseRandMoves(int);

t_tree createEmptyTree();

int isEmptyTree(p_tree);

void freeTree(p_tree);

t_queue_tab createEmptyQueue();

int isEmptyQueue(t_queue_tab);

int isFullQueue(t_queue_tab q);

void enqueueTab(t_queue_tab *pq, t_node *val);

//Elias part
t_node* create_tree(t_node* root, int* liste_move, int deep, int nb_move, t_map map, t_localisation loc, t_move previous_move);

int cost_actual(t_localisation loc, t_map map); // Return the cost of the case on which is the robot

void swap(int * list, int a); //Swap the first element of the list with another one given in the parameter

int* new_list(int* list, int a, int nb_move_remaining); //Return

//My part
p_node searchBestNode(p_node);

#endif //UNTITLED1_TREE_H
