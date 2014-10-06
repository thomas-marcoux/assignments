import param
import eval

p = param.Parameters(1.0, 1.0, 0)

def search(S):
    s = 0
    p.randomize()
    print(eval.evaluate(p))
    while s < S:
        s += 1
