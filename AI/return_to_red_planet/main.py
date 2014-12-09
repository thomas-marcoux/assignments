import math
import time

class Datapoint:
    def __init__(self, x, y, l):
        self.x = float(x)
        self.y = float(y)
        self.prediction = float(l)
        self.distance = 0.0
        self.l = 0.0
        
    def set_distance(self, testPoint):
        self.distance = calc_distance(self, testPoint)

def read_data(xFile, yFile, lFile):
    lst = []
    x = open(xFile, 'r')
    y = open(yFile, 'r')
    l = open(lFile, 'r')
    for xLine, yLine, lLine in zip(x, y, l):
        d = Datapoint(xLine, yLine, lLine)
        lst.append(d)
    return lst

def readTesting():
    return read_data("testX.txt", "testY.txt", "testL.txt")
    
def readTraining():
    return read_data("trainX.txt", "trainY.txt", "trainL.txt")

def calc_distance(p1, p2):
    return math.sqrt(math.pow(p2.x - p1.x, 2) + math.pow(p2.y - p1.y, 2))

def set_all_distances(trainingList, testPoint):
    for datapoint in trainingList:
        datapoint.set_distance(testPoint)

def sort_by_distance(trainingList):
    trainingList.sort(key=lambda Datapoint: Datapoint.distance)

def get_average_knn(trainingList, k):
    sumLabel = 0
    for i in range(k):
        sumLabel += trainingList[i].prediction
    return sumLabel / k

def predict_label(trainingList, testPoint, k):
    testPoint.l = get_average_knn(trainingList, k)

def set_all_labels(trainingList, testingList, k):
    for datapoint in testingList:
        set_all_distances(trainingList, datapoint)
        sort_by_distance(trainingList)
        predict_label(trainingList, datapoint, k)

def get_accuracy(testingList):
    sumPrediction = 0
    sumLabel = 0
    for datapoint in testingList:
        sumPrediction += datapoint.prediction
        sumLabel += datapoint.l
    return sumLabel / sumPrediction

def loop_k(trainingList, testingList, maxK):
    accuracy = {}
    for k in range(1, maxK):
        set_all_labels(trainingList, testingList, k)
        accuracy[k] = get_accuracy(testingList)
    return accuracy

def main():
    print(time.ctime())
    k = 41
    trainingList = readTraining()
    testingList = readTesting()
    accuracy = loop_k(trainingList, testingList, k)
    print(accuracy)
    print(time.ctime())

main()
