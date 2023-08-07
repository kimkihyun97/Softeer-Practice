import sys
input = sys.stdin.readline

## golbal val
N = None
scores, ranks = None, None

if __name__ == "__main__" :
    N = int(input())
    ranks = [[0]*(N) for _ in range(4)]
    scores = [0]*N
    for i in range(3) :
        temp = sorted([(s,i) for i, s in enumerate(list(map(int, input().split())))], key = lambda x : -x[0])
        ranks[i][temp[0][1]] = 1
        scores[temp[0][1]] += temp[0][0]
        for j in range(1, N) :
            if temp[j-1][0] == temp[j][0] :
                ranks[i][temp[j][1]] = ranks[i][temp[j-1][1]]
            else :
                ranks[i][temp[j][1]] = j + 1
            scores[temp[j][1]] += temp[j][0]

    scores = sorted([(s,i) for i, s in enumerate(scores)], key = lambda x : -x[0])

    ranks[3][scores[0][1]] = 1
    for i in range(1, len(scores)) :
        if scores[i-1][0] == scores[i][0] : ranks[3][scores[i][1]] = ranks[3][scores[i-1][1]]
        else : ranks[3][scores[i][1]] = i +1

    for r in ranks :
        print(*r) 
