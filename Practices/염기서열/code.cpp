#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int N, M;
vector<string> DNAs;
vector<string> SUPER_DNA;
int dp[(1<<15)];


void GenSuperDna(int idx)
{
    string gen = "";
    int temp_idx = idx;
    int loc = 0;
    while(temp_idx % 2 == 0)
    {
        loc++;
        temp_idx /= 2;
    }
    int bit_idx = idx - pow(2, loc);
    //cout << idx << " " << bit_idx << endl;
    // gen superDna
    if(SUPER_DNA[bit_idx] != "")
    {
        for(int i = 0; i < M; i++)
        {
            char c1 = DNAs[loc][i];
            char c2 = SUPER_DNA[bit_idx][i];
            if(c1 == '.' && c2 != '.')
            {
                gen += c2;
            }
            else if(c2 == '.' && c1 != '.')
            {
                gen += c1;
            }
            else if(c1 != c2)
            {
                gen = "";
                break;
            }
            else
            {
                gen += c1;
            }
        }
    }
    SUPER_DNA[idx] = gen;
    //cout << idx << " " << gen << endl;
    // Cal min DNA
    if(gen != "")
    {
        dp[idx] = 1;
    }
    else
    {
        dp[idx] = 16;
        for(int i = (1 << loc); i < idx; i++)
        {
            dp[idx] = min(dp[i] + dp[idx-i], dp[idx]);
        }
    }
}

int main()
{
    cin >> N >> M;
    DNAs.resize(N+1,"");
    SUPER_DNA.resize((1<<N), "");
    for(int i =0; i < M; i++) SUPER_DNA[0] += '.';
    for(int i =0; i < N; i++)
    {
        cin >> DNAs[i];
    }
    
    for(int i =1; i < (1<<N); i++)
    {
       GenSuperDna(i);   
    }
    cout << dp[(1<<N) - 1];
}
