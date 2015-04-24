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

class ThePermutationGameDiv2 {
public:
	long long findMin(int);
};

long long gcd (long long a, long long b) {
	if (b==0) return a;
	return gcd (b, a%b);
}

long long lcm (long long a, long long b) {
	return (a*b)/gcd(a,b);
}


long long ThePermutationGameDiv2::findMin(int N) {
	long long ret = 1;
	for (int i=1;i<=N;i++) {
		ret = lcm (ret,i);
	}
	return ret;
}


//Powered by [KawigiEdit] 2.0!