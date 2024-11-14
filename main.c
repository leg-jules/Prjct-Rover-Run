#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "loc.h"
#include "map.h"
#include "tree.h"

int main() {
    printf("                                                                    ||\n");
    printf("                                                  __..--\".          ||\n");
    printf("                                 __..--\"`._..--\" . . . .`.        ||\n");
    printf("                         __..--\". . . . . . .`. . . . . . .`.      ||\n");
    printf("                 __..--\". . . . .`. . . . . . .`. . . . . . .`.   //                `7MM""\"Mq.                                        \n");
    printf("         __..--\". . `.  . . . . . .`. . . . . . .`. . . . . . .`.//                   MM   `MM.                                       \n");
    printf("  _..--\"  . . . . . . `.  . . . . . .`. . . . . . .`. . . . . . .||                   MM   ,M9   ,pW\"Wq.  `7M'   `MF' .gP\"Ya  `7Mb,od8\n");
    printf(":\". . . .`.  . . . . . . `.  . . . . . .`. . . . . . .`. . . . . .||`.                MMmmdM9   6W'   `Wb   VA   ,V  ,M'   Yb   MM' \"'\n");
    printf("`:. . . . .`.  . . . . . . `.  . . . . . .`. . . . . . .`. . . . .||__>               MM  YM.   8M     M8    VA ,V   8M\"\"\"\"\"\"   MM    \n");
    printf("  `:. . . . .`.  . . . . . . `.  . . . . . .`. . . . . . .`.__..-o||                  MM   `Mb. YA.   ,A9     VVV    YM.    ,   MM    \n");
    printf("    `:. . . . .`.  . . . . . . `.  . . . . . .`. . . . .`;Y\"->.  \"\"                 .JMML. .JMM. `Ybmd9'       W      `Mbmmd' .JMML.  \n");
    printf("      `:. . . . .`.  . . . . . . `.  . . . . . .`. . . __.>.:\'\n");
    printf("        `:. . . . .`.  . . . . . . `.  . . . . __..--\"\" ..+\"`.\n");
    printf("   _..-._ `:. . . . .`.  . . . . . . `.__..--\"\" ....:::::.|   `.                                 `7MM""\"Mq.                          \n");
    printf(" .\"`` \\_--\" >:. . . . .`.  . . __..,-|\" . ..::::::::::::::`--\"\"-:.                                 MM   `MM.                         \n");
    printf("' ..`\\J.-  \"8-`:. . .  __..--\"\" ...-I  \\ `. `::::::::::::::::::::\".                                MM   ,M9  `7MM  `7MM  `7MMpMMMb.  \n");
    printf("`/'\\\\88o. ,O \\  `:.--\"\"....:|:::'''`'\\ ='. }-._'::::::::::::::::::|                                MMmmdM9     MM    MM    MM    MM  \n");
    printf("8  8|PP|\"(:. \\-\" \"\"`:::::::|:::.((::='/ .\\\"\"-.:_ ':::::::::::''_.'  _..                            MM  YM.     MM    MM    MM    MM  \n");
    printf(" 8  8|::/ \\`::Y  _____`:::::|::::.\\\\[ .\\ \"/\"..* *\"-. '''__..--\")\\,\"\".-.\\_                          MM   `Mb.   MM    MM    MM    MM           _..._\n");
    printf("`\\b d/\"===\\==V::.--..__`:::|:::::.|,'*.\"\".:.. \"_-.*`.\"\"    _.-\"-\"\\? \"_=``.                       .JMML. .JMM.  `Mbod\"YML..JMML  JMML.       .'     '.      _\n");
    printf("\\`\".\"' .: :-.::.        `:|:::.'.'*.' __..--\"\"   `.*`:--\"\".-\"?,  .)=\"`\\ \\ \\                                                                /    .-\"\"-\\   _/ \\\n");
    printf(" `.``...''_/   ``::      _\\\\--.'.'*.'-\"\"   _..-._ _..>.*;-\"\"@_.-/-\" `\\.-\"\"\"-.\\                                                           .-|   /:.   |  |   |\n");
    printf("   `-::--\"            .-\"@\"}.'.'*.:)     .\"\\` \\ \\`.--'_`-'     `\\. \\-'-\"-   `.                                                           |  \\  |:.   /.-'-./\n");
    printf("                     <\\  _...'*.'      .' \\.`\\ `\\ \\\"\"         `\\ `' ' .-.\\   |                                                           | .-'-;:__.'    =/\n");
    printf("                     _\\\" .---'        -\\. `\\.-\"\"\"-.\\           \\`|    ._)/   '                                                           .'=  *=|EFREI_.='\n");
    printf("                   .\"\\.`-\"\\`.         `\\. \\-'-\"\"-   `.           \\\\  `---\"   /                                                          /   _.  |    ;\n");
    printf("                 .' \\.`\\ `\\ \\\\        `\\ `' ' .-.\\   |            `.       _/                                                          ;-.-'|    \\   |\n");
    printf("                 -\\. `\\.-\"\"\"-.\\        \\`|    ._)/   '              `-..--\"                                                           /   | \\    _\\  _\\\n");
    printf("                `\\. \\-'-\"\"-   `.        \\\\  `---\"   /                                                                                 \\__/'._;.  ==' ==\\\n");
    printf("                `\\ `' ' .-.\\   |         `.       _/                                                                                           \\    \\   |\n");
    printf("                 \\`|    ._)/   '           `-..--\"                                                                                             /    /   / \n");
    printf("                  \\\\  `---\"   /                                                                                                                /-._/-._/\n");
    printf("                   `.       _/                                                                                                                 \\   `\\  \\\n");
    printf("                     `-..--\"\"                                                                                                                   `-._/._/\n\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");


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
    srand(time(NULL));
    int xPos = rand() % map.x_max;
    int yPos = rand() % map.y_max;
    t_localisation loca = loc_init(xPos, yPos, rand() % 4);
    printf("Position initialized at:\n");
    printf("   X : %d\n",xPos);
    printf("   Y : %d\n",yPos);
    printf("   Orientation: %s\n\n", orientation_names[loca.ori]);



    // test arbre n aire
    int avails[5] = {1,2,3,4,5};
    t_node *root = createNode(0,0, 5, avails, 0);
    t_tree myTree = createNTree(root);

    printf("Tree n-ary:\n");
    printTree(&myTree);

    return 0;

}
