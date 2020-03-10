from numpy.random import random

def randomSequence(mean,intervalSize,distributionSize):
	fluctuation=random(distributionSize)
	distribution=mean-intervalSize*0.5+intervalSize*fluctuation
	return distribution

def monteCarloCircleArea(xPositions,yPositions):
	counter=0.
	size=len(xPositions)
	size1=len(yPositions)
	if size!=size1:
		print("Please provide two vectors with the same size.")
		return
	for point in range(0,size):
		magnitude=(xPositions[point]**2+yPositions[point]**2)**0.5
		if magnitude<=1:
			counter+=1.
	area=4.*counter/size
	return area