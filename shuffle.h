//
// Created by elias on 12/11/2024.
//

#ifndef UNTITLED1_SHUFFLE_H
#define UNTITLED1_SHUFFLE_H

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

t_stack add_moves(int nb_move);

t_stack Fisher_Yates(t_stack stack);

int* create_tab(t_stack stack, int nb_value);

#endif //UNTITLED1_SHUFFLE_H
