#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class card
{
public:
    vector<int> cards;
    int cardsptr = 0;
    //1:<<,2:>>,3:~,4:l,5:C
    void init(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            cards.push_back(1);
            cards.push_back(2);
            cards.push_back(2);
            cards.push_back(3);
            cards.push_back(4);
            cards.push_back(5);
            cards.push_back(5);
        }
        random_shuffle(cards.begin(), cards.end());
    }
};