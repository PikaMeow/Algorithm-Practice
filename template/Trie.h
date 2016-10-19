#include <cstring>

#define MAXN 100010
class Trie {
private:
    int node[MAXN][30];//Trie树的节点数组
    int val[MAXN];//每个节点的子节点个数数组
    int size;//Trie树的节点个数
public:
    void clear() {memset(node[0],0,sizeof(node[0]));size=1;}//初始化Trie树
    int index(char);//返回某个字符的索引值
    void insert(char*);//向Trie树中插入一个字符串
    void del(char *,int);//删除以某字符串为前缀的Trie树中的相应节点
    int search(char *);//查询以某字符串为前缀的Trie树中的字符串的个数
};

int Trie::index(char c) {
     return c-'a';
}

void Trie::insert(char *str) {
    int u=0;
    int len=strlen(str);
    for(int i=0;i<len;i++) {
        int c=index(str[i]);
        if(!node[u][c]) {
            memset(node[size],0,sizeof(node[size]));
            val[size]=0;
            node[u][c]=size++;
        }
        u=node[u][c];
        val[u]++;
    }
}

void Trie::del(char *str,int num) {
     int u=0;
     int len=strlen(str);
     for(int i=0;i<len;i++) {
         int c=index(str[i]);
         u=node[u][c];
         val[u]-=num;
     }
     memset(node[u],0,sizeof(node[u]));
}

int Trie::search(char *str) {
    int u=0;
    int len=strlen(str);
    for(int i=0;i<len;i++) {
        int c=index(str[i]);
        if(!node[u][c]) return 0;
        u=node[u][c];
    }
    return val[u];
}


