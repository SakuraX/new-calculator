#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <process.h>
#define  NEW  (struct node *)malloc(sizeof(struct node))


struct node
{
    char name[100],tel[20];
    struct node *next;
};



 output(struct node *h)//输出（文件部分不会）
{
    struct node *p;
    p=h;
    if(h==NULL)
    {
        printf("您的通讯录没有存储信息");
        return;

    }
    printf ("通讯录的列表如下:\n");
    while (p!=NULL)
    {
        printf("%s %s\n",p->name,p->tel);
        p=p->next;
    }
    printf ("通讯录输入完毕!\n");
}

struct node *creat()//创建完成
{
    struct node *p,*q,*h,*q1,*p1,*r;
  h=p=q=r=NULL;
  char name[20],tel[20];
  int i;
   printf("名字:");
  gets(name);
  while(strlen(name)!=0)
  {
    p=NEW;

     printf("电话:");
     gets(tel);
     while(1)
     {

      if(strlen(tel)!=7||strlen(tel)!=11)
    {printf("你输入的号码可能有错，你确定要输入嘛？(是(1)/否(0)");
     scanf("%d",&i);
     if(i)
     {strcpy(p->tel,tel);
       break;}
        if(!i)
        {
         printf("请重新输入电话:");
         fflush(stdin);
         gets(tel);
}}
        if(strlen(tel)==7||strlen(tel)==11)
        break;
        }
        strcpy(p->name,name);
        strcpy(p->tel,tel);
     if(h==NULL)
        h=p;
     else
      q->next=p;
        q=p;
     printf("是否还要接着输入：（是请输1,否请输0）");
     scanf("%d",&i);
     getchar();
     if(i)
     {printf("名字:");
     gets(name);}
     if(!i)
        break;
      }p->next=NULL;

  for(p1=h;p1!=NULL;p1=p1->next)
   {r=NEW;
    for(q1=p1->next;q1!=NULL;q1=q1->next)
    {if(strcmp(p1->name,q1->name)>0)
        {
               strcpy(r->name,p1->name);
               strcpy(r->tel,p1->tel);
               strcpy(p1->name,q1->name);
               strcpy(p1->tel,q1->tel);
               strcpy(q1->name,r->name);
               strcpy(q1->tel,r->tel);
               }
               free(r);
               if(strcmp(p1->name,q1->name)==0)
               ;

    }
   }


return h;
}


  modify(struct node *h)//修改(完成)
{    char name[20],name1[20],tel[20];
     struct node *p,*q;
     printf("\n请输入名字:");
     gets(name);
    for(p=h;p!=NULL;p=p->next)
   {

    if(!strcmp(name,p->name))
   {

    printf("\n已查到，记录为：");
     printf("\n%s,%s",p->name,p->tel);
     printf("\n请输入新姓名");
     gets(name1);
     strcpy(p->name,name1);
     printf("\n请输入新电话");
     gets(tel);
     strcpy(p->tel,tel);
    }

     if(strcmp(name,p->name)!=0)
      printf("\n对不起，通讯录中没有此人的记录。");
      }
}
 delet(struct node *h)//删除完成
 {   char name[20];
     struct node *p,*q;
     printf("\n请输入名字:");
     gets(name);
     p=q=h;

     while((p->next!=NULL)&&!strcmp(p->name,name))
     {
         q=p;
         p=p->next;
     }

     q->next=p->next;
     free(p);

 }
 search(struct node *h)//查找（完成）
{
 int k=0;

 char name[20];
 struct node *p,*q;



     printf("\n请输入姓名:");
     gets(name);
     for(p=h;p!=NULL;p=p->next)
    {if(!strcmp(name,p->name))
      {
        printf("\n\n已查到，记录为：");
        printf("\nname:%s\ntel:%s",p->name,p->tel);
        k=1;

    }
    }
   if(!k)
     printf("\n\n对不起，通讯录中没有此人的记录。");

  }
  append(struct node *h)//添加完成
  {
 char name[20],tel[20];
 int i;
 struct node *p,*q,*r,*q1;
 q=r=q1=NULL;

  if(h==NULL)
 {printf("请先创建通讯录");
 return;}
 if(h!=NULL)
 { printf("请输入要添加的姓名:");
  gets(name);
  while(strlen(name)!=0)
{  q=NEW;
   strcpy(q->name,name);
   printf("请输入电话：");
   gets(tel);
   while(1)
     {

      if(strlen(tel)!=7||strlen(tel)!=11)
    {printf("你输入的号码可能有错，你确定要输入嘛？(是(1)/否(0)");
     scanf("%d",&i);
     if(i)
     {strcpy(q->tel,tel);
       break;}
        if(!i)
        {
         printf("请重新输入电话:");
         fflush(stdin);
         gets(tel);
}}
        if(strlen(tel)==7||strlen(tel)==11)
        break;
        }
        strcpy(q->name,name);
        strcpy(q->tel,tel);
   for(p=h;p!=NULL;p=p->next)
  {if(strcmp(name,h->name)<0)
     {
      q->next=h;
      h=q;
      break;
      }
    if(strcmp(name,p->name)>0&&p->next!=NULL)
    {p->next=q;
    q->next=p->next->next;
    break;}
    if(p->next==NULL)
    {p->next=q;
    q->next=NULL;}}
    printf("是否还要接着添加：（是请输1,否请输0）");
     scanf("%d",&i);
     getchar();
     if(i)
     {printf("名字:");
     gets(name);}
     if(!i)
        break;
}}}

main()
{
    int m;
    struct node *creat();
struct node *h,*h1;
h=NULL;

 while(1)
{
printf("\n\t\t*********欢迎使用通讯录*********\n\n");
printf("\n\t\t         创建，请按1\n");
printf("\n\t\t         查找，请按2\n");
printf("\n\t\t         修改，请按3\n");
printf("\n\t\t         删除，请按4\n");
printf("\n\t\t         添加，请按5\n");
printf("\n\t\t         输出，请按6\n");
printf("\n\t\t         退出，请按0\n");
printf("\n\t\t********************************\n\n");
printf("请输入0~6其中的一个数字:");
scanf("%d",&m);
getchar();
  if(m>=0&&m<=6)
    {
      switch(m)
       {
         case 1: h=creat(h);//完成
                  break;
         case 2: search(h);//王城
                 break;
         case 3: modify(h);//完成
                 break;
         case 4: delet(h);//完成
                 break;
         case 5: append(h);break;//完成
         case 6:output(h);//完成
                 break;
         case 0: exit(0);
       }

       printf("\n\n操作完毕,");
     }
    else
      printf("\n\n选择错误,");
      system("pause");
      system("cls");
   }


 } //开始菜单




