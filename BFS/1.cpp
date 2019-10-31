#include <string>
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <vector>

union {
    int data;
    uint8_t rf[4];
}ar;

using namespace std;
int main(int argc, char const *argv[])
{
    vector<int>v(5,10);
    vector<int>v2(v);
    string ch = "hello";
    string::iterator it = ch.begin();
    string ch2 = "world";
    string ch3 = ch + ch2;
    cout << *it << '\n';
    for(vector<int>::iterator it = v.begin(); it < v.end();it++)
    {
        cout << *it << '\n';
    }
    for(int i = 0;i < 10;i++)
    {
        v2.push_back(i);
    }
    for(vector<int>::iterator it1 = v2.begin();it1 < v2.end();it1++)
    {
        cout << *it1 << '\n';
    }
    cout << ch3 <<'\n';
    return 0;
}
