#include <iostream>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
using namespace std;
string dectobin(int *x);
char flip(char c) {return (c == '0')? '1': '0';}
void printOneAndTwoCompliment(string bin);
int main() {
   int a;
   cout << "Enter decimal number:";
   cin >> a;
   string bin = dectobin(&a);
   cout << "Binary number is " << bin << endl;
   printOneAndTwoCompliment(bin);
    
    return 0;
}

// davaleba I
string dectobin(int *x) {
    //int *p = &x;
    string bin;
    while (*x > 0) {
        bin += to_string(*x % 2);
        *x = *x / 2;
    }

    return bin;
}
/// davaleba II
void printOneAndTwoCompliment(string bin) {
    int n = bin.length();
    int i;
    string ones, twos;
    ones = twos = "";
    for(i = 0; i < n; i++){
        ones += flip(bin[i]);
    }
    twos = ones;
    for (i = n-1; i > 0; i++){
        if (ones[i] == '1'){
            twos[i] = '0';
        }else {
            twos[i] = '1';
            break;
        }
    }
    
    if (i == -1) {
        twos = '1' + twos;
    }
    cout << "1's complement: " << ones << endl;
    cout << "2's complement: " << twos << endl;
}