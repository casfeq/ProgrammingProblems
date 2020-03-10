#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double monteCarloCircleArea(vector<double> xPositions, vector<double> yPositions)
{
	double area;
	int size=xPositions.size(), size1=yPositions.size();

	if(size!=size1)
	{
		cout << "Please provide vectors with the same size.\n";
		return 0; 
	}

	double counter=0.;

	for(int i=0; i<size; i++)
	{
		double magnitude=sqrt(xPositions[i]*xPositions[i]+yPositions[i]*yPositions[i]);
		if(magnitude<=1) counter+=1.;
	}

	area=4.*counter/size;

	return area;
}