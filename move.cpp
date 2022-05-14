#include "move.h"

// TODO: Implement here the methods of Move

Move::Move(Piece movePiece, int moveX, int moveY, char moveOrientation, char moveFlip)
{
    movePiece.setPlaced();
    x=moveX;
    y=moveY;
    orientation=moveOrientation;    //initializes a move with piece movePiece,based on the coordinates of the top left square moveX
    flip=moveFlip;                  //and moveY, orientation moveOrientation and flip moveFlip
    piece=movePiece;
}
                                    //getters, return the values
Piece Move::getPiece()
{
    return piece;
}

int Move::getX()
{
    return x;
}

int Move::getY()
{
    return y;
}

char Move::getOrientation()
{
    return orientation;
}

char Move::getFlip()
{
    return flip;
}
