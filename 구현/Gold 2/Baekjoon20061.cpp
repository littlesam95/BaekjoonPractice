#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 6
#define MAX_N 10005
#define LL long long
#define INF 1e9

using namespace std;
int N;
int Green_MAP[MAX][MAX];
int Blue_MAP[MAX][MAX];
int answer = 0;

// ����� �ʷϻ� ����� ��������.
void Green_MAP_Falling(int T, int Y, int X) {
	if (T == 1) { // 1X1 ����� �״�� ��������.
		int H = 0;
		while ((H <= 5) && (Green_MAP[H][X] == 0)) {
			H++;
		};
		H--;
		Green_MAP[H][X] = T;
	}
	else if (T == 2) { // 1X2 ����� �� ������ ����ִ��� Ȯ���ؾ� �Ѵ�.
		int H = 0;
		while ((H <= 5) && (Green_MAP[H][X] == 0) && (Green_MAP[H][X + 1] == 0)) {
			H++;
		};
		H--;
		Green_MAP[H][X] = T;
		Green_MAP[H][X + 1] = T;
	}
	else if (T == 3) { // 2X1 ����� �� ����� ����ִ��� Ȯ���ؾ� �Ѵ�.
		int H = 0;
		while ((H <= 4) && (Green_MAP[H][X] == 0) && (Green_MAP[H + 1][X] == 0)) {
			H++;
		};
		H--;
		Green_MAP[H][X] = T;
		Green_MAP[H + 1][X] = T;
	}
}

void Green_Full_Block() {
	for (int i = 5; i >= 2; i--) {
		bool isFull = true; // i���� ������� ���� �� ������ true, �ƴϸ� false
		for (int j = 0; j <= 3; j++) {
			if (Green_MAP[i][j] == 0) { // �ϳ��� ����ٸ� i���� ��� ����� �������� �ʴ´�.
				isFull = false;
				break;
			}
		}
		if (isFull) {
			answer++; // i���� ����� ��� ���������Ƿ�, ������ 1�� �ø���.
			for (int j = 0; j <= 3; j++) { // i���� ����� ��� ����
				Green_MAP[i][j] = 0;
			}
			for (int j = (i - 1); j >= 0; j--) {
				for (int k = 0; k <= 3; k++) {
					Green_MAP[j + 1][k] = Green_MAP[j][k];
				}
			}
			for (int j = 0; j <= 3; j++) {
				Green_MAP[0][j] = 0;
			}
			i++;
		}
	}
}

void Green_Delete_Row() {
	int Cnt = 0; // ������ ���� ����
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			if (Green_MAP[i][j] > 0) { // i�࿡ �ϳ��� ����� �ִٸ� ������ ���� �ϳ� �þ��.
				Cnt++;
				break;
			}
		}
	}
	for (int i = (5 - Cnt); i >= 0; i--) {
		for (int j = 0; j <= 3; j++) {
			Green_MAP[i + Cnt][j] = Green_MAP[i][j];
		}
	}
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			Green_MAP[i][j] = 0;
		}
	}
}

int Green_Board_Size() {
	int res = 0;
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 3; j++) {
			if (Green_MAP[i][j] != 0) {
				res++;
			}
		}
	}

	return res;
}

// ����� �Ķ��� ����� ��������.
void Blue_MAP_Falling(int T, int Y, int X) {
	// 1X1�� ��쿡�� �״�� ��������.
	if (T == 1) {
		int H = 0;
		while ((H <= 5) && (Blue_MAP[H][X] == 0)) {
			H++;
		};
		H--;
		Blue_MAP[H][X] = T;
	}
	// 2X1�� ��쿡�� 4����� �����ش�.
	else if (T == 2) {
		int H = 0;
		while ((H <= 4) && (Blue_MAP[H][X] == 0) && (Blue_MAP[H + 1][X] == 0)) {
			H++;
		};
		H--;
		Blue_MAP[H][X] = T;
		Blue_MAP[H + 1][X] = T;
	}
	// 1X2�� ��쿡�� ���� ������ �����ش�.
	else if (T == 3) {
		int H = 0;
		while ((H <= 5) && (Blue_MAP[H][X] == 0) && (Blue_MAP[H][X + 1] == 0)) {
			H++;
		};
		H--;
		Blue_MAP[H][X] = T;
		Blue_MAP[H][X + 1] = T;
	}
}

void Blue_Full_Block() {
	for (int i = 5; i >= 2; i--) {
		bool isFull = true; // i���� ������� ���� �� ������ true, �ƴϸ� false
		for (int j = 0; j <= 3; j++) {
			if (Blue_MAP[i][j] == 0) { // �ϳ��� ����ٸ� i���� ��� ����� �������� �ʴ´�.
				isFull = false;
				break;
			}
		}
		if (isFull) {
			answer++; // i���� ����� ��� ���������Ƿ�, ������ 1�� �ø���.
			for (int j = 0; j <= 3; j++) { // i���� ����� ��� ����
				Blue_MAP[i][j] = 0;
			}
			for (int j = (i - 1); j >= 0; j--) {
				for (int k = 0; k <= 3; k++) {
					Blue_MAP[j + 1][k] = Blue_MAP[j][k];
				}
			}
			for (int j = 0; j <= 3; j++) {
				Blue_MAP[0][j] = 0;
			}
			i++;
		}
	}
}

void Blue_Delete_Row() {
	int Cnt = 0; // ������ ���� ����
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			if (Blue_MAP[i][j] > 0) { // i�࿡ �ϳ��� ����� �ִٸ� ������ ���� �ϳ� �þ��.
				Cnt++;
				break;
			}
		}
	}
	for (int i = (5 - Cnt); i >= 0; i--) {
		for (int j = 0; j <= 3; j++) {
			Blue_MAP[i + Cnt][j] = Blue_MAP[i][j];
		}
	}
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			Blue_MAP[i][j] = 0;
		}
	}
}

int Blue_Board_Size() {
	int res = 0;
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 3; j++) {
			if (Blue_MAP[i][j] != 0) {
				res++;
			}
		}
	}

	return res;
}

int main() {
	FIRST
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int T, Y, X;
		cin >> T >> Y >> X;
		Green_MAP_Falling(T, Y, X);
		Blue_MAP_Falling(T, X, Y);
		Green_Full_Block();
		Green_Delete_Row();
		Blue_Full_Block();
		Blue_Delete_Row();
	}
	cout << answer << "\n";
	cout << Green_Board_Size() + Blue_Board_Size() << "\n";

	getchar();
	getchar();
	return 0;
}