#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int T, A, B, C, D, E, F, G, H;
vector<pair<pair<long long, long long>, pair<long long, long long> > > vec;
int answer_line, answer_point;

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

int intersect(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
	int ab = CCW(A, B, C) * CCW(A, B, D);
	int cd = CCW(C, D, A) * CCW(C, D, B);
	if ((ab == 0) && (cd == 0)) {
		if (A > B) {
			swap(A, B);
		}
		if (C > D) {
			swap(C, D);
		}
		return ((C <= B) && (A <= D));
	}
	return ((ab <= 0) && (cd <= 0));
}

bool cross_point(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
	int line = CCW(A, B, C) * CCW(A, B, D);
	int rect = CCW(C, D, A) * CCW(C, D, B);
	if ((line == 0) && (rect <= 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool cross_line(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
	int line = CCW(A, B, C) * CCW(A, B, D);
	int rect = CCW(C, D, A) * CCW(C, D, B);
	if ((line < 0) && (rect <= 0)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		vec.clear();
		answer_line = answer_point = 0;
		cin >> E >> F >> G >> H;
		cin >> A >> B >> C >> D;
		if (A > C) {
			swap(A, C);
			swap(B, D);
		}
		vec.push_back(make_pair(make_pair(A, B), make_pair(C, D))); // 선분
		vec.push_back(make_pair(make_pair(E, F), make_pair(G, F))); // 직사각형의 아래쪽 선분(선 1)
		vec.push_back(make_pair(make_pair(G, H), make_pair(G, F))); // 직사각형의 오른쪽 선분(선 2)
		vec.push_back(make_pair(make_pair(E, H), make_pair(G, H))); // 직사각형의 위쪽 선분(선 3)
		vec.push_back(make_pair(make_pair(E, H), make_pair(E, F))); // 직사각형의 왼쪽 선분(선 4)
		pair<long long, long long> line_1, line_2, square_1, square_2, square_3, square_4; // 선분의 두 점과 직사각형의 모서리(왼쪽 아래 모서리부터 반 시계방향)
		line_1.first = A;
		line_1.second = B;
		line_2.first = C;
		line_2.second = D;
		square_1.first = E;
		square_1.second = F;
		square_2.first = G;
		square_2.second = F;
		square_3.first = G;
		square_3.second = H;
		square_4.first = E;
		square_4.second = H;
		// 1. 교점이 없는지 판단
		bool is_intersect = false;
		for (int i = 1; i <= 4; i++) {
			if (intersect(vec[0].first, vec[0].second, vec[i].first, vec[i].second) > 0) {
				is_intersect = true; // 1이 나온 경우 교차한다는 뜻이다.
				break;
			}
		}
		if (!is_intersect) { // 사각형의 모든 변과 교차하지 않을 경우
			cout << 0 << "\n";
			continue;
		}
		// 사각형의 선분 중 하나 이상 교차할 경우
		// 2. 교점이 무수히 많은 경우
		if (A == C && A == E) {
			if (((B < H) && (D > F)) || ((D < H) && (B > F))) {
				cout << 4 << "\n";
				continue;
			}
		}
		else if (A == C && A == G) {
			if (((B < H) && (D > F)) || ((D < H) && (B > F))) {
				cout << 4 << "\n";
				continue;
			}
		}
		else if (B == D && B == F) {
			if (((A < G) && (C > E)) || ((C < G) && (A > E))) {
				cout << 4 << "\n";
				continue;
			}
		}
		else if (B == D && B == H) {
			if (((A < G) && (C > E)) || ((C < G) && (A > E))) {
				cout << 4 << "\n";
				continue;
			}
		}
		// 3. 선분이 사각형의 꼭짓점을 지나는 경우
		for (int i = 1; i <= 4; i++) {
			if (cross_point(vec[0].first, vec[0].second, vec[i].first, vec[i].second)) {
				answer_point++;
			}
		}
		// 4. 선분이 사각형의 변을 지나는 경우
		for (int i = 1; i <= 4; i++) {
			if (cross_line(vec[0].first, vec[0].second, vec[i].first, vec[i].second)) {
				answer_line++;
			}
		}
		cout << answer_line + (answer_point / 2) << "\n";
	};

	getchar();
	getchar();
	return 0;
}