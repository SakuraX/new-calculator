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



 output(struct node *h)//������ļ����ֲ��ᣩ
{
    struct node *p;
    p=h;
    if(h==NULL)
    {
        printf("����ͨѶ¼û�д洢��Ϣ");
        return;

    }
    printf ("ͨѶ¼���б�����:\n");
    while (p!=NULL)
    {
        printf("%s %s\n",p->name,p->tel);
        p=p->next;
    }
    printf ("ͨѶ¼�������!\n");
}

struct node *creat()//�������
{
    struct node *p,*q,*h,*q1,*p1,*r;
  h=p=q=r=NULL;
  char name[20],tel[20];
  int i;
   printf("����:");
  gets(name);
  while(strlen(name)!=0)
  {
    p=NEW;

     printf("�绰:");
     gets(tel);
     while(1)
     {

      if(strlen(tel)!=7||strlen(tel)!=11)
    {printf("������ĺ�������д���ȷ��Ҫ�����(��(1)/��(0)");
     scanf("%d",&i);
     if(i)
     {strcpy(p->tel,tel);
       break;}
        if(!i)
        {
         printf("����������绰:");
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
     printf("�Ƿ�Ҫ�������룺��������1,������0��");
     scanf("%d",&i);
     getchar();
     if(i)
     {printf("����:");
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


  modify(struct node *h)//�޸�(���)
{    char name[20],name1[20],tel[20];
     struct node *p,*q;
     printf("\n����������:");
     gets(name);
    for(p=h;p!=NULL;p=p->next)
   {

    if(!strcmp(name,p->name))
   {

    printf("\n�Ѳ鵽����¼Ϊ��");
     printf("\n%s,%s",p->name,p->tel);
     printf("\n������������");
     gets(name1);
     strcpy(p->name,name1);
     printf("\n�������µ绰");
     gets(tel);
     strcpy(p->tel,tel);
    }

     if(strcmp(name,p->name)!=0)
      printf("\n�Բ���ͨѶ¼��û�д��˵ļ�¼��");
      }
}
 delet(struct node *h)//ɾ�����
 {   char name[20];
     struct node *p,*q;
     printf("\n����������:");
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
 search(struct node *h)//���ң���ɣ�
{
 int k=0;

 char name[20];
 struct node *p,*q;



     printf("\n����������:");
     gets(name);
     for(p=h;p!=NULL;p=p->next)
    {if(!strcmp(name,p->name))
      {
        printf("\n\n�Ѳ鵽����¼Ϊ��");
        printf("\nname:%s\ntel:%s",p->name,p->tel);
        k=1;

    }
    }
   if(!k)
     printf("\n\n�Բ���ͨѶ¼��û�д��˵ļ�¼��");

  }
  append(struct node *h)//������
  {
 char name[20],tel[20];
 int i;
 struct node *p,*q,*r,*q1;
 q=r=q1=NULL;

  if(h==NULL)
 {printf("���ȴ���ͨѶ¼");
 return;}
 if(h!=NULL)
 { printf("������Ҫ��ӵ�����:");
  gets(name);
  while(strlen(name)!=0)
{  q=NEW;
   strcpy(q->name,name);
   printf("������绰��");
   gets(tel);
   while(1)
     {

      if(strlen(tel)!=7||strlen(tel)!=11)
    {printf("������ĺ�������д���ȷ��Ҫ�����(��(1)/��(0)");
     scanf("%d",&i);
     if(i)
     {strcpy(q->tel,tel);
       break;}
        if(!i)
        {
         printf("����������绰:");
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
    printf("�Ƿ�Ҫ������ӣ���������1,������0��");
     scanf("%d",&i);
     getchar();
     if(i)
     {printf("����:");
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
printf("\n\t\t*********��ӭʹ��ͨѶ¼*********\n\n");
printf("\n\t\t         �������밴1\n");
printf("\n\t\t         ���ң��밴2\n");
printf("\n\t\t         �޸ģ��밴3\n");
printf("\n\t\t         ɾ�����밴4\n");
printf("\n\t\t         ��ӣ��밴5\n");
printf("\n\t\t         ������밴6\n");
printf("\n\t\t         �˳����밴0\n");
printf("\n\t\t********************************\n\n");
printf("������0~6���е�һ������:");
scanf("%d",&m);
getchar();
  if(m>=0&&m<=6)
    {
      switch(m)
       {
         case 1: h=creat(h);//���
                  break;
         case 2: search(h);//����
                 break;
         case 3: modify(h);//���
                 break;
         case 4: delet(h);//���
                 break;
         case 5: append(h);break;//���
         case 6:output(h);//���
                 break;
         case 0: exit(0);
       }

       printf("\n\n�������,");
     }
    else
      printf("\n\nѡ�����,");
      system("pause");
      system("cls");
   }


 } //��ʼ�˵�




