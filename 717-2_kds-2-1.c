#include <stdio.h> 
int main(){ 
int n,y=1,a,b,prov=1; 
scanf("%d",&n); 
scanf("%d",&a); 
while(y<=n-1){ 
scanf("%d",&b);  
y++; 
if(a<b) printf("%d",1); 
else printf("%d",0); 
}; 
return 0; 
}
