#include<stdio.h>
#define MAX 8;
main()
{
  int a[]={2,3,6,5,1,7,8,4};
  int len=MAX;
  int l,m,r;
  l=m=0;
  r=len-1;
  merge_sort(a,l,r);
  for(l=0;l<=r;l++)
  printf("%d",a[l]);
  printf("\nDone sorting in ascending ordrer\n");
  printf("Press any key to exit\n");
  getchar();
}

merge_sort(int a[],int l,int r)
{
  int m;
  if(l<r)
    {
      m=(r+l)/2;
      merge_sort(a,l,m);
      merge_sort(a,m+1,r);
      merge(a,l,m,r);
    }
}

merge(int a[],int l,int m,int r)
{
  int temp[8];
  int i,j,k;
  m=m+1;
  i=k=l;
  j=m;
  while((i<m)&&(j<=r))
    {
      if(a[i]<a[j])
	{
	  temp[k]=a[i];
	  k++;
	  i++;
	}
      else if(a[j]<a[i])
	{
	  temp[k]=a[j];
	  k++;
	  j++;
	}
    }

      while(j<=r)
	{
	  temp[k]=a[j];
	  k++;
	  j++;
	}

     while(i<m)
	{
	  temp[k]=a[i];
	  k++;
	  i++;
	}
  for(k=l;k<=r;k++)
    {
      a[k]=temp[k];
    }
}
