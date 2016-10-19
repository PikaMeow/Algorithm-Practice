#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 1000
int m,n,p,volume;
int big[MAX];//存放大立方体每个位置的值
int small[15][MAX];//存放每个小立方体每个位置的值
int size[15];//存放每个小立方体的尺寸
int tree[15];//存放每个小立方体放置的位置

//判断在位置pos放置第cube_num个小立方体时，相应位置的值加和后%p是否为0
bool value_valid(int cube_num,int pos) {
    int vol=size[cube_num]*size[cube_num]*size[cube_num];
    for(int i=0;i<vol;i++) {
        // 将小立方体相应位置的值映射到大立方体相应位置上(进制转换...)
        int big_pos=pos+i%size[cube_num]+i/size[cube_num]%size[cube_num]*m+i/size[cube_num]/size[cube_num]%size[cube_num]*m*m;
        //如果有一个位置不满足要求，返回false
        if((small[cube_num][i]+big[big_pos])%p) {
            return false;
        }
    }
    return true;
}

// 判断位置pos是否能够放置第cube_num个立方体
bool pos_valid(int cube_num,int pos) {
    int range=m-size[cube_num];
    int tmp=pos;
    
    //如果小立方体超出大立方体的范围，返回false
    while(tmp) {
        if(tmp%m>range) {
            return false;
        }
        tmp/=m;
    }

    //如果小立方体会与之前放置的小立方体出现重合部分，返回false
    if(cube_num) {
        for(int i=0;i<cube_num;i++) {
            int tmp_origin=tree[i];
            for(int k=0;k<3;k++) {
                if(tmp_origin%m) {
                    int origin=tree[i];
                    tmp=pos;
                    int cnt=0;
                    for(int j=0;j<3;j++) {
                        int tmp1=tmp%m;
                        int tmp2=origin%m;
                        if(tmp1>tmp2-size[cube_num] && tmp1<tmp2+size[i]) {
                            tmp/=m;
                            origin/=m;
                            cnt++;
                        } else {
                            break;
                        }
                    }
                    if(cnt==3) {
                        return false;
                    }
                }
                tmp_origin/=m;
            }
        }
    }
    return true;
}

void search(int cube_num) {
    // 对第cube_num个小立方体，遍历大立方体中的所有位置
    // 如果所有小立方体均已填充，说明找到可行解，返回
    // 否则，判断当前位置是否可以填充该立方体(第cube_num个),
    // 再判断当前位置是否满足 '%p=0' 的要求
    // 如果都满足，那么将该立方体放置在该位置，寻找下一个小立方体的位置
    // 如果 '位置不满足' 或者 '值不满足' ，那么换一个位置继续试验
    for(int i=0;i<volume;i++) {
        if(tree[n-1]!=-1) {
            return;
        }
        if(pos_valid(cube_num,i)) {
            if(value_valid(cube_num,i)) {
                tree[cube_num]=i;
                search(cube_num+1);
            }
        }
    }
    return;
}
int main() {

    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    //读取输入数据
    scanf("%d%d%d",&m,&n,&p);
    volume=m*m*m;
    for(int i=0;i<volume;i++) {
        scanf("%d",&big[i]);
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&size[i]);
        int vol=size[i]*size[i]*size[i];
        for(int j=0;j<vol;j++) {
            scanf("%d",&small[i][j]);
        }
    }

    memset(tree,0xff,sizeof(tree));// 初始化为-1

    search(0);//寻找正确解
    
    //输出
    for(int i=0;i<n;i++) {
        printf("%d %d %d\n",tree[i]/m/m%m,tree[i]/m%m,tree[i]%m);
    }
}