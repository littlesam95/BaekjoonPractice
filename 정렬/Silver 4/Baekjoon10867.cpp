#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int N;
vector<int> vec;
unordered_set<int> s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		s.insert(number);
	}


	for (auto w : s) {
		vec.push_back(w);
	}

	sort(vec.begin(), vec.end());
	int size = vec.size();
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}

	getchar();
	getchar();
	return 0;
}