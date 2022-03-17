#include<iostream>
#include<string>
#include<stdio.h>

#include "jogo.hh"

using namespace std;

Jogo *main_jogo;

int main(int argc, char *argv[])
{

    cout << "Input initial configuration: " << endl;

    char input_inicial[16];
    char input_final[16];
    int i = 0;

    string n_inicial;
    while (i < 16)
    {
        cin >> n_inicial;
        input_inicial[i] = stoi(n_inicial);
        i++;
    }

    fflush(NULL);
    cout << "Input final configuration: " << endl;

    i = 0;
    string n_final;
    while (i < 16)
    {
        cin >> n_final;
        input_final[i] = stoi(n_final);
        i++;
    }


    main_jogo = new Jogo(input_inicial, input_final);
    

    return 0;
}