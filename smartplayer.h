#ifndef SMARTPLAYER_H
#define SMARTPLAYER_H

#include "player.h"

/**
 * Class that implements a smart player that plays according to the state of the game.
 */
class SmartPlayer : public Player {
public:
    /**
     * Initializes a smart player calling the constructor of the player.
     *
     * @param id the id of the player.
     */
    SmartPlayer(int id);

    /**
     * Receives the current state of the board and returns a move.
     *
     * @return an object of type Move containing a piece, its position, its orientation, and its flip.
     */
    Move* makeMove(Board* board);
    int evaluateBoard(Board* board);
};

#endif // SMARTPLAYER_H
