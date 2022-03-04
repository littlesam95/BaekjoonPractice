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
#define MAX 100005
#define INF 1e9

using namespace std;
int N, M, K;
vector<int> Condition[MAX];
int Build[MAX];
int Build_Able[MAX];
bool answer = true;

int main() {
	FIRST
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		/*
			X�ǹ��� �Ǽ��ؾ� Y�ǹ��� �Ǽ��� �� �ִ�.
			X�ǹ��� �����ϴ� ���� ������ �ǹ����� Condition[X] ���Ϳ� �����Ѵ�.
		*/
		int X, Y;
		cin >> X >> Y;
		Condition[X].push_back(Y);
		Build_Able[Y]++; // Y�ǹ��� �Ǽ��ϱ� ���� �ʿ��� �ǹ�, 0�� �Ǿ�� Y�� �Ǽ��� �� ����.
	}
	for (int i = 0; i < K; i++) {
		int Cmd, A;
		cin >> Cmd >> A;
		if (Cmd == 1) { // A�� �ǹ��� 1�� �Ǽ���
			if (Build_Able[A] > 0) { // A�� �ǹ��� �Ǽ��ϱ� ���� �ʿ��� �ǹ��� �� �Ǽ��Ǿ� ���� �ʴٸ�
				// ����� ġƮŰ�� ����� ���̴�.
				answer = false;
				break;
			}
			else { // �ʿ��� �ǹ��� �� �Ǽ��Ǿ��ٸ�
				Build[A]++; // A�� �ǹ��� �Ǽ��Ѵ�. ���⼭ �ǹ��� �������� �� �����Ƿ� boolean�� �ƴ� ���������� �����Ͽ���.
				if (Build[A] == 1) { 
					/*
						A�� �ǹ��� �ϳ��� �־ B, C�� �ǹ��� �Ǽ��� �� �����Ƿ�,
						A�� �ǹ��� �ϳ��� �Ǽ��Ǿ� ���� ������
						A�� �ǹ��� �ʿ�� �ϴ� �ǹ����� ������ �����Ѵ�.
					*/
					for (int j = 0; j < Condition[A].size(); j++) {
						int Cond = Condition[A][j];
						Build_Able[Cond]--;
					}
				}
			}
		}
		else if (Cmd == 2) { // A�� �ǹ��� 1�� �ı���
			if (Build[A] == 0) { // A�� �ǹ��� �Ǽ��Ǿ� ���� �ʴٸ� ����� ġƮŰ�� ����� ���̴�.
				answer = false;
				break;
			}
			else { // A�� �ǹ��� 1�� �̻� �����Ѵٸ�
				Build[A]--; // A�� �ǹ��� �ı��Ѵ�.
				if (Build[A] == 0) { // A�� �ǹ��� 0��, �� ������ٸ� B, C�� �ǹ��� �ʿ��� ������ �ϳ� �Ҿ���� ���̴�.
					for (int j = 0; j < Condition[A].size(); j++) {
						int Cond = Condition[A][j];
						Build_Able[Cond]++;
					}
				}
			}
		}
	}
	if (answer) {
		cout << "King-God-Emperor" << "\n";
	}
	else {
		cout << "Lier!" << "\n";
	}

	getchar();
	getchar();
	return 0;
}