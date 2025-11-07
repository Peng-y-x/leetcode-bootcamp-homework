class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for(int n : nums){
            freq[n]++;
        }
        auto cmp = [](pair<int, int>& a, pair<int, int>& b){
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);

        for(auto& p : freq){
            maxHeap.push(p);
        }
        for(int i = 0; i < k && !maxHeap.empty(); i++){
            auto top = maxHeap.top();
            ans.push_back(top.first);
            maxHeap.pop();
        }
        return ans;
    }
};
