# Rationals

*By Ben Forde and Hugo Phibbs*

Etude 8 work for COSC326

## Our approach

- We originally started out with using inbuilt integer c++ for implementing arithmetic of Integers. However, this didn't
  handle arbitrarily large input as required
- So instead, we switched to storing Integer values as strings, then basing out algorithms off of this. We were familiar
  with these algorithms as they were equivalent to the Java ones that we originally implemented in Étude 6.

## Compiling and running

- From the main directory of this submission.
- Navigate to the source code directory with:

```shell
cd src
```

- Then compile the source code with:

```shell
g++ -std=c++11 Integer.cpp Rational.cpp main.cpp -o main
```

- Then to check that you compiled the source code correctly enter:

```shell
./main
```

- A welcome message should then appear

## Sources

- Our algorithms for Integer arithmetic were sourced from GeeksForGeeks, and then refactored for our code
- For addition we used [this algorithm](https://www.geeksforgeeks.org/sum-two-large-numbers/)
- // TODO