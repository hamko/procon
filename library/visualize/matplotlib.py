import numpy as np
import matplotlib.pyplot as plt
import os

omega = 0.9
v = 0.1
T = 15
gx = 1
gy = 0

x, y= 1.0, 0.0
for t in range(T+1):
    print(t)
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1, aspect='equal')
    ax.set_title('t = ' + str(t))
    ax.scatter([x], [y]);
    ax.scatter([gx], [gy], s = 100, marker='*');
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_xlim([-0.5, 1.5])
    ax.set_ylim([-0.75, 0.75])
    ax.grid(which='major',color='gray',linestyle='dashed')
    filename = "img/" + ('%04d' % t) + ".png"
    plt.savefig(filename)
    plt.close()

    if t == T: 
        break

    ux = 0
    uy = 0
    ux, uy = map(float, input().split());
    x_next = x - y * omega + x * v + ux
    y_next = y + x * omega + y * v + uy
    x = x_next
    y = y_next
    print(x, y)

