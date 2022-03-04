#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 123457
#define INF 2e9

using namespace std;
struct ROOM {
	long long T, A, H;
};

long long N, ATK;
vector<ROOM> room;
long long MaxHP = 0;

bool Monster_Battle(long long IDX, long long ATK, long long &HP) {
	long long MobATK = room[IDX].A;
	long long MobHP = room[IDX].H;
	long long CurHP = HP;
	long long nextHP = CurHP / MobATK; // ���Ͱ� ��縦 �� �� ������ ��簡 �״��� Ȯ��
	if (CurHP % MobATK != 0) {// ����� ü���� 0 ���Ϸ� �������� ��� ü���� 1 ���Ѵ�.
		nextHP++;
	}
	long long nextMobHP = MobHP / ATK; // ��簡 ���͸� �� �� ������ ���Ͱ� �״��� Ȯ��
	if (MobHP % ATK != 0) { // ������ ü���� 0 ���Ϸ� �������� ��� ü���� 1 ���Ѵ�. 
		nextMobHP++;
	}
	if (nextMobHP > nextHP) { // ������ ������ ������ ü���� ��纸�� ���� ��� ��簡 �й�
		return false;
	}
	CurHP -= (MobATK * (nextMobHP - 1)); // ��簡 �¸��� ��� ���Ͱ� ��縦 ������ Ƚ�� * ������ ���ݷ¸�ŭ ����� ü���� ��´�.
	HP = CurHP;
	return true;
}

void Potion_Drink(long long IDX, long long &ATK, long long &HP) {
	ATK += room[IDX].A;
	HP += room[IDX].H;
}

void Find_HP(long long left, long long right) {
	long long CurHP, CurATK;
	while (left <= right) {
		CurATK = ATK;
		CurHP = left + (right - left) / 2; // �ּ��� MaxHP�� �̺� Ž������ ���Ѵ�.
		long long tmp = CurHP;
		bool flag = true;
		for (int i = 1; i <= N; i++) { // 1�� ����� Ž��
			if (room[i].T == 1) { // �濡 ���Ͱ� �ִ� ���
				bool Battle = Monster_Battle(i, CurATK, tmp); // ���Ϳ� ����
				if (!Battle) { // ��簡 �й����� ���
					flag = false;
					break;
				}
			}
			else if (room[i].T == 2) { // �濡 ������ �ִ� ���
				Potion_Drink(i, CurATK, tmp); // ������ ���Ŵ�.
				if (tmp > CurHP) { // ���� ü���� �̺� Ž������ ���� MaxHP���� ������ ��� ���� ü���� MaxHP�� �������ٰ� �Ͽ����Ƿ�
					tmp = CurHP;
				}
			}
		}
		if (flag) { // ���� MaxHP�� ���ָ� ������ �� �ִٸ� right���� �����.
			MaxHP = CurHP;
			right = CurHP - 1;
		}
		else { // ���� MaxHP�� ���ָ� ������ �� ���ٸ� left���� ���δ�.
			left = CurHP + 1;
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> ATK;
	room.resize(N + 1);
	for (int i = 1; i <= N; i++) { // 1������ N�������� �� ������ �Է¹޴´�.
		cin >> room[i].T >> room[i].A >> room[i].H;
	}
	Find_HP(1, LLONG_MAX); // �ּڰ��� 1, �ִ��� long long�� �ִ�
	cout << MaxHP << "\n";

	getchar();
	getchar();
	return 0;
}