#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int count,temp=x,res=1;
        if(x<0)
            return false;
        while(temp/res>=10)
            res=res*10;
        while(x!=0){
            temp=x/res;
            cout<<temp;
            cout<<"以及";
            cout<<x%10<<endl;
            if(temp==x%10){
                x=(x%res)/10;
                cout<<"修改之后x "<<x<<endl;
            }
            else
                return false;
            res=res/100;
        }
        return true;
    }
};

int main()
{
    Solution test;
    bool judge=test.isPalindrome(1000021);
    if(judge)
        cout<<"是回文数";
    else
        cout<<"非回文数";
    return 0;
}