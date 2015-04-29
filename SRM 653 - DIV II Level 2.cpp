/*
	Author: Youssef ElGhareeb
*/

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

long long combs [2005][2005];
const long long MOD = 1000000007;

class RockPaperScissorsMagicEasy {
public:
	int count(vector <int>, int);
};

int RockPaperScissorsMagicEasy::count(vector <int> card, int score) {
	int sz = card.size();
	int diff = sz-score; //number of losses or ties
	memset (combs,0,sizeof(combs));
	
	combs[0][0] = 1;
	for (int i=1;i<2005;i++) {
		combs[i][0] = 1;
		for (int j=1;j<2005;j++) {
			combs[i][j] = (combs[i-1][j] + combs[i-1][j-1])%MOD;
		}
	}
	long long ret = combs[sz][diff];
	for (int i=0;i<diff;i++) ret = (ret*2)%MOD;
	return ret;
}

//Powered by [KawigiEdit] 2.0!