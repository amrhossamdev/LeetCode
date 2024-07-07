class Solution {
    
    fun containsDuplicate(nums: IntArray): Boolean {
        var freq = HashMap<Int,Int>();
        
        for(i in nums){
            freq[i] = freq.getOrDefault(i , 0) + 1;
        }
        
        for((_,it) in freq){
            if(it>=2)return true;
        }
        return false;
    }
}