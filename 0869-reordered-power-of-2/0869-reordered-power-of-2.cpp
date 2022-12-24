class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        int numOfZeros = 0;
        int nums = 0;
        for(int i =0;i<s.size();++i){
            if(s[i] == '0')++numOfZeros;
        }
        nums = s.size() - numOfZeros;
        if(numOfZeros *2 > nums)return false;
        
        sort(s.begin(),s.end());
        do{
            int x = stoi(s);
            if((x & -x) == x)return true;
        }while(next_permutation(s.begin(),s.end()));
        return false;
    }
};