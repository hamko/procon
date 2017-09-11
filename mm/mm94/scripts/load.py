import numpy as np
import re
def load(filename, keyword):
    ret = np.array([]);
    first = 1
    size = -1;
    for line in  open(filename, 'r'):
        if '#'+keyword+'\n' not in line:
            continue;
        line = np.array(list(map(float,re.sub(r'#.*$', '', line).strip().split())))
        if size >= 0 and size != len(line):
            print("size not match : file =", filename, ", keyword =", keyword);
            exit(1);
        if first:
            first = 0;
            size = len(line)
            ret = np.array([line]).reshape(size, 1);
        else:
            ret = np.append(ret, line.reshape(size, 1), axis=1);
    return ret


