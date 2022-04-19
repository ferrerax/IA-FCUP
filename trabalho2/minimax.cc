/*
 * minimax.cc
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

#include "minimax.hh"
#include <iostream>

using namespace std;


minimaxPlayer::minimaxPlayer(char token) {
	// TODO Auto-generated constructor stub
	this->token = token;

}

minimaxPlayer::~minimaxPlayer() {
	// TODO Auto-generated destructor stub
}

int minimaxPlayer::r_minimax(tabuleiro *t, int depth, char player) {
	tabuleiro * options[N_COLUMN];
	int value = is_maximizing(depth,player) ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

	if (depth < MINIMAX_DEPTH){
		t->getOptions(options); //Cal implementar
		if (is_maximizing(depth, player)){
			for (int i = 0; i < N_COLUMN; i++){
				value = MAX(value,r_minimax(t, depth, player));
			}
		} else {
			for (int i = 0; i < N_COLUMN; i++){
				value = MIN(value,r_minimax(t, depth, player));
			}
		}
	}
	if (depth != 0){
		delete t;
	}

	return t->getUtility();

}

bool minimaxPlayer::is_maximizing(int depth, char player) {
	bool res = false;
	if (player == 'x'){
		res = depth%2 != 0; //ha de maximitzar les profunditats parells
	} else {
		res = depth%2 == 0; //ha de maximitzar les profunditats imparells
	}
	return res;
}

int minimaxPlayer::playRound(tabuleiro *t) {

	int num; //error

	cout << "[+] Current Table:" << endl << endl;
	t->print_formatted();

	num = r_minimax(t,0,this->token);

	num = num < N_COLUMN and num >= 0 ? num : -1;  //Checking minimax input.

	return num;
}
