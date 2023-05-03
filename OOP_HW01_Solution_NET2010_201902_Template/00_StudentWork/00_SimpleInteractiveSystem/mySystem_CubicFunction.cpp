//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/02/25
//
#include "mySystem_CubicFunction.h"
#include <iostream>

using namespace std;

CUBIC_FUNCTION::CUBIC_FUNCTION( )
{
	x0 = -100.0;
	x1 = 100.0;
	mNumSamples = 400;
    
	a = b = c = d = 0.5;
    a = -0.03;
    b = -0.3;
}

void CUBIC_FUNCTION::increase(double dv)
{
    a += dv;
}

void CUBIC_FUNCTION::decrease(double dv)
{
    a -= dv;

}


void CUBIC_FUNCTION::askForInput( )
{
	//
	//ax^3 + bx^2 + cx + d
	//Show the system name
	//Ask to input a, b, c, d
	//Ask to input the range of x in [-100, 100]
	//Ask to input the number of sample points
	//
	cout << "CUBIC_FUNCTION" << endl;
	
	cout << "Input the coeffients: ax^3 + bx^2 + cx + d" << endl;
	cin >> a >> b >> c >> d;
	while (true) {
		cout << "Input the range of x in [-100, 100]:" << endl;
		cin >> x0 >> x1;
		if ((x0 >= -100 && x0 <= 100) && (x1 >= -100 && x1 <= 100))
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

void CUBIC_FUNCTION::getRangeOfX( double &xmin, double &xmax ) const
{
	//Return the range of x in x0 and x1.
	xmin = x0;
	xmax = x1;
}

int CUBIC_FUNCTION::getNumOfSamples( ) const
{
	//Return the number of samples
	//return mNumSamples;
	return mNumSamples;

}

double CUBIC_FUNCTION::getValue( double x ) const
{
	//Compute ax^3 + bx^2 + cx + d
	//i.e., compute the value a*x*x*x + b*x*x + c*x + d
	return a*x*x*x + b*x*x + c*x + d;
	//return ((a*x + b)*x + c)*x + d;
    //return a*x + b;
}
// CODE: 2019/02/25. Do not delete this line.