from collections import deque
import sys
input = sys.stdin.readline

## global val
N = 0
parking = None
dp = None
ans = 0

if __name__ == "__main__" :
    N = int(input())
    stack = list(map(int, input().split()))
    dp = [[0]*(N+1) for _ in range(N+1)]
    ## ai < aj && ai > ak (i < j < k)
    for i in range(N-1, -1, -1) :
        for j in range(1, N) :
            if stack[i] < j :
                dp[j][i] = dp[j][i+1] +1
            else :
                dp[j][i] = dp[j][i+1]

    for i in range(N) :
        for j in range(i + 1, N) :
            if stack[i] < stack[j] :
                ans += dp[stack[i]][j]

    print(ans)
