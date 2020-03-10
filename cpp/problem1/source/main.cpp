#include "randomLib.hpp"

int main()
{
	double mean=10;
	double intervalSize=2;
	int distributionSize=10;
	vector<double> distribution;
	double empiricalMean;

	distribution=randomSequence(mean,intervalSize,distributionSize,1);
	printSequence(distribution);
	empiricalMean=sequenceEmpiricalMean(distribution);

	cout << "empiricalMean=" << empiricalMean << "\n";

	return 0;
}