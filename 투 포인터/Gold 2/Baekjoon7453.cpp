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

// �߰����� ������(Meet in the middle)
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for (int i = 0; i < N; i++) { // C+D�� ������� ����
		for (int j = 0; j < N; j++) {
			vec.push_back(C[i] + D[j]);
		}
	}
	sort(vec.begin(), vec.end()); // lower_bound(), upper_bound() �Լ��� ����ϱ� ���� �������ش�.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			auto D = equal_range(vec.begin(), vec.end(), -(A[i] + B[j])); // lower_bound(), upper_bound()�� �̷���� pair�� return
			answer += distance(D.first, D.second); // C+D�� -(A+B)�� ���� �Ǵ� ���� ����, �� ���� 0�� �Ǵ� ���� ������ distance()�� ã�´�.
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}