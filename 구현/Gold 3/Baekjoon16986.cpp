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
#define MAX 15
#define INF 1e9

using namespace std;
int N, K;
int A[MAX][MAX]; // 가위바위보 게임의 상성
int MAP[3][20]; // A번 사람이 B번째로 낼 손동작
int visited[MAX]; // A번 손동작을 냈는지 안 냈는지의 여부
int Win[3]; // A번 사람이 이긴 횟수
int Player_Phase[3]; // A번 사람이 낸 손동작의 횟수
bool answer = false;

bool Check_All() { // 모든 손동작을 다 냈다면 true를 return
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

void Play_Game(int Depth, int Winner, int Turn) {
	if (answer) {
		// answer가 true가 되었다는 것은 더 이상 남은 경우의 수를 따질 필요가 없다는 것이다.
		return;
	}
	if (Depth == 20) {
		// 가위바위보 게임의 최대 횟수는 20회이다.
		return;
	}
	if (Check_All() && (Win[0] < K)) {
		// 모든 손동작을 다 냈는데 이긴 횟수가 K번이 안 된다면 게임을 더 진행할 필요가 없다.
		return;
	}
	if (Win[0] == K) {
		if ((Win[1] < K) && (Win[2] < K)) {
			// 지우가 K번 이겼을 때, 경희, 민호가 K번 미만으로 이겼다면 지우의 우승이다.
			answer = true;
		}
		return;
	}
	if ((Win[1] == K) || (Win[2] == K)) {
		if (Win[0] < K) {
			// 경희나 민호가 먼저 K번 이기면 지우는 우승에 실패한 것이므로 게임을 더 진행할 필요가 없다.
			return;
		}
	}
	int First = Winner; // 직전 게임 우승자. 첫 게임은 지우
	int Second = Turn; // 직전에 게임에 참여하지 않은 사람, 첫 게임은 경희
	// 지우가 게임에 참여했을 경우
	if ((First == 0) && (Second != 0)) {
		int next_Turn;
		if (Second == 1) {
			next_Turn = 2;
		}
		else if (Second == 2) {
			next_Turn = 1;
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				int First_Card = i; // 지우가 고를 손동작(1~N까지)
				int Second_Card = MAP[Second][Player_Phase[Second]]; // 상대방이 낼 손동작
				if (A[First_Card][Second_Card] == 0) {
					Win[Second]++; // 이긴 사람의 이긴 횟수 증가
					Player_Phase[Second]++; // 지우의 상대가 낼 손동작의 순번 증가
					visited[i] = true; // i번째 손동작을 내었다 -> true
					Play_Game(Depth + 1, Second, next_Turn); // 재귀
					visited[i] = false;
					Player_Phase[Second]--;
					Win[Second]--;
				}
				else if (A[First_Card][Second_Card] == 1) {
					int Cur_Winner = max(First, Second);
					Win[Cur_Winner]++;
					Player_Phase[Second]++;
					visited[i] = true;
					Play_Game(Depth + 1, Cur_Winner, next_Turn);
					visited[i] = false;
					Player_Phase[Second]--;
					Win[Cur_Winner]--;
				}
				else if (A[First_Card][Second_Card] == 2) {
					Win[First]++;
					Player_Phase[Second]++;
					visited[i] = true;
					Play_Game(Depth + 1, First, next_Turn);
					visited[i] = false;
					Player_Phase[Second]--;
					Win[First]--;
				}
			}
		}
	}
	else if ((First != 0) && (Second == 0)) {
		int next_Turn;
		if (First == 1) {
			next_Turn = 2;
		}
		else if (First == 2) {
			next_Turn = 1;
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				int First_Card = MAP[First][Player_Phase[First]];
				int Second_Card = i;
				if (A[First_Card][Second_Card] == 0) {
					Win[Second]++;
					Player_Phase[First]++;
					visited[i] = true;
					Play_Game(Depth + 1, Second, next_Turn);
					visited[i] = false;
					Player_Phase[First]--;
					Win[Second]--;
				}
				else if (A[First_Card][Second_Card] == 1) {
					int Cur_Winner = max(First, Second);
					Win[Cur_Winner]++;
					Player_Phase[First]++;
					visited[i] = true;
					Play_Game(Depth + 1, Cur_Winner, next_Turn);
					visited[i] = false;
					Player_Phase[First]--;
					Win[Cur_Winner]--;
				}
				else if (A[First_Card][Second_Card] == 2) {
					Win[First]++;
					Player_Phase[First]++;
					visited[i] = true;
					Play_Game(Depth + 1, First, next_Turn);
					visited[i] = false;
					Player_Phase[First]--;
					Win[First]--;
				}
			}
		}
	}
	// 지우가 게임에 참여하지 않았을 때
	else if ((First != 0) && (Second != 0)) {
		int First_Card = MAP[First][Player_Phase[First]];
		int Second_Card = MAP[Second][Player_Phase[Second]];
		if (A[First_Card][Second_Card] == 0) {
			Win[Second]++;
			Player_Phase[First]++;
			Player_Phase[Second]++;
			Play_Game(Depth + 1, Second, 0); // 다음 차례는 무조건 지우
			Player_Phase[Second]--;
			Player_Phase[First]--;
			Win[Second]--;
		}
		else if (A[First_Card][Second_Card] == 1) {
			int Cur_Winner = max(First, Second);
			Win[Cur_Winner]++;
			Player_Phase[First]++;
			Player_Phase[Second]++;
			Play_Game(Depth + 1, Cur_Winner, 0);
			Player_Phase[Second]--;
			Player_Phase[First]--;
			Win[Cur_Winner]--;
		}
		else if (A[First_Card][Second_Card] == 2) {
			Win[First]++;
			Player_Phase[First]++;
			Player_Phase[Second]++;
			Play_Game(Depth + 1, First, 0);
			Player_Phase[Second]--;
			Player_Phase[First]--;
			Win[First]--;
		}
	}
}

int main() {
	FIRST
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			/*
				가위바위보의 상성. A[i][j]가 2라면 i를 낸 쪽이 이겼다는 뜻이고,
				1이라면 경기 진행 순서가 늦는 쪽이 이기고,
				0이라면 j를 낸 쪽이 이겼다는 뜻이다.
			*/
			cin >> A[i][j];
		}
	}
	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < 20; j++) {
			// 지우를 0, 경희를 1, 민호를 2라고 봤을 때 경희와 민호가 낼 손동작 20가지를 배열에 저장한다.
			cin >> MAP[i][j];
		}
	}
	if (N >= K) {
		/*
			K가 N보다 크다면, N가지 손동작을 1번씩 냈음에도 불구하고
			이겨야 하는 횟수가 더 남은 것이기 때문에,
			무조건 답은 0이 나와야 한다.
			따라서 N이 K 이상일 경우만 따진다.
		*/
		Play_Game(0, 0, 1); // 재귀를 이용하여 모든 경우의 수를 따진다.
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}