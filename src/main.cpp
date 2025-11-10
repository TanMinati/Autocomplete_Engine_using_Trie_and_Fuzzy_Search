#include<bits/stdc++.h>
#include "../myinclude/trie.hpp"
#include "../myinclude/autocomplete.hpp"
#include "../myinclude/fuzzysearch.hpp"
#include "../myinclude/buildtrie.hpp"
#define int long long
using namespace std;
const int MAX_DIST=2; //Max Edit Distance to be considered
Trie trie;
int32_t main(){
    build();
    cout<<"Enter the number of prefix you would like to enter:"<<endl;
    int t;
    cin>>t;
    while(t--){
        cout<<"Enter the prefix:"<<endl;
        string prefix;
        cin>>prefix;
        cout<<"Closest matches are:"<<endl;
        for(auto it:autocomplete(prefix,MAX_DIST)){
            cout<<it<<endl;
        }
    }
}