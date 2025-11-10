#include<bits/stdc++.h>
#include "../myinclude/autocomplete.hpp"
#include "../myinclude/fuzzysearch.hpp"
#include "../myinclude/trie.hpp"
using namespace std;
#define int long long
// Function to find the similiar prefixes in order to indetify typos
void searchRecursive(Node* node, const string& word, const string& query, vector<int>& prevRow, int maxDist,vector<FuzzyMatch>& results) {

    if (node == nullptr) return;

    int m = query.size();
    vector<int> currRow(m + 1);
    currRow[0] = prevRow[0] + 1;

    // Fill DP row
    for (int j = 1; j <= m; ++j) {
        int insertCost = currRow[j - 1] + 1;
        int deleteCost = prevRow[j] + 1;
        int replaceCost = prevRow[j - 1] + (word.back() == query[j - 1] ? 0 : 1);
        currRow[j] = min({insertCost, deleteCost, replaceCost});
    }

    // If this is a valid word, save it WITH its frequency
    if (node->flag && currRow[m] <= maxDist) {
        // node->frequency MUST exist in your Node struct
        results.push_back({word, currRow[m], node->frequency});
    }

    // Prune branch
    if (*min_element(currRow.begin(), currRow.end()) > maxDist) {
        return;
    }

    // Explore child nodes
    for (int c = 0; c < 26; ++c) {
        if (node->links[c] != nullptr) {
            char nextChar = 'a' + c;
            searchRecursive(node->links[c], word + nextChar, query, currRow, maxDist, results);
        }
    }
}