#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100002
#define LL long long
#define INF 1e9

using namespace std;
int N, M, A, B, K;
int H[MAX];
int Sum[MAX];
int Tmp;

void Settings() {
	Sum[A] += K;
	Sum[B + 1] -= K;
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> H[i];
	}
	while (M--) {
		cin >> A >> B >> K;
		Settings();
	};
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		Tmp += Sum[i];
		H[i] += Tmp;
		cout << H[i] << " ";
	}
	cout << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}