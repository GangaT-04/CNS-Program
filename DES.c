#include<stdio.h>
#include<conio.h>
void main(){
int key[56],plain[64],a[64],b[56],c[48],i1,j1,temp,k,g;
int 
plain1[64]={58,50,42,34,26,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56
,48,40,32,24,16,8,57,49,41,33,25,17,9,1,58,51,43,35,27,19,11,3,61,53,45,37,29,21,13
,5,63,55,47,39,31,23,15,7};
int i,j, 
key1[56]={31,41,51,21,11,1,2,12,22,32,42,52,3,13,23,33,43,53,4,14,24,34,44,54,5,15,
25,35,45,55,6,16,26,36,46,56,7,17,27,37,47,8,18,28,38,48,9,19,29,39,49,10,20,30,40,
50};
printf("enter plain:");
for(i=0;i<64;i++){
scanf("%d",&plain[i]);
}
printf("enter key:");
for(j=0;j<56;j++){
 scanf("%d",&key[j1]);
}
//initial permutation
temp=plain[0];
for(i=0;i<63;i++){
 plain[i]=plain[i+1];
}
plain[i]=temp;
temp=key[0];
for(j=0;j<55;j++){
 key[j]=key[j+1];
}
key[j]=temp;
for(i=0;i<64;i++){
 a[i]=plain[plain1[i]];
}
for(j=0;j<56;j++){
 b[j]=key[key1[j]];
}
//divide into two halfs
temp=b[0];
for(i=0;i<28;i++){
b[i]=b[i+1];
}
b[i]=temp;
temp=b[28];
for(i=28;i<55;i++){
b[i]=b[i+1];
}
b[i]=temp;
//contradict
for(i=7;i<56;i=i+8){
 b[i]=3;
}
for(j=0,i=0;j<56;j++){
if(b[j]!=3){
 c[i]=b[j];
 i++;
}
//above reduced to 48 bit
}
for(k=0;k<16;k++){
	int f,s,m[64],n[48],o[48],p[32],co,l;
	for(j=32,i=0;j<64;j++,i++){
		m[i]=a[j];
		a[i]=a[j];
	}
//expand to 48 bit
for(j=32,co=0;j<64;i++,j++){
	if(co<48) {
		n[i]=a[j];
        co++;
		if(j==63){
			j=32;
		}
	}
}
//XOR with key
 	for(l=0;l<48;l++){
 		o[l]=n[l]^c[l];
 	}
//reduce to 32 bit
	for(i=7;i<48;i=i+8)
	{
		o[i]=3;
	}
	for(j=0,i=0;j<48;j++)
	{
		if(o[j]!=3){
 			p[i]=o[j];
			i++;
		}
 		for(f=0,s=32;f<32;f++,s++){
 // a[s]=a[f]^p[f];
 			if((a[f]!=0)&&(p[f]!=0)){
 				a[s]=0;
 			}
 			else{
 				a[s]=1;
 			}
		}
	}
}
printf("\n\n ENCRYPTED OUTPUT:::\n\n");
for(g=0;g<64;g++){
printf("%d ",a[g]);
}
getch();
}