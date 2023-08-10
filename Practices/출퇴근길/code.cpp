#include<iostream>
#include<vector>

using namespace std;
int n, m, s, t, ans(0);
vector<vector<int>> map, r_map;
vector<int> fromS, fromT, toS, toT;

void DFS(vector<vector<int>>& map, vector<int>& visited, int cur)
{
	if(visited[cur] == 1)
	{
		return;
	}
	else
	{
		visited[cur] = 1;
		for(int neighbor : map[cur])
		{
			DFS(map, visited, neighbor);
		}
	}
}

int main()
{
	cin >> n >> m;
	map.resize(n+1);
	r_map.resize(n+1);
	for(int i =0; i < m; i++)
	{
       int xi, yi;
	   cin >> xi >> yi;
	   map[xi].push_back(yi);
	   r_map[yi].push_back(xi);
	}
	cin >> s >> t;
    
	//DFS
	fromS.resize(n+1,0);
	fromT.resize(n+1,0);
	toS.resize(n+1,0);
	toT.resize(n+1,0);

	fromS[t] = 1;
	fromT[s] = 1;

	DFS(map, fromS, s);
	DFS(map, fromT, t);
	DFS(r_map, toS, s);
	DFS(r_map, toT, t);
    
	for(int i =1; i <= n; i++)
	{
		if(fromS[i] && fromT[i] && toS[i] && toT[i])
		{
			ans++;
		}
	}
	cout << ans - 2;
	return 0;
}
