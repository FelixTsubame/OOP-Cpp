//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/02/25
//
#include "mySystemApp.h"

using namespace std;

#define STUDENT_INFO "Name:³¯·q¿Î   ID:0710028"

void MY_SYSTEM_APP::showMyStudentInfo( ) const
{
	cout << "*******************************" << endl;
	cout << "Student ID:0710028\t" << endl;
	cout << "Student Name:³¯·q¿Î\t" << endl;
	cout << "Student Email:lichuan.felix@gmail.com\t" << endl;
	cout << "*******************************" << endl;
}

MY_SYSTEM_APP::MY_SYSTEM_APP( )
{
	mSystemType = SYSTEM_TYPE_MONTE_CARLO_CIRCLE;
    string title = STUDENT_INFO;
        glutSetWindowTitle(title.data( ));
}

void MY_SYSTEM_APP::initApp( )
{
	mFlgShow_Grid = true;
}

void MY_SYSTEM_APP::update( )
{

}
// CODE: 2019/02/25. Do not delete this line.



