#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
int learn;
int word[50];
int answer = 0;

int dfs(int start, int learning) {
	int res = 0;
	if (learning == K) { // learning�� K, �� K���� ���ĺ��� ��� ���
		for (int i = 0; i < N; i++) {
			if ((word[i] & learn) == word[i]) { // &(AND) �����ڸ� ����Ͽ�, i��° �ܾ ���Ե� ���ĺ����� ��� ���ĺ���(learn)�� ���ԵǴ��� Ȯ���Ѵ�.
				// AND �������̱� ������, ���� ��Ʈ�� �� 1�� ��쿡�� 1�� ����Ѵ�.
				res++;
			}
		}
		return res;
	}

	// ���� Ž���� �ǽ��Ѵ�.
	for (int i = start; i < 26; i++) { // start��° ���ĺ����� z����
		if ((learn & (1 << i)) == 0) { // i��° ���ĺ��� ����� ���� ���
			learn |= (1 << i);
			res = max(res, dfs(i + 1, learning + 1)); // i��° ���ĺ��� ��� ���¿��� ��͸� �����Ѵ�.
			learn &= ~(1 << i); // i + 1��° ���ĺ��� ����� ���� ��츦 Ž���ؾ� �ϹǷ�, i��° ���ĺ� �� ���Ҹ� ���� learn���� �����Ѵ�.
			// ������ ���� ��ȣ�� &= �̴�.
		}
	}

	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// ���� ���� �ݵ�� anta, tica�� ���λ�� ���̻�� ���� ������, learn ���տ� a, c, i, n, t��� ���Ҹ� �߰����ش�.
	// ���տ� ���Ҹ� �߰��� �� ����ϴ� ��ȣ�� |= �̴�.
	learn |= 1 << ('a' - 'a');
	learn |= 1 << ('c' - 'a');
	learn |= 1 << ('i' - 'a');
	learn |= 1 << ('n' - 'a');
	learn |= 1 << ('t' - 'a');

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			word[i] |= (1 << str[j] - 'a'); // �о�� �ϴ� ���� ��� �ܾ ��Ʈ�������� �߰��Ѵ�.
		}
	}
	if (K < 5) { // anta�� tica�� ���λ�� ���̻�� ���� ������, a, c, i, n, t 5���� ���ĺ��� �ݵ�� ���� �� �־�� �Ѵ�.
		// ���� K�� 5 �̸��� ���� ��� �ܾ�� ���� �� ����.
		answer = 0;
	}
	else if (K == 26) { // ��� ���ĺ� a ~ z���� �����ƴٸ� ��� �ܾ ���� �� �ִ�.
		answer = N;
	}
	else { // K�� 5 �̻� 26 �̸��� ���, ���� Ž������ �� ���� �ܾ ���� �� �ִ��� Ȯ���Ѵ�.
		answer = dfs(0, 5); // learning�� 5���� �����ϴ� ������ a, c, i, n, t 5������ ���ĺ��� �̹� ����� �����̴�.
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}