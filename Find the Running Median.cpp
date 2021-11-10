// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        10 Nov 2021
//  @Detail  :        Find the Running Median (HackerRank)
//  ============================
//  -->

vector<double> runningMedian(vector<int> a) {
    vector<double> result;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    left.push(INT_MIN); right.push(INT_MAX);
    for(int &z : a)
    {
        int n = left.size(), m = right.size();
        if(n == m)
        {
            left.push(z);
            if(left.top() > right.top())
            {
                int a = left.top(), b = right.top();
                left.pop();    right.pop();
                left.push(b);   right.push(a);
            }
            result.push_back((double)left.top());
        }
        else
        {
            right.push(z);
            if(left.top() > right.top())
            {
                int a = left.top(), b = right.top();
                left.pop();    right.pop();
                left.push(b);   right.push(a);
            }
            result.push_back((double)(left.top() + right.top()) / 2.0);
        }
    }
    return result;
}
