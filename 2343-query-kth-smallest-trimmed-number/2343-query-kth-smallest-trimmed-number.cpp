class Solution {
public:
vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    int n = nums[0].size();
    vector<pair<string, int>> pairs;
    for (int i = 0; i < nums.size(); ++i)
        pairs.push_back({ nums[i], i });
    vector<int> res;
    for(auto &q : queries) {
        int k = q[0], trim = q[1];
        nth_element(begin(pairs), begin(pairs) + k - 1, end(pairs), [&](const auto &a, const auto &b){
            int cmp = a.first.compare(n - trim, string::npos, b.first, n - trim, string::npos);
            return cmp == 0 ? a.second < b.second : cmp < 0;
        });
        res.push_back(pairs[k - 1].second);
    }
    return res;
}
};