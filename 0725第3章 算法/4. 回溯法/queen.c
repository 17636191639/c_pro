 #include <stdio.h>
 
#define N 4							    //N 皇后问题						
	
int board[N][N];                        //棋盘 0表示空白 1表示有皇后
int way;								//摆放的方法数
 
 
//判断能否在(x,y)的位置摆放一个皇后；0不可以，1可以
int is_feasible(int row, int col)
{
	int i;
	int j;

	//位置不合法
	if(row > N || row < 0 || col > N || col < 0)
	{
		return 0;
	}
 
	//该位置已经有皇后了，不能
	//在行列冲突判断中也包含了该判断，单独提出来为了提高效率
	if(board[row][col] != 0)
	{	
		return 0;
	}
 
	//下面判断是否和已有的冲突
	//行和列是否冲突
	for(i = 0; i < N; ++i)
	{
		if(board[row][i] != 0 || board[i][col] != 0)
		{
			return 0;
		}
	}
 
	//斜线方向冲突
	for(i = 1; i < N; ++i)
	{
		/* i表示从当前点(row,col)向四个斜方向扩展的长度
		 
		左上角 \  / 右上角  i=2
				\/          i=1
				/\          i=1
		左下角 /  \ 右下角  i=2
		*/
		
		//左上角
		if((row - i) >= 0 && (col - i) >= 0)            //位置合法
		{
			if(board[row - i][col - i] != 0)            //此处已有皇后，冲突
			{
				return 0;
			}
		}
		
		//左下角
		if((row + i) < N && (col - i) >= 0)       
		{
			if(board[row + i][col - i] != 0)
			{
				return 0;
			}
		}
		
		//右上角
		if((row - i) >= 0 && (col + i) < N)       
		{
			if(board[row - i][col + i] != 0)
			{
				return 0;
			}
		}
		
		//右下角
		if((row + i) < N && (col + i) < N)         
		{
			if(board[row + i][col + i] != 0)
			{
				return 0;
			}
		}
	}
 
	return 1; 										//不会发生冲突，返回1
}
 
 
//摆放第t个皇后 ；从1开始
void queen(int t)
{
	int i;
	int j;

	//摆放完成，输出结果
	if(t > N)
	{
		way++;

#if 0
	printf("%d\n", way);
		/*如果N较大，输出结果会很慢；N较小时，可以用下面代码输出结果*/
		for(i = 0; i < N; ++i)
		{
			for(j = 0; j < N; ++j)
			{
				printf("%-3d", board[i][j]);
			}
			printf("\n");
		}
		printf("\n------------------------\n\n");
#endif
		return;
	}
	
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			//（i,j）位置可以摆放皇后，不冲突
			if(is_feasible(i, j))
			{ 
				board[i][j] = 1;    //摆放皇后t
				queen(t + 1);       //递归摆放皇后t+1
				board[i][j] = 0;    //恢复
			}
		}
	}
	
}
 
//返回num的阶乘,num!
int factorial(int num)
{
	if(num==0 || num==1)
	{
		return 1;
	}

	return num * factorial(num - 1);
}
 
//回溯法解决八皇后问题
int main(int argc, char* argv[])
{
	int i;
	int j;
	//
	
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			board[i][j] = 0;
		}
	}
 
	way = 0;
 
	queen(1);  //从第1个皇后开始摆放
 
	//如果每个皇后都不同
	printf("考虑每个皇后都不同，摆放方法：%d\n", way);                          //N=8时, way=3709440 种
 
	//如果每个皇后都一样，那么需要除以 N！出去重复的答案（因为相同，则每个皇后可任意调换位置）
	printf("考虑每个皇后都相同，摆放方法：%d\n", way / factorial(N));           //N=8时, way=3709440/8! = 92种
 
	return 0;
}
