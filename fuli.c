/**
	此版本是在前三个版本的基础上添加了 等额本息还贷计算 的新功能
	并且按照实验要求增强了系统的健壮性，保证在输入一部分的错误的
	数据，后程序不会崩溃。例如是在输入int或者是输入double类型的
	地方，输入了字符，是会提示并且允许重新输入。

	并且通过宏定义使得代码变得简洁，还有简化了修改的操作，还认识
	到宏定义的妙用是可以使得编程变得简单，还可以增大代码的复用性。

**/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define WARN1   while(0 == 
#define WARN2   ){	while('\n' != getchar())	{	}	printf("输入不合法!\n请重新输入:	");		}

double danli()
{
    double P,F,i; //P是本金，F是收益，i年利率
    int N; //是期限
    double nlx;
	printf("------进入单利计算\n");
    printf("请输入本金：\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("请输入年利率\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("请输入年限：\n");
    WARN1	scanf("%d",&N)	WARN2
    
    nlx = P*i;
    F = nlx*N + P;
    return F;
    
}

double fuli()
{
    
    double P,F,i; //P是本金，F是收益，i年利率
    int N,W; //是期限
	printf("-------进入复利计算\n");
    printf("请输入本金：\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("请输入年利率\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("请输入年限：\n");
    WARN1	scanf("%d",&N)	WARN2
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
	printf("-------进入本金计算\n");
    printf("请输入收益：\n");
    WARN1	scanf("%lf",&F)	WARN2
    printf("请输入年利率\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("请输入年限：\n");
    WARN1	scanf("%d",&N)	WARN2
    printf("请输入复利次数：\n");
    WARN1	scanf("%d",&W)	WARN2
    i = pow(1+i/W,W)-1;
    P = F/pow((i+1),N);
    return P;
}

double TZtime()
{
    double year;
    double P,F,i; //P是本金，F是收益，i年利率
    int W; //是期限
	printf("-------进入投资时间计算\n");
    printf("请输入本金：\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("请输入收益：\n");
    WARN1	scanf("%lf",&F)	WARN2
    printf("请输入年利率\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("请输入复利次数：\n");
    WARN1	scanf("%d",&W)	WARN2
    i = pow((1+i/W),W)-1;
    year = log(F/P)/log(1+i);
    return year;
    
}
double bestProject()
{
    double P,F,i;
    int N,W;
	printf("-------进入项目利率计算\n");
	printf("请输入本金：\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("请输入收益：\n");
    WARN1	scanf("%lf",&F)	WARN2
    printf("请输入年限\n");
    WARN1	scanf("%d",&N)	WARN2
    printf("请输入复利次数：\n");
    WARN1	scanf("%d",&W)	WARN2
    i = W*(pow(pow(F/P,1.0/N),1.0/W)-1.0);
    return i;
    
    
}

double sum()
{
    double y,F=0.0,i;
    int N;
    int ch;
	printf("-------进入定投计算\n");
    printf("####### 1-年投资  2-月投资 #######\n");
    WARN1	scanf("%d",&ch)	WARN2
    if(ch == 1)
    {
        printf("请输入年投资额：\n");
        WARN1	scanf("%lf",&y)	WARN2
    }
    else
    {
        printf("请输入月投资额：\n");
        WARN1	scanf("%lf",&y)	WARN2
    }
    
    printf("请输入年利率\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("请输入年限\n");
    WARN1	scanf("%d",&N)	WARN2
    //        printf("请输入复利次数：\n");
    //        scanf("%d",&W);
    if(ch == 2)
    {
        i = i/12.0;
        N = N*12;
    }
    F = y*(1.0+i)*(-1+pow(1.0+i,N))/i;

    return F;

    
    
}

double refund()
{
	double P,i,month_amount;
    int N,month;
	printf("-------进入本息还款计算\n");
    printf("请输入贷款金额：\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("请输入年利率：\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("请输入归还年限：\n");
    WARN1	scanf("%d",&N)	WARN2

		//每月还款额=[贷款本金×月利率×（1+月利率）^还款月数]÷[（1+月利率）^还款月数－1]

	i = i/12;
	month = N*12;
	month_amount = P*i*pow((1.0+i),month)/(pow(1.0+i,month)-1);
	return month_amount;

}

void main()
{
    double F1;
    int ch2; 
    
    while(1)
    {
        printf("*************复利计算机(4.0)************\n");
        
        printf("------    1 复利                  ------\n");
        printf("------    2 单利                  ------\n");
        printf("------    3 本金估算              ------\n");
        printf("------    4 投资年限估算          ------\n");
        printf("------    5 最优投资项目利率估算  ------\n");
        printf("------    6 定期投资收益计算      ------\n");
	    printf("------    7 等额本息还款计算      ------\n");
        printf("------    0 退出                  ------\n");
		printf("请选择：    ");
		WARN1	scanf("%d",&ch2)	WARN2
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
		case 7:
			F1 = refund();
			break;
        case 0:
            exit(1);
            break;
        default:
            printf("输入不合法！！\n");
            continue ;
        }

            printf("结果为：%.2lf\n",F1);

    }
    
    
}