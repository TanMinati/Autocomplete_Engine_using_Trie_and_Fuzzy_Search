#ifndef TRIE_HPP
#define TRIE_HPP

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Structure for handling retrieved words
struct FuzzyMatch {
    string word;
    int distance;
    int frequency;
};

// Node structure for Trie
struct Node {
    Node* links[26];
    bool flag = false;
    int frequency=0;

    bool containsKey(char ch);
    void put(char ch, Node* node);
    Node* get(char ch);
    void setEnd();
    bool isEnd();
    int getFrequency();
};

// Trie class
class Trie {
private:
    Node* root;

public:
    Trie();

    void insert(const string& word,const int& freq);
    bool search(const string& word);
    bool startsWith(const string& prefix);
    Node* getPrefixNode(const string &prefix);
    Node* getroot();
};

extern Trie trie;
#endif // TRIE_HPP
