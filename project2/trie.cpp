#include<map>

using namespace std;

class trie
{
public:
    map<int,map<int,int> > t;
    void add(int w)
	{
		int k=0;
		for(int i=10;~i;i--)
		{
			bool m=((1<<i)&w);
			if(!t[k][m])
			{
				t[k][m]=++cnt;
			}
			k=t[k][m];
		}
		return ;
	}
};
