#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001
#define INF 2e9

using namespace std;
int N, M;
int Arr[MAX];
int Sum_Arr[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Arr[i];
		Sum_Arr[i] = Sum_Arr[i - 1] + Arr[i];
	}
	cin >> M;
	while (M--) {
		int I, J;
		cin >> I >> J;
		cout << Sum_Arr[J] - Sum_Arr[I - 1] << "\n";
	};

	getchar();
	getchar();
	return 0;
}