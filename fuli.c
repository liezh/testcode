/**
	�˰汾����ǰ�����汾�Ļ���������� �ȶϢ�������� ���¹���
	���Ұ���ʵ��Ҫ����ǿ��ϵͳ�Ľ�׳�ԣ���֤������һ���ֵĴ����
	���ݣ�����򲻻������������������int����������double���͵�
	�ط����������ַ����ǻ���ʾ���������������롣

	����ͨ���궨��ʹ�ô����ü�࣬���м����޸ĵĲ���������ʶ
	���궨��������ǿ���ʹ�ñ�̱�ü򵥣��������������ĸ����ԡ�

**/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define WARN1   while(0 == 
#define WARN2   ){	while('\n' != getchar())	{	}	printf("���벻�Ϸ�!\n����������:	");		}

double danli()
{
    double P,F,i; //P�Ǳ���F�����棬i������
    int N; //������
    double nlx;
	printf("------���뵥������\n");
    printf("�����뱾��\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("������������\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("���������ޣ�\n");
    WARN1	scanf("%d",&N)	WARN2
    
    nlx = P*i;
    F = nlx*N + P;
    return F;
    
}

double fuli()
{
    
    double P,F,i; //P�Ǳ���F�����棬i������
    int N,W; //������
	printf("-------���븴������\n");
    printf("�����뱾��\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("������������\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("���������ޣ�\n");
    WARN1	scanf("%d",&N)	WARN2
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
	printf("-------���뱾�����\n");
    printf("���������棺\n");
    WARN1	scanf("%lf",&F)	WARN2
    printf("������������\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("���������ޣ�\n");
    WARN1	scanf("%d",&N)	WARN2
    printf("�����븴��������\n");
    WARN1	scanf("%d",&W)	WARN2
    i = pow(1+i/W,W)-1;
    P = F/pow((i+1),N);
    return P;
}

double TZtime()
{
    double year;
    double P,F,i; //P�Ǳ���F�����棬i������
    int W; //������
	printf("-------����Ͷ��ʱ�����\n");
    printf("�����뱾��\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("���������棺\n");
    WARN1	scanf("%lf",&F)	WARN2
    printf("������������\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("�����븴��������\n");
    WARN1	scanf("%d",&W)	WARN2
    i = pow((1+i/W),W)-1;
    year = log(F/P)/log(1+i);
    return year;
    
}
double bestProject()
{
    double P,F,i;
    int N,W;
	printf("-------������Ŀ���ʼ���\n");
	printf("�����뱾��\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("���������棺\n");
    WARN1	scanf("%lf",&F)	WARN2
    printf("����������\n");
    WARN1	scanf("%d",&N)	WARN2
    printf("�����븴��������\n");
    WARN1	scanf("%d",&W)	WARN2
    i = W*(pow(pow(F/P,1.0/N),1.0/W)-1.0);
    return i;
    
    
}

double sum()
{
    double y,F=0.0,i;
    int N;
    int ch;
	printf("-------���붨Ͷ����\n");
    printf("####### 1-��Ͷ��  2-��Ͷ�� #######\n");
    WARN1	scanf("%d",&ch)	WARN2
    if(ch == 1)
    {
        printf("��������Ͷ�ʶ\n");
        WARN1	scanf("%lf",&y)	WARN2
    }
    else
    {
        printf("��������Ͷ�ʶ\n");
        WARN1	scanf("%lf",&y)	WARN2
    }
    
    printf("������������\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("����������\n");
    WARN1	scanf("%d",&N)	WARN2
    //        printf("�����븴��������\n");
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
	printf("-------���뱾Ϣ�������\n");
    printf("����������\n");
    WARN1	scanf("%lf",&P)	WARN2
    printf("�����������ʣ�\n");
    WARN1	scanf("%lf",&i)	WARN2
    printf("������黹���ޣ�\n");
    WARN1	scanf("%d",&N)	WARN2

		//ÿ�»����=[�����������ʡ���1+�����ʣ�^��������]��[��1+�����ʣ�^����������1]

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
        printf("*************���������(4.0)************\n");
        
        printf("------    1 ����                  ------\n");
        printf("------    2 ����                  ------\n");
        printf("------    3 �������              ------\n");
        printf("------    4 Ͷ�����޹���          ------\n");
        printf("------    5 ����Ͷ����Ŀ���ʹ���  ------\n");
        printf("------    6 ����Ͷ���������      ------\n");
	    printf("------    7 �ȶϢ�������      ------\n");
        printf("------    0 �˳�                  ------\n");
		printf("��ѡ��    ");
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
            printf("���벻�Ϸ�����\n");
            continue ;
        }

            printf("���Ϊ��%.2lf\n",F1);

    }
    
    
}