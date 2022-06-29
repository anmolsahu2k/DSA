#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s1 = "XY";
    string s2 = "12";
    string s3 = "X2Y1";
    string temp = s1 + s2;
    if(s1.length()+s2.length()!=s3.length())
    {
        cout << "Not Valid";
        return 0;
    }
    sort(temp.begin(), temp.end());
    sort(s3.begin(), s3.end());
    if(s3==temp)
        cout << "Valid Shuffle";
    else
        cout << "Not Valid";
    return 0;
}