#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// var
int N, K;
int ans = 4000001;
struct Point
{
	int x, y;
};
vector<vector<Point>> colors;

void DFS(Point p1, Point p2, int c_type, int area)
{
	if(c_type == K + 1)
	{
		if(area < ans) ans = area;
		return;
	}

	for(auto p : colors[c_type])
	{
		Point tmp1(p1), tmp2(p2);
		// for x
		if(p.x < p1.x) tmp1.x = p.x;
		else if(p.x > p2.x) tmp2.x = p.x;
        // for y
		if(p.y < p1.y) tmp1.y = p.y;
		else if(p.y > p2.y) tmp2.y = p.y;
	    
		// update   
		int temp_area = abs((tmp2.x - tmp1.x) *(tmp2.y - tmp1.y));
		if(temp_area < ans) DFS(tmp1, tmp2, c_type+1, temp_area);
	} 

}

int main()
{
    cin >> N >> K;
	colors.resize(K+1);
	for(int i =0; i < N; i++)
	{
		Point temp;
		int k;
		cin >> temp.x >> temp.y >> k;
		colors[k].push_back(temp);
	}

	for(auto c : colors[1])
	{
		DFS(c, c, 2, 0);
	}
    cout << ans;
    return 0;
}
