/*
// Program by: Erica Chen
// Coached by: Pete Aguirre II
// Description: For Lab 3, we learn about a model for two species where one
//              will be the predator and the other is the prey. These models
//              are linked, and it can be shown in these equations:
//              Vt+1 = Vt + rVt – aVtPt and Pt+1 = Pt + abVtPt - dPt, where:
//                  - V is the prey organism
//                  - P is the predator organism
//              In these equations, there are parameters, which are constants
//              that can affect the populations and are part of flow equations.
//              The parameters listed in this exercise is r, which is the prey
//              reproductive coefficient at 0.01, a is the prey consumption
//              coefficient at 0.0005, d is the predator death coefficient at
//              0.1 and b is the conversion of prey to new predators at 0.1.
//              The initial population size at for prey is V0 = 1500 and
//              predators at P0 = 50. To see the full results of how each
//              population looked like over time, I set the steps to 400.
*/

#include <stdio.h>
#include <string.h>
int main(void)
{
    int i;
    float r = 0.01; // prey reproductive coefficient
    float a = 0.0005; // prey consumption rate coefficient
    float d = 0.1; // predator death rate coefficient
    float b = 0.1; // conversion of prey to new predators
    float V[700];
    float P[700];
    float t[700];
    char text[400];
    char filename[400];
    FILE *outfile;

    V[0] = 1500; // initial V popualtion size
    P[0] = 50; // initial predator pop size
    t[0] = 0; // initial time
   // printf("P\t   V\t  t\n");
    for( i=0; i<=400; i++)
    {
        V[i+1] = V[i] + r * V[i] - a * V[i] * P[i];
        P[i+1] = P[i] + a * b * V[i] * P[i] - d * P[i];
        t[i+1] = t[i] + 1;
        printf("%7.4f\t %f\t %7.4f\n", t[i], V[i], P[i]);

    }

    printf( "Save data to disk file ? (y/n): ");
    scanf( "%s", text);
    if( strcmp(text, "y") == 0 )
    {
        printf( "Lab 3 : ");
        scanf( "%s", filename);
        outfile = fopen( filename, "w");
        for( i=0; i<=400; i++ )
        {
            fprintf( outfile, "%7.4f\t %f\t %7.4f\n", t[i], V[i], P[i]);
        }
        fclose(outfile);
    }
    return 0;
}

//  Created by Erica Chen on 2/20/19.
//  Copyright © 2019 Erica Chen. All rights reserved.

/*
// Pete's feedbacks:
// - Good job on commenting the variables, now document the equations :)
// - Nicely done!
*/
