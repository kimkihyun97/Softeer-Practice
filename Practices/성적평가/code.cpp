#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void RankProcess(int N, vector<pair<int, int> > &scores)
{
	int pivot = 3001;
	int cur_rank(0), rank_flag(0);
	vector<int> rank(N,0);
	sort(scores.rbegin(), scores.rend());
	for(int i =0; i < N; i++)
	{
		if(scores[i].first < pivot)
		{
			rank_flag++;
			cur_rank = rank_flag;
			rank[scores[i].second] = cur_rank;
            pivot = scores[i].first;
		}
		else if(scores[i].first == pivot)
		{
			rank[scores[i].second] = cur_rank;
			rank_flag++;
		}
	}
	for(int i =0; i < N; i++)
	{
		cout << rank[i] << " ";
	}
	cout <<"\n";
}

int main(int argc, char** argv)
{
    int N;
	cin >> N;
    vector<pair<int,int> > total_scores(N, make_pair(0,0));
    for(int i = 0; i < 3; i++)
	{
		vector<pair<int,int> > scores(N, make_pair(0,0));
		for(int j = 0;j < N; j++)
		{
		   cin >> scores[j].first;
		   scores[j].second = j;
		   total_scores[j].first += scores[j].first;
		   total_scores[j].second = j;
		}
		RankProcess(N, scores);
	}
	RankProcess(N, total_scores);
	return 0;
}
