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

using namespace std;

class FoldingPaper2 {
public:
	int solve(int, int, int);
	int eval (int,int,int,int);
};

int FoldingPaper2 :: eval (int begw, int begh, int endw, int endh) {
	int ret = 0;
	while (begw>endw) {
		if (begw%2) begw++;
		begw/=2;
		ret++;
	}
	while (begh>endh) {
		if (begh%2) begh++;
		begh/=2;
		ret++;
	}
	return ret;
}

int FoldingPaper2::solve(int W, int H, int A) {
	if (W>H) swap (W,H);
	
	vector<pair<int,int> > v;
	
	for (int i=1; i<=sqrt(A);i++) {
		if (A%i==0) v.push_back (make_pair(i,A/i));
	}
	
	int ret = -1;
	for (int i=0;i<v.size();i++) {
		pair<int,int> p = v[i];
		if (p.first<=W && p.second<=H) {
			if (ret==-1) ret = eval (W,H,p.first,p.second);
			else ret = min (ret, eval (W,H,p.first,p.second));
		}
		if (p.first<=H && p.second<=W) {
			if (ret==-1) ret = eval (W,H,p.second,p.first);
			else ret = min (ret, eval (W,H,p.second,p.first));
		}
	}
	return ret;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!