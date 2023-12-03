class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while (l < r) {
            if (isVowel(s[l]) && isVowel(s[r])) {
                swap(s[l], s[r]);
                l++, r--;
            } else if (isVowel(s[l]) && !isVowel(s[r])) {
                r--;
            } else if (isVowel(s[r]) && !isVowel(s[l])) {
                l++;
            } else {
                l++, r--;
            }
        }
        return s;
    }
};