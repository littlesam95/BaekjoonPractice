#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11

using namespace std;
int N, A, B;
int MAP[MAX];
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		MAP[i] = -1;
	}
}

int main() {
	FIRST;
	init();
	cin >> N;
	while (N--) {
		cin >> A >> B;
		if (MAP[A] == -1) {
			MAP[A] = B;
		}
		else {
			if (MAP[A] != B) {
				MAP[A] = B;
				answer++;
			}
		}
	};
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}