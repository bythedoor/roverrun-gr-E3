//
// Created by elias on 12/11/2024.
//
#include "shuffle.h"

t_stack add_moves(int nb_move){
    // Initialisation of a stack with all the moves available
    // Adds each type of move and its availability
    // 0 = F_10, 1 = F_20, ...
    t_stack moves_tab = createStack(100);

    for (int i=0; i<22; i++)
    {
        push(&moves_tab, 0);
    }
    for (int i=0; i<15; i++)
    {
        push(&moves_tab, 1);
    }
    for (int i=0; i<7; i++)
    {
        push(&moves_tab, 2);
    }
    for (int i=0; i<7; i++)
    {
        push(&moves_tab, 3);
    }
    for (int i=0; i<21; i++)
    {
        push(&moves_tab, 4);
    }
    for (int i=0; i<21; i++)
    {
        push(&moves_tab, 5);
    }
    for (int i=0; i<7; i++)
    {
        push(&moves_tab, 6);
    }


    return moves_tab;
}

t_stack Fisher_Yates(t_stack stack){
    for (int i=stack.nbElts - 1; i>1; i--)
    {
        int j = rand() % (i+1); // Chooses a random number between 0 and the number of elements in the stack

        // Exchange the values
        int temp = stack.values[i];
        stack.values[i] = stack.values[j];
        stack.values[j] = temp;
    }
    return stack;

}   // Fisher-Yates algorithm, shuffling all the values in the stack (linear complexity)

int* create_tab(t_stack stack, int nb_value){
    int* rand_moves = (int*)malloc(nb_value * sizeof(int));
    for (int i=0; i<nb_value; i++)
    {
        rand_moves[i] = stack.values[i];
    }
    return rand_moves;
}
