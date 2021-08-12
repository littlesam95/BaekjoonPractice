#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
int button[10] = { 1,1,1,1,1,1,1,1,1,1 };
int min_count = INT_MAX;

void comp(string num) {
	for (int i = 0; i < 10; i++) {
		if (button[i]) { // 버튼이 정상적이라면
			string tmp = num + to_string(i);
			int tmpLen = tmp.length();
			min_count = min(min_count, abs(N - stoi(tmp)) + tmpLen); // +, - 버튼만 누를 때 누르는 횟수 vs 가장 가까운 채널 번호를 누르고 +, - 버튼을 누르는 횟수

			if (tmp.length() < 6) { // 목표 채널 번호가 6자리수가 아니라면 tmp부터 다시 반복(000001, 000002, 000003, ...)
				comp(tmp);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	min_count = min(min_count, abs(100 - N)); // N과 현재 채널 번호인 100의 차이
	for (int i = 0; i < M; i++) {
		int number;
		cin >> number;
		button[number] = 0;
	} // 고장난 버튼은 0

	if (M < 10) { // 0~9 버튼이 전부 고장났다면 +, - 버튼을 계속 누르는 수 밖에 없음
		comp("");
	}

	cout << min_count << "\n";

	getchar();
	getchar();
	return 0;
}