#include <iostream>

using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(s.length()==1)
            return s;
        string outline;
        int size=numRows*2-2;
        for(int i=0;i<size;i++)
        {
            for(int j=i;j<s.length();j=+size)
            {
                outline.push_back(s[j]);
                if(i==numRows/2+1)
                    outline.push_back(s[j+numRows/2+1]);
            }
        }
        return outline;
    }
};

int main()
{
    Solution slu;
    string output=slu.convert("PAYPALISHIRING",3);
    cout<<output;
    return 0;
}