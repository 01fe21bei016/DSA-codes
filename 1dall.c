#include<stdio.h>
#include<time.h>

main()
{
    int a[90],n;
    printf("Enter the value of n\n");
         scanf("%d",&n);

    read(a,n);
    asc(a,n);
}
  void read(int a[90],int n)
 {
     int i;
     printf("Enetr th array elements\n");
     for(i=0;i<n;i++)
     {
         scanf("%d",&a[i]);
     }

 }

 void asc(int a[90],int n)
 {
     double start,stop;
     int i,j,temp;
     start=clock();
     for(i=0;i<n-1;i++)
     {
         for(j=0;j<n-i-1;j++)
         {
             if(a[j]>a[j+1])
             {
                 temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
             }
         }
         //printf("%d ",a[i]);
     }
    // printf("%d",a[i]);

    for(i=0;i<n;i++)
     {
         printf("%d ",a[i]);
     }
      printf("\n");
      stop=clock();
     printf("\n%lf",(stop)/CLOCKS_PER_SEC);

}
