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

using namespace std;

class ABC {
public:
	string createString(int, int);
};

string ABC::createString(int N, int K) {
	int besta=-1, bestb, bestc;
	for (int a=0;a<N;a++) {
		for (int b=0; b<N-a;b++) {
			int c = N-a-b;
			if (a*(b+c) + b*c >= K) {
				besta = a;
				bestb = b;
				bestc = c;
				break;
			}
		}
	}
	if (besta == -1) return "";
	
	string ret = "";
	for (int i=0;i<besta;i++) ret += "A";
	for (int i=0;i<bestb;i++) ret += "B";
	for (int i=0;i<bestc;i++) ret += "C";
	
	int rem = besta*(bestb+bestc) + bestb*bestc - K;
	while (rem--) {
		for (int i=0;i<N-1;i++) {
			if (ret[i]<ret[i+1]) {
				swap (ret[i], ret[i+1]);
				break;
			}
		}
	}
	return ret;
}


//Powered by [KawigiEdit] 2.0!