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
public:
	Player();
	virtual ~Player() = default;

	virtual int playRound(tabuleiro * t);    //returns column moved NOT changes tabulairo.

};

#endif /* PLAYER_HH_ */
