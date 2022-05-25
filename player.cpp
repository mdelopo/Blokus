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
    pieces = new Piece*[21];
    createPieces(); //asteraki
}

Player::~Player(){
    for(int i=0; i<21; i++)
    {
        delete pieces[i];
    }
    delete pieces;
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
    return 21-numPieces;
}

int Player::getNumberOfAvailablePieces()
{
    return numPieces;
}

//HumanPlayer

HumanPlayer::HumanPlayer(int id):Player(id)
{
}

HumanPlayer::HumanPlayer(int id, string name):Player(id)
{
    this->name = name;
}

//Computerplayer

int ComputerPlayer::getRandomPieceId()
{
    return rand()%21;
}

Orientation ComputerPlayer::getRandomOrientation()
{
    return (Orientation)(rand()%4); // Rather ugly, but correct :D
}

Flip ComputerPlayer::getRandomFlip()
{
    return (Flip)(rand()%2);
}

ComputerPlayer::ComputerPlayer(int id):Player(id){}

