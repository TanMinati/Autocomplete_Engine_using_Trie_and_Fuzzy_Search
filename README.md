# 🚀 Autocomplete Engine with Trie and Fuzzy Search (C++)

This repository contains the C++ implementation of a high-performance, typo-tolerant autocomplete engine. It uses a **Trie (prefix tree)** for extremely fast prefix matching and integrates **fuzzy search** (based on Levenshtein distance) to provide intelligent suggestions even when the user makes spelling mistakes.

---

## 💡 How It Works

The engine combines two core concepts to provide fast and accurate suggestions.

### 1. Trie-Based Autocomplete

A Trie is a tree-like data structure perfect for prefix-based lookups.

1.  **Insertion:** All words from the dictionary are inserted into the Trie. Each node represents a character, and paths from the root to a marked "end" node represent complete words.
2.  **Search:** When a user types a prefix (e.g., "prog"), the engine traverses the Trie to the node corresponding to that prefix.
3.  **Suggestion:** It then performs a Depth-First Search (DFS) from that node to find all descendant words, which are collected as suggestions (e.g., "program", "programming", "progress").

This allows for prefix lookups in $O(L)$ time, where $L$ is the length of the prefix, regardless of the dictionary size.



### 2. Fuzzy Search Integration

To handle typos, the engine uses a fuzzy search algorithm, such as calculating the **Levenshtein distance** (edit distance).

1.  **Typo Detection:** If a user types "progran" (a typo for "program"), a standard Trie search would fail to find the prefix.
2.  **Fuzzy Match:** The engine then calculates the edit distance between the input and words in the Trie (often limited to a relevant subset for performance).
3.  **Suggestion:** Words that are within a small edit distance (e.g., 1 or 2 edits) are returned as "fuzzy" suggestions.

---

## ✨ Key Features

* **Fast Prefix Matching:** Near-instant suggestions using the Trie data structure.
* **Typo Tolerance:** Intelligently suggests correct words (e.g., "pythn" -> "python") using fuzzy search.
* **Efficient Storage:** Tries are space-efficient for large word lists with shared prefixes.
* **Modern C++:** Written in clean, efficient, and modern C++.

---

