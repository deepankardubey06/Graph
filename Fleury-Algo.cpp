#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;

vector<vector<int>> graph;
vector<int> deg(n);

void addEdge(int u, int v){
	graph[u].push_back(v);
	graph[v].push_back(u);
	deg[u]++;
	deg[v]++;
}

int findOddDeg(){
	int u = 0;
	for(int i=0; i<deg.size(); i++){
		if(deg[i] % 2 == 1){
			u = i;
			break;
		}
	}
	return u;
}

void dfs(int start, vector<int> &visi, int &count){
	visi[start] = 1;
	count++;

	for(auto i: graph[start]){
		if(!visi[i]){
			dfs(i, visi, count);
		}
	}
}

void remEdge(int u, int v){
	auto itr1 = find(graph[u].begin(), graph[u].end(), v);
	*itr1 = -1;
	auto itr2 = find(graph[v].begin(), graph[v].end(), u);
	*itr2 = -1;
}

bool validEdge(int u, int v){

	int count = 0;
	for(auto i: graph[u]){
		if(i != -1){
			count++;
		}
	}
	if(count == 1){
		return false;
	}

	int count1 = 0;
	vector<int> visi(graph.size());
	dfs(u, visi, count1);

	remEdge(u, v);

	int count2 = 0;
	vector<int> visi(graph.size());
	dfs(u, visi, count2);

	addEdge(u, v);

	if(count1 > count2){
		return false
	}
	return true;
}

void printEulerPath(int u){

	for(auto i: graph[u]){

		int curr_node = u;

		if(i != -1 && validEdge(u, i)){
			cout<< curr_node << "-" << i << endl;
			remEdge(u, v);
			printEulerPath(i);
		}
	}
}

int main{
	// int n;
	// cin>>n;
	n = 4
	// vector<int> deg(n);
	vector<vector<int>>(n, vector<int>()) g2;

	addEdge(2, 0);
	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(2, 3);

	int u = findOddDeg();
	printEulerPath(u);

	return 0;
}