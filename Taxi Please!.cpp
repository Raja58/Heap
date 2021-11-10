// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        10 Nov 2021
//  @Detail  :        Taxi Please! (HackerEarth)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;
#define int long long

struct detail{
    int id;
    int start;
    int end;
};

struct info{
    int taxiId;
    int endTime;
    bool operator<(const info &x) const{
        return endTime > x.endTime;
    }
};

vector<int> getTaxiId(int &n, int &m, vector<detail> &input)
{
    vector<int> result(n);
    priority_queue<int, vector<int>, greater<int>> taxi;
    for(int i = 1; i <= m; i++)
        taxi.push(i);

    priority_queue<info> cache;
    for(int i = 0; i < n; i++)
    {
        while(!cache.empty() && cache.top().endTime <= input[i].start)
        {
            taxi.push(cache.top().taxiId);
            cache.pop();
        }

        if(taxi.empty())
        {
            result[input[i].id] = -1;
            continue;
        }

        int taxiId = taxi.top(); taxi.pop();
        result[input[i].id] = taxiId;
        cache.push({taxiId, input[i].end});
    }
    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin>>n>>m;
    vector<detail> input(n);
    for(int i = 0; i < n; i++)
    {
        cin>>input[i].start;
        cin>>input[i].end;
        input[i].end += input[i].start;
        input[i].id = i;
    }

    sort(input.begin(), input.end(), [](detail &x, detail &y){return x.start < y.start;});
    vector<int> result = getTaxiId(n, m, input);
    for(int &z : result)
        cout<<z<<" ";
    return 0;
}
