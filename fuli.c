#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double danli()
{
	double P,F,i; //P�Ǳ���F�����棬i������
	int N; //������
	double nlx;
	printf("�����뱾��\n");
	scanf("%lf",&P);
	printf("������������\n");
	scanf("%lf",&i);
	printf("���������ޣ�\n");
	scanf("%d",&N);
	
	nlx = P*i;
	F = nlx*N + P;
	return F;
	
}

double fuli()
{
	
	double P,F,i; //P�Ǳ���F�����棬i������
	int N,W; //������
	printf("�����뱾��\n");
	scanf("%lf",&P);
	printf("������������\n");
	scanf("%lf",&i);
	printf("���������ޣ�\n");
	scanf("%d",&N);
	printf("�����븴��������\n");
	scanf("%d",&W);
	
	i=pow(1+i/W,W)-1;
	F=P*pow((i+1),N);
	return F;
}

double gusuan()
{
	double P,F,i; //P�Ǳ���F�����棬i������
	int N,W; //������
	printf("���������棺\n");
	scanf("%lf",&F);
	printf("������������\n");
	scanf("%lf",&i);
	printf("���������ޣ�\n");
	scanf("%d",&N);
	printf("�����븴��������\n");
	scanf("%d",&W);
	i = pow(1+i/W,W)-1;
	P = F/pow((i+1),N);
	return P;
}

double TZtime()
{
	double year;
	double P,F,i; //P�Ǳ���F�����棬i������
	int N,W; //������
	printf("�����뱾��\n");
	scanf("%lf",&P);
	printf("���������棺\n");
	scanf("%lf",&F);
	printf("������������\n");
	scanf("%lf",&i);
	printf("�����븴��������\n");
	scanf("%d",&W);
	i = pow((1+i/W),W)-1;
	year = log(F/P)/log(1+i);
	return year;
	
}
double bestProject()
{
	double P,F,i;
	int N,W;
	printf("�����뱾��\n");
	scanf("%lf",&P);
	printf("���������棺\n");
	scanf("%lf",&F);
	printf("����������\n");
	scanf("%d",&N);
	printf("�����븴��������\n");
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
	printf("####### 1-��Ͷ��  2-��Ͷ�� #######\n");
	scanf("%d",&ch);
	if(ch == 1)
	{
		printf("��������Ͷ�ʶ\n");
		scanf("%lf",&y);
	}
	else
	{
		printf("��������Ͷ�ʶ\n");
		scanf("%lf",&moon);
	}
	
	printf("������������\n");
	scanf("%lf",&i);
	printf("����������\n");
	scanf("%d",&N);
	//		printf("�����븴��������\n");
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
		printf("***********���������(3.0)**********\n");
		
		printf("------    1 ����                  ------\n");
		printf("------    2 ����                  ------\n");
		printf("------    3 �������              ------\n");
		printf("------    4 Ͷ�����޹���          ------\n");
		printf("------    5 ����Ͷ����Ŀ���ʹ���  ------\n");
		printf("------    6 ����Ͷ���������      ------\n");
		printf("------    0 �˳�                  ------\n");
		printf("��ѡ��	");
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
		
		printf("���Ϊ��%.2lf\n",F1);
	}
	
	
}