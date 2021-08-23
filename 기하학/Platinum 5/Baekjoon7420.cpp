#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535

using namespace std;
struct Point {
	long long x, y, p, q;
	Point() {}
	Point(long long x_, long long y_, long long p_ = 0, long long q_ = 0) : x(x_), y(y_), p(p_), q(q_) {}
	bool operator < (const Point &A) {
		if (p * A.q != q * A.p) {
			return (p * A.q > q * A.p);
		}
		if (y != A.y) {
			return (y < A.y);
		}
		return (x < A.x);
	}
};

int N, L;
vector<Point> vec;
vector<int> convex_hull;
double answer = 0;

long long CCW(Point &A, Point &B, Point &C) {
	long long op = (A.x * B.y) + (B.x * C.y) + (C.x * A.y);
	op -= (A.y * B.x + B.y * C.x + C.y * A.x);
	return op;
}

double len_calc(long long A, long long B, long long C, long long D) {
	double res = (sqrt((A - C) * (A - C) + (B - D) * (B - D)));
	return res;
}

long long DOT(Point A, Point B) {
	return (A.x * B.x + A.y * B.y);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		Point tmp;
		tmp.x = x;
		tmp.y = y;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i < N; i++) {
		vec[i].p = vec[i].x - vec[0].x;
		vec[i].q = vec[i].y - vec[0].y;
	}
	sort(++vec.begin(), vec.end());
	stack<int> s;
	s.push(0);
	s.push(1);
	int next_top = 2;
	while (next_top < N) {
		while (s.size() >= 2) {
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();
			if (CCW(vec[first], vec[second], vec[next_top]) > 0) {
				s.push(second);
				break;
			}
		};
		s.push(next_top++);
	};
	while (!s.empty()) {
		int top = s.top();
		s.pop();
		convex_hull.push_back(top);
	};
	for (int i = 0; i < convex_hull.size(); i++) {
		if (i < convex_hull.size() - 2) {
			double dist1 = len_calc(vec[convex_hull[i]].x, vec[convex_hull[i]].y, vec[convex_hull[i + 1]].x, vec[convex_hull[i + 1]].y);
			answer += dist1;
			double dist2 = len_calc(vec[convex_hull[i + 2]].x, vec[convex_hull[i + 2]].y, vec[convex_hull[i + 1]].x, vec[convex_hull[i + 1]].y);
			Point A, B;
			A.x = (vec[convex_hull[i]].x - vec[convex_hull[i + 1]].x);
			A.y = (vec[convex_hull[i]].y - vec[convex_hull[i + 1]].y);
			B.x = (vec[convex_hull[i + 2]].x - vec[convex_hull[i + 1]].x);
			B.y = (vec[convex_hull[i + 2]].y - vec[convex_hull[i + 1]].y);
			long long inner = DOT(A, B);
			double theta = acos((double)inner / dist1 / dist2); // 각도 구하고 호 구할 때
			theta = PI - theta;
			answer += (L * theta);
		}
		else if (i == convex_hull.size() - 2) {
			double dist1 = len_calc(vec[convex_hull[i]].x, vec[convex_hull[i]].y, vec[convex_hull[i + 1]].x, vec[convex_hull[i + 1]].y);
			answer += dist1;
			double dist2 = len_calc(vec[convex_hull[0]].x, vec[convex_hull[0]].y, vec[convex_hull[i + 1]].x, vec[convex_hull[i + 1]].y);
			Point A, B;
			A.x = (vec[convex_hull[i]].x - vec[convex_hull[i + 1]].x);
			A.y = (vec[convex_hull[i]].y - vec[convex_hull[i + 1]].y);
			B.x = (vec[convex_hull[0]].x - vec[convex_hull[i + 1]].x);
			B.y = (vec[convex_hull[0]].y - vec[convex_hull[i + 1]].y);
			long long inner = DOT(A, B);
			double theta = acos((double)inner / dist1 / dist2);
			theta = PI - theta;
			answer += (L * theta);
		}
		else if (i == convex_hull.size() - 1) {
			double dist1 = len_calc(vec[convex_hull[i]].x, vec[convex_hull[i]].y, vec[convex_hull[0]].x, vec[convex_hull[0]].y);
			answer += dist1;
			double dist2 = len_calc(vec[convex_hull[1]].x, vec[convex_hull[1]].y, vec[convex_hull[0]].x, vec[convex_hull[0]].y);
			Point A, B;
			A.x = (vec[convex_hull[i]].x - vec[convex_hull[0]].x);
			A.y = (vec[convex_hull[i]].y - vec[convex_hull[0]].y);
			B.x = (vec[convex_hull[1]].x - vec[convex_hull[0]].x);
			B.y = (vec[convex_hull[1]].y - vec[convex_hull[0]].y);
			long long inner = DOT(A, B);
			double theta = acos((double)inner / dist1 / dist2);
			theta = PI - theta;
			answer += (L * theta);
		}
	}

	cout << round(answer) << "\n";

	getchar();
	getchar();
	return 0;
}