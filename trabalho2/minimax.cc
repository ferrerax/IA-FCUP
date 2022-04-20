/*
 * minimax.cc
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#define MAX(x, y) (x >= y ? x : y)
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


int minimaxPlayer::first_minimax(tabuleiro *t, char player) {
	tabuleiro * options[N_COLUMN];
	int best_move;
	int aux;
	int value = player == 'x' ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

		t->getOptions(options,player);
		if (player == 'x'){
			for (int i = 0; i < N_COLUMN; i++){
				if (options[i] and (aux = MAX(value,r_minimax(options[i], 1, false)) ) >= value ){
					value = aux;
					best_move = i;
					delete options[i];
				}
			}
		} else {
			for (int i = 0; i < N_COLUMN; i++){
				if (options[i] and (aux = MIN(value,r_minimax(options[i], 1, true)) ) < value ){
					value = aux;
					best_move = i;
					delete options[i];
				}
			}
		}

	return best_move;

}

int minimaxPlayer::r_minimax(tabuleiro *t, int depth, bool maximize) {
	tabuleiro * options[N_COLUMN];
	static int best_move;
	int util;
	int value = maximize ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

	util = t->getUtility();  	//Estem sempre calculant la utility i aixo es lent.
	if (depth < MINIMAX_DEPTH and util != 512 and util != -512){
		t->getOptions(options,maximize ? 'x' : 'o');
		if (maximize){  //mes eficient que tenir els ifs dins del for.
			for (int i = 0; i < N_COLUMN; i++){
				if(options[i]){
					value = MAX(value,r_minimax(options[i], depth+1, not maximize)); //tracto fill
					delete options[i];
				}
			}
			return value;
		} else {
			for (int i = 0; i < N_COLUMN; i++){
				if (options[i]){
					value = MIN(value,r_minimax(options[i], depth+1, not maximize)); //borro fill
					delete options[i];
				}
			}
			return value;
		}
	}


	return util;

}

bool minimaxPlayer::is_maximizing(int depth, char player) {
	bool res = false;
	if (player == 'x'){
		res = true;
	} else {
		res = false;
	}
	return res;
}

int minimaxPlayer::playRound(tabuleiro *t) {

	int num; //error


	num = first_minimax(t,this->token);
	num = num < N_COLUMN and num >= 0 ? num : -1;  //Checking minimax input.


	return num;
}
