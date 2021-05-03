#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

bool COMP(string a, string b) { // 길이가 같으면 문자열의 알파벳순을 비교
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}

int main() {
	int N;
	cin >> N;

	vector<string> str;
	string tmp;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, tmp);
		str.push_back(tmp);
	}

	sort(str.begin(), str.end(), COMP); // algorithm 라이브러리의 sort() 함수를 사용해 정렬

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cout << str[i] << "\n";
		}
		else if (i > 0) {
			if (str[i - 1] != str[i]) {
				cout << str[i] << "\n";
			}
		}
	}

	getchar();
	getchar();
	return 0;
}