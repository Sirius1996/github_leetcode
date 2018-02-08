class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x,res=1;
        if(x<0)
            return false;
        while(temp/res>10)
            res=res*10;
        while(x!=0){
            temp=x/res;
            if(temp==x%10){
                x=(x%res)/10;
                //x=(x/10)/res;注意这里，出错点
            }
            else
                return false;
            res=res/100;
        }
        return true;
    }
};




/*class Solution {
public:
    bool isPalindrome(int x) {
        int count,temp,res;
        if(x<0)
            return false;
        while(x!=0){
            count=0;
            temp=x;
            res=1;
            while(temp>=10){
                temp=temp/10;
                count++;
            }
            if(temp==x%10){
                for(int i=0;i<count;i++)
                    res=res*10;
                x=(x/res)/10;
            }
            else
                return false;
        }
        return true;
    }
};*/