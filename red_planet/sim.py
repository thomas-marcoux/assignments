import math

T = 3650
step = 0.1
G = 0.7
maxRange = 5.0

class   Point:
    def __init__(self, dist, angle):
        self.dist = dist
        self.angle = angle
        self.setCartesianCoord()

    def setCartesianCoord(self):
        self.posX = self.dist * math.cos(self.angle)
        self.posY = self.dist * math.sin(self.angle)

    def calcDistance(self, point):
        return 1

class   Planet(Point):
    def __init__(self, name, dist, mass, angle, vel):
        self.name = name
        self.mass = mass
        self.vel = vel
        super().__init__(dist, angle)

    def rotate(self, time):
        self.angle += self.vel * time
        self.setCartesianCoord()
        
class   Satellite(Point):
    def __init__(self, home):
        self.dist = home.dist
        super().__init__(home.dist, home.angle)
        self.angle = home.angle - home.vel
        self.setCartesianVel(1.0)#difference in position of the sat and the planet

    def setCartesianVel(self, vel):
        self.velX = vel * math.cos(self.angle)
        self.velY = vel * math.sin(self.angle)

    def calcDist(self, planet):
        return self.calcDistance(planet)

    def getForce(self, planet):
        return 1

    def getAcceleration(self, planet, friction):
        return 1

    def updatePosition(self, planet, friction):
        return 1

Sun = Planet("Sun", 0.0, 100.0, 0.0, 0.0)
Mercury = Planet("Mercury", 100.0, 20.0, math.pi / 2.0, 2.0 * math.pi / 288)
Venus = Planet("Venus", 200.0, 40.0, math.pi / 2.0, 2.0 * math.pi / 225)
Earth = Planet("Earth", 400.0, 100.0, math.pi / 2.0, 2.0 * math.pi / 365)
Mars = Planet("Mars", 800.0, 80.0, math.pi / 2.0, 2.0 * math.pi / 687)
bodies = [Sun, Mercury, Venus, Earth, Mars]
sat = Satellite(Earth)
dist = {}

def simulate(velX, velY, friction):
    t = 0
    success = False
    while t < T and not success:
        for body in bodies:
            sat.updatePosition(body, friction)
            print(body.name)
            print("X = %f" % body.posX)
            print("Y = %f" % body.posY)
        success = True
        t += step

simulate(1.0, 1.0, 1.0)
