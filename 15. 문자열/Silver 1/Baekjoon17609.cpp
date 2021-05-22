#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int T;
string str;

int pelindrome(int left, int right, bool test) {
	while (left < right) {
		if (str[left] != str[right]) {
			if (test) {
				if ((pelindrome(left + 1, right, false) == 0) || pelindrome(left, right - 1, false) == 0) {
					return 1;
				}
			}
			return 2;
		}
		left++;
		right--;
	};
	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> str;
		cout << pelindrome(0, str.length() - 1, true) << "\n";
	};

	getchar();
	getchar();
	return 0;
}