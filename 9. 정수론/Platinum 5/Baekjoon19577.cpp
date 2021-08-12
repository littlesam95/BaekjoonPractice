#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
vector<int> vec;
int answer = -1;

// 오일러 Φ 함수 알고리즘 : N과 서로소인 N 미만의 수의 개수 찾기
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	if (N % 2 == 0) {
		for (int i = 1; (i * i) <= N; i++) { // 약수 O(sqrt(N))만에 빨리 구하기
			if (N % i == 0) {
				vec.push_back(i);
				if (i != (N / i)) {
					vec.push_back(N / i);
				}
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			int now_x = vec[i];
			int phi = now_x;
			for (int j = 2; (j * j) <= now_x; j++) {
				if (now_x % j == 0) {
					phi /= j;
					phi *= (j - 1);
					while (now_x % j == 0) {
						now_x /= j;
					}
				}
			}
			if (now_x != 1) {
				phi /= now_x;
				phi *= (now_x - 1);
			}
			if (phi * vec[i] == N) {
				answer = vec[i];
				break;
			}
		}
	}
	else if (N == 1) {
		answer = 1;
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}