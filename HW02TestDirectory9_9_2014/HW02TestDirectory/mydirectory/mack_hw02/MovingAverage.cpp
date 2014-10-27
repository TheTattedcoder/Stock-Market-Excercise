/******************************************************************************
Homework 2 Main program
Author/copyright: Domonick Mack
Date last modified: 8 September 2014

This program calculates stocks , which are 
100 values , reads them in averages 5 and 10
at a time. Compares the tolerance to see if 
to sell or buy that item. 
*****/
#include "MovingAverage.h"

MovingAverage::MovingAverage()
{
}

MovingAverage::~MovingAverage()
{
}
/******************************************************************************
In this function, it takes in two values with the type "int". These two values
come from the doMovingAverage() function which are the index position and the 
width of the window of values in the vector. The for loop adds all the values 
at each position within the length of the window.Then it is given to the variable
"sum" which is then divided by the width of the vector and given to the variable 
"average". Finally the "average" is then passed back to the doMovingAverage() 
to continue the process. The Formatting Utils function follow respectively. 

Parameters:
   start - starting position within the width of the vector 
   width - size given of how many values are within the vector
   
   Output: Formatted integers using the class Utils and
           returns average of the width of window (i.e. vector)    
****/
double MovingAverage::computeAverage(int start, int width)
{
double value;
auto sum = 0.0;
double average;
   
  for(auto i = start; i < (start + width) ; ++i )
  {
   value = theData[i];
   std::string val =  Utils::Format(value,8,3);
   std::cout << val;
   sum += value;
  }
    std::cout << " :";
    std::string tempA = Utils::Format(sum,7,3);
    std::cout << tempA << " :";
    average = sum / width;
    std::string tempB = Utils::Format(average,8,3);
    std::cout << tempB;
   
  return( average );
}
/******************************************************************************
 Within this function, doMovingAverage(), this is where we would take in the 
the width value and subtract it from the size of the vector of stocks. The 
reason for this is to get every five of ten value from the vector and add them
using the computeAverage() in the for loop. Once the computation is complete and
the answer returns to the variable "average", then the variable "decisionMetric"
, which is the last number in the window and divides it by the average of the 
vector. Finally, in the for loop a couple of statements are ran to decide if 
the decisionMetric is greater than tolerance + 1 then sell that bad boy, if the
the decisionMetric is less than the tolerance -1, then buy it or say nothing. 
Once that is determined increment the valueStart, starting postion in vector, by
one. 

Parameters:
   tolerance - percentage of rate of growth, given as a double
   width - size given of how many values are within the vector
   
Output: Formatted integers using the class Utils and if that set of days 
        was for sale, if they were bought or lefted alone.
   

****/
void MovingAverage::doMovingAverage(int width, double tolerance)
{
std::cout << "Entering doMovingAverage" << std::endl;
double average;
auto valueStart = 0;
double  decisionMetric = 0.0;
string tol = Utils::Format(decisionMetric,8,3);
std::cout << " Computing the width and tolerance " << width << " " << tolerance
     << std::endl;
  
 for(auto i = 0; i < theData.size() -width; ++i)
 {
    average = computeAverage(i,width);
    std::cout << Utils::Format(average,8,3);
    decisionMetric = theData[i + width - 1]/average;
    std::string DM = Utils::Format(decisionMetric,8,3);
    std::cout << DM;
   
    if(  decisionMetric > (1 + tolerance))
    {
       std::cout << " sell" << std::endl;
       ++valueStart;
    }
      else 
      {
         if(  decisionMetric < (1 - tolerance) )
         {
           std::cout << " buy " << std::endl;
           valueStart++;
         }
         else
         {
           std::cout << "\n";
         }
      }        
  }             
std::cout << "leaving doMovingAverage" << std::endl;        
        
}

/******************************************************************************
In the readData() we are simply inputting the "xintput.txt" file in a vector. 
we create a object for Scanner class and use a While loop to continuously scan
for text in the file until it has nothing else in it. While the scanner is 
reading in the values this data is now pushed back into a vector called TheData.
We now have a vector that consist of 100 values of stock and it now received.


****/
void MovingAverage::readData(std::string fileName)
{
Scanner inScanner;
double value ;
inScanner.openFile(fileName);
std::cout << "Now receiving Stocks" << std::endl;

  while(inScanner.hasNext())
  {
    value = inScanner.nextDouble(); 
    theData.push_back(value);  
  }
  
 
}

std::string MovingAverage::toStringTheData()
{
  std::string blah = " ";
  return blah;
}
