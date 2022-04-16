/*
 * user.hh
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#ifndef USER_HH_
#define USER_HH_

#include "tabuleiro.hh"

class userPlayer {
public:
	userPlayer();
	virtual ~userPlayer();

	int playRound(tabuleiro * t);    //returns column moved. NOT changes tabuleiro.
};

#endif /* USER_HH_ */
