/*
// Program by: Erica Chen
// Coached by: Pete Aguirre II
// Description: For this week’s exercise, we learn to develop a stochastic
//              model approach to population dynamics, such as predicting
//              future population sizes through an RNG. Unlike previous models,
//              like the deterministic model, this approach treats population
//              events such as births and deaths as stochastic events, meaning
//              that these events are random and would be based on probability.
//              Because of this, these birth and death events have an associated
//              randomness and unpredictability. By utilizing the program that
//              was created for a random generator, we will be generating two
//              graphs for the populations. First graph will have birth rate
//              set to 0.30 and death rate set at 0.275. The second graph will
//              be the opposite, where birth rate will be 0.275 and death rate
//              set at 0.30.
//              The population will start with 10 organisms and carry out to
//              150 generations to see these stochastic events happening.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main(void){

  // For RNG
  int i, j;
  float guess;

  // For current assignment
  float b, d; //
  float plusP, negP, zeroP; // P values
  int gen, org;   // loop conter for generations and organisms
  int ngen, norg; // how many generations and how many organisms
  int births = 0;
  int deaths = 0;



  // Generation prompt
  printf("Set value for generation: ");
  scanf("%d", &ngen);

  int N[ngen]; // For things that are in population, N = population

  // For output filestreams
  char text[ngen];
  char filename[ngen];
  FILE *outfile;

  // Organisms prompt
  printf("Set value for organisms: ");
  scanf("%d", &norg);

  // Birthrate prompt
  printf("Set value for b: ");
  scanf("%f", &b);

  // Death rate prompt
  printf("Set value for d: ");
  scanf("%f", &d);

  // This loop is needed so no garbage values occur
  for(i=0; i<ngen; i++){
    N[i] = 0;
  }

  // Equation of different P's
  plusP = b*(1-d);
  negP = d*(1-b);
  zeroP = 1-plusP-negP;

  // Print P values
  printf("\n");
  printf("Results of P: \n");
  printf("plusP = %.3f\n", plusP);
  printf("negP = %.3f\n", negP);
  printf("zeroP = %.3f\n", zeroP);
  printf("\n");

  srand((unsigned int)time(NULL));

  N[0] = 10;
  for(gen=0; gen<ngen; gen++){
    births = 0; // reset
    deaths = 0; // reset
    // ----
    // Nest start
    for(org=0; org<norg;org++){
      // RNG
      guess = ((float)rand())/RAND_MAX;
      // 2 conditions
      if(guess >= 0 && guess <= plusP){
        births++;
        //printf("Someone gave birth!\n");
      }
      else if(guess > plusP && guess <= (plusP+negP)){
        deaths++;
        //printf("Someone died.\n");
      }

    }
    // Nest end
    // -----

    // Necessary to initialize the beginning to 10 and
    // also to make deaths and births to 0 at this time
    if(gen == 0){
      N[0] = 10;
      births = 0; // reset
      deaths = 0; // reset
    }
    // Necessary to solve for N[1 and above]
    else{ N[gen] = N[gen-1] + births - deaths; }

    // Indicators
    printf("Birth: %d\n", births);
    printf("Death: %d\n", deaths);

    if(N[gen] > 0){
      printf("Total Population: %d\n", N[gen]);
      printf("\n");
    }
    else if(N[gen] <= 0){
      printf("Total Population: %d\n", 0);
      printf("Population died at %d generation.\n", gen);
      printf("\n");
      break;
    }
  }

  // For saving stuff
  outfile = fopen("output.txt", "w");
  for(i=0; i<ngen; i++){
    fprintf(outfile, "%d = %d\n", i, N[i]);
  }
  fclose(outfile);


  return 0;
}

//  Created by Erica Chen on 4/15/19.
//  Copyright © 2019 Erica Chen. All rights reserved.

/*
// Pete's feedbacks:
// - Nicely done!
*/
