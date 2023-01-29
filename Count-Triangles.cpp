#include<iostream>
#include<vector>
using namespace std;

void solve(){
    vector<vector<int>> digraph = {{0, 0, 1, 0},
                                     {1, 0, 0, 1},
                                     {0, 1, 0, 0},
                                     {0, 0, 1, 0}};
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        // cout<<i<<" ";
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (digraph[i][j] && digraph[j][k] && digraph[k][i])
                {
                    count++;
                    // cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    //When graph is directed
    cout<< count / 3  << endl;
    //When graph is undirected
    // cout << count / 6 << endl;
}

int main(){
    solve();
    return 0;
}