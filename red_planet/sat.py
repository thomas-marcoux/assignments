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

    def getDistFromPlanet(self, point):
        return self.calcDistance(point)

    def getForce(self, planet):
        return G * planet.mass / self.getDistFromPlanet(planet)
        #return G * planet.mass / ((self.getDistFromPlanet(planet))**2)

    def getAcceleration(self, planet, friction):
        return self.getForce(planet) - friction * self.vel

    def updatePosition(self, planet, friction):
        self.posX += 0
        self.posY += 0

    def updateVelocity(self, planet, friction):
        self.velX += 0
        self.velY += 0

    def update(self, planet, friction):
        self.updatePosition(planet, friction)
        self.updateVelocity(planet, friction)

Sat = Satellite(planet.Earth)
