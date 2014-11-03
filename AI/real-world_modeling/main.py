import rejection_sampling
import answers
import network

r = rejection_sampling.rejection_sampling(answers.answs, network.net,
                                      network.jointDis, 'D', 'yes')
print(r)
