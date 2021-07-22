#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
char a, b, c;
vector<pair<int, bool> > vec[30];

void preOrder(int node) {
	cout << (char)(node + 'A'); // ��Ʈ + ���� �ڽ� + ������ �ڽ� ���̹Ƿ� ��Ʈ���� ���
	for (int i = 0; i < vec[node].size(); i++) {
		preOrder(int(vec[node][i].first)); // ���� ���� �ڽĺ��� ��͸� �̿��� Ž��
	}
}

void inOrder(int node) {
	if ((vec[node].size()) && (vec[node][0].second)) { // ���� �ڽ��� �ִٸ� ��͸� �̿��� Ž���� �����Ͽ� ���� �ڽĺ��� ���
		inOrder(int(vec[node][0].first));
	}
	cout << (char)(node + 'A'); // ���� �ڽ� + ��Ʈ + ������ �ڽ� ���̹Ƿ� ���� �ڽ� Ž�� �� ��Ʈ ���
	if ((vec[node].size()) && (!vec[node][0].second)) { // ������ �ڽĸ� �ִٸ� Ž���� �����Ͽ� ������ �ڽ��� ���
		inOrder(int(vec[node][0].first));
	}
	else if (vec[node].size() == 2) { // ���� �ڽ��� �� �����Ѵٸ�
		inOrder(int(vec[node][1].first));
	}
}

void postOrder(int node) {
	for (int i = 0; i < vec[node].size(); i++) { // ���� �ڽ� + ������ �ڽ� + ��Ʈ ���̹Ƿ� ���� �ڽĺ��� ��͸� �̿��� Ž�� ����
		postOrder(int(vec[node][i].first));
	}
	cout << (char)(node + 'A'); // ���� ��Ʈ ���
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (b != '.') {
			vec[a - 'A'].push_back(make_pair(b - 'A', true)); // �ڽ� ��尡 �ִٸ� Ʈ���� �ִ´�.
		}
		if (c != '.') {
			vec[a - 'A'].push_back(make_pair(c - 'A', false));
		}
	}
	preOrder(0); // ���� ��ȸ
	cout << "\n";
	inOrder(0); // ���� ��ȸ
	cout << "\n";
	postOrder(0); // ���� ��ȸ
	cout << "\n";

	getchar();
	getchar();
	return 0;
}