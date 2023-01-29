//Satisfiability of Equality Equations
#include<iostream>
#include<vector>

using namespace std;

int findPar(int node, vector<int> &par){
    if(node == par[node]){
        return node;
    }
    return par[node] = findPar(par[node], par);
}

void unionn(int u, int v, vector<int> &par, vector<int> &rank)
{
    u = findPar(u, par);
    v = findPar(v, par);
    if(rank[u] == rank[v]){
        par[v] = u;
        rank[u]++;
    }
    else if(rank[u] > rank[v]){
        par[v] = u;
    }
    else{
        par[u] = v;
    }
}

bool equationsPossible(vector<string> &equations)
{
    vector<int> par(26);
    vector<int> rank(26);

    for(int i=0; i<26; i++){
        par[i] = i;
    }

    for(int i=0; i<equations.size(); i++){
        string f_part = equations[i].substr(0,1);
        string s_part = equations[i].substr(3,1);
        string mid = equations[i].substr(1,2);
        if(mid == "=="){
            int val1 = f_part[0] - 'a';
            int val2 = s_part[0] - 'a';
            unionn(val1, val2, par, rank);
        }
    }

    for (int i = 0; i < equations.size(); i++)
    {
        string f_part = equations[i].substr(0, 1);
        string s_part = equations[i].substr(3, 1);
        string mid = equations[i].substr(1, 2);
        if (mid == "!=")
        {
            int val1 = f_part[0] - 'a';
            int val2 = s_part[0] - 'a';
            if(findPar(val1, par) == findPar(val2, par)){
                return false;
            }
        }
    }
    return true;
}

int main(){

    // string eq = "z==b";
    // string first = eq.substr(0,1);
    // cout<<first[0] - 'a'<<endl;
    vector<string> equations = { "a==b", "b!=a" };
    equations = {"b==a", "a==b"};
    cout<< equationsPossible(equations);
    return 0;
}