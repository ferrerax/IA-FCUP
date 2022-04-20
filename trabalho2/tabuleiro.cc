#include "tabuleiro.hh"
#include <iostream>
#include<string.h>
#include <cmath>

using namespace std;

//tabuleiro::tabuleiro(char *numbs) {
//    memcpy(matriu, numbs, N_NUMEROS);
//}

tabuleiro::tabuleiro()
{
    memset(matriu, '-', N_NUMEROS);
    
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

	int sum, total_sum = 0;
	int cont;
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

tabuleiro::tabuleiro(tabuleiro * t) {
	memcpy(matriu,t->matriu,sizeof(matriu));
}
