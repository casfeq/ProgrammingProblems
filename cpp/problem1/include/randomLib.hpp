#include <iostream>
#include <numeric>
#include <vector>

#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

using namespace std;
using namespace boost;

typedef minstd_rand base_generator_type;

void printSequence(vector<double> distribution)
{
	cout << "distribution=[ ";
	for(int i=0; i<distribution.size(); i++)
	{
		cout << distribution[i] << " ";
	}
	cout << "]\n";
}

double sequenceEmpiricalMean(vector<double> distribution)
{
	int size=distribution.size();
	double empiricalMean;
	if(size!=0) empiricalMean=accumulate(distribution.begin(),distribution.end(),0.0)/size;

	cout << "empiricalMean=" << empiricalMean << "\n";

	return empiricalMean;
}

vector<double> randomSequence(double mean, double intervalSize, int distributionSize)
{
	vector<double> distribution;
	base_generator_type generator(19890425);
	uniform_real<> uniform_distribution(0,intervalSize);
	variate_generator<base_generator_type&,uniform_real<>> fluctuation(generator,
		uniform_distribution);

	for(int i=0; i<distributionSize; i++)
	{
		distribution.push_back(mean+intervalSize*(fluctuation()-0.5));
	}

	printSequence(distribution);
	sequenceEmpiricalMean(distribution);

	return distribution;
}