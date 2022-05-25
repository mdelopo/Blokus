#include "board.h"
#include "player.h"

// TODO: Implement here the method pieceCanBePlaced and computeScore of Board
// Do not implement any other methods of Board (as they are already implemented in file board.cpp)

bool Board::pieceCanBePlaced(Piece* piece, int x, int y)
{
    bool canBePlaced = true;
    if(x<0 || x+piece->getSizeX()>13) return false;
    if(y<0 || y+piece->getSizeY()>13) return false;

    if(playerHasPlacedNoPieces(piece->getPlayer())) //proti kinisi
    {
        int firstX, firstY;
        if(piece->getPlayer()=='#')
        {
            firstX=4;
            firstY=4;
        }
        else if(piece->getPlayer()=='O')
        {
            firstX=9;
            firstY=9;
        }
        for(int i=0; i<piece->getSizeX(); i++)
        {
            for(int j=0; j<piece->getSizeY(); j++)
            {
                if(piece->squareHasPiece(i,j)==true && x+i==firstX && y+j==firstY) return true;
            }
        }

    }

    for(int i=0; i<piece->getSizeX(); i++) //
    {
        for(int j=0; j<piece->getSizeY(); j++)
        {
            if(hasPiece(x+i,y+j)==true && piece->squareHasPiece(i,j)==true) return false;
        }
    }

    canBePlaced=false;
    for(int i=0; i<piece->getSizeX(); i++) //
    {
        for(int j=0; j<piece->getSizeY(); j++)
        {
            if(piece->squareHasPiece(i,j))
            {
                if(squareBelongsToPlayer(x+i-1,y+j-1,piece->getPlayer())) canBePlaced = true;
                if(squareBelongsToPlayer(x+i-1,y+j+1,piece->getPlayer())) canBePlaced = true;
                if(squareBelongsToPlayer(x+i+1,y+j-1,piece->getPlayer())) canBePlaced = true;
                if(squareBelongsToPlayer(x+i+1,y+j+1,piece->getPlayer())) canBePlaced = true;


                if(squareBelongsToPlayer(x+i-1,y+j,piece->getPlayer())) canBePlaced = false;
                if(squareBelongsToPlayer(x+i+1,y+j,piece->getPlayer())) canBePlaced = false;
                if(squareBelongsToPlayer(x+i,y+j-1,piece->getPlayer())) canBePlaced = false;
                if(squareBelongsToPlayer(x+i,y+j+1,piece->getPlayer())) canBePlaced = false;
            }
        }
    }
    return canBePlaced;
}

int Board::computeScore(Player* player)
{
    int score = 0;
    for(int i=0; i<14; i++){
        for(int j=0; j<14;j++){
            if(squareBelongsToPlayer(i,j,player->getSymbol())) score++;
        }
    }

    if(player->getNumberOfAvailablePieces()==0) score+=15;

    Piece* lastPiecePlayed = getLastPiecePlayedByPlayer(player);
    if(lastPiecePlayed->getId()==0) score+=5;

    return score;
}
