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
#define LL long long
#define INF 1e9

using namespace std;
LL N, K;
LL Diagonal = 1; // (1, 1)�� ���� �ִ� �밢���� ������ 1��° �밢��
string S;
pair<LL, LL> Rabbit = make_pair(1, 1); // �䳢�� ó�� ��ġ�� (1, 1)
LL answer = 1; // ó���� (1, 1), �� 1�� �湮�����Ƿ� �ʱⰪ�� 1�̸�, 32��Ʈ ������ ���� �� �ִٰ� �Ͽ����Ƿ� long long������ �����Ѵ�.

LL Find_Number(LL Y, LL X) {
	if (Diagonal % 2 == 0) {
		// ¦����° �밢���� ���
		if (Diagonal > N) {
			// �밢�� ��ȣ�� N�� �Ѿ ��� ������ (�밢�� - N) * (�밢�� - N)�� ���ش�.
			return (((Diagonal * (Diagonal - 1)) / 2) + Y - ((Diagonal - N) * (Diagonal - N)));
		}
		return (((Diagonal * (Diagonal - 1)) / 2) + Y); // (�밢�� * (�밢�� - 1)) / 2 + X��ǥ�� ������ ���� (X, Y)�� ���� �ȴ�.
	}
	else if (Diagonal % 2 == 1) {
		// Ȧ����° �밢���� ���
		if (Diagonal > N) {
			return (((Diagonal * (Diagonal + 1)) / 2) - Y + 1 - ((Diagonal - N) * (Diagonal - N)));
		}
		return (((Diagonal * (Diagonal + 1)) / 2) - (Y - 1)); // (�밢�� * (�밢�� + 1)) / 2 - (X - 1)��ǥ�� ������ ���� (X, Y)�� ���� �ȴ�.
	}
}

int main() {
	FIRST
	cin >> N >> K;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		LL CurY = Rabbit.first;
		LL CurX = Rabbit.second;
		LL nextY, nextX;
		if (S[i] == 'U') {
			// ���� �� ĭ �̵��ϸ� ���� �밢������ �̵��Ѵ�.
			Diagonal--;
			nextY = CurY - 1;
			nextX = CurX;
			answer += Find_Number(nextY, nextX);
		}
		else if (S[i] == 'D') {
			// �Ʒ��� �� ĭ �̵��ϸ� ���� �밢������ �̵��Ѵ�.
			Diagonal++;
			nextY = CurY + 1;
			nextX = CurX;
			answer += Find_Number(nextY, nextX);
		}
		else if (S[i] == 'L') {
			// �������� �� ĭ �̵��ϸ� ���� �밢������ �̵��Ѵ�.
			Diagonal--;
			nextY = CurY;
			nextX = CurX - 1;
			answer += Find_Number(nextY, nextX);
		}
		else if (S[i] == 'R') {
			// ���������� �� ĭ �̵��ϸ� ���� �밢������ �̵��Ѵ�.
			Diagonal++;
			nextY = CurY;
			nextX = CurX + 1;
			answer += Find_Number(nextY, nextX);
		}
		Rabbit = make_pair(nextY, nextX);
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}