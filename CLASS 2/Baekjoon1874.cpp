#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int*stackArr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> stackArr[i];
	}

	stack<int> st;
	int number = 1;
	char*result = new char[(n * 2)];
	int index = 0;
	bool res = true;
	for (int i = 0; i < n; i++) {
		if (st.size() == 0) { // stack�� ����ִٸ�
			while (number <= stackArr[i]) { // ó�� ������ i��° ������ �ִ� ������ 1�� ������Ű�� push
				st.push(number);
				number++;
				result[index++] = '+';
			};
			st.pop(); // i��° ������ �ִ� �� = top pop
			result[index++] = '-';;
		}
		else { // stack�� ������� �ʴٸ�
			if (stackArr[i] > stackArr[i - 1]) { // i-1��° �������� i��° ������ �ִ� ���� �� ũ��
				while (number <= stackArr[i]) { // i��° ������ �ִ� ������ 1�� ������Ű�� push
					st.push(number);
					number++;
					result[index++] = '+';
				};
				st.pop(); // i��° ������ �ִ� �� = top pop
				result[index++] = '-';;
			}
			else if (stackArr[i] < stackArr[i - 1]) { // i-1��° �������� i��° ������ �ִ� ���� �� ������
				if (st.top() == stackArr[i]) { // top�� i��° ������ �ִ� �� ���ؼ� ���ٸ� pop
					st.pop();
					result[index++] = '-';;
				}
				else { // �ٸ��� �ݺ��� ���� �� NO ���
					res = false;
					break;
				}
			}
		}
	}

	if (res) { // ������ �����̶�� push�� pop ������ ��ȣ�� �����
		for (int i = 0; i < index; i++) {
			cout << result[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}


	getchar();
	getchar();
	return 0;
}