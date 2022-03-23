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
			if (jogo->search(a_BFS) == nullptr){
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
//    cout << "Input initial configuration: " << endl;
//
//    char input_inicial[16];
//    char input_final[16];
//    int i = 0;
//
//    string n_inicial;
//    while (i < 16)
//    {
//        cin >> n_inicial;
//        input_inicial[i] = stoi(n_inicial);
//        i++;
//    }
//
//    fflush(NULL);
//    cout << "Input final configuration: " << endl;
//
//    i = 0;
//    string n_final;
//    while (i < 16)
//    {
//        cin >> n_final;
//        input_final[i] = stoi(n_final);
//        i++;
//    }
//
//
//    main_jogo = new Jogo(input_inicial, input_final);
    

    return 0;
}
