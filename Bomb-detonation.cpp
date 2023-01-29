#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void display(vector<vector<int>> &ans){
    for(int i=0; i<ans.size(); i++){
        cout<<i<<"->";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(vector<vector<int>> &detonation, int start, vector<int> &visi){
    visi[start] = 1;
    for(int i: detonation[start]){
        if(visi[i] == 0){
            dfs(detonation,i, visi);
        }
    }
}

void maximumDetonation(vector<vector<int>> &bombs)
{
    vector<vector<int>> detonation(bombs.size(),vector<int>());
    long double x1, x2, y1, y2, d, r1;

    for(int i=0; i<bombs.size(); i++){
        x1 = bombs[i][0];
        y1 = bombs[i][1];
        r1 = bombs[i][2];
        for(int j=0; j<bombs.size(); j++){
            if(i != j){
                x2 = bombs[j][0];
                y2 = bombs[j][1];
                d = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
                if(d <= r1){
                    detonation[i].push_back(j);
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<bombs.size(); i++){
        vector<int> visi(bombs.size(),0);
        dfs(detonation,i,visi);
        int count = 0;
        for(int j=0; j<visi.size(); j++){
            if(visi[j] == 1){
                count++;
            }
        }
        ans = max(ans,count);
    }
    cout<<ans;
}

int main(){
    vector<vector<int>> bombs = { { 1, 2, 3 }, { 2, 3, 1 }, { 3, 4, 2 }, { 4, 5, 3 }, { 5, 6, 4 } };
    maximumDetonation(bombs);
    return 0;
}