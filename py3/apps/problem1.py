import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), os.path.pardir))
import numpy as np
from libs.Random import *

mean = 10
intervalSize = 2
distributionSize = 10

randomNumbers = RandomSequence(mean, intervalSize, distributionSize)
empiricalMean = np.mean(randomNumbers)

print(randomNumbers)
print(empiricalMean)