
#include "MovingAverage.h"

MovingAverage::MovingAverage()
{
}

MovingAverage::~MovingAverage()
{
}

double MovingAverage::computeAverage(int start, int width)
{
double value;
double sum = 0.0;
double average;
   
  for(int i = start; i < (start + width) ; i++ )
  {
   value = theData[i];
   string val =  Utils::Format(value,8,3);
   cout << val;
   sum += value;
   
  
  }
    cout << " :";
    string tempA = Utils::Format(sum,7,3);
    cout << tempA << " :";
    average = sum / width;
    string tempB = Utils::Format(average,8,3);
    cout << tempB;
   
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
****/
void MovingAverage::doMovingAverage(int width, double tolerance)
{
cout << "Entering doMovingAverage" << endl;
double average;
int valueStart = 0;
double  decisionMetric = 0.0;
string tol = Utils::Format(decisionMetric,8,3);
cout << " Computing the width and tolerance " << width << " " << tolerance
     << endl;
  
 for(unsigned i = 0; i < theData.size() -width; i++)
 {
    average = computeAverage(i,width);
    std::cout << Utils::Format(average,8,3);
    decisionMetric = theData[i + width - 1]/average;
    string DM = Utils::Format(decisionMetric,8,3);
    cout << DM;
   
    if(  decisionMetric > (1 + tolerance))
    {
       cout << " sell" << endl;
       valueStart++;
    }
      else 
      {
         if(  decisionMetric < (1 - tolerance) )
         {
           cout << " buy " << endl;
           valueStart++;
         }
         else
         {
           cout << "\n";
         }
      }        
  }             
cout << "leaving doMovingAverage" << endl;        
        
}

/******************************************************************************
In the readData() we are simply inputing the "xintput.txt" file in a vector. 
we create a object for Scanner class and use a While loop to continously scan
for text in the file until it has nothing else in it. While the scanner is 

****/
void MovingAverage::readData(string fileName)
{
Scanner inScanner;
double value ;
inScanner.openFile(fileName);
cout << "Now receiving Stocks" << endl;

  while(inScanner.hasNext())
  {
    value = inScanner.nextDouble(); 
    theData.push_back(value);  
  }
  
 
}

string MovingAverage::toStringTheData()
{
  string blah = " ";
  return blah;
}
