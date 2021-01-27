#include<map>

using namespace std;

class trie
{
public:
	//tree：Trie 树。
    map<int,map<int,int> > tree;
    //num：某个玩家所在的位置，arcnum：某个位置的玩家。
    map<int,int> num,arcnum;
    int cnt=0;
    void clear()
    {
    	tree.clear();
    	num.clear();
    	arcnum.clear();
    	cnt=0; 
	}
    //player:某个玩家的操作，card:加入的基本牌。
    void add(int player,int card)
	{
		int k=0;
		for(int i=10;~i;i--)
		{
			bool w=((1<<i)&card);
			if(!tree[k][w])
			{
				tree[k][w]=++cnt;
			}
			k=tree[k][w];
		}
		num[player]=k;
		arcnum[k]=player; 
		return ;
	}
};
