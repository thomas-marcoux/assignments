import math

class   Point:
    def __init__(self, dist, angle):
        self.dist = dist
        self.angle = angle
        self.setCartesianCoord()

    def setCartesianCoord(self):
        self.posX = self.dist * math.cos(self.angle)
        self.posY = self.dist * math.sin(self.angle)

    def calcDistance(self, point):
        x = point.posX - self.posX
        y = point.posY - self.posY
        return math.sqrt((x**2) + (y**2))
