def MonteCarloCircleArea(xPositions, yPositions):
	size = len(xPositions)
	size1 = len(yPositions)
	if size != size1:
		print("Please provide vectors with the same size.")
		return
	counter = 0
	for point in range(0, size):
		magnitude = (xPositions[point] ** 2 + yPositions[point] ** 2) ** 0.5
		if magnitude <= 1:
			counter += 1
	area = 4*counter / size
	return area