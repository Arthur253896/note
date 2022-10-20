#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define maxn 256
int m[maxn][maxn];
//黄瑞贺的作业
void OddMagic(int n)                         //奇数阶幻方
{
    memset(m,0,sizeof(m));                   //幻方清零
    int x=0, y=n/2;
    for(int i=1; i<=n*n; i++)
    {
        m[x][y]=i;
        x--;                                 //依次沿右上角填充
        y++;
        if(x<0 && y>n-1) {x=x+2; y=y-1;}     //沿对角线超出
        else if(x<0) x=x+n;                  //沿上边界超出
        else if(y>n-1) y=y-n;                //沿右边界超出
        else if(m[x][y]!=0) {x=x+2; y=y-1;}  //右上角已填充
    }
}

void DoubleEvenMagic(int n)                  //双偶数阶幻方
{
    memset(m,0,sizeof(m));                   //幻方清零
    for(int i=1, x=0, y=0; i<=n*n; i++)      //依次按顺序赋初值
    {
        m[x][y]=i;
        y++;
        if(y>n-1) {x++; y-=n;}
    }
    for(int i=0; i<n; i++)                   //将幻方分解成m*m个4阶幻方，并将每个4阶幻方的对角线元素换成其互补数
        for(int j=0; j<n; j++)
            if(i%4==0 && j%4==0)             //左对角线
                for(int k=0; k<4; k++)
                    m[i+k][j+k]=(n*n+1)-m[i+k][j+k];
            else if(i%4==3 &&j%4==0)         //右对角线
                for(int k=0; k<4; k++)
                    m[i-k][j+k]=(n*n+1)-m[i-k][j+k];
}

void SingleEvenMagic(int n)                  //单偶数阶幻方
{
    memset(m,0,sizeof(m));                   //幻方清零
    int n0=n/2;
    OddMagic(n0);                            //将幻方分解成2*2个奇数阶幻方，调用奇数阶幻方函数填充左上角奇数阶幻方
    for(int i=0; i<n0; i++)
        for(int j=0; j<n0; j++)
        {
            m[i+n0][j+n0]=m[i][j]+n0*n0;       //填充右下角奇数阶幻方
            m[i][j+n0]=m[i+n0][j+n0]+n0*n0;     //填充右上角奇数阶幻方
            m[i+n0][j]=m[i][j+n0]+n0*n0;       //填充左下角奇数阶幻方
        }
    int k=(n-2)/4;                             //满足公式n=4*k+2
    for(int i=0; i<n0; i++)
        for(int j=0; j<k; j++)
            if(i==n0/2) swap(m[i][i+j],m[i+n0][i+j]);   //将左上角幻方最中间元素从左向右的k个元素与左下角幻方相应位置元素交换
            else swap(m[i][j],m[i+n0][j]);              //将左上角幻方除最中间行外的每行前k个元素与左下角幻方相应位置元素交换
    for(int i=0; i<n0; i++)
        for(int j=n0+n0/2; j>n0+n0/2-(k-1); j--)
            swap(m[i][j],m[i+n0][j]);                   //将右上角幻方最中间列起从右向左的k-1列元素与右下角幻方相应位置元素交换
}

bool Check(int n)
{
    int cnt=n*(n*n+1)/2;                                //每行每列以及对角线之和
    for(int i=0; i<n; i++)
    {
        int sum_row=0,sum_line=0;
        for(int j=0; j<n; j++)
            {
                sum_row+=m[i][j];                       //检查各行
                sum_line+=m[j][i];                      //检查各列
            }
        if(sum_row!=cnt || sum_line!=cnt) return false;
    }
    int sum_left=0,sum_right=0;
    for(int i=0; i<n; i++)
    {
        sum_left+=m[i][i];                              //检查左对角线
        sum_right+=m[n-i-1][i];                         //检查右对角线
    }
    if(sum_left!=cnt || sum_right!=cnt) return false;
    return true;
}

void print(int n)                                       //按格式输出
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(j==n-1) printf("%4d\n",m[i][j]);
            else printf("%4d",m[i][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cout<<"请输入一个大于2的数"<<endl;
    while(cin>>n)
    {
        if(n<3) cout<<"不可能组成幻方"<<endl;
        else if(n&1) {
            OddMagic(n); if(Check(n)) print(n);
            }                    //输出奇数阶幻方
        else if(!(n%4)) {
            DoubleEvenMagic(n); if(Check(n)) print(n);
            }     //输出双偶数阶幻方
        else {
            SingleEvenMagic(n); if(Check(n)) print(n);
            }                //输出单偶数阶幻方
        break;
    }
    return 0;
}