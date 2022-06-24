# QmisID_calc

## Introduction
This code consists of four parts, QmisID_count, plots, fit and MisID_Calc.

QmisID_count is the main part, that reads through the ntuples and makes all plots seperately for ss and os events as well as counts the number of ss and os events in each bin.

The text output from QmisID_count can be used as an input in MisID_Calc to perform the likelihood fit to Extract QmisID. 

The Fit folder is to fit the Z peak and plots folder has scripts that can be used for ploting various uncertainties.

## QmisID_count

The main code is in QmisID_count.cxx which has the main event loop with all the cuts and weights applied.

It can be compiled and run using the driver script ana.C The input output file paths are declared here. Also, you can define what kind of weight you would like to apply. It is important to check which number is used at SetData option before running the code.

0: MC, 1: data, 2: data with BG subtraction, 3: QmisID reweighting, 4: gammastar region, 5: co region, 6: ttw region

The binning is defined in the header file QmisID_count.h. Also you can decide which branches to access using this file.

To run the code 
```
source COMPILEIT
./ana 1
```

## MisID_Calc

This is a very simple root macro to perform TMinuit fit. Use the run.sh file to run the script.

## Plots

This uses atlasplots for plotting. https://atlas-plots.readthedocs.io/

