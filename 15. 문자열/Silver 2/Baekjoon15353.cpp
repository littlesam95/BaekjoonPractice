#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
string A, B;
stack<string> s;
int up = 0;
string res = "";

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;

	int lenA = A.length();
	int lenB = B.length();
	int len = 0;
	if (lenA > lenB) {
		len = lenA;
		string str = "";
		for (int i = 0; i < (lenA - lenB); i++) {
			str += "0";
		}
		str += B;
		B = str;
	}
	else if (lenA < lenB) {
		len = lenB;
		string str = "";
		for (int i = 0; i < (lenB - lenA); i++) {
			str += "0";
		}
		str += A;
		A = str;
	}
	else if (lenA == lenB) {
		len = lenA;
	}

	for (int i = len - 1; i >= 0; i--) {
		int num = stoi(A.substr(i, 1)) + stoi(B.substr(i, 1)) + up;
		if (num >= 10) {
			if (i != 0) {
				up = num / 10;
				int b = num % 10;
				s.push(to_string(b));
			}
			else if (i == 0) {
				s.push(to_string(num));
			}
		}
		else if (num < 10) {
			s.push(to_string(num));
			up = 0;
		}
	}

	int size = s.size();
	for (int i = 0; i < size; i++) {
		res += s.top();
		s.pop();
	}

	cout << res << "\n";

	getchar();
	getchar();
	return 0;
}