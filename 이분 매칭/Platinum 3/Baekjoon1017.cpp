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
#define MAX 2222
#define INF 1e9+7

using namespace std;
int N, A, B;
int Odd = 1;
int Even = 1;
bool Flag = false;
int DP[MAX];
vector<int> vec1, vec2;
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
vector<int> answer;

void Erathsthenes() {
	for (int i = 2; i < MAX; i++) {
		DP[i] = i;
	}
	for (int i = 2; i <= sqrt(MAX); i++) {
		DP[i * i] = 0;
	}
	for (int i = 2; i < MAX; i++) {
		if (DP[i] == 0) {
			continue;
		}
		for (int j = i * i; j < MAX; j += i) {
			DP[j] = 0;
		}
	}
}

bool DFS(int E) {
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (visited[Next]) { // Next-50��° ¦���� �̹� Ž���� ���
			continue;
		}
		if ((Next == A) || (Next == B)) { // Next-50��° ���� ó���� ù ��° Ȧ�� Ȥ�� Ȧ���� ��Ī��Ų ¦���� ���
			continue;
		}
		visited[Next] = true;
		if (DP[vec1[E] + vec2[Next - 50]] == 0) { // E��° Ȧ���� Next-50��° ¦���� ���� �Ҽ��� �ƴ� ���
			continue;
		}
		if ((WORK[Next] == -1) || DFS(WORK[Next])) { // �� ��쿡 ��� �ش����� ���� ��, Next-50��° ¦���� ��Ī���� �ʾҴٸ� E��° Ȧ���� ��Ī��Ų��.
			WORK[Next] = E;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Erathsthenes();
	cin >> N;
	vec1.resize(N * 2 + 1);
	vec2.resize(N * 2 + 1);
	for (int i = 1; i <= N; i++) { // N���� ���� �Է¹޴´�. ���⼭ Ȧ�� ¦���� ������.
		int X;
		cin >> X;
		if ((i == 1) && (X % 2 == 0)) {
			Flag = true;
		}
		if (X % 2 == 1) {
			vec1[Odd++] = X;
		}
		else if (X % 2 == 0) {
			vec2[Even++] = X;
		}
	}
	// �Ҽ��� 2�� �����ϸ� �� Ȧ���̹Ƿ�, �� ���� ������ ���� �� �ִ� �Ҽ��� ��� Ȧ���̴�. N���� ���� ���� �ߺ����� �����Ƿ�, �� ���� ���� 2�� ���� �� ���� �����̴�.
	if (Even != Odd) { // ���� Ȧ���� ¦���� ������ ��ġ���� �ʴ´ٸ� ������ ���� �� ����. ���� -1�� ����Ѵ�.
		cout << -1 << "\n";
		return 0;
	}
	if (Flag) {
		swap(vec1, vec2);
		swap(Odd, Even);
	}
	for (int i = 1; i < Odd; i++) {
		for (int j = 1; j < Even; j++) {
			if (DP[vec1[i] + vec2[j]] > 0) { // i��° Ȧ���� j��° ¦���� ���� �Ҽ���� i�� j�� �������� �����Ѵ�.
				Graph[i].push_back(j + 50); // �� �� �ε����� �ߺ��� �� �����Ƿ� ¦�� �ε����� 50�� �����ش�. N�� �ִ� 50���� �� �� �ֱ� ������
			}
		}
	}
	for (int i = 1; i < Even; i++) { // ¦���鸶�� ù ��° Ȧ���� ��Ī�Ѵ�.
		memset(WORK, -1, sizeof WORK);
		if (DP[vec1[1] + vec2[i]] == 0) { // ù ��° Ȧ���� i��° ¦���� ���� �Ҽ��� �ƴ� ��
			continue;
		}
		WORK[i + 50] = 1; // i��° ¦���� ù ��° Ȧ���� ��Ī�Ѵ�.
		int Matching = 1; // ��Ī�����Ƿ� ��ĪȽ���� 1�� �ʱ�ȭ�Ѵ�.
		A = 1;
		B = i + 50;
		for (int j = 2; j < Odd; j++) { // 2��° Ȧ������ ���ʷ� ¦���� ��Ī�Ѵ�.
			memset(visited, false, sizeof visited);
			visited[1] = true;
			visited[i + 50] = true;
			if (DFS(j)) {
				Matching++; // ��Ī�� �Ǿ��ٸ� ��ĪȽ���� ������Ų��.
			}
		}
		if (Matching == Even - 1) { // ���� ��Ī�� �Ǿ��ٸ� ù ��° Ȧ���� ��Ī��Ų ¦���� ���� vector�� push�Ѵ�.
			answer.push_back(vec2[i]);
		}

	}
	if (answer.size() > 0) {
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}