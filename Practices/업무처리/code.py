from collections import deque
import sys
input = sys.stdin.readline

## global val
H, K, R = None, None, None
min_idx, max_idx = None, None
tree = []
ans = 0

def TopDown(day) :
    global ans
    is_odd = True
    if day %2 == 0 : is_odd = False
    
    # spuervisor
    if is_odd and tree[0][0] :
        ans += tree[0][0].popleft()
    elif not is_odd and tree[0][1] :
        ans += tree[0][1].popleft()
    
    # middle
    for i in range(1, min_idx) :
        if is_odd and tree[i][0] :
            if i%2 != 0 :
                tree[(i-1)//2][0].append(tree[i][0].popleft())
            else :
                tree[(i-1)//2][1].append(tree[i][0].popleft())
        elif not is_odd and tree[i][1] :
            if i%2 != 0 :
                tree[(i-1)//2][0].append(tree[i][1].popleft())
            else :
                tree[(i-1)//2][1].append(tree[i][1].popleft())
    
    # staff
    for i in range(min_idx, max_idx+1) :
        if tree[i] :
            if i%2 != 0 :
                tree[(i-1)//2][0].append(tree[i].popleft())
            else :
                tree[(i-1)//2][1].append(tree[i].popleft())


if __name__ == "__main__" :
    H, K, R = map(int, input().split())
    min_idx, max_idx = 2**H - 1, 2**(H+1)-2
    tree = [[deque([]), deque([])] for _ in range(min_idx)] + [deque([]) for _ in range(min_idx, max_idx+1)]

    for i in range(min_idx, max_idx+1) :
        tree[i].extend(list(map(int, input().split())))

    for i in range(1, R+1) :
        TopDown(i)
        # print(f'day {i}')
        # print(tree)

    print(ans)
