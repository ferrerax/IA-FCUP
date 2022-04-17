/*
 * user.hh
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#ifndef USER_HH_
#define USER_HH_

#include "tabuleiro.hh"
#include "player.hh"

class userPlayer : public Player{
public:
	userPlayer();
	virtual ~userPlayer();

	int playRound(tabuleiro * t);    //returns column moved. NOT changes tabuleiro.
};

#endif /* USER_HH_ */
