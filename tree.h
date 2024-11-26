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


t_node* create_tree(t_node* root, int* liste_move, int deep, int nb_move, t_map map, t_localisation loc, t_move move );

int cost_actual(t_localisation loc, t_map map); // Return the cost of the case on which is the robot

void swap(int * list, int a); //Swap the first element of the list with another one given in the parameter

int* new_list(int* list, int a, int nb_move_remaining); //Return enlebvant le mouvement fait par le robot

t_node* findMinLeaf(t_node* root);    //trouver le noeud avec la val la plus petite

void FindPathToLeaf(t_node* targetLeaf);    //trouver le meilleur chemin  

void displayMoves(t_move tab_moves[],int i);    //afficher les mouvements

#endif //UNTITLED1_TREE_H
