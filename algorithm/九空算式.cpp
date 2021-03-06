/*猜算式
看下面的算式：
□□ x □□ = □□ x □□□
它表示：两个两位数相乘等于一个两位数乘以一个三位数。
如果没有限定条件，这样的例子很多。
但目前的限定是：这9个方块，表示1~9的9个数字，不包含0。
该算式中1至9的每个数字出现且只出现一次！
比如：
46 x 79 = 23 x 158
54 x 69 = 27 x 138
54 x 93 = 27 x 186
.....
请编程，输出所有可能的情况！
注意：
左边的两个乘数交换算同一方案，不要重复输出！
不同方案的输出顺序不重要
*/
#include <iostream>
using namespace std;
int flag[10000]={0};
int allSort(int n[],int start,int end);
int main()
{
	int n[9];
	for (int i=0;i<9;i++)
	{
		n[i] = i+1;
	}
	allSort(n,0,8);
	return 0;
}

void check(int n[])
{
	int a=n[0]*10+n[1];
	int b=n[2]*10+n[3];
	int c=n[4]*10+n[5];
	int d=n[6]*100+n[7]*10+n[8];

    int flag1 = a*100+b;
    int flag2 = a    +b*100;

	if(a*b==c*d &&flag[flag2]==0 && flag[flag1]==0)
		{
		    cout<<a<<"x"<<b<<"="<<c<<"x"<<d<<endl;
            flag[flag1]=1;
            flag[flag2]=1;
		}
}
int allSort(int n[],int start,int end)
{
	if (start>=end)
	{
		check(n);
		return 0;
	}else{
		for (int i = start; i <=end; i++)
		{
			int t = n[start];
			n[start] = n[i];
			n[i] = t;

			allSort(n,start+1,end);
			t = n[start];
			n[start] = n[i];
			n[i] = t;
		}
	}
    return 0;
}
