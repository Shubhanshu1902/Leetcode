#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool valid_word;
    vector<TrieNode*> next;

    TrieNode()
    {
        valid_word = false;
        next = vector<TrieNode*>(26,NULL);
    }
};

class Trie
{
private:
    TrieNode* find(string s){   
        TrieNode* node = root;
        for(auto c:s){
            if(!node->next[c-'a']) return NULL;
            node = node->next[c-'a'];
        }

        return node;
    }

public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode;
    }

    void insert(string word)
    {
        TrieNode* node = root;
        for(auto c: word)
        {
            if(!node->next[c-'a']) node->next[c-'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }

        node->valid_word = true;
    }

    bool search(string word)
    {
        TrieNode* node = find(word);
        return node && node->valid_word;
    }

    bool startsWith(string prefix)
    {
        TrieNode* node = find(prefix);
        return node;
    }
};