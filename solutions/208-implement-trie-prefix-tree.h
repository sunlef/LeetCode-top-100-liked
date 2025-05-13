// https://leetcode.cn/problems/implement-trie-prefix-tree
class Trie {
 public:
  Trie() : next_{} {}

  void insert(string word) {
    Trie *ptr = this;
    for (char c : word) {
      int k = c - 'a';
      if (!ptr->next_[k]) {
        ptr->next_[k] = new Trie();
      }
      ptr = ptr->next_[k];
    }
    if (!ptr->next_[26]) {
      ptr->next_[26] = new Trie();
    }
  }

  bool search(string word) {
    Trie *ptr = this;
    for (char c : word) {
      int k = c - 'a';
      if (!ptr->next_[k]) {
        return false;
      }
      ptr = ptr->next_[k];
    }
    return bool(ptr->next_[26]);
  }

  bool startsWith(string prefix) {
    Trie *ptr = this;
    for (char c : prefix) {
      int k = c - 'a';
      if (!ptr->next_[k]) {
        return false;
      }
      ptr = ptr->next_[k];
    }
    return true;
  }

 private:
  Trie *next_[27];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */