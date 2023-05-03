//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/03/17
//
#include "mySystem_GalaxySystem.h"
#include <iostream>

using namespace std;

namespace {
    double getRandDouble( double L, double U ) {
        return L + (U-L)*rand( )/(double) RAND_MAX;
    }
};

GALAXY_SYSTEM::GALAXY_SYSTEM( )
{
    mTimeStep = 0.0025; 
    mMaxV = 100.0;
    mNumOfObjs = 100;
    mNumLargeObjs = 2;
    mMinR = 0.5;            //minimum radius of objects
    mMaxR = 3.0;            //maximum radius of objects
    mSpaceSize = 300.0;
    mG = 5.0;               //gravitational constant
    generateObjects( );
}

/*
Generate randomly the positions,  
velocities and radii of the objects.

Also, if the objects are large, 
set their masses to be a large number.

The mass of an  object depends on the object's radius.

The position of an object is inside 
[-halfSpaceSize, halfSpaceSize]x[-halfSpaceSize, halfSpaceSize].

The velocity of an object is inside
[-100.0, 100]x[-100.0, 100].

Initialize the alive flag of each object.
the alive flag indicates whether the object is alive or not.
If the object is not alive, ignore it in all the calculations.

If there's only one large object,
set its position to the origin
and set its velocity to zero.

*/
void GALAXY_SYSTEM::generateObjects( )
{
    //Fill in here
	mNumOfObjs = 100;
    mX.resize( mNumOfObjs );
	mY.resize(mNumOfObjs);
    mR.resize( mNumOfObjs );
    mMass.resize( mNumOfObjs );
    mVx.resize( mNumOfObjs );
    mVy.resize( mNumOfObjs );
	mAlive.resize(mNumOfObjs );
    mFx.resize( mNumOfObjs );
    mFy.resize( mNumOfObjs );

	for (int i = 0; i < mNumOfObjs;i++)
	{
		mX[i] = getRandDouble(-mSpaceSize / 2, mSpaceSize / 2);
		mY[i] = getRandDouble(-mSpaceSize / 2, mSpaceSize / 2);
		mR[i] = getRandDouble(mMinR, mMaxR);
		mMass[i] = mR[i] * mR[i];
		mVx[i] = getRandDouble(-mMaxV, mMaxV);
		mVy[i] = getRandDouble(-mMaxV, mMaxV);
		mAlive[i] = true;
	}
	for (int i = 0; i < mNumLargeObjs; i++)
	{
		if (mNumLargeObjs == 1)
		{
			mX[i] = 0;
			mY[i] = 0;
		}
		mVx[i] = 0;
		mVy[i] = 0;
		mR[i] = mMaxR * 2.0;
		mMass[i] = mMaxR * mMaxR * 1000;
	}
	//cout << "yes\n";
}

/*
Handle the key events.
*/
bool GALAXY_SYSTEM::handleKeyPressedEvent( int key )
{
    bool flgHandled = false;
	switch (key) {
	case '1': mNumLargeObjs = 1;
		flgHandled = true;
		break;
	case '2': mNumLargeObjs = 2;
		flgHandled = true;
		break;
	case '3': mNumLargeObjs = 3;
		flgHandled = true;
		break;
	default:
		break;
	}
	generateObjects();
    return flgHandled;
}

/*
Generate the objects.
Call generateObjects( ).
*/
void GALAXY_SYSTEM::reset( )
{
    generateObjects( );
}

/*
Show the system title.
Show the key usage.
*/
void GALAXY_SYSTEM::askForInput( )
{
	cout << "GALAXY_SYSTEM::askForInput" << endl;
	cout << "Key usage:" << endl;
	cout << "1: one large object" << endl; // generate the objects. Only one large object
	cout << "2: two large object" << endl; // generate the objects. Only two large objects
	cout << "3: three large object" << endl; // generate the objects. Only three large objects
	cout << "r: reset" << endl; 		// reset the positions of the objects
}

/*
Return the number of objects
return mNumOfObjs
*/
int GALAXY_SYSTEM::getNumOfObjs( ) const
{
    return mNumOfObjs;
}

/*
Get the object information based on the object index.
(x,y) = position
r = radius
Return the alive flag.
*/
bool GALAXY_SYSTEM::getObjInfo( int objIndex, double &x, double &y, double &r ) const
{
    x = mX[objIndex];
    y = mY[objIndex];
    r = mR[objIndex];
    return mAlive[objIndex];
}

/*
Merge the objects if they overlap with each other.
Modify the velocities of the objects after merging
based on the conservation of momentum.
Set the alive flags of the objects accordingly.

Pseudo-code

For each pair of the objects
  if they do not overlap continue
  If they overlap
    do
      turn off the alive flag of the object with smaller radius
      compute the new velocity of the larger object
*/
void GALAXY_SYSTEM::mergeObjects( )
{
	for (int i = 0; i < mNumOfObjs; ++i) {
		if (!mAlive[i]) continue;
		int mivi_mjvj_X = 0;
		int mivi_mjvj_Y = 0;
		for (int j = i + 1; j < mNumOfObjs; ++j) {
			if (!mAlive[j]) continue;

			/*check if two spheres overlap
				if they overlap,
					set the smaller one to be ¡¥not alive¡¦
					new velocity = (mi * vi + mj * vj) / (total mass); momentum conservation
					Hint :
			Assume object i is larger.Then, we have*/
			if((mR[i]+mR[j])*(mR[i] + mR[j])>(mX[i]-mX[j])*(mX[i] - mX[j])+(mY[i]-mY[j])*(mY[i] - mY[j]))
			{
				if (mMass[i] < mMass[j])
				{
					swap(mX[i], mX[j]);
					swap(mY[i], mY[j]);
					swap(mMass[i], mMass[j]);
					swap(mR[i], mR[j]);
					swap(mVx[i], mVx[j]);
					swap(mVy[i], mVy[j]);
					swap(mAlive[i], mAlive[j]);
				}
				mivi_mjvj_X = mVx[i] * mMass[i] + mVx[j] * mMass[j];
				mivi_mjvj_Y = mVy[i] * mMass[i] + mVy[j] * mMass[j];


				mMass[i] += mMass[j]; // total mass
				mVx[i] = mivi_mjvj_X / mMass[i];
				mVy[i] = mivi_mjvj_Y / mMass[i];
				mAlive[j] = false;
			}
			
		} // end loop j
	} // end loop i

}

/*
Update the position of the objects
Steps:
1. compute the forces exerting on each object
2. compute the velocity of each object
3. compute the position of each object

Constraints:
The component of a velocity must be inside [-mMaxV, mMaxV].

The component of a position must be inside [-halfSpaceSize, halfSpaceSize].
Warp the position if it's outside of the range.
Consider a position (x,y).
If x > halfSpaceSize, set x = -halfSpaceSize;


*/
void GALAXY_SYSTEM::update( ) 
{
    mergeObjects( ); // merge objects first if they overlap with each other
	for (int i = 0; i < mNumOfObjs; i++) {
		mFx[i] = 0;
		mFy[i] = 0;
		//cout << "?????\n";
	}
	for (int i = 0; i < mNumOfObjs; i++) {
		if (!mAlive[i]) continue;
		//mFx[i] = 0;
		//mFy[i] = 0;
		for (int j = i+1; j < mNumOfObjs; j++)
		{
			if (!mAlive[j]) continue;

				//compute a unit vector which indicates the force direction
			double dx = mX[i] - mX[j], dy = mY[i] - mY[j];
			double d = sqrt(dx * dx + dy * dy);
			double nx = dx / d; //normalize along the x-axis
			double ny = dy / d; //normalize along the y-axis

			double mij = mMass[i] * mMass[j];

			mFx[i] -= mij * mG*nx / (d*d); 	//notice the negative sign	
			mFy[i] -= mij * mG*ny / (d*d);	//notice the negative sign

			mFx[j] += mij * mG*nx / (d*d);	//notice the positive sign
			mFy[j] += mij * mG*ny / (d*d);  //notice the positive sign
			//cout << mFx[i] << '\n';
			//cout << mFx[i] << "\n";
		}
		//cout << mX[i] << '\n';
		//cout << mFx[i] << "\n";
		//cout << mFy[i] << "\n";
	}
	for (int i = 0; i < mNumOfObjs; i++)
	{
		if (!mAlive[i]) continue;
		double m = mMass[i];

		mVx[i] = mVx[i] + mFx[i] / m * mTimeStep;
		mVy[i] = mVy[i] + mFy[i] / m * mTimeStep;
		if (mVx[i] > mMaxV)
			mVx[i] = mMaxV;
		if (mVx[i] < -mMaxV)
			mVx[i] = -mMaxV;
		if (mVy[i] > mMaxV)
			mVy[i] = mMaxV;
		if (mVy[i] < -mMaxV)
			mVy[i] = -mMaxV;
		//cout << "vx" << mVx[i] << '\n';
	}
	for (int i = 0; i < mNumOfObjs; i++)
	{
		if (!mAlive[i]) continue;
		mX[i] = mX[i] + mVx[i] * mTimeStep;
		mY[i] = mY[i] + mVy[i] * mTimeStep;
		if (mX[i] > mSpaceSize / 2)
			mX[i] = -mSpaceSize / 2;
		else if (mX[i] < -mSpaceSize / 2)
			mX[i] = mSpaceSize / 2;
		if (mY[i] > mSpaceSize / 2)
			mY[i] = -mSpaceSize / 2;
		else if (mY[i] < -mSpaceSize / 2)
			mY[i] = mSpaceSize / 2;
	}
    //
    //Fill in here
    //compute forces exerting on objects
    //compute velocities of objects
    //compute positions of objects
    //make sure the objects inside the space
}