//-----------------------------------------------------------------
// lrc.c
//
// Simple game of LEFT, RIGHT, CENTER implemented in C
//-----------------------------------------------------------------
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// type definition for the faces type
typedef enum faciem { LEFT, RIGHT, CENTER, PASS } faces;

// array (of faces type) with that represents 1 die
faces die[] = { LEFT, RIGHT, CENTER, PASS, PASS, PASS };

// char array of each of the players' names
const char *names[] = { "Dude", "Walter", "Maude", "Big Lebowski", "Brandt",
  "Bunny", "Karl", "Kieffer", "Franz", "Smokey" };

// simulates rolling of the dice
faces rollDice() {
  uint32_t roll = rand() % 6;
  return die[roll];
}

// Returns the position of the player to the left .
//
// pos: The position of the current player .
// players: The number of players in the game .
uint32_t left(uint32_t pos, uint32_t players) {
  return ((pos + players - 1) % players);
}

// Returns the position of the player to the right .
//
// pos: The position of the current player .
// players: The number of players in the game .
uint32_t right(uint32_t pos, uint32_t players) {
  return ((pos + 1) % players);
}

int main(void) {
  uint32_t seed;
  uint32_t players;
  // each player starts with $3, and there is a max of 10 players:
  uint32_t bank[] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
  // the pot starts at $0:
  uint32_t pot = 0;

  // take user input for the seed
  printf("Random seed: ");
  scanf("%d", &seed);
  srand(seed);

  // take user input for the number of players
  printf("How many players? ");
  scanf("%d", &players);

  // error checking
  if ((players <= 1) || (players > 10)) {
    printf("Error: invalid number of players.\nUsage: Number of players must "
           "be an integer between 2 and 10.\n");
    exit(EXIT_FAILURE);
  }

  // begin the game (while loop = the game itself) (for loop = rolling the dice)
  uint32_t i = 0;
  // counter to keep track of players' rolls (prevent rolling more than 3 per turn)
  uint32_t numRolls;
  // loop until only one player has money left in the bank
  while ((bank[i] + pot) != players * 3) {
    // a player can only roll if they have money in the bank
    if (bank[i] >= 1) {
      printf("%s rolls... ", names[i]);
      numRolls = 0;
      for (uint32_t j = bank[i]; (numRolls < j) && (numRolls < 3); numRolls++) {
        faces f = rollDice();
        if (f == PASS) {
          printf("gets a pass ");
        }

        if (f == LEFT) {
          printf("gives $1 to %s ", names[left(i, players)]);
          bank[i]--;
          bank[left(i, players)]++;
        }

        if (f == RIGHT) {
          printf("gives $1 to %s ", names[right(i, players)]);
          bank[i]--;
          bank[right(i, players)]++;
        }

        if (f == CENTER) {
          pot++;
          bank[i]--;
          printf("puts $1 in the pot ");
        }
      }
      printf("\n");
    }

    // move to the next player (player to the right)
    i = ((i + 1) % players);
  }

  // announce the winner
  printf("%s wins the $%d pot with $%d left in the bank!\n", names[i], pot,
      bank[i]);
  return 0;
}
