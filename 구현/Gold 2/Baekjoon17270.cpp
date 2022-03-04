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
#define MAX 105
#define LL long long
#define INF 1e9

using namespace std;
int V, M, J, S;
int MAP[MAX][MAX];
int Min_Cost = INF;
int Small_Time = INF;
vector<int> Meet_Space;
int answer = -1;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MAP[i][j] = INF;
		}
	}
}

void Find_Candidate() {
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) { // 1. �������� ��� ��ġ�� ������ ��� ��ġ�� ���ο� ��� ��Ұ� �� �� ����.
			continue;
		}
		if (Min_Cost > MAP[J][i] + MAP[S][i]) {
			// 2. ��ǰ�� �Ǹ��� �����̴� ���ο� ��� ��Ҵ� �����̰� �ɸ��� �ִ� �ð��� ���ϰ� �ɸ��� �ִ� �ð��� ���� �ּҰ� �ǵ��� �ϰ� �ʹ�.
			Min_Cost = MAP[J][i] + MAP[S][i];
		}
	}
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) { // 1. �������� ��� ��ġ�� ������ ��� ��ġ�� ���ο� ��� ��Ұ� �� �� ����.
			continue;
		}
		if ((Min_Cost == MAP[J][i] + MAP[S][i]) && (MAP[J][i] <= MAP[S][i]) && (Small_Time > MAP[J][i])) {
			/* 
				3. �����̰� �� �ʰ� �����ϸ� ���Ͽ��� ������ �Ҹ��� ���� ���� ���ϱ⿡, 
				1���� 2�� ������ �����ϴ� ��� �߿����� �����̰� ���Ϻ��� �ʰ� �����ϴ� ���� ��� ��Ұ� �� �� ����.
				4. ���� �� ������ ��� �����ϴ� ��� ��Ұ� ���� ���� �ִٸ�,
				�� �߿� �����̷κ��� ���� ����� ���� ���� ��� ��Ұ� �ȴ�.
				�׷� ��ҵ� ���� ���� �ִٸ�, �� �߿� ��ȣ�� ���� ���� ��Ұ� ���� ��� ��Ұ� �ȴ�.
			*/
			Small_Time = MAP[J][i];
		}
	}
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) {
			continue;
		}
		if ((Min_Cost == MAP[J][i] + MAP[S][i])  && (Small_Time == MAP[J][i])) {
			Meet_Space.push_back(i);
		}
	}
	if (!Meet_Space.empty()) {
		sort(Meet_Space.begin(), Meet_Space.end());
		answer = Meet_Space[0];
	}
}

int main() {
	FIRST
	init();
	cin >> V >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		MAP[A][B] = min(MAP[A][B], C);
		MAP[B][A] = min(MAP[B][A], C);
	}
	cin >> J >> S;
	// �÷��̵�-�ͼ� �˰������� ��� ��� ���� �ִ� �Ÿ��� ���Ѵ�.
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (MAP[i][j] > MAP[i][k] + MAP[k][j]) {
					MAP[i][j] = MAP[i][k] + MAP[k][j];
				}
			}
		}
	}
	Find_Candidate(); // ���� 4������ �´� �ĺ� ��Ҹ� ã�´�.
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}