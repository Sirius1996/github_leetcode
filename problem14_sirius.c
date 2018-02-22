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
    }
    return common;
}