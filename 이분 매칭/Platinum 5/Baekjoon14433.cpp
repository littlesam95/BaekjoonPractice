#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 301
#define INF 1e9+7

using namespace std;
int N, M, K1, K2;
int WANT1[MAX];
bool visited1[MAX];
int WANT2[MAX];
bool visited2[MAX];
vector<int> Graph1[MAX];
vector<int> Graph2[MAX];
int answer1 = 0;
int answer2 = 0;

// �̺� ��Ī(Bipartite Matching)
bool DFS1(int X) {
	for (int i = 0; i < Graph1[X].size(); i++) {
		int Next = Graph1[X][i];
		if (visited1[Next]) {
			continue;
		}
		visited1[Next] = true;
		if ((WANT1[Next] == 0) || DFS1(WANT1[Next])) { // ���� ��Ʈ��(Next)�� ��Ī�� ������ ���ٸ� ��Ʈ�ϰ� ���� ���(X)�� ��Ī��Ű�� true�� return�Ѵ�.
			// �Ǵ� ���� ��Ʈ�ϰ� ��Ī�� ������ �ִٸ�, �� ������ ���ϴ� ��Ʈ���� Ž��(DFS ���)
			WANT1[Next] = X;
			return true;
		}
	}
	return false;
}

bool DFS2(int X) {
	for (int i = 0; i < Graph2[X].size(); i++) {
		int Next = Graph2[X][i];
		if (visited2[Next]) {
			continue;
		}
		visited2[Next] = true;
		if ((WANT2[Next] == 0) || DFS2(WANT2[Next])) { // ���� ��Ʈ��(Next)�� ��Ī�� ������ ���ٸ� ��Ʈ�ϰ� ���� ���(X)�� ��Ī��Ű�� true�� return�Ѵ�.
			// �Ǵ� ���� ��Ʈ�ϰ� ��Ī�� ������ �ִٸ�, �� ������ ���ϴ� ��Ʈ���� Ž��(DFS ���)
			WANT2[Next] = X;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K1 >> K2;
	for (int i = 0; i < K1; i++) {
		int I, J;
		cin >> I >> J;
		Graph1[I].push_back(J);
	}
	for (int i = 0; i < K2; i++) {
		int I, J;
		cin >> I >> J;
		Graph2[I].push_back(J);
	}
	// ������ ��
	memset(WANT1, 0, sizeof WANT1);
	for (int i = 1; i <= N; i++) {
		memset(visited1, false, sizeof visited1);
		if (DFS1(i)) {
			answer1++;
		}
	}
	// ��� ��
	memset(WANT2, 0, sizeof WANT2);
	for (int i = 1; i <= N; i++) {
		memset(visited2, false, sizeof visited2);
		if (DFS2(i)) {
			answer2++;
		}
	}
	if (answer1 < answer2) {
		cout << "�� ���� ������" << "\n";
	}
	else {
		cout << "�׸� �˾ƺ���" << "\n";
	}

	getchar();
	getchar();
	return 0;
}