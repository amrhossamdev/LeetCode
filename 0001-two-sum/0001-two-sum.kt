class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val freq = HashMap<Int, Int>()
        
        val n = nums.size
        for (i in 0 until n) {
            val have = target - nums[i]
            if (freq.containsKey(have)) {
                return intArrayOf(freq[have]!!, i)
            }
            freq[nums[i]] = i
        }
        
        return intArrayOf(0, 0)
    }
}