/*
 * config.hh
 *
 *  Created on: 22 de març 2022
 *      Author: quim
 */

#ifndef CONFIG_HH_
#define CONFIG_HH_


#define N_ROW 4
#define N_NUMEROS N_ROW*N_ROW

//Only for IDFS
#ifndef MAX_DEPTH
#define MAX_DEPTH 100
#endif

//To choose heuristics. 0->pieces distance | 1->Manhattan distance
#define HEURISTIC 0

#endif /* CONFIG_HH_ */
