#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
vector<pair<double, double> > vec;

int CCW(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
	double op = A.first * B.second + B.first * C.second + C.first * A.second;
	op -= (A.second * B.first + B.second * C.first + C.second * A.first);
	if (op < 0) {
		return -1;
	}
	else if (op == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	cout << CCW(vec[0], vec[1], vec[2]) << "\n";

	getchar();
	getchar();
	return 0;
}