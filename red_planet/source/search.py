import param
import planet
import sim
import sat
import eval

def search(S):
    s = 0
    p = param.Parameters()
    while s < S:
        p.randomize()
        solution = sim.simulate(sat.Satellite(planet.Earth, p))
        print (s+1, ": <eval>\t$", eval.evaluate(solution), "\t", solution.distMin, "\t",
               solution.tMin, "\t", p.velX, "\t", p.velY, "\t", p.friction)
        s += 1
