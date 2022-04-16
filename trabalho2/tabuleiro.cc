#include "tabuleiro.hh"
#include <iostream>
#include<string.h>
#include <cmath>

using namespace std;

tabuleiro::tabuleiro(char *numbs) {
    memcpy(matriu, numbs, N_NUMEROS);
}

tabuleiro::~tabuleiro()
{
    
}

bool tabuleiro::comparar_tabs(tabuleiro *a, tabuleiro *b)
{
    for (int i = 0; i < N_NUMEROS; i++)
    {
        if (a->matriu[i] != b->matriu[i])
        {
            return false;
        }
    }
    return true;
    
}

//int tabuleiro::busca_blanc(){
//        for(int i = 0; i < N_NUMEROS; i++){
//            if (matriu[i] == 0)
//                return i;
//        }
//    return -1;
//}

//int tabuleiro::get_inversions() {
//    unsigned int inv_count = 0;
//
//    for (int i = 0; i < N_NUMEROS; i ++){
//        for (int j = i + 1; j < N_NUMEROS; j++){
//            if( (matriu[j] < matriu[i]) and (matriu[j] != 0) )
//                inv_count++;
//        }
//    }
//
//    return inv_count;
//}

//tabuleiro* tabuleiro::right()
//{
//    int blanc = this->busca_blanc();
//    if(blanc % N_ROW != N_ROW-1) {
//        return new tabuleiro(this->matriu, RIGHT);
//    } else {
//        return NULL;
//    }
//}
//
//tabuleiro *tabuleiro::left()
//{
//    int blanc = this->busca_blanc();
//    if (blanc % N_ROW != 0)
//    {
//        return new tabuleiro(this->matriu, LEFT);
//    }
//    else
//    {
//        return NULL;
//    }
//}
//tabuleiro *tabuleiro::top()
//{
//    int blanc = this->busca_blanc();
//    if (blanc >= N_ROW)
//    {
//        return new tabuleiro(this->matriu, TOP);
//    }
//    else
//    {
//        return NULL;
//    }
//}

string tabuleiro::getHash() {
	string aux(this->matriu);
	return aux;
}

void tabuleiro::print()
{
    for (size_t i = 0; i < N_NUMEROS; i++)
    {
        cout << to_string((int) this->matriu[i]) << " ";
    }
    cout << endl;
    
}

void tabuleiro::print_formatted()
{
    for (size_t i = 0; i < N_ROW; i++)
    {
        for (size_t j = 0; j < N_COLUMN; j++)
        {
            if (matriu[i * N_ROW + j] < 10) cout << " ";
            cout << to_string((int)this->matriu[i * N_ROW + j]) << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

//tabuleiro *tabuleiro::bot()
//{
//    int blanc = this->busca_blanc();
//    if (blanc < N_ROW*(N_ROW-1))
//    {
//        return new tabuleiro(this->matriu, BOT);
//    }
//    else
//    {
//        return NULL;
//    }
//}
//tabuleiro::tabuleiro(char *nums, t_dir dir)
//{
//    memcpy(matriu, nums, N_NUMEROS);
//    int b = this->busca_blanc();
//
//    switch (dir)
//    {
//    case RIGHT:
//        matriu[b] = matriu[b+1];
//        matriu[b+1] = 0;
//        break;
//    case LEFT:
//        matriu[b] = matriu[b - 1];
//        matriu[b - 1] = 0;
//        break;
//    case TOP:
//        matriu[b] = matriu[b - N_ROW];
//        matriu[b - N_ROW] = 0;
//        break;
//    case BOT:
//        matriu[b] = matriu[b + N_ROW];
//        matriu[b + N_ROW] = 0;
//        break;
//    default:
//        break;
//    }
//}

//int tabuleiro::getNumberPieces(tabuleiro *t) {
//	int r = 0;
//	for (int i = 0; i < N_NUMEROS; i++){
//		if (t->matriu[i] != this->matriu[i]){
//			r++;
//		}
//	}
//	return r;
//}
//
//int tabuleiro::getManhattanDistance(tabuleiro *t) {
//	int r,x1,x2,y1,y2 = 0;
//
//	for (int i = 0; i < N_NUMEROS; i++){
//		x1 = t->matriu[i]%N_ROW;
//		x2 = this->matriu[i]%N_ROW;
//		y1 = t->matriu[i]/N_ROW;
//		y2 = this->matriu[i]/N_ROW;
//
//		r += abs(x1-x2) + abs(y1-y2);
//	}
//	return r;
//}
