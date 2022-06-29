//SEE IMAGE
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool dictionaryCheck(string s)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int dictionarySize = sizeof(dictionary)/sizeof(dictionary[0]);
    for(int i=0;i<dictionarySize;i++)
    {
        if(dictionary[i].compare(s)==0)
            return true;
    }
    return false;
}

bool wordBreak(string str)
{
    int size=str.length();
    if(size==0)
        return true;
    //check each substring in str(i,il,ili,ilik,.....) with dictionary
    //if any substring present in dictionary, check remaining substrings by calling recursively 
    for(int i=1;i<=size;i++)
    {
        //dictionaryCheck(i) && wordBreak(like)->[dictionaryCheck(like) && wordBreak()]->true
        if(dictionaryCheck(str.substr(0,i)) && wordBreak(str.substr(i,size-i)))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout<<wordBreak("ilikesamsung");
    return 0;
}