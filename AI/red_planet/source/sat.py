import math
import point
import param

G = 0.7

class   Satellite(point.Point):
    def __init__(self, home, param):
        super().__init__(home.dist, home.angle)
        self.angle = home.angle - home.vel
        self.setCartesianCoord()
        self.setParam(param)
        self.vel = self.getDistFromPlanet(home)

    def setParam(self, param):
        self.velX = param.velX
        self.velY = param.velY
        self.friction = param.friction

    def setCartesianVel(self, vel):
        self.velX = vel * math.cos(self.angle)
        self.velY = vel * math.sin(self.angle)

    def getDistFromPlanet(self, point):
        return self.calcDistance(point)

    def getForce(self, planet):
        return G * planet.mass / self.getDistFromPlanet(planet)
        #return G * planet.mass / ((self.getDistFromPlanet(planet))**2)

    def updateAcceleration(self, force):
        self.accX = force - self.friction * self.velX
        self.accY = force - self.friction * self.velY

    def updatePosition(self, time):
        self.posX += time * self.velX
        self.posY += time * self.velY

    def updateVelocity(self, time):
        self.velX += time * self.accX
        self.velY += time * self.accY

    def update(self, force, time):
        self.updateAcceleration(force)
        self.updatePosition(time)
        self.updateVelocity(time)
