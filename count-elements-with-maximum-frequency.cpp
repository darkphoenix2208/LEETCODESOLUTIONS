// Problem  : Count Elements With Maximum Frequency
// Difficulty: Easy
// Tags     : Array, Hash Table, Counting
// URL      : https://leetcode.com/problems/count-elements-with-maximum-frequency/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────



class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        
        for (int num : nums) {
            freq[num]++;
        }

        
        int maxFreq = 0;
        for (auto& pair : freq) {
            maxFreq = max(maxFreq, pair.second);
        }

    
        int sum = 0;
        for (auto& pair : freq) {
            if (pair.second == maxFreq) {
                sum += pair.second;
            }
        }

        return sum;
    }
};


// Auto-commit update
