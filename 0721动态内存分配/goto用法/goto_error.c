
void func(void)
{
	char *p1 = NULL;
	char *p2 = NULL;
	char *p3 = NULL;
	
	p1 = (char *)malloc(10);
	if(!p1)
	{
		goto func_end_proccess;
	}
	p2 = (char *)malloc(10);
	if(!p2)
	{
		goto func_end_proccess;
	}
	p3 = (char *)malloc(10)
	if(!p3)
	{
		goto func_end_proccess;
	}

func_end_proccess:
	if (p1)
	{
		free(p1);
		p1 = NULL;
	}	
	
	if (p2)
	{
		free(p2);
		p1 = NULL;
	}	

	if (p3)
	{
		free(p3);
		p1 = NULL;
	}	
}

