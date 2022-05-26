#include <iostream>
#include <cstdlib>
#include "player.h"

// TODO: Implement here the methods of Player and all derived classes

Player::Player(int id)
{
    this->id=id;
    if(id==0)
    {
        name = "Player 1";
        symbol = '#';
    }
    else if(id==1)
    {
        name = "Player 2";
        symbol = 'O';
    }
    numPieces = 21;
    pieces = new Piece*[numPieces];
    createPieces(); //asteraki
}

Player::~Player(){
    for(int i=0; i<numPieces; i++)
    {
        delete pieces[i];
    }
    delete [] pieces;
}

int Player::getId()
{
    return id;
}

char Player::getSymbol()
{
    return symbol;
}

string Player::getName()
{
    return name;
}

Piece* Player::getPiece(int index)
{
    return pieces[index];
}

int Player::getNumberOfPlacedPieces()
{
    int NumberOfPlacedPieces = 0;
    for(int i=0; i<numPieces; i++)
    {
        if(pieces[i]->isPlaced()==true)
        {
                NumberOfPlacedPieces++;
        }
    }
    return NumberOfPlacedPieces;
}

int Player::getNumberOfAvailablePieces()
{
    int NumberOfAvailablePieces = numPieces-getNumberOfPlacedPieces();
    return NumberOfAvailablePieces;
}

//HumanPlayer

HumanPlayer::HumanPlayer(int id):Player(id)
{
}

HumanPlayer::HumanPlayer(int id, string name):Player(id)
{
    this->name = name;
}

//ComputerPlayer
ComputerPlayer::ComputerPlayer(int id):Player(id){}

int ComputerPlayer::getRandomPieceId()
{
    return (rand()%numPieces)+1;
}

Orientation ComputerPlayer::getRandomOrientation()
{
    return (Orientation)(rand()%4); // Rather ugly, but correct :D
}

Flip ComputerPlayer::getRandomFlip()
{
    return (Flip)(rand()%2);
}
