I will be creating a simple game of "Left, Right, and Center" using the C programming language.
The rules are simple: 1-10 players, each player rolls the dice the same number of times as however 
much money they have left unless they have more than 3 dollars (then they only roll three times). 
The game is over when the pot is empty (someone wins all of the money).

The first thing I will do is make sure I am including the following header
files: stdio.h, stdlib.h, stdint.h.

To get started, I used the arrays die[] (of the faces type) to store all 
of the different faces and the names[] array (which are char pointers).

Next, I wrote the Makefile which enables shorthand compilation of my program,
easy generation of the executable binary for lrc.c (lrc.o), a make all target,
clang format tool, and a make clean tool.

Now, getting into the basics of how the program will operate:
I will start by generating a random number of players in the range of 1 to 10
using rand().

The second condition that I will establish is that the player whose
turn it is will roll:
- 3 times if they have $3 or more
- 2 times if they have $2
- 1 time if they have $1
- 0 times (pass) if they have $0
In the logic stated above, the number of "times" represents the number of die
that player will roll; I will use a while loop to iterate through and make sure
that each player will roll the appropriate number of times depending on how much
money they have.

To determine the number of rolls, I will do the following:
Set the money held by [x or y] player equal to equal to a variable that I will
decrement at the end of each iteration of the while loop.