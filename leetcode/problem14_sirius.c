#include<stdio.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    char* common=strs[0];
    int i,j;
    if(strsSize==0)
        return "";
    for(i=1;i<strsSize;i++)
    {
        j=0;
        while(strs[i][j]==common[j]&&common[j]&&strs[i][j])
            j++;
        common[j]='\0';
        printf("第%d趟\n",i);
    }
    return common;
}

int main()
{
    int a=0,b=0;
    char* strIn[]={"aa","ab","a"};
    printf("调用前\n");
    char* output=longestCommonPrefix(strIn,3);
    printf("调用后\n");
    printf("%s",output);
    return 0;
}