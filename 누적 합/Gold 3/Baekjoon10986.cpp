#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001
#define INF 2e9

using namespace std;
int N, M;
long long Sum_Arr[MAX];
long long cnt[MAX];
long long answer;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		Sum_Arr[i] = (Sum_Arr[i - 1] % M + tmp % M) % M;
		cnt[Sum_Arr[i]]++;
	}
	answer = cnt[0];
	for (int i = 0; i < M; i++) {
		long long now_Cnt = cnt[i];
		answer += now_Cnt * (now_Cnt - 1) / 2;
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}