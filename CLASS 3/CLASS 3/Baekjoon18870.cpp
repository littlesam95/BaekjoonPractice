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
	vector<int> matrix; // vector로 좌표들을 저장
	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
		matrix.push_back(number);
	}
	vector<int> copy(matrix); // 복사 vector
	sort(copy.begin(), copy.end()); // 복사 vector 오름차순 정렬
	copy.erase(unique(copy.begin(), copy.end()), copy.end()); // 중복된 원소들을 제거

	for (int i = 0; i < N; i++) {
		auto it = lower_bound(copy.begin(),copy.end(),matrix[i]); // lower_bound() 함수를 통하여 원본 vector의 i 번째 원소가 복사 vector의 몇 번째에 존재하는지 확인
		cout << it - copy.begin() << " "; // 반환된 주소값에 시작 주소값을 빼준 값이 정답이다.
	}


	getchar();
	getchar();
	return 0;
}