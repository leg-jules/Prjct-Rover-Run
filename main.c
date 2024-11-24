#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "loc.h"
#include "map.h"
#include "tree.h"

int main() {
    printf(" ____  ____  _     _____ ____    ____  _     _    \n");
    printf("/  __\\/  _ \\/ \\ |\\/  __//  __\\  /  __\\/ \\ /\\/ \\  /|\n");
    printf("|  \\/|| / \\|| | //|  \\  |  \\/|  |  \\/|| | ||| |\\ ||\n");
    printf("|    /| \\_/|| \\// |  /_ |    /  |    /| \\_/|| | \\||\n");
    printf("\\_/\\_\\\\____/\\__/  \\____\\\\_/\\_\\  \\_/\\_\\\\____/\\_/  \\|\n");
    printf("                                                  \n");
    printf("\n");


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
    printf("Robot initial position: x=%d, y=%d, orientation=%c\n", loc.pos.x, loc.pos.y, getOriAsString(loc.ori));
    int avails[5] = {1,2,3,4,5};
    t_node *root = createNode(0,0, 5, avails, 0);
    root->loc.ori = loc.ori;
    // test arbre n aire

    t_tree myTree = createNTree(root);

    printf("Tree n-ary:\n");
    printNTree(myTree);

    return 0;

}
