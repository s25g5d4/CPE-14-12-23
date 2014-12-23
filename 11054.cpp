#include <iostream>

int main()
{
    using namespace std;
    
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        
        long long now = 0;
        long long count = 0;
        
        while (n--) {
            int a;
            cin >> a;
            
            now += a;
            count += (now < 0 ? -now : now);
        }
        
        cout << count << endl;
    }
    
    return 0;
}