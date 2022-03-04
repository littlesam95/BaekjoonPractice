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
#define MAX_R 30005
#define MAX_C 35
#define LL long long
#define INF 1e9

/*
	���������� ���� ��θ� ã�Ƽ� ���� �����ٸ� ���4~5������ ���̵��� �ǰ�����
	���ó� �÷�Ƽ�� ������ �׷� ��� ����� ������ �ʴ´�.
	�ֳ��ϸ� ���̰� �ִ� 3�������ε�, ������ �ִ� 10���� ������,
	�Ϲ����� ������� Ǭ�ٸ� �ð� �ʰ��� �߻��Ѵ�.
	���� �ٸ� ������� �����ؾ� �Ѵ�.
	���۸��� ���ؼ� ���� ������ ��θ� �����ִ� ������� �����Ѵٸ�,
	���� ���� ���� �� ���� ���� �� �� ���� �ľ��� �� ������,
	�ð��� ���� ���� �� �ִ�.
*/

using namespace std;
int R, C, N;
int MAP[MAX_R][MAX_C];
set<int> Wall[MAX_C]; // C���� �ִ� ��ֹ��� ��
/*
	�� ������ �����ϴ� �� �Ǵ� ���� ��ġ�� ��Ÿ���� ���Ͽ� set�� ����Ͽ���.
	set�� ���ҵ��� �ڵ����� �������� ���Ľ����ִ� Ư¡�� ������ �ִ�.
*/
stack<pair<int, int> > Check_Pos[MAX_C]; // 1�� C������ ����߸��� ���� üũ����Ʈ ��ǥ
/*
	������ ��θ� �������ֱ� ���� üũ����Ʈ�̴�.
	üũ����Ʈ�� �ش��ϴ� ĭ�� �ٷ� �� ĭ�� ���� ��������.
*/

void Stone_Falling(int Row, int Col, int First) { // Row, Col�� ���� �������� ��, First�� ���� ������ ó�� ��
	int H = *(Wall[Col].upper_bound(Row)); // Col������, ���� �������鼭 �ٸ� ���� �ε��� ���� ã��

	if (MAP[H][Col] == 1) { // �������� ���� H�� Col������ ���� ������ ��
		// ���� ĭ�� ���� �Ʒ� ĭ�� �� ĭ�̶�� ���� �Ʒ� ĭ���� ��������. Col�� 1 �̸��� �Ǹ� �� �ǹǷ� ����ó���� ���ش�.
		if ((Col - 1 >= 1) && (MAP[H][Col - 1] == 0) && (MAP[H - 1][Col - 1] == 0)) {
			// MAP[H - 1][Col - 1]�� �ٷ� ���� ĭ, MAP[H][Col - 1]�� �ٷ� ���� �Ʒ� ĭ�� �ǹ��Ѵ�.
			Check_Pos[First].push(make_pair(H - 1, Col)); // ���� ���� ���� �Ʒ� ĭ���� ���������Ƿ�, üũ����Ʈ�� ����
			Stone_Falling(H - 1, Col - 1, First); // ���� �Ʒ��� ������ �� �ٽ� ������ üũ����Ʈ ã��
		}
		// ������ ĭ�� ������ �Ʒ� ĭ�� �� ĭ�̶�� ������ �Ʒ� ĭ���� ��������. Col�� C �ʰ��� �Ǹ� �� �ǹǷ� ����ó���� ���ش�.
		else if ((Col + 1 <= C) && (MAP[H][Col + 1] == 0) && (MAP[H - 1][Col + 1] == 0)) {
			Check_Pos[First].push(make_pair(H - 1, Col)); // ���� ���� ������ �Ʒ� ĭ���� ���������Ƿ�, üũ����Ʈ�� ����
			Stone_Falling(H - 1, Col + 1, First); // ������ �Ʒ��� ������ �� �ٽ� ������ üũ����Ʈ ã��
		}
		// ������ ���� ���ٸ� ���� ���߰� �ٽô� �������� �ʴ´�.
		else {
			MAP[H - 1][Col] = 1;
			Wall[Col].erase(H);
			Wall[Col].insert(H - 1);
		}

	}
	else { // �������� ���� ���̶��
		MAP[H - 1][Col] = 1; // �� ���� ��������.
		Wall[Col].erase(H);
		Wall[Col].insert(H - 1);
	}
}

void Print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (MAP[i][j] == 0) {
				cout << ".";
			}
			else if (MAP[i][j] == 1) {
				cout << "O";
			}
			else if (MAP[i][j] == -1) {
				cout << "X";
			}
		}
		cout << "\n";
	}
}

int main() {
	FIRST
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= C; j++) {
			if (S[j - 1] == '.') {
				MAP[i][j] = 0;
			}
			else if (S[j - 1] == 'X') {
				MAP[i][j] = -1;
				Wall[j].insert(i); // j�� i�࿡ ���� �������Ƿ�, Wall[j]�� i�� insert�Ѵ�.
			}
		}
	}
	for (int i = 1; i <= C; i++) {
		// ���� 1���� R���� �����ϹǷ�, R+1�࿡ ���� �ִٰ� �����ص� �������.
		Wall[i].insert(R + 1);
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Col, Y, X;
		cin >> Col;
		/*
			���� ����߸� ��, ���� ������ �̵��� ��θ� ã�ƾ� �Ѵ�.
		*/
		while (!Check_Pos[Col].empty()) { // Col�������� ���� üũ����Ʈ
			Y = Check_Pos[Col].top().first;
			X = Check_Pos[Col].top().second;
			if (MAP[Y][X] != 0) { // ���� üũ����Ʈ�� �� ĭ�� �ƴ� ��, �� ���� üũ����Ʈ�� ���� ������ ��
				Check_Pos[Col].pop(); // ���� ĭ���� ���� ���� �����ϹǷ�, üũ����Ʈ�� ���� �� ����
			}
			else { // ���� üũ����Ʈ�� ���� ����߸� ���̴�. ���� üũ����Ʈ�� �� Ž���� �ʿ䰡 �����Ƿ�, �ݺ����� �����Ѵ�.
				break;
			}
		};
		if (Check_Pos[Col].empty()) { // Col���� üũ����Ʈ�� �� �̻� ���� ���
			Stone_Falling(1, Col, Col); // �� ���� ���� ������ ���� ����� ���� ������ �̵� ��ΰ� �����Ƿ�, ó�� 1�࿡�� ���� ������.
		}
		else { // Col���� üũ����Ʈ�� �����ϴ� ���
			Stone_Falling(Y, X, Col); // �� ���� �̹� ���� 1�࿡�� ������, ���� (Y, X)���� ���� ���̹Ƿ�, �������� (Y, X)�� �Ѵ�.
		}
	}
	Print();

	getchar();
	getchar();
	return 0;
}