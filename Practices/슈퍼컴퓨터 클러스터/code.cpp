#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
long long B;
vector<int> com_perform;

bool check(long long mid) {
    long long cost = 0;
    for(int i=0;i<N;i++) {
        if(mid > com_perform[i]) {
            long long diff = mid - com_perform[i];
            cost += diff * diff;
            if (cost > B) return false; // if cost exceeds budget, return immediately
        }
    }
    return cost <= B;
}

int main(int argc, char** argv) {
    cin >> N >> B;
    com_perform.resize(N,0);
    int min_perform = 1e9;
    for(int i = 0; i < N; i++) {
        cin >> com_perform[i];
        min_perform = min(min_perform, com_perform[i]);
    }

    long long low = min_perform, high = min_perform + B; // extend the search range to [min_perform, min_perform + B]
    long long ans = 0;

    while(low <= high) {
        long long mid = (low + high) / 2;
        if(check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
