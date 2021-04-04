#include <stdio.h>
 
#define N 5         //物品的数量
#define C  10       //背包的容量
 
int w[N] = {2, 2, 6, 5, 4};  //每个物品的重量
int v[N] = {6, 3, 5, 4, 6};   //每个物品的价值
int x[N] = {0, 0, 0, 0, 0};   //x[i]=1代表物品i放入背包，0代表不放入
 
int cur_weight = 0;  //当前放入背包的物品总重量
int cur_value = 0;   //当前放入背包的物品总价值
 
int best_value = 0;  //最优值；当前的最大价值，初始化为0
int best_x[N];       //最优解；best_x[i]=1代表物品i放入背包，0代表不放入
 
//t = 0 to N-1
void backtrack(int t)
{
	int i;

	//叶子节点，输出结果
	if(t > N - 1) 
	{
		//如果找到了一个更优的解
		if(cur_value > best_value)
		{
			//保存更优的值和解
			best_value = cur_value;
			for(i = 0; i < N; ++i) 
			{
				best_x[i] = x[i];
			}
		}
	}
	else
	{
		//遍历当前节点的子节点：0 不放入背包，1放入背包
		for(i = 0; i <= 1; ++i)
		{
			x[t] = i;
 
			if(i == 0)         //不放入背包
			{
				backtrack(t + 1);
			}
			else               //放入背包
			{
 				//约束条件：放的下
				if((cur_weight + w[t]) <= C)
				{
					cur_weight += w[t];
					cur_value += v[t];
					backtrack(t + 1);
					cur_weight -= w[t];
					cur_value -= v[t];
				}
			}
		}
	}
}
 
 //回溯法解决0-1背包问题
int main(int argc, char* argv[])
{
	int i; 
	
	backtrack(0);
 
	printf("最优值：%d\n",best_value);
 
	for(i = 0; i < N; i++)
	{
	   printf("%-3d", best_x[i]);
	}

	return 0;
}
