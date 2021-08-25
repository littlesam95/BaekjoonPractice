#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 4001

using namespace std;
int N;
int A[MAX], B[MAX], C[MAX], D[MAX];
vector<int> vec;
long long answer = 0;

// 중간에서 만나기(Meet in the middle)
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for (int i = 0; i < N; i++) { // C+D의 결과들을 저장
		for (int j = 0; j < N; j++) {
			vec.push_back(C[i] + D[j]);
		}
	}
	sort(vec.begin(), vec.end()); // lower_bound(), upper_bound() 함수를 사용하기 위해 정렬해준다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			auto D = equal_range(vec.begin(), vec.end(), -(A[i] + B[j])); // lower_bound(), upper_bound()로 이루어진 pair를 return
			answer += distance(D.first, D.second); // C+D가 -(A+B)와 같게 되는 쌍의 개수, 즉 합이 0이 되는 쌍의 개수를 distance()로 찾는다.
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}