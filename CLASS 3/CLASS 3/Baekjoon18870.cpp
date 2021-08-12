#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> matrix; // vector�� ��ǥ���� ����
	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
		matrix.push_back(number);
	}
	vector<int> copy(matrix); // ���� vector
	sort(copy.begin(), copy.end()); // ���� vector �������� ����
	copy.erase(unique(copy.begin(), copy.end()), copy.end()); // �ߺ��� ���ҵ��� ����

	for (int i = 0; i < N; i++) {
		auto it = lower_bound(copy.begin(),copy.end(),matrix[i]); // lower_bound() �Լ��� ���Ͽ� ���� vector�� i ��° ���Ұ� ���� vector�� �� ��°�� �����ϴ��� Ȯ��
		cout << it - copy.begin() << " "; // ��ȯ�� �ּҰ��� ���� �ּҰ��� ���� ���� �����̴�.
	}


	getchar();
	getchar();
	return 0;
}