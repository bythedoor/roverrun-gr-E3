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


    //printf("Cost :  %d  Coordonnees : [%d][%d]   orientation : %d",new->value, new->localisation.pos.x, new->localisation.pos.y, new->localisation.ori); //Utiliser pour debug
    //printf("\ndeep : %d\n",new->depth );  //Utiliser pour debug


    if (new->depth >= 5) {
        return new;
    }

    new->sons = (t_node**)malloc(new->nbSons * sizeof(t_node*));   
    for (int i = 0; i < new->nbSons; i++) { 
        new->sons[i] = NULL; 
    }
    

    for (int i = 0; i < nb_move; i++) {  //Loop creating all the nodes of the new node

        int curr_move = liste_move[i]; //Initialisation of the move of the son
        int* curr_liste = new_list(liste_move, i, nb_move);  //Create a new list of moves available for the son

        t_localisation new_loc = move(new->localisation, curr_move);

        if (isValidLocalisation(new_loc.pos, 6, 7) == 1 &&  cost_actual(new_loc,map) <10000 && cost_actual(new_loc,map) != 0) {  //Check if the robot is out of the map or if the robot is in a hole

            new->sons[i] = create_tree(new, curr_liste, deep + 1, nb_move - 1, map, new_loc, curr_move); //creation the son

        }
        else{
            if (cost_actual(new_loc,map) == 0){
                printf("------------------------------TROUV2----------------------------------"); // Savoir si on est arriver a la base
            }
            new->sons[i] = NULL;
            //printf("IMPOSSIBLE, cout : %d  x =%d  y= %d", cost_actual(new_loc,map), new_loc.pos.x, new_loc.pos.y); //Pour debug
        }

        free(curr_liste);
    }
    return new;
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

t_node* findMinLeaf(t_node* root) {
    if (root == NULL) {
        return NULL;    // Cas arbre vide
    }

    if (root->nbSons == 0 || root->sons == NULL) {      // Case where the node is a leaf
        return root;
    }

    t_node* minLeaf = NULL;     // Initialise the sheet with the smallest value
    int minValue = INT_MAX;     // Initialise with a max value for comparison

    for (int i = 0; i < root->nbSons; i++) {        // Browse all the sons
        if (root->sons[i] != NULL) {
            t_node* candidate = findMinLeaf(root->sons[i]);     // Find the mini leaf for this sub-tree
            if (candidate != NULL && candidate->value < minValue) {
                minValue = candidate->value;
                minLeaf = candidate;
            }
        }
    }

    if (minLeaf != NULL && root->depth == 0) {      // Display of node information with smaller value
        printf("\n\nFound leaf with minimum value:\n");
        printf("Value: %d\t", minLeaf->value);
        printf("Depth: %d\t", minLeaf->depth);
        printf("Coordinates: [%d][%d]\t", minLeaf->localisation.pos.x, minLeaf->localisation.pos.y);
        printf("Orientation: %d\n\n", minLeaf->localisation.ori);
    }
    return minLeaf; // Turn over the sheet with smaller value
}


void FindPathToLeaf(t_node* targetLeaf) {

    if (targetLeaf == NULL) {
        printf("Target leaf is NULL.\n");
        return;
    }

    t_move* tab_moves = malloc(targetLeaf->depth * sizeof(t_move)); // Dynamic allocation according to depth
    if (tab_moves == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    t_node *curr = targetLeaf;
    for (int i = targetLeaf->depth - 1; i >= 0; i--) {      // go from the leaf to the root
        tab_moves[i] = curr->move;
        curr = curr->parent;
    }

    printf("Path from root to leaf:\n");
    for (int i = targetLeaf->depth - 1; i >= 0; i--) {      
        displayMoves(tab_moves, targetLeaf->depth - i - 1); 
    }
    free(tab_moves);
}

void displayMoves(t_move tab_moves[],int i) {
    switch (tab_moves[i]) {
        case F_10:
            printf("Move %d: Forward 10 m\n", i);
            break;
        case F_20:
            printf("Move %d: Forward 20 m\n", i);
            break;
        case F_30:
            printf("Move %d: Forward 30 m\n", i);
            break;
        case B_10:
            printf("Move %d: Backward 10 m\n", i);
            break;
        case T_LEFT:
            printf("Move %d: Turn left (+90)\n", i);
            break;
        case T_RIGHT:
            printf("Move %d: Turn right (-90)\n", i);
            break;
        case U_TURN:
            printf("Move %d: U-turn (180)\n", i);
            break;

    }
}

