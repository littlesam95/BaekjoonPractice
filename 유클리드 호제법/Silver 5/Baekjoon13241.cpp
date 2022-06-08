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
LL A, B;

LL GCD(LL F, LL S) {
	while (1) {
		LL R = F % S;
		if (R == 0) {
			return S;
		}
		F = S;
		S = R;
	}
}

LL LCM(LL F, LL S) {
	return (F * S) / GCD(F, S);
}

void Input() {
	cin >> A >> B;
}

void Find_Answer() {
	cout << LCM(A, B) << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}