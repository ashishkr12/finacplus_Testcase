#include <bits/stdc++.h>
using namespace std;

string caesarCipher(const string &text, int rotate) {
    string ans = "";
    for (char ch : text) {
        if ('A' <= ch && ch <= 'Z') { 
            ans += char(((ch - 'A' + rotate) % 26) + 'A');
        } else {
            ans += ch; 
        }
    }
    return ans;
}
string runLenEncoding(const string &text) {
    string encoded = "";
    int count = 1;
    
    for (int i = 1; i < text.size(); i++) {
        if (text[i] == text[i - 1]) {
            count++;
        } else {
            encoded += text[i - 1];
            if (count > 1) encoded += to_string(count);
            count = 1;
        }
    }
    
    encoded += text.back();
    if (count > 1) encoded += to_string(count);
    return encoded;
}

string specialCipher(const string &str, int rotate) {
    string ciphered = caesarCipher(str, rotate);
    return runLenEncoding(ciphered);
}

int main() {
    string str;
    int rotate;
    
    
    cout << "Enter string: ";
    cin >> str;
    
    cout << "Enter no of rotation: ";
    cin >> rotate;
    
    string ans = specialCipher(str, rotate);
    cout << "Output: " << ans << endl; 
    
    return 0;
}