class Solution(object):
    def twoSum(self, nums, target):
        D = {}
        for i in range(len(nums)):
            if target - nums[i] in D :
                return [i,D[target - nums[i]]]
            D[nums[i]] = i