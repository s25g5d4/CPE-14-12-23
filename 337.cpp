#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    int case_num = 1;
    
    while(1) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        
        cin.ignore();
        
        string output[10];
        for (int i = 0; i < 10; ++i) {
            output[i] = "          ";
        }
        
        int cursor[2] = {0, 0};
        bool override_mode = true;
        
        while (n--) {
            string control;
            getline(cin, control, '\n');
            
            string::iterator it;
            for (it = control.begin(); it != control.end(); ++it) {
                if (*it == '^') {
                    ++it;
                    bool write_char = false;
                    
                    switch (*it) {
                    case 'u':
                        cursor[0] = cursor[0] > 0 ? cursor[0] - 1 : 0;
                        break;
                        
                    case 'd':
                        cursor[0] = cursor[0] < 9 ? cursor[0] + 1 : 9;
                        break;
                        
                    case 'l':
                        cursor[1] = cursor[1] > 0 ? cursor[1] - 1 : 0;
                        break;
                        
                    case 'r':
                        cursor[1] = cursor[1] < 9 ? cursor[1] + 1 : 9;
                        break;
                        
                    case 'b':
                        cursor[1] = 0;
                        break;
                        
                    case 'h':
                        cursor[0] = 0;
                        cursor[1] = 0;
                        break;
                        
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        cursor[0] = (int)(*it - '0');
                        ++it;
                        cursor[1] = (int)(*it - '0');
                        break;
                        
                    case 'i':
                        override_mode = false;
                        break;
                        
                    case 'o':
                        override_mode = true;
                        break;
                        
                    case 'c':
                        for (int i = 0; i < 10; ++i) {
                            output[i] = "          ";
                        }
                        break;
                        
                    case 'e':
                        output[cursor[0]].insert(cursor[1], 10, ' ');
                        output[cursor[0]].resize(10);
                        break;
                        
                    case '^':
                        write_char = true;
                        break;
                    }
                    
                    if (!write_char) {
                        continue;
                    }
                }
                
                if (override_mode) {
                    output[cursor[0]].replace(cursor[1], 1, 1, *it);
                }
                else {
                    output[cursor[0]].insert(cursor[1], 1, *it);
                    if (output[cursor[0]].length() > 10) {
                        output[cursor[0]].resize(10);
                    }
                }
                
                cursor[1] = cursor[1] < 9 ? cursor[1] + 1 : 9;
            }
        }
        
        cout << "Case " << case_num << endl;
        cout << "+----------+" << endl;
        for (int i = 0; i < 10; ++i) {
            cout << "|" << output[i] << "|" << endl;
        }
        cout << "+----------+" << endl;
        
        ++case_num;
    }
}