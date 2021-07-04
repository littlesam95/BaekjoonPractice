#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int> > vec;
int answer = 1000000001;

bool comp(pair<int, int> A, pair<int, int> B) {
	return (A.second > B.second);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec.push_back(make_pair(n1, n2));
	}
	sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < vec.size(); i++) {
		if (answer > vec[i].second) {
			answer = vec[i].second;
			answer -= (vec[i].first - 1);
		}
		else {
			answer -= vec[i].first;
		}
	}

	if (answer >= 1) {
		cout << (answer - 1) << "\n";
	}
	else if (answer < 1) {
		cout << answer << "\n";
	}

	getchar();
	getchar();
	return 0;
}