#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001

using namespace std;
int N, M;
int Edge_size = 0;
int parent[MAX];
vector<pair<double, double> > Pos;
vector<pair<double, pair<int, int> > > vec;
double answer = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
	}
}

int Find(int X) {
	if (parent[X] < 0) {
		return X;
	}
	return parent[X] = Find(parent[X]);
}

void Union_Set(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X != P_Y) {
		parent[P_Y] = P_X;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	Pos.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> Pos[i].first >> Pos[i].second;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int A = i;
			int B = j;
			double X = (Pos[i].first - Pos[j].first) * (Pos[i].first - Pos[j].first);
			double Y = (Pos[i].second - Pos[j].second) * (Pos[i].second - Pos[j].second);
			double C = sqrt(X + Y);
			vec.push_back(make_pair(C, make_pair(A, B)));
		}
	}
	sort(vec.begin(), vec.end());
	init();
	for (int i = 0; i < vec.size(); i++) {
		int A = vec[i].second.first;
		int B = vec[i].second.second;
		int C = vec[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			answer += vec[i].first;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << round(answer * 100) / (double)100 << "\n";

	getchar();
	getchar();
	return 0;
}