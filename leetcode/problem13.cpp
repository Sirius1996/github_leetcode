#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int len = s.length();
        // 转换
        for(int i = 0;i < len;++i){
            if(i > 0 && map(s[i]) > map(s[i-1])){
                result += map(s[i]) - 2*map(s[i-1]);
            }
            else{
                result += map(s[i]);
            }
        }//for
        return result;
    }
private:
    int map(char r){
        switch(r){
            case 'M':return 1000;
            case 'D':return 500;
            case 'C':return 100;
            case 'L':return 50;
            case 'X':return 10;
            case 'V':return 5;
            case 'I':return 1;
            default:return 0;
        }
    }
};