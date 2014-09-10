/******************************************************************************
Homework 2 Main program
Author/copyright: Domonick Mack
Date last modified: 8 September 2014

This program calculates stocks , which are 
100 values , reads them in averages 5 and 10
at a time. Compares the tolerance to see if 
to sell or buy that item. 
*****/

#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class MovingAverage
{
public:
  MovingAverage();
  virtual ~MovingAverage();

  void doMovingAverage(int width, double tolerance);
  void readData(string fileName);
  string toStringTheData();

private:
  vector<double> theData;

  double computeAverage(int start, int width);
};

#endif
