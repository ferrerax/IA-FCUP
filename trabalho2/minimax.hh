/*
 * minimax.hh
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#ifndef minimax_HH_
#define minimax_HH_

#include "tabuleiro.hh"
#include "player.hh"

class minimaxPlayer : public Player{

private:
	int r_minimax(tabuleiro * t, int depth, char player);
	bool is_maximizing(int depth,char player);

public:
	minimaxPlayer(char token);
	virtual ~minimaxPlayer();

	int playRound(tabuleiro * t);    //returns column moved. NOT changes tabuleiro.
};

#endif /* minimax_HH_ */
