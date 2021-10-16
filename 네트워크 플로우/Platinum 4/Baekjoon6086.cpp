#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 60
#define INF 2e9

using namespace std;
int N;
int Source = 0; // �칰
int Sink = 'Z' - 'A'; // �ܾ簣
int CAPACITY[MAX][MAX]; // i���� j���� �带 �� �ʿ��� ���� �뷮
int FLOW[MAX][MAX]; // i���� j���� �帣�� ����
vector<int> Vertex[MAX]; // ������ ����
int Total_Flow = 0;

// ����յ�-ī�� �˰���(Edmonds-Karp Algorithm)
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	while (N--) { // �������� ������ �Է�
		char CFrom, CTo;
		int Value;
		cin >> CFrom >> CTo >> Value;
		// �Է¹��� ���ڸ� 0~51 ������ ������ ��ȯ�Ѵ�.
		int From, To;
		if ((CFrom >= 'A') && (CFrom <= 'Z')) {
			From = CFrom - 'A';
		}
		else {
			From = CFrom - 'a' + 26;
		}
		if ((CTo >= 'A') && (CTo <= 'Z')) {
			To = CTo - 'A';
		}
		else {
			To = CTo - 'a' + 26;
		}
		// From���� To�� �� �� �ʿ��� �뷮 ���ϱ�
		CAPACITY[From][To] += Value;
		CAPACITY[To][From] += Value;
		// ������ ���� �߰�
		Vertex[From].push_back(To);
		Vertex[To].push_back(From);
	};

	while (1) {
		int PREV[MAX];
		memset(PREV, -1, sizeof PREV);
		queue<int> q;
		q.push(Source);

		while (!q.empty()) {
			int nowS = q.front();
			q.pop();

			for (int i = 0; i < Vertex[nowS].size(); i++) {
				int nextS = Vertex[nowS][i];
				if (PREV[nextS] == -1) { // �湮���� �ʾҴ� nextS�� ��,
					if (CAPACITY[nowS][nextS] > FLOW[nowS][nextS]) { // nowS���� nextS�� �带 �� �ִ� ������ �ִٸ�
						q.push(nextS);
						PREV[nextS] = nowS; // nextS�� ��� ������ ���� �����Ѵ�.
						if (nextS == Sink) { // nextS�� Sink�� break
							break;
						}
					}
				}
			}
		};
		if (PREV[Sink] == -1) { // Source���� Sink���� ������ ���ٸ� break
			break;
		}
		int flow = INF; // ���ݱ��� ���� ��� �󿡼� ���� ������ ���� ���� ���ϱ� ���� flow�� INF�� �ʱ�ȭ���״�.
		for (int i = Sink; i != Source; i = PREV[i]) {
			flow = min(flow, CAPACITY[PREV[i]][i] - FLOW[PREV[i]][i]);
		}
		// ������ ���� ���� ������ flow�� ������ ������ �������� flow��ŭ ���ش�.
		for (int i = Sink; i != Source; i = PREV[i]) {
			FLOW[PREV[i]][i] += flow;
			FLOW[i][PREV[i]] -= flow;
		}
		Total_Flow += flow;
	};
	cout << Total_Flow << "\n";

	getchar();
	getchar();
	return 0;
}