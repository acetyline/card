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