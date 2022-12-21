#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool valid_word;
    TrieNode *children[26];

    TrieNode()
    {
        valid_word = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode;
    }

    void insert(string word)
    {
        int m = word.size();
        
    }

    bool search(string word)
    {
    }

    bool startsWith(string prefix)
    {
    }
};