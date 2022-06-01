#include "player.h"
#include "algorithms.h"

ComputerPlayer::ComputerPlayer(int id) : Player(id) {

}

int ComputerPlayer::evaluateBoard(Board* board)
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

Move* ComputerPlayer::makeMove(Board* board) {
    // Get possible moves of all pieces
    int numPossibleMoves;
    Move** possibleMoves = getPossibleMoves(board, numPossibleMoves);

    // Get scores of the possible moves
    int* possibleMovesScores = new int[numPossibleMoves];
    for (int i = 0; i < numPossibleMoves; i++)
        possibleMovesScores[i] = evaluateMove(board, possibleMoves[i]);

    // Get the move to play
    Move* moveToPlay = new Move(getElementWithMaxScore(possibleMoves, possibleMovesScores, numPossibleMoves));

    // Delete the possible moves and the scores
    for (int i = 0; i < numPossibleMoves; i++)
        delete possibleMoves[i];
    delete[] possibleMoves;
    delete[] possibleMovesScores;

    // Return the move to play
    return moveToPlay;
}
