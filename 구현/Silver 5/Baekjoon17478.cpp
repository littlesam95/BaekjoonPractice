#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int N;

void Func(int X) {
	if (X == N) {
		for (int i = 0; i < (X * 4); i++) {
			cout << "_";
		}
		cout << "\"����Լ��� ������?\"" << "\n";
		for (int i = 0; i < (X * 4); i++) {
			cout << "_";
		}
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
		for (int i = 0; i < (X * 4); i++) {
			cout << "_";
		}
		cout << "��� �亯�Ͽ���." << "\n";
		return;
	}
	for (int i = 0; i < (X * 4); i++) {
		cout << "_";
	}
	cout << "\"����Լ��� ������?\"" << "\n";
	for (int i = 0; i < (X * 4); i++) {
		cout << "_";
	}
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
	for (int i = 0; i < (X * 4); i++) {
		cout << "_";
	}
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
	for (int i = 0; i < (X * 4); i++) {
		cout << "_";
	}
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
	Func(X + 1);
	for (int i = 0; i < (X * 4); i++) {
		cout << "_";
	}
	cout << "��� �亯�Ͽ���." << "\n";
}

int main() {
	FIRST;
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
	Func(0);

	getchar();
	getchar();
	return 0;
}