/*
 * user.cc
 *
 *  Created on: 16 d’abr. 2022
 *      Author: quim
 */

#include "user.hh"
#include <iostream>

using namespace std;


userPlayer::userPlayer() {
	// TODO Auto-generated constructor stub

}

userPlayer::~userPlayer() {
	// TODO Auto-generated destructor stub
}

int userPlayer::playRound(tabuleiro *t) {

	int num; //error

	cout << "[+] Current Table:" << endl << endl;
	t->print_formatted();
	cout << "Users move (number between 0 - " << N_COLUMN << " indicating column):";
	cin >> num;
	cout << endl;

	num = num < N_COLUMN and num > 0 ? num : -1;  //Checking user input.

	return num;
}
