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
					현재 앨범(Cur_Album)에서 map.find() 함수를 이용해서 만들고자 하는 앨범의 이름 S가 이미 있는지 찾는다.
					있으면 duplicated album name을 출력한다.
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
				// 현재 앨범(Cur_Album)에 속해있는 앨범이 존재한다면, 이름이 사전순으로 가장 빠른 앨범을 삭제한다.
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
				// 현재 앨범(Cur_Album)에 속해있는 모든 앨범을 삭제한다.
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
				// 현재 앨범(Cur_Album)에 속해있는 앨범이 존재한다면, 이름이 사전순으로 가장 늦은 앨범을 삭제한다.
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
				// 현재 앨범(Cur_Album)에 속해있는 앨범 중 S의 이름을 가진 앨범이 존재한다면 해당 앨범을 삭제한다.
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
					현재 앨범(Cur_Album)에서 set.find() 함수를 이용해서 만들고자 하는 사진의 이름 S가 이미 있는지 찾는다.
					있으면 duplicated photo name을 출력한다.
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
				// 현재 앨범(Cur_Album)에 속해있는 사진이 존재한다면, 이름이 사전순으로 가장 빠른 사진을 삭제한다.
				if (Cur_Album->Photo.size() > 0) {
					SIT = Cur_Album->Photo.begin();
					Cur_Album->Photo.erase(SIT);
					Deleted_Photo++;
				}
			}
			else if (S == "0") {
				// 현재 앨범(Cur_Album)에 속해있는 모든 사진을 삭제한다.
				if (Cur_Album->Photo.size() > 0) {
					SIT = Cur_Album->Photo.begin();
					for (SIT = Cur_Album->Photo.begin(); SIT != Cur_Album->Photo.end(); SIT++) {
						Deleted_Photo++;
					}
					Cur_Album->Photo.clear();
				}
			}
			else if (S == "1") {
				// 현재 앨범(Cur_Album)에 속해있는 사진이 존재한다면, 이름이 사전순으로 가장 늦은 사진을 삭제한다.
				if (Cur_Album->Photo.size() > 0) {
					SIT = Cur_Album->Photo.end();
					SIT--;
					Cur_Album->Photo.erase(SIT);
					Deleted_Photo++;
				}
			}
			else {
				// 현재 앨범(Cur_Album)에 속해있는 사진 중 S의 이름을 가진 사진이 존재한다면 그 사진을 삭제한다.
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
				// 현재 앨범이 최상위 앨범인 album이라면 이동하지 않고, 그게 아니라면 상위 앨범으로 이동한다.
				if (Cur_Album->Name != "album") {
					Cur_Album = Cur_Album->Parent;
				}
			}
			else if (S == "/") {
				// 최상위 앨범인 album으로 이동한다.
				Cur_Album = Root;
			}
			else {
				// 현재 앨범에 속해있는 앨범 중 S의 이름을 가진 앨범으로 이동하며, S가 없다면 현재 앨범에 머무른다.
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