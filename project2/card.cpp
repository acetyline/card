#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

class card
{
public:
    vector<int> skillcards;
    vector<int> firstcards;
    vector<int> basiccards;
    int skillptr = 0;
    int basicptr = 0;
    //1:<<,2:>>,3:~,4:l,5:C
    void init(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            skillcards.push_back(1);
            skillcards.push_back(2);
            skillcards.push_back(2);
            skillcards.push_back(3);
            skillcards.push_back(4);
            skillcards.push_back(5);
            skillcards.push_back(5);
        }
        random_shuffle(skillcards.begin(), skillcards.end());

    }
    void getfirst(int n)
    {   
        for (int i = 1; i <= 511;i++)
        {
            basiccards.push_back(i);
        }
        vector<int> a;
        for (int i = 1; i <= 31;i++)
        {
            a.push_back(i);
        }
        random_shuffle(a.begin(), a.end());
        for (int i = 0; i < n;i++)
        {
            firstcards.push_back(a[i]);
            basiccards.erase(basiccards.begin()+a[i]-1);
        }
    }
    //<< 
    void left(int &value)
    //value：玩家数值
	{
		value<<=1;
	}
	//>> 
    void right(int &value)
    //value：玩家数值
	{
		value>>=1;
	}
	//>>
    void left(int &value)
    //value：玩家数值
    {
	value<<=1;
    }
    //~
    void opposite(int &value)
    //value：玩家数值
    {
        for(int i=10;~i;i--)
        {
	    if(value&(1<<i))
	    {
	        value^=(1<<(i+1)-1);
	        break;
	    }
	}
    }
    //I
    void insert(int &value,int k)
    //value：玩家数值，k:更改数位 
    {
        value^=(1<<k);
    }
    //C
    void clear(int &value,int k)
    //value：玩家数值，k:更改数位
    {
	value^=(1<<k);
    }
};
