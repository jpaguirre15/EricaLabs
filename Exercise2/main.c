/*
// Programmed by: Erica Chen
// Coached by: Pete Aguirre II
// Description: For this second exercise, we will be modifying the program that
//              was taught to us from Lab 1 so that it can solve a logistic
//              population growth model. We continue learning about the
//              modeling process and how there are two approaches, which is the
//              classical and alternative approach. We also learned how to save
//              a data file, which is needed for this exercise because we are
//              solving for two sets of results. The model used for this
//              exercise for the program to solve will be:
//                Nt+1 = Nt +rNt(1- Nt/K), where:
//                - N will be population size
//                - t is time in months
//                - r is the reproductive rate
//                - which is 0.25 per year
//                - K is the carrying capacity which is 100
//              Run 1 will have an initial population of size 2, which is under
//              the carrying capacity and Run 2 will have an initial population
//              size of 120, which is over the carrying capacity. We want to see
//              the results of the population size for both tests in 100 months.
*/

#include <stdio.h>
#include <string.h>
int main( void )
{
    int i;
    float r;
    int K;
    float N[101], t[101];
    char text[1024];
    char filename[1024];
    FILE *outfile;

    r = 0.25;
    K = 100; // this is what K means (carrying capacity)
    N[0] = 2;
    t[0] = 0;

    for( i=0; i<K+1; i++)
    {
        N[i+1] = N[i] + r * N[i] * (1-N[i]/K);
        t[i+1] = t[i] + 1;
        printf("%4.1f, %f\n", t[i], N[i]);
    }

    printf( "Save data to disk file ? (y/n): ");
    scanf( "%s", text);
    if( strcmp(text, "y") == 0 )
    {
        printf( "Lab 2 : ");
        scanf( "%s", filename);
        outfile = fopen( filename, "w");
        for( i=0; i<=K; i++ )
        {
            fprintf( outfile, "%4.1f, %f\n", t[i], N[i]);
        }
        fclose(outfile);
    }
    return 0;
}

//  Created by Erica Chen on 2/11/19.
//  Copyright © 2019 Erica Chen. All rights reserved.

/*
// Pete's feedbacks:
// - Comment more for a cleaner code please!!
// - Nicely done!
*/
