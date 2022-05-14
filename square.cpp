#include <iostream>
#include "square.h"

// TODO: Implement here the methods of Square

Square::Square()
{
    x=-1;           //initializes a square with coordinates (-1,-1) and player character '-'
    y=-1;
    player='-';
}

void Square::setCoordinates(int newx, int newy)
{
    x=newx;
    y=newy;
}
                            //getters, return the values
int Square::getX()
{
    return x;
}

int Square::getY()
{
    return y;
}

void Square::addPiece(char piecePlayer)
{
    player=piecePlayer;     //adds the character of the given player to the square
}

void Square::removePiece()
{
    player='-';             //removes the character of a player and replaces it with '-'
}

bool Square::hasPiece()
{
    if(player=='#'|| player=='O') return true;
    else return false;
}

char Square::getPlayer()
{
    return player;
}
