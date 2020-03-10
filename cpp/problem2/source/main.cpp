#include "randomLib.hpp"
#include "monteCarloLib.hpp"

int main()
{
	int size=10000;
	vector<double> xPositions, yPositions;
	double area;

	xPositions=randomSequence(0,2,size,11);
	yPositions=randomSequence(0,2,size,111);
	area=monteCarloCircleArea(xPositions,yPositions);

	cout << "area=" << area << "\n";

	return 0;
}