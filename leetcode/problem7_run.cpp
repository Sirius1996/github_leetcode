#include <iostream>

using namespace std;

public:
    int reverse(int x) {
        int result=0;
        while(x!=0){
            if (abs(result) > INT_MAX / 10) //judge whether the integer overflows or not
                return 0;
            result=result*10+x%10;
            x=x/10;
        }
        return result;
    }
};

int main()
{
    Solution test;
    int outNum=test.reverse(-210);
    cout<<outNum;
    return 0;
}