#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class OneEntrance {
	int blocked[12],visited[12];
	vector<vector<int> > adj_mat;
	int ss;
public:
	int count(vector <int>, vector <int>, int);
	bool check (vector<int>& perm);
	bool put (int,int);
};

bool OneEntrance :: put (int n, int node) {
	if (visited[node]) return false;
	visited[node] = 1;

	if (n==node) {
		blocked[n] = 1;
		return true;
	}
	if (blocked[node]) return false;
	for (int i=0; i<adj_mat[node].size();i++) {
		if (put (n, adj_mat[node][i])) return true;
	}
	return false;
}

bool OneEntrance:: check (vector<int>& perm) {
	memset (blocked,0,sizeof(blocked));

	for (int i=0;i<perm.size();i++) {
		memset (visited,0,sizeof(visited));
		if (!put(perm[i], ss)) return false;
	}
	
	return true;
}

int OneEntrance::count(vector <int> a, vector <int> b, int s) {
	//Construct the adjacency matrix
	adj_mat.resize (a.size()+1);
	ss = s;
	for (int i=0;i<a.size();i++) {
		adj_mat [a[i]].push_back (b[i]);
		adj_mat [b[i]].push_back (a[i]);
	}
	
	vector<int> perm;
	int ret=0;
	for (int i=0;i<a.size()+1;i++) perm.push_back(i);
	do {
		if (check (perm)) ret++;
	} while (next_permutation(perm.begin(), perm.end()));
	return ret;
}