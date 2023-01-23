#include<stdio.h>
#include<conio.h>
char c[100],p[100];
char *encryption(char p[],int k)
{
	
	int c1,i=0,n;
	while(p[i]!='\0')
	{
		if(p[i]>='a' && p[i]<='z')
		{
			n=p[i]-'a';
			c1=(n+k)%26;
			c1=c1+'a';
		}
		c[i]=c1;
		i=i+1;
		
	}
	c[i]='\0';
	return c;
}
char *decryption(char c[],int k)
{
	
	int c1,i=0,n;
	while(c[i]!='\0')
	{
		if(c[i]>='a' && c[i]<='z')
		{
			n=c[i]-'a';
			c1=(n-k)%26;
			if(c1<0)
				c1=c1+26;
			c1=c1+'a';
		}
		p[i]=c1;
		i=i+1;
		
	}
	p[i]='\0';
	return p;
}
void main()
{
	char m[100];
	int k;
	printf("Enter the message:");
	scanf("%s",m);
	printf("Enter the key:");
	scanf("%d",&k);
	
	printf("The encryption:%s",encryption(m,k));
	printf("The decryption:%s",decryption(encryption(m,k),k));
}