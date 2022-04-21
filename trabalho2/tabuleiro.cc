#include "tabuleiro.hh"
#include <iostream>
#include<string.h>
#include <cmath>
#include <bits/stdc++.h>

#include <vector>

using namespace std;

//tabuleiro::tabuleiro(char *numbs) {
//    memcpy(matriu, numbs, N_NUMEROS);
//}

tabuleiro::tabuleiro()
{
    memset(matriu, '-', N_NUMEROS);
    mov = 0;
    
    //debug

//    char matriu_aux[] = {
//    		'x','o','x','x','o','x','x',
//			'x','x','-','o','x','o','x',
//			'x','o','-','o','o','x','-',
//			'o','o','-','o','o','o','-',
//			'x','x','-','-','o','x','-',
//			'x','o','-','-','-','o','-'
//    };
//
//    memcpy(matriu,matriu_aux,sizeof(matriu_aux));

	std::random_device rndDevice;
	randomEng = new std::mt19937(rndDevice());

	moves = getMoves();

}

bool tabuleiro::comparar_tabs(tabuleiro *a, tabuleiro *b)
{
    for (int i = 0; i < N_NUMEROS; i++)
    {
        if (a->matriu[i] != b->matriu[i])
        {
            return false;
        }
    }
    return true;
    
}



int tabuleiro::checkWinner() {
	int winner = 0;
	int utility = calcUtility();

	if (utility == 512)
		winner = 1;
	else if (utility == -512){
		winner = 2;
	}

	return winner;
}

bool tabuleiro::lastMovementWon(char lastPlayer)
{

	int last_col = this->mov % N_COLUMN;
	int last_row = this->mov / N_COLUMN;

	// X X X X
	int left = 0, right = 0;
	for (int col = last_col - 1; col >= 0 && matriu[last_row*N_COLUMN + col] == lastPlayer; --col)
		left++;
	for (int col = last_col + 1; col < N_COLUMN && matriu[last_row*N_COLUMN + col] == lastPlayer; ++col)
		right++;
	if (left + 1 + right >= 4)
	{
		return true;
	}

	// X
	// X
	// X
	// X
	int up = 0, down = 0;
	for (int row = last_row - 1; row >= 0 && matriu[row*N_COLUMN + last_col] == lastPlayer; --row)
		up++;
	for (int row = last_row + 1; row < N_ROW && matriu[row*N_COLUMN + last_col] == lastPlayer; ++row)
		down++;
	if (up + 1 + down >= 4)
	{
		return true;
	}

	// X
	//  X
	//   X
	//    X
	up = 0;
	down = 0;
	for (int row = last_row - 1, col = last_col - 1; row >= 0 && col >= 0 && matriu[row*N_COLUMN + col] == lastPlayer; --row, --col)
		up++;
	for (int row = last_row + 1, col = last_col + 1; row < N_ROW && col < N_COLUMN && matriu[row*N_COLUMN + col] == lastPlayer; ++row, ++col)
		down++;
	if (up + 1 + down >= 4)
	{
		return true;
	}

	//    X
	//   X
	//  X
	// X
	up = 0;
	down = 0;
	for (int row = last_row + 1, col = last_col - 1; row < N_ROW && col >= 0 && matriu[row*N_COLUMN + col] == lastPlayer; ++row, --col)
		up++;
	for (int row = last_row - 1, col = last_col + 1; row >= 0 && col < N_COLUMN && matriu[row*N_COLUMN + col] == lastPlayer; --row, ++col)
		down++;
	if (up + 1 + down >= 4)
	{
		return true;
	}

	return false;
}



string tabuleiro::getHash() {
	string aux(this->matriu);
	return aux;
}

void tabuleiro::print()
{
    for (size_t i = 0; i < N_NUMEROS; i++)
    {
        cout << to_string((int) this->matriu[i]) << " ";
    }
    cout << endl;
    
}

bool tabuleiro::makeMove(int col, char player) {  //changes tabuleiro
	for (int i = N_ROW - 1; i >= 0; i--){
		if(matriu[i*N_COLUMN+col] == '-'){
			matriu[i*N_COLUMN+col] = player;
			mov = i*N_COLUMN+col;
			updateMoves();
			return true;
		}
	}
	
	 return false;   //Movement coudln't be done.
}

void tabuleiro::print_formatted()
{
    for (size_t i = 0; i < N_ROW; i++)
    {
        for (size_t j = 0; j < N_COLUMN; j++)
        {
            if (matriu[i * N_COLUMN + j] < 10) cout << " ";
            cout << this->matriu[i * N_COLUMN + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    

}

int tabuleiro::getUtility() {
	return calcUtility();
}

int tabuleiro::calcUtility() {

	int sum = 0;
	int total_sum = 0;
	int cont = 0;
	char token;

	//Lines
	for (int i = 0; i < N_ROW*N_COLUMN; i++){  	//recorre tota la matriu

		token = this->matriu[i];
		cont = token != '-' ? 1 : 0;									//Contem primer token
		for (int k = 1; k < 4; k++){			//Mirem el segment a veure que passa.
			if (token == '-' and token != this->matriu[i+k]){
				token = this->matriu[i+k];
			} else if (token == '-') {
				continue;
			}
			if(this->matriu[i+k] == token){		//Seguim amb token igual
				cont++;
			} else if (this->matriu[i+k] == '-') { //esta be contar espais blancs, anem be.
				continue;
			} else {							//En un mateix segment conviuen x i o. Cal sumar 0 al resultat.
				cont = 0;						//Buidem el compte i sortim.
				break;
			}
		}
		if(token == 'x'){
			if(cont == 4){
				return 512;
			}
			sum += this->punts[cont];
		} else {
			if(cont == 4){
				return -512;
			}
			sum -= this->punts[cont];
		}

		if ( (i+4)%N_COLUMN == 0 and i != 0){ 					//Estem mirant lultim segment
			i += 3;  							//Canvi de fila
		}
	}

	total_sum += sum;
	sum = 0;

	//Columns
	for (int j = 0; j < N_COLUMN; j++)			//Aqui ho faig mes facil. ja optimitzarem si volem, fa palot.
		for (int i = 0; i < N_ROW-3; i++){  	//recorre tota la matriu
			token = this->matriu[i*N_COLUMN+j];
			cont = token != '-' ? 1 : 0;									//Contem primer token
			for (int k = 1; k < 4; k++){
				if (token == '-' and token != this->matriu[(i+k)*N_COLUMN+j]){
					token = this->matriu[(i+k)*N_COLUMN+j];
				} else if (token == '-') {
					continue;
				}
				if(this->matriu[(i+k)*N_COLUMN+j] == token){		//Seguim amb token igual
					cont++;
				} else if (this->matriu[(i+k)*N_COLUMN+j] == '-') { //esta be contar espais blancs, anem be.
					continue;
				} else {							//En un mateix segment conviuen x i o. Cal sumar 0 al resultat.
					cont = 0;						//Buidem el compte i sortim.
					break;
				}
			}

			if(token == 'x'){
				if(cont == 4){
					return 512;
				}
				sum += this->punts[cont];
			} else {
				if(cont == 4){
					return -512;
				}
				sum -= this->punts[cont];
			}


		}

	total_sum += sum;
	sum = 0;

	//Diagonal
	for (int i = 0; i < N_ROW-3; i++)			//Aqui ho faig mes facil. ja optimitzarem si volem, fa palot.
		for (int j = 0; j < N_COLUMN-3; j++){  	//recorre tota la matriu
			token = this->matriu[i*N_COLUMN+j];
			cont = token != '-' ? 1 : 0;									//Contem primer token
			for (int k = 1; k < 4; k++){
				if (token == '-' and token != this->matriu[(i+k)*N_COLUMN+j+k]){
					token = this->matriu[(i+k)*N_COLUMN+j+k];
				} else if (token == '-') {
					continue;
				}
				if(this->matriu[(i+k)*N_COLUMN+j+k] == token){		//Seguim amb token igual
					cont++;
				} else if (this->matriu[(i+k)*N_COLUMN+j+k] == '-') { //esta be contar espais blancs, anem be.
					continue;
				} else {							//En un mateix segment conviuen x i o. Cal sumar 0 al resultat.
					cont = 0;						//Buidem el compte i sortim.
					break;
				}
			}

			if(token == 'x'){
				if(cont == 4){
					return 512;
				}
				sum += this->punts[cont];
			} else {
				if(cont == 4){
					return -512;
				}
				sum -= this->punts[cont];
			}
		}

	total_sum += sum;
	sum = 0;

	//Antidiagonal
	for (int i = 0; i < N_ROW-3; i++)			//Aqui ho faig mes facil. ja optimitzarem si volem, fa palot.
		for (int j = 3; j < N_COLUMN; j++){  	//recorre tota la matriu
			token = this->matriu[i*N_COLUMN+j];
			cont = token != '-' ? 1 : 0;									//Contem primer token
			for (int k = 1; k < 4; k++){
				if (token == '-' and token != this->matriu[(i+k)*N_COLUMN+j-k]){
					token = this->matriu[(i+k)*N_COLUMN+j-k];
				} else if (token == '-') {
					continue;
				}
				if(this->matriu[(i+k)*N_COLUMN+j-k] == token){		//Seguim amb token igual
					cont++;
				} else if (this->matriu[(i+k)*N_COLUMN+j-k] == '-') { //esta be contar espais blancs, anem be.
					continue;
				} else {							//En un mateix segment conviuen x i o. Cal sumar 0 al resultat.
					cont = 0;						//Buidem el compte i sortim.
					break;
				}
			}
			if(token == 'x'){
				if(cont == 4){
					return 512;
				}
				sum += this->punts[cont];
			} else {
				if(cont == 4){
					return -512;
				}
				sum -= this->punts[cont];
			}
		}

	total_sum += sum;


	return total_sum;

}

void tabuleiro::getOptions(tabuleiro *t_array[], char player) {

	//Cal implementar. ha de retornar tots els possibles moviments (OJO QUE HI HA MOVIMENTS QUE NO ES PODEN FER SI LES COLUMNES ESTAN PLENES!!!!)

	for (int i = 0; i < N_COLUMN; i++){
		t_array[i] = new tabuleiro(this);  			//Creo nou tabuleiro
		if(not t_array[i]->makeMove(i, player)){	//Mirem que es pugui fer el moviment
			delete t_array[i];						//No es pot fer el moviment aixi que buidem memoria i posem un nullet.
			t_array[i] = nullptr;
		}
	}
}

std::vector<int> tabuleiro::getMoves() {
	std::vector<int> moves;
	moves.reserve(N_COLUMN);

	for (int col = 0; col < N_COLUMN; ++col)
	{
		if (matriu[(N_ROW-1) + (N_ROW*col)] == '-')
		{
			moves.push_back(col);
		}
	}

	return moves;
}

int tabuleiro::getNumberMoves()
{
	return moves.size();
}

void tabuleiro::updateMoves()
{
	if(mov / N_COLUMN == 0) {
		moves.erase(std::remove(moves.begin(), moves.end(), mov%N_COLUMN), moves.end());
	}
}

int tabuleiro::simulateMove()
{
	//std::uniform_int_distribution<int> dist(0, moves.size() - 1);
	return moves[rand() % moves.size()];
}

tabuleiro::tabuleiro(tabuleiro * t) {
	memcpy(matriu,t->matriu,sizeof(matriu));
	moves = t->getMoves();

	std::random_device rndDevice;
	randomEng = new std::mt19937(rndDevice());
	mov = 0;
}

void tabuleiro::getOptionsMapMax(std::multimap<int, tabuleiro*, std::greater<int> > &m, char player) {

	tabuleiro * aux;

	for (int i = 0; i < N_COLUMN; i++){
		aux = new tabuleiro(this);
		if(aux->makeMove(i, player)){
			m.insert(make_pair(aux->getUtility(),aux));
		} else {
			delete aux;
		}
	}
}

void tabuleiro::getOptionsMapMin(std::multimap<int, tabuleiro*> &m, char player) {

	tabuleiro * aux;

	for (int i = 0; i < N_COLUMN; i++){
		aux = new tabuleiro(this);
		aux->mov = i;
		if(aux->makeMove(i, player)){
			m.insert(make_pair(aux->getUtility(),aux));
		} else {
			delete aux;
		}
	}
}

int tabuleiro::getMov() {
	return this->mov;
}
