#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "config.hh"
#include "jogo.hh"

using namespace std;

int main(int argc, char *argv[])
{

	t_player opt_p1, opt_p2;
	Jogo j;

	if(argc < 3) {
		Usage();
	}

	string opt1, opt2;
	opt1 = argv[1];
	opt2 = argv[2];

	if(opt1 == "User") 
		opt_p1 = p_USER;
	else if(opt1 == "MCTS") 
		opt_p1 = p_MCTS;
	else if(opt1 == "MiniMax")
		opt_p1 = p_MM;
	else if (opt1 == "AlphaBeta")
		opt_p1 = p_AB;
	else
		Usage();

	if (opt2 == "User")
		opt_p2 = p_USER;
	else if (opt2 == "MCTS")
		opt_p2 = p_MCTS;
	else if (opt2 == "MiniMax")
		opt_p2 = p_MM;
	else if (opt2 == "AlphaBeta")
		opt_p2 = p_AB;
	else
		Usage();

	j = new Jogo(opt_p1, opt_p2);

	
	

	return 0;
}

void Usage() {
	cout << "Usage: " << string(argv[0]) << "player_1 player_2" << endl;
	cout << "	Player options: User | MCTS | MiniMax | AlphaBeta" << endl;
	exit(1);
}