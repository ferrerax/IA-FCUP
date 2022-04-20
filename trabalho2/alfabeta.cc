/*
 * alfabeta.cc
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

#include "alfabeta.hh"
#include <iostream>

using namespace std;


alfabetaPlayer::alfabetaPlayer(char token) {
	// TODO Auto-generated constructor stub
	this->token = token;

}

alfabetaPlayer::~alfabetaPlayer() {
	// TODO Auto-generated destructor stub
}


int alfabetaPlayer::first_alfabeta(tabuleiro *t, char player) {
	tabuleiro * options[N_COLUMN];
	int best_move;
	int aux;
	int value = player == 'x' ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

		t->getOptions(options,player);
		if (player == 'x'){
			for (int i = 0; i < N_COLUMN; i++){
				if ( options[i] and (aux = MAX(value,r_alfabeta(options[i], 1, -MINIMAX_MAX_UTILITY, MINIMAX_MAX_UTILITY, false)) ) > value ){
					value = aux;
					best_move = i;
					delete options[i];
				}
			}
		} else {
			for (int i = 0; i < N_COLUMN; i++){
				if ( options[i] and (aux = MIN(value,r_alfabeta(options[i], 1, -MINIMAX_MAX_UTILITY, MINIMAX_MAX_UTILITY, true)) ) < value ){
					value = aux;
					best_move = i;
					delete options[i];
				}
			}
		}

	return best_move;

}

int alfabetaPlayer::r_alfabeta(tabuleiro *t, int depth, bool maximize, int alfa, int beta) {
	tabuleiro * options[N_COLUMN];
	static int best_move;
	int util;
	int value = maximize ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

	util = t->getUtility();  	//Estem sempre calculant la utility i aixo es lent.
	if (depth < ALFABETA_DEPTH and util != 512 and util != -512){
		t->getOptions(options,maximize ? 'x' : 'o');
		if (maximize){  //mes eficient que tenir els ifs dins del for.
			for (int i = 0; i < N_COLUMN; i++){
				if(options[i]){
					value = MAX(value,r_alfabeta(options[i], depth+1, alfa, beta, not maximize)); //tracto fill
					delete options[i];
					if (value >= beta){
						break;
					}
					alfa = MAX(value,alfa);
				}
			}
			return value;
		} else {
			for (int i = 0; i < N_COLUMN; i++){
				if (options[i]){
					value = MIN(value,r_alfabeta(options[i], depth+1, alfa, beta, not maximize)); //borro fill
					delete options[i];
					if (value <= alfa){
						break;
					}
					beta = MIN(value,alfa);
				}
			}
			return value;
		}
	}


	return util;

}

bool alfabetaPlayer::is_maximizing(int depth, char player) {
	bool res = false;
	if (player == 'x'){
		res = true;
	} else {
		res = false;
	}
	return res;
}

int alfabetaPlayer::playRound(tabuleiro *t) {

	int num; //error


	num = first_alfabeta(t,this->token);

	num = num < N_COLUMN and num >= 0 ? num : -1;  //Checking alfabeta input.

	return num;
}
