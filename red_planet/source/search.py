import param
import planet
import sim
import sat
import eval

p = param.Parameters(1.0, 1.0, 0)

def search(S):
    s = 0
    while s < S:
        p.randomize()
        solution = sim.simulate(sat.Satellite(planet.Earth, p))
        s += 1
        print (eval.evaluate(solution))
