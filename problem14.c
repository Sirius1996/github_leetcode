char* longestCommonPrefix(char** strs, int strsSize) 
{
	int i;
	int j;
	int k;
	char temp;
	char result[32] = {0};
    
    if(strsSize == 0)
        return "";
    
    for(j = 0; strs[j] != '\0'; j++)
	{
    	for(i = 0; i < strsSize; i++)
    	{
    		if(strs[i+1][j] < strs[i][j])
    		{
    			temp = strs[i+1][j];
    			strs[i+1][j] = strs[i][j];
    			strs[i][j] = temp;
			}
		}
	}
	
	for(j = 0; strs[j] != '\0'; j++)
	{
		for(i = 0; i <strsSize; i++)
		{
			temp = strs[0][j];
			if(strs[i][j] != strs[0][j])
			{
				break;
			}
		}
	}
	
	for(k = 0; k < i; k++)
		result[k] = strs[0][k];
	
	return result;
}

