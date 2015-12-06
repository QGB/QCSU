// sub.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * left(char *dst,char *src, int n)
{
    char *p = src;
    char *q = dst;
    int len = strlen(src);
    if(n>len) n = len;

    while(n--) *(q++) = *(p++);
    *(q++)='\0';
    return dst;
}
/**
 *n:����
 *m:λ��
 */
char * mid(char *dst,char *src,int m ,int n)
{
    char *p = src;
    char *q = dst;
    int len = strlen(src);
    if(n>len) n = len-m;
    if(m<0) m=0;
    if(m>len) return NULL;
    p += m;
    while(n--) *(q++) = *(p++);
    *(q++)='\0';
    return dst;
}

char * right(char *dst,char *src, int n)
{
    char *p = src;
    char *q = dst;
    int len = strlen(src);
    if(n>len) n = len;
    p += (len-n);
    while(*(q++) = *(p++));
    return dst;
}


int strFind(char *str,char c)
{
 int n=0;
 while(*str)
 {
  if(*str==c) return n;
  n++,str++;
 }
 return n;
}

int StringFind( char* string,const char* find){
	int number=1;
	char* pos = string;
	char* p = string;
	int count = -1;
	while (number > 0)
	{
		/*������ҵ����ַ�λ�õ�ָ�룬�Ա���ʱָ����б���*/
		pos = strstr(p,find);
		/*��λ��ָ��Ϊ0ʱ��˵��û���ҵ�����ַ�*/
		if (pos == 0)
			return -1;
		/*��λ��ָ�����ʱָ�����˵����һ���ַ�����Ҫ�ҵ��ַ��������ʱָ��С��λ��ָ�룬����б����ַ�������������count��1*/
		while(p <= pos)
		{
			if(*p > 0x80 || *p < 0)
			{
				p++;
			}
			p++;
			count++;
		}
		/*��Ҫ���ҵĴ�����һ*/
		number--;
	}
	return count;
}


char* sub( char* ast,char* asa,char* asb){
	int ia=-1,ib=-1,iam=0,ibm=0,im=0;
	//printf("t=[%s],a=[%s],b=[%s]",ast,asa,asb);
	 iam=strlen(asa);
	 ibm=strlen(asb);
	 im=strlen(ast);

	if (im==0)
		return "";

	if (iam==0&&ibm==0)
		return "";

	char* sd=(char *)malloc(im*sizeof(char));
	int i=0;
	for (i=0;i<im;i++)
		sd[i]='\0';

	if (iam==0)
	{
		ib=StringFind(ast,asb);
		if (ib==-1)
			return "";

		memcpy(sd,ast,ib);
		return sd;
	}


	if (ibm==0)
	{
		ia=StringFind(ast,asa);
		if (ia==-1)
			return "";
		ia=ia+iam;
		memcpy(sd,ast+ia,im);
		return sd;
	}


	if (NULL !=strstr(asa,asb))
		return "";

	ia=StringFind(ast,asa)+iam;

	im=im-ia;
	if (0==im||-1==ia)
		return "";


	memcpy(sd,ast+ia,im);

	char* sdb=(char *)malloc(im*sizeof(char));
	for (i=0;i<im;i++)
		sdb[i]='\0';

	ib=StringFind(sd,asb);
	if (ib==-1)
		return "";
	memcpy(sdb,sd,ib);

	return sdb;
}
#define errExit return -1;

//FILE* ft=fopen("D:\\VS2008\\sub\\Debug\\t.txt","r");


int main(int argc, char* argv[])
{
    char * as1="",*as2="";



	//help
	if (argc<2)	{
		printf("Usage: sub s1 [s2]\n\t input:stdin\n\t output:stdout\n");
		system("pause");
		errExit
	}

//  args
	if (NULL==argv[1])as1="";
    else as1=argv[1];

    if (NULL==argv[2])as2="";
    else as2=argv[2];

//    printf("%s,[%s],%d",as1,as2,argv[argc]==NULL);
//    return -2;
	//argv[1]="1\0";
	//argv[2]="B\0";

	char sl[1024];             //ÿ������ȡ���ַ���
	while(1)
	{
		if (fgets(sl,1024,stdin)!=NULL){
			//strlen(sl);
			char* sp=sub(sl,as1,as2);
			int im=strlen(sp);
			if (im<1)
				continue;

			if(sp[im-1]!='\n'){
				sp[im]='\n';
				sp[im+1]='\0';
			}

			fputs(sp,stdout);

		}else{
			break;
		}
			//
	}

	//printf("123\n");
//	system("pause");
	return 0;
}

