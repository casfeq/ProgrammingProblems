from numpy.random import random

def randomSequence(mean,intervalSize,distributionSize):
	fluctuation=random(distributionSize)
	distribution=mean-intervalSize*0.5+intervalSize*fluctuation
	return distribution