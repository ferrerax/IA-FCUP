#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "jogo.hh"

using namespace std;

Jogo *main_jogo;

void execute_algorithm(Jogo * jogo, t_algorithm alg){
	no * solution;

	if ( (solution = jogo->search(alg)) == nullptr){
		cout << "[!] There's no solution" << endl;
	} else {
		list<no*> path;
		solution->trackToRoot(path);
		cout << "Solved! Done in " << path.size() << " steps" << endl << endl;
		//jogo->printSolution();
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
			execute_algorithm(jogo, a_DFS);
			execute_algorithm(jogo, a_BFS);
			execute_algorithm(jogo, a_IDFS);
			execute_algorithm(jogo, a_GULOSA);
			execute_algorithm(jogo, a_A_ESTRELA);

			}
			delete jogo;

		}
		newini.close(); //close the file object.
		newfin.close(); //close the file object.
	}

    return 0;
}
