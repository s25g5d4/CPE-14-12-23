#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    
    int n;
    cin >> n;
    
    for (int case_num = 1; case_num <= n; ++case_num) {
        cout << "Case " << case_num << ":" << endl;
        
        int char_cost[36];
        for (int i = 0; i < 36; ++i) {
            cin >> char_cost[i];
        }
        
        int query_count;
        cin >> query_count;
        
        while (query_count--) {
            int query_num;
            cin >> query_num;
            
            vector< pair<int, int> > query_result;
            
            for (int i = 2; i <= 36; ++i) {
                int _num = query_num;
                int query_cost = 0;
                
                while (_num > 0) {
                    query_cost += char_cost[_num % i];
                    _num /= i;
                }
                
                query_result.push_back(make_pair<int, int>(query_cost, i));
            }
            
            stable_sort(query_result.begin(), query_result.end());
            
            cout << "Cheapest base(s) for number " << query_num << ":";
            
            vector< pair<int, int> >::iterator it;
            for (it = query_result.begin(); it != query_result.end(); ++it) {
                if (it->first == query_result[0].first) {
                    cout << " " << it->second;
                }
                else {
                    break;
                }
            }
            
            cout << endl;
        }
        
        if (case_num < n) {
            cout << endl;
        }
    }
}
