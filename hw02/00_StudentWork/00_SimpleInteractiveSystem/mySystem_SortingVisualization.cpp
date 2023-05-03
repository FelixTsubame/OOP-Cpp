//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/03/17
//
#include "mySystem_SortingVisualization.h"
#include <iostream>

using namespace std;

SORTING_VISUALIZATION::SORTING_VISUALIZATION( )
{
    mNumElements = 20;
    mMinValue = 1;
    mMaxValue = 30;
    reset( );
}

/*
Generate randomly the elements between mMinValue and mMaxValue.
The total number of elements is mNumElements.
*/
void SORTING_VISUALIZATION::reset( )
{
	mNumbers.resize(mNumElements);
	mCurrentIndex = 0;
	mMaxNonHandledElementIndex = mNumElements;
	for (int i = 0; i < mNumElements; i++)
	{
		int temp;
		int r = rand() % RAND_MAX;
		double f = r / (double)RAND_MAX;
		temp = mMinValue + (mMaxValue - mMinValue)*f;
		mNumbers[i]=temp;
	}
}

/*
Show the system title.
Ask to input the range [mMinValue, mMaxValue] of the elements.
Ask to input the number of elements.
Generate the elements.
*/
void SORTING_VISUALIZATION::askForInput( )
{
    cout << "//////////////////////////////" << endl;
    cout << "SORTING_VISUALIZATION" << endl;
	cout << "The range of elements is [1,30]:\n";
	cout << "Input minValue and maxValue:\n";
	cin >> mMinValue >> mMaxValue;
	cout << "Input the number of elements [1,50]:\n";
	cin >> mNumElements;
	//reset();
	cout << "//////////////////////////////" << endl;
	cout << "Press SPACEBAR to visualize the process..." << endl;
	cout << "//////////////////////////////" << endl;
}

/*
Two elements whose
indices are (index) and (index+1).

Swap these two elements if their order is incorrect.
*/
void SORTING_VISUALIZATION::checkAndSwapTwoElements( int index )
{
	if (mNumbers[index] > mNumbers[index + 1])
		swap(mNumbers[index], mNumbers[index + 1]);
	//cout << "yes\n";
}

/*
Perform one swap step for two elements.
The first element is indicated by mCurrentIndex.
*/
void SORTING_VISUALIZATION::processOneSwapStep( )
{
	checkAndSwapTwoElements(mCurrentIndex);
	mCurrentIndex++;
	//cout << mCurrentIndex << "\n";
	if (mCurrentIndex == mMaxNonHandledElementIndex-1)
	{
		mMaxNonHandledElementIndex-=1;
		mCurrentIndex = 0;
	}
	if (mMaxNonHandledElementIndex <= 1)
		mCurrentIndex = mNumElements;
	
}

/*
Return the current element that will be processed.
*/
int SORTING_VISUALIZATION::getCurrentElementIndex( ) const
{
	//cout << "yes_current\n";
	//if (mMaxNonHandledElementIndex == 1)

    return mCurrentIndex;
}

/*
Return the index of the last non-handled element.

mMaxNonHandledElementIndex
*/
int SORTING_VISUALIZATION::getMaxNonHandledElementIndex( ) const
{
	//cout << "yes_Max\n";
	return mNumElements;
}

/*
Return the number of elements.
*/
int SORTING_VISUALIZATION::getNumOfElements( ) const
{
    //Return the number of elements
	//cout << "yes_getNum\n";
	return mNumElements;
}

/*
Return the element whose index is elementIndex.
*/
int SORTING_VISUALIZATION::getElement( int elementIndex ) const
{
    return mNumbers[elementIndex];
}