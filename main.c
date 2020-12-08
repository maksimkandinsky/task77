#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void binsearch( int *p, int l,int r,int n){
     int m;
     m = (l+r)/2;
     if (l>r){
        printf(-1);
     }else{
     if(p[m]==n){
        printf("%d",m);
     }
     if(p[m]>n){
        binsearch(p,l,m-1,n);
     }
     if(p[m]<n){
        binsearch(p,m+1,r,n);
     }
     }
}
void f(int *p,int *q, int m,int n){
int s[m+n];
int j,k,t,l;
for(j = 0;j<m+n;j++){
    if (j<m){
        s[j]=p[j];
    }else{
    s[j]=q[j-m];
    }
}
    for(j =m;j<m+n;j++){
        for(k = j-m;k<j;k++){
            if(s[j]<s[k]){
               t = s[j];
               for(l = j;l>k;l--){
                s[l]=s[l-1];
               }
                s[k]=t;
            }
        }
    }
for(j = 0;j<m+n;j++){
    printf("%d\n",s[j]);
}
}
int main()
{
 setlocale(LC_ALL,"Rus");
   int m,n,i,k,x;
   int *p,*q,*r;
printf("Введите кол-во элементов в первом массиве,во 2,элементы первого,элементы второго\n");
   scanf("%d%d",&m,&n);
   p = (int*)malloc(m*sizeof(int));
   q = (int*)malloc(n*sizeof(int));
   for(i = 0;i<m;i++){
    scanf("%d",&p[i]);
   }
    for(i = 0;i<n;i++){
    scanf("%d",&q[i]);
   }
   f(p,q,m,n);
   printf("Введите колво элементов,элементы,элемент,номер которого надо найти\n");
   scanf("%d",&k);
   r=(int*)malloc(k*sizeof(int));
   for(i = 0;i<k;i++){
    scanf("%d",&r[i]);
   }
   scanf("%d",&x);
   binsearch(r,0,k-1,x);
    return 0;
}
