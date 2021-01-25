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
        vector<int> owncard;

};

void getcard(player P,card C)
{
    if(C.cardsptr<=C.cards.size()-1)
    {
        P.owncard.push_back(C.cards[C.cardsptr]);
        C.cardsptr++;
    }
}