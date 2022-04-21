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
	this->nodes = 0;
	this->time = 0;
	this->turns_played = 0;

}

alfabetaPlayer::~alfabetaPlayer() {
	// TODO Auto-generated destructor stub
}


int alfabetaPlayer::first_alfabeta(tabuleiro *t, char player) {
	multimap<int,tabuleiro *> min_map;
	multimap<int,tabuleiro *,greater<int>> max_map;
	int best_move;
	int aux = 0;
	int value = player == 'x' ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

	if (player == 'x'){
		t->getOptionsMapMax(max_map,player);
		auto iter = max_map.begin();
		while(iter != max_map.end()){
			this->nodes++;
			if ( (aux = MAX(value,r_alfabeta(iter->second, iter->first, 1, false, -MINIMAX_MAX_UTILITY, MINIMAX_MAX_UTILITY)) ) > value ){
				value = aux;
				best_move = iter->second->getMov()%N_COLUMN;
				delete iter->second;
			}
			iter++;
		}
	} else {
		t->getOptionsMapMin(min_map,player);
		auto iter = min_map.begin();
		while(iter != min_map.end()){
			this->nodes++;
			if ( (aux = MIN(value,r_alfabeta(iter->second, iter->first, 1, true, -MINIMAX_MAX_UTILITY, MINIMAX_MAX_UTILITY)) ) < value ){
				value = aux;
				best_move = iter->second->getMov()%N_COLUMN;
				delete iter->second;
			}
			iter++;
		}
	}

	return best_move;

}

int alfabetaPlayer::r_alfabeta(tabuleiro *t, int util, int depth, bool maximize, int alfa, int beta) {
	multimap<int,tabuleiro *> min_map;
	multimap<int,tabuleiro *,greater<int>> max_map;
	static int best_move;
	int value = maximize ? -MINIMAX_MAX_UTILITY : MINIMAX_MAX_UTILITY;

	if (depth < ALFABETA_DEPTH and util != 512 and util != -512){
		if (maximize){
			t->getOptionsMapMax(max_map,maximize ? 'x' : 'o');
			auto iter = max_map.begin();
			while(iter != max_map.end()){
				this->nodes++;
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
				this->nodes++;
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

//bool alfabetaPlayer::is_maximizing(int depth, char player) {
//	bool res = false;
//	if (player == 'x'){
//		res = true;
//	} else {
//		res = false;
//	}
//	return res;
//}

int alfabetaPlayer::playRound(tabuleiro *t) {

	int num; //error

	this->turns_played++;
	double c_start = clock();
	num = first_alfabeta(t,this->token);
	num = num < N_COLUMN and num >= 0 ? num : -1;  //Checking alfabeta input.
	this->time += 1000.0 * (clock() - c_start)/CLOCKS_PER_SEC;

	return num;
}
