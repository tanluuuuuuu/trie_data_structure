#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <stdio.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
#include <cctype>


typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define vt vector

const int ALPHABET_SIZE = 26;
int ans = -1;

struct TrieNode {
	TrieNode *childNode[ALPHABET_SIZE];
	bool isLeafNode;

	TrieNode() {
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			childNode[i] = NULL;
		}
		isLeafNode = false;
	}
};

void insert(TrieNode* root, string s)
{
	TrieNode* cur = root;
	for (auto c : s)
	{
		int id = c - 'a';
		if (cur->childNode[id] == NULL)
		{
			cur->childNode[id] = new TrieNode();
		}
		cur = cur->childNode[id];
	}
	cur->isLeafNode = true;
}

void search(TrieNode*, int);
void search(TrieNode* root, int count)
{
	if (root->isLeafNode == true)
	{
		count += 1;
		ans = max(ans, count);
	}
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->childNode[i] != NULL)
		{
			search(root->childNode[i], count);
		}
	}
}

int main()
{
	TrieNode* root = new TrieNode();

	ll n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		insert(root, s);
	}
	search(root, 0);
	cout << ans;
}
