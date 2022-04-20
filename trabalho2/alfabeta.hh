/*
 * alfabeta.hh
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#ifndef alfabeta_HH_
#define alfabeta_HH_

#include "tabuleiro.hh"
#include "player.hh"

class alfabetaPlayer : public Player{

private:
	int r_alfabeta(tabuleiro * t, int depth, bool maximize, int alfa, int beta);
	int first_alfabeta(tabuleiro *t, char player);
	bool is_maximizing(int depth,char player);

public:
	alfabetaPlayer(char token);
	virtual ~alfabetaPlayer();

	int playRound(tabuleiro * t);    //returns column moved. NOT changes tabuleiro.
};

#endif /* alfabeta_HH_ */
