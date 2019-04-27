/*
// Program by: Erica Chen
// Coached by: Pete Aguirre II
// Description: For this week’s exercise, we learn about how to generate random
//              numbers with a random number generator on the computer. This
//              week’s focus is on stochastic models where the process or model
//              includes some random or unpredictable components. With
//              stochastic models, we would not be able to predict what would
//              happen in the future compared to previous models, which are the
//              deterministic models. Even random events can have probabilities
//              of appearing again if we generate it 100 or 1,000 times, but
//              not in the same sequences as previous the previous event. By
//              using the random number generator (RNG), we can produce a
//              sequence of numbers. The starting point in the sequence is
//              called a seed, and by changing the “seed”, we can get a
//              different set of numbers every time the RNG goes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

  int i, j, n, guess;

  int track[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  printf("How many numbers produced?: ");
  scanf("%d", &n);


  srand(time(0));
  for(i=0; i<n; i++){
    guess = rand()%(9 + 1);
    printf("Guess %d at position %d\n", guess, i+1);
    for(j=0; j<10; j++){
      if(guess == j){ track[j]++; }
    }
  }

  printf("\n");
  for(i=0; i<10; i++){
    printf("Number %d tracked: %d\n", i, track[i]);
  }

  return 0;
}

//  Created by Erica Chen on 4/15/19.
//  Copyright © 2019 Erica Chen. All rights reserved.

/*
// Pete's feedbacks:
// - Don't be cocky! Still use documentation even with this simple of a program.
//   So you know what it does in the future.
// - Nicely done!
*/
