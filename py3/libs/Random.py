from numpy.random import random

def RandomSequence(mean, intervalSize, distributionSize):
	fluctuation = random(distributionSize)
	distribution = mean + intervalSize * (fluctuation - 0.5)
	return distribution