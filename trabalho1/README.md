# Jogo do 15

Searching strategies implemented to solve Jogo do 15

## Compilation

To compile the code go to the project directory and use `make` as follows specifying the compilator to be used and the desired name for the executable:

```bash
make CC=g++ TARGET=jogo15
```

In this example g++ is used.

## Run

To run must have 2 input arguments. The list of initial configurations and the list of final configurations in two different files as follows:

```bash
./jogo15 jps/i_c1.cnf jps/f_c1.cnf
```
`i_c1.cnf` is the file containing the inital configurations and `f_c1.cnf` contain the final configurations. These files contains all the configurations wanted to test in different lines. One example is given below:

```
1 2 3 4 9 5 7 8 13 6 10 12 0 14 11 15
9 12 13 7 0 14 5 2 6 1 4 8 10 15 3 11
6 12 5 9 14 2 4 11 0 7 8 13 3 10 1 15
1 2 3 4 9 5 7 8 13 6 10 12 0 11 14 15
```

More examples can be found in directory `/jps`.

## Output

The program will output for each configuration and each algorithm the path to solution and the statistics asked which are the algorithm used, time spent, number of nodes, number of bytes and steps to solution.
