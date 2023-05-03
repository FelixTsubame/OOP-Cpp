//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/02/25
//
#include "mySystem_StudentRecordManager.h"
#include <iostream>


using namespace std;

STUDENT_RECORD_MANAGER::STUDENT_RECORD_MANAGER( )
{
	mNumStudents = 0;
}

void STUDENT_RECORD_MANAGER::askForInput( )
{
	//Show the system title
	//Ask to input the number of students
	//Ask to input the score of each student
	//Show the average
	//Show the standard deviation
	//Show the scores in an ascending order
	//
	cout << "STUDENT_RECORD_MANAGER" << endl;
	while ( true ) {
		cout << "Input the number of students [2, 100]:" << endl;

		cin >> mNumStudents;
		if ( mNumStudents >= 2 && mNumStudents <=100 ) break;
	}
	cout << "Input the score of each student, the score range is [0, 100]:" << "\n";
	mScore.clear();
	int score=0;
	for (int i = 0; i < mNumStudents; i++)
	{
		cin >> score;
		mScore.push_back(score);
	}
	cout << "Average:" << computeAverage( ) << "\n";

	cout << "Standard Deviation:" << computeStandardDeviation( ) << "\n";

    
    sortScores( );
	showSortedScores( );
}

double STUDENT_RECORD_MANAGER::computeAverage( )
{
	//Compute the average
    int totalScore = 0;
	for (int i = 0; i < mScore.size(); i++)
		totalScore += mScore[i];
	mAverageScore = totalScore/mNumStudents;
	return mAverageScore;
}

double STUDENT_RECORD_MANAGER::computeStandardDeviation( )
{
	//Compute the standard deviation

	double sum = 0.0;
	double sum_s = 0.0;
	for (int i = 0; i < mScore.size(); i++)
		sum += mScore[i];
	sum /= mNumStudents;
	for (int i = 0; i < mScore.size(); i++)
		sum_s += (mScore[i]-sum)*(mScore[i] - sum);
	mStandardDeviation = sqrt(sum_s/(mNumStudents-1));

	return mStandardDeviation;
}

void STUDENT_RECORD_MANAGER::sortScores( )
{
	mSortedScore.clear();
	//Sorting in an ascending order
	for (int i = 0; i < mNumStudents; i++)
		mSortedScore.push_back(mScore[i]);
	for (int i = 0; i < mNumStudents; i++)
		for (int j = 0; j < mNumStudents - i - 1; j++)
			if (mSortedScore[j] > mSortedScore[j + 1])
				swap(mSortedScore[j], mSortedScore[j + 1]);
}

void STUDENT_RECORD_MANAGER::showSortedScores( ) const
{
	//Show the scores in an ascending order
	cout << "Sorted Score:" << "\n";
	for (int i = 0; i < mSortedScore.size();i++)
		cout << mSortedScore[i] << '\n';
}

int STUDENT_RECORD_MANAGER::getNumOfStudentsInScoreInterval(int s0, int s1) const
{
	//
	//Return the number of students whose score is inside the interval [s0, s1]. 
	//s0 and s1 are included.
	// 
	int num = 0;
	for (int i = 0; i < mNumStudents; i++)
	{
		if (mScore[i] >= s0 && mScore[i] <= s1)
			num++;
	}
    return num;
}
// CODE: 2019/02/25. Do not delete this line.