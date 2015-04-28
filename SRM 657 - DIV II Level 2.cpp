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

class ProblemSetsEasy {
public:
	int maxSets(int, int, int, int, int);
};

int ProblemSetsEasy::maxSets(int E, int EM, int M, int MH, int H) {
	int easy = E;
	int medium = M;
	int hard = H;

	while (EM>0 && MH>0) {
		if (easy<medium) {
			easy++;
			EM--;
		}
		else if (hard<medium) {
			hard++;
			MH--;
		}
		else if (medium<=easy || medium<=hard) {
			medium++;
			if (EM<MH) MH--;
			else if (EM>MH) EM--;
			else if (EM==MH) {
				if (easy<hard) MH--;
				else EM--;
			}
		}
	}
	while (MH>0) {
		MH--;
		if (medium<hard) medium++;
		else hard++;
	}
	
	while (EM>0) {
		EM--;
		if (easy<medium) easy++;
		else medium++;
	}
	
	return min (easy, min (medium,hard));
}


//Powered by [KawigiEdit] 2.0!