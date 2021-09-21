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
#define MAX 705
#define INF 2e9

using namespace std;
int M, N;
vector<int> MAP;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	MAP.resize((M * 2) - 1, 1);
	for (int i = 1; i <= N; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		for (int j = X; j < X + Y; j++) {
			MAP[j]++;
		}
		for (int j = X + Y; j < (M * 2) - 1; j++) {
			MAP[j] += 2;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (j == 0) {
				cout << MAP[M - i - 1] << " ";
			}
			else {
				cout << MAP[M + j - 1] << " ";
			}
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}