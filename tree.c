//
// Created by elias on 12/11/2024.
//

#include "tree.h"

t_node* create_tree(t_node* root, t_move ** liste_move, int deep, int nb_move, t_move move_robot, t_map map){
    t_localisation new_loc = move(root->localisation, move_robot);
    t_node* new = createNode(root->nbSons-1, deep, new_loc);
    new->value = cost_actual(new, map);
    new->parent = root;
    for (int i = 0; i<new->nbSons; i++){
        t_move ** curr_liste = liste_move;
        t_move * curr_move = liste_move[i];


        t_node* son = create_tree(new, curr_liste, deep+1, nb_move-1, *curr_move, map);
    }

}


int cost_actual(t_node* node, t_map map){
    return map.costs[node->localisation.pos.x][node->localisation.pos.y];
}

t_move** swap(t_move** list, int a){
    if (a!= 0){
        t_move* tmp = list[0];
        list[0] = list[a];
        list[a] = list[0];
    }
    return list;
}

t_move** new_list(t_move ** list, int a){
    list = swap(list, a);
    t_move** new_list;



}