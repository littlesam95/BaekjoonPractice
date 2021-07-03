#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
vector<int> vec;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	int honor = 1;
	for (int i = 0; i < N; i++) {
		if (vec[i] > honor) {
			int diff = vec[i] - honor;
			vec[i] -= diff;
			answer += diff;
			honor++;
		}
		else {
			honor = vec[i] + 1;
		}
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}