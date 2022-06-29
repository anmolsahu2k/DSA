#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    //can also use queue
    string s1 = "ABBAABBBA";
    string s2 = "BAABBBAAB";
    if (s1.size() != s2.size())
    {
        cout << "Not Equal";
        return 0;
    }
    string temp = s1 + s1;
    if (temp.find(s2) != string::npos)
        cout << "Equal";
    else
        cout << "Not Equal";

    return 0;
}
