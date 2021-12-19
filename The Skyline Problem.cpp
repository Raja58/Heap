// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        19 Dec 2021
//  @Detail  :        The Skyline Problem (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    struct detail{
        int xValue;
        int height;
        bool isStart;
        bool operator<(const detail &z) const{
            if(xValue != z.xValue)
                return xValue < z.xValue;
            if(isStart == true && z.isStart == true)
                return height > z.height;
            if(isStart == false && z.isStart == false)
                return height < z.height;
            return isStart;
        }
    };
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<detail> input;
        for(int i = 0; i < n; i++)
        {
            input.push_back({buildings[i][0], buildings[i][2], true});
            input.push_back({buildings[i][1], buildings[i][2], false});
        }
        sort(input.begin(), input.end());
        
        vector<vector<int>> result;
        int maxHeight = 0;
        map<int, int> cache;
        cache[0]++;
            
        for(int i = 0; i < 2 * n; i++)
        {
            if(input[i].isStart == true)
            {
                cache[input[i].height]++;
                if(maxHeight < (--cache.end()) -> first)
                {
                    maxHeight = (--cache.end()) -> first;
                    result.push_back({input[i].xValue, input[i].height});
                }
            }
            else
            {
                cache[input[i].height]--;
                if(cache[input[i].height] == 0)
                    cache.erase(input[i].height);
                if(maxHeight > (--cache.end()) -> first)
                {
                    maxHeight = (--cache.end()) -> first;
                    result.push_back({input[i].xValue, maxHeight});
                }
            }
        }
        return result;
    }
};
