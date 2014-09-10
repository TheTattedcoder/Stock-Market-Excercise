/******************************************************************************
Homework 2 Main program
Author/copyright: Domonick Mack
Date last modified: 8 September 2014

This program calculates stocks , which are 
100 values , reads them in averages 5 and 10
at a time. Compares the tolerance to see if 
to sell or buy that item. 
*****/
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cmath>
using namespace std;

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "MovingAverage.h"

class Main
{
public:
  int main();
  virtual ~Main();

private:

};

#endif // MAIN_H
