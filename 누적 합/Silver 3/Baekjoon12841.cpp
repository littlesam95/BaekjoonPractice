#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001
#define LL long long
#define INF 1e12

using namespace std;
int N;
LL Crossroad[MAX];
LL Left_Road[MAX];
LL Right_Road[MAX];
LL Answer_Pos, Answer_Len = INF;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Crossroad[i];
	}
	for (int i = 2; i <= N; i++) {
		int X;
		cin >> X;
		Left_Road[i] = Left_Road[i - 1] + X;
	}
	for (int i = 2; i <= N; i++) {
		int X;
		cin >> X;
		Right_Road[i] = Right_Road[i - 1] + X;
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		LL Tmp = Left_Road[i] + Crossroad[i] + Right_Road[N] - Right_Road[i];
		if (Answer_Len > Tmp) {
			Answer_Len = Tmp;
			Answer_Pos = i;
		}
	}
}

void Find_Answer() {
	cout << Answer_Pos << " " << Answer_Len << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}