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
int N;
vector<pair<pair<pair<long long, long long>, pair<long long, long long> >, int> > vec;
int arr[3001];
int arr_rank[3001];
int visited[3001];
int group_idx = 0;
int answer_big = INT_MIN;

// 유니온 파인드 + 선분 교차 판정
void init() {
	for (int i = 0; i < 3001; i++) {
		arr[i] = -1;
		arr_rank[i] = 1;
		visited[i] = 0;
	}
}

int find(int x) {
	if (arr[x] < 0) {
		return x;
	}
	int parent = find(arr[x]);
	arr[x] = parent;
	return parent;
}

void union_set(pair<pair<pair<long long, long long>, pair<long long, long long> >, int> X, pair<pair<pair<long long, long long>, pair<long long, long long> >, int> Y) {
	int P_X = find(X.second);
	int P_Y = find(Y.second);
	if (P_X != P_Y) { // 교차하는데 부모가 다르다고 한다면 같은 그룹으로 묶는다.
		arr[P_Y] = P_X; // 선분 y의 부모를 x의 부모로 최신화한다.
		arr_rank[P_X] += arr_rank[P_Y]; // 그룹에 속해있는 선분의 개수를 최신화한다. x의 root의 그룹과 y의 root의 그룹에 속해 있는 선분의 개수를 합친다.
		arr_rank[P_Y] = 1;
	}
}

// 선분 교차 판정 알고리즘
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

int intersect(pair<pair<pair<long long, long long>, pair<long long, long long> >, int> A, pair<pair<pair<long long, long long>, pair<long long, long long> >, int> B) {
	pair<long long, long long> a = A.first.first;
	pair<long long, long long> b = A.first.second;
	pair<long long, long long> c = B.first.first;
	pair<long long, long long> d = B.first.second;
	int ab = CCW(a, b, c) * CCW(a, b, d);
	int cd = CCW(c, d, a) * CCW(c, d, b);
	if ((ab == 0) && (cd == 0)) {
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		return ((c <= b) && (a <= d));
	}
	return ((ab <= 0) && (cd <= 0));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vec.push_back(make_pair(make_pair(make_pair(x1, y1), make_pair(x2, y2)), i)); // 선분의 양 끝점 및 번호(1~N)를 입력
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int is_intersect = intersect(vec[i], vec[j]);
			if (is_intersect == 1) { // 두 선분이 교차한다면 유니온 파인드 알고리즘의 union 함수를 실행하여 두 선분을 그룹으로 묶는다.
				union_set(vec[i], vec[j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) { // 각 선분의 부모 선분을 찾아, 부모 선분을 중심으로 union되어 있는 선분들의 그룹 번호를 매긴다.
		int parent = find(i);
		if (parent == i) {
			group_idx++;
			visited[i] = group_idx;
		}
		else {
			visited[i] = visited[parent];
		}
	}
	for (int i = 1; i <= N; i++) {
		answer_big = max(answer_big, arr_rank[i]); // 가장 큰 그룹을 찾는다.
	}
	cout << group_idx << "\n";
	cout << answer_big << "\n";

	getchar();
	getchar();
	return 0;
}