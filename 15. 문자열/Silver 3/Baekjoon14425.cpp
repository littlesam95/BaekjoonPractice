#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <climits>
#include <algorithm>
#define MAX 26

using namespace std;
// 트라이(Trie)로 풀기
struct Trie {
	Trie *node[MAX];
	bool is_finish;

	Trie() {
		fill(node, node + MAX, nullptr);
		is_finish = false;
	}
	~Trie() {
		for (int i = 0; i < MAX; i++) {
			delete node[i];
		}
	}
	void insert(char *word) {
		if (*word == '\0') {
			is_finish = true;
			return;
		}
		int word_idx = *word - 'a';
		if (node[word_idx] == NULL) {
			node[word_idx] = new Trie();
		}
		node[word_idx]->insert(word + 1);
	}
};

int N, M;

bool find(Trie* trie, char *word) {
	bool res = false;
	if (*word == '\0') {
		return trie->is_finish;
	}
	int word_idx = *word - 'a';
	if (trie->node[word_idx]) {
		return find(trie->node[word_idx], word + 1);
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	Trie *root = new Trie;
	int answer = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		char S[501];
		cin >> S;
		root->insert(S);
	}
	for (int i = 0; i < M; i++) {
		char S[501];
		cin >> S;
		if (find(root, S)) {
			answer++;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}