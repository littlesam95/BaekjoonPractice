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
		vec.push_back(make_pair(make_pair(A, B), make_pair(C, D))); // ����
		vec.push_back(make_pair(make_pair(E, F), make_pair(G, F))); // ���簢���� �Ʒ��� ����(�� 1)
		vec.push_back(make_pair(make_pair(G, H), make_pair(G, F))); // ���簢���� ������ ����(�� 2)
		vec.push_back(make_pair(make_pair(E, H), make_pair(G, H))); // ���簢���� ���� ����(�� 3)
		vec.push_back(make_pair(make_pair(E, H), make_pair(E, F))); // ���簢���� ���� ����(�� 4)
		pair<long long, long long> line_1, line_2, square_1, square_2, square_3, square_4; // ������ �� ���� ���簢���� �𼭸�(���� �Ʒ� �𼭸����� �� �ð����)
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
		// 1. ������ ������ �Ǵ�
		bool is_intersect = false;
		for (int i = 1; i <= 4; i++) {
			if (intersect(vec[0].first, vec[0].second, vec[i].first, vec[i].second) > 0) {
				is_intersect = true; // 1�� ���� ��� �����Ѵٴ� ���̴�.
				break;
			}
		}
		if (!is_intersect) { // �簢���� ��� ���� �������� ���� ���
			cout << 0 << "\n";
			continue;
		}
		// �簢���� ���� �� �ϳ� �̻� ������ ���
		// 2. ������ ������ ���� ���
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
		// 3. ������ �簢���� �������� ������ ���
		for (int i = 1; i <= 4; i++) {
			if (cross_point(vec[0].first, vec[0].second, vec[i].first, vec[i].second)) {
				answer_point++;
			}
		}
		// 4. ������ �簢���� ���� ������ ���
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