## Compilation
To compile the program, use the Make tool:

```
make CC=g++
```
where CC is for the compiler.

## Running
The program requires one parameter, a csv file with a dataset to create the decision tree.

```
./trabalho3 dataset.csv
```
If you also want to classify another dataset with the decision tree created, add the `-c` option with another dataset:

```
./trabalho3 dataset.csv -c classify.csv
```
