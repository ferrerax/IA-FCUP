#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "jogo.hh"

using namespace std;

Jogo *main_jogo;

int main(int argc, char *argv[])
{

	fstream newini;
	fstream newfin;
	Jogo * jogo;
	no * solution;

	newini.open(argv[1],ios::in); //open initial configurations file.
	newfin.open(argv[2],ios::in); //open final configurations file.
	if (newini.is_open() && newfin.is_open()){   //checking whether the file is open
		string ini;
		string fin;

		char ini_chars[16];
		char fin_chars[16];

		while(getline(newini, ini) && getline(newfin, fin)){
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
			if ( (solution = jogo->search(a_GULOSA)) == nullptr){
				cout << "[!] There's no solution" << endl;
			} else {
				cout << "Solved!" << endl;
				//jogo->printSolution();
			}
			delete jogo;

		}
		newini.close(); //close the file object.
		newfin.close(); //close the file object.
	}

    return 0;
}
