import random

class   Parameters():
    def randomize(self):
        self.velX = round(random.random(), 4)*10*(random.sample([-1, 1], 1)).pop()
        self.velY = round(random.random(), 4)*10*(random.sample([-1, 1], 1)).pop()
        self.friction = round(random.random(), 4) % 0.01
