/*******************************************************************
 * Victoria Weaver
 * Applied Programming- Fall 2015
 * 
 * Program to correct the output of the sensor to the required
 *	accuracy.  The program should follow the same pipeline design, 
 * 	that is, it should read input from stdin and write output to
 * 	stdout.
 *******************************************************************/

#include <stdio.h>
#include <math.h>

#include "Sensor.h"

/*****************************************************************************
 * * Main program to correct digital measurements.
 * ****************************************************************************/
int main(int argc, char *argv[]){

	/* Digital value to be read from stdin */
	DigitalValues DigitalValue = 0;
	DigitalValues Corrected = 0;

	/* Read in the data */
	while (scanf("%hd", &DigitalValue) != EOF){	
		/* Fit the data */
		Corrected  = DigitalValue * (DigitalValue * 0.00003 + 0.7683) + 184.438 + 0.5;

		/* Print the data */
		printf("%d\n", ((int) Corrected));
     
    } /* for() */
	
	return 0;

}

