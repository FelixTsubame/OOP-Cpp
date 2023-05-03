//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/02/25
//
#include "mySystem_SineCosineFunction.h"
#include <iostream>

using namespace std;

namespace {
//minimum number of sample points
#define MIN_NUM_SAMPLES 10

//default number of sample points
#define DFT_NUM_SAMPLES 100  
};

SINECOSINE_FUNCTION::SINECOSINE_FUNCTION( )
{
	x0 = -10.0;
	x1 = 10.0;
	mNumSamples = DFT_NUM_SAMPLES;
	a = b = 1;
}

void SINECOSINE_FUNCTION::increaseA(double increasedAmount)
{
    a += increasedAmount;
	

}

void SINECOSINE_FUNCTION::decreaseA(double decreasedAmount)
{
	a -= decreasedAmount;
}

void SINECOSINE_FUNCTION::increaseB(double increasedAmount)
{
    b += increasedAmount;

}

void SINECOSINE_FUNCTION::decreaseB(double decreasedAmount)
{
	b -= decreasedAmount;
}

void SINECOSINE_FUNCTION::increaseSampleNum(int increasedAmount )
{
    mNumSamples += increasedAmount;
}

void SINECOSINE_FUNCTION::decreaseSampleNum(int decreasedAmount)
{
	mNumSamples -= decreasedAmount;
	if (mNumSamples < 10)
		mNumSamples = 10;
}

//
// reset
void SINECOSINE_FUNCTION::reset()
{
    a = b = 1;
}

//
//Show the system name
//Ask to input a, b
//Ask to input the range of x in [-10, 10]
//Ask to input the number of sample points
//
void SINECOSINE_FUNCTION::askForInput( )
{
	cout << "SINECOSINE_FUNCTION" << endl;
	cout << "Input the coeffients, a and b: a cos(b*x)" << endl;
	cin >> a >> b;
	while (true) {
		cout << "input the range of x, minimum and maximum (The minimum and maximum values should be in the interval [-10, 10].)" << "\n";
		cin >> x0 >> x1;
		if ((x0 >= -10 && x0 <= 10) && (x1 >= -10 && x1 <= 10))
		{
			if (x0 > x1)
				swap(x0, x1);
			break;
		}
	}
	while (true)
	{
		cout << "Input the number of sample points (Interval [2, 100]):" << endl;
		cin >> mNumSamples;
		if (mNumSamples >= 2 && mNumSamples <= 100)
			break;
	}
}
//
// Get the range of x
// by-reference
//(x0, x1) formal parameters
// x0: minimum x 
// x1: maximum x
//
void SINECOSINE_FUNCTION::getRangeOfX(double& xmin,double& xmax ) const
{
	//Return the range of x in x0 and x1.
	xmin = x0;
	xmax = x1;
}

//
//Return the number of samples
//
int SINECOSINE_FUNCTION::getNumOfSamples( ) const
{
	return mNumSamples;
}

//
// Get the function value for x
//
double SINECOSINE_FUNCTION::getValue( double x ) const
{
	// a cos(b*x)
	return a*cos(b*x);
}
// CODE: 2019/02/25. Do not delete this line.