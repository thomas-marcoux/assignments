import math
import point
import planet

G = 0.7

class   Satellite(point.Point):
    def __init__(self, home):
        super().__init__(home.dist, home.angle)
        self.angle = home.angle - home.vel
        self.setCartesianCoord()
        self.setCartesianVel(1.0)#difference in position of the sat and the planet

    def setCartesianVel(self, vel):
        self.velX = vel * math.cos(self.angle)
        self.velY = vel * math.sin(self.angle)

    def calcDist(self, point):
        return self.calcDistance(point)

    def getForce(self, planet):
        return 1

    def getAcceleration(self, planet, friction):
        return 1

    def updatePosition(self, planet, friction):
        return 1

Sat = Satellite(planet.Earth)
