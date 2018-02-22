#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty())
            return "";
        else if(strs.size() == 1)
            return strs[0];
        string common="";
        string tempStr="";
        auto temp1=strs[0];
        auto temp2=strs[1];
        auto strPtr1=temp1.begin();
        auto strPtr2=temp2.begin();
        int pos=2;
        while(strPtr1!=temp1.end()&&strPtr2!=temp2.end())
        {
            if(*strPtr1==*strPtr2)
                common.push_back(*strPtr1);
            strPtr1++;
            strPtr2++;
        }
        temp2=strs[2];
        while(pos<strs.size())
        {
            int i=0;
            auto strPtr=temp2.begin();
            auto comPtr=common.begin();
            while(strPtr!=temp2.end()&&comPtr!=common.end())
            {
                if(*comPtr!=*strPtr)
                {
                    common.erase(i,common.size()-1);
                    break;
                }
                comPtr++;
                strPtr++;
                i++;
            }
            pos++;
        }
        
        return common;
    }
};

int main()
{
    vector<string> inputstr={"abc","ab"};
    Solution test;
    cout<<test.longestCommonPrefix(inputstr)<<endl;
    return 0;
}

