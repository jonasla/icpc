#include <iostream>
#include <map>

using namespace std;

const int MAXN = 60000;

struct TrieNode {
  map<char, int> sig; 
  bool final = false;
  void reset() { sig.clear(); final = false; }
};

TrieNode trie[MAXN];
int trie_n = 1;

void resetTrie() {
  trie_n = 1;
  trie[0].reset();
}

void insertar(string st) {
  int pos = 0;
  for(int i=0; i<(int)st.size(); i++) {
    if (trie[pos].sig.find(st[i]) == trie[pos].sig.end()) {
      trie[pos].sig[st[i]] = trie_n;
      trie[trie_n].reset();
      trie_n++;
    }
    pos = trie[pos].sig[st[i]];
  }
  trie[pos].final = true;
}

bool buscar(string st) {
  int pos = 0;
  for(int i=0; i<(int)st.size(); i++) {
    if (trie[pos].sig.find(st[i]) == trie[pos].sig.end())
      return false;
    pos = trie[pos].sig[st[i]];
  }
  return (trie[pos].final == true);
}

int main() {
  resetTrie();
  insertar("abra");
  insertar("abracadabra");
  cout << buscar("") << "\n";
  cout << buscar("abra") << "\n";
  cout << buscar("abraca") << "\n";
  cout << buscar("abracadabra") << "\n";
  return 0;
}
