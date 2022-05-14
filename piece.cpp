#include "piece.h"

// TODO: Implement here the methods of Piece

Piece::Piece()
{
    id=-1;
    pieceSize=5;
    player='-';
    placed=false;
}

Piece::Piece(int pieceId, char piecePlayer, char pieceSquares[5][5])
{
    pieceSize=5;
    placed=false;
    player=piecePlayer;
    id=pieceId;

    for(int i=0; i<pieceSize; i++)
    {
        for(int j=0; j<pieceSize; j++)
        {
            squares[i][j].setCoordinates(i,j);          //cycles through the 5x5 array and copies the character of the
            if(pieceSquares[i][j]!='-')                 //player to the squares that form the piece
            {
                squares[i][j].addPiece(pieceSquares[i][j]);
            }
        }
    }
}
                                                        //getters, return the values
int Piece::getId()
{
    return id;
}

char Piece::getPlayer()
{
    return player;
}

void Piece::setPlaced()
{
    placed=true;
}

bool Piece::isPlaced()
{
    return placed;
}

int Piece::getSize()
{
    return pieceSize;
}

Square Piece::getSquare(int x, int y)
{
    return squares[x][y];
}

bool Piece::squareHasPiece(int x, int y)
{
    if(squares[x][y].getPlayer()=='#' || squares[x][y].getPlayer()=='O') return true;
    else return false;
}

void Piece::rotatePieceClockwise()
{
    Square temporary[5][5];
    for(int i=0; i<5; i++)                          //creates a temporary 5x5 array of squares and copies its contents
    {
        for(int j=0; j<5; j++)
        {
            temporary[i][j].setCoordinates(i,j);
            temporary[i][j].addPiece(squares[i][j].getPlayer());
        }
    }
    for(int i=0; i<5; i++)                          //replaces the original array of squares in order to rotate the piece
    {                                               //rotation algorithm with loop for each square
        for(int j=0; j<5; j++)
        {
            if(temporary[i][j].getPlayer()!='-') squares[j][4-i].addPiece(temporary[i][j].getPlayer());
            else squares[j][4-i].addPiece('-');
        }
    }
}

void Piece::rotatePiece(char orientation)
{
    if(orientation=='r') rotatePieceClockwise();    //calls the rotatePieceClockwise once
    else if(orientation=='d')
    {
        rotatePieceClockwise();
        rotatePieceClockwise();                     //calls the rotatePieceClockwise twice
    }
    else if (orientation=='l')
    {
        rotatePieceClockwise();
        rotatePieceClockwise();
        rotatePieceClockwise();                     //calls the rotatePieceClockwise three times
    }
}

void Piece::flipPiece()
{
    Square temporary[5][5];                         //creates a temporary 5x5 array of squares and copies its contents
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            temporary[i][j].setCoordinates(i,j);
            temporary[i][j].addPiece(squares[i][j].getPlayer());
        }
    }
    for(int i=0; i<5; i++)                          //replaces the original array of squares in order to flip the piece
    {                                               //newY=y, newX=4-x
        for(int j=0; j<5; j++)
        {
            if(temporary[i][j].getPlayer()!='-') squares[i][4-j].addPiece(temporary[i][j].getPlayer());
            else squares[i][4-j].addPiece('-');
        }
    }
}
