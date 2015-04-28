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

class RandomPancakeStackDiv2 {
public:
	double expectedDeliciousness(vector <int>);
};

int factorial (int n) {
	double ret = 1;
	for (int i=2;i<=n;i++) ret*=i;
	return ret;
}

double RandomPancakeStackDiv2::expectedDeliciousness(vector <int> d) {
	//BRUTE FORCE
	int sz = d.size();
	
	vector<int> perms(sz);
	for (int i=0;i<sz;i++) perms[i]=i;
	long long ret = 0;
	do {
		//Compute the expected value
		ret += d[perms[0]];
		for (int i=1;i<sz;i++) {
			if (perms[i]>perms[i-1]) break;
			else	ret += d[perms[i]];
		}
	} while (next_permutation (perms.begin(), perms.end()));
	return ret/(double)factorial(sz);
}


//Powered by [KawigiEdit] 2.0!