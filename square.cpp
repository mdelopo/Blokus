#include <iostream>
#include "square.h"

// TODO: Implement here the methods of Square

Square::Square(){
x=-1;
y=-1;
player='-';
}

void Square::setCoordinates(int newx, int newy){
x=newx;
y=newy;
}

int Square::getX(){
return x;
}

int Square::getY(){
return y;
}

void Square::addPiece(char piecePlayer){
player=piecePlayer;
}

void Square::removePiece(){
player='-';
}

bool Square::hasPiece(){
if(player=='#'|| player=='O') return true;
else return false;
}

char Square::getPlayer(){
return player;
}
