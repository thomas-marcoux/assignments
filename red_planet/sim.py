import sat
import planet

T = 3650
step = 0.1
maxRange = 5.0
bodies = [planet.Sun, planet.Mercury, planet.Venus, planet.Earth, planet.Mars]
dist = {}

def simulate(velX, velY, friction):
    t = 0
    success = False
    while t < T and not success:
        for body in bodies:
            sat.Sat.updatePosition(body, friction)
            print(body.name)
            print("dist = %f" % sat.Sat.calcDistance(body))
        success = True
        t += step
