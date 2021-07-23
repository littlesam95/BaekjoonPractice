#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define MAX_NODE 100001

// �ּ� ���� ����(LCA) �˰���
using namespace std;
int T;
int N;
int a, b;
int depth[MAX_NODE]; // node�� ����(����)
int ac[MAX_NODE][20]; // ac[x][y] : x�� 2^y��° ����
int parent[MAX_NODE];
vector<int> vec[MAX_NODE];
int max_level;

void init() {
	N = 0;
	a = 0;
	b = 0;
	for (int i = 0; i < 10010; i++) {
		depth[i] = 0;
		parent[i] = 0;
		vec[i].clear();
		for (int j = 0; j < 20; j++) {
			ac[i][j] = 0;
		}
	}
}

void make_tree(int S, int parent) {
	depth[S] = depth[parent] + 1; // ��� S�� ���̴� �θ� ����� ���� + 1
	ac[S][0] = parent; // S�� 1��° ������ �θ� ���
	max_level = (int)floor(log2(MAX_NODE)); // MAX_NODE�� log2�� ���� �������ش�.
	for (int i = 1; i <= max_level; i++) {
		int tmp = ac[S][i - 1]; // ��� S�� 2^(i-1)��° ����
		/*
			�� ac[S][i] = ac[tmp][i - 1]��
			S�� 2^i��° ������ tmp�� 2^(i-1)��° ������ 2^(i-1)��° ����� ���ٴ� �ǹ�
			i = 3�� �� S�� 8��° ������ tmp�� 4��° ����� ����.
		*/
		ac[S][i] = ac[tmp][i - 1];
	}
	int len = vec[S].size(); // S�� ����Ǿ� �ִ� ����� ����
	for (int i = 0; i < len; i++) {
		int there = vec[S][i];
		if (there != parent) { // there ��尡 S�� �θ� ��尡 �ƴ϶�� there ���� S�� �ڽ� ����̹Ƿ� dfs ����
			make_tree(there, S);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init(); // depth, parent, ac �迭 �� vec ���� �ʱ�ȭ
		cin >> N;
		for (int i = 1; i < N; i++) { // N-1���� Ʈ���� �����ϴ� ���� ���� �Է�
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
			parent[b] = a; // b�� �θ�� a
		}

		int root;
		for (int i = 1; i <= N; i++) {
			if (!parent[i]) { // �θ� ���ٸ�(0) �� ��尡 ��Ʈ ����� ���̴�.
				root = i;
				break;
			}
		}
		depth[0] = -1;
		make_tree(root, 0); // ��Ʈ ������ Ž�� ����, ��Ʈ ����� depth�� 0

		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) { // depth[b] >= depth[a]�� �ǵ��� swap
				int tmp;
				tmp = a;
				a = b;
				b = tmp;
			}
			// b�� �÷��� depth�� �����ش�.
			for (int i = max_level; i >= 0; i--) {
				if (depth[a] <= depth[ac[b][i]]) { // b�� 2^i��° ������ depth�� a�� depth���� ũ�ų� ������ ��� ������ Ÿ�� ����.
					b = ac[b][i];
				}
			}
		}

		int answer = a;
		if (a != b) { // a�� b�� �ٸ��ٸ� ���� depth�� ������, depth�� ��� �÷� ������ ������ ������ �ݺ�
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				answer = ac[a][i];
			}
		}

		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}

// LCA �˰����� �˱� ���� https://www.crocus.co.kr/895 ������.