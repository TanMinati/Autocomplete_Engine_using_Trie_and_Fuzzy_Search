#include <fstream>
#include <sstream>
#include <iostream>
#include "../myinclude/trie.hpp"
using namespace std;
#define int long long
// Builds trie based on the text file
void build(){
    ifstream file("scripts/unigram_freq.csv");  //Opens the CSV file
    int cnt=0;
    // Handles the error in opening the file
    if (!file.is_open()) {
        cerr << "File not found!" << endl;
        return;
    }

    string line;
    getline(file, line); // skip header line

    //Getting word and its frequency and updating in trie
    while (getline(file, line)) {
        stringstream ss(line);
        string word, freqStr;
        getline(ss, word, ',');
        getline(ss, freqStr, ',');
        int freq = stoll(freqStr);
        trie.insert(word, freq);
        cnt++;
    }
}