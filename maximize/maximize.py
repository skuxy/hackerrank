# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys

from itertools import product


with sys.stdin as f:
    K, M = [int(x) for x in f.readline().strip().split()]
    combinations = []

    for _ in range(K):
        arr = [int(x) for x in f.readline().strip().split()[1:]]
        if not combinations:
            combinations += arr
            continue

        combinations = list(product(combinations, arr))

        try:
            combinations = [(*x[0], x[1]) for x in combinations]
        except TypeError:
            continue

    max_result = 0

    for c in combinations:
        try:
            r = sum([x*x for x in c]) % M
        except TypeError:
            r = c*c % M

        if r > max_result:
            max_result = r

    print(max_result)
