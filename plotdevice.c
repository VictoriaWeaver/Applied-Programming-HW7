/****************************************************************
 plotdevice devicedata

 Generates a png figure with the device input-output curve,
 the file devicedata has two columns the first is for the
 input values and the second for the output values.

 Notes:
 1) If you have two files one with inputs and one with outputs
    you can combine them "by rows" using the bash command

    paste x_data_file y_data_file > devicedata

 2) In your .bashrc file you need to add the following lines
     export GDFONTPATH=/usr/share/fonts/dejavu/DejaVuSans
     export GNUPLOT_DEFAULT_DDFONT="DejaVuSans.ttf"
        
 3) popen is not ANSI (it is POSIX compliant) 

 Author: Juan C. Cockburn - Rev. Nov 2014 (Red Hat OS)
 Revised: 4/14/2015
 ***************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
  float yMax;		/* Maximum Magnitude of DFT coeffcients */
  FILE *pipe;		/* pipe to gnuplot  */
  char *datafile;	/* string for title */
  char cmd[256];        /* command string   */

  /* Allocate space for file name string */
  datafile = malloc(sizeof(char)*256);
  
  if (2 == argc) {
      strcpy(datafile,argv[1]);
      printf("Data file: |%s|\n",datafile); 
      /* Open pipe to gnuplot */
      if ((pipe = (FILE *) popen ("gnuplot -persist", "w")) == NULL) {
        fprintf (stderr,"Unable to open pipe to gnuplot\n");
        return -1;
      }
      /* Gnuplot commands */
      
      /* Set output to png file, can change to svg or x11 */
      fprintf (pipe, "set terminal png enhanced font 'DejaVuSans.ttf'\n");
      sprintf (cmd, "set output 'device_%s.png'\n","0");
      fprintf (pipe, "%s", cmd);

      /* Set plot attributes */ 
      fprintf (pipe, "set key off\n");
      fprintf (pipe, "set border 3\n");
      fprintf (pipe, "set style data lines\n");

      #if 0
      /* X-axis formatting */
      sprintf (cmd,"set xrange [0:%d]\n",N);
      fprintf (pipe, "%s", cmd);
      fprintf (pipe, "set xtic 8 nomirror\n");
      /* Y-axis formatting  */   
      sprintf (cmd,"set yrange [0:%d]\n",ceil(yMax));
      fprintf (pipe, "%s", cmd);
      fprintf (pipe, "set ytic 10 nomirror\n");
      #endif
      
      /* Title, labels and legend */
      sprintf (cmd,"set title 'Sensor Response Curve'\n");
      fprintf (pipe, "%s", cmd);
      fprintf (pipe, "set ylabel 'Digital Output'\n");
      fprintf (pipe, "set xlabel 'Analog Input'\n");

      /* Read data from file and generate plot */ 
      fprintf (pipe, "plot ");
      sprintf (cmd,"'%s' using 1:2 lt 1 lw 2\n",datafile);
      fprintf (pipe, "%s", cmd);

      /* clean up: close pipe and return success code */
      pclose (pipe);
      return 0;
    }  /* if argc */
  else /* not called with 2 arguments */
    {  /* wrong number of args, display program usage */
      printf ("Usage: %s datafile\n", argv[0]);
    }				/* else () */
  return 0;
} /* main */
