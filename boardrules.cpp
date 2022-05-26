#include "board.h"
#include "player.h"

// TODO: Implement here the method pieceCanBePlaced and computeScore of Board
// Do not implement any other methods of Board (as they are already implemented in file board.cpp)

bool Board::pieceCanBePlaced(Piece* piece, int x, int y)
{
    //oria tou board
    if(x<0 || x+piece->getSizeX()-1>13) return false;
    if(y<0 || y+piece->getSizeY()-1>13) return false;

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
        return false;
    }

    for(int i=0; i<piece->getSizeX(); i++) //kateilimmeno square
    {
        for(int j=0; j<piece->getSizeY(); j++)
        {
            if(hasPiece(x+i,y+j)==true && piece->squareHasPiece(i,j)==true) return false;
        }
    }

    bool canBePlaced=false;
    for(int i=0; i<piece->getSizeX(); i++)
    {
        for(int j=0; j<piece->getSizeY(); j++)
        {
            if(piece->squareHasPiece(i,j))
            {
                //gwnies
                if(x+i-1>=0 && x+i-1<=13 && y+j-1>=0 && y+j-1<=13) if(squareBelongsToPlayer(x+i-1,y+j-1,piece->getPlayer())) canBePlaced = true;
                if(x+i-1>=0 && x+i-1<=13 && y+j+1>=0 && y+j+1<=13) if(squareBelongsToPlayer(x+i-1,y+j+1,piece->getPlayer())) canBePlaced = true;
                if(x+i+1>=0 && x+i+1<=13 && y+j-1>=0 && y+j-1<=13) if(squareBelongsToPlayer(x+i+1,y+j-1,piece->getPlayer())) canBePlaced = true;
                if(x+i+1>=0 && x+i+1<=13 && y+j+1>=0 && y+j+1<=13) if(squareBelongsToPlayer(x+i+1,y+j+1,piece->getPlayer())) canBePlaced = true;

                //pleyres
                if(x+i-1>=0 && x+i-1<=13 && y+j>=0 && y+j<=13) if(squareBelongsToPlayer(x+i-1,y+j,piece->getPlayer())) return false;
                if(x+i+1>=0 && x+i+1<=13 && y+j>=0 && y+j<=13) if(squareBelongsToPlayer(x+i+1,y+j,piece->getPlayer())) return false;
                if(x+i>=0 && x+i<=13 && y+j-1>=0 && y+j-1<=13) if(squareBelongsToPlayer(x+i,y+j-1,piece->getPlayer())) return false;
                if(x+i>=0 && x+i<=13 && y+j+1>=0 && y+j+1<=13) if(squareBelongsToPlayer(x+i,y+j+1,piece->getPlayer())) return false;
            }
        }
    }
    return canBePlaced;
}

int Board::computeScore(Player* player)
{
    int score = 0;
    for(int i=0; i<14; i++)
    {
        for(int j=0; j<14; j++)
        {
            if(squareBelongsToPlayer(i,j,player->getSymbol())) score++;
        }
    }

    if(player->getNumberOfAvailablePieces()==0) score+=15; //o player epaikse ola ta kommatia (+15 pontoi)

    Piece* lastPiecePlayed = getLastPiecePlayedByPlayer(player);
    if(lastPiecePlayed->getId()==0) score+=5; //o player epaikse teleytaio to piece 1 (+5 pontoi)

    return score;
}
