import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), os.path.pardir))
from libs.Random import RandomSequence
from libs.MonteCarlo import *

size = 10000

xPositions = RandomSequence(0, 2, size)
yPositions = RandomSequence(0, 2, size)
area = MonteCarloCircleArea(xPositions, yPositions)

print(area)