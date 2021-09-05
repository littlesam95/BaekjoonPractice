#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
int N;
int arr[MAX];
stack<int> s;
unordered_map<int, int> um;
vector<int> answer;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (um.find(arr[i]) == um.end()) {
			um.insert(make_pair(arr[i], 1));
		}
		else {
			um[arr[i]]++;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		if (s.empty()) {
			answer.push_back(-1);
		}
		else {
			while (um[s.top()] <= um[arr[i]]) {
				s.pop();
				if (s.empty()) {
					break;
				}
			}
			if (!s.empty()) {
				answer.push_back(s.top());
			}
			else {
				answer.push_back(-1);
			}
		}
		s.push(arr[i]);
	}
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}