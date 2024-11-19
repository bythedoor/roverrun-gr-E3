//
// Created by elias on 12/11/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include "node.h"
#include "map.h"
#include "moves.h"
typedef struct s_tree
{
    t_node *root ;
} t_tree ;


t_node* create_tree(t_node* root, t_move ** liste_move, int deep, int nb_move, t_move move, t_map map );

int cost_actual(t_node* node, t_map map); // Return the cost of the case on which is the robot

t_move** swap(t_move ** list, int a); //Swap the first element of the list with another one given in the parameter

t_move** new_list(t_move ** list, int a); //Return

#endif //UNTITLED1_TREE_H
