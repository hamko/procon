import numpy as np
from matplotlib.pyplot import *
import matplotlib.cm as cm
import os
import load
import sys

x = []
y = []
err = []

i = 0
colors = 'rbgcmyk'
for run_dir in sys.argv[1:]:
    scores = np.array([])
    for filename in os.listdir(run_dir):
        tmp = load.load(run_dir+'/'+filename, 'final_score')
        scores = np.append(scores, tmp)
    print(scores);
#    plot(scores, 'o'+colors[i%len(colors)], alpha = 0.5, label=os.path.basename(run_dir))

    x += [i];
    y += [np.mean(scores)];
    err += [np.std(scores)];

    i += 1

print(x)
print(y)
print(err)

errorbar(x,y,yerr=err)
#legend()
legend(bbox_to_anchor=(1.05, 1), loc='upper left', borderaxespad=0)
# 右側の余白を調整
subplots_adjust(right=0.7)

title("scores for test cases")
xlabel("Case")
ylabel("Points")
show()
