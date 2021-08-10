#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 500000000

using namespace std;
int N, M, Q;
pair<int, int> monkey[501];
int dist[501][501]; // �÷��̵�-�ͼ� �˰����� ����Ͽ� ������ �ִ� ����� �� ���
int dist2[501][501]; // dist[][]�� �۸��̰� �����̸� ���� ���� ������ �� �ִ� �ð��� ���Ѵ�.
vector<pair<int, int> > query;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				dist[i][j] = monkey[i].first;
				continue;
			}
			else {
				dist[i][j] = MAX;
				dist2[i][j] = MAX;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) { // �۸��̰� �����̸� �������� �ð� �Է�
		cin >> monkey[i].first;
		monkey[i].second = i; // ������ pair<>�� �����Ͽ� first���� �������� �ð�, second���� ���� ��ȣ
	}
	init();
	for (int i = 0; i < M; i++) { // ��� �� ��� ����
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				dist2[i][j] = monkey[i].first; // i�� j�� ���� �����̹Ƿ� dist2[][]���� �۸��̰� �����̸� �������� �ð��� ����
			}
			else {
				dist2[i][j] = dist[i][j] + max(monkey[i].first, monkey[j].first); // i���� j�� ���� ��� + �۸��̰� �����̸� �ִ�� ������ �� �ִ� �ð�
			}
		}
	}
	sort(monkey + 1, monkey + N + 1); // �۸��̰� �����̸� �������� ���� ����
	int monkey_idx[501];
	for (int i = 1; i <= N; i++) {
		monkey_idx[monkey[i].second] = i; // ���ĵʿ� ���� ������ ��ȣ�� ���������� ���� �ʾ����Ƿ� ���� ��ȣ�� �����Ѵ�.
	}
	for (int k = 1; k <= N; k++) {
		int num = monkey[k].second; // �������� �ð��� �������� ������������ �Ǿ��ֱ� ������ ���� ��ȣ�� ���������� �ƴϴ�. ���� ���� ��ȣ�� ���� ����
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int big = max(monkey[monkey_idx[i]].first, max(monkey[monkey_idx[j]].first, monkey[k].first));
				// �� ���� �� �۸��̰� �����̸� ���� ���� ������ �� �ִ� ������ �ð��� ����
				if (dist[i][j] > dist[i][num] + dist[num][j]) { // dist[][]���� �ִ� ��� ����
					dist[i][j] = dist[i][num] + dist[num][j];
				}
				if (dist2[i][j] > dist[i][num] + dist[num][j] + big) { // dist2[][]���� �۸��̰� �����̸� ������ �� �ִ� �ð��� �����Ͽ� �ִ� ��� ����
					dist2[i][j] = dist[i][num] + dist[num][j] + big;
				}
			}
		}
	}
	
	// ��ߵ��ÿ� �������ø� �Է��ϰ� �ִ� ����� �� ��� ���(�ּ� �ð�) ���
	for (int i = 0; i < Q; i++) {
		int S, T;
		cin >> S >> T;
		if (dist2[S][T] < MAX) {
			cout << dist2[S][T] << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
	
	getchar();
	getchar();
	return 0;
}