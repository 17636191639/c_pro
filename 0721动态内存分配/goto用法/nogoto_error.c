
void Func(void)
{
	char *p1 = NULL;
	char *p2 = NULL;
	char *p3 = NULL;
	
	p1 = (char *)malloc(10);
	if(!p1)
		return ;
	p2 = (char *)malloc(10);
	if(!p2)
	{
		free(p1);
		p1 = NULL;
		return ;
	}
	p3 = (char *)malloc(10)
	if(!p3)
	{
		free(p1);
		p1 = NULL;
		free(p2);
		p2 = NULL:
		return;	
	}

	//如果要是申请的指针是10个的，程序应该怎么写？
	//下面任然要释放内存
	if （p1）
	{
		free(p1);
		p1 = NULL;
	}	
	
	if （p2）
	{
		free(p2);
		p1 = NULL;
	}	

	if （p3）
	{
		free(p3);
		p1 = NULL;
	}	
}

