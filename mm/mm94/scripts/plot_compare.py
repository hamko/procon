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

    if i == 0: 
        d1 = scores;
    elif i == 1:
        d2 = scores;

    i += 1

print(x)
print(y)
print(err)

xlim(xmin=-1, xmax=len(sys.argv)-1)
xticks(np.arange(len(sys.argv)-1),sys.argv[1:])
errorbar(x,y,yerr=err,fmt='ro',ecolor='g')

from scipy import stats
p = None
if i >= 2:
    t, p = stats.ttest_ind(d1, d2, equal_var=False);

if p == None:
    title("Comparison of scores with std error bars")
else:
    title("Comparison of scores with std error bars (p="+str(p)+")")

xlabel("Case")
ylabel("Points")


show()

