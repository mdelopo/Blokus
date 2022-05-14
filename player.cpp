#include <iostream>
#include "player.h"

// TODO: Implement here the methods of Player

Player::Player(int playerId)
{
    id=playerId;                    //creates a player with given id, names him and creates his pieces
    if(id==0) name="Player 1";
    else if(id==1) name="Player 2";
    numPlacedPieces=0;
    createPieces();
}
                                    //getters, return the values
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
    return 21-numPlacedPieces;      //21 pieces for each player,available pieces are 21 minus the number of placed pieces
}
