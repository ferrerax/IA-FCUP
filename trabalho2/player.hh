/*
 * player.hh
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#ifndef PLAYER_HH_
#define PLAYER_HH_

#include "tabuleiro.hh"

class Player {  //Abstract

protected:
	char token;
	float time;
	int turns_played;
	int nodes;

public:
	Player();
	virtual ~Player() = default;

	virtual int playRound(tabuleiro * t) = 0;    //returns column moved NOT changes tabulairo.
	char opponentToken();
};

#endif /* PLAYER_HH_ */
