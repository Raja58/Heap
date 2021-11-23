// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        23 Nov 2021
//  @Detail  :        Find K Closest Elements (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    struct detail{
        int dif;
        int val;
        bool operator<(const detail &x) const{
            if(dif == x.dif)
                return val < x.val;
            return dif < x.dif;
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<detail> cache;
        for(int i = 0; i < k; i++)
            cache.push({abs(arr[i] - x), arr[i]});
        for(int i = k; i < arr.size(); i++)
        {
            detail temp = cache.top();
            if(abs(arr[i] - x) > temp.dif)
                continue;
            if(abs(arr[i] - x) == temp.dif && temp.val < arr[i])
                continue;
            cache.pop();
            cache.push({abs(arr[i] - x), arr[i]});
        }
        vector<int> result;
        while(!cache.empty())
        {
            detail temp = cache.top();  cache.pop();
            result.push_back(temp.val);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
