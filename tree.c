//
// Created by elias on 12/11/2024.
//

#include "tree.h"
#include "node.h"
#include "queue.h"

t_node* create_tree(t_node* root, int* liste_move, int deep, int nb_move, t_map map, t_localisation loc, t_move previous_move){

    t_node* new = createNode((root->nbSons)-1, deep+1, loc);//Create a new node
    new->move = previous_move;

    new->value = cost_actual(new->localisation, map); //calculate the cost of the square on which is the robot
    new->parent = root; //Initialisation of the parent of the new node


    printf("Cost :  %d  Coordonnees : [%d][%d]   orientation : %d",new->value, new->localisation.pos.x, new->localisation.pos.y, new->localisation.ori);
    printf("\ndeep : %d\n",new->depth );


    if (new->depth >= 5) {
        return new;
    }

    new->sons = (t_node**)malloc(new->nbSons * sizeof(t_node*));

    for (int i = 0; i < nb_move; i++) {  //Loop creating all the nodes of the new node

        int curr_move = liste_move[i]; //Initialisation of the move of the son
        int* curr_liste = new_list(liste_move, i, nb_move);  //Create a new list of moves available for the son

        t_localisation new_loc = move(new->localisation, curr_move);

        if (isValidLocalisation(new_loc.pos, 6, 7) == 1 &&  cost_actual(new_loc,map) <10000 && cost_actual(new_loc,map) != 0) {  //Check if the robot is out of the map or if the robot is in a hole

            new->sons[i] = create_tree(new, curr_liste, deep + 1, nb_move - 1, map, new_loc, curr_move); //creation the son

        }
        else{
            if (cost_actual(new_loc,map) == 0){
                printf("------------------------------TROUV2----------------------------------");
            }
            new->sons[i] = NULL;
            printf("IMPOSSIBLE, cout : %d  x =%d  y= %d", cost_actual(new_loc,map), new_loc.pos.x, new_loc.pos.y);
        }

        free(curr_liste);
    }

}


int cost_actual(t_localisation loc, t_map map){
    if (isValidLocalisation(loc.pos, 7, 6) == 1 ){
        return map.costs[loc.pos.x][loc.pos.y];
    }
    else
        return 9000000;
}

void swap(int* list, int a){

    if (a!= 0){
        int tmp = list[0];
        list[0] = list[a];
        list[a] = tmp;
    }
}

int* new_list(int * list, int a, int nb_move_remaining){
    swap(list, a);
    int* new_list = (int*)malloc((nb_move_remaining-1) * sizeof(int));

    for (int i = 1; i < nb_move_remaining; i++) {
        new_list[i-1] = list[i];
    }
    return new_list;

}


