/*
 * alfabeta.cc
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#define MAX(x, y) (x >= y ? x : y)
#define MIN(x, y) (x < y ? x : y)

#include "alfabeta.hh"
#include <iostream>
#include <map>


using namespace std;


alfabetaPlayer::alfabetaPlayer(char token) {
	// TODO Auto-generated constructor stub
	this->token = token;

}

alfabetaPlayer::~alfabetaPlayer() {
	// TODO Auto-generated destructor stub
}


int alfabetaPlayer::first_alfabeta(tabuleiro *t, char player) {
	map<int,tabuleiro *> min_map;
	map<int,tabuleiro *,greater<int>> max_map;
	int best_move;
	int aux,i = 0;
	int value = player == 'x' ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

	if (player == 'x'){
		t->getOptionsMapMax(max_map,player);
		auto iter = max_map.begin();
		while(iter != max_map.end()){
			if ( (aux = MAX(value,r_alfabeta(iter->second, iter->first, 1, false, -MINIMAX_MAX_UTILITY, MINIMAX_MAX_UTILITY)) ) >= value ){
				value = aux;
				best_move = i;
				delete iter->second;
			}
			iter++;
			i++;
		}
	} else {
		t->getOptionsMapMin(min_map,player);
		auto iter = min_map.begin();
		while(iter != min_map.end()){
			if ( (aux = MIN(value,r_alfabeta(iter->second, iter->first, 1, true, -MINIMAX_MAX_UTILITY, MINIMAX_MAX_UTILITY)) ) < value ){
				value = aux;
				best_move = i;
				delete iter->second;
			}
			iter++;
			i++;
		}
	}

	return best_move;

}

int alfabetaPlayer::r_alfabeta(tabuleiro *t, int util, int depth, bool maximize, int alfa, int beta) {
	map<int,tabuleiro *> min_map;
	map<int,tabuleiro *,greater<int>> max_map;
	static int best_move;
	int value = maximize ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

	if (depth < ALFABETA_DEPTH and util != 512 and util != -512){
		if (maximize){
			t->getOptionsMapMax(max_map,maximize ? 'x' : 'o');
			auto iter = max_map.begin();
			while(iter != max_map.end()){
				value = MAX(value,r_alfabeta(iter->second, iter->first, depth+1, not maximize, alfa, beta)); //tracto fill
				delete iter->second;
				if (value >= beta){
					break;
				}
				alfa = MAX(value,alfa);
				iter++;
			}
			return value;
		}
		else {
			t->getOptionsMapMin(min_map,maximize ? 'x' : 'o');
			auto iter = min_map.begin();
			while(iter != min_map.end()){
				value = MIN(value,r_alfabeta(iter->second, iter->first, depth+1, not maximize, alfa, beta));
				delete iter->second;
				if (value <= alfa){
					break;
				}
				beta = MIN(value,beta);
				iter++;
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
