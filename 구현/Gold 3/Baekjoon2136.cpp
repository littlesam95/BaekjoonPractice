#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define INF 2e9

using namespace std;
int N, L;
int Ant[MAX];
int Left_Ant, Right_Ant;
int Left_Count = 0;
pair<int, int> Ant_Info[MAX];

bool comp(pair<int, int> A, pair<int, int> B) {
	return (A.second < B.second);
}

int main() {
	FIRST
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		int X;
		cin >> X;
		Ant[i] = X;
	}
	/*
		개미 A, B가 서로 충돌하면, 개미의 번호를 모른다면 A가 가는 길을 B가 대신 가고,
		B가 가는 길을 A가 대신 간다고 할 수 있다. 따라서, 결론적으로 A와 B가 부딪히든 말든,
		A는 B를 통과해 가던 길을 계속 가고, B도 마찬가지라고 할 수 있다.
		따라서, 오른쪽으로 가는 개미들이 L 지점에서 떨어지는 가장 긴 시간을 구하고,
		왼쪽으로 가는 개미들이 0 지점에서 떨어지는 가장 긴 시간을 구해서
		오른쪽으로 가는 개미가 가장 마지막으로 떨어진다면 왼쪽으로 가는 개미의 수 + 1번째 개미가
		가장 늦게 떨어지는 것이고, 왼쪽으로 가는 개미가 가장 마지막으로 떨어진다면
		왼쪽으로 가는 개미의 수번째 개미가 가장 늦게 떨어지는 것이다.
	*/
	for (int i = 1; i <= N; i++) {
		// 일단 개미의 방향을 파악해서 오른쪽 or 왼쪽으로 가는 개미들이 떨어지는 가장 긴 시간을 구한다.
		if (Ant[i] > 0) {
			Right_Ant = max(L - Ant[i], Right_Ant);
		}
		else if (Ant[i] < 0) {
			Left_Count++;
			Left_Ant = max(abs(Ant[i]), Left_Ant);
		}
		// 그리고 i번째 개미의 번호와 떨어지는 시간을 pair로 묶어 배열에 저장한다.
		Ant_Info[i - 1] = make_pair(i, abs(Ant[i]));
	}
	sort(Ant_Info, Ant_Info + N, comp); // 떨어지는 시간을 기준으로 정렬한다.

	if (Left_Ant < Right_Ant) { // 오른쪽으로 떨어지는 개미들이 떨어지는 데 걸리는 시간이 더 길다면
		cout << Ant_Info[Left_Count].first << " " << Right_Ant << "\n";
		// 떨어지는 시간 순으로 정렬했을 때 왼쪽으로 가는 개미의 수 + 1번째 개미의 번호와 떨어지는 데 걸리는 시간을 출력
	}
	else { // 왼쪽으로 떨어지는 개미들이 떨어지는 데 걸리는 시간이 더 길다면
		cout << Ant_Info[Left_Count - 1].first << " " << Left_Ant << "\n";
		// 떨어지는 시간 순으로 정렬했을 때 왼쪽으로 가는 개미의 수번째 개미의 번호와 떨어지는 데 걸리는 시간을 출력
	}

	getchar();
	getchar();
	return 0;
}