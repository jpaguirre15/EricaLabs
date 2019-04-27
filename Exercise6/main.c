/*
// Program by: Erica Chen
// Coached by: Pete Aguirre II
// Description: For this week’s exercise, we revisited the logistic population
//              model that was seen in Lab 2, which was:
//               Nt+1 = Nt +rNt(1- Nt/K).
//              However, for the purpose of this week’s exercise, the logistic
//              population model will be represented as an ordinary
//              differential equation (ODE) instead of the finite difference
//              equation (FDE). For an ODE, time is going to be continuous
//              compared to an FDE. The ODE used for this week’s exercise will
//              be:
//                dN/dt = rN (1-N/K)
//              We also revisited Euler’s Method which can help us predict
//              population sizes and the prediction will be more accurate with
//              small numbers. However, using larger time steps will not give a
//              great accuracy since the curve of the line is smooth and that
//              is one flaw of this method. By comparing the results from
//              Euler’s Method to an analytical solution (if applicable), we
/               can see how accurate the solutions are from Euler’s Method.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void){

    int i, steps, increment;
    float r, K, dn, dt, tfinal;
    char text[30];
    char filename[30];
    FILE *outfile;

    r = 1.5;
    K = 100;
    tfinal = 30;
    dt = 2.0;
    steps = 15;

    //steps = ceil(tfinal/dt);
    float N[steps+1], t[steps+1];

    t[0] = 0;
    N[0] = 2;

    for(i=0; i<steps; i++){
        //dn = k * N[index] * dt;
        dn = r * N[i] * (1- N[i]/K) * dt;
        N[i+1] = N[i] + dn;
        t[i+1] = t[i] + dt;
    }
    increment = round(1/dt);

    printf("dt = %6.5f, Increment = %i\n", dt, increment);
    for(i=0; i<=steps; i += increment){
        printf("%4.1f, %6.4f\n", t[i], N[i]);
    }

    printf( "Save data to disk file ? (y/n): ");
    scanf( "%s", text);
    if( strcmp(text, "y") == 0 )
    {
        printf( "Lab 06 : ");
        scanf( "%s", filename);
        outfile = fopen( filename, "w");
        for( i=0; i<=steps; i++ )
        {
            fprintf( outfile, "%4.1f\t %6.4f\n", t[i], N[i]);
        }
        fclose(outfile);
    }

    return 0;
}

//  Created by Erica Chen on 3/25/19.
//  Copyright © 2019 Erica Chen. All rights reserved.

/*
// Pete's feedbacks:
// - What happened with documentation?? :c
// - Nicely done!
*/
