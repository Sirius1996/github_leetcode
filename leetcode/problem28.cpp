class Solution {
public:
    int strStr(string haystack, string needle) {
        auto ptr1=haystack.begin();
        auto ptr2=needle.begin();
        if(haystack.size()==0&&needle.size()==0)
            return 0;
        if(haystack.size()==0)
            return -1;
        if(needle.size()==0)
            return 0;
        int count=0,res,flag=0;
        for(;ptr1!=haystack.end();ptr1++)
        {
            if(*ptr1==*ptr2)
            {
                if(flag==0)
                {
                    flag=1;
                    res=count;
                }
                if(ptr2+1==needle.end()&&flag==1)
                    return res;
                ptr2++;
            }
            else
            {
                ptr2=needle.begin();
                if(flag==1)
                {
                    ptr1=haystack.begin()+res;
                    count=res;
                    flag=0;
                }
            }
            count++;
        }
        return -1;
    }
};