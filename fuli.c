#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double danli()
{
	double P,F,i; //P是本金，F是收益，i年利率
	int N; //是期限
	double nlx;
	printf("请输入本金：\n");
	scanf("%lf",&P);
	printf("请输入年利率\n");
	scanf("%lf",&i);
	printf("请输入年限：\n");
	scanf("%d",&N);
	
	nlx = P*i;
	F = nlx*N + P;
	return F;
	
}

double fuli()
{
	
	double P,F,i; //P是本金，F是收益，i年利率
	int N,W; //是期限
	printf("请输入本金：\n");
	scanf("%lf",&P);
	printf("请输入年利率\n");
	scanf("%lf",&i);
	printf("请输入年限：\n");
	scanf("%d",&N);
	printf("请输入复利次数：\n");
	scanf("%d",&W);
	
	i=pow(1+i/W,W)-1;
	F=P*pow((i+1),N);
	return F;
}

double gusuan()
{
	double P,F,i; //P是本金，F是收益，i年利率
	int N,W; //是期限
	printf("请输入收益：\n");
	scanf("%lf",&F);
	printf("请输入年利率\n");
	scanf("%lf",&i);
	printf("请输入年限：\n");
	scanf("%d",&N);
	printf("请输入复利次数：\n");
	scanf("%d",&W);
	i = pow(1+i/W,W)-1;
	P = F/pow((i+1),N);
	return P;
}

double TZtime()
{
	double year;
	double P,F,i; //P是本金，F是收益，i年利率
	int N,W; //是期限
	printf("请输入本金：\n");
	scanf("%lf",&P);
	printf("请输入收益：\n");
	scanf("%lf",&F);
	printf("请输入年利率\n");
	scanf("%lf",&i);
	printf("请输入复利次数：\n");
	scanf("%d",&W);
	i = pow((1+i/W),W)-1;
	year = log(F/P)/log(1+i);
	return year;
	
}
double bestProject()
{
	double P,F,i;
	int N,W;
	printf("请输入本金：\n");
	scanf("%lf",&P);
	printf("请输入收益：\n");
	scanf("%lf",&F);
	printf("请输入年限\n");
	scanf("%d",&N);
	printf("请输入复利次数：\n");
	scanf("%d",&W);
	i = W*(pow(pow(F/P,1.0/N),1.0/W)-1.0);
	return i;
	
	
}

double sum()
{
	double y,moon,F=0.0,i,mi;
	double nlx,ylx;
	int N,W;
	int ch,j;
	printf("####### 1-年投资  2-月投资 #######\n");
	scanf("%d",&ch);
	if(ch == 1)
	{
		printf("请输入年投资额：\n");
		scanf("%lf",&y);
	}
	else
	{
		printf("请输入月投资额：\n");
		scanf("%lf",&moon);
	}
	
	printf("请输入年利率\n");
	scanf("%lf",&i);
	printf("请输入年限\n");
	scanf("%d",&N);
	//		printf("请输入复利次数：\n");
	//		scanf("%d",&W);
	if(ch == 1)
	{
		F = y;
		for(j=0 ; j<N ; j++)
		{
			nlx = F*i;
			F=y+nlx+F;
		}
		return F-y;
	}
	else
	{
		F = moon;
		mi = i/12.0;
		for(j=0 ; j<N*12 ; j++)
		{
			ylx = F*mi;
			F=moon+ylx+F;
		}
		return F-moon;
	}
	
	
}

void main()
{
	double F1;
	int ch2; 
	
	while(1)
	{
		printf("***********复利计算机(3.0)**********\n");
		
		printf("------    1 复利                  ------\n");
		printf("------    2 单利                  ------\n");
		printf("------    3 本金估算              ------\n");
		printf("------    4 投资年限估算          ------\n");
		printf("------    5 最优投资项目利率估算  ------\n");
		printf("------    6 定期投资收益计算      ------\n");
		printf("------    0 退出                  ------\n");
		printf("请选择：	");
		scanf("%d",&ch2);
		switch(ch2){
		case 1:
			F1 = fuli(); break;
		case 2:
			F1 = danli(); break;
		case 3:
			F1 = gusuan();
			break;
		case 4:
			F1 = TZtime();
			break;
		case 5:
			F1 = bestProject();
		case 6:
			F1 = sum();
			break;
		case 0:
			exit(1);
			break;
		}
		
		printf("结果为：%.2lf\n",F1);
	}
	
	
}