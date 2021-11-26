// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        K Closest Points to Origin (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    struct detail{
        vector<int> pt;
        bool operator<(const detail &x) const{
            return pow(pt[0], 2) + pow(pt[1], 2) < pow(x.pt[0], 2) + pow(x.pt[1], 2);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<detail> cache;
        for(int i = 0; i < k; i++)
            cache.push({points[i]});
        for(int i = k; i < points.size(); i++)
        {
            cache.push({points[i]});
            cache.pop();
        }
        
        vector<vector<int>> result;
        while(!cache.empty())
        {
            detail temp = cache.top();  cache.pop();
            result.push_back(temp.pt);
        }
        return result;
    }
};
