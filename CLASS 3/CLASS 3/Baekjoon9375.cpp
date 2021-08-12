#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		int n;
		cin >> n;
		vector<pair<string, string> > vec;
		vector<pair<string, int> > m;
		int sum;
		string str1, str2;
		for (int i = 0; i < n; i++) {
			cin >> str1 >> str2;
			vec.push_back(make_pair(str1, str2));
			int tmp = m.size();
			bool b = true;
			for (int j = 0; j < tmp; j++) {
				if (str2 == m[j].first) {
					b = false;
					break;
				}
			}
			if (b) {
				m.push_back(make_pair(str2, 0));
			}
		}
		int size = m.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < size; j++) {
				if (vec[i].second == m[j].first) {
					m[j].second++;
				}
			}
		}

		sum = 1;
		for (int i = 0; i < size; i++) {
			sum *= (m[i].second + 1);
		}

		cout << sum - 1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}