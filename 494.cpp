#include <iostream>

int main()
{
    using namespace std;
    
    char input = cin.get();
    bool is_word = false;
    int count = 0;
    
    while (!cin.eof()) {
        if ((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z')) {
            is_word = true;
        }
        else {
            if (is_word) {
                ++count;
            }
            
            is_word = false;
            
            if (input == '\n') {
                cout << count << endl;
                count = 0;
            }
        }
        
        input = cin.get();
    }
    
    if (count > 0) {
        cout << count << endl;
    }
    
    return 0;
}