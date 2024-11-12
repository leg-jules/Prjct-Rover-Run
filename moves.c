//
// Created by flasque on 19/10/2024.
//

#include "moves.h"

/** rules for coordinates:
    *  - x grows to the right with step of +1
    *  - y grows to the bottom with step of +1
    *  - the origin (x=0, y=0) is at the top left corner
    */

t_orientation rotate(t_orientation, t_move);

t_localisation translate(t_localisation, t_move);

t_orientation rotate(t_orientation ori, t_move move)
{
    int rst;
    switch (move)
    {
        case T_LEFT:
            rst=3;

            break;
        case T_RIGHT:
            rst=1;
            break;
        case U_TURN:
            rst=2;
            break;
        default:
            return ori;
            break;
    }
    return (ori+rst)%4;
}

/**
 * @brief Function to rotate the robot according to a move and its actual orientation
 * @param ori : the actual orientation of the robot
 * @param move : the move to do
 * @return the new orientation of the robot
 */

t_localisation translate(t_localisation loc, t_move move)
{
    t_position res = loc.pos;
    switch (move) {
        case F_10:
            switch (loc.ori) {
                case NORTH: res.y--; break;
                case SOUTH: res.y++; break;
                case EAST:  res.x++; break;
                case WEST:  res.x--; break;
                default: break;
            }
        case F_20:
            switch (loc.ori) {
                case NORTH: res.y -= 2; break;
                case SOUTH: res.y += 2; break;
                case EAST:  res.x += 2; break;
                case WEST:  res.x -= 2; break;
                default: break;
            }
        case F_30:
            switch (loc.ori) {
                case NORTH: res.y -= 3; break;
                case SOUTH: res.y += 3; break;
                case EAST:  res.x += 3; break;
                case WEST:  res.x -= 3; break;
                default: break;
            }
        case B_10:
            switch (loc.ori) {
                case NORTH: res.y++; break;
                case SOUTH: res.y--; break;
                case EAST:  res.x--; break;
                case WEST:  res.x++; break;
                default: break;
            }
        default: break;
    }
    return loc_init(res.x, res.y, loc.ori);
}

/**
 * @brief function to translate the robot according to a move and its actual position
 * @param loc : the actual localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */

char *getMoveAsString(t_move move)
{
    return _moves[move];
}

t_localisation move(t_localisation loc, t_move move)
{
    t_localisation new_loc;
    new_loc.ori = rotate(loc.ori, move);
    new_loc = translate(loc, move);
    return new_loc;
}

void updateLocalisation(t_localisation *p_loc, t_move m)
{
    *p_loc = move(*p_loc, m);
    return;
}

