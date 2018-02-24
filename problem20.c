#include<stdio.h>
#include<stdlib.h>


bool isValid(char* s) {
    int count=0;
    for(int i=0;s[i]!='\0';i++)
    count=i;
    char* cmp=(char*)malloc(count*sizeof(char));
    for(int i=0;i<count;i++)
        cmp[i]='\0';
    count=0;

    
    for(int j=0;s[j]!='\0';j++)
    {
        if(s[j]=='('||s[j]=='['||s[j]=='{')
        {
            cmp[count]=s[j];
            count++;
        }
        else if((s[j]==')'&&count>=0&&cmp[count]=='(')||(s[j]==']'&&count>=0&&cmp[count]=='[')||(s[j]=='}'&&count>=0&&cmp[count]=='{'))
        {
            cmp[count]='\0';
            count--;
        }
        else
            return false;
    }
    if(cmp[0]!='\0')
        return false;
    return true; 
}

int main()
{
    char* s="()";
    bool judge=isValid(s);
    if(judge)
        printf("true");
    else
        printf("false");
    return 0;
}


