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
#define MAX 100000000
#define LL long long
#define INF 1e9

using namespace std;
int C;
string S;
LL N, T, L;

void Input() {
	cin >> C;
}

void Settings() {
	if (S == "O(N)") {
		LL Sum = N * T;
		if (Sum <= (L * MAX)) {
			cout << "May Pass.\n";
		}
		else {
			cout << "TLE!\n";
		}
	}
	else if (S == "O(N^2)") {
		if (N >= 31623) {
			cout << "TLE!\n";
		}
		else {
			LL Sum = (N * N * T);
			if (Sum <= (L * MAX)) {
				cout << "May Pass.\n";
			}
			else {
				cout << "TLE!\n";
			}
		}
	}
	else if (S == "O(N^3)") {
		if (N >= 1001) {
			cout << "TLE!\n";
		}
		else {
			LL Sum = (N * N * N * T);
			if (Sum <= (L * MAX)) {
				cout << "May Pass.\n";
			}
			else {
				cout << "TLE!\n";
			}
		}
	}
	else if (S == "O(2^N)") {
		if (N >= 30) {
			cout << "TLE!\n";
		}
		else {
			LL Sum = (LL)pow(2, N) * T;
			if (Sum <= (L * MAX)) {
				cout << "May Pass.\n";
			}
			else {
				cout << "TLE!\n";
			}
		}
	}
	else if (S == "O(N!)") {
		if (N >= 13) {
			cout << "TLE!\n";
		}
		else {
			LL Sum = T;
			for (LL i = 1; i <= N; i++) {
				Sum *= i;
			}
			if (Sum <= (L * MAX)) {
				cout << "May Pass.\n";
			}
			else {
				cout << "TLE!\n";
			}
		}
	}
}

void Find_Answer() {
	while (C--) {
		cin >> S >> N >> T >> L;
		Settings();
	};
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}