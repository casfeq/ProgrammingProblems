#include "randomLib.hpp"

int main()
{
	double mean=10;
	double intervalSize=2;
	int distributionSize=10;
	vector<double> distribution=randomSequence(mean,intervalSize,distributionSize);

	return 0;
}