/*************************************
 * Header for device parameters 
 *
 * Revised 4/14/2015 (JCCK)
 ************************************/

/* Typemark for 16-bit Digital numbers */
/* WARNING: Platform dependent         */
typedef short int DigitalValues;

/* Number of sensor measurements over operating range. */
#define NUM_STEPS (4000)

/* Range of possible input values */
#define MIN_SENSOR (0.0)
#define MAX_SENSOR (5.0)

/* Range of input values that the sensor was designed for */
#define MIN_ACCURATE_SENSOR (0.1)
#define MAX_ACCURATE_SENSOR (4.9)

/* Characterisitcs of AD converter */
#define A2D_SIZE (12)
#define MAX_A2D ((1 << A2D_SIZE) - 1)
