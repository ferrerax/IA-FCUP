/*
 * player.cc
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#include "player.hh"

Player::Player() {
	// TODO Auto-generated constructor stub

}

char Player::opponentToken() {
	return token == 'x' ? 'o' : 'x';
}

float Player::getMeanTime() {
	return this->time/(double)this->turns_played;
}

int Player::getMeanNodes() {
	return this->nodes/this->turns_played;
}
//Player::~Player() {
//	// TODO Auto-generated destructor stub
//}

