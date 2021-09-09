#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <climits>
#include <algorithm>
#define MAX 1000010

using namespace std;
struct Info {
	int S, E;
};

int N;
int sumX[MAX];
int sumY[MAX];
Info tmp;
vector<Info> vec;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		vec.push_back({ X + 500000,Y + 500000 }); // 좌표가 -500,000까지 나올 수 있으므로 500,000을 더해준다.
	}
	for (int i = 0; i < N; i++) {
		Info now = vec[i];
		Info nxt = vec[(i + 1) % N];
		if (now.E == nxt.E) {
			sumX[min(now.S, nxt.S)]++;
			sumX[max(now.S, nxt.S)]--;
		}
		else {
			sumY[min(now.E, nxt.E)]++;
			sumY[max(now.E, nxt.E)]--;
		}
	}
	for (int i = 1; i < MAX; i++) { // 누적합을 구한다.
		sumX[i] += sumX[i - 1];
		sumY[i] += sumY[i - 1];
	}
	cout << max(*max_element(sumX, sumX + MAX), *max_element(sumY, sumY + MAX)) << "\n";

	getchar();
	getchar();
	return 0;
}