import sys
import math
import heapq
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

## var
stages = [[] for _ in range(10001)]
cleared = [0 for _ in range(10001)]
INF = 1000000001
lvs = []
n,m = 0,0

def IsPrime(lv) :
    if lv <= 3 :
        return True
    flag = math.ceil(math.sqrt(lv))

    for divi in range(2, flag+1) :
        if lv % divi == 0 :
            return False
    return True

def DIJKSTRA(start):
  q = []
  heapq.heappush(q, (0, start)) 
  lvs[start] = 0

  while q:
    ## update
    cur_lv, cur_s = heapq.heappop(q)                
    
    ## filtered
    if lvs[cur_s] < cur_lv:
        continue
    for next_s, next_lv in stages[cur_s]:     
        temp_lv = max(next_lv, cur_lv)
        if temp_lv < lvs[next_s] :
            lvs[next_s] = temp_lv
            heapq.heappush(q, (temp_lv, next_s))

if __name__ == "__main__" :
    
    n,m = map(int, input().split())
    lvs = [INF for _ in range(n+1)]
    for i in range(m) :
        s1, s2, lv = map(int, input().split())
        ## 양방향
        stages[s1].append((s2,lv))
        stages[s2].append((s1,lv))
    DIJKSTRA(1)
    ## figure out min_lv
    min_lv = lvs[-1] + 1
    
    if min_lv % 2 == 0 and min_lv > 2 :
        min_lv += 1
    step = 2

    while True :
        if IsPrime(min_lv) :
            print(min_lv)
            break
        min_lv += step
