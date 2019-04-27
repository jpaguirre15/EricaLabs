/*
// Programmed by: Erica Chen
// Coached by: Pete Aguirre II
// Description: For this first exercise, we got introduced to programming with
//              C, which is a computer program language that helps create a
//              list of functions for a computer to follow, such as generating
//              a simple population growth model. The model used for this
//              exercise is given in:
//                Nt+1 = Nt +rNt, where:
//                - N is the number of animals in the population
//                - t is the time in months
//                - r is the growth rate coefficient
//                -which is 0.5.
//              By programming with C on a computer, we can easily get the
//              number of offsprings in x number of months.
*/

#include <stdio.h>

int main( void )
{
    int i;
    float r, N, t, model;

    r = 0.5;
    t= 0;
    N= 2;

    for( i=0; i<10; i++)
    {
        N= N + r * N;
        t= t + 1;
        printf("At time %f, N= %f,/n", t, N);
    }
    return 0;
}

//  Created by Erica Chen on 2/04/19.
//  Copyright © 2019 Erica Chen. All rights reserved.

/*
// Pete's feedbacks:
// - Comment more
// - Label your code in the beginning, to claim the code is yours, example:

//   Programmed by: <your name>
//   Coached by: <name of mentor>
//   Description: blah blah blahhhhh

// - Nicely done!
*/
