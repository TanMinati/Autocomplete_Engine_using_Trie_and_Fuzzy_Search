#ifndef FUZZYSEARCH_HPP
#define FUZZYSEARCH_HPP

#include<bits/stdc++.h>
#include "../myinclude/trie.hpp"
using namespace std;
#define int long long

void searchRecursive(Node* node, const string& word, const string& query,vector<int>& prevRow, int maxDist,vector<FuzzyMatch>& results);

#endif