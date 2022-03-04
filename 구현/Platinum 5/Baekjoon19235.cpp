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

// 블록이 초록색 보드로 떨어진다.
void Green_MAP_Falling(int T, int Y, int X) {
	if (T == 1) { // 1X1 블록은 그대로 떨어진다.
		int H = 0;
		while ((H <= 5) && (Green_MAP[H][X] == 0)) {
			H++;
		};
		H--;
		Green_MAP[H][X] = T;
	}
	else if (T == 2) { // 1X2 블록은 옆 열까지 비어있는지 확인해야 한다.
		int H = 0;
		while ((H <= 5) && (Green_MAP[H][X] == 0) && (Green_MAP[H][X + 1] == 0)) {
			H++;
		};
		H--;
		Green_MAP[H][X] = T;
		Green_MAP[H][X + 1] = T;
	}
	else if (T == 3) { // 2X1 블록은 밑 행까지 비어있는지 확인해야 한다.
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
	for (int i = 4; i >= 0; i--) { // 4열부터 블록을 내릴 수 있는지 확인한다.
		for (int j = 0; j <= 3; j++) {
			int Number = Green_MAP[i][j]; // 블록의 번호
			if ((Number == 1) || (Number == 3)) { // 블록이 1X1이거나 2X1이면 옆 열까지 따질 필요 없다.
				// 타입 3인 경우에도, 아래 블록을 내린 후 윗 블록을 내리기 전에 다른 블록이 끼어들 일이 없으므로, 하나하나씩 내려줘도 된다.
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
				// 타입 2인 경우, 오른쪽 열의 타일도 현재 타일과 번호가 같아야 한다. 그리고 오른쪽만을 확인하므로, 제일 오른쪽 열인 경우에는 제외한다.
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
	// 연한 색을 제외하고, 초록색 보드를 5행부터 역순으로 탐색해주며 행이 가득 차 있다면 블록을 모두 제거해준다.
	bool Flag = true; // Flag가 true라면 더 이상 블록으로 가득 차 없어질 행이 없다는 뜻이다.
	for (int i = 5; i >= 2; i--) {
		bool isFull = true; // i행이 블록으로 가득 차 있으면 true, 아니면 false
		for (int j = 0; j <= 3; j++) {
			if (Green_MAP[i][j] == 0) { // 하나라도 비었다면 i행의 모든 블록을 제거하지 않는다.
				isFull = false;
				break;
			}
		}
		if (isFull) {
			Flag = false;
			answer++; // i행의 블록을 모두 제거했으므로, 점수를 1점 올린다.
			for (int j = 0; j <= 3; j++) { // i행의 블록을 모두 제거
				Green_MAP[i][j] = 0;
			}
		}
	}
	if (!Flag) { 
		/*
			한 행 이상 블록을 제거했다면 블록을 움직여주고, 
			블록을 움직이고 난 후에도 블록을 제거할 행이 있는지 확인해준다.
			이 때 재귀를 사용한다.
		*/
		Green_Move();
		Green_Full_Block();
	}
}

void Green_Delete_Row() {
	int Cnt = 0; // 제거할 행의 개수
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			if (Green_MAP[i][j] > 0) { // i행에 하나라도 블록이 있다면 제거할 행이 하나 늘어난다.
				Cnt++;
				break;
			}
		}
	}
	if (Cnt > 0) {
		for (int i = 5; i > (5 - Cnt); i--) { // 5행부터 최대 4행까지 블록을 제거한다.
			for (int j = 0; j <= 3; j++) {
				Green_MAP[i][j] = 0;
			}
		}
	}
	// 5~4행까지 블록을 제거한 후에는 다시 블록을 움직여주고 블록을 제거할 행이 있는지 확인한다.
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

// 블록이 파란색 보드로 떨어진다.
void Blue_MAP_Falling(int T, int Y, int X) {
	// 1X1인 경우에는 그대로 떨어진다.
	if (T == 1) {
		int H = 0;
		while ((H <= 5) && (Blue_MAP[H][X] == 0)) {
			H++;
		};
		H--;
		Blue_MAP[H][X] = T;
	}
	// 2X1인 경우에는 4행까지 따져준다.
	else if (T == 2) {
		int H = 0;
		while ((H <= 4) && (Blue_MAP[H][X] == 0) && (Blue_MAP[H + 1][X] == 0)) {
			H++;
		};
		H--;
		Blue_MAP[H][X] = T;
		Blue_MAP[H + 1][X] = T;
	}
	// 1X2인 경우에는 다음 열까지 따져준다.
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
			int Number = Blue_MAP[i][j]; // 블록의 번호
			if ((Number == 1) || (Number == 2)) { // 블록이 1X1이거나 2X1이면 옆 열까지 따질 필요 없다.
				// 타입 3인 경우에도, 아래 블록을 내린 후 윗 블록을 내리기 전에 다른 블록이 끼어들 일이 없으므로, 하나하나씩 내려줘도 된다.
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
				// 타입 3인 경우, 오른쪽 열의 타일도 현재 타일과 번호가 같아야 한다. 그리고 오른쪽만을 확인하므로, 제일 오른쪽 열인 경우에는 제외한다.
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
	// 특정 행이 블록으로 가득 차 있다면 제거해주고, 위에 있는 모든 블록을 아래로 떨군다.
	bool Flag = true; // Flag가 true라면 더 이상 블록으로 가득 차 없어질 행이 없다는 뜻이다.
	for (int i = 5; i >= 2; i--) {
		bool isFull = true; // i행이 블록으로 가득 차 있으면 true, 아니면 false
		for (int j = 0; j <= 3; j++) {
			if (Blue_MAP[i][j] == 0) {
				isFull = false;
				break;
			}
		}
		if (isFull) {
			Flag = false;
			answer++;
			for (int j = 0; j <= 3; j++) { // i행의 블록을 모두 제거
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
	int Cnt = 0; // 제거할 행의 개수
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
		// 블록이 초록색 보드로 떨어진다.
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