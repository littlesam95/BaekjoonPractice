#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define LL long long
#define INF 1e9

using namespace std;
struct NODE {
	NODE* Parent;
	string Name;
	set<string> Photo;
	map<string, NODE*> Child;
};

int N;
NODE* Root;
NODE* Cur_Album;
map<string, NODE*>::iterator MIT;
set<string>::iterator SIT;

NODE* Make_Node() {
	NODE* Node = new NODE();
	Node->Parent = NULL;
	return Node;
}

void init() {
	Root = Make_Node();
	Root->Name = "album";
	Cur_Album = Root;
}

pair<int, int> Delete_Album(NODE* Node) {
	int Album_Cnt = 1;
	int Photo_Cnt = Node->Photo.size();
	map<string, NODE*>::iterator IT;
	for (IT = Node->Child.begin(); IT != Node->Child.end(); IT++) {
		pair<int, int> Deleted_Album = Delete_Album((*IT).second);
		Album_Cnt += Deleted_Album.first;
		Photo_Cnt += Deleted_Album.second;
	}
	return make_pair(Album_Cnt, Photo_Cnt);
}

int main() {
	FIRST
	cin >> N;
	init();
	for (int i = 0; i < N; i++) {
		string CMD;
		cin >> CMD;
		if (CMD == "mkalb") {
			string S;
			cin >> S;
			if (Cur_Album->Child.find(S) != Cur_Album->Child.end()) {
				/*
					���� �ٹ�(Cur_Album)���� map.find() �Լ��� �̿��ؼ� ������� �ϴ� �ٹ��� �̸� S�� �̹� �ִ��� ã�´�.
					������ duplicated album name�� ����Ѵ�.
				*/
				cout << "duplicated album name" << "\n";
			}
			else {
				NODE* child = Make_Node();
				child->Parent = Cur_Album;
				child->Name = S;
				Cur_Album->Child.insert(make_pair(S, child));
			}
		}
		else if (CMD == "rmalb") {
			string S;
			cin >> S;
			pair<int, int> Deleted_Album;
			if (S == "-1") {
				// ���� �ٹ�(Cur_Album)�� �����ִ� �ٹ��� �����Ѵٸ�, �̸��� ���������� ���� ���� �ٹ��� �����Ѵ�.
				if (Cur_Album->Child.size() > 0) {
					MIT = Cur_Album->Child.begin();
					Deleted_Album = Delete_Album((*MIT).second);
					cout << Deleted_Album.first << " " << Deleted_Album.second << "\n";
					Cur_Album->Child.erase(MIT);
				}
				else {
					cout << 0 << " " << 0 << "\n";
				}
			}
			else if (S == "0") {
				// ���� �ٹ�(Cur_Album)�� �����ִ� ��� �ٹ��� �����Ѵ�.
				if (Cur_Album->Child.size() > 0) {
					int Album_Cnt = 0;
					int Photo_Cnt = 0;
					for (MIT = Cur_Album->Child.begin(); MIT != Cur_Album->Child.end(); MIT++) {
						Deleted_Album = Delete_Album((*MIT).second);
						Album_Cnt += Deleted_Album.first;
						Photo_Cnt += Deleted_Album.second;
					}
					cout << Album_Cnt << " " << Photo_Cnt << "\n";
					Cur_Album->Child.clear();
				}
				else {
					cout << 0 << " " << 0 << "\n";
				}
			}
			else if (S == "1") {
				// ���� �ٹ�(Cur_Album)�� �����ִ� �ٹ��� �����Ѵٸ�, �̸��� ���������� ���� ���� �ٹ��� �����Ѵ�.
				if (Cur_Album->Child.size() > 0) {
					MIT = Cur_Album->Child.end();
					MIT--;
					Deleted_Album = Delete_Album((*MIT).second);
					cout << Deleted_Album.first << " " << Deleted_Album.second << "\n";
					Cur_Album->Child.erase(MIT);
				}
				else {
					cout << 0 << " " << 0 << "\n";
				}
			}
			else {
				// ���� �ٹ�(Cur_Album)�� �����ִ� �ٹ� �� S�� �̸��� ���� �ٹ��� �����Ѵٸ� �ش� �ٹ��� �����Ѵ�.
				if (Cur_Album->Child.find(S) != Cur_Album->Child.end()) {
					MIT = Cur_Album->Child.find(S);
					Deleted_Album = Delete_Album((*MIT).second);
					cout << Deleted_Album.first << " " << Deleted_Album.second << "\n";
					Cur_Album->Child.erase(MIT);
				}
				else {
					cout << 0 << " " << 0 << "\n";
				}
			}
		}
		else if (CMD == "insert") {
			string S;
			cin >> S;
			if (Cur_Album->Photo.find(S) != Cur_Album->Photo.end()) {
				/*
					���� �ٹ�(Cur_Album)���� set.find() �Լ��� �̿��ؼ� ������� �ϴ� ������ �̸� S�� �̹� �ִ��� ã�´�.
					������ duplicated photo name�� ����Ѵ�.
				*/
				cout << "duplicated photo name" << "\n";
			}
			else {
				Cur_Album->Photo.insert(S);
			}
		}
		else if (CMD == "delete") {
			int Deleted_Photo = 0;
			string S;
			cin >> S;
			if (S == "-1") {
				// ���� �ٹ�(Cur_Album)�� �����ִ� ������ �����Ѵٸ�, �̸��� ���������� ���� ���� ������ �����Ѵ�.
				if (Cur_Album->Photo.size() > 0) {
					SIT = Cur_Album->Photo.begin();
					Cur_Album->Photo.erase(SIT);
					Deleted_Photo++;
				}
			}
			else if (S == "0") {
				// ���� �ٹ�(Cur_Album)�� �����ִ� ��� ������ �����Ѵ�.
				if (Cur_Album->Photo.size() > 0) {
					SIT = Cur_Album->Photo.begin();
					for (SIT = Cur_Album->Photo.begin(); SIT != Cur_Album->Photo.end(); SIT++) {
						Deleted_Photo++;
					}
					Cur_Album->Photo.clear();
				}
			}
			else if (S == "1") {
				// ���� �ٹ�(Cur_Album)�� �����ִ� ������ �����Ѵٸ�, �̸��� ���������� ���� ���� ������ �����Ѵ�.
				if (Cur_Album->Photo.size() > 0) {
					SIT = Cur_Album->Photo.end();
					SIT--;
					Cur_Album->Photo.erase(SIT);
					Deleted_Photo++;
				}
			}
			else {
				// ���� �ٹ�(Cur_Album)�� �����ִ� ���� �� S�� �̸��� ���� ������ �����Ѵٸ� �� ������ �����Ѵ�.
				if (Cur_Album->Photo.find(S) != Cur_Album->Photo.end()) {
					SIT = Cur_Album->Photo.find(S);
					Cur_Album->Photo.erase(SIT);
					Deleted_Photo++;
				}
			}
			cout << Deleted_Photo << "\n";
		}
		else if (CMD == "ca") {
			string S;
			cin >> S;
			if (S == "..") {
				// ���� �ٹ��� �ֻ��� �ٹ��� album�̶�� �̵����� �ʰ�, �װ� �ƴ϶�� ���� �ٹ����� �̵��Ѵ�.
				if (Cur_Album->Name != "album") {
					Cur_Album = Cur_Album->Parent;
				}
			}
			else if (S == "/") {
				// �ֻ��� �ٹ��� album���� �̵��Ѵ�.
				Cur_Album = Root;
			}
			else {
				// ���� �ٹ��� �����ִ� �ٹ� �� S�� �̸��� ���� �ٹ����� �̵��ϸ�, S�� ���ٸ� ���� �ٹ��� �ӹ�����.
				if (Cur_Album->Child.find(S) != Cur_Album->Child.end()) {
					MIT = Cur_Album->Child.find(S);
					Cur_Album = (*MIT).second;
				}
			}
			cout << Cur_Album->Name << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}