#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "stack.h"
#include <time.h>

int main() {
    srand(time(NULL)); // Allows us to generate random numbers with rand() each time the program runs
    t_map map;

    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

    // Initialisation of a stack with all the moves available
    t_stack moves_tab = createStack(100);

    // Adds each type of move and its availability
    // 0 = F_10, 1 = F_20, ...
    // On doit trouver un moyen de rendre ça plus efficace
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

    for (int i=0; i<moves_tab.nbElts;i++)
        printf("%d", moves_tab.values[i]);
    printf("\n");

    // Fisher-Yates algorithm, shuffling all the values in the stack (linear complexity)
    for (int i=moves_tab.nbElts; i>1; i--)
    {
        int j = rand() % (moves_tab.nbElts+1); // Chooses a random number between 0 and the number of elements in the stack

        // Exchange the values
        int temp = moves_tab.values[i];
        moves_tab.values[i] = moves_tab.values[j];
        moves_tab.values[j] = temp;
    }
    // Test (displays shuffled values)
    for (int i=0; i<moves_tab.nbElts;i++)
        printf("%d", moves_tab.values[i]);
    printf("\n");

    // Create a tab with the 9 random moves selected
    int rand_moves[9];
    for (int i=0; i<5; i++) // Testing with 5 moves first
    {
        rand_moves[i] = moves_tab.values[i];
    }

    // Test (displays the random moves selected)
    for (int i=0; i<9; i++)
    {
        printf("%d",rand_moves[i]);
    }
    printf("\n");

    /*
    // Displays the size of the map created (7x6 initially)
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);

    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);*/

    // Question : how do we set the initial position of the rover ?

    return 0;
}
