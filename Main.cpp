#include "Main.h"

/******************************************************************************
Homework 2 Main program
Author/copyright: Domonick Mack
Date last modified: 8 September 2014

This program calculates stocks , which are 
100 values , reads them in averages 5 and 10
at a time. Compares the tolerance to see if 
to sell or buy that item. 
*****/

int main(int argc, char *argv[])
{
  string fileName = "xinput.txt";
  MovingAverage movingAverage;

  movingAverage.readData(fileName);

  movingAverage.doMovingAverage(5, 0.1);

  movingAverage.doMovingAverage(5, 0.05);

  movingAverage.doMovingAverage(10, 0.1);

  movingAverage.doMovingAverage(10, 0.05);

  return 0;
}

