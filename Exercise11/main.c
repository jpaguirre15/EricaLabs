/*
// Program by: Erica Chen
// Coached by: Pete Aguirre II 
// Description: Exercise 11 is based on Robert May's simple population model.
//              Following the formula: N[t+1] = aN[t](1-N[t]), where:
//                                     N[t] = the population at time t
//                                     a = growth coefficient
//              Given a = 1.5, 2.6, 3.3, 3.75
//                    N[0] = 0.1
*/

#include <stdio.h>

int main(void){

  // Variables or Project 11
  float N[26], a;
  int time, i;

  // Variables for output filestreams
  char text[26];
  char filename[26];
  FILE *outfile;

  printf("Value of a: ");
  scanf("%f", &a);

  // Loop to initialize all N array to 0 to ensure no garbage values occur
  for(i=0; i<26; i++){
    N[i] = 0;
  }

  // Loop 26 times
  for(time=0; time<26; time++){
    // When time is at 0
    if(time == 0){
      N[0] = 0.1;
      N[time+1] = N[time]*a*(1-N[time]);
    }
    // Anytime after 0
    else{
      N[time+1] = N[time]*a*(1-N[time]);
    }
    printf("%d\t %.2f\n", time, N[time]);
  }

  // For saving stuff
  outfile = fopen("output.txt", "w");
  for(i=0; i<26; i++){
    fprintf(outfile, "%i\t%f\n", i, N[i]);
  }
  fclose(outfile);

  printf("Values saved at output.txt\n");

  return 0;
}

//  Created by Erica Chen on 4/26/19.
//  Copyright © 2019 Erica Chen. All rights reserved.

/*
// Pete's feedbacks:
// - Thank goodness for shorter descriptions! :D
// - Nicely done!
*/
