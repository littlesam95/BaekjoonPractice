#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 5

using namespace std;
vector<int> Color[26];
vector<char> Number[10];
int NMAP[10];
int answer = 0;

void Func() {
	// 1. ī�� 5���� ��� ���� ���̸鼭 ���ڰ� �������� ��
	for (int i = 0; i < 26; i++) {
		if (Color[i].size() == 5) {
			bool Flag = true;
			for (int j = 0; j < 4; j++) {
				if (Color[i][j] + 1 != Color[i][j + 1]) {
					Flag = false;
					break;
				}
			}
			if (Flag) {
				answer = 900 + Color[i][4];
				return;
			}
		}
	}
	// 2. ī�� 5�� �� 4���� ���ڰ� ���� ��
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 4) {
			answer = 800 + i;
			return;
		}
	}
	// 3. ī�� 5�� �� 3���� ���ڰ� ���� ������ 2�嵵 ���ڰ� ���� ��
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 3) {
			for (int j = 1; j < 10; j++) {
				if (i == j) {
					continue;
				}
				if (Number[j].size() == 2) {
					answer = 700 + (i * 10) + j;
					return;
				}
			}
		}
	}
	// 4. 5���� ī�� ������ ��� ���� ��
	for (int i = 0; i < 26; i++) {
		if (Color[i].size() == 5) {
			answer = 600 + Color[i][4];
			return;
		}
	}
	// 5. ī�� 5���� ���ڰ� �������� ��
	for (int i = 1; i < 6; i++) {
		if (NMAP[i] == 1) {
			bool Flag = true;
			for (int j = i + 1; j < i + 5; j++) {
				if (NMAP[j] != 1) {
					Flag = false;
					break;
				}
			}
			if (Flag) {
				answer = 500 + i + 4;
				return;
			}
		}
	}
	// 6. ī�� 5�� �� 3���� ���ڰ� ���� ��
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 3) {
			answer = 400 + i;
			return;
		}
	}
	// 7. ī�� 5�� �� 2���� ���ڰ� ���� �� �ٸ� 2���� ���ڰ� ���� ��
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 2) {
			for (int j = 1; j < 10; j++) {
				if (i == j) {
					continue;
				}
				if (Number[j].size() == 2) {
					int big = max(i, j);
					int small = min(i, j);
					answer = 300 + (big * 10) + small;
					return;
				}
			}
		}
	}
	// 8. ī�� 5�� �� 2���� ���ڰ� ���� ��
	for (int i = 1; i < 10; i++) {
		if (Number[i].size() == 2) {
			answer = 200 + i;
			return;
		}
	}
	// 9. ���� � ��쿡�� �ش����� ���� ��
	for (int i = 9; i >= 1; i--) {
		if (NMAP[i] > 0) {
			answer = 100 + i;
			return;
		}
	}
}

int main() {
	FIRST;
	for (int i = 0; i < MAX; i++) {
		char A;
		int B;
		cin >> A >> B;
		Color[A - 'A'].push_back(B);
		Number[B].push_back(A);
		NMAP[B]++;
	}
	for (int i = 0; i < 26; i++) {
		sort(Color[i].begin(), Color[i].end());
	}
	for (int i = 0; i < 10; i++) {
		sort(Number[i].begin(), Number[i].end());
	}
	Func();
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}