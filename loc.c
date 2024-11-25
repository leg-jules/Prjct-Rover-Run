//
// Created by flasque on 19/10/2024.
//

#include "loc.h"

t_localisation loc_init(int x, int y, t_orientation ori)
{
    t_localisation loc;
    loc.pos.x = x;
    loc.pos.y = y;
    loc.ori = ori;
    return loc;
}

int isValidLocalisation(t_position loc, int x_max, int y_max)
{
    return (loc.x >= 0 && loc.x < x_max && loc.y >= 0 && loc.y < y_max);
}

t_position LEFT(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x - 1;
    new_pos.y = pos.y;
    return new_pos;
}

t_position RIGHT(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x + 1;
    new_pos.y = pos.y;
    return new_pos;
}

t_position UP(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x;
    new_pos.y = pos.y - 1;
    return new_pos;
}

t_position DOWN(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x;
    new_pos.y = pos.y + 1;
    return new_pos;
}

char getOriAsString (t_orientation ori)
{
    switch (ori)
    {
        case NORTH:
            return 'N';
        case EAST:
            return 'E';
        case SOUTH:
            return 'S';
        case WEST:
            return 'W';
        default:
            return '?';
    }
}

//randomly update the localisation of the robot
t_localisation randomLoc(t_map map){
    srand(time(NULL));
    int xPos = rand() % map.x_max;
    int yPos = rand() % map.y_max;
    t_localisation loca = loc_init(xPos, yPos, rand() % 4);
    return loca;
}