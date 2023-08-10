#define INF 1000000001
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

//global val
int N, M;
vector<vector<pair<int, int>>> map;
vector<int> lv_board;
int ans;

bool FindPrime(int cur)
{
	if(cur == 1 || cur == 2 || cur == 3) return true;
	for(int i = 2; i < sqrt(cur) + 1; i++)
	{
        if(cur % i == 0) return false;
	}
	return true;
}

void Dijkstra()
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int stage = q.front();
		int cur_lv = lv_board[stage];
		q.pop();
		if(stage == N) continue;

		for(auto info : map[stage])
		{
            int nxt_stage = info.first;
			int nxt_lv = info.second;
			int temp_lv;
			if(lv_board[stage] >= lv_board[nxt_stage]) continue;
			if(cur_lv < nxt_lv) temp_lv = nxt_lv;
			else temp_lv = cur_lv;
			if(temp_lv < lv_board[nxt_stage])
			{
				lv_board[nxt_stage] = temp_lv;
				q.push(nxt_stage);
			}
		}
	}
}

int main(int argc, char** argv)
{
    cin >> N >> M;
	map.resize(N+1, vector<pair<int, int>>());
	lv_board.resize(N+1, INF);
	lv_board[0] = 0;
	lv_board[1] = 0;
	for(int i =0; i < M; i++)
	{
		int idx, nxt_idx, lv;
		cin >> idx >> nxt_idx >> lv;
		map[idx].push_back({nxt_idx, lv});
		map[nxt_idx].push_back({idx, lv});
	}
	Dijkstra();
	ans = lv_board[N]+1;
	while(!FindPrime(ans)) ans++;
	cout << ans; 
	return 0;
}
