import network
import random

def     sample(answer, event, parent):
    print(answer[event])
    print(answer[parent])

def     prior_sampling(answers):
    x = {}
    for i in answers:
        n = random.randrange(len(answers)) + 1
        x[i] = answers[n]
        sample(answers[n], 'D', 'C')
    return x

