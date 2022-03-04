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
			map을 이용하여 주어진 N개의 도시에 번호를 매긴다.
			이 때 중복되는 도시가 나올 수 있으므로 unordered_map을 사용
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
					A도시와 B도시 간에 최소의 이동 비용을 따져야 하므로 초기값을 크게 설정
				*/
				Vehicle[i][j] = INF;
				Naeilo[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < K; i++) {
		string Type, S, E;
		double Cost; // 50% 할인했을 때 소수점 밑까지 따지므로 정수형이 아닌 double형으로 설정하였다.
		cin >> Type >> S >> E >> Cost;
		int Start = City[S];
		int End = City[E];
		// 내일로 티켓 없이 S에서 E로 이동할 때 드는 비용
		Vehicle[Start][End] = min(Vehicle[Start][End], Cost);
		Vehicle[End][Start] = min(Vehicle[End][Start], Cost);
		// 내일로 티켓을 사용할 때
		if ((Type == "Mugunghwa") || (Type == "ITX-Saemaeul") || (Type == "ITX-Cheongchun")) {
			// 무궁화호, ITX-새마을, ITX-청춘은 무료로 이용할 수 있다.
			Naeilo[Start][End] = min(Naeilo[Start][End], (double)0);
			Naeilo[End][Start] = min(Naeilo[End][Start], (double)0);
		}
		else if ((Type == "S-Train") || (Type == "V-Train")) {
			// S-Train, V-Train은 50% 할인된 가격이다.
			Naeilo[Start][End] = min(Naeilo[Start][End], Cost / 2);
			Naeilo[End][Start] = min(Naeilo[End][Start], Cost / 2);
		}
		else {
			// 그 외 교통수단은 비용이 변화가 없다.
			Naeilo[Start][End] = min(Naeilo[Start][End], Cost);
			Naeilo[End][Start] = min(Naeilo[End][Start], Cost);
		}
	}
	// 플로이드-와샬 알고리즘을 사용해서 각 도시 간의 최소 비용을 정한다.
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
		// 이제 여행할 도시 간의 이동 비용(내일로 티켓 없이, 내일로 티켓 사용하고)을 계산한다.
		int Start = City[Tour[i - 1]];
		int End = City[Tour[i]];
		Vehicle_Cost += Vehicle[Start][End];
		Naeilo_Cost += Naeilo[Start][End];
	}
	Naeilo_Cost += R; // 마지막으로 내일로 티켓 구매 비용을 더해준다.
	// 내일로 티켓을 샀을 때의 이동 비용이 더 싸다면 Yes, 같거나 비싸다면 No를 출력한다.
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