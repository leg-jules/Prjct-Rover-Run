#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "loc.h"
#include "map.h"
#include "tree.h"

int main() {
    t_map map;
    t_map map1 = createRandomMap(6,7);
    srand(time(NULL));


    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

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
    for (int i = 0; i < map1.y_max; i++)
    {
        for (int j = 0; j < map1.x_max; j++)
        {
            printf("%-5d ", map1.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map1);

    // randomisation position du robot init
    t_localisation loc = randomLoc(map1);
    // test arbre n aire
    int avails[5] = {1,2,3,4,5};
    t_node *root = createNode(0,0, 5, avails, 0);

    root->loc.ori = loc.ori;
    root->loc.pos = loc.pos;

    t_tree myTree = createNTree(root, 5, loc, map1);

    printf("Tree n-ary:\n");
//    printNTree(root, 0);
//    minimumNode(myTree);

    isOnBaseStation(loc, map1);
    printf("\n");

    displayMap(map1);
    freeMap(map1);
    isOutOfMap(loc, map1);

    return 0;

}