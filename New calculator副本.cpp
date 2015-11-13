#include "stdio.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "string.h"
#define bool int
#define false 0
#define true 1

using namespace std;

struct num
{
   int val;
   struct num *next;
};

struct num* createlist(string str)
{
	int length=str.size();
	struct num *head=new num();
	struct num *prev=head,*e=new num();

	for(int i=0;i<length;i++)
	{
		struct num *p=new num();
		p->val=str[i]-48;
	//	p->next=NULL;

		prev->next=p;
		prev=p;
	}
	prev->next=e;
	e->val=-1;
	e->next=NULL;
	return head;
}


int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void add()
{
    system("title plus");
    int numA[1000],sizeA,iA=1;
    int numB[1000],sizeB,iB=1;
    int ans[1000],sizeofAns;
    char numa[1000];
    char numb[1000];
    int i;

    memset(numA,0,sizeof(numA));
    memset(numB,0,sizeof(numB));
     memset(ans,0,sizeof(ans));
    printf("Please enter the first number:\n");
    gets(numa);
    sizeA=(int)(strlen(numa));
    printf("Please enter the second number:\n");
    gets(numb);
    sizeB=(int)(strlen(numb));

    while(iA<=sizeA)
    {
        numA[iA]=(numa[sizeA-iA]-'0');
        iA++;
    }

    while(iB<=sizeB)
    {
        numB[iB]=(numb[sizeB-iB]-'0');
        iB++;
    }
    sizeofAns=max(sizeA,sizeB)+1;
    for(i=1;i<=sizeofAns;i++)
    {
        int temp=0;
        ans[i]+=numA[i]+numB[i];
        temp=ans[i]/10;
        ans[i+1]+=temp;
        ans[i]%=10;
    }
    if(ans[sizeofAns]==0)
        sizeofAns--;
    printf("The result is:\n");
    for(i=sizeofAns;i>=1;i--)
        printf("%d",ans[i]);
    printf("\n");
}

void minus_num()
{
    system("title minus");
    int numA[1000],sizeA,iA=1;
    int numB[1000],sizeB,iB=1;
    int ans[1000],sizeofAns;
    char numa[1000];
    char numb[1000];
    int i,negative=0;

    memset(numA,0,sizeof(numA));
    memset(numB,0,sizeof(numB));
    memset(ans,0,sizeof(ans));
    printf("Please enter the minuend:\n");
    gets(numa);
    sizeA=(int)(strlen(numa));
    printf("Please enter the subtrahend:\n");
    gets(numb);
    sizeB=(int)(strlen(numb));
    if(sizeA<sizeB || (numa[1]<numb[1] && sizeA<=sizeB))
    {
        while(iA<=sizeB)
        {
            numA[iA]=(numb[sizeB-iA]-'0');
            iA++;
        }

        while(iB<=sizeA)
        {
            numB[iB]=(numa[sizeA-iB]-'0');
            iB++;
        }
        negative=1;
    }
    else
    {
        while(iA<=sizeA)
        {
            numA[iA]=(numa[sizeA-iA]-'0');
            iA++;
        }

        while(iB<=sizeB)
        {
            numB[iB]=(numb[sizeB-iB]-'0');
            iB++;
        }
    }
    sizeofAns=max(sizeA,sizeB);
    for(i=0;i<=sizeofAns;i++)
    {
        if(numA[i]<numB[i])
        {
            numA[i]+=10;
            numA[i+1]--;
        }
        ans[i]=numA[i]-numB[i];
    }
    while(ans[sizeofAns]==0)
        sizeofAns--;
    printf("The result is:\n");
    if(negative==1)
        printf("-");
    for(i=sizeofAns;i>=1;i--)
        printf("%d",ans[i]);
    printf("\n");
}

void mutilplication()
{
    system("title multiplication");
    int numA[1000],sizeA,iA=0;
    int numB[1000],sizeB,iB=0;
    int ans[1000],sizeofAns;
    char numa[1000];
    char numb[1000];
    int i,j;

    memset(numA,0,sizeof(numA));
    memset(numB,0,sizeof(numB));
    memset(ans,0,sizeof(ans));
    printf("Please enter the first number:\n");
    gets(numa);
    sizeA=(int)(strlen(numa));
    printf("Please enter the second number:\n");
    gets(numb);
    sizeB=(int)(strlen(numb));

    while(iA<sizeA)
    {
        numA[iA]=(numa[iA]-'0');
        iA++;
    }

    while(iB<sizeB)
    {
        numB[iB]=(numb[iB]-'0');
        iB++;
    }
    sizeofAns=sizeA+sizeB-1;
    for(i=0;i<sizeA;i++)
        for(j=0;j<sizeB;j++)
            ans[i+j]+=numA[i]*numB[j];
    for(i=sizeofAns;i>=1;i--)
      if(ans[i]>=10)
      {
          ans[i-1]+=ans[i]/10;
          ans[i]%=10;
      }
    if(ans[0]!=0)
        i=0;
    else
        i=1;
    printf("The result is:\n");
    for(i;i<sizeofAns;i++)
        printf("%d",ans[i]);
    printf("\n");
}



void divide()
{
	struct num *h,*he,*p,*r,*e;
	int n,i=0,d;
	string str;

	cout<<"Please enter the  dividend:\n";
	cin>>str;
	cout<<"Please enter the divisor:\n";
	cin>>d;
	h=createlist(str);
    he=new num();
    r=he;
    e=new num();
    for(;h->val!=-1;h=h->next,i*=10)
    {
        p=new num();
    	p->val=(h->val+i)/d;
    	i=(h->val+i)%d;
    	r->next=p;
    	r=p;
    //	cout<<p->val;
    }
    r->next=e;
    e->val=-1;
    while(he->val==0)
     he=he->next;
     cout<<"The result is:\n";
    while(he->val!=-1)
    {
      cout<<he->val;
      he=he->next;
    }

}


void matrix_transfer()
{
    int m,n,a[100][100],b[100][100];
    cout<<"Please enter the dimension of the matrix:\n";
    cin>>m>>n;
    cout<<"Please enter the matrix:\n";
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            b[j][i]=a[i][j];
        }

    cout<<"The result is:\n";

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
         printf("%2d ",b[i][j]);
       cout<<endl;
    }
}


void matrix_muti()
{
        system("title matrix multiplication");
        int a[100][100],b[100][100];
        int ans[100][100];
        int m,n1,n2,p,i,j,k;

        printf("Please enter the dimension of the first matrix:\n");
        scanf("%d %d",&m,&n1);
        printf("Please enter the first matrix:\n");

        for(i=1;i<=m;i++)
            for(j=1;j<=n1;j++)
                scanf("%d",&a[i][j]);

        printf("Please enter the dimension of the second matrix:\n");
        scanf("%d %d",&n2,&p);
        printf("Please enter the second matrix:\n");

        for(i=1;i<=n2;i++)
            for(j=1;j<=p;j++)
                scanf("%d",&b[i][j]);

        if(n1!=n2)
            printf("WRONG DIMENSION! Quit....\n");
        else
        {
            for(i=1;i<=m;i++)
                for(j=1;j<=p;j++)
                    for(k=1;k<=n1;k++)
                        ans[i][j]+=a[i][k]*b[k][j];
            printf("The result is:\n");
            for(i=1;i<=m;i++)
            {
                for(j=1;j<=p;j++)
                    printf("%4d ",ans[i][j]);
                printf("\n");
            }
        }

}

void matrix_add()
{
    system("title matrix plus");
    int n,m,i,j;
    int a[100][100],b[100][100];
    printf("Please enter the dimension of the  matrix:\n");
    scanf("%d %d",&n,&m);
    printf("Please enter the first matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);

    printf("Please enter the second matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&b[i][j]);
    printf("The result is:\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
           printf("%3d ",a[i][j]+b[i][j]);
        printf("\n");
    }
}

void matrix_minus()
{
    system("title matrix minus");
    int n,m,i,j;
    int a[100][100],b[100][100];
    printf("Please enter the dimension of the matrix:");
    scanf("%d %d",&n,&m);
    printf("Please enter the first matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);

    printf("Please enter the second matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&b[i][j]);
    printf("The result is:\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("%3d ",a[i][j]-b[i][j]);
        printf("\n");
    }
}


void opera()
{
    system("title operation");
    char a[100];
    int s1[100],*sp1,i;
    char s2[100],*sp2;
    int boo[100]={0};
    boo['*']=1;
    boo['/']=1;
    sp1=s1;
    sp2=s2;

    printf("Please enter the operation:\n");
    gets(a);

    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            int ans=0,k=1;
            while(a[i]>='0' && a[i]<='9')
            {
                ans=ans*k+(a[i]-'0');
                i++;
                k*=10;
            }
            *sp1=ans;
            sp1++;
            i--;

        }
        else
        {

            if(i==1)
            {
                *sp2=a[i];
                sp2++;
            }
            else
            {
                if(boo[*(sp2-1)]>=boo[a[i]])
                {
                    int aa=*(--sp1);
                    int bb=(*(--sp1));
                    switch(*(--sp2))
                    {
                        case '+':aa=aa+bb;break;
                        case '-':aa=-aa+bb;break;
                        case '*':aa=aa*bb;break;
                        case '/':aa=bb/aa;break;
                    }
                    *sp1=aa;
                    sp1++;
                    *sp2=a[i];
                    sp2++;
                }
                else
                {
                    *sp2=a[i];
                    sp2++;
                }
            }


        }
    }

    while(sp2>=s2+1)
    {
        int aa=*(--sp1);
        int bb=(*(--sp1));
        switch(*(--sp2))
        {
            case '+':aa=aa+bb;break;
            case '-':aa=-aa+bb;break;
            case '*':aa=aa*bb;break;
            case '/':aa=bb/aa;break;
        }
        *sp1=aa;
        sp1++;
    }
    printf("The result is:");
    printf("%d\n",*(--sp1));

}

void UI()
{
    system("mode 82,14");
    int i,j;
    for(i=1;i<=79;i++)
        printf("*");
    printf("\n");
    for(i=1;i<=3;i++)
    {
        printf("*");
        for(j=1;j<78;j++)
            printf(" ");
        printf("*");
        printf("\n");
    }
    printf("*");
    for(i=1;i<25;i++)
        printf(" ");
    printf("welcome to our calculator!");
    for(i=1;i<28;i++)
        printf(" ");
    printf("*");
    printf("\n");

    printf("*");
    for(i=1;i<25;i++)
        printf(" ");
    printf("1.plus             2.minus");
    for(i=1;i<28;i++)
        printf(" ");
    printf("*");
    printf("\n");

    printf("*");
    for(i=1;i<25;i++)
        printf(" ");
    printf("3.multiplication   4.divide");
    for(i=1;i<27;i++)
        printf(" ");
    printf("*");
    printf("\n");

    printf("*");
    for(i=1;i<25;i++)
        printf(" ");
    printf("5.algorithm about matrix.  ");
    for(i=1;i<27;i++)
        printf(" ");
    printf("*");
    printf("\n");

    printf("*");
    for(i=1;i<25;i++)
        printf(" ");
    printf("6.Simple four operations.  ");
    for(i=1;i<27;i++)
        printf(" ");
    printf("*");
    printf("\n");

    for(i=1;i<27;i++)
        printf(" ");
    printf("Please make a choice:");
}

void matrix_UI()
{
     system("cls");
    int i,j;
    for(i=1;i<=81;i++)
        printf("*");
    printf("\n");
    for(i=1;i<=3;i++)
    {
        printf("*");
        for(j=1;j<80;j++)
            printf(" ");
        printf("*");
        printf("\n");
    }
    printf("*");
    for(i=1;i<25;i++)
        printf(" ");
    printf("welcome to our matrix calculator!");
    for(i=1;i<23;i++)
        printf(" ");
    printf("*");
    printf("\n");

    printf("*");
    for(i=1;i<25;i++)
        printf(" ");
    printf("1.   plus              2.minus");
    for(i=1;i<26;i++)
        printf(" ");
    printf("*");
    printf("\n");

    printf("*");
    for(i=1;i<25;i++)
        printf(" ");
    printf("3.multiplication       4.transfer");
    for(i=1;i<23;i++)
        printf(" ");
    printf("*");
    printf("\n");



    for(i=1;i<30;i++)
        printf(" ");
    printf("Please make a choice:");

}

void matrix_choose()
{
    matrix_UI();
      int n;
    scanf("%d",&n);
    getchar();
    system("cls");
    switch(n)
    {
        case 1:matrix_add(); break;
        case 2:matrix_minus();break;
        case 3:matrix_muti();break;
        case 4:matrix_transfer();break;
    }
}

void choose()
{
    UI();
    int n;
    scanf("%d",&n);
    getchar();
    system("cls");
    switch(n)
    {
        case 1:add(); break;
        case 2:minus_num();break;
        case 3:mutilplication();break;
        case 4:divide();break;
        case 5:system("title matrix calculator"); matrix_choose(); break;
        case 6:opera();
    }
}



int main()
{

    system("title calculator");
    choose();
    return 0;
}
