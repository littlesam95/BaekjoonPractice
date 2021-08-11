#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MAX 1000000007

using namespace std;
int N, M;
long long dist[501];
vector<pair<pair<int, int>, int> > vec;

void init() {
	for (int i = 1; i <= N; i++) {
		dist[i] = MAX;
	}
}

void bellman_ford() {
	dist[1] = 0; // 1�� ���ÿ��� ����ϱ� ������ 1�� ������ ����� 0�̶�� �Ѵ�.
	for (int i = 1; i <= N - 1; i++) { // 
		for (int j = 0; j < vec.size(); j++) {
			int S = vec[j].first.first;
			int E = vec[j].first.second;
			int now_cost = vec[j].second;
			if (dist[S] == MAX) { // ��� ������ ������ ���� �����̶�� �н�
				continue;
			}
			if (dist[E] > dist[S] + now_cost) { // ��� ������ ���� �����̶�� �ش� ������ �մ� ������ �Ÿ��� ���ؼ� �ֽ�ȭ
				dist[E] = dist[S] + now_cost;
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		int S = vec[i].first.first;
		int E = vec[i].first.second;
		int now_cost = vec[i].second;
		if (dist[S] == MAX) {
			continue;
		}
		if (dist[E] > dist[S] + now_cost) {
			// �������� �׷������(���� ����Ŭ�� �߻����� �ʴ� �׷������) N - 1���� Ž���� ���� �� �ѹ��� Ž���� �� �ϴ��� �ּ� ����� ���ϰ� �Ǵ� ������ �߻����� ���� ���̴�.
			// ���� �ּ� ����� ���ϰ� �Ǵ� ������ N��° Ž������ �����Ѵٸ� �װ��� ���� ����Ŭ�� �߻��ϴ� �׷����� �ȴ�.
			// �̰��� �������� "�ð��� ������ ���� ������ �ǵ��� �� �ִٸ�" �̶�� ������ �ش��Ѵ�. ���� ���� ����Ŭ�� �߻��ϴ� �׷������ -1�� ����ϰ� �����Ѵ�.
			cout << -1 << "\n";
			return;
		}
	}
	for (int i = 2; i <= N; i++) { // �������� �׷������ 1�� ���ÿ��� 2~N�� ���ñ��� �̵��ϴ� ���������� �ּ� ����� ����Ѵ�.
		if (dist[i] == MAX) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back(make_pair(make_pair(a, b), c));
	}
	bellman_ford();

	getchar();
	getchar();
	return 0;
}