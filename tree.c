//
// Created by Kimberley on 11/13/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
#include "stack.h"
#include <time.h>

/**
 * @brief Function to generate random moves
 * @return pointer to tab with all moves available
 */
int* chooseRandMoves(int nb) {
    srand(time(NULL)); // Allows us to generate random numbers with rand() each time the program runs

    // Initialisation of a stack with all the moves available
    t_stack moves_tab = createStack(100);
    int avail_moves[9] = {22, 15, 7, 7, 21, 21, 7};

    // Adds each type of move and its availability
    // 0 = F_10, 1 = F_20, ...
    for (int i=0; i < 9; i++) {
        for (int j=0; j < avail_moves[i]; j++) {
            push(&moves_tab, i);
        }
    }

    // Fisher-Yates algorithm, shuffling all the values in the stack (linear complexity)
    for (int i=moves_tab.nbElts; i>1; i--)
    {
        int j = rand() % (moves_tab.nbElts+1); // Chooses a random number between 0 and the number of elements in the stack

        // Exchange the values
        int temp = moves_tab.values[i];
        moves_tab.values[i] = moves_tab.values[j];
        moves_tab.values[j] = temp;
    }

    // Create a tab with the random moves selected
    int *rand_moves = (int*) malloc(sizeof(int) * nb);
    for (int i=0; i<nb; i++) // Testing with 5 moves first
    {
        rand_moves[i] = moves_tab.values[i];
    }

    return rand_moves;
}

/**
 * @brief Function to create an empty tree
 * @return pointer to the empty tree
 */
t_tree createEmptyTree(){
    t_tree new_tree;
    new_tree.root = NULL;
    return new_tree;
}

/**
 * @brief Function to test if a tree is empty (no root)
 * @param tree
 * @return 0 (False) or 1 (True)
 */
int isEmptyTree(p_tree tree) {
    return(tree->root == NULL);
}

void freeTree(p_tree tree) {
    free(tree);
}

t_queue_tab createEmptyQueue()
{
    t_queue_tab q;
    q.first = q.last = 0;
    return q;
}

int isEmptyQueue(t_queue_tab q)
{
    return (q.first == q.last);
}

int isFullQueue(t_queue_tab q)
{
    return (q.last-q.first == MAX);
}

t_node* create_tree(t_node* root, int* liste_move, int deep, int nb_move, t_map map, t_localisation loc, t_move previous_move){

    t_node* new = createNode((root->nbSons)-1, deep+1, loc);//Create a new node
    new->move = previous_move;

    new->cost = cost_actual(new->loc, map); //calculate the cost of the square on which is the robot
    new->parent = root; //Initialisation of the parent of the new node


    printf("Cost :  %d  Coordonnees : [%d][%d]   orientation : %d",new->cost, new->loc.pos.x, new->loc.pos.y, new->loc.ori);
    printf("\ndeep : %d\n",new->depth );


    if (new->depth >= 5) {
        return new;
    }

    new->sons = (t_node**)malloc(new->nbSons * sizeof(t_node*));

    for (int i = 0; i < nb_move; i++) {  //Loop creating all the nodes of the new node

        int curr_move = liste_move[i]; //Initialisation of the move of the son
        int* curr_liste = new_list(liste_move, i, nb_move);  //Create a new list of moves available for the son

        t_localisation new_loc = move(new->loc, curr_move);

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

void enqueueTab(t_queue_tab *pq, t_node *val) {
    int pos;
    pos = pq->last%MAX;
    pq->values[pos] = val;
    pq->last = pq->last+1;
}

p_node searchBestNode(p_node root) {
    t_queue_tab visitQueue = createEmptyQueue(); //création de la file
    p_node temp;
    int minCost = 15; // cout minimal
    p_node minNode = NULL;

    if (root != NULL) {
        if (root->sons != NULL) {
            for (int i = 0; i <= root->nbSons; i++) {
                temp = root->sons[0];
                enqueueTab(&visitQueue, temp);
                if (temp->cost < minCost) {
                    minCost = temp->cost;
                    minNode = temp;
                }
            }
        }
    }
    return minNode;
}

// Test
/*
p_node insertNode(p_node node, int cost, int nbSons, int* sons) {
    printf("%d", node->cost);

    // Creating the new node
    p_node newNode = createNode(sons[0]);

    int i = 0;
    if (node->nbSons >= (sizeof(node->sons)/sizeof(node->sons[0]))) {
        return node;
    }
    else {
        i++;
        node->nbSons--;
        insertNode(&node->sons[i], sons[i], node->nbSons, sons);
    }
    return node;
}*/