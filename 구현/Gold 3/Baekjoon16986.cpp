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
int A[MAX][MAX]; // ���������� ������ ��
int MAP[3][20]; // A�� ����� B��°�� �� �յ���
int visited[MAX]; // A�� �յ����� �´��� �� �´����� ����
int Win[3]; // A�� ����� �̱� Ƚ��
int Player_Phase[3]; // A�� ����� �� �յ����� Ƚ��
bool answer = false;

bool Check_All() { // ��� �յ����� �� �´ٸ� true�� return
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

void Play_Game(int Depth, int Winner, int Turn) {
	if (answer) {
		// answer�� true�� �Ǿ��ٴ� ���� �� �̻� ���� ����� ���� ���� �ʿ䰡 ���ٴ� ���̴�.
		return;
	}
	if (Depth == 20) {
		// ���������� ������ �ִ� Ƚ���� 20ȸ�̴�.
		return;
	}
	if (Check_All() && (Win[0] < K)) {
		// ��� �յ����� �� �´µ� �̱� Ƚ���� K���� �� �ȴٸ� ������ �� ������ �ʿ䰡 ����.
		return;
	}
	if (Win[0] == K) {
		if ((Win[1] < K) && (Win[2] < K)) {
			// ���찡 K�� �̰��� ��, ����, ��ȣ�� K�� �̸����� �̰�ٸ� ������ ����̴�.
			answer = true;
		}
		return;
	}
	if ((Win[1] == K) || (Win[2] == K)) {
		if (Win[0] < K) {
			// ���� ��ȣ�� ���� K�� �̱�� ����� ��¿� ������ ���̹Ƿ� ������ �� ������ �ʿ䰡 ����.
			return;
		}
	}
	int First = Winner; // ���� ���� �����. ù ������ ����
	int Second = Turn; // ������ ���ӿ� �������� ���� ���, ù ������ ����
	// ���찡 ���ӿ� �������� ���
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
				int First_Card = i; // ���찡 �� �յ���(1~N����)
				int Second_Card = MAP[Second][Player_Phase[Second]]; // ������ �� �յ���
				if (A[First_Card][Second_Card] == 0) {
					Win[Second]++; // �̱� ����� �̱� Ƚ�� ����
					Player_Phase[Second]++; // ������ ��밡 �� �յ����� ���� ����
					visited[i] = true; // i��° �յ����� ������ -> true
					Play_Game(Depth + 1, Second, next_Turn); // ���
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
	// ���찡 ���ӿ� �������� �ʾ��� ��
	else if ((First != 0) && (Second != 0)) {
		int First_Card = MAP[First][Player_Phase[First]];
		int Second_Card = MAP[Second][Player_Phase[Second]];
		if (A[First_Card][Second_Card] == 0) {
			Win[Second]++;
			Player_Phase[First]++;
			Player_Phase[Second]++;
			Play_Game(Depth + 1, Second, 0); // ���� ���ʴ� ������ ����
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
				������������ ��. A[i][j]�� 2��� i�� �� ���� �̰�ٴ� ���̰�,
				1�̶�� ��� ���� ������ �ʴ� ���� �̱��,
				0�̶�� j�� �� ���� �̰�ٴ� ���̴�.
			*/
			cin >> A[i][j];
		}
	}
	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < 20; j++) {
			// ���츦 0, ���� 1, ��ȣ�� 2��� ���� �� ����� ��ȣ�� �� �յ��� 20������ �迭�� �����Ѵ�.
			cin >> MAP[i][j];
		}
	}
	if (N >= K) {
		/*
			K�� N���� ũ�ٸ�, N���� �յ����� 1���� �������� �ұ��ϰ�
			�̰ܾ� �ϴ� Ƚ���� �� ���� ���̱� ������,
			������ ���� 0�� ���;� �Ѵ�.
			���� N�� K �̻��� ��츸 ������.
		*/
		Play_Game(0, 0, 1); // ��͸� �̿��Ͽ� ��� ����� ���� ������.
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}