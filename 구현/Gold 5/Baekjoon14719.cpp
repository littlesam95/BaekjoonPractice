#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 501

using namespace std;
int H, W;
int MAP[MAX];
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> H >> W;
	for (int i = 1; i <= W; i++) {
		cin >> MAP[i];
	}
	for (int i = 2; i <= W - 1; i++) {
		int LHeight = 0;
		int RHeight = 0;
		for (int j = 1; j < i; j++) {
			LHeight = max(LHeight, MAP[j]);
		}
		for (int j = i + 1; j <= W; j++) {
			RHeight = max(RHeight, MAP[j]);
		}
		int Height = min(LHeight, RHeight);
		if (Height >= MAP[i]) {
			answer += (Height - MAP[i]);
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}