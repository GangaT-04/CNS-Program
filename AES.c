#include<stdio.h>
void main()
{
	short a[16][16],b[16][16],key1[16][16];
	short mix[16][16],m[16][16]={02,03,01,01,01,02,03,01,01,01,02,03,03,01,01,02};
	char p[]="Two One Nine Two";
	char k1[]="Thats my Kung fu";
	int i,j,k=0,c=0,temp;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			a[j][i]=p[k++];
		}
	}
	printf("Plain Text in 4x4 matrix:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%x\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			b[j][i]=k1[c++];
		}
	}
	printf("Keyin 4x4 matrix:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%x\t",b[i][j]);
		}
		printf("\n");
	}
	printf("Shift Rows:\n");
	for(i=1;i<4;i++)
	{
		for(j=i;j<4;j++)
		{
			temp=a[j][0];
			for(k=0;k<3;k++)
			{
				a[j][k]=a[j][k+1];
			}
			a[j][k]=temp;
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%x\t",a[i][j]);
		}
		printf("\n");
	}
	printf("Mix column:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			mix[i][j]=0;
			for(k=0;k<4;k++)
			{
				mix[i][j]+=m[i][k]*a[k][j];
			}
			mix[i][j]=mix[i][j]%283;
		}
    }
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%x\t",mix[i][j]);
		}
		printf("\n");
	}
	printf("Add Round Key:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			key1[i][j]=mix[i][j]^b[i][j];
			
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%x\t",key1[j][i]);
		}
		printf("\n");
	}
}