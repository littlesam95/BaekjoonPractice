#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int> > score;
int day_score[1001] = { 0, };
int answer = 0;

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.second > B.second) {
		return true;
	}
	else if (A.second == B.second) {
		if (A.first < B.first) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		score.push_back(make_pair(n1, n2));
	}
	sort(score.begin(), score.end(), comp);

	for (int i = 0; i < N; i++) {
		int day = score[i].first - 1;
		while (1) {
			if ((day_score[day] == 0) || (day < 0)) {
				break;
			}
			day--;
		}
		if (day >= 0) {
			day_score[day] = score[i].second;
		}
	}

	for (int i = 0; i < 1001; i++) {
		answer += day_score[i];
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}