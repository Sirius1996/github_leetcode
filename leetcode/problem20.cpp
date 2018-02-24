#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
         string cmp;
         int count=-1;
         if(s.size()%2!=0)
            return false;
         for(auto it=s.begin();it!=s.end();it++)
         {
             if(*it=='('||*it=='['||*it=='{')
             {
                cmp.push_back(*it);
                count++;
             }
            else
            {
                if((*it==')'&&count>=0&&cmp[count]=='(')||(*it==']'&&count>=0&&cmp[count]=='[')||(*it=='}'&&count>=0&&cmp[count]=='{'))
                {
                    cmp.pop_back();
                    count--;
                }
                else
                    return false;
            }
         }
        if(cmp.size()==0)
            return true;
        return false;
    }
};

int main()
{
    string input="(()";
    Solution sol;
    bool judge=sol.isValid(input);
    if(judge)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}