import math
import point

class   Planet(point.Point):
    def __init__(self, name, dist, mass, angle, vel):
        self.name = name
        self.mass = mass
        self.vel = vel
        super().__init__(dist, angle)

    def rotate(self, time):
        self.angle += self.vel * time
        self.setCartesianCoord()
        
Sun = Planet("Sun", 0.0, 100.0, 0.0, 0.0)
Mercury = Planet("Mercury", 100.0, 20.0, math.pi/2.0, 2.0*math.pi/288)
Venus = Planet("Venus", 200.0, 40.0, math.pi/2.0, 2.0*math.pi/225)
Earth = Planet("Earth", 400.0, 100.0, math.pi/2.0, 2.0*math.pi/365)
Mars = Planet("Mars", 800.0, 80.0, math.pi/2.0, 2.0*math.pi/687)
