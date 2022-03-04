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
			X건물을 건설해야 Y건물을 건설할 수 있다.
			X건물이 존재하는 것이 조건인 건물들을 Condition[X] 벡터에 저장한다.
		*/
		int X, Y;
		cin >> X >> Y;
		Condition[X].push_back(Y);
		Build_Able[Y]++; // Y건물을 건설하기 위해 필요한 건물, 0이 되어야 Y를 건설할 수 있음.
	}
	for (int i = 0; i < K; i++) {
		int Cmd, A;
		cin >> Cmd >> A;
		if (Cmd == 1) { // A번 건물을 1개 건설함
			if (Build_Able[A] > 0) { // A번 건물을 건설하기 위해 필요한 건물이 다 건설되어 있지 않다면
				// 영우는 치트키를 사용한 것이다.
				answer = false;
				break;
			}
			else { // 필요한 건물이 다 건설되었다면
				Build[A]++; // A번 건물을 건설한다. 여기서 건물이 여러개일 수 있으므로 boolean이 아닌 정수형으로 선언하였다.
				if (Build[A] == 1) { 
					/*
						A번 건물이 하나만 있어도 B, C번 건물을 건설할 수 있으므로,
						A번 건물이 하나만 건설되어 있을 때에만
						A번 건물을 필요로 하는 건물들의 조건을 수정한다.
					*/
					for (int j = 0; j < Condition[A].size(); j++) {
						int Cond = Condition[A][j];
						Build_Able[Cond]--;
					}
				}
			}
		}
		else if (Cmd == 2) { // A번 건물이 1개 파괴됨
			if (Build[A] == 0) { // A번 건물이 건설되어 있지 않다면 영우는 치트키를 사용한 것이다.
				answer = false;
				break;
			}
			else { // A번 건물이 1개 이상 존재한다면
				Build[A]--; // A번 건물을 파괴한다.
				if (Build[A] == 0) { // A번 건물이 0개, 즉 사라졌다면 B, C번 건물은 필요한 조건을 하나 잃어버린 것이다.
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