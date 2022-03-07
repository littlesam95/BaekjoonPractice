#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 501
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
map<string, int> KM;
map<int, string> KM2;
int Parent[MAX];
int answer = 0;
vector<string> answerK;

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union(int X, int Y, int Which) {
	int PX = Find(X);
	int PY = Find(Y);
	if (Which == 1) {
		Parent[PY] = PX;
	}
	else if (Which == 2) {
		Parent[PX] = PY;
	}
}

void Union2(int X, int Y, int Which) {
	int PX = Find(X);
	int PY = Find(Y);
	if (Which == 1) {
		Parent[X] = X;
		Parent[PY] = X;
	}
	else if (Which == 2) {
		Parent[Y] = Y;
		Parent[PX] = Y;
	}
}

vector<string> Split(string S) {
	vector<string> res;
	string tmp = "";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ',') {
			res.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += S[i];
		}
	}
	res.push_back(tmp);
	return res;
}

void Input() {
	cin >> N >> M;
	Init();
	string S;
	cin.ignore();
	for (int i = 1; i <= N; i++) {
		getline(cin, S);
		string Kingdom_Name = S.substr(11);
		KM.insert(make_pair(Kingdom_Name, i));
		KM2.insert(make_pair(i, Kingdom_Name));
	}
	for (int i = 0; i < M; i++) {
		getline(cin, S);
		vector<string> Info = Split(S);
		string K1 = Info[0].substr(11);
		string K2 = Info[1].substr(11);
		if (Find(KM[K1]) != Find(KM[K2])) { // ���� �ӱ��� ���ֱ� ���谡 �ƴ� ���
			// �ٸ� �ձ��� �ӱ��� �ƴ� �ձ��� �ڽ��� �ӱ��� �ƴ� �ٸ� �ձ��� �����Ͽ� ������ ���� �� �ִ�.
			Union(KM[K1], KM[K2], stoi(Info[2]));
		}
		else { // �ӱ��� ���ֱ��� �ο�� ���(�ӱ��� ���� ���ֱ����� �ο� �� ����)
			if (KM[K1] == Find(KM[K1])) { // �� ��° �ձ��� ù ��° �ձ��� ���ֱ��� ���
				if (Info[2] == "2") { // �ӱ��� ���ֱ��� �̱�
					Union2(KM[K1], KM[K2], 2);
				}
			}
			else if (KM[K2] == Find(KM[K2])) { // ù ��° �ձ��� �� ��° �ձ��� ���ֱ��� ���
				if (Info[2] == "1") { // �ӱ��� ���ֱ��� �̱�
					Union2(KM[K1], KM[K2], 1);
				}
			}
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		int P = Find(i);
		if (P == i) {
			answerK.push_back(KM2[i]);
		}
	}
	sort(answerK.begin(), answerK.end());
	cout << (int)answerK.size() << "\n";
	for (int i = 0; i < answerK.size(); i++) {
		cout << "Kingdom of " << answerK[i] << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}