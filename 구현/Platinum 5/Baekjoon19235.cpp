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

void Green_Move() {
	for (int i = 4; i >= 0; i--) { // 4������ ����� ���� �� �ִ��� Ȯ���Ѵ�.
		for (int j = 0; j <= 3; j++) {
			int Number = Green_MAP[i][j]; // ����� ��ȣ
			if ((Number == 1) || (Number == 3)) { // ����� 1X1�̰ų� 2X1�̸� �� ������ ���� �ʿ� ����.
				// Ÿ�� 3�� ��쿡��, �Ʒ� ����� ���� �� �� ����� ������ ���� �ٸ� ����� ����� ���� �����Ƿ�, �ϳ��ϳ��� �����൵ �ȴ�.
				if (Green_MAP[i + 1][j] == 0) {
					int H = i + 1;
					while ((H <= 5) && (Green_MAP[H][j] == 0)) {
						H++;
					};
					H--;
					Green_MAP[i][j] = 0;
					Green_MAP[H][j] = Number;
				}
			}
			else if ((j < 3) && (Number == 2)) {
				// Ÿ�� 2�� ���, ������ ���� Ÿ�ϵ� ���� Ÿ�ϰ� ��ȣ�� ���ƾ� �Ѵ�. �׸��� �����ʸ��� Ȯ���ϹǷ�, ���� ������ ���� ��쿡�� �����Ѵ�.
				if (Green_MAP[i][j + 1] == Number) {
					if ((Green_MAP[i + 1][j] == 0) && (Green_MAP[i + 1][j + 1] == 0)) {
						int H = i + 1;
						while ((H <= 5) && (Green_MAP[H][j] == 0) && (Green_MAP[H][j + 1] == 0)) {
							H++;
						}
						H--;
						Green_MAP[i][j] = 0;
						Green_MAP[i][j + 1] = 0;
						Green_MAP[H][j] = 2;
						Green_MAP[H][j + 1] = 2;
					}
				}
			}
		}
	}
}

void Green_Full_Block() {
	// ���� ���� �����ϰ�, �ʷϻ� ���带 5����� �������� Ž�����ָ� ���� ���� �� �ִٸ� ����� ��� �������ش�.
	bool Flag = true; // Flag�� true��� �� �̻� ������� ���� �� ������ ���� ���ٴ� ���̴�.
	for (int i = 5; i >= 2; i--) {
		bool isFull = true; // i���� ������� ���� �� ������ true, �ƴϸ� false
		for (int j = 0; j <= 3; j++) {
			if (Green_MAP[i][j] == 0) { // �ϳ��� ����ٸ� i���� ��� ����� �������� �ʴ´�.
				isFull = false;
				break;
			}
		}
		if (isFull) {
			Flag = false;
			answer++; // i���� ����� ��� ���������Ƿ�, ������ 1�� �ø���.
			for (int j = 0; j <= 3; j++) { // i���� ����� ��� ����
				Green_MAP[i][j] = 0;
			}
		}
	}
	if (!Flag) { 
		/*
			�� �� �̻� ����� �����ߴٸ� ����� �������ְ�, 
			����� �����̰� �� �Ŀ��� ����� ������ ���� �ִ��� Ȯ�����ش�.
			�� �� ��͸� ����Ѵ�.
		*/
		Green_Move();
		Green_Full_Block();
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
	if (Cnt > 0) {
		for (int i = 5; i > (5 - Cnt); i--) { // 5����� �ִ� 4����� ����� �����Ѵ�.
			for (int j = 0; j <= 3; j++) {
				Green_MAP[i][j] = 0;
			}
		}
	}
	// 5~4����� ����� ������ �Ŀ��� �ٽ� ����� �������ְ� ����� ������ ���� �ִ��� Ȯ���Ѵ�.
	Green_Move();
	Green_Full_Block();
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

void Blue_Move() {
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j <= 3; j++) {
			int Number = Blue_MAP[i][j]; // ����� ��ȣ
			if ((Number == 1) || (Number == 2)) { // ����� 1X1�̰ų� 2X1�̸� �� ������ ���� �ʿ� ����.
				// Ÿ�� 3�� ��쿡��, �Ʒ� ����� ���� �� �� ����� ������ ���� �ٸ� ����� ����� ���� �����Ƿ�, �ϳ��ϳ��� �����൵ �ȴ�.
				if (Blue_MAP[i + 1][j] == 0) {
					int H = i + 1;
					while ((H <= 5) && (Blue_MAP[H][j] == 0)) {
						H++;
					};
					H--;
					Blue_MAP[i][j] = 0;
					Blue_MAP[H][j] = Number;
				}
			}
			else if ((j < 3) && (Number == 3)) {
				// Ÿ�� 3�� ���, ������ ���� Ÿ�ϵ� ���� Ÿ�ϰ� ��ȣ�� ���ƾ� �Ѵ�. �׸��� �����ʸ��� Ȯ���ϹǷ�, ���� ������ ���� ��쿡�� �����Ѵ�.
				if (Blue_MAP[i][j + 1] == 3) {
					if ((Blue_MAP[i + 1][j] == 0) && (Blue_MAP[i + 1][j + 1] == 0)) {
						int H = i + 1;
						while ((H <= 5) && (Blue_MAP[H][j] == 0) && (Blue_MAP[H][j + 1] == 0)) {
							H++;
						}
						H--;
						Blue_MAP[i][j] = 0;
						Blue_MAP[i][j + 1] = 0;
						Blue_MAP[H][j] = 3;
						Blue_MAP[H][j + 1] = 3;
					}
				}
			}
		}
	}
}

void Blue_Full_Block() {
	// Ư�� ���� ������� ���� �� �ִٸ� �������ְ�, ���� �ִ� ��� ����� �Ʒ��� ������.
	bool Flag = true; // Flag�� true��� �� �̻� ������� ���� �� ������ ���� ���ٴ� ���̴�.
	for (int i = 5; i >= 2; i--) {
		bool isFull = true; // i���� ������� ���� �� ������ true, �ƴϸ� false
		for (int j = 0; j <= 3; j++) {
			if (Blue_MAP[i][j] == 0) {
				isFull = false;
				break;
			}
		}
		if (isFull) {
			Flag = false;
			answer++;
			for (int j = 0; j <= 3; j++) { // i���� ����� ��� ����
				Blue_MAP[i][j] = 0;
			}
		}
	}
	if (!Flag) {
		Blue_Move();
		Blue_Full_Block();
	}
}

void Blue_Delete_Row() {
	int Cnt = 0; // ������ ���� ����
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			if (Blue_MAP[i][j] > 0) {
				Cnt++;
				break;
			}
		}
	}
	if (Cnt > 0) {
		for (int i = 5; i > (5 - Cnt); i--) {
			for (int j = 0; j <= 3; j++) {
				Blue_MAP[i][j] = 0;
			}
		}
	}
	Blue_Move();
	Blue_Full_Block();
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
		// ����� �ʷϻ� ����� ��������.
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