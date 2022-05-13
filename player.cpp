#include <iostream>
#include "player.h"

// TODO: Implement here the methods of Player

Player::Player(int playerId)
{
    id=playerId;
    if(id==0) name="Player 1";
    else if(id==1) name="Player 2";
    numPlacedPieces=0;
    createPieces();
}

string Player::getName()
{
    return name;
}

Piece Player::getPiece(int index)
{
    return pieces[index];
}

int Player::getNumberOfAvailablePieces()
{
    return 21-numPlacedPieces;
}
