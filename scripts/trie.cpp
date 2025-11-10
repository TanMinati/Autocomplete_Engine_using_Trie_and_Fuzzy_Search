#include "../myinclude/trie.hpp"
#include <bits/stdc++.h>
#define int long long
using namespace std;

// ------ Node Class Methods ------

// Check if the node contains
// a specific key (letter)
bool Node::containsKey(char ch) {
    return links[ch - 'a'] != NULL;
}

// Insert a new node with a specific
// key (letter) into the Trie
void Node::put(char ch, Node* node) {
    links[ch - 'a'] = node;
}

// Get the node with a specific
// key (letter) from the Trie
Node* Node::get(char ch) {
    return links[ch - 'a'];
}

// Set the current node
// as the end of a word
void Node::setEnd() {
    flag = true;
}

// Check if the current node
// marks the end of a word
bool Node::isEnd() {
    return flag;
}

// Returns the frequency
// of the word
int Node::getFrequency(){
    return frequency;
}
// ------ Trie Class Methods ------
// Trie class

// Constructor to initialize the
// Trie with an empty root node
Trie::Trie() {
    root = new Node();
}

// Inserts a word into the Trie
// Time Complexity O(len), where len
// is the length of the word
void Trie::insert(const string& word,const int& freq) {
    Node* node = root;
    for (int i = 0; i < word.length(); i++) {
        if (!node->containsKey(word[i])) {
            // Create a new node for
            // the letter if not present
            node->put(word[i], new Node());
        }
        // Move to the next node
        node = node->get(word[i]);
    }
    // Mark the end of the word
    node->frequency=freq;
    node->setEnd();
}

// Returns if the word
// is in the trie
bool Trie::search(const string& word) {
    Node* node = root;
    for (int i = 0; i < word.length(); i++) {
        if (!node->containsKey(word[i])) {
            // If a letter is not found,
            // the word is not in the Trie
            return false;
        }
        // Move to the next node
        node = node->get(word[i]);
    }
    // Check if the last node
    // marks the end of a word
    return node->isEnd();
}

// Returns if there is any word in the
// trie that starts with the given prefix
bool Trie::startsWith(const string& prefix) {
    Node* node = root;
    for (int i = 0; i < prefix.length(); i++) {
        if (!node->containsKey(prefix[i])) {
            // If a letter is not found, there is
            // no word with the given prefix
            return false;
        }
        // Move to the next node
        node = node->get(prefix[i]);
    }
    // The prefix is found in the Trie
    return true;
}


// Return pointer to the node 
// at the end of the prefix
Node* Trie::getPrefixNode(const string &prefix){
    Node* node = root;
    for (int i = 0; i < prefix.length(); i++) {
        // check if child exists
        if (!node->containsKey(prefix[i])){
            // prefix not found
            // hence returns NULL pointer
            return nullptr;
        }
        // Move to the next node
        node = node->get(prefix[i]);
    }
    return node;
}

// Returns the root of the trie
Node* Trie::getroot(){
    return root;
}
