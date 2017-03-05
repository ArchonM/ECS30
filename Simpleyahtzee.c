#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
// Constants used throughout the program.
// This would allow us to easily change the game to use, say, 4 dice instead of 5
#define NUM_DICE 5
#define NUM_FACES 6
#define UNSCORED_CATEGORY -1

// Sets up the game. Seed rand and mark every category as unscored
void initializeGame(int categoryScores[NUM_FACES]);

// Marks all die as unsaved. Used at the start of a round
void resetsavedDice(bool savedDice[NUM_DICE]);

// Play one round of simple yahtzee
void playRound(bool savedDice[NUM_DICE], int dice[NUM_DICE]);

// Obtains saved dice from player
void getPlayerSaveDice(bool savedDice[]);

// Re-roll all die that are not saved
void rollAllUnsavedDice(bool savedDice[NUM_DICE], int dice[NUM_DICE]);

// Ask user for category and score round for that category if available
void scoreRound(int dice[NUM_DICE], int categoryScores[NUM_FACES]);

// Prints the current dice rolls and re-rolls remaining
void printRoundState(int dice[NUM_DICE], int roll);

// Prints current total score of all saved categories
void printTotalScore(int categoryScores[NUM_FACES]);

// Flush stdin buffer
void flushStdin();

// Plays simple yahtzee
//
// Simple yahtzee consists of 6 rounds. In each round, 5 dice are rolled,
// and they may be re-rolled twice. The player saves dice they wish to keep
// which will not be re-rolled.
int main() {
  int dice[NUM_DICE], categoryScores[NUM_FACES];
  bool savedDice[NUM_DICE];
  initializeGame(categoryScores);
  // Play and score all rounds
  for (int gamesPlayed = 0; gamesPlayed < NUM_FACES; ++gamesPlayed) {
    playRound(savedDice, dice);
    scoreRound(dice, categoryScores);
  }
  printf("Game over.\n");
}

//////////////////////////////////
//// INITIALIZATION FUNCTIONS ////

// Sets up the game. Seed rand and mark every category as unscored
void initializeGame(int categoryScores[NUM_FACES]) {
  for (int i = 0; i < NUM_FACES; ++i) {
    categoryScores[i] = UNSCORED_CATEGORY;
  }
  int seed;
  printf("Enter seed: ");
  scanf("%d", &seed);
  // Flush the input buffer after every scanf call.
  flushStdin();
  srand(seed);
}

// Marks all die as unsaved. Used at the start of a round
void resetsavedDice(bool savedDice[NUM_DICE]) {
  for (int i = 0; i < NUM_DICE; i++) {
    savedDice[i] = false;
  }
}

//////////////////////////////////////
//// END INITIALIZATION FUNCTIONS ////

///////////////////////////////////
//// PLAYING A ROUND FUNCTIONS ////

// Play one round of simple yahtzee
void playRound(bool savedDice[NUM_DICE], int dice[NUM_DICE]) {
  resetsavedDice(savedDice);
  // Initial roll before asking to save dice
  rollAllUnsavedDice(savedDice, dice);
  printRoundState(dice, 2);
  for (int roll = 0; roll < 2; ++roll) {
    getPlayerSaveDice(savedDice);
    rollAllUnsavedDice(savedDice, dice);
    printRoundState(dice, 1 - roll);
  }
}

// Obtains saved dice from player
void getPlayerSaveDice(bool savedDice[]) {
  char option;
  int die;
  bool reroll = false;
  int scanfResult;
  while (!reroll) {
    printf("Enter dice to save or 'r' for reroll: ");
    // Read input and clear input buffer afterwards
    scanfResult = scanf("%c", &option);
    die = atoi(&option);
    printf("the char you just entered is %c\n",option);
    printf("the variable die is: %d ???\n",atoi(&option));
    flushStdin();
    // If some character successfully read
    if (scanfResult == 1) {
      // If user requests a reroll
      if (option == 'r') {
        reroll = true;
        continue;
      }
      // Else if user toggles saving of a die
      else if (isdigit(option) && 1 <= die && die <= NUM_DICE) {
        savedDice[die - 1] = !savedDice[die - 1];
        printf("Die %d is now %s\n", die, savedDice[die - 1] ? "saved" : "unsaved");
        continue;
      }
    }
    // Otherwise re-prompt for input
    printf("Error: invalid command. Enter 'r' for re-roll unsaved die or 1-5 to toggle saving die\n");
  }
}

// Re-roll all die that are not saved
void rollAllUnsavedDice(bool savedDice[NUM_DICE], int dice[NUM_DICE]) {
  for (int i = 0; i < NUM_DICE; i++) {
    if (!savedDice[i]) {
      dice[i] = 1 + rand() % NUM_FACES;
    }
  }
}

// Ask user for category and score round for that category if available
void scoreRound(int dice [NUM_DICE], int categoryScores[NUM_FACES]) {
  int categoryNum;
  int numMatches;
  for(int i = 0; i < NUM_FACES; i++){
  printf("Enter category to save score: ");
  scanf("%d", &categoryNum);
    if(!(categoryScores[categoryNum] == 0)){
      printf("Error: invalid command. Enter 1-6 to save to an unused category\n");
    }
    if(!(categoryNum == 1 || categoryNum == 2 || categoryNum == 3 || categoryNum == 4 || categoryNum == 5 || categoryNum == 6)){
      printf("Error: invalid command. Enter 1-6 to save to an unused category\n");
    }
    else{
      break;
    }
  }
  for(int i = 0; i < NUM_FACES; i++){
    if(dice[i] == categoryNum){
      numMatches = numMatches + 1;
       }
  }
     categoryScores[categoryNum] = categoryNum * numMatches;
  for (int i = 0; i < NUM_FACES; i++){
    if(categoryScores[categoryNum] == 0){
      printf("Category %d score: not scored\n", i + 1);
    }
    else{
    printf("Category %d score: %d\n", i + 1, categoryScores[categoryNum]);
  }
}
  printf("Total Score: %d\n", categoryScores[categoryNum]);

  // Homework TODO: write code for this function.
  // This function should:
  // 1) Ask the user for a category to save the round score to
  // 2) Check if the input category is scored or not using UNSCORED_CATEGORY
  // 3) Score the result for category i in categoryScores[i - 1]
  // 4) Print the current total score
}

///////////////////////////////////////
//// END PLAYING A ROUND FUNCTIONS ////

////////////////////////////
//// PRINTING FUNCTIONS ////

// Prints the current dice rolls and re-rolls remaining
void printRoundState(int dice[NUM_DICE], int rerollsLeft) {
  printf("%d %d %d %d %d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
  printf("Rolls left: %d\n", rerollsLeft);
  // 五个随机数
  // 剩余
  //
  // Homework: write code for this function.
  // Example output, if all dice are 1 and 2 rerolls are left:
  // Dice: 1 1 1 1 1
  // Rolls left: 2-----%d
}

// Prints current total score of all saved categories
void printTotalScore(int categoryScores[NUM_FACES]) {
  int sum;
  int categoryNum;
  for (int i = 0; i < NUM_FACES; i++){
    if(categoryScores[categoryNum] == 0){
      printf("Category %d score: not scored\n", i + 1);
    }
    else{
    printf("Category %d score: %d", i + 1, categoryScores[categoryNum]);
  }
}
for(int i = 0; i < NUM_FACES; i++){
  sum = sum + categoryScores[i];
}
printf("Total score: %d\n", sum);
  // Homework TODO: write code for this function.
  // Example output, if the score for category i is 2i except
  // for category 2, which is unscored:
  // Category 1 score: 1
  // Category 2 score: not scored
  // Category 3 score: 6
  // Category 4 score: 8
  // Category 5 score: 10
  // Category 6 score: 12
  // Total Score: 27

}

////////////////////////////////
//// END PRINTING FUNCTIONS ////

// Flush stdin buffer
void flushStdin() {
  char c;
  // Skip all characters until end-of-file marker
  // or new line / carriage return
  while ( (c = getchar()) != EOF &&
          c != '\n' &&
          c != '\r' ) {};
}
