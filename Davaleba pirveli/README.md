# დავალება I

*ათობითი რიცხვის მანიპულირების კოდი*

**1. მთავარი ფუნქცია პოინტერებით**

```cpp
string dectobin(int *x) {
    string bin;
    while (*x > 0) {
        bin += to_string(*x % 2);
        *x = *x / 2;
    }

    return bin;
}
```
ეს ფუნქცია პარამეტრად იღებს ინტეჯერის მისამართს და აბრუნებს
ორობითი რიცხვის სტრინგს.

**2. ფუნქციის გამოძახება**
```cpp
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//////////დავალება I ათობითი რიცხვის ორობითში გადაყვანა////////////////////////


string dectobin(int *x);
int main() {
    int a;
    cout << "Enter decimal number:";
    cin >> a;
    cout << "Binary number of " << a << " is " << dectobin(&a);
    return 0;
}
```
რიცხვის შეყვანის შემდეგ კონსოლში გვექნება შემდეგი შედეგი
```
Enter decimal number:32
Binary number of 32 is 000001
```

# დავალება II

*ათობითი რიცხვის შესაბამისი ერთის და ორის კომპლემენტი*

**1.მთავარი ფუნქცია**
```cpp
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
```
ეს ფუნქცია იღებას ორობით რიცხვს ამ შემთხვევაში ის არის სტრინგი რომელიც მივიღე წინა ფუნქციიდან და გამოაქვს ათობითი რიცხვის შესაბამისი ერთის და ორის კომპლემენტი

**2. ფუნქციის გამოძახება**
```cpp
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
```
ფუნქციის გამოძახების შემდეგ კონსოლში მივიღებთ შემდეგ პასუხს
```
Enter decimal number:32
Binary number is 000001
1's complement: 111110
2's complement: 111111

```