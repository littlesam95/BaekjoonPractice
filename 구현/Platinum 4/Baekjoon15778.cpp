#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	// 모든 말은 말판의 날밭((30, 30))에서 시작
	int Y = 30;
	int X = 30;
	bool Teammate[4] = { false, false, false, false }; // A~D를 업거나 업혀 있으면 true, 아니라면 false
	bool isStart = false; // 출발한 상태라면 true, 아니라면 false
};

int N;
INFO Horse[2][4]; // 0팀은 대문자, 1팀은 소문자
string MAP[33] = {
"..----..----..----..----..----..",
"..    ..    ..    ..    ..    ..",
"| \\                          / |",
"|  \\                        /  |",
"|   \\                      /   |",
"|    ..                  ..    |",
"..   ..                  ..   ..",
"..     \\                /     ..",
"|       \\              /       |",
"|        \\            /        |",
"|         ..        ..         |",
"|         ..        ..         |",
"..          \\      /          ..",
"..           \\    /           ..",
"|             \\  /             |",
"|              ..              |",
"|              ..              |",
"|             /  \\             |",
"..           /    \\           ..",
"..          /      \\          ..",
"|         ..        ..         |",
"|         ..        ..         |",
"|        /            \\        |",
"|       /              \\       |",
"..     /                \\     ..",
"..   ..                  ..   ..",
"|    ..                  ..    |",
"|   /                      \\   |",
"|  /                        \\  |",
"| /                          \\ |",
"..    ..    ..    ..    ..    ..",
"..----..----..----..----..----.." };  // 말판을 문자열로 구현
/*
	(0, 0) 뒷밭   (0, 6) 뒷윷   (0, 12) 뒷걸   (0, 18) 뒷개    (0, 24) 뒷도      (0, 30) 앞밭(모)

	             (5, 5) 뒷모도                                (5, 25) 앞모도
	(6, 0) 찌도                                                                  (6, 30) 윷
	                     (10, 10) 뒷모개                 (10, 20) 앞모개

	(12, 0) 찌개                                                                  (6, 30) 걸
	                                     (15, 15) 방

	(18, 0) 찌걸                                                                  (6, 30) 개
	                        (10, 20) 속윷          (20, 20) 사려

	(24, 0) 찌윷                                                                  (6, 30) 도
	              (5, 25) 속모                               (25, 25) 안찌

	(30, 0) 쩔밭   (30, 6) 날도   (30, 12) 날개   (30, 18) 날걸   (30, 24) 날윷   (30, 30) 날밭
*/

void Horse_Move_First_Second(int& Y, int& X, int Team, int Mal, int Cnt) { // 1, 2번 경로(우하향 대각선 방향)
	int CurY = Y;
	int CurX = X;
	int CurCnt = Cnt;
	while (CurCnt--) {
		if (((CurY == 0) && (CurX == 0)) || ((CurY == 5) && (CurX == 5)) || ((CurY == 10) && (CurX == 10))
			|| ((CurY == 15) && (CurX == 15)) || ((CurY == 20) && (CurX == 20)) || ((CurY == 25) && (CurX == 25))) {
			// 뒷밭, 뒷모도, 뒷모개, 방, 사려, 안찌에 위치한 경우 우하향으로 한 칸씩 이동
			CurY += 5;
			CurX += 5;
		}
		else if ((CurY == 30) && (CurX == 30)) { // 날밭에 위치한 경우 말판에서 말이 빠져나간다.
			CurY = -1;
			CurX = -1;
			break;
		}
	};
	Y = CurY;
	X = CurX;
}

void Horse_Move_Third(int& Y, int& X, int Team, int Mal, int Cnt) { // 3번 경로(삼각형)
	int CurY = Y;
	int CurX = X;
	int CurCnt = Cnt;
	while (CurCnt--) {
		if (((CurY == 0) && (CurX == 30)) || ((CurY == 5) && (CurX == 25)) || ((CurY == 10) && (CurX == 20))
			|| ((CurY == 15) && (CurX == 15)) || ((CurY == 20) && (CurX == 10)) || ((CurY == 25) && (CurX == 5))) {
			// 뒷밭, 뒷모도, 뒷모개, 방, 사려, 안찌에 위치한 경우 우하향으로 한 칸씩 이동
			CurY += 5;
			CurX -= 5;
		}
		else if (((CurY == 30) && (CurX == 0)) || ((CurY == 30) && (CurX == 6))
			|| ((CurY == 30) && (CurX == 12)) || ((CurY == 30) && (CurX == 18)) || ((CurY == 30) && (CurX == 24))) {
			// 쩔밭, 날도, 날개, 날걸, 날윷에 위치한 경우 오른쪽으로 한 칸씩 이동
			CurX += 6;
		}
		else if ((CurY == 30) && (CurX == 30)) { // 날밭에 위치한 경우 말판에서 말이 빠져나간다.
			CurY = -1;
			CurX = -1;
			break;
		}
	};
	Y = CurY;
	X = CurX;
}

void Horse_Move_Fourth(int& Y, int& X, int Team, int Mal, int Cnt) { // 4번 경로(사각형)
	int CurY = Y;
	int CurX = X;
	int CurCnt = Cnt;
	while (CurCnt--) {
		if (!Horse[Team][Mal].isStart) { // 아직 출발 안 한 경우 출발하면서 도로 이동
			Horse[Team][Mal].isStart = true;
			CurY -= 6;
		}
		else {
			if (((CurY > 0) && (CurY < 30)) && (CurX == 30)) { // 도, 개, 걸, 윷에 위치한 경우 위로 한 칸씩 이동
				CurY -= 6;
			}
			else if ((CurY == 0) && (CurX > 0)) { // 앞밭(모), 뒷도, 뒷개, 뒷걸, 뒷윷에 위치한 경우 왼쪽으로 한 칸씩 이동
				CurX -= 6;
			}
			else if ((CurY < 30) && (CurX == 0)) { // 뒷밭, 찌도, 찌개, 찌걸, 찌윷에 위치한 경우 아래쪽으로 한 칸씩 이동
				CurY += 6;
			}
			else if (CurY == 30) {
				if (CurX < 30) { // 쩔밭, 날도, 날개, 날걸, 날윷에 위치한 경우 오른쪽으로 한 칸씩 이동
					CurX += 6;
				}
				else if (CurX >= 30) { // 날밭에 위치한 경우 말판에서 말이 빠져나간다.
					CurY = -1;
					CurX = -1;
					break;
				}
			}
		}
	};
	Y = CurY;
	X = CurX;
}

void Make_Teammate(int Y, int X, int Team, int Mal) {
	for (int i = 0; i < 4; i++) {
		if (i == Mal) { // 본인이 본인을 업을 수는 없다.
			continue;
		}
		if ((Horse[Team][i].Y == Y) && (Horse[Team][i].X == X) && (!Horse[Team][Mal].Teammate[i]) && (Horse[Team][i].isStart)) {
			// 말판을 출발한 아군 말이 현재 말과 같은 위치에 있는데 아직 업지 않은 경우
			Horse[Team][Mal].Teammate[i] = true;
			Horse[Team][i].Teammate[Mal] = true;
		}
	}
}

void Delete_Other_Team_Horse(int Y, int X, int Team) {
	if (Team == 0) { // 현재 말이 대문자(0팀)라면
		for (int i = 0; i < 4; i++) {
			if ((Horse[1][i].Y == Y) && (Horse[1][i].X == X) && (Horse[1][i].isStart)) {
				// 말판을 출발한 1팀 말이 현재 말과 같은 위치에 있는 경우 그 말을 잡을 수 있다.
				Horse[1][i].Y = 30;
				Horse[1][i].X = 30;
				Horse[1][i].isStart = false;
				// 말판을 출발하기 전으로 되돌린다.
				for (int j = 0; j < 4; j++) { // 또한 말이 잡혔으므로, 말이 업고 있거나 말을 업은 말들과 전부 관계를 끊는다.
					if (i == j) {
						continue;
					}
					if (Horse[1][i].Teammate[j]) {
						Horse[1][i].Teammate[j] = false;
					}
				}
			}
		}
	}
	else if (Team == 1) { // 현재 말이 소문자(1팀)라면
		for (int i = 0; i < 4; i++) {
			if ((Horse[0][i].Y == Y) && (Horse[0][i].X == X) && (Horse[0][i].isStart)) {
				Horse[0][i].Y = 30;
				Horse[0][i].X = 30;
				Horse[0][i].isStart = false;
				for (int j = 0; j < 4; j++) {
					if (i == j) {
						continue;
					}
					if (Horse[0][i].Teammate[j]) {
						Horse[0][i].Teammate[j] = false;
					}
				}
			}
		}
	}
}

void Remain_Operation(int Y, int X, int Team, int Mal) {
	// N턴에서 움직여 최종적으로 변경된 말의 좌표 다시 초기화
	Horse[Team][Mal].Y = Y;
	Horse[Team][Mal].X = X;
	for (int i = 0; i < 4; i++) { // 말에 업혀 있거나 말을 업은 말들의 좌표 역시 초기화
		if (Mal == i) {
			continue;
		}
		if (Horse[Team][Mal].Teammate[i]) {
			Horse[Team][i].Y = Y;
			Horse[Team][i].X = X;
		}
	}
	if ((Horse[Team][Mal].Y != -1) && (Horse[Team][Mal].X != -1)) { // 말이 말판에서 빠져나가지 않은 경우
		Delete_Other_Team_Horse(Horse[Team][Mal].Y, Horse[Team][Mal].X, Team); // 잡을 수 있는 말들을 탐색
		Make_Teammate(Horse[Team][Mal].Y, Horse[Team][Mal].X, Team, Mal); // 말이업을 수 있는 말들을 탐색
		for (int i = 0; i < 4; i++) { // 마찬가지로 말에 업혀 있거나 말을 업은 말들이 업을 수 있는 말들을 탐색
			if (Mal == i) {
				continue;
			}
			if (Horse[Team][Mal].Teammate[i]) {
				Make_Teammate(Horse[Team][i].Y, Horse[Team][i].X, Team, i);
			}
		}
	}
}

void Print() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			int Y = Horse[i][j].Y;
			int X = Horse[i][j].X;
			if ((!Horse[i][j].isStart) || ((Y == -1) && (X == -1))) {
				// 출발하지 않았거나 말판 한 바퀴를 다 돌고 나간 말이라면 MAP에 표시하지 않는다.
				continue;
			}
			if (j == 0) {
				MAP[Y][X] = (i == 0) ? 'A' : 'a';
			}
			if (j == 1) {
				MAP[Y][X + 1] = (i == 0) ? 'B' : 'b';
			}
			if (j == 2) {
				MAP[Y + 1][X] = (i == 0) ? 'C' : 'c';
			}
			if (j == 3) {
				MAP[Y + 1][X + 1] = (i == 0) ? 'D' : 'd';
			}
		}
	}
	for (int i = 0; i < 32; i++) {
		cout << MAP[i] << "\n";
	}
	cout << "\n";
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		char Mal;
		string Yut;
		cin >> Mal >> Yut;
		// 말의 현재 좌표 가져오기
		int Y, X;
		if ((Mal >= 'A') && (Mal <= 'D')) { // 대문자라면 0팀
			Y = Horse[0][Mal - 'A'].Y;
			X = Horse[0][Mal - 'A'].X;
		}
		else if ((Mal >= 'a') && (Mal <= 'd')) { // 소문자라면 1팀
			Y = Horse[1][Mal - 'a'].Y;
			X = Horse[1][Mal - 'a'].X;
		}

		// 즉 윷의 앞면의 수(F)만큼 전진
		int Cnt = 0;
		for (int j = 0; j < Yut.size(); j++) {
			if (Yut[j] == 'F') {
				Cnt++;
			}
		}
		Cnt = (Cnt) ? Cnt : 5; // 모두 뒷면(B)이라면 5칸 전진

		// 말 움직이기
		if ((Mal >= 'A') && (Mal <= 'D')) { // 말이 대문자라면 0팀
			if (((Y == 0) && (X == 0)) || ((Y == 15) && (X == 15))) {
				// 말이 뒷밭에서 출발할 때에는 2번 경로로 이동, 방에서 출발할 때에는 1번 경로로 이동
				Horse_Move_First_Second(Y, X, 0, Mal - 'A', Cnt);
			}
			else if ((Y == 0) && (X == 30)) {
				// 말이 앞밭에서 출발할 때에는 3번 경로로 이동
				Horse_Move_Third(Y, X, 0, Mal - 'A', Cnt);
			}
			else if ((Y == 30) && (X == 30) && (Horse[0][Mal - 'A'].isStart)) {
				// 말이 이미 출발한 상태에서 날밭에서 출발하는 경우에는 말판에서 빠져나가게 된다.
				Y = -1;
				X = -1;
			}
			else if ((Y % 6 == 0) || (X % 6 == 0)) {
				// 말이 도, 개, 걸, 윷, 뒷도, 뒷개, 뒷걸, 뒷윷, 찌도, 찌개, 찌걸, 찌윷, 쩔밭, 날도, 날개, 날걸, 날윷에서 출발할 때에는 4번 경로로 이동
				Horse_Move_Fourth(Y, X, 0, Mal - 'A', Cnt);
			}
			else {
				if (Y == X) { // 말이 뒷모도, 뒷모개, 사려, 안찌에서 출발할 때에는 2번 경로로 이동
					Horse_Move_First_Second(Y, X, 0, Mal - 'A', Cnt);
				}
				else { // 말이 앞모도, 앞모개, 속윷, 속모에서 출발할 때에는 3번 경로로 이동
					Horse_Move_Third(Y, X, 0, Mal - 'A', Cnt);
				}
			}
			Remain_Operation(Y, X, 0, Mal - 'A'); // 적팀 말 제거, 아군 말 업기 등 추가 작업
		}
		else if ((Mal >= 'a') && (Mal <= 'd')) { // 말이 소문자라면 1팀
			if (((Y == 0) && (X == 0)) || ((Y == 15) && (X == 15))) {
				Horse_Move_First_Second(Y, X, 1, Mal - 'a', Cnt);
			}
			else if ((Y == 0) && (X == 30)) {
				Horse_Move_Third(Y, X, 1, Mal - 'a', Cnt);
			}
			else if ((Y == 30) && (X == 30) && (Horse[1][Mal - 'a'].isStart)) {
				Y = -1;
				X = -1;
			}
			else if ((Y % 6 == 0) || (X % 6 == 0)) {
				Horse_Move_Fourth(Y, X, 1, Mal - 'a', Cnt);
			}
			else {
				if (Y == X) {
					Horse_Move_First_Second(Y, X, 1, Mal - 'a', Cnt);
				}
				else {
					Horse_Move_Third(Y, X, 1, Mal - 'a', Cnt);
				}
			}
			Remain_Operation(Y, X, 1, Mal - 'a');
		}
	}
	Print();

	getchar();
	getchar();
	return 0;
}