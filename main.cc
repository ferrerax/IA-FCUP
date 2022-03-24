#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "jogo.hh"
#include "config.hh"

using namespace std;

Jogo *main_jogo;

void execute_algorithm(Jogo * jogo, t_algorithm alg){
	no * solution;

	if ( (solution = jogo->search(alg)) == nullptr){
		cout << "[!] There's no solution" << endl;
	} else {
		list<no*> path;
		solution->trackToRoot(path);
		cout << "Solved! Done in " << path.size()-1 << " steps" << endl << endl;
		jogo->printSolution(path);
		jogo->printStatistics();
	}
}

int main(int argc, char *argv[])
{
	fstream newini;
	fstream newfin;
	Jogo * jogo;

	newini.open(argv[1],ios::in); //open initial configurations file.
	newfin.open(argv[2],ios::in); //open final configurations file.
	if (newini.is_open() && newfin.is_open()){   //checking whether the file is open
		string ini;
		string fin;

		char ini_chars[16];
		char fin_chars[16];

		while(getline(newini, ini) && getline(newfin, fin)){
			cout << endl << "[+] NEW CONFIGURATION" << endl;
			cout << "Using initial table " << ini << "\n";
			cout << "Using final table " << fin << "\n";

			size_t pos = 0;
			string token;
			int it = 0;
			string delimiter = " ";

			while ((pos = ini.find(delimiter)) != string::npos)
			{
				token = ini.substr(0, pos);
				ini_chars[it] = (char) stoi(token);
				ini.erase(0, pos + delimiter.length());
				it++;
			}
			ini_chars[it] = (char) stoi(ini);  // Last token

			pos = 0;
			it = 0;
			while ((pos = fin.find(delimiter)) != string::npos)
			{
				token = fin.substr(0, pos);
				fin_chars[it] = (char)stoi(token);
				fin.erase(0, pos + delimiter.length());
				it++;
			}
			fin_chars[it] = (char) stoi(fin);

			jogo = new Jogo(ini_chars, fin_chars); //new game created.

			//algorithms
			cout << endl << "***** DFS *****" << endl << endl;
			try {
				execute_algorithm(jogo, a_DFS);
			}
			catch(const char* s){
				cout << "Algorithm Timeout" << endl << endl;
				jogo->printStatistics();
			}

			cout << endl << "Erasing tree from memory..." << endl << endl;
			delete jogo;
			jogo = new Jogo(ini_chars, fin_chars);

			cout << endl << "***** BFS *****" << endl << endl;
			try {
				nodes = 0;
				execute_algorithm(jogo, a_BFS);
			}
			catch(const char * s){
				cout << "Algorithm Timeout" << endl << endl;
				jogo->printStatistics();
			}

			cout << endl << "Erasing tree from memory..." << endl << endl;
			delete jogo;
			jogo = new Jogo(ini_chars, fin_chars);

			cout << endl << "***** IDFS *****" << endl << endl;
			try {
				execute_algorithm(jogo, a_IDFS);
			}
			catch(const char * s){
				cout << "Algorithm Timeout" << endl << endl;
				jogo->printStatistics();
			}

			cout << endl << "Erasing tree from memory..." << endl << endl;
			delete jogo;
			jogo = new Jogo(ini_chars, fin_chars);

			cout << endl << "***** GULOSA *****" << endl << endl;
			try {
				execute_algorithm(jogo, a_GULOSA);
			}
			catch(const char * s){
				cout << "Algorithm Timeout" << endl << endl;
				jogo->printStatistics();
			}

			cout << endl << "Erasing tree from memory..." << endl << endl;
			delete jogo;
			jogo = new Jogo(ini_chars, fin_chars);

			cout << endl << "***** A* *****" << endl << endl;
			try {
				execute_algorithm(jogo, a_A_ESTRELA);
			}
			catch(const char * s){
				cout << "Algorithm Timeout" << endl << endl;
				jogo->printStatistics();
			}
			cout << endl << "Erasing tree from memory..." << endl << endl;
			delete jogo;

		}
		newini.close(); //close the file object.
		newfin.close(); //close the file object.
	}

	return 0;
}
