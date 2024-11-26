#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "stack.h"
#include <time.h>
#include "shuffle.h"
#include "moves.h"
#include "loc.h"
#include "tree.h"
#include "node.h"

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

    t_stack moves_tab = add_moves(100);
    for (int i=0; i<moves_tab.nbElts;i++)
        printf("%d", moves_tab.values[i]);
    printf("\n");

    moves_tab = Fisher_Yates(moves_tab);

    // affichage
    for (int i=0; i<moves_tab.nbElts;i++)
        printf("%d", moves_tab.values[i]);
    printf("\n");

    // Create a tab with the 9 random moves selected
    int taille = 10;
    int* rand_moves = create_tab(moves_tab, taille);;

    // affichage
    for (int i=0; i<taille; i++)
    {
        printf("%d",rand_moves[i]);
    }
    printf("\n");


    t_node* test;
    t_localisation loc_robot;
    loc_robot.pos.x = 4; loc_robot.pos.y = 5;
    loc_robot.ori = NORTH;
    test->nbSons = taille+1;
    test->depth = -1;
    test->parent = NULL;
    t_tree tree;

    tree.root = create_tree(test, rand_moves, -1, taille, map, loc_robot, 0);


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
    displayMap(map);

    t_node* minLeaf = findMinLeaf(tree.root);    // fonction pour trouver la feuille avec la valeur minimale

    if (minLeaf != NULL) {
        FindPathToLeaf(minLeaf);    //affichage du chemin 
    } else {
        printf("No valid leaf found in the tree.\n");
    }

    return 0;
}
