import math

T = 3650
step = 0.1
G = 0.7
maxRange = 5.0

class   Point:
    def __init__(self, dist, angle, vel):
        self.dist = dist
        self.angle = angle
        self.vel = vel
        self.setCartesianCoord()

    def setCartesianCoord(self):
        self.posX = self.dist * math.cos(self.angle)
        self.posY = self.dist * math.sin(self.angle)

    def rotate(self, angle):
        self.angle += angle
        self.setCartesianCoord()

class   Planet(Point):
    def __init__(self, name, dist, mass, angle, vel):
        self.name = name
        self.mass = mass
        super().__init__(dist, angle, vel)
        
class   Satellite(Point):
    def __init__(self, home):
        self.dist = home.dist
        super().__init__(home.dist, home.angle, home.vel)
        self.angle = home.angle - home.vel

    def calc_dist(planet):
        return 1

    def calc_force(planet):
        dist = calc_dist(planet)
        return G * planet.mass / (dist * dist)

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
            dist[body.name] = sat.dist - body.dist
            if dist[body.name] == 0:
                print(body.name)
        success = True
        t += step
        
simulate(0.0, 0.0, 0.0)
