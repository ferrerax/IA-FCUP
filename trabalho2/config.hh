/*
 * config.hh
 *
 *  Created on: 9 d'abril 2022
 *      Author: quim
 */

#ifndef CONFIG_HH_
#define CONFIG_HH_


#define N_ROW 		6 				//Rows in table
#define N_COLUMN	7				//Columns in table
#define N_NUMEROS N_ROW*N_COLUMN	//Size of the tabulairo

#define MINIMAX_MAX_UTILITY 100000000
#define MINIMAX_DEPTH 6				//Max depth for minimax

#define ALFABETA_DEPTH 6			//Max depth for alpha beta

#define MCTS_ITERATIONS 10000		//Iterations for MCTS

#endif /* CONFIG_HH_ */
