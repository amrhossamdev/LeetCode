class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    int n = pattern.size();
    map<char, set<string>> inDegreeChar;
    map<string, set<char>> inDegreeWord;
    string word = "";
    vector<string>words;
    for (auto x : s) {
      if (x == ' ') {
        words.push_back(word);
        word = "";
      } else {
        word += x;
      }
    }
    words.push_back(word);
    if(words.size() != pattern.size())return false;
    for (int i = 0; i < n; ++i) {
  
      inDegreeChar[pattern[i]].insert(words[i]);
      inDegreeWord[words[i]].insert(pattern[i]);
    }
    for (auto i : inDegreeChar) {
      
      if (i.second.size() > 1) return false;
    }
       for (auto i : inDegreeWord) {
      
      if (i.second.size() > 1) return false;
    }
    return true;
  }
};