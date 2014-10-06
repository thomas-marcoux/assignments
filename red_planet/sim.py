import sat
import planet

T = 3650
step = 0.1
maxRange = 5.0
bodies = [planet.Sun, planet.Mercury, planet.Venus, planet.Earth, planet.Mars]
dist = {}

def getForceSum(bodies):
    force = 0
    for body in bodies:
        force += sat.Sat.getForce(body)
    return force

def rotateAll(bodies):
    for body in bodies:
        body.rotate(step)

def simulate(velX, velY, friction):
    t = 0
    success = False
    while t < T and not success:
        force = getForceSum(bodies)
        sat.Sat.update(force, step)
        if (sat.Sat.getDistFromPlanet(planet.Mars) <= 5.0):
            success = True
        rotateAll(bodies)
        t += step
