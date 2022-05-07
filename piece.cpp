#include "piece.h"

// TODO: Implement here the methods of Piece

Piece::Piece(){
id=-1;
pieceSize=5;
player='-';
placed=false;
}

Piece::Piece(int pieceId, char piecePlayer, char pieceSquares[5][5]){
pieceSize=5;
placed=false;
player=piecePlayer;
id=pieceId;

for(int i=0; i<5;i++){
    for(int j=0; j<5; j++){
        squares[i][j].setCoordinates(i,j);
        if(pieceSquares[i][j]=='#' || pieceSquares[i][j]=='O')squares[i][j].addPiece(pieceSquares[i][j]);
        else squares[i][j].addPiece('-');
    }
}
}

int Piece::getId(){
return id;
}

char Piece::getPlayer(){
return player;
}

void Piece::setPlaced(){
placed=true;
}

bool Piece::isPlaced(){
return placed;
}

int Piece::getSize(){
return pieceSize;
}

Square Piece::getSquare(int x, int y){
return squares[x][y];
}

bool Piece::squareHasPiece(int x, int y){
if(squares[x][y].getPlayer()=='#' || squares[x][y].getPlayer()=='O') return true;
else return false;
}

void Piece::rotatePieceClockwise(){
Square temporary[5][5];
for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
        temporary[i][j].setCoordinates(i,j);
        temporary[i][j].addPiece(squares[i][j].getPlayer());
    }
}
for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
        if(temporary[i][j].getPlayer()!='-') squares[4-j][i].addPiece(temporary[i][j].getPlayer());
        else squares[4-j][i].addPiece('-');
}
}
}

void Piece::rotatePiece(char orientation){
if(orientation=='r') rotatePieceClockwise();
else if(orientation=='d') {
    rotatePieceClockwise();
    rotatePieceClockwise();
}
else if (orientation=='l'){
    rotatePieceClockwise();
    rotatePieceClockwise();
    rotatePieceClockwise();
}
}

void Piece::flipPiece(){
Square temporary[5][5];
for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
        temporary[i][j].setCoordinates(i,j);
        temporary[i][j].addPiece(squares[i][j].getPlayer());
    }
}
for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
        if(temporary[i][j].getPlayer()!='-') squares[i][4-j].addPiece(temporary[i][j].getPlayer());
        else squares[i][4-j].addPiece('-');
}
}
}
