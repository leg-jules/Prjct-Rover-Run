#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "loc.h"
#include "map.h"
#include "tree.h"

int main() {

    printf(" "
           "_ __ _____   _____ _ __   _ __ _   _ _ __  \n"
           "| '__/ _ \\ \\ / / _ \\ '__| | '__| | | | '_ \\ \n"
           "| | | (_) \\ V /  __/ |    | |  | |_| | | | |\n"
           "|_|  \\___/ \\_/ \\___|_|    |_|   \\__,_|_| |_|\n"
           "                                             \n"
           "                                             \n");
    t_map map;

    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

    printf("Map created with dimensions %d x %d\n\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n\n");
    }
    displayMap(map);
    printf("\n\n");

    // randomisation position du robot init
    t_localisation loc = randomLoc(map);



    // test arbre n aire
    int avails[5] = {1,2,3,4,5};
    t_node *root = createNode(0,0, 5, avails, 0);
    t_tree myTree = createNTree(root);

    printf("Tree n-ary:\n");
    printNTree(myTree);

    return 0;

}
