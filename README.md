# Rationals
**Etude 8 work for COSC326**

*By Ben Forde and Hugo Phibbs*

## Our approach

- We originally started out with using inbuilt integer C++ for implementing arithmetic of Integers. However, this didn't
  handle arbitrarily large input as required
- So instead, we switched to storing Integer values as strings, then basing our algorithms off of this. We were familiar
  with these algorithms as they were equivalent to the Java ones that we originally implemented in Étude 6.
- After implementing these algorithms fully, we rigorously tested our program to make sure it ran flawless with both
  regular and edge case input.

### Implementing arithmetic algorithms

- We found algorithms online via GeeksForGeeks for subtraction, multiplication and addition of arbitrarily large string
  integers, based off of primary school level arithmetic. However, these were only effective for positive Integers. To
  remedy this, we used the operator methods as wrappers for methods to handle subtraction, multiplication and addition
  of *positive* integers only. Then the sign (
  positive or negative) was adjusted based on inputs.
- Division was a bit harder, please see bellow
- In addition to regular input, exceptional input also needed to be handled, which was easier said than done.

#### Division

- We initially sourced a division algorithm from GeeksForGeeks. However, this had some limitations: Firstly, it didn't
  work for arbitrarily large divisors and didn't pass basic tests. So we ended up just writing our own division
  algorithm, inspired by what we saw in the town-hall (the 'Pitch my Etude' one).
- Our algorithm works by doing repeated division with zeros appended to our divisor. This is done for a particular base,
  until the remainder is negative. Then a lower base is used and so forth. This is much faster than just repeated
  division of the divisor with no zeros added - we had already implemented this in Java for Etude 6, and had no doubts
  that it wouldn't be much faster in C++
- All the code done is inspired by another group in this course (I'm not sure of their names), however, they purely
  provided us the basic idea, and then we implemented our own algorithm from there.
- We ended up creating a method that found the quotient and remainder for the divison of two positive integers. It
  pretty much does integer division much like in Python. The result of this could then be adjusted depending on the sign
  of the Integers in the division operation

#### Modulo arithmetic

- We reused the quotient and remainder algorithm for positive integers and generalised it to all possible combinations
  of input sign, the finding an adjusted remainder from there. 

#### Greatest common divisor

- This uses the Euclidean Algorithm, more info can be found [here](https://en.wikipedia.org/wiki/Euclidean_algorithm).

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

- Our algorithms for Integer arithmetic were sourced from GeeksForGeeks, and then refactored for our code. For addition
  we used [this algorithm](https://www.geeksforgeeks.org/sum-two-large-numbers/), for
  subtraction [this one](https://www.geeksforgeeks.org/difference-of-two-large-numbers/) and for
  multiplication [this one](https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/)
- Prior knowledge in regard to modulo arithmetic and greatest common divisor.
- For reversing C++ strings, [here](https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/)
- Inspiration from another COSC326 group.

## Tests

- Our tests for Rational and Integer can be found in the attached test package. They are quite long, so I have decided
  not add them to the README.
- Tests are done using [Google Test](https://google.github.io/googletest/)


Rational test:
## Negitives:

* Rational t = Rational("-1/2"); == "-1/2"
* "-1/2" + "-3/2" = "-2"
* "-1/2" * "-3/2" = "3/4"
* "-1/2" - "-3/2" = "1"
* "-1/2" / "-3/2" = "1/3"
* "-1/2" /= "-3/2" = "1/3"
* "-1/2" *= "-3/2" = "3/4"
* "-1/2" -= "-3/2" = "1"
* "-1/2" += "-3/2" = "2"

## Positives
* Rational t = Rational("1/2");
* "1/2" + "3/2" = "2"
* "1/2" - "3/2" = "-1"
* "1/2" * "3/2" = "3/4"
* "1/2" / "3/2" = "1/3"
* "1/2" /= "3/2" = "1/3"
* "1/2" *= "3/2" = "3/4"
* "1/2" -= "3/2" = "-1"
* "1/2" += "3/2" = "2"


## signs:
t = 1/2,    g = 3/2
* if(t < g){
         cout << "working";
     }
* if(g < t){
         cout << " not working"; (shouldnt print)
     }
* if(g > t){
         cout << "working";
     }
* if(t > g){
         cout << " not working"; (shouldnt print)
     }
* if(t >= g){
         cout << "not working"; (Shouldnt print)
     }
* if(g >= t){
         cout << "working"; 
     }
* if(t >= t){
         cout << "working"; 
     }

* if(t <= g){
         cout << "working";
     }
* if(g <= t){
         cout << "not working"; (shouldnt print)
     }
* if(t <= t){
         cout << "working"; 
     }
* if(t == t){
         cout << "working";
     }
* if(t == g){
         cout << "not working"; (shouldnt print)
     }

* if(t != t){
         cout << "not working"; (shouldnt print)
     }
* if(t != g){
         cout << "working";
     }


## Unary: 
* t = -1/2
t = +t; returns: 1/2


* t = 1/2
t = -t; returns: -1/2



## Assignment: 
  *  Rational t = Rational("-1/2"); == "-1/2"
  *  Rational t = Rational(Integer("1"), Integer("2")); == "1/2"
  *   Rational t = Rational(Integer("-1"), Integer("2")); == "-1/2"
  *  Rational t = Rational(); == "0"
  *  Rational t = Rational(Integer("1"), Integer("1"), Integer("2")); == "1.1/2"




    



