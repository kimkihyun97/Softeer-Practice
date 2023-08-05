import sys
import math
input = sys.stdin.readline
max_upgrade = 0
min_upgrade = 0
performamces_num = dict()
if __name__ == "__main__" :
    N, B = map(int, input().split())
    performamces = list(map(int, input().split()))
    performamces.sort(key = lambda x : x)
    for performamce in performamces :
        if(performamce not in performamces_num.keys()) :
            performamces_num[performamce] = 1
        else :
            performamces_num[performamce] += 1
    
    min_upgrade = performamces[0]
    max_upgrade = performamces[-1] + math.floor(math.sqrt(B))

    while (max_upgrade - min_upgrade > 1) :
        upgrade = (max_upgrade + min_upgrade) // 2
        cost = 0
        for k, v in performamces_num.items() :
            if k < upgrade :
                cost += ((upgrade - k)**2)*v
                if(cost > B) :
                    max_upgrade = upgrade
                    break
        else:
            min_upgrade = upgrade

print(min_upgrade)
