#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
string S, T;
bool res = false;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	cin >> T;
	// 역방향으로 진행(T에서 문자를 빼면서 S와 비교)
	while (1) {
		if (S.length() == T.length()) {
			if (S == T) {
				res = true;
			}
			break;
		}

		char c = T[T.length() - 1];
		T.pop_back();
		if (c == 'B') {
			reverse(T.begin(), T.end());
		}
	};

	cout << res << "\n";

	getchar();
	getchar();
	return 0;
}