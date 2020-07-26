# 常用算法模版
##### 快速幂

```c
int pow_mod(int a,int b,int c)
{
	int ans=1;
	a=a%c;
	while(b)
	{
		if(b&1)	ans=ans*a%c;
		a=a*a%c;
		b>>=1;
	}
	return ans;
}
```
##### 素数判断

```c
int Isprime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)	return 0;
	return 1;
}
```
##### 最大公约数（欧几里得）

```c
#include<cstdio>
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
		printf("%d\n",gcd(a,b));
	return 0;
}
```
##### 扩展欧几里得

```c
int a,b,x,y;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int ans=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return ans;
}
```
##### 汉诺塔

```c
#include<cstdio> 
int i=1;
void hanoi(int n,char from,char depend,char to)
{
	if(n==1)
	{
		printf("第%d步:将%d从%c---->%c\n",i++,n,from,to);
		return ;
	}
	else
	{
		hanoi(n-1,from,to,depend);
		printf("第%d步:将%d从%c---->%c\n",i++,n,from,to);
		hanoi(n-1,depend,from,to);
	}
}
 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
		hanoi(n,'A','B','C');
	return 0;
}
```
##### N皇后

```c
/*
	在一个n*n的棋盘上放n个皇后
	一共有多少种方法
	放置这些皇后
	
	任意两个皇后不能再同一行，同一列，同一对角线上
	否则会相互攻击 
	 
*/
#include<cstdio>
#include<cmath> 
const int MAXN=1000;
int n;
int p[MAXN];//存放第i行的皇后的列的编号 
void n_queen(int k)//在 0~k-1行皇后已经摆好的情况下，摆放 k 行及其后的皇后 
{
	int i,j;//因为后来要用到，所以提前定义 
	if(k==n)//n个皇后能够全部放下，就输出结果 
	{
		for(i=0;i<n;i++)
			printf("%d ",p[i]+1); //因为列的标号从1开始，所以输出的时候就输出p[i]+1; 
		printf("\n");
		return ; //递归完毕 
	}
	for(i=0;i<n;i++)//逐步尝试第k个皇后的位置 
	{
		for(j=0;j<k;j++)//和前k-1个皇后相比较，看是否在同一行同一列或者在对角线上 
			if(p[j]==i||abs(p[j]-i)==abs(k-j))//有一次这里写了个";"，找了半天没找到bug... 
				break;
	
		// i 表示列数， j 表示行数 
		//目的是为了将第 k 行的皇后放在第 i 列 
		//所以从第 0 行开始遍历，判断从 0---k-1 行的皇后 与 第 k行的皇后是否有冲突 
		//	p[j]==i, 如果第 j 行的皇后在第 i 列
		// 第 k 行皇后皇后的位置(k,  i ) //(需要完成的是p[k]=i);  
		// 第 j 行皇后皇后的位置(j,p[j]) 
		//abs(p[j]-i)==abs(k-j)	用来判断第 k 行的皇后与第 j 行的皇后是否在对角线上 
 
		if(j==k)//当前选的位置与 i 不冲突 
		{
			p[k]=i;	//将第 k 个皇后放在位置 i  
			n_queen(k+1);//第k个皇后放好了，去放第k+1(k<n)个皇后 
		 } 
	}
}
int main() 
{
	while(~scanf("%d",&n))	n_queen(0);//从第 0 个皇后开始放 
	return 0;
} 
```
##### 最长公共子序列（长度+打印路径）

```c
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int  maxn=1009;
char a[maxn],b[maxn];
int path[maxn][maxn],dp[maxn][maxn];//path 记录路径 
 
void lcs(int i,int j)//打印路径 
{
	if(i==0||j==0)	return ;//结束标志，a或者b只要有一个找完了，就不在找了 
	if(path[i][j]==1)//path是1的时候输出这个字符 
	{
		lcs(i-1,j-1);//因为是从后往前找的 
		printf("%c",a[i-1]);//所以这句得写到递归函数下边 
	 } 
	else if(path[i][j]==2)
		lcs(i-1,j);
	else 
		lcs(i,j-1);
	return ;
}
 
int main()
{
	while(~scanf("%s %s",a,b))
	{
		memset(dp,0,sizeof(dp));
		int m=strlen(a);
		int n=strlen(b);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				if(a[i-1]==b[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
					path[i][j]=1;
				}
				else if(dp[i-1][j]>dp[i][j-1])
				{
					dp[i][j]=dp[i-1][j];
					path[i][j]=2;
				}
				else
				{
					dp[i][j]=dp[i][j-1];	
					path[i][j]=3;
				}
		
		lcs(m,n);		
		printf("\n"); 
//		printf("\n%d\n",dp[m][n]);//输出最长子序列的长度 
	}
	return 0;
```
##### 最长递增子序列（长度+打印路径）

```c
#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int a[MAXN];
int dp[MAXN];
int n;
int vis[MAXN];
void dfs(int pos)//打印路径 
{
	if(pos==-1)	return  ;
	dfs(vis[pos]);
	printf(" %d",pos+1);//这里是正序输出编号(从1开始的) 
}
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		memset(vis,-1,sizeof(vis));
		int res=0;
		int pos=-1;
		
		for(int i=0;i<n;i++)
		{
			dp[i]=1;
			for(int j=0;j<i;j++)
				if(a[i]>a[j])
				{
					if(dp[i]<dp[j]+1)
					{
						dp[i]=dp[j]+1;
						vis[i]=j;//vis[i]=j 表示以a[i]为结尾的LIS的上一个元素是a[j]		
					}
				}	
			if(res<dp[i])
			{
				res=dp[i];
				pos=i;//找到LIS的最后一个结点 
			}
		}
		printf("The number is %d:",res);//输出LIS的长度 
		dfs(pos);
		printf("\n");
	}
	return 0;
}
```
##### 01背包

```c
 /*
    根据这个状态转移方程我们可以写出这个代码，复杂度O(nW)
*/
for(int i=0;i<n;i++)
    for(int j=0;j<=W;j++)
        if(j<w[i])  
            dp[i+1][j]=dp[i][j];
        else
            dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
printf("%d\n",dp[n][W]);

/*
    此外，01背包的还可以通过两个数组滚动来实现重复利用
*/
int dp[2][MAXN];
for(int i=0;i<n;i++)
    for(int j=0;j<=W;j++)
       if(j<w[i])
          dp[(i+1)&1][j]=dp[i&1][j];
       else
  dp[(i+1)&1][j]=max(dp[i&1][j],dp[i&1][j-w[i]]+v[i]);
 
printf("%d\n",dp[n&1][W]);

/*
    当然，还可以通过不断重复用一个数组来实现
*/
 
int dp[MAXN];
for(int i=0;i<n;i++)
    for(int j=W;j>=w[i];j--)
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
printf("%d\n",dp[W]);

```
##### 完全背包

```c
/*
    每种物品任意选择件数
*/ 
 
for(int i=0;i<n;i++)
    for(int j=0;j<=W;j++)
        if(j<w[i])
            dp[i+1][j]=dp[i][j];
        else
            dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
printf("%d\n",dp[n][W]);
 
/*
    一维数组
*/
int dp[MAXN];
for(int i=0;i<n;i++)
    for(int j=w[i];j<=W;j++)
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
printf("%d\n",dp[W]);
```
##### 多重背包

```c
for(int i=0;i<n;i++){
    int num=m[i];//用来找a 
    for(int k=1;num>0;k<<=1){
        int mul=min(k,num);
        for(int j=W;j>=w[i]*mul;j--){
            dp[j]=max(dp[j],dp[j-w[i]*mul]+v[i]*mul); 
        }
        num-=mul;
    }
}
printf("%d\n",dp[W]);
```
##### n！末尾0的个数

```c
int cal(int n)
{
	if(n<5)	return 0;
	n=n/5;
	return n+cal(n);
}
 
 
//也可以这样写
int sum=0;
while(n)	sum+=(n/=5);
printf("%d\n",sum);
```
##### N的阶乘位数

```c
 
#include<cstdio>
#include<cmath>
int main()
{
	double sum=0;
	for(int i=1;i<=10000;i++)	// n是10000的情况下 
		sum+=log10(i);
	printf("%d\n",(int)sum+1);
	return 0;
}
```
##### 大斐波那契数

```c
/*
  大斐波那契数 
*/
#include<cstdio>
#include<cstring>
#define ll long long
const int MAXN=1e4+3;
const int c=10000;
ll a[MAXN][MAXN];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		a[1][0]=1;a[2][0]=1;//初始化 第一个数和第二个数 
		int dight=0;//斐波那契数的 位数 
		int temp=0;//储存进位
		for(int i=3;i<=n;i++)	//从3算到N
		{
			temp=0;//进位每次计算都要初始化为0
			for(int j=0;j<=dight;j++)
			{
				a[i][j]=a[i-1][j]+a[i-2][j]+temp;
				temp=a[i][j]/10;
				a[i][j]%=10;
			 } 
			if(temp)//如果有进位的话 
			{
				dight++;//位数加一 
				a[i][dight]=temp;//给最高位赋值 
			}
		 } 
		for(int i=dight;i>=0;i--)//逆序输出这个数组 
			printf("%lld",a[n][i]);//n代表是第n个斐波那契数，i是这个数的第i位 
		printf("\n");			
	}
	return 0;
}
```
##### 大数加法

```c
/*
	大数加法采用的是模拟的思想，就是利用数组来储存一个数的每一位 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000;
char s1[MAXN],s2[MAXN];
int n1[MAXN],n2[MAXN],sum[MAXN];
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		scanf("%s %s",s1,s2);//用字符串来储存两个大数 
		memset(n1,0,sizeof(n1));//初始化数组，让它们全为0 
		memset(n2,0,sizeof(n2));
		memset(sum,0,sizeof(sum));//初始化保存结果的数组 
		int len1=strlen(s1);//第一个数的长度 
		int len2=strlen(s2);//第二个数的长度 
		int j=0;
		for(int i=len1-1;i>=0;i--)//将第一个数的每一位都逆序赋值给第一个数组 
			n1[j++]=s1[i]-'0';
		j=0;	
		for(int i=len2-1;i>=0;i--)
			n2[j++]=s2[i]-'0';
		int len=len1>len2?len1:len2;//找出来两个数中比较长的那个数 
		int pre=0;//用来保存进位 
		for(int i=0;i<len;i++)//给sum赋值，要记得sum可能是大于9的，输出的时候要对10取余 
		{
			sum[i]=n1[i]+n2[i]+pre/10;	
			pre=sum[i];
		}
		if(pre>9)//保存最高位的是sum[len-1] ，如果大于9 ，结果的位数要加一 
		{
			sum[len]=pre/10;//取高位 
			len++;//位数 +1
		}
		int t=len;
		for(int i=len-1;i>=0;i--)	//去掉前置0 
		{
			if(sum[i]==0)	t--;//像 0001 + 3 这种，结果应该输出 4 而不是0004 
			else			break;
		}
		printf("Case %d:\n%s + %s = ",k,s1,s2);
		for(int i=t-1;i>=0;i--)		
			printf("%d",sum[i]%10);
		printf("\n");
		if(k!=T)	printf("\n");//最后一组数据不要空行 
	 } 
	return 0;
}
```
##### 大数乘法

```c
/*
	大数乘法： 
	
	运用模拟，两个数组来储存两个大数
	另外一个数组来保存运算结果	
	
	em....
	
*/
 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000;
char s1[MAXN],s2[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int main() 
{
	while(scanf("%s %s",s1,s2)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int len1=strlen(s1);//第一个数的长度 
		int len2=strlen(s2);//第二个数的长度 
		int i,j;
		for(i=len1-1,j=0;i>=0;i--)	a[j++]=s1[i]-'0';//用数组逆序保存第一个数 
		for(i=len2-1,j=0;i>=0;i--)	b[j++]=s2[i]-'0';//用数组逆序保存第二个数 
		for(i=0;i<len1;i++)		
			for(j=0;j<len2;j++)
				c[j+i]+=a[i]*b[j];//一定要 + *  
		int len=len1+len2;
		for(i=0;i<len;i++)//进行进位运算 
			if(c[i]>9)
			{
				c[i+1]+=c[i]/10;
				c[i]%=10;
			 } 
		int t=len;
		for(i=len-1;i>=0;i--)//去掉前置0 
			if(c[i]==0)	t--;
			else		break;
		for(i=t-1;i>=0;i--)//输出 
			printf("%d",c[i]);		
		printf("\n");
	}	
	return 0;
}
```
##### 并查集

```c
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1e3+3;
int pre[MAXN];
int t,n,m;
void init(int n)//初始化 
{
	for(int i=1;i<=n;i++)
		pre[i]=i;
} 
int find(int x)//找根 
{
	return pre[x]==x?x:pre[x]=find(pre[x]);
}
void join(int x,int y)//连接 
{
	x=find(x);
	y=find(y);
	if(x!=y)	pre[x]=y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		init(n);
		
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			join(x,y);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(pre[i]==i)	ans++;
		cout<<ans<<endl;
	}
	return 0;
}
```
##### Kurskal算法

```c
/*
	依旧是最小生成树的模板题
	用的是Kurskal算法
	因为我只会这一个。。。	
*/
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Road{int x,y,cost;}w;
int pre[105],n,m;
vector<Road> d;		//不定数组，储存道路 
void init(int n)	//初始化元素，元素的根就是自己 
{
	for(int i=1;i<=n;i++)
		pre[i]=i;
}
int find(int x)		//查找元素的根 
{
	return x==pre[x]?x:pre[x]=find(pre[x]);
}
bool cmp(Road a,Road b)//排序的函数，让道路的权值从小到大排列 
{
	return a.cost<b.cost;
}
bool join(int x,int y)//合并元素的根 
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		pre[x]=y;
		return true;//合并成功一个元素之后返回 true，以便下边好记录一共有多少元素被并起来了 
	}
	return false;
}
int main()
{
	while(~scanf("%d %d",&n,&m)&&n)	//这里要注意，n 是道路的个数，m是村庄的个数 
	{
		init(m);	//初始化村庄 
		d.clear();	//清空数组 
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&w.x,&w.y,&w.cost);
			d.push_back(w);
		}
		sort(d.begin(),d.end(),cmp);//将道路按权值升序排列 
		int cnt=0;
		int sum=0;
		for(int i=0;i<d.size();i++)
		{
			if(join(d[i].x,d[i].y))
			{
				sum+=d[i].cost;	//道路的权值和 
				cnt++;
			}
			if(cnt==m-1)	break;//好几次这里写成了cnt==n-1，WA的要哭。。 
		}
		if(cnt==m-1)	printf("%d\n",sum);
		else			printf("?\n");
	}
	return 0;
}
```
##### 01背包+输出路径

```c
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100000+7;
int dp[MAXN];
bool vis[25][MAXN];
int n,W,v[MAXN];
int main()
{
    while(~scanf("%d %d",&W,&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=n-1;i>=0;i--)
            for(int j=W;j>=v[i];j--)
                if(dp[j-v[i]]+v[i]>dp[j])
                {
                    dp[j]=dp[j-v[i]]+v[i];
                    vis[i][j]=1;    
                }
        int j=W;
        for(int i=0;i<n;i++)
        {
            if(vis[i][j])
            {
                printf("%d ",v[i]);
                j -= v[i];  
            }   
        } 
        printf("sum:%d\n",dp[W]);
 
    }
    return 0;
}
```
##### 简单搜索BFS

```c
#include<bits/stdc++.h>
using namespace std;
const int MAXN=50;
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n,m,ans,stx,sty,edx,edy;
int d[4][2]={0,1, 0,-1, 1,0, -1,0};
struct node{
    int x,y;
    node(){}
    node(int _x,int _y):x(_x),y(_y){}
};
 
void BFS(int x,int y)
{
    vis[x][y]=1;
    ans++;
    node e1=node(x,y);
    queue<node> que;
    que.push(e1);
    while(que.size())
    {
        node e2=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int dx=e2.x+d[i][0];
            int dy=e2.y+d[i][1];
            if(dx>=0 && dx<n && dy>=0 && dy<m && !vis[dx][dy] && str[dx][dy]!='#')
            {
                ans++;
                vis[dx][dy]=1;
                que.push(node(dx,dy));
            }
        }
    }
}
 
int main()
{
    while(~scanf("%d %d",&m,&n)&&(n|m))
    {
        memset(str,0,sizeof(str));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)    scanf("%s",str[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='@')
                {
                    stx=i;
                    sty=j;
                    break;
                }
            }
        ans=0;
        BFS(stx,sty);
        printf("%d\n",ans);
    }
    return 0;
}
```
##### 简单搜索DFS

```c
#include<bits/stdc++.h>
using namespace std;
const int MAXN=50;
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
int d[4][2]={1,0, -1,0, 0,1, 0,-1};
int n,m,ans;
int stx,sty,edx,edy;
 
void DFS(int x,int y)
{
    vis[x][y]=1;
    ans++;
    for(int i=0;i<4;i++)
    {
        int dx=x+d[i][0];
        int dy=y+d[i][1];
        if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && str[dx][dy]!='#')//判断条件不能搞错 
        {
            vis[dx][dy]=1;
            DFS(dx,dy);
        }
    }
}
 
int main()
{
    while(~scanf("%d %d",&m,&n)&&(n|m))
    {
        memset(str,0,sizeof(str));//不初始化 Wa 
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)    scanf("%s",str[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='@')//找到起点 
                {
                    stx=i;
                    sty=j;
                    break;
                }
            }
        ans=0;
        DFS(stx,sty);//从起点开始搜索 
        printf("%d\n",ans);
    }
    return 0;
}
```
##### 最短路DIjkstra

```c
/*
	邻接链表写法 
	
*/
 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> P;
const int maxn=1e3+5;
const int INF=0x3f3f3f3f;
 
struct edge
{
	int to,cost;
	edge(){}
	edge(int _to,int _cost)
	{
		to=_to;
		cost=_cost;
	}
};
 
vector<edge> G[maxn];
int d[maxn];
 
void dijkstra(int s)
{
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	priority_queue<P,vector<P>,greater<P> >que;
	que.push(P(0,s));
	while(que.size())
	{
		P p=que.top();que.pop();
		int v=p.second;
		if(d[v]<p.first)	continue;
		for(int i=0;i<G[v].size();i++)
		{
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
			
		}
	}
}
 
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)&&(n|m))//n is number of  vertex  ,  m is number of edge
	{
		for(int i=0;i<maxn;i++)	G[i].clear();//一定要记得初始化邻接链表，不然会错 
		for(int i=0;i<m;i++)//
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			G[x].push_back(edge(y,z));
			G[y].push_back(edge(x,z));
		}
		dijkstra(1);
		printf("%d\n",d[n]); 
	}
	return 0;
}
```
##### 分治着逆序数

```c
#include<cstdio>
#include<cstring>
//#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=50005;
 
int a[maxn],b[maxn];
int count;
int n;
 
void merge(int a[],int start,int mid,int end)
{
	int i=start,j=mid+1,k=start;
	while(i<=mid&&j<=end)
	{
		if(a[i]<=a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			count+=j-k;
			b[k++]=a[j++];
		}
	}
	while(i<=mid)
	{
		b[k++]=a[i++];
	}
	while(j<=end)
	{
		b[k++]=a[j++];
	}
	for(int i=start;i<=end;i++)
	{
		a[i]=b[i];
	}
}
void mergesort(int *a,int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
 
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)	scanf("%d",a+i);
		count=0;
		mergesort(a,0,n-1);
		printf("%d\n",count);
	}
	return 0;
}
```
##### KMP找下标

```c
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+7;
int s[MAXN],p[MAXN];
int slen,plen;
int nex[MAXN];
 
void GetNext()
{
    int i,j;
    i=0;
    j=nex[0]=-1;
    while(i<plen)
    {
        while(-1!=j&&p[i]!=p[j])    j=nex[j];
        if(p[++i]==p[++j])  nex[i]=nex[j];
        else                nex[i]=j;
    }
}
 
int KMP()
{
    GetNext();
    int i,j;
    i=j=0;
    while(i<slen&&j<plen)
    {
        while(-1!=j && s[i]!=p[j])  j=nex[j];
        i++;j++;
    }
    if(j==plen)
        return i-j+1;
    else
        return -1;
}
 
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&slen,&plen);
        for(int i=0;i<slen;i++) scanf("%d",&s[i]);
        for(int i=0;i<plen;i++) scanf("%d",&p[i]);
        printf("%d\n",KMP());
    }
    return 0;
}
```
##### 全排列

```c
/*
    |求1到n的全排列, 有条件|
    |16/11/05ztx, thanks to wangqiqi|
*/

void Pern(int list[], int k, int n) {   //  k表示前k个数不动仅移动后面n-k位数
    if (k == n - 1) {
        for (int i = 0; i < n; i++) {
            printf("%d", list[i]);
        }
        printf("\n");
    }else {
        for (int i = k; i < n; i++) {   //  输出的是满足移动条件所有全排列
            swap(list[k], list[i]);
            Pern(list, k + 1, n);
            swap(list[k], list[i]);
        }
    }
}
```
##### 二分搜索

```c++
/*
    |二分搜索|
    |要求：先排序|
*/

//  left为最开始元素, right是末尾元素的下一个数，x是要找的数
int bsearch(int *A, int left, int right, int x){
    int m;
    while (left < right){
        m = left + (right - left) / 2;
        if (A[m] >= x)  right = m;   else left = m + 1;    
        // 如果要替换为 upper_bound, 改为:if (A[m] <= v) x = m+1; else y = m;     
    }
    return left;
}

/*
    C++自带的lower_bound(a,a+n,x)返回数组中最后一个x的下一个数的地址 
    upper_bound(a,a+n,x)返回数组中第一个x的地址
    lower_bound(a,a+n,x）-upper_bound(a,a+n,x)返回数组中x的个数
*/ 
```
