class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int>freq(26,0);
        for(int i = 0;i<b.size();++i){
            freq[b[i]-'a']++;
        }
        for(int i =0;i<a.size();++i){
            if(freq[a[i]-'a']){
                freq[a[i]-'a']--;
            }else{
                return false;
            }
        }
        return true;
    }
};