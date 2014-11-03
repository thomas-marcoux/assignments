import random

def     parent(network, event):
    p = []
    for i in network:
        for j in network[i]:
            if (event == j):
                p += i
    return p

def     randomSample(answers, network, event):
    n = random.randrange(len(answers)) + 1
    return answers[n][event]

def     prior_sampling(answers, network, jointDis):
    x = {}
    for i in jointDis:
        x[i] = randomSample(answers, network, i)
    return x

