#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 50
#define LL long long
#define INF 1e9

using namespace std;
string I;
int N, M;
string Answer = "";

void Input() {
	cin >> I;
}

void Split() {
	string Tmp = "";
	for (int i = 0; i < I.size(); i++) {
		if (I[i] == ':') {
			N = stoi(Tmp);
			Tmp = "";
		}
		else {
			Tmp += I[i];
		}
	}
	M = stoi(Tmp);
}

int GCD(int A, int B) {
	while (1) {
		int R = A % B;
		if (R == 0) {
			return B;
		}
		A = B;
		B = R;
	};
}

void Settings() {
	Split();
	int G = GCD(N, M);
	N /= G;
	M /= G;
	Answer = to_string(N) + ":" + to_string(M);
}

void Find_Answer() {
	cout << Answer << "\n";
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