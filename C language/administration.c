/*

 * ��Ŀ���ƣ�ѧ���ɼ�����ϵͳ
 
 * ���ߣ�Mr.Wang 
 
 * ����ʵ������ɾ���ġ��顢���桢���롢���򡢷ֶεȹ���
 
 * ����ʱ�䣺��һ��ѧ��
 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>     //ϵͳʱ�� 
#include<conio.h>
#include<windows.h>  //ϵͳ������
struct Student       //����ṹ�����
    {
        char cla[20];
        char name[20];
        long long int num;
        float score[5];
        float aver;
    }stu[1000];
struct Student stu[1000],*p=stu; //����ȫ��p->struct Student stu[]
int count=0,n=0;   //����ȫ�ֱ���count
//*************************************
//*************************************
//ѧ���ɼ�¼��
void input(struct Student stu[])
{
    void save(struct Student stu[]);
    int choose;
    int i;
    char tempcla[10]={"-1"};  //������ʱ�����ַ��������ڰ���-1�����ز˵� 
    a:
    system("cls");    //����
    fflush(stdin);    //��ջ����� 
    printf("��  ��  ¼  ��\n");
    printf("************************************************************************************************************\n");
    printf("����������\t\t�༶��������  ѧ�š�     ���ſγɼ�(���� Ӣ�� C���� ��������� ������̵���)\n");
    printf("�밴�մ˸�ʽ�������룺  1801  ���� 541813460***\t            100  100  100   100        100\n\n");
    printf("�༶(��-1���ز˵�)��");  //����༶
    while(scanf("%s",stu[count].cla)==0)   //�жϷ���ֵ����ȥ���ʹ���bug 
    {
        fflush(stdin);
        printf("��ʽ�������������룺");
    }
    if(strcmp(stu[count].cla,tempcla)==0)  //��-1���ز˵�
    {
        printf("\n����������ز˵���\n\n");
        system("pause");
        return;
    }
    while(strlen(stu[count].cla)>10)  //�ж��ַ�����
    {
        fflush(stdin);
        printf("�༶���벻����������¼��:");
        scanf("%s",stu[count].cla);
    }
    printf("\n������");  //��������
    fflush(stdin);
    while(scanf("%s",stu[count].name)==0)
    {
        fflush(stdin);
        printf("��ʽ�������������룺");
    }
    while(strlen(stu[count].name)>7)
    {
        fflush(stdin);
        printf("����������������¼��:");
        scanf("%s",stu[count].name);
    }
    printf("\nѧ�ţ�");    //��������
    w:
    fflush(stdin);
    while(scanf("%lld",&stu[count].num)==0)
    {
        fflush(stdin);
        printf("��ʽ�������������룺");
    }
    for(i=0;i<count;i++)     //�ж��ظ�ѧ��
    {
        if(stu[count].num==stu[i].num)
        {
            printf("���и�ѧ�ţ����������룺\n");
            goto w;
        }
    }
    printf("\n����(0~100)��");  //�������
    fflush(stdin);
    while(scanf("%f",&stu[count].score[0])==0)
    {
        fflush(stdin);
        printf("��ʽ�������������룺");
    }
    while(stu[count].score[0]<0||stu[count].score[0]>100)
    {
        fflush(stdin);
        printf("���ݳ��������������룺");
        scanf("%f",&stu[count].score[0]);
    }
    printf("\nӢ��(0~100)��");   //����Ӣ��
    fflush(stdin);
    while(scanf("%f",&stu[count].score[1])==0)
    {
        fflush(stdin);
        printf("��ʽ�������������룺");
    }
    while(stu[count].score[1]<0||stu[count].score[1]>100)
    {
        fflush(stdin);
        printf("���ݳ��������������룺");
        scanf("%f",&stu[count].score[1]);
    }
    printf("\nC����(0~100)��");  //����C����
    fflush(stdin);
    while(scanf("%f",&stu[count].score[2])==0)
    {
        fflush(stdin);
        printf("��ʽ�������������룺");
    }
    while(stu[count].score[2]<0||stu[count].score[2]>100)
    {
        fflush(stdin);
        printf("���ݳ��������������룺");
        scanf("%f",&stu[count].score[2]);
    }
    printf("\n���������(0~100)��");  //������������
    fflush(stdin);
    while(scanf("%f",&stu[count].score[3])==0)
    {
        fflush(stdin);
        printf("��ʽ�������������룺");
    }
    while(stu[count].score[3]<0||stu[count].score[3]>100)
    {
        fflush(stdin);
        printf("���ݳ��������������룺");
        scanf("%f",&stu[count].score[3]);
    }
    printf("\n������̵���(0~100)��"); //����������̵���
    fflush(stdin);
    while(scanf("%f",&stu[count].score[4])==0)
    {
        fflush(stdin);
        printf("��ʽ�������������룺");
    }
    while(stu[count].score[4]<0||stu[count].score[4]>100)
    {
        fflush(stdin);
        printf("���ݳ��������������룺");
        scanf("%f",&stu[count].score[4]);
    }
    stu[count].aver=(stu[count].score[0]+stu[count].score[1]+stu[count].score[2]+stu[count].score[3]+stu[count].score[4])/5.0;//����ƽ���ɼ� 
    count++;   //�ṹ��������+1
    save(p);   //�����ļ�
    fflush(stdin);
    printf("�Ƿ����¼�룺\n\n");
    printf("1.�� 2.��\n");
    fflush(stdin);
    printf("\n��ѡ��:");
    b:
    while(scanf("%d",&choose)==0)
    {
    	printf("������ĸ�ʽ�������������룺\n");
    	fflush(stdin);
    	goto b;
	}
   switch(choose)
    {
        case 1:goto a;break;
        case 2:return;break;
        default:printf("û�и���ţ����������룺");goto b;
    }
}
//*************************************
//*************************************
//ѧ���ɼ���ʾ
void print(struct Student stu[])
{
    void sort(struct Student stu[]);
    system("cls");
    if(count==0) printf("\n����δ¼��ѧ����Ϣ���뷵�ز˵�����¼�룡\n");
    sort(p);    //������
    return;
}
//*************************************
//*************************************
//ѧ�����ƾ���
void average(struct Student stu[])
{
	system("cls");
	int i;
	if(count==0) printf("\n����δ¼��ѧ����Ϣ���뷵�ز˵�����¼�룡\n");
	float aver[5];
	float total[5]={0};
	for(i = 0; i < count; i++)
	{
		total[0]+=stu[i].score[0];
		total[1]+=stu[i].score[1];
		total[2]+=stu[i].score[2];
		total[3]+=stu[i].score[3];
		total[4]+=stu[i].score[4];
	}
	aver[0]=total[0]/count;
	aver[1]=total[1]/count;
	aver[2]=total[2]/count;
	aver[3]=total[3]/count;
	aver[4]=total[4]/count;
	printf("����ƽ���ɼ���ʾ\n");
	printf("***************************************************************************************************\n");
	printf("����:\t%.2f\n",aver[0]);
	printf("Ӣ��:\t%.2f\n",aver[1]);
	printf("C����:\t%.2f\n",aver[2]);
	printf("���������:  %.2f\n",aver[3]);
	printf("������̵���:%.2f\n",aver[4]); 
    printf("***************************************************************************************************\n");
    system("pause");
    return;
} 
//*************************************
//*************************************
//ƽ���ɼ�����
void sort(struct Student stu[])
{
    void save(struct Student stu[]);
    system("cls");
    fflush(stdin);
    char tempname[20];  //��ʱ����
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    if(count==0) printf("\n\n����δ¼��ѧ����Ϣ���뷵�ز˵�����¼�룡\n\n");
    else
    {
        printf("\n�ɼ���ʾ(��ƽ���ɼ�����)\n");   //ð������
            for(i=0;i<count-1;i++)
            {
                for(j=0;j<count-i-1;j++)
                {
                    if(stu[j].aver<stu[j+1].aver)  //ע���ַ����ĸ��� 
                    {
                        strcpy(tempcla,stu[j].cla);strcpy(stu[j].cla,stu[j+1].cla);strcpy(stu[j+1].cla,tempcla);
                        strcpy(tempname,stu[j].name);strcpy(stu[j].name,stu[j+1].name);strcpy(stu[j+1].name,tempname);
                        t1=stu[j].num;stu[j].num=stu[j+1].num;stu[j+1].num=t1;
                        t=stu[j].score[0];stu[j].score[0]=stu[j+1].score[0];stu[j+1].score[0]=t;
                        t=stu[j].score[1];stu[j].score[1]=stu[j+1].score[1];stu[j+1].score[1]=t;
                        t=stu[j].score[2];stu[j].score[2]=stu[j+1].score[2];stu[j+1].score[2]=t;
                        t=stu[j].score[3];stu[j].score[3]=stu[j+1].score[3];stu[j+1].score[3]=t;
                        t=stu[j].score[4];stu[j].score[4]=stu[j+1].score[4];stu[j+1].score[4]=t;
                        t=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=t;

                    }
                }

            }
            printf("************************************************************************************************************\n");
            printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
            printf("************************************************************************************************************\n");
            for(i=0;i<count;i++)
                printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    save(p);   //�����ļ�
    }
    system("pause");
    return;
}
//*************************************
//*************************************
//�������ɼ�����
void mathsort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n�ɼ���ʾ(����ѧ�ɼ�����)\n");
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(stu[j].score[0]<stu[j+1].score[0])
            {
                strcpy(tempcla,stu[j].cla);strcpy(stu[j].cla,stu[j+1].cla);strcpy(stu[j+1].cla,tempcla);
                strcpy(tempname,stu[j].name);strcpy(stu[j].name,stu[j+1].name);strcpy(stu[j+1].name,tempname);
                t1=stu[j].num;stu[j].num=stu[j+1].num;stu[j+1].num=t1;
                t=stu[j].score[0];stu[j].score[0]=stu[j+1].score[0];stu[j+1].score[0]=t;
                t=stu[j].score[1];stu[j].score[1]=stu[j+1].score[1];stu[j+1].score[1]=t;
                t=stu[j].score[2];stu[j].score[2]=stu[j+1].score[2];stu[j+1].score[2]=t;
                t=stu[j].score[3];stu[j].score[3]=stu[j+1].score[3];stu[j+1].score[3]=t;
                t=stu[j].score[4];stu[j].score[4]=stu[j+1].score[4];stu[j+1].score[4]=t;
                t=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=t;
            }
        }
    }
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
        printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    printf("\n����������سɼ�����\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//��Ӣ��ɼ�����
void Engsort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n�ɼ���ʾ(��Ӣ��ɼ�����)\n");
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(stu[j].score[1]<stu[j+1].score[1])
            {
                strcpy(tempcla,stu[j].cla);strcpy(stu[j].cla,stu[j+1].cla);strcpy(stu[j+1].cla,tempcla);
                strcpy(tempname,stu[j].name);strcpy(stu[j].name,stu[j+1].name);strcpy(stu[j+1].name,tempname);
                t1=stu[j].num;stu[j].num=stu[j+1].num;stu[j+1].num=t1;
                t=stu[j].score[0];stu[j].score[0]=stu[j+1].score[0];stu[j+1].score[0]=t;
                t=stu[j].score[1];stu[j].score[1]=stu[j+1].score[1];stu[j+1].score[1]=t;
                t=stu[j].score[2];stu[j].score[2]=stu[j+1].score[2];stu[j+1].score[2]=t;
                t=stu[j].score[3];stu[j].score[3]=stu[j+1].score[3];stu[j+1].score[3]=t;
                t=stu[j].score[4];stu[j].score[4]=stu[j+1].score[4];stu[j+1].score[4]=t;
                t=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=t;
            }
        }
    }
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
    {
         printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    }
    printf("\n����������سɼ�����\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//��C��������
void Csort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n�ɼ���ʾ(��C���Գɼ�����)\n");
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(stu[j].score[2]<stu[j+1].score[2])
            {
                strcpy(tempcla,stu[j].cla);strcpy(stu[j].cla,stu[j+1].cla);strcpy(stu[j+1].cla,tempcla);
                strcpy(tempname,stu[j].name);strcpy(stu[j].name,stu[j+1].name);strcpy(stu[j+1].name,tempname);
                t1=stu[j].num;stu[j].num=stu[j+1].num;stu[j+1].num=t1;
                t=stu[j].score[0];stu[j].score[0]=stu[j+1].score[0];stu[j+1].score[0]=t;
                t=stu[j].score[1];stu[j].score[1]=stu[j+1].score[1];stu[j+1].score[1]=t;
                t=stu[j].score[2];stu[j].score[2]=stu[j+1].score[2];stu[j+1].score[2]=t;
                t=stu[j].score[3];stu[j].score[3]=stu[j+1].score[3];stu[j+1].score[3]=t;
                t=stu[j].score[4];stu[j].score[4]=stu[j+1].score[4];stu[j+1].score[4]=t;
                t=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=t;
            }
        }
    }
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
    {
         printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    }
    printf("\n����������سɼ�����\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//���������������
void comsort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n�ɼ���ʾ(������������ɼ�����)\n");
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(stu[j].score[3]<stu[j+1].score[3])
            {
                strcpy(tempcla,stu[j].cla);strcpy(stu[j].cla,stu[j+1].cla);strcpy(stu[j+1].cla,tempcla);
                strcpy(tempname,stu[j].name);strcpy(stu[j].name,stu[j+1].name);strcpy(stu[j+1].name,tempname);
                t1=stu[j].num;stu[j].num=stu[j+1].num;stu[j+1].num=t1;
                t=stu[j].score[0];stu[j].score[0]=stu[j+1].score[0];stu[j+1].score[0]=t;
                t=stu[j].score[1];stu[j].score[1]=stu[j+1].score[1];stu[j+1].score[1]=t;
                t=stu[j].score[2];stu[j].score[2]=stu[j+1].score[2];stu[j+1].score[2]=t;
                t=stu[j].score[3];stu[j].score[3]=stu[j+1].score[3];stu[j+1].score[3]=t;
                t=stu[j].score[4];stu[j].score[4]=stu[j+1].score[4];stu[j+1].score[4]=t;
                t=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=t;
            }
        }
    }
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
    {
         printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    }
    printf("\n����������سɼ�����\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//��������̵�������
void softsort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n�ɼ���ʾ(��������̵��۳ɼ�����)\n");
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(stu[j].score[4]<stu[j+1].score[4])
            {
                strcpy(tempcla,stu[j].cla);strcpy(stu[j].cla,stu[j+1].cla);strcpy(stu[j+1].cla,tempcla);
                strcpy(tempname,stu[j].name);strcpy(stu[j].name,stu[j+1].name);strcpy(stu[j+1].name,tempname);
                t1=stu[j].num;stu[j].num=stu[j+1].num;stu[j+1].num=t1;
                t=stu[j].score[0];stu[j].score[0]=stu[j+1].score[0];stu[j+1].score[0]=t;
                t=stu[j].score[1];stu[j].score[1]=stu[j+1].score[1];stu[j+1].score[1]=t;
                t=stu[j].score[2];stu[j].score[2]=stu[j+1].score[2];stu[j+1].score[2]=t;
                t=stu[j].score[3];stu[j].score[3]=stu[j+1].score[3];stu[j+1].score[3]=t;
                t=stu[j].score[4];stu[j].score[4]=stu[j+1].score[4];stu[j+1].score[4]=t;
                t=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=t;
            }
        }
    }
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
    {
        printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    }
    printf("\n����������سɼ�����\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//�ɼ�����
void projectsort(struct Student stu[])
{
    if(count==0)
    {
        printf("\n\n����δ¼��ѧ����Ϣ���뷵�ز˵�����¼�룡\n\n");
        system("pause");
        return;
    }
    int choose;
    system("cls");
    fflush(stdin);
    choose:   //�ɼ�����ҳ��˵�
    printf("\n\t\t\t\t\t\t   �ɼ�����\n\n");
    printf("\t\t\t\t****************************************************\n\n");
    printf("\t\t\t\t        |1. ����\t     2. Ӣ��      |\n\n");
    printf("\t\t\t\t        |3. C����\t     4. ���������|\n\n");
    printf("\t\t\t\t        |5. ������̵���     6. ƽ���ɼ�  |\n\n");
    printf("\t\t\t\t        |7. ���ز˵�\t\t\t  |\n");
    printf("\t\t\t\t****************************************************\n\n");
    printf("\t\t\t\t��ѡ��");
    a:
    while(scanf("%d",&choose)==0)
    {
        printf("�����ʽ���������������룺");
        fflush(stdin);
    }
    switch(choose)
    {
	    case 1:
	        mathsort(p);
	        system("cls");
	        goto choose;
	        break;
	    case 2:
	        Engsort(p);
	        system("cls");
	        goto choose;
	        break;
	    case 3:
	        Csort(p);
	        system("cls");
	        goto choose;
	        break;
	    case 4:
	        comsort(p);
	        system("cls");
	        goto choose;
	        break;
	    case 5:
	        softsort(p);
	        system("cls");
	        goto choose;
	        break;
	    case 6:
	        sort(p);
	        system("cls");
	        goto choose;
	        break;
	    case 7:
	        printf("����������ز˵���\n\n");
	        system("pause");
	        return;
	    default:
	        printf("û�и���ţ������������룺");goto a;
    }

}
//*************************************
//*************************************
//��ѧ�Ų�ѯ
void findnum(struct Student stu[])
{
    int i;
    int searchindex=-1;  //�����±�ֵ 
    long long int searchnum;
    fflush(stdin);
    printf("\n�������ѯ�ɼ���ѧ��ѧ�ţ�");
    scanf("%lld",&searchnum);
    for(i=0;i<count;i++)
    {
        if(searchnum==stu[i].num)
        {
            system("cls");
            searchindex=i;
            printf("************************************************************************************************************\n");
            printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
            printf("************************************************************************************************************\n");
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            break;  //�ҵ������� 
        }
    }
    if(searchindex==-1)
        printf("\n�ܱ�Ǹ��û���ҵ���ѧ����ѧ�ţ�\n\n");
    printf("\n����������سɼ���ѯ\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//��������ѯ
void findname(struct Student stu[])
{
    int i;
    char searchname[20];
    int searchindex=-1;
    fflush(stdin);
    printf("\n�������ѯ�ɼ�ѧ����������\n");
    scanf("%s",searchname);
    for(i=0;i<count;i++)  //ѭ��Ѱ������
    {
        if(strcmp(searchname,stu[i].name)==0)
        {
            system("cls");
            searchindex=i;
            printf("************************************************************************************************************\n");
            printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
            printf("************************************************************************************************************\n");
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            break;//�ҵ�����
        }
    }
    if(searchindex==-1)
        printf("\n�ܱ�Ǹ��û���ҵ���ѧ����������\n\n");
    printf("\n����������سɼ���ѯ\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//�ɼ���ѯ
void find(struct Student stu[])
{
    if(count==0)
    {
        printf("\n\n����δ¼��ѧ����Ϣ���뷵�ز˵�����¼�룡\n\n");
        system("pause");
        return;
    }
    int choose;
    system("cls");
    fflush(stdin);
    choose:   //�ɼ���ѯҳ��˵�
    printf("\n\t\t\t\t\t\t  �ɼ���ѯ\n\n");
    printf("\t\t\t\t\t*****************************\n\n");
    printf("\t\t\t\t\t |1.��ѧ�Ų��� 2.����������|\n\n");
    printf("\t\t\t\t\t |3.ȫ����ʾ   4.���ز˵�  |\n\n");
    printf("\t\t\t\t\t*****************************\n");
    printf("\t\t\t\t\t\n�������ѯ��ʽ:");
    a:
    while(scanf("%d",&choose)==0)
    {
        printf("�����ʽ���������������룺");
        fflush(stdin);
    }
    switch(choose)
    {
	    case 1:
	        findnum(p);
	        system("cls");
	        goto choose;
	        break;
	    case 2:
	        findname(p);
	        system("cls");
	        goto choose;
	        break;
	    case 3:
	        print(p);
	        system("cls");
	        goto choose;
	        break;
	    case 4:
	        printf("\n����������ز˵���\n\n");
	        system("pause");
	        return;
	    default:
	        printf("û�и���ţ������������룺");goto a;
    }
}
//*************************************
//*************************************
//ɾ���ɼ�
void del(struct Student stu[])
{
    void delnum(struct Student stu[]);
    void delname(struct Student stu[]);
    void save(struct Student stu[]);
    int choose;
    if(count==0)
    {
        printf("\n\n����δ¼��ѧ����Ϣ���뷵�ز˵�����¼�룡\n\n");
        system("pause");
        return;
    }
    choose:
    fflush(stdin);   //ɾ���ɼ�ҳ��˵�
    printf("\n\t\t\t\t\t     ɾ���ɼ�\n\n");
    printf("\t\t\t\t********************************\n\n");
    printf(" \t\t\t\t\t   1.��ѧ��ɾ��\n\n\t\t\t\t\t   2.������ɾ��\n\n\t\t\t\t\t   3.���ز˵�\n\n");
    printf("\t\t\t\t********************************\n\n");
    printf("������ɾ����ʽ��");
    a:
    while(scanf("%d",&choose)==0)
    {
        printf("�����ʽ���������������룺");
        fflush(stdin);
    }
    switch(choose)
    {
	    case 1:
	        delnum(p);
	        save(p);
	        system("cls");
	        goto choose;
	        break;
	    case 2:
	        delname(p);
	        save(p);
	        system("cls");
	        goto choose;
	        break;
	    case 3:
	        printf("\n����������ز˵���\n\n");
	        system("pause");
	        return;
	    default:
	        printf("û�и���ţ������������룺");goto a;
    }

}
//*************************************
//*************************************
//��ѧ��ɾ���ɼ�
void delnum(struct Student stu[])
{
    void print(struct Student stu[]);
    int i,choose;
    int searchindex=-1;
    long long int deletenum;
    fflush(stdin);
    printf("������Ҫɾ��ѧ����ѧ��(��-1���أ���");
    scanf("%lld",&deletenum);
    printf("�Ƿ�ȷ��ɾ����\n");
    fflush(stdin);
    printf("1.�� 2.��\n");
    fflush(stdin);
    printf("��ѡ��:");
    b:
    while(scanf("%d",&choose)==0)
    {
    	printf("������ĸ�ʽ�������������룺\n");
    	fflush(stdin);
    	goto b;
	}
    switch(choose)
    {
        case 1:break;
        case 2:return;break;
        default:printf("û�и���ţ����������룺");goto b;
    }
    if(deletenum==-1)
    {
        printf("\n�����������ɾ���ɼ���\n\n");
        system("pause");
        return;
    }
    for(i=0;i<count;i++)
    {
        if(deletenum==stu[i].num)
        {
            searchindex=i;
            break;
        }
    }
    if(searchindex==-1)
    {
        printf("\n���ź���δ���ҵ���Ҫɾ��ѧ����ѧ�ţ�\n");
        printf("\n����������ز˵�\n\n");
        system("pause");
        return;
    }
    else  //������Ϣ��ÿ��������ǰ���и���
    {
        for(i=searchindex;i<count-1;i++)
        {
            strcpy(stu[i].cla,stu[i+1].cla);
            stu[i].num=stu[i+1].num;
            strcpy(stu[i].name,stu[i+1].name);
            stu[i].score[0]=stu[i+1].score[0];
            stu[i].score[1]=stu[i+1].score[1];
            stu[i].score[2]=stu[i+1].score[2];
            stu[i].score[3]=stu[i+1].score[3];
            stu[i].score[4]=stu[i+1].score[4];
            stu[i].aver=stu[i+1].aver;
        }
        count--;  //��������-1
    }
    if(count==0)
    {
        printf("\nĿǰû��ѧ����Ϣ���뷵�ز˵�¼��!\n\n");
        system("pause");
        return;
    }
    system("cls");  //ɾ������д�ӡ
    printf("\nɾ���ɹ���\n\n");
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
         printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    printf("\n����������ز˵�\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//������ɾ���ɼ�
void delname(struct Student stu[])
{
    void print(struct Student stu[]);
    int i,choose;
    char tempname[10]={"-1"};
    int searchindex=-1;
    char deletename[20];
    fflush(stdin);
    printf("������Ҫɾ��ѧ������������-1���أ���");
    scanf("%s",deletename);
    printf("�Ƿ�ȷ��ɾ����\n");
    fflush(stdin);
    printf("1.�� 2.��\n");
    fflush(stdin);
    printf("��ѡ��:");
    b:
    while(scanf("%d",&choose)==0)
    {
    	printf("������ĸ�ʽ�������������룺\n");
    	fflush(stdin);
    	goto b;
	}
	switch(choose)
    {
        case 1:;break;
        case 2:return;break;
        default:printf("û�и���ţ����������룺");goto b;
    }
    if(strcmp(deletename,tempname)==0)
    {
        printf("\n�����������ɾ���ɼ���\n\n");
        system("pause");
        return;
    }
    for(i=0;i<count;i++)
    {
        if(strcmp(deletename,stu[i].name)==0)
        {
            searchindex=i;
            break;
        }
    }
    if(searchindex==-1)
    {
        printf("\n���ź���δ���ҵ���Ҫɾ��ѧ����������\n");
        printf("\n����������ز˵�\n\n");
        system("pause");
        return;
    }
    else
    {
        for(i=searchindex;i<count-1;i++)
        {
            strcpy(stu[i].cla,stu[i+1].cla);
            stu[i].num=stu[i+1].num;
            strcpy(stu[i].name,stu[i+1].name);
            stu[i].score[0]=stu[i+1].score[0];
            stu[i].score[1]=stu[i+1].score[1];
            stu[i].score[2]=stu[i+1].score[2];
            stu[i].score[3]=stu[i+1].score[3];
            stu[i].score[4]=stu[i+1].score[4];
            stu[i].aver=stu[i+1].aver;
        }
        count--;
    }
    printf("\n");
    printf("\nɾ���ɹ���\n\n");
    if(count==0)
    {
        printf("\nĿǰû��ѧ����Ϣ���뷵�ز˵�¼��!\n\n");
        system("pause");
        return;
    }
    system("cls");
    printf("\nɾ���ɹ���\n\n");
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
        printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    printf("\n����������ز˵�\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//�޸ĳɼ�
void change(struct Student stu[])
{
    void save(struct Student stu[]);
    int i,j;
    int choose;
    long long int searchnum,tempnum;
    int searchindex=-1;
    if(count==0)
    {
        printf("\n\n����δ¼��ѧ����Ϣ���뷵�ز˵�����¼�룡\n\n");
        system("pause");
        return;
    }
    a:
    system("cls");
    printf("\n�޸ĳɼ���\n\n");
    fflush(stdin);
    printf("************************************************\n");
    printf("\n�������޸�ѧ����ѧ�ţ�(��-1���ز˵���");
    scanf("%lld",&searchnum);
    fflush(stdin);
    if(searchnum==-1)
    {
        printf("\n����������ز˵���\n\n");
        system("pause");
        return;
    }
    system("cls");
    for(i=0;i<count;i++)
    {
        if(searchnum==stu[i].num)
        {
            searchindex=i;
            printf("\n��ѧ����Ϣ��\n");  //�޸ĳɼ�ҳ��˵�
            printf("************************************************************************************************************\n");
            printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
            printf("************************************************************************************************************\n");
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            printf("************************************************\n");
            printf("|1.�޸İ༶\t       2. �޸�����            |\n");
            printf("|3.�޸�ѧ��\t       4. �޸ĸ���            |\n");
            printf("|5.�޸�Ӣ��\t       6. �޸�C����           |\n");
            printf("|7.�޸ļ��������      8. �޸�������̵���    |\n");
            printf("|9.���ز˵�\t                              |\n");
            printf("************************************************\n");
            printf("��ѡ���޸ĵ���Ϣ��");
            choose:
            while(scanf("%d",&choose)==0)
            {
                printf("�����ʽ���������������룺");
                fflush(stdin);
            }
            switch(choose)
            {
	            case 1:
	                fflush(stdin);
	                printf("���޸İ༶:");
	                while(scanf("%s",stu[i].cla)==0)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                }
	                while(strlen(stu[count].cla)>10)  //�ж��ַ�����
	                {
	                    printf("�༶���벻����������¼��:");
	                    fflush(stdin);
	                    scanf("%s",stu[count].cla);
	                }
	                break;
	            case 2:
	                fflush(stdin);
	                printf("���޸�����:");
	                while(scanf("%s",stu[i].name)==0)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                }
	                while(strlen(stu[count].name)>10)  //�ж��ַ�����
	                {
	                    printf("�༶���벻����������¼��:");
	                    fflush(stdin);
	                    scanf("%s",stu[count].name);
	                }
	                break;
	            case 3:
	                fflush(stdin);
	                printf("���޸�ѧ��:");
	                w:
	                while(scanf("%lld",&stu[i].num)==0)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                }
	                tempnum=stu[i].num;
	                stu[i].num=0;
	                for(j=0;j<count;j++)
	                {
	                    if(tempnum==stu[j].num)
	                    {
	                        printf("���и�ѧ�ţ����������룺\n");
	                        goto w;
	                    }
	                }
	                stu[i].num=tempnum;
	                break;
	            case 4:
	                fflush(stdin);
	                printf("���޸ĸ���:");
	                while(scanf("%f",&stu[i].score[0])==0)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                }
	                while(stu[i].score[0]<0||stu[i].score[0]>100)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[0]);
	                }
	                break;
	            case 5:
	                fflush(stdin);
	                printf("���޸�Ӣ��:");
	                while(scanf("%f",&stu[i].score[1])==0)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                }
	                while(stu[i].score[1]<0||stu[i].score[1]>100)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[1]);
	                }
	                break;
	            case 6:
	                fflush(stdin);
	                printf("���޸�C����:");
	                while(scanf("%f",&stu[i].score[2])==0)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                }
	                while(stu[i].score[2]<0||stu[i].score[2]>100)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[2]);
	                }
	                break;
	            case 7:
	                fflush(stdin);
	                printf("���޸ļ��������:");
	                while(scanf("%f",&stu[i].score[3])==0)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                }
	                while(stu[i].score[3]<0||stu[i].score[3]>100)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[3]);
	                }
	                break;
	            case 8:
	                fflush(stdin);
	                printf("���޸�������̵���:");
	                while(scanf("%f",&stu[i].score[4])==0)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                }
	                while(stu[i].score[4]<0||stu[i].score[4]>100)
	                {
	                    printf("��ʽ�������������룺");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[4]);
	                }
	                break;
	            case 9:
	                printf("\n����������ز˵���\n\n");
	                save(p);
	                return;
	            default:
	                printf("û�и���ţ������������룺");
	                goto choose;
            }//switch��β�� 
            stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2]+stu[i].score[3]+stu[i].score[4])/5.0;
            printf("\n�޸ĳɹ���\n");
            printf("************************************************************************************************************\n");
            printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n");
            printf("************************************************************************************************************\n");
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
        }//if������
    }//for������
    if(searchindex==-1)
    {
        printf("\n�ܱ�Ǹ��δ���ҵ���ѧ��������������ѧ��!\n\n");
        system("pause");
        goto a;
    }
    save(p);
    system("pause");
    return;
}
//*************************************
//*************************************
//�ɼ��ֶ�
void section(struct Student stu[])
{
    int a=0,b=0,c=0;
    if(count==0)
    {
        printf("\n\n����δ¼��ѧ����Ϣ���뷵�ز˵�����¼�룡\n\n");
        system("pause");
        return;
    }
    printf("�ɼ��ֶ�\n");
    int i;
    printf("\n\n");
    printf("�����ͬѧ(80~100)\n");
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n\n");
    for(i=0;i<count;i++)
    {
        if(stu[i].aver>=80)
        {
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            a++;
        }
    }
    printf("************************************************************************************************************\n");
    printf("һ����%d��\n",a);
    printf("\n\n");
    printf("���õ�ͬѧ(60~79)\n");
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n\n");
    for(i=0;i<count;i++)
    {
        if(stu[i].aver>=60&&stu[i].aver<80)
        {
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            b++;
        }
    }
    printf("************************************************************************************************************\n");
    printf("һ����%d��\n",b);
    printf("\n\n");
    printf("�������ͬѧ(0~59)\n");
    printf("************************************************************************************************************\n");
    printf("\t�༶\t����\tѧ��\t\t����\tӢ��\tC����\t���������\t������̵���\tƽ���ɼ�\t\n\n");
    for(i=0;i<count;i++)
    {
        if(stu[i].aver<60)
        {
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            c++;
        }
    }
    printf("************************************************************************************************************\n");
    printf("һ����%d��\n",c);
    printf("\n\n");
    printf("����������ز˵�!\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//�ļ�����
void read(struct Student stu[])
{
    int i;
    FILE*fp;
    if((fp=fopen("student.bat","rb"))==NULL)
        return;
    for(i=0;i<1000;i++)
    {
        if(fread(&stu[i],sizeof(struct Student),1,fp)!=1)
        {
            if(feof(fp))
            {
                fclose(fp);
                goto a;
            }
            printf("file read error\n");
        }
        count++;  //����һ������������+1
    }
    fclose(fp);
    a:
    printf("\n�����ļ��ѳɹ���ף��ʹ����죡\n\n");
    printf("�밴���������ҳ��˵���\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//�ļ��洢
void save(struct Student stu[])
{
    int i;
    FILE*fp;
    fp=fopen("student.bat","wb");
    for(i = 0; i < count; i++)
    {
        if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
            printf("file write error\n");
    }
    fclose(fp);
    printf("\n�ѱ������ļ���\n\n");
    //system("pause");
}
//*************************************
//*************************************
//������
int main()
{
    system("color 9E"); //���ñ�����ɫ
    int i=4;
    char code[20]={'1','2','3','4','5','6'},password[20];
	int x;
	char c;
    //��ʼҳ��
    time_t timep;    //ϵͳʱ�� 
	struct tm *p_1;
	time (&timep);
	p_1=gmtime(&timep);
	printf("\t\t\t\t\t\t  ��ǰʱ��%02dʱ%02d��%\n",8+p_1->tm_hour,p_1->tm_min); 
	printf("\t\t\t\t\t\t   %d��%02d��%02d��\n",1900+p_1->tm_year,1+p_1->tm_mon,p_1->tm_mday);
    printf("\t������������������������������������������������������\n\n");
    printf("\t��\t\t\t\t\t������Զ�����������ֺ��� \t\t\t\t\t��\n\n");
    printf("\t��\t\t\t*****************************************************\t\t\t\t��\n\n");
    printf("\t��\t\t\t\t\t ѧ �� �� �� ϵ ͳ\t\t\t\t\t\t��\n\n");
    printf("\t��\t\t\t  ������:Mr.Wang רҵ:�������1801 ѧ��:************\t\t\t\t��\n\n");
    printf("\t��\t\t\t*****************************************************\t\t\t\t��\n\n");
    printf("\t��\t\t\t  ��ӭʹ���������18-01��ѧ������ϵͳ,ף��ʹ�����! \t\t\t\t��\n\n");
    printf("\t������������������������������������������������������\n\n"); 
	printf("��������λ��½���룡\n");
	q:
	x=0;
	while(x<6 && c!=13)
	{
		c=getch();
		if(c!=13)
		putchar('*');
		password[x++]=c;
	}
	password[x]='\0';
    if(strcmp(password,code)!=0)
    {
    	fflush(stdin);
        printf("\n������������������%d�λ��ᣬ���������룺",i--);
        if(i==-1)
        {
            exit(0);
        }
        goto q;
    }
    read(p); //�����ļ�
    system("cls");    //����
    //ҳ��˵�
    menu:
    system("cls");
    time (&timep);
	p_1=gmtime(&timep);
    printf("\t\t\t\t\t\t   ��ǰʱ��%02dʱ%02d��%\n",8+p_1->tm_hour,p_1->tm_min); 
	printf("\t\t\t\t\t\t    %d��%02d��%02d��\n",1900+p_1->tm_year,1+p_1->tm_mon,p_1->tm_mday);
    printf("\n");
    printf("\t\t\t\t\t\t    ҳ  ��  ��  ��\n");
    printf("\n");
    printf("\t\t���������������������������������������������������������������������������������\n\n");
    printf("\t\t\t   | 1. �ɼ�¼��\t\t2. �ɼ���ʾ\t\t3. ���ƾ���  |\n\n");
    printf("\t\t\t   | 4. �ɼ�����\t\t5. �ɼ�����\t\t6. ��Ϣ�޸�  |\n\n");
    printf("\t\t\t   | 7. ɾ���ɼ�\t\t8. �ɼ��ֶ�\t\t0. �˳�ϵͳ  |\n\n");
    printf("\t\t���������������������������������������������������������������������������������\n");
    printf("\t\t\t\t\t\t          * \n");
    printf("\t\t\t\t\t\t         *** \n");
    printf("\t\t\t\t\t\t        ***** \n");
    printf("\t\t\t\t\t\t       *******\n");
    printf("\t\t\t\t\t\t      *********\n");
    printf("\t\t\t\t\t\t     *********** \n");
    //printf("\t\t\t\t\t\t**********************\n");
    printf("\t\t\t\t\t\t ********************\n");
    printf("\t\t\t\t\t\t  ******************\n");
    printf("\t\t\t\t\t\t   ******* ********\n");
    printf("\t\t\t\t\t\t  *******   ********\n");
    printf("\t\t\t\t\t\t ******       *******\n");
    printf("\t\t\t\t\t\t******          ******\n");
    printf("��ѡ����Ӧ��ţ�");
    int choose;
    int a; 
    w:
    while(scanf("%d",&choose)==0)
    {
        printf("��ʽ�������������룺");
        fflush(stdin);
    }
    switch(choose)
    {
    	case 1:   //�ɼ�¼��
	        system("cls");
	        printf("ѧ���ɼ�¼��\n");
	        input(p);
	        goto menu;
	    case 2:  //�ɼ���ʾ������
	    	system("cls");
	        printf("ѧ���ɼ���ʾ\n");
	        print(p);
	        goto menu;
	    case 3:  //���Ƴɼ� 
	    	system("cls");
			average(p);
			goto menu;
	    case 4:  //�ɼ�����
	    	 system("cls");
	        projectsort(p);
	        goto menu;
	    case 5:  //�ɼ�����
	        system("cls");
	        find(p);
	        goto menu;
	    case 6:  //�ɼ��޸�
		    system("cls");
	        change(p);
	        goto menu;
	    case 7:  //�ɼ�ɾ��
		    system("cls");
	        del(p);
	        goto menu;
	    case 8:  //�ɼ��ֶ�
		    system("cls");
	        section(p);
	        goto menu;
	    case 0: //�˳�ϵͳ
	        fflush(stdin);
	        printf("\n�Ƿ�����˳���\n");
	        printf("\n1. �� 2. ��\n\n");
	        back:
	        printf("��ѡ��:");
	        while(scanf("%d",&a)==0)
	        {
	        	fflush(stdin);
	        	printf("�������ʽ�������������룺");
			}
	        if(a==1)
	        {
	            system("cls");
	            //����ͼ�� 
	            float y, x, b;
	            for (y = 1.5f;y > -1.5f;y -= 0.1f)
	            {
	                for (x = -1.5f;x < 1.5f;x += 0.05f)
	                {
	                    b = x*x + y*y - 1;
	                    putchar(b*b*b - x*x*y*y*y <= 0.0f ? '*' : ' ');
	                }
	                putchar('\n');
	            }
	            Sleep(1000);  //���� 
	            printf("��ӭ�´μ���ʹ�ñ���Ʒ!\n");
	            printf("�����˳������Ժ�.");
	            Sleep(500);
	            printf(".");
	            Sleep(500);
	            printf(".");
	            Sleep(500);
	            printf(".");
	            Sleep(500);
	            printf(".");
	            Sleep(500);
	            printf(".");
	            Sleep(500);
	            exit(0);
	        }//if(a==1)������ 
	        if(a==2)goto menu;
	        if(a!=1||a!=2)printf("����������������:\n");goto back;
	    default:
	    	printf("û�и���ţ����������룺");
        	goto w;
	}//switch������ 
    return 0;
}
