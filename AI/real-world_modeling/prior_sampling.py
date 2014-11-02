import random

def     parent(network, event):
    p = []
    for i in network:
        for j in network[i]:
            if (event == j):
                p += i
    return p

def     sample(answer, event, parent):
    print(answer[event])
    print(answer[parent])

def     prior_sampling(answers, network):
    x = {}
    print(parent(network, 'D'))
    for i in answers:
        n = random.randrange(len(answers)) + 1
        x[i] = answers[n]
        #sample(answers[n], 'D', 'C')
    return x

