/*
// Program by: Erica Chen
// Coached by: Pete Aguirre II
// Description: We continue off with exploring previous week’s program, which
//              was learning how to find roots with Newton’s Method and in term
//              should help us solve the energy budget. By using the numerical
//              method, Newton’s Method of root finding, we can easily solve
//              Lab 8’s model, which cannot be solved analytically. Energy
//              budgets describe how all objects are in a state of continuous
//              exchange of energy with their environment and an example of
//              this is the lizard energy model budget. This exercise’s
//              objective is to continue off from last week’s model of finding
//              roots while adding essential parameters to solve the lizard
//              energy budget. The goal is to see how air temperature can
//              affect body temperature of the lizard. Parameters that are used
//              are insulation resistance constant at 0.002 m2 degree C * W-1,
//              mass at 0.067 kg, surface area of 0.018 m2, animal emissivity
//              at 0.95 and lizard diameter at 0.01 m. The air temperature will
//              be set at 35 degrees Celsius, and the maximum body core
//              temperature of the lizard is set to 45 degrees Celsius.
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#define euler 2.718
#define sigma 5.67e-8
#define converter 3.722
#define k1 3.49

// From find roots
double f(double);
double fderiv(double);
double x1, x2, deriv;

// From Lizard Energy Budget

// Input(s)
double Qa;               // W/m^2
double windSpeedVel;     // wind speed velocity m/s
double diameter;         // in meter
double insul;            // in Celcius m^2 W^-1
double eps;              // epsilon
double airTemp;          // Ta in Celcius
double maxbodycoreTemp;  // Maximum body Core Temp. in Celcius

// Output(s)
double M;      // Metabolic energy
double lambE;  // Evaportating cooling term
double QOut;   // Radiation outflow
double hc;     // Convection coefficient
double C;      // Covection

double bodyTemp; // In celcius Tb, is this given?

int main(void)
{
  int i, count;
  x1 = 30;
  Qa = 800;              // W/m^2
  windSpeedVel = 2.0;    // wind speed velocity m/s
  diameter = 0.01;       // in meter
  insul = 0.002;         // in Celcius m^2 W^-1
  eps = 0.95;            // epsilon
  airTemp = 35;          // Ta in Celcius
  maxbodycoreTemp = 45;  // Maximum body Core Temp. in Celcius



  // For no. input
  //printf("Enter no.: ");
  //scanf("%lf", &x1);

  // For fidning roots
  for(i=0; i<20; i++){
    x2 = x1 - f(x1)/fderiv(x1);
    // break in condition
    if(fabs(x2-x1) < 1e-10){
      break;
    }
    x1 = x2;
    // print results


  }

    printf("Tb = %5.2f\n", x1);
    printf("QOut = %.2lf\n", QOut);
    printf("C = %.2lf\n", C);
    printf("LambdaE = %.2lf\n", lambE);
    printf("M = %.2lf\n", M);



    return 0;
}

// For fidning root, include later
// Return the total budget here, formula: return (M - lambE + Qa - QOut - C)
double f(double bodyTemp){

  // Metabolic energy term (M)
  M = (0.0258*exp(bodyTemp/10))*converter;

  // Evaportating Cooling Term (E)
  if(bodyTemp <= 20){
    lambE = 0.27*converter;
  }
  else if(bodyTemp > 20 && bodyTemp < 36){
    lambE = (0.08*exp(0.0586*bodyTemp))*converter;
  }
  else if(bodyTemp >= 36){
    lambE =(0.00297*exp(0.1516*bodyTemp))*converter;
  }

  // Radiation outflow term
  QOut = eps*sigma*pow((bodyTemp+273.15-insul*(M-lambE)),4);

  // Convection coefficient
  hc = k1*sqrt(windSpeedVel/diameter);

  // Convection term
  C = hc*(bodyTemp-airTemp-insul*(M-lambE));

  return M-lambE+Qa-QOut-C;
}

double fderiv(double x){
    double h = 0.0001;
    return (f(x+h)-f(x-h))/(2*h);
}

//  Created by Erica Chen on 4/09/19.
//  Copyright © 2019 Erica Chen. All rights reserved.

/*
// Pete's feedbacks:
// - Good documentation
// - Nicely done!
*/
