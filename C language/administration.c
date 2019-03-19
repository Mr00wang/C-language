/*

 * 项目名称：学生成绩管理系统
 
 * 作者：Mr.Wang 
 
 * 需求：实现增、删、改、查、保存、导入、排序、分段等功能
 
 * 开发时间：大一上学期
 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>     //系统时间 
#include<conio.h>
#include<windows.h>  //系统函数库
struct Student       //定义结构体变量
    {
        char cla[20];
        char name[20];
        long long int num;
        float score[5];
        float aver;
    }stu[1000];
struct Student stu[1000],*p=stu; //定义全局p->struct Student stu[]
int count=0,n=0;   //定义全局变量count
//*************************************
//*************************************
//学生成绩录入
void input(struct Student stu[])
{
    void save(struct Student stu[]);
    int choose;
    int i;
    char tempcla[10]={"-1"};  //定义临时姓名字符串，用于按（-1）返回菜单 
    a:
    system("cls");    //清屏
    fflush(stdin);    //清空缓存区 
    printf("成  绩  录  入\n");
    printf("************************************************************************************************************\n");
    printf("请依次输入\t\t班级、姓名、  学号、     五门课成绩(高数 英语 C语言 计算机基础 软件工程导论)\n");
    printf("请按照此格式进行输入：  1801  张三 541813460***\t            100  100  100   100        100\n\n");
    printf("班级(按-1返回菜单)：");  //输入班级
    while(scanf("%s",stu[count].cla)==0)   //判断返回值，除去类型错误bug 
    {
        fflush(stdin);
        printf("格式有误，请重新输入：");
    }
    if(strcmp(stu[count].cla,tempcla)==0)  //按-1返回菜单
    {
        printf("\n按任意键返回菜单！\n\n");
        system("pause");
        return;
    }
    while(strlen(stu[count].cla)>10)  //判断字符长度
    {
        fflush(stdin);
        printf("班级输入不合理，请重新录入:");
        scanf("%s",stu[count].cla);
    }
    printf("\n姓名：");  //输入姓名
    fflush(stdin);
    while(scanf("%s",stu[count].name)==0)
    {
        fflush(stdin);
        printf("格式有误，请重新输入：");
    }
    while(strlen(stu[count].name)>7)
    {
        fflush(stdin);
        printf("姓名不合理，请重新录入:");
        scanf("%s",stu[count].name);
    }
    printf("\n学号：");    //输入姓名
    w:
    fflush(stdin);
    while(scanf("%lld",&stu[count].num)==0)
    {
        fflush(stdin);
        printf("格式有误，请重新输入：");
    }
    for(i=0;i<count;i++)     //判断重复学号
    {
        if(stu[count].num==stu[i].num)
        {
            printf("已有该学号，请重新输入：\n");
            goto w;
        }
    }
    printf("\n高数(0~100)：");  //输入高数
    fflush(stdin);
    while(scanf("%f",&stu[count].score[0])==0)
    {
        fflush(stdin);
        printf("格式有误，请重新输入：");
    }
    while(stu[count].score[0]<0||stu[count].score[0]>100)
    {
        fflush(stdin);
        printf("数据超出，请重新输入：");
        scanf("%f",&stu[count].score[0]);
    }
    printf("\n英语(0~100)：");   //输入英语
    fflush(stdin);
    while(scanf("%f",&stu[count].score[1])==0)
    {
        fflush(stdin);
        printf("格式有误，请重新输入：");
    }
    while(stu[count].score[1]<0||stu[count].score[1]>100)
    {
        fflush(stdin);
        printf("数据超出，请重新输入：");
        scanf("%f",&stu[count].score[1]);
    }
    printf("\nC语言(0~100)：");  //输入C语言
    fflush(stdin);
    while(scanf("%f",&stu[count].score[2])==0)
    {
        fflush(stdin);
        printf("格式有误，请重新输入：");
    }
    while(stu[count].score[2]<0||stu[count].score[2]>100)
    {
        fflush(stdin);
        printf("数据超出，请重新输入：");
        scanf("%f",&stu[count].score[2]);
    }
    printf("\n计算机基础(0~100)：");  //输入计算机基础
    fflush(stdin);
    while(scanf("%f",&stu[count].score[3])==0)
    {
        fflush(stdin);
        printf("格式有误，请重新输入：");
    }
    while(stu[count].score[3]<0||stu[count].score[3]>100)
    {
        fflush(stdin);
        printf("数据超出，请重新输入：");
        scanf("%f",&stu[count].score[3]);
    }
    printf("\n软件工程导论(0~100)："); //输入软件工程导论
    fflush(stdin);
    while(scanf("%f",&stu[count].score[4])==0)
    {
        fflush(stdin);
        printf("格式有误，请重新输入：");
    }
    while(stu[count].score[4]<0||stu[count].score[4]>100)
    {
        fflush(stdin);
        printf("数据超出，请重新输入：");
        scanf("%f",&stu[count].score[4]);
    }
    stu[count].aver=(stu[count].score[0]+stu[count].score[1]+stu[count].score[2]+stu[count].score[3]+stu[count].score[4])/5.0;//计算平均成绩 
    count++;   //结构体数据数+1
    save(p);   //保存文件
    fflush(stdin);
    printf("是否继续录入：\n\n");
    printf("1.是 2.否\n");
    fflush(stdin);
    printf("\n请选择:");
    b:
    while(scanf("%d",&choose)==0)
    {
    	printf("您输入的格式错误，请重新输入：\n");
    	fflush(stdin);
    	goto b;
	}
   switch(choose)
    {
        case 1:goto a;break;
        case 2:return;break;
        default:printf("没有该序号，请重新输入：");goto b;
    }
}
//*************************************
//*************************************
//学生成绩显示
void print(struct Student stu[])
{
    void sort(struct Student stu[]);
    system("cls");
    if(count==0) printf("\n您尚未录入学生信息，请返回菜单进行录入！\n");
    sort(p);    //排序函数
    return;
}
//*************************************
//*************************************
//学生各科均分
void average(struct Student stu[])
{
	system("cls");
	int i;
	if(count==0) printf("\n您尚未录入学生信息，请返回菜单进行录入！\n");
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
	printf("各科平均成绩显示\n");
	printf("***************************************************************************************************\n");
	printf("高数:\t%.2f\n",aver[0]);
	printf("英语:\t%.2f\n",aver[1]);
	printf("C语言:\t%.2f\n",aver[2]);
	printf("计算机基础:  %.2f\n",aver[3]);
	printf("软件工程导论:%.2f\n",aver[4]); 
    printf("***************************************************************************************************\n");
    system("pause");
    return;
} 
//*************************************
//*************************************
//平均成绩排序
void sort(struct Student stu[])
{
    void save(struct Student stu[]);
    system("cls");
    fflush(stdin);
    char tempname[20];  //临时变量
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    if(count==0) printf("\n\n您尚未录入学生信息，请返回菜单进行录入！\n\n");
    else
    {
        printf("\n成绩显示(按平均成绩排序)\n");   //冒泡排序
            for(i=0;i<count-1;i++)
            {
                for(j=0;j<count-i-1;j++)
                {
                    if(stu[j].aver<stu[j+1].aver)  //注意字符串的复制 
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
            printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
            printf("************************************************************************************************************\n");
            for(i=0;i<count;i++)
                printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    save(p);   //保存文件
    }
    system("pause");
    return;
}
//*************************************
//*************************************
//按高数成绩排序
void mathsort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n成绩显示(按数学成绩排序)\n");
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
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
        printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    printf("\n按任意键返回成绩排序！\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//按英语成绩排序
void Engsort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n成绩显示(按英语成绩排序)\n");
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
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
    {
         printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    }
    printf("\n按任意键返回成绩排序！\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//按C语言排序
void Csort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n成绩显示(按C语言成绩排序)\n");
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
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
    {
         printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    }
    printf("\n按任意键返回成绩排序！\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//按计算机基础排序
void comsort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n成绩显示(按计算机基础成绩排序)\n");
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
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
    {
         printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    }
    printf("\n按任意键返回成绩排序！\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//按软件工程导论排序
void softsort(struct Student stu[])
{
    system("cls");
    fflush(stdin);
    char tempname[20];
    char tempcla[20];
    int i,j;
    long long int t1;
    float t;
    printf("\n成绩显示(按软件工程导论成绩排序)\n");
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
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
    {
        printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
           stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    }
    printf("\n按任意键返回成绩排序！\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//成绩排序
void projectsort(struct Student stu[])
{
    if(count==0)
    {
        printf("\n\n您尚未录入学生信息，请返回菜单进行录入！\n\n");
        system("pause");
        return;
    }
    int choose;
    system("cls");
    fflush(stdin);
    choose:   //成绩排序页面菜单
    printf("\n\t\t\t\t\t\t   成绩排序\n\n");
    printf("\t\t\t\t****************************************************\n\n");
    printf("\t\t\t\t        |1. 高数\t     2. 英语      |\n\n");
    printf("\t\t\t\t        |3. C语言\t     4. 计算机基础|\n\n");
    printf("\t\t\t\t        |5. 软件工程导论     6. 平均成绩  |\n\n");
    printf("\t\t\t\t        |7. 返回菜单\t\t\t  |\n");
    printf("\t\t\t\t****************************************************\n\n");
    printf("\t\t\t\t请选择：");
    a:
    while(scanf("%d",&choose)==0)
    {
        printf("输入格式有误，请您重新输入：");
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
	        printf("按任意键返回菜单！\n\n");
	        system("pause");
	        return;
	    default:
	        printf("没有该序号，请您重新输入：");goto a;
    }

}
//*************************************
//*************************************
//按学号查询
void findnum(struct Student stu[])
{
    int i;
    int searchindex=-1;  //定义下表值 
    long long int searchnum;
    fflush(stdin);
    printf("\n请输入查询成绩的学生学号：");
    scanf("%lld",&searchnum);
    for(i=0;i<count;i++)
    {
        if(searchnum==stu[i].num)
        {
            system("cls");
            searchindex=i;
            printf("************************************************************************************************************\n");
            printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
            printf("************************************************************************************************************\n");
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            break;  //找到后跳出 
        }
    }
    if(searchindex==-1)
        printf("\n很抱歉，没有找到该学生的学号！\n\n");
    printf("\n按任意键返回成绩查询\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//按姓名查询
void findname(struct Student stu[])
{
    int i;
    char searchname[20];
    int searchindex=-1;
    fflush(stdin);
    printf("\n请输入查询成绩学生的姓名：\n");
    scanf("%s",searchname);
    for(i=0;i<count;i++)  //循环寻找姓名
    {
        if(strcmp(searchname,stu[i].name)==0)
        {
            system("cls");
            searchindex=i;
            printf("************************************************************************************************************\n");
            printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
            printf("************************************************************************************************************\n");
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            break;//找到跳出
        }
    }
    if(searchindex==-1)
        printf("\n很抱歉，没有找到该学生的姓名！\n\n");
    printf("\n按任意键返回成绩查询\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//成绩查询
void find(struct Student stu[])
{
    if(count==0)
    {
        printf("\n\n您尚未录入学生信息，请返回菜单进行录入！\n\n");
        system("pause");
        return;
    }
    int choose;
    system("cls");
    fflush(stdin);
    choose:   //成绩查询页面菜单
    printf("\n\t\t\t\t\t\t  成绩查询\n\n");
    printf("\t\t\t\t\t*****************************\n\n");
    printf("\t\t\t\t\t |1.按学号查找 2.按姓名查找|\n\n");
    printf("\t\t\t\t\t |3.全部显示   4.返回菜单  |\n\n");
    printf("\t\t\t\t\t*****************************\n");
    printf("\t\t\t\t\t\n请输入查询方式:");
    a:
    while(scanf("%d",&choose)==0)
    {
        printf("输入格式有误，请您重新输入：");
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
	        printf("\n按任意键返回菜单！\n\n");
	        system("pause");
	        return;
	    default:
	        printf("没有该序号，请您重新输入：");goto a;
    }
}
//*************************************
//*************************************
//删除成绩
void del(struct Student stu[])
{
    void delnum(struct Student stu[]);
    void delname(struct Student stu[]);
    void save(struct Student stu[]);
    int choose;
    if(count==0)
    {
        printf("\n\n您尚未录入学生信息，请返回菜单进行录入！\n\n");
        system("pause");
        return;
    }
    choose:
    fflush(stdin);   //删除成绩页面菜单
    printf("\n\t\t\t\t\t     删除成绩\n\n");
    printf("\t\t\t\t********************************\n\n");
    printf(" \t\t\t\t\t   1.按学号删除\n\n\t\t\t\t\t   2.按姓名删除\n\n\t\t\t\t\t   3.返回菜单\n\n");
    printf("\t\t\t\t********************************\n\n");
    printf("请输入删除方式：");
    a:
    while(scanf("%d",&choose)==0)
    {
        printf("输入格式有误，请您重新输入：");
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
	        printf("\n按任意键返回菜单！\n\n");
	        system("pause");
	        return;
	    default:
	        printf("没有该序号，请您重新输入：");goto a;
    }

}
//*************************************
//*************************************
//按学号删除成绩
void delnum(struct Student stu[])
{
    void print(struct Student stu[]);
    int i,choose;
    int searchindex=-1;
    long long int deletenum;
    fflush(stdin);
    printf("请输入要删除学生的学号(按-1返回）：");
    scanf("%lld",&deletenum);
    printf("是否确定删除：\n");
    fflush(stdin);
    printf("1.是 2.否\n");
    fflush(stdin);
    printf("请选择:");
    b:
    while(scanf("%d",&choose)==0)
    {
    	printf("您输入的格式错误，请重新输入：\n");
    	fflush(stdin);
    	goto b;
	}
    switch(choose)
    {
        case 1:break;
        case 2:return;break;
        default:printf("没有该序号，请重新输入：");goto b;
    }
    if(deletenum==-1)
    {
        printf("\n按任意键返回删除成绩！\n\n");
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
        printf("\n很遗憾，未能找到所要删除学生的学号！\n");
        printf("\n按任意键返回菜单\n\n");
        system("pause");
        return;
    }
    else  //查找信息后，每组数据往前进行覆盖
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
        count--;  //总数据组-1
    }
    if(count==0)
    {
        printf("\n目前没有学生信息，请返回菜单录入!\n\n");
        system("pause");
        return;
    }
    system("cls");  //删除后进行打印
    printf("\n删除成功！\n\n");
    printf("************************************************************************************************************\n");
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
         printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    printf("\n按任意键返回菜单\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//按姓名删除成绩
void delname(struct Student stu[])
{
    void print(struct Student stu[]);
    int i,choose;
    char tempname[10]={"-1"};
    int searchindex=-1;
    char deletename[20];
    fflush(stdin);
    printf("请输入要删除学生的姓名（按-1返回）：");
    scanf("%s",deletename);
    printf("是否确定删除：\n");
    fflush(stdin);
    printf("1.是 2.否\n");
    fflush(stdin);
    printf("请选择:");
    b:
    while(scanf("%d",&choose)==0)
    {
    	printf("您输入的格式错误，请重新输入：\n");
    	fflush(stdin);
    	goto b;
	}
	switch(choose)
    {
        case 1:;break;
        case 2:return;break;
        default:printf("没有该序号，请重新输入：");goto b;
    }
    if(strcmp(deletename,tempname)==0)
    {
        printf("\n按任意键返回删除成绩！\n\n");
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
        printf("\n很遗憾，未能找到所要删除学生的姓名！\n");
        printf("\n按任意键返回菜单\n\n");
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
    printf("\n删除成功！\n\n");
    if(count==0)
    {
        printf("\n目前没有学生信息，请返回菜单录入!\n\n");
        system("pause");
        return;
    }
    system("cls");
    printf("\n删除成功！\n\n");
    printf("************************************************************************************************************\n");
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
    printf("************************************************************************************************************\n");
    for(i=0;i<count;i++)
        printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
    printf("\n按任意键返回菜单\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//修改成绩
void change(struct Student stu[])
{
    void save(struct Student stu[]);
    int i,j;
    int choose;
    long long int searchnum,tempnum;
    int searchindex=-1;
    if(count==0)
    {
        printf("\n\n您尚未录入学生信息，请返回菜单进行录入！\n\n");
        system("pause");
        return;
    }
    a:
    system("cls");
    printf("\n修改成绩！\n\n");
    fflush(stdin);
    printf("************************************************\n");
    printf("\n请输入修改学生的学号：(按-1返回菜单）");
    scanf("%lld",&searchnum);
    fflush(stdin);
    if(searchnum==-1)
    {
        printf("\n按任意键返回菜单！\n\n");
        system("pause");
        return;
    }
    system("cls");
    for(i=0;i<count;i++)
    {
        if(searchnum==stu[i].num)
        {
            searchindex=i;
            printf("\n该学生信息：\n");  //修改成绩页面菜单
            printf("************************************************************************************************************\n");
            printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
            printf("************************************************************************************************************\n");
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
            printf("************************************************\n");
            printf("|1.修改班级\t       2. 修改姓名            |\n");
            printf("|3.修改学号\t       4. 修改高数            |\n");
            printf("|5.修改英语\t       6. 修改C语言           |\n");
            printf("|7.修改计算机基础      8. 修改软件工程导论    |\n");
            printf("|9.返回菜单\t                              |\n");
            printf("************************************************\n");
            printf("请选择修改的信息：");
            choose:
            while(scanf("%d",&choose)==0)
            {
                printf("输入格式有误，请您重新输入：");
                fflush(stdin);
            }
            switch(choose)
            {
	            case 1:
	                fflush(stdin);
	                printf("请修改班级:");
	                while(scanf("%s",stu[i].cla)==0)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                }
	                while(strlen(stu[count].cla)>10)  //判断字符长度
	                {
	                    printf("班级输入不合理，请重新录入:");
	                    fflush(stdin);
	                    scanf("%s",stu[count].cla);
	                }
	                break;
	            case 2:
	                fflush(stdin);
	                printf("请修改姓名:");
	                while(scanf("%s",stu[i].name)==0)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                }
	                while(strlen(stu[count].name)>10)  //判断字符长度
	                {
	                    printf("班级输入不合理，请重新录入:");
	                    fflush(stdin);
	                    scanf("%s",stu[count].name);
	                }
	                break;
	            case 3:
	                fflush(stdin);
	                printf("请修改学号:");
	                w:
	                while(scanf("%lld",&stu[i].num)==0)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                }
	                tempnum=stu[i].num;
	                stu[i].num=0;
	                for(j=0;j<count;j++)
	                {
	                    if(tempnum==stu[j].num)
	                    {
	                        printf("已有该学号，请重新输入：\n");
	                        goto w;
	                    }
	                }
	                stu[i].num=tempnum;
	                break;
	            case 4:
	                fflush(stdin);
	                printf("请修改高数:");
	                while(scanf("%f",&stu[i].score[0])==0)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                }
	                while(stu[i].score[0]<0||stu[i].score[0]>100)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[0]);
	                }
	                break;
	            case 5:
	                fflush(stdin);
	                printf("请修改英语:");
	                while(scanf("%f",&stu[i].score[1])==0)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                }
	                while(stu[i].score[1]<0||stu[i].score[1]>100)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[1]);
	                }
	                break;
	            case 6:
	                fflush(stdin);
	                printf("请修改C语言:");
	                while(scanf("%f",&stu[i].score[2])==0)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                }
	                while(stu[i].score[2]<0||stu[i].score[2]>100)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[2]);
	                }
	                break;
	            case 7:
	                fflush(stdin);
	                printf("请修改计算机基础:");
	                while(scanf("%f",&stu[i].score[3])==0)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                }
	                while(stu[i].score[3]<0||stu[i].score[3]>100)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[3]);
	                }
	                break;
	            case 8:
	                fflush(stdin);
	                printf("请修改软件工程导论:");
	                while(scanf("%f",&stu[i].score[4])==0)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                }
	                while(stu[i].score[4]<0||stu[i].score[4]>100)
	                {
	                    printf("格式有误，请重新输入：");
	                    fflush(stdin);
	                    scanf("%f",&stu[i].score[4]);
	                }
	                break;
	            case 9:
	                printf("\n按任意键返回菜单！\n\n");
	                save(p);
	                return;
	            default:
	                printf("没有该序号，请您重新输入：");
	                goto choose;
            }//switch结尾处 
            stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2]+stu[i].score[3]+stu[i].score[4])/5.0;
            printf("\n修改成功：\n");
            printf("************************************************************************************************************\n");
            printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n");
            printf("************************************************************************************************************\n");
            printf("\t%-8s%-8s%-16lld%-8.2lf%-8.2lf%-8.2lf%-16.2lf%-16.2lf%-12.2lf\n\n",stu[i].cla,stu[i].name,stu[i].num,
                   stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].aver);
        }//if结束处
    }//for结束处
    if(searchindex==-1)
    {
        printf("\n很抱歉，未能找到该学生，请重新输入学号!\n\n");
        system("pause");
        goto a;
    }
    save(p);
    system("pause");
    return;
}
//*************************************
//*************************************
//成绩分段
void section(struct Student stu[])
{
    int a=0,b=0,c=0;
    if(count==0)
    {
        printf("\n\n您尚未录入学生信息，请返回菜单进行录入！\n\n");
        system("pause");
        return;
    }
    printf("成绩分段\n");
    int i;
    printf("\n\n");
    printf("优秀的同学(80~100)\n");
    printf("************************************************************************************************************\n");
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n\n");
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
    printf("一共有%d人\n",a);
    printf("\n\n");
    printf("良好的同学(60~79)\n");
    printf("************************************************************************************************************\n");
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n\n");
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
    printf("一共有%d人\n",b);
    printf("\n\n");
    printf("不及格的同学(0~59)\n");
    printf("************************************************************************************************************\n");
    printf("\t班级\t姓名\t学号\t\t高数\t英语\tC语言\t计算机基础\t软件工程导论\t平均成绩\t\n\n");
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
    printf("一共有%d人\n",c);
    printf("\n\n");
    printf("按任意键返回菜单!\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//文件导入
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
        count++;  //存入一个，数据组数+1
    }
    fclose(fp);
    a:
    printf("\n导入文件已成功，祝您使用愉快！\n\n");
    printf("请按任意键进入页面菜单！\n\n");
    system("pause");
    return;
}
//*************************************
//*************************************
//文件存储
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
    printf("\n已保存至文件中\n\n");
    //system("pause");
}
//*************************************
//*************************************
//主函数
int main()
{
    system("color 9E"); //设置背景颜色
    int i=4;
    char code[20]={'1','2','3','4','5','6'},password[20];
	int x;
	char c;
    //初始页面
    time_t timep;    //系统时间 
	struct tm *p_1;
	time (&timep);
	p_1=gmtime(&timep);
	printf("\t\t\t\t\t\t  当前时间%02d时%02d分%\n",8+p_1->tm_hour,p_1->tm_min); 
	printf("\t\t\t\t\t\t   %d年%02d月%02d日\n",1900+p_1->tm_year,1+p_1->tm_mon,p_1->tm_mday);
    printf("\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n\n");
    printf("\t★\t\t\t\t\t有朋自远方来，不亦乐乎！ \t\t\t\t\t★\n\n");
    printf("\t★\t\t\t*****************************************************\t\t\t\t★\n\n");
    printf("\t★\t\t\t\t\t 学 生 管 理 系 统\t\t\t\t\t\t★\n\n");
    printf("\t★\t\t\t  制作者:Mr.Wang 专业:软件工程1801 学号:************\t\t\t\t★\n\n");
    printf("\t★\t\t\t*****************************************************\t\t\t\t★\n\n");
    printf("\t★\t\t\t  欢迎使用软件工程18-01的学生管理系统,祝您使用愉快! \t\t\t\t★\n\n");
    printf("\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n\n"); 
	printf("请输入六位登陆密码！\n");
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
        printf("\n输入密码有误，您还有%d次机会，请重新输入：",i--);
        if(i==-1)
        {
            exit(0);
        }
        goto q;
    }
    read(p); //导入文件
    system("cls");    //清屏
    //页面菜单
    menu:
    system("cls");
    time (&timep);
	p_1=gmtime(&timep);
    printf("\t\t\t\t\t\t   当前时间%02d时%02d分%\n",8+p_1->tm_hour,p_1->tm_min); 
	printf("\t\t\t\t\t\t    %d年%02d月%02d日\n",1900+p_1->tm_year,1+p_1->tm_mon,p_1->tm_mday);
    printf("\n");
    printf("\t\t\t\t\t\t    页  面  菜  单\n");
    printf("\n");
    printf("\t\t★————————————————————————————————————————★\n\n");
    printf("\t\t\t   | 1. 成绩录入\t\t2. 成绩显示\t\t3. 各科均分  |\n\n");
    printf("\t\t\t   | 4. 成绩排序\t\t5. 成绩查找\t\t6. 信息修改  |\n\n");
    printf("\t\t\t   | 7. 删除成绩\t\t8. 成绩分段\t\t0. 退出系统  |\n\n");
    printf("\t\t★————————————————————————————————————————★\n");
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
    printf("请选择相应序号：");
    int choose;
    int a; 
    w:
    while(scanf("%d",&choose)==0)
    {
        printf("格式错误，请重新输入：");
        fflush(stdin);
    }
    switch(choose)
    {
    	case 1:   //成绩录入
	        system("cls");
	        printf("学生成绩录入\n");
	        input(p);
	        goto menu;
	    case 2:  //成绩显示和排序
	    	system("cls");
	        printf("学生成绩显示\n");
	        print(p);
	        goto menu;
	    case 3:  //均科成绩 
	    	system("cls");
			average(p);
			goto menu;
	    case 4:  //成绩排序
	    	 system("cls");
	        projectsort(p);
	        goto menu;
	    case 5:  //成绩查找
	        system("cls");
	        find(p);
	        goto menu;
	    case 6:  //成绩修改
		    system("cls");
	        change(p);
	        goto menu;
	    case 7:  //成绩删除
		    system("cls");
	        del(p);
	        goto menu;
	    case 8:  //成绩分段
		    system("cls");
	        section(p);
	        goto menu;
	    case 0: //退出系统
	        fflush(stdin);
	        printf("\n是否继续退出：\n");
	        printf("\n1. 是 2. 否\n\n");
	        back:
	        printf("请选择:");
	        while(scanf("%d",&a)==0)
	        {
	        	fflush(stdin);
	        	printf("您输入格式有误，请重新输入：");
			}
	        if(a==1)
	        {
	            system("cls");
	            //心形图案 
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
	            Sleep(1000);  //休眠 
	            printf("欢迎下次继续使用本产品!\n");
	            printf("正在退出，请稍后.");
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
	        }//if(a==1)结束处 
	        if(a==2)goto menu;
	        if(a!=1||a!=2)printf("输入有误，重新输入:\n");goto back;
	    default:
	    	printf("没有该序号！请重新输入：");
        	goto w;
	}//switch结束处 
    return 0;
}
