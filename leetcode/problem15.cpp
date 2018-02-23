#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> judgetemp1,judgetemp2;
        int judge=0;
        if(nums.size()<3)
            return res;
        for(int i=0;i<nums.size()-2;i++)
            for(int j=i+1;j<nums.size()-1;j++)
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        judge=0;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        
                        //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                        for(auto a=res.begin();a!=res.end();a++)
                        {
                            judgetemp2.clear();
                            judgetemp2=*a;
                            if(judge==3)
                                break;
                            else
                            {
                                judge=0;
                                judgetemp1.clear();
                                judgetemp1.push_back(nums[i]);
                                judgetemp1.push_back(nums[j]);
                                judgetemp1.push_back(nums[k]);
                            }
                            //cout<<"进到循环1"<<endl;
                            for(auto b=(judgetemp2).begin();b!=(judgetemp2).end();b++)
                            {
                                
                                //cout<<"进到循环"<<endl;
                                for(auto ptr=judgetemp1.begin();ptr!=judgetemp1.end();ptr++)
                                {
                                    if(*ptr==*b)
                                    {
                                        judge++;
                                        judgetemp1.erase(ptr);
                                        judgetemp2.erase(a);
                                        a--;
                                        ptr--;
                                    }
                                }
                            }                            
                        }
                        cout<<"judge is: "<<judge<<endl;
                        int tempint;
                        for(auto it=temp.begin();it!=temp.end()-1;it++)
                        {
                            if(*it>*(it+1))//交换大小
                            {
                                tempint=*it;
                                *it=*(it+1);
                                *(it+1)=tempint;
                            }
                        }

                        if(judge<3)
                            res.push_back(temp);
                        //res.push_back(temp);
                        temp.clear();
                    }
                        
                }
        return res;
    }
};

int main()
{
    vector<int> test={0,3,0,1,1,-1,-5,-5,3,-3,-3,0};
    Solution res;
    vector<vector<int>> outRes=res.threeSum(test);
    for(auto it1=outRes.begin();it1!=outRes.end();it1++)
    {
        for(auto it2=(*it1).begin();it2!=(*it1).end();it2++)
            cout<<*it2<<" ";
        cout<<endl;
    }

    return 0;
}




