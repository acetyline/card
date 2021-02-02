#include<map>
#include<vector> 
#include<queue>
#include "trie.h"

using namespace std;

	void trie::clear()
    {
    	tree.clear();
    	num.clear();
    	arcnum.clear();
    	cnt=0;
	}
	//player:某个玩家的操作 card:加入的基本牌
    void trie::add(int player,int card)
	{
		int k=0;
		for(int i=10;~i;i--)
		{
			bool w=((1<<i)&card);
			if(!tree[k][w])
			{
				tree[k][w]=++cnt;
				deep[cnt]=deep[k]+1;
			}
			k=tree[k][w];
		}
		num[player]=k;
		arcnum[k]=player;
		return ;
	}
	//out：输出 
	vector<vector<pair<pair<int,int>,int> > > trie::putout() 
	{
		queue<int> q;
		vector<vector<pair<pair<int,int>,int> > > out;
		q.push(1);
		int temp=0;
		//val：某点对应的 0/1 
		map<int,bool> val;
		val[1]=0;
		out.push_back(vector<pair<pair<int,int>,int> >());
		while(!q.empty())
		{
			int k=q.front();
			q.pop();
			if(deep[k]==temp+1)
			{
				temp++;
				out.push_back(vector<pair<pair<int,int>,int> >());
			}
			out[temp].push_back(make_pair(make_pair(k,val[k]),fa[k]));
			for(int i=0;i<=1;i++)
			{
				if(tree[k][i])
				{
					fa[tree[k][i]]=k;
					q.push(tree[k][i]);
					val[tree[k][i]]=i;
				}
			}
		}
		return out; 
	}