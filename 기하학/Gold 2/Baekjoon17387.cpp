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

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C) { // CCW는 삼각형의 면적을 구하는 공식과 벡터를 이용하여 구한다.
	long long op = A.first * B.second + B.first * C.second + C.first * A.second;
	op -= (A.second * B.first + B.second * C.first + C.second * A.first);
	// 면적이 0보다 크면 반시계방향, 0이면 세 점이 평행한 것이며 0보다 작으면 시계 방향
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

int intersect(pair<pair<long long, long long>, pair<long long, long long> > A, pair<pair<long long, long long>, pair<long long, long long> > B) {
	pair<long long, long long> a = A.first;
	pair<long long, long long> b = A.second;
	pair<long long, long long> c = B.first;
	pair<long long, long long> d = B.second;
	int ab = CCW(a, b, c) * CCW(a, b, d); // ab선분에서 다른 선분의 두 점 c, d로의 CCW를 계산
	int cd = CCW(c, d, a) * CCW(c, d, b); // cd선분에서 다른 선분의 두 점 a, b로의 CCW를 계산
	if ((ab == 0) && (cd == 0)) { // 이 경우 b에 대한 c의 상대 위치와 d에 대한 a의 상대 위치를 비교해주면 된다.
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		return ((c <= b) && (a <= d));
	}
	return ((ab <= 0) && (cd <= 0)); // CCW(a, b, c) * CCW(a, b, d)가 0 이하이며, CCW(c, d, a) * CCW(c, d, b)가 0 이하라면 두 선분이 교차한다고 할 수 있다.
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 2; i++) { // 두 선분의 양 끝 점의 좌표를 입력받는다.
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vec.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}
	cout << intersect(vec[0], vec[1]) << "\n";

	getchar();
	getchar();
	return 0;
}