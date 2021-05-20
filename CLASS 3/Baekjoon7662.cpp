#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int T, k, n;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		multiset<int> ms; // multiset�� key�� �ߺ� ������ set�� ������ �� �ִ�. �ڵ����� �������� ������ �ȴ�.
		cin >> k;
		for (int i = 0; i < k; i++) {
			string cmd;
			cin >> cmd;
			if (cmd == "I") {
				cin >> n;
				ms.insert(n);
			}
			else if (cmd == "D") {
				cin >> n;
				if (n == 1) {
					if (!ms.empty()) {
						auto iter = ms.end();
						iter--;
						ms.erase(iter);
					}
				}
				else if (n == -1) {
					if (!ms.empty()) {
						ms.erase(ms.begin());
					}
				}
			}
		}

		if (ms.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			auto endIter = ms.end();
			endIter--;
			cout << *endIter << " " << *ms.begin() << "\n";
		}
	};



	getchar();
	getchar();
	return 0;
}