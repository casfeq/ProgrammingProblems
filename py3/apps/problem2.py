import sys,os
sys.path.append(os.path.join(os.path.dirname(__file__),os.path.pardir))
from libs.Random import randomSequence
from libs.MonteCarlo import *

size=10000

xPositions=randomSequence(0,2,size)
yPositions=randomSequence(0,2,size)
area=monteCarloCircleArea(xPositions,yPositions)

print(area)