#include<iostream>
#include<vector>
#include<map>

using namespace std;

class trie
{
public:
	//tree：Trie 树
    map<int,map<int,int> > tree;
    //num：某个玩家所在的位置，arcnum：某个位置的玩家，deep：深度，fa：祖先 
    map<int,int> num,arcnum,deep,fa;
    int cnt=0;
    void clear();
    void add(int ,int);
	//out：输出
    vector<vector<pair<pair<int, int>, int>>> putout();
};
