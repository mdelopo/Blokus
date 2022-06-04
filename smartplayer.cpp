#include "smartplayer.h"
#include "algorithms.h"

SmartPlayer::SmartPlayer(int id) : Player(id) {
    name = "Team 037"; // TODO: Change this to your team number e.g. "Team 150"
}

Move* SmartPlayer::makeMove(Board* board) {
    int numPossibleMoves;
    Move** possibleMoves = getPossibleMoves(board, numPossibleMoves);
    int *moveScores = new int[numPossibleMoves];
    for (int i = 0; i < numPossibleMoves; i++)
        moveScores[i] = evaluateMove(board, possibleMoves[i]);
    int * distances = new int[numPossibleMoves];
    if (!getId()) {
        for (int i = 0; i < numPossibleMoves; i++){
            distances[i]=1000000;
            Piece *movepiece = possibleMoves[i]->getPiece();
            for (int x=0; x<movepiece->getSizeX(); x++){
                for (int y=0; y<movepiece->getSizeY(); y++){
                    if (movepiece->squareHasPiece(x,y)) {
                            int distance = ((x+possibleMoves[i]->getX()-7)*(x+possibleMoves[i]->getX()-7)+(y+possibleMoves[i]->getY()-7)*(y+possibleMoves[i]->getY()-7));
                        if(distance < distances[i])
                           distances[i] = distance;
                    }
                }
            }
        }
    }
    if (getId()) {
        for (int i = 0; i < numPossibleMoves; i++){
            distances[i]=1000000;
            Piece *movepiece = possibleMoves[i]->getPiece();
            for (int x=0; x<movepiece->getSizeX(); x++){
                for (int y=0; y<movepiece->getSizeY(); y++){
                    if (movepiece->squareHasPiece(x,y)) {
                            int distance = ((x+possibleMoves[i]->getX()-6)*(x+possibleMoves[i]->getX()-6)+(y+possibleMoves[i]->getY()-6)*(y+possibleMoves[i]->getY()-6));
                        if(distance < distances[i])
                           distances[i] = distance;
                    }
                }
            }
        }
    }
    for (int i = 0; i < numPossibleMoves; i++)
        moveScores[i] = moveScores[i] - distances[i];
     Move* moveToPlay = new Move(getElementWithMaxScore(possibleMoves, moveScores, numPossibleMoves));

    for (int i = 0; i < numPossibleMoves; i++) delete possibleMoves[i];
        delete[] possibleMoves;
        delete[] moveScores;



    return moveToPlay;
}

int SmartPlayer::evaluateBoard(Board* board)
{
    int scores[2], score = 0;
    char symbols[2];
    symbols[getId()] = getSymbol();
    symbols[opponent->getId()] = opponent->getSymbol();

    for(int id=0; id<2; id++) //epanalipsi gia tous 2 players
    {
        scores[id]=0;
        for(int x=0; x<board->getSizeX(); x++) //katametrisi kateilimmenon square
        {
            for(int y=0; y<board->getSizeY(); y++)
            {
                if(board->squareBelongsToPlayer(x,y,symbols[id])) scores[id]+=1;
            }
        }
    }
    score = scores[getId()] - scores[opponent->getId()]; //ypologismos score
    return score;
}
