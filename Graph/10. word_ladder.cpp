#include<string>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        q.push("0");
        int ladder=1;
        while(!q.empty())
        {
            int n=q.size();
            //incrementing ladder after every level(method-1)
            for(int k=0;k<n;k++)
            {
                string word=q.front();
                q.pop();
                if(word==endWord)
                    return ladder;
                dict.erase(word);
                for(int j=0;j<word.size();j++)
                {
                    char c=word[j];
                    for(int i=0;i<26;i++)
                    {
                        word[j]='a'+i;
                        if(dict.find(word)!=dict.end())
                            q.push(word);
                    }
                    word[j]=c;
                }
            }
            ladder++;
        }
        //incrementing ladder after every level(method-2)
        // while(!q.empty())
        // {
        //     string word=q.front();
        //     q.pop();
        //     if(word==endWord)
        //         return ladder;
        //     if(!q.empty()&&word=="0")
        //     {
        //         ladder++;
        //         q.push("0");
        //         continue;
        //     }
        //     dict.erase(word);
        //     for(int j=0;j<word.size();j++)
        //     {
        //         char c=word[j];
        //         for(int i=0;i<26;i++)
        //         {
        //             word[j]='a'+i;
        //             if(dict.find(word)!=dict.end())
        //                 q.push(word);
        //         }
        //         word[j]=c;
        //     }
        // }
        return 0;
    }
};