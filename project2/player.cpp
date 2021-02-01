#include<vector>
#include<map>
#include "card.cpp"

using namespace std;

struct Sign
{
    int au = 0;
    int ag = 0;
    int cu = 0;
    int fe = 0;
    int death = 0;
    int weight = 0;
};

class player
{
    public:
        int score = 100;
        int judge = 0;
        Sign sign;
        vector<int> skillcard;
        vector<int> basiccard;
        string printscore()
        {
            string ans;
            char q = '0';
            while(score)
            {
            q += (score %= 2);
            score /= 2;
            ans += q;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    //返回false表明出牌不符合条件
    bool usecard(int pos,bool kind)//kind=true表示基本牌,kind=false表示特殊牌
    {
        if(kind==true)
        {
            if(pos<=0||pos>basiccard.size())
                return false;
                else
                {
                    //TODO
                    basiccard.erase(basiccard.begin() - 1 + pos);
                }
        }
        else
        {
            if(pos<=0||pos>skillcard.size())
                return false;
            else if(skillcard[pos-1]==5)
                return false;
            else
            {
                //TODO
                skillcard.erase(skillcard.begin() - 1 + pos);
            }
        }
    }

    bool useclear()//返回true表示能出，返回false表示出不了
    {
        for (int i = 0; i < skillcard.size();i++)
        {
            if(skillcard[i]==5)
            {
                skillcard.erase(skillcard.begin() + i);
                return true;
            }
        }
        return false;
    }


};

void getcard(player P,card C,int kind)
{
    if(kind==1)
    {
        if(C.skillptr<=C.skillcards.size()-1)
        {
            P.skillcard.push_back(C.skillcards[C.skillptr]);
            C.skillptr++;
        }
    }
    else
    {
        if(C.basicptr<=C.basiccards.size()-1)
        {
        P.basiccard.push_back(C.basiccards[C.basicptr]);
        C.basicptr++;
        }
    }
}