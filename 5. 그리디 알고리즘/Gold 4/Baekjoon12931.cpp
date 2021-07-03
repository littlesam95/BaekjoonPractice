#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int res[50] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> res[i];
	}

	while (1) {
		bool c = true;
		for (int i = 0; i < N; i++) {
			if (res[i] > 0) {
				c = false;
				break;
			}
		}
		if (c) {
			break;
		}
		bool b = true;
		for (int i = 0; i < N; i++) {
			if ((res[i] % 2) == 1) {
				b = false;
				break;
			}
		}
		if (b) {
			for (int i = 0; i < N; i++) {
				res[i] /= 2;
			}
			answer++;
		}
		else {
			for (int i = 0; i < N; i++) {
				if ((res[i] % 2) == 1) {
					res[i]--;
					answer++;
				}
			}
		}
	};

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}