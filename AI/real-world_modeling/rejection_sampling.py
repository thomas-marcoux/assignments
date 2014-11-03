import prior_sampling

def     rejection_sampling(answers, network, jointDis, event, value):
    N = {}
    Nconsistent = 0
    for j in answers:
        x = prior_sampling.prior_sampling(answers, network, jointDis)
        if (x[event] == value):
            #N[x] += 1
            Nconsistent += 1
    return Nconsistent
