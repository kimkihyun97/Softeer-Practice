#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
// < ^ > v
pair<int, int> dir[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
vector<string> map;
int can_path, H, W;
pair<int, int> start_hw;
int star_dir;
string command;

string CheckDir(int cur_d, int next_d)
{
	if(cur_d == next_d) return "A";
	else if(cur_d - next_d == 1 || cur_d - next_d == -3) return "LA";
	return "RA";

}

void BFS(int pph, int ppw, int ph, int pw, int sh, int sw, int sd)
{
	vector<vector<bool>> visited(H,vector<bool>(W,false));
	visited[pph][ppw] = true;
	visited[ph][pw] = true;
	queue<vector<int>> q;
	queue<string> co;
	q.push({sh, sw, sd, 3});
	co.push("A");
	while(!q.empty())
	{
	    int h, w, d, p;
		string cur_co;
		h = q.front()[0];
		w = q.front()[1];
		d = q.front()[2];
		p = q.front()[3];
		cur_co = co.front();
		q.pop();
		co.pop();
		if(p == can_path)
		{
			if(command.length() < cur_co.length() || command == "")
			{
				start_hw.first = pph;
				start_hw.second = ppw;
				star_dir = sd;
				command = cur_co;
			}
		}	
		for(int i =0; i < 4; i++)
		{
			int nh, nw, nnh, nnw;
			nh = h + dir[i].first;
			nw = w + dir[i].second;
			nnh = nh + dir[i].first;
			nnw = nw + dir[i].second;
			if(nh > -1 && nh < H && nw > -1 && nw < W && nnh > -1 && nnh < H && nnw > -1 && nnw < W)
			{
				if(map[nh][nw] == '#' && visited[nh][nw] == false && map[nnh][nnw] == '#' && visited[nnh][nnw] == false)
				{
					string next_co;
					next_co = CheckDir(d,i);
					visited[nh][nw] = true;
					visited[nnh][nnw] = true;
					q.push({nnh, nnw, i, p+2});
					co.push(cur_co + next_co);
				}
			}
		}
	}

}

int main(int argc, char** argv)
{
	cin >> H >> W;
	for(int i=0; i < H; ++i)
	{
        string temp;
		cin >> temp;
		for(int j = 0;j < W; j++)
		{
			if(temp[j] == '#') can_path++;
		}
		map.push_back(temp);
	}

	for(int h =0; h < H; h++)
	{
		for(int w = 0; w < W; w++)
		{
			if(map[h][w] == '#')
			{
				int cnt = 0;
				int nh, nw, nnh, nnw; // for testing
				vector<vector<int>> start_set;
				for(int k =0; k < 4; k++)
				{
					nh = h + dir[k].first;
					nw = w + dir[k].second;
					nnh = nh + dir[k].first;
					nnw = nw + dir[k].second;
					if(nh > -1 && nh < H && nw > -1 && nw < W && nnh > -1 && nnh < H && nnw > -1 && nnw < W)
					{
						if(map[nh][nw] == '#' && map[nnh][nnw] == '#')
						{
							cnt++;
							start_set.push_back({nh, nw, nnh, nnw, k});
						}
					}
				}
				if(cnt == 1)
				{
					BFS(h, w, start_set[0][0], start_set[0][1], start_set[0][2], start_set[0][3], start_set[0][4]);
				}
			}
		}
	}
	cout << start_hw.first + 1 << " " << start_hw.second + 1 << endl;
	switch(star_dir)
	{
		case 0 :
		    cout << '<' << endl;
			break;
		case 1 :
		    cout << '^' << endl;
			break;
		case 2 :
		    cout << '>' << endl;
			break;
		case 3 :
		    cout << 'v' << endl;
			break;
	}
	cout << command;
	return 0;
}
