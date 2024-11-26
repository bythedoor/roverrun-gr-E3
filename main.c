#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "stack.h"
#include "tree.h"

int main() {
    t_map map;

    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

    int* randMoves = chooseRandMoves(3);
    printf("Here are the moves chosen randomly : ");
    for (int i=0; i<9; i++) {
        printf("%d ", randMoves[i]);
    }
    printf("\n");


    int taille = 10;

    p_node min = (p_node)malloc(sizeof(t_node));
    t_node* test;
    t_localisation loc_robot;
    loc_robot.pos.x = 4; loc_robot.pos.y = 5;
    loc_robot.ori = NORTH;
    test->nbSons = taille+1;
    test->depth = -1;
    test->parent = NULL;
    t_tree tree;

    tree.root = create_tree(test, randMoves, -1, taille, map, loc_robot, 0);
    min = searchBestNode(tree.root);

    printf("\nBest Cost is : %d", min->cost);
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

    return 0;
}
