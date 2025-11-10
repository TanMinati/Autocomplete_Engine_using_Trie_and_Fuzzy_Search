#include<bits/stdc++.h>
#include "../myinclude/trie.hpp"
#include "../myinclude/autocomplete.hpp"
#include "../myinclude/fuzzysearch.hpp"
using namespace std;
#define int long long
// Comparator function for ranking the words;
struct MatchComparator {
    bool operator()(const FuzzyMatch& a, const FuzzyMatch& b) const {
        // 1. Smallest distance first
        if (a.distance != b.distance) {
            return a.distance < b.distance;
        }
        // 2. Highest frequency second
        if (a.frequency != b.frequency) {
            return a.frequency > b.frequency;
        }
        // 3. Alphabetical third
        return a.word < b.word;
    }
};
// Function for autocompleting the prefix
vector<string> autocomplete(const string& query, int maxDist) {
    // This vector will hold all possible matches
    vector<FuzzyMatch> all_matches; 
    Node* root = trie.getroot();

    for (int i = 0; i < 26; i++) {
        vector<int> prevRow(query.size() + 1);
        for (int j = 0; j < prevRow.size(); ++j) {
            prevRow[j] = j;
        }

        string word_prefix;
        char nextChar = 'a' + i;
        if (root->links[i]) { // Check if child exists before recursing
            searchRecursive(root->links[i], word_prefix + nextChar, query, prevRow, maxDist, all_matches);
        }
    }

    // Sort all the matches using our custom comparator
    sort(all_matches.begin(), all_matches.end(), MatchComparator{});

    // Extract just the top 10 words
    vector<string> top_10_words;
    for (int i = 0; i < all_matches.size() && i < 10; ++i) {
        top_10_words.push_back(all_matches[i].word);
    }

    return top_10_words;
}