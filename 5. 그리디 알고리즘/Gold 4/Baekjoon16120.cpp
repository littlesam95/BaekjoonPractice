#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string str;
string answer;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	int p_cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			p_cnt++;
			continue;
		}
		if ((p_cnt >= 2) && (str[i + 1] == 'P')) {
			p_cnt--;
			i++;
		}
		else {
			answer = "NP";
			break;
		}
	}

	if ((p_cnt == 1) && (answer != "NP")) {
		answer = "PPAP";
	}
	else {
		answer = "NP";
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}