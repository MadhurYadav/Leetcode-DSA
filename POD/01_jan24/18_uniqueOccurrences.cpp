class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
          unordered_map<int, int> count;
        for (int num : arr) {
            count[num]++;
        }
        unordered_set<int> uniqueCounts;
        for (auto [key, value] : count) {
            if (uniqueCounts.count(value)) return false;
            uniqueCounts.insert(value);
        }
        return true;
    }
};