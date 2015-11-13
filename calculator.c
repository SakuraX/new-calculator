#include "stdio.h"
#include <math.h>
#include "stdlib.h"
#include "string.h"
#define bool int
#define false 0
#define true 1

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void add()
{
    int numA[1000],sizeA,iA=1;
    int numB[1000],sizeB,iB=1;
    int ans[1000],sizeofAns;
    char numa[1000];
    char numb[1000];
    int i;
    
    memset(numA,0,sizeof(numA));
    memset(numB,0,sizeof(numB));
     memset(ans,0,sizeof(ans));
    printf("请输入第一个数:\n");
    gets(numa);
    sizeA=(int)(strlen(numa));
    printf("请输入第二个数:\n");
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
    printf("结果是:\n");
    for(i=sizeofAns;i>=1;i--)
        printf("%d",ans[i]);
    
}

void minus()
{
    int numA[1000],sizeA,iA=1;
    int numB[1000],sizeB,iB=1;
    int ans[1000],sizeofAns;
    char numa[1000];
    char numb[1000];
    int i,negative=0;
    
    memset(numA,0,sizeof(numA));
    memset(numB,0,sizeof(numB));
    memset(ans,0,sizeof(ans));
    printf("请输入第一个数:\n");
    gets(numa);
    sizeA=(int)(strlen(numa));
    printf("请输入第二个数:\n");
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
    if(negative==1)
        printf("-");
    for(i=sizeofAns;i>=1;i--)
        printf("%d",ans[i]);
}

void mutilplication()
{
    int numA[1000],sizeA,iA=0;
    int numB[1000],sizeB,iB=0;
    int ans[1000],sizeofAns;
    char numa[1000];
    char numb[1000];
    int i,j;
    
    memset(numA,0,sizeof(numA));
    memset(numB,0,sizeof(numB));
    memset(ans,0,sizeof(ans));
    printf("请输入第一个数:\n");
    gets(numa);
    sizeA=(int)(strlen(numa));
    printf("请输入第二个数:\n");
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
    printf("结果为:\n");
    for(i;i<sizeofAns;i++)
        printf("%d",ans[i]);
    printf("\n");
}

void clz(char r[])
{
    if(r[0]=='-')r++; //使r指针向前移一位；
    int len = strlen(r);
    int i=0,k=0;
    if(len<2)return;
    if(r[i]=='0')
    {
        for(;r[k]=='0'&&r[k+1]!='.';k++);
        for(;i<len-k;i++)
        {
            r[i]=r[i+k];
        }
        r[i]='\0';
    }
}
//清除数可不要的小数点
void clDot(char r[])
{
    int len = strlen(r);
    if(r[len-1]=='.')
        r[len-1]=0;
}
//为除计算之用的减法
void dsub(char a[],char b[])
{
    int i,alen,blen;
    char r,t,jiewei=0;
    char *pb ;
    alen = strlen(a);
    blen = strlen(b);
    pb = (char *)calloc(alen,sizeof(char));
    //使pb与a位数对齐//
    memset(pb,'0',alen);
    t = alen;
    for(i=blen-1;i>=0;i--)
        pb[--t]=b[i];
    
    
    for(i=alen-1;i>=0;i--) //相减运算
    {
        t = a[i]-jiewei;
        if(t<pb[i]) jiewei=1;
        else jiewei = 0;
        r = (t+jiewei*10)-pb[i];
        a[i] = r+'0';
    }
    a[alen]='\0';
    clz(a);
    free(pb);
}
//比较两数的大小
int cmp(const char a[],const char b[])
{
    int alen = strlen(a);
    int blen = strlen(b);
    if(alen>blen)
        return 1;
    else if(alen == blen)
    {
        if(strcmp(a,b)>0)
            return 1;
        if(strcmp(a,b)==0)
            return 0;
    }
    return -1;
}
//除法计算
void divid(const char a[],const char b[],char result[])
{
    bool isNegative = false;
    char *op1,*pa,*pb,*pr;
    int up,alen,blen,adotp,bdotp,i,k,dotp,t,t1,j,quo_size;
    /////////////判定符号///////////////
    //如果为异号
    if((a[0] == '-'||b[0] == '-')&&a[0] != b[0])
        result[0] = '-',isNegative = true;
    
    //去除负号
    if(a[0] == '-')a++;
    if(b[0] == '-')b++;
    ///////////////////////////////////
    
    alen = strlen(a)-1; //减去一位小数点
    blen = strlen(b)-1;
    
    ///////获取被除数小数点移位后的位置//////////
    adotp = strchr(a,'.')-a;
    bdotp = strchr(b,'.')-b;
    
    //计算商小数点位置
    dotp = adotp+blen-bdotp;
    if(isNegative)dotp++;
    
    //////////准备数据/////////////
    op1 = (char *)calloc(alen+blen+1,sizeof(char));
    pa = (char *)calloc(alen+blen+1,sizeof(char));
    pb = (char *)calloc(blen+1,sizeof(char));
    pr = (char *)calloc(alen+blen+1,sizeof(char));
    
    for(i = 0,t=0; i<=alen; i++)
    {
        if(a[i]!='.')
            pa[t++] = a[i];
    }
    for(;t<dotp-1;t++)
    {
        pa[t] = '0';
    }
    for(;t<blen;t++)
    {
        pa[t] = '0';
    }
    
    pa[t] = '\0';
    for(i = 0,t=0; i<=blen; i++)
    {
        if(b[i]!='.')
            pb[t++] = b[i];
    }
    pb[t] = '\0';
    clz(pa);
    clz(pb);
    ////////取得被除数的高位数op1,且op1大于被除数b//////////
    strncpy(op1,pa,strlen(pb));
    if(strcmp(op1,pb)<0)
    {
        strncpy(op1,pa,strlen(pb)+1);
    }
    
    /////计算//////
    j = k = strlen(op1);
    t1=0;
    quo_size = strlen(pa)+1-k; //获取商的长度
    
    while(t1<quo_size)
    {
        up = 0;
        t = cmp(op1,pb);
        while(t>=0)
        {
            dsub(op1,pb);
            t = cmp(op1,pb);
            up++;
        }
        pr[t1++] = up+'0';
        op1[strlen(op1)]=pa[j++];
        clz(op1);
    }
    quo_size+=50;//加50精度
    while(t1<quo_size&&(cmp(op1,(char *)"0")>0))
    {
        up = 0;
        op1[strlen(op1)]='0';
        t = cmp(op1,pb);
        while(t>=0)
        {
            dsub(op1,pb);
            t = cmp(op1,pb);
            up++;
        }
        pr[t1++] = up+'0';                    
    }
    //////////////////////////////
    
    if(isNegative)t=1;
    else t=0;
    for(i=0;i<=t1;i++)//复制结果并给商加上小数点
    {
        if(t==dotp) result[t++] = '.';
        result[t++]=pr[i];
    }   
    
    
    clz(result);
    clDot(result);
    free(op1);
    free(pa);
    free(pb);
}

void divide()
{
    char result[1000],a[1000],b[1000];
    printf("请输入第一个数:\n");
    gets(a);
    printf("请输入第二个数:\n");
    gets(b);
    divid(a,b,result);
    printf("结果为:\n");
    puts(result);
}


int main()
{
    add();
    minus();
    mutilplication();
    divide();
    return 0;
}