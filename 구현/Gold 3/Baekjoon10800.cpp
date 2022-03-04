#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 200010
#define INF 2e9

using namespace std;
struct BALL_INFO {
	int IDX, C, S;
};

int N;
vector<BALL_INFO> ball_vec;
int color[MAX];
int answer[MAX];

bool comp(BALL_INFO A, BALL_INFO B) {
	if (A.S == B.S) {
		return (A.C < B.C);
	}
	return (A.S < B.S);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	ball_vec.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int C, S;
		cin >> C >> S;
		ball_vec[i].IDX = i;
		ball_vec[i].C = C;
		ball_vec[i].S = S;
	}
	int sum = 0;
	sort(ball_vec.begin() + 1, ball_vec.end(), comp);
	for (int i = 1, j = 1; i <= N; i++) {
		while (ball_vec[i].S > ball_vec[j].S) {
			color[ball_vec[j].C] += ball_vec[j].S;
			sum += ball_vec[j].S;
			j++;
		};
		answer[ball_vec[i].IDX] = sum - color[ball_vec[i].C];
	}
	for (int i = 1; i <= N; i++) {
		cout << answer[i] << "\n";
	}

	getchar();
	getchar();
	return 0;
}