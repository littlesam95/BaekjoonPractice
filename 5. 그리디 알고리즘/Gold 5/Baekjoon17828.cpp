#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, X;
string answer = "";

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> X;
	if (N <= X) {
		for (int i = 0; i < N; i++) {
			answer += "A";
			X--;
		}
		for (int i = (N - 1); i >= 0; i--) {
			if (X >= 25) {
				answer[i] = 'Z';
				X -= 25;
			}
			else {
				answer[i] = (char)(int(answer[i]) + X);
				X = 0;
			}
			if (X == 0) {
				break;
			}
		}
		if (X == 0) {
			cout << answer << "\n";
		}
		else {
			cout << "!\n";
		}
	}
	else {
		cout << "!\n";
	}

	getchar();
	getchar();
	return 0;
}