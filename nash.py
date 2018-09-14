import numpy as np

full_this = 0
full_other = 0

n = 100000
eps = 1#0.99

for count in range(n):
    other = np.random.randint(2)
    this = 1*(np.random.random(1) < eps)

    this_gain = 0
    other_gain = 0

    if other and this:
        this_gain = -5
        other_gain = -5
    elif this and not other:
        this_gain = 0
        other_gain = -10
    elif other and not this:
        this_gain = -10
        other_gain = 0
    else:
        this_gain = -1
        other_gain = -1

    full_this += this_gain
    full_other += other_gain

print("Avg total gain: ",full_this/n)
print("Avg total loss: ",full_other/n)

print("Sum: ",(full_this+full_other)/n)
