//
// Created by Kimberley on 11/13/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"
#include <time.h>

/**
 * @brief Function to generate random moves
 * @return tab with all moves available
 */
int** chooseRandMoves(int nb) {
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
    int rand_moves[nb];
    for (int i=0; i<5; i++) // Testing with 5 moves first
    {
        rand_moves[i] = moves_tab.values[i];
    }

    return &rand_moves;
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

void createTree(p_tree pt, int val, int nbSons, int depth, int moves) {
    p_node pn = createNode(val, nbSons, depth);
    pt->root = pn;
}


p_node findBestWay(p_tree tree, p_node node) {
    t_queue moves = createQueue(200);
    p_node temp = node;
    while (temp != NULL) {
        if (temp->value == 0) {
            return temp;
        }
        else {
            for (int i=0; i < temp->nbSons; i++) {
                enqueue(&moves, *(temp->sons));
                temp = moves.values[1];
                dequeue(&moves);
            }
        }
    }
}