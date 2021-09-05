#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 500001

using namespace std;
int N;
int arr[MAX];
stack<pair<int, int> > s;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		while (!s.empty()) { // stack�� empty�� �ƴ϶��
			if (s.top().first < arr[i]) { // ���� ����� Ű���� ���� ������� ���� pop�����ش�.
				answer += s.top().second;
				s.pop();
			}
			else {
				break;
			}
		};
		if (s.empty()) { // stack�� empty��� ���� ����� Ű, 1�� pair�� ���� push�����ش�.
			s.push(make_pair(arr[i], 1));
		}
		else { // stack�� empty�� ��
			if (s.top().first == arr[i]) { // ���� ����� Ű�� stack�� top�� ��ġ�ϴ� ����� Ű�� ���ٸ� top�� ��ġ�ϴ� ����� second(���� �� ��)�� �������ش�.
				pair<int, int> tmp = s.top();
				s.pop();
				answer += tmp.second;
				if (!s.empty()) { // stack�� ������� �ʴٸ� stack �� ���� ū ����� ���� �̷�Ƿ� ���� 1 ���������ش�.
					answer++;
				}
				tmp.second++;
				s.push(tmp);
			}
			else { // ���� ����� Ű�� �� �۴ٸ� push���ش�.
				s.push(make_pair(arr[i], 1));
				answer++; // ���� ������� ó������ Ű�� ū ����� ���� �̷�Ƿ� ���� 1 ���������ش�.
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}