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

struct Point {
	Point () {
	}
	Point (int _x, int _y, int _id) {
		x = _x;
		y = _y;
		id = _id;
	}
	int x,y,id;
};

bool acompare(const Point& lhs, const Point& rhs) { 
	if (lhs.y<rhs.y) return true;
	else if (lhs.y==rhs.y && lhs.x<rhs.x) return true;
	return false;
}

class NoRightTurnDiv2 {
public:
	vector <int> findPath(vector <int>, vector <int>);
};

vector <int> NoRightTurnDiv2::findPath(vector <int> x, vector <int> y) {
	const double PI = atan2 (0,-2);
	int second_point, visited[55], rem, prevx, prevy;
	double min_angle=10, prev_angle=-1, angle=-1;
	
	vector<Point> v (x.size());
	vector<int> ret;

	for (int i=0;i<x.size();i++) v[i] = Point(x[i], y[i], i);
	sort(v.begin(), v.end(), acompare);
	ret.push_back (v[0].id);
	
	
	
	for (int j=0;j<x.size();j++) {
		if (j==v[0].id) continue;
		double angle = atan2 (y[j]-v[0].y, x[j]-v[0].x);
		if (angle<0) angle += 2*PI;
		if (angle<min_angle) {
			min_angle = angle;
			second_point = j;
		}
	}
	
	ret.push_back (second_point);
	
	for (int i=0;i<55;i++) visited[i] = 0;
	visited[v[0].id] = visited[second_point] = 1;
	rem = x.size()-2;
	
	prev_angle = min_angle;
	prevx=x[ret[1]]; prevy=y[ret[1]];
	while (rem>0) {
		rem--;
		double min_diff = 10, new_angle=-1;
		int next_point;
		
		for (int j=0;j<x.size();j++) {
			if (visited[j]) continue;	
			new_angle = atan2 (y[j]-prevy, x[j]-prevx);
			if (new_angle<0) new_angle += 2*PI; //convert to pops
			double nn = (new_angle<prev_angle)? 2*PI+new_angle-prev_angle :new_angle-prev_angle;
			
			if (nn>PI) continue; //Clockwise
			if (nn<min_diff) {
				min_diff = nn;
				next_point = j;
				angle = new_angle;
			}
		}
		prev_angle = angle;
		visited[next_point] = 1;
		ret.push_back (next_point);
		prevx = x[next_point];
		prevy = y[next_point];
	}
	return ret;
}


//Powered by [KawigiEdit] 2.0!