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
            sat.Sat.update(body, friction)
            print(body.name)
            print("force = %f" % sat.Sat.getForce(body))
        success = True
        t += step
