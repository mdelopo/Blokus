#include "move.h"

// TODO: Implement here the methods of Move

Move::Move(Piece movePiece, int moveX, int moveY, char moveOrientation, char moveFlip)
{
    movePiece.setPlaced();
    x=moveX;
    y=moveY;
    orientation=moveOrientation;
    flip=moveFlip;
    piece=movePiece;
}

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
