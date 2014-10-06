import math
import sol

def evaluate(solution):
    cost = solution.distMin * math.pow(10, 5)
    + math.fabs(solution.velInit) * math.pow(10, 4) + solution.tMin * 10
    return round(cost, 2)
