import planet
import sol

T = 3650
step = 0.1
maxRange = 5.0
bodies = [planet.Sun, planet.Mercury, planet.Venus, planet.Earth, planet.Mars]

def getForceSum(sat, bodies):
    force = 0
    for body in bodies:
        force += sat.getForce(body)
    return force

def rotateAll(bodies):
    for body in bodies:
        body.rotate(step)

def simulate(sat):
    t = 0
    success = False
    solution = sol.Sol(sat.vel)
    solution.setDistMin(sat.getDistFromPlanet(planet.Mars))
    while t < T and not success:
        force = getForceSum(sat, bodies)
        sat.update(force, step)
        distFromMars = sat.getDistFromPlanet(planet.Mars)
        if (distFromMars <= maxRange):
            success = True
        if distFromMars < solution.distMin:
            solution.setDistMin(distFromMars)
        rotateAll(bodies)
        t += step
    solution.setTmin(t)
    return solution
