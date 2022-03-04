#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 25
#define INF 2e9

using namespace std;
int N;
int MAP[MAX][MAX];
int Region[MAX][MAX];
int answer = INF;
int answer_MAP[MAX][MAX];

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Region[i][j] = 5;
		}
	}
}

void Region_Arrange(int Y, int X, int D1, int D2) {
	// 모든 선거구를 5번으로 채운다.
	init();
	// 다음은 1번 선거구를 채운다.
	int Sub_Area = 0;
	for (int i = 1; i < Y + D1; i++) {
		if (i >= Y) {
			Sub_Area++;
		}
		for (int j = 1; j <= X - Sub_Area; j++) {
			Region[i][j] = 1;
		}
	}
	// 다음은 2번 선거구를 채운다.
	Sub_Area = 0;
	for (int j = N; j > X; j--) {
		if (j <= X + D2) {
			Sub_Area++;
		}
		for (int i = 1; i <= Y + D2 - Sub_Area; i++) {
			Region[i][j] = 2;
		}
	}
	// 다음은 3번 선거구를 채운다.
	Sub_Area = 0;
	for (int j = 1; j < X - D1 + D2; j++) {
		if (j >= X - D1) {
			Sub_Area++;
		}
		for (int i = N; i >= Y + D1 + Sub_Area; i--) {
			Region[i][j] = 3;
		}
	}
	// 다음은 4번 선거구를 채운다.
	Sub_Area = 0;
	for (int i = N; i > Y + D2; i--) {
		if (i <= Y + D1 + D2) {
			Sub_Area++;
		}
		for (int j = N; j >= X - D1 + D2 + Sub_Area; j--) {
			Region[i][j] = 4;
		}
	}
}

void Find_Answer() {
	int People[6] = { -1,0,0,0,0,0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			People[Region[i][j]] += MAP[i][j];
		}
	}
	sort(People, People + 6);
	if (answer > People[5] - People[1]) {
		answer = People[5] - People[1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				answer_MAP[i][j] = Region[i][j];
			}
		}
	}
}

bool First_Condition(int D1, int D2) {
	if ((D1 >= 1) && (D2 >= 1)) {
		return true;
	}
	return false;
}

bool Second_Condition(int Y, int D1, int D2) {
	if ((Y >= 1) && (Y < Y + D1 + D2) && (Y + D1 + D2 <= N)) {
		return true;
	}
	return false;
}

bool Third_Condition(int X, int D1, int D2) {
	if ((X - D1 >= 1) && (X - D1 < X) && (X < X + D2) && (X + D2 <= N)) {
		return true;
	}
	return false;
}

int main() {
	FIRST
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int Y = 1; Y <= N; Y++) {
		for (int X = 2; X <= N; X++) {
			for (int D1 = 1; D1 <= X; D1++) {
				for (int D2 = 1; D2 < N - X; D2++) {
					if (First_Condition(D1, D2) && Second_Condition(Y, D1, D2) && Third_Condition(X, D1, D2)) {
						Region_Arrange(Y, X, D1, D2);
						Find_Answer();
					}
				}
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}