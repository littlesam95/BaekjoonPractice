#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <algorithm>
#define MAX 200001

using namespace std;
vector<pair<pair<long long, long long>, pair<long long, long long> > > vec;
pair<long long, long long> answer;

// 선분의 교점 구하기
void find_intersect(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
	double P_X = (A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first);
	double P_Y = (A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first);
	double P = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);
	if (P == 0) {
		if ((B == C) && (A <= C)) {
			cout << B.first << " " << B.second << "\n";
		}
		else if ((A == D) && (C <= A)) {
			cout << A.first << " " << A.second << "\n";
		}
	}
	else {
		double X = P_X / P;
		double Y = P_Y / P;
		cout << fixed;
		cout.precision(9);
		cout << X << " " << Y << "\n";
	}
}

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C) {
	long long op = A.first * B.second + B.first * C.second + C.first * A.second;
	op -= (A.second * B.first + B.second * C.first + C.second * A.first);
	if (op > 0) {
		return 1;
	}
	else if (op == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

void intersect(pair<pair<long long, long long>, pair<long long, long long> > A, pair<pair<long long, long long>, pair<long long, long long> > B) {
	pair<long long, long long> a = A.first;
	pair<long long, long long> b = A.second;
	pair<long long, long long> c = B.first;
	pair<long long, long long> d = B.second;
	int ab = CCW(a, b, c) * CCW(a, b, d);
	int cd = CCW(c, d, a) * CCW(c, d, b);
	if ((ab == 0) && (cd == 0)) {
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		if ((a <= d) && (b >= c)) {
			cout << 1 << "\n";
			find_intersect(a, b, c, d);
		}
		else {
			cout << 0 << "\n";
		}
	}
	else {
		if ((ab <= 0) && (cd <= 0)) {
			cout << 1 << "\n";
			find_intersect(vec[0].first, vec[0].second, vec[1].first, vec[1].second);
		}
		else {
			cout << 0 << "\n";
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 2; i++) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vec.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}
	intersect(vec[0], vec[1]);

	getchar();
	getchar();
	return 0;
}