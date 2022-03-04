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
#define INF 1e9

using namespace std;
int N, R, M, K;
unordered_map<string, int> City;
vector<string> Tour;
double Vehicle[MAX][MAX];
double Naeilo[MAX][MAX];
double Vehicle_Cost = 0;
double Naeilo_Cost = 0;

int main() {
	FIRST
	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		/*
			map�� �̿��Ͽ� �־��� N���� ���ÿ� ��ȣ�� �ű��.
			�� �� �ߺ��Ǵ� ���ð� ���� �� �����Ƿ� unordered_map�� ���
		*/
		string C;
		cin >> C;
		City[C] = i;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		string C;
		cin >> C;
		Tour.push_back(C);
	}
	cin >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				/*
					A���ÿ� B���� ���� �ּ��� �̵� ����� ������ �ϹǷ� �ʱⰪ�� ũ�� ����
				*/
				Vehicle[i][j] = INF;
				Naeilo[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < K; i++) {
		string Type, S, E;
		double Cost; // 50% �������� �� �Ҽ��� �ر��� �����Ƿ� �������� �ƴ� double������ �����Ͽ���.
		cin >> Type >> S >> E >> Cost;
		int Start = City[S];
		int End = City[E];
		// ���Ϸ� Ƽ�� ���� S���� E�� �̵��� �� ��� ���
		Vehicle[Start][End] = min(Vehicle[Start][End], Cost);
		Vehicle[End][Start] = min(Vehicle[End][Start], Cost);
		// ���Ϸ� Ƽ���� ����� ��
		if ((Type == "Mugunghwa") || (Type == "ITX-Saemaeul") || (Type == "ITX-Cheongchun")) {
			// ����ȭȣ, ITX-������, ITX-û���� ����� �̿��� �� �ִ�.
			Naeilo[Start][End] = min(Naeilo[Start][End], (double)0);
			Naeilo[End][Start] = min(Naeilo[End][Start], (double)0);
		}
		else if ((Type == "S-Train") || (Type == "V-Train")) {
			// S-Train, V-Train�� 50% ���ε� �����̴�.
			Naeilo[Start][End] = min(Naeilo[Start][End], Cost / 2);
			Naeilo[End][Start] = min(Naeilo[End][Start], Cost / 2);
		}
		else {
			// �� �� ��������� ����� ��ȭ�� ����.
			Naeilo[Start][End] = min(Naeilo[Start][End], Cost);
			Naeilo[End][Start] = min(Naeilo[End][Start], Cost);
		}
	}
	// �÷��̵�-�ͼ� �˰����� ����ؼ� �� ���� ���� �ּ� ����� ���Ѵ�.
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Vehicle[i][k] + Vehicle[k][j] < Vehicle[i][j]) {
					Vehicle[i][j] = Vehicle[i][k] + Vehicle[k][j];
				}
				if (Naeilo[i][k] + Naeilo[k][j] < Naeilo[i][j]) {
					Naeilo[i][j] = Naeilo[i][k] + Naeilo[k][j];
				}
			}
		}
	}
	for (int i = 1; i < M; i++) {
		// ���� ������ ���� ���� �̵� ���(���Ϸ� Ƽ�� ����, ���Ϸ� Ƽ�� ����ϰ�)�� ����Ѵ�.
		int Start = City[Tour[i - 1]];
		int End = City[Tour[i]];
		Vehicle_Cost += Vehicle[Start][End];
		Naeilo_Cost += Naeilo[Start][End];
	}
	Naeilo_Cost += R; // ���������� ���Ϸ� Ƽ�� ���� ����� �����ش�.
	// ���Ϸ� Ƽ���� ���� ���� �̵� ����� �� �δٸ� Yes, ���ų� ��δٸ� No�� ����Ѵ�.
	if (Vehicle_Cost > Naeilo_Cost) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

	getchar();
	getchar();
	return 0;
}