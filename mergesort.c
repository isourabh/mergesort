#include<stdio.h>
#define MAX 8;//used to specify length of array
void merge_sort(int a[],int ,int);
void merge(int a[],int ,int ,int);
void print_array(int *,int);
main()
{
  int a[]={2,3,6,5,1,7,8,4};
  int len=MAX;
  int l,m,r;
  l=m=0;
  r=len-1;
  printf("input given\n");
  print_array(a,len);
  merge_sort(a,l,r);
  printf("result after sorting\n");
  print_array(a,len);
  printf("\nDone sorting in ascending ordrer\n");
  printf("Press any key to exit\n");
  getchar();
}

void merge_sort(int a[],int l,int r)
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

void merge(int a[],int l,int m,int r)
{
  int *temp;
  int i,j,k;
  k=MAX;
  temp=(int *)malloc(sizeof (int)*k);
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
  free(temp);
}

void print_array(int *temp, int size)
{
  int i;
  for(i=0;i<size;i++)
    {
      printf("%d ",temp[i]);
    }
  printf("\n");
}
