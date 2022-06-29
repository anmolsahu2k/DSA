//pick and don't pick
#include <iostream>
#include <string>
using namespace std;
int subsequences(string input, string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return 0;
    }
    //pick
    subsequences(input.substr(1), output+input[0]);
    //don't pick
    subsequences(input.substr(1), output);
}

int main()
{
    string input = "abcd";
    string output = "";
    subsequences(input, output);
    return 0;
}