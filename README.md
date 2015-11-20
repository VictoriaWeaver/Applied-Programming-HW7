# Applied-Programming-HW7

Application of Curve Fitting to Sensor Calibration

Victoria Weaver
HW7 Applied Programming
Fall 2015

Use of makefile:
To compile all of the files, run the command "make".  All of the files will be compiled.
There are four different commands to run the files**:
        To generate the analog values input to the device, run the command "make data".  All of the analog data values will be output to a textfile "analogValues.txt".
        To generate the digital values returned from the device (unaltered), run the command "make output".  All of the digital values output from the device will be output to a file "uncorrectedDigital.txt".
        To generate the corrected digital values, run the command "make correction".  All of the corrected digital values will be output to a file "correctedDigital.txt".
        To determine the maximum percent error of the device, run the command "make error".  The maximum percent error will be output to stdout.
After running the files, and before compiling them again, run the command "make clean".  This will clean the directory of all the unnecessary files before they are compiled again.  Always run the command "male clean" after any edits are made to the files.  It is also wise to do so after running the files.

**Note:  The commands do not need to be run in a certain order.  Also note that every time they are run, the textfiles containing the output will be overwritten.
