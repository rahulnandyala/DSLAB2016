#include<stdio.h>
#include<stdlib.h>
#define maxsize 50
void inp(int a[],int size);
void disp(int a[],int size);
void insert(int a[],int *size,int pos,int ele);
void del(int a[],int *size,int pos); 
void main()
{
 int ch,a[maxsize],size,ele,pos;
 char ch1;
 do
 {
  printf("\nMENU:\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit");
  printf("\nEnter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the size: ");
	  scanf("%d",&size);
          inp(a,size);
	  break;
   case 2:printf("The array is: ");
	  disp(a,size);
	  break;
   case 3:printf("\nEnter element that you want to enter: ");
	  scanf("%d",&ele);
	  printf("\nEnter the position you want to enter in: ");
	  scanf("%d",&pos);
   	  insert(a,&size,pos,ele);
	  break;
   case 4:printf("\nEnter the position you want to delete from: ");
 	  scanf("%d",&pos);
   	  del(a,&size,pos);
	  break;
   case 5:exit(0);
	  break;
   default:printf("\nPlease enter the correct choice!!!!");
	   break;
  }
 printf("\nDo you want to enter the menu again(y/n): ");
 scanf("%*c%c",&ch1);
 }while(ch1=='y'||ch1=='Y');
}//end of main

void inp(int a[],int size)
{
 if(size>maxsize)
 {
  printf("\nSize exceeds maximum limit!!!");
 }
 else
 {
  int i;
  printf("\nEnter the elements:\n");
  for(i=0;i<size;i++)
  {
   scanf("%d",&a[i]);
  }
 }
}//end of function

void disp(int a[],int size)
{
 int i;
 printf("\nThe Array is: ");
 for(i=0;i<size;i++)
 {
  printf("%d ",a[i]);
 }
}//end of function

void insert(int a[],int *size,int pos,int ele)
{
 int i,tmp,tmp1;
 if((pos-1)>=0&&(pos-1)<=*size)
 {
  *size=*size+1;
  if(*size>maxsize)
  {
   printf("\nCannot enter as it exceeds max limit!!!");
   *size=*size-1;
  }
  else
  {
   tmp=a[pos-1];
   a[pos-1]=ele;
   for(i=pos-1;i<*size-1;i++)
   {
    tmp1=a[i+1];
    a[i+1]=tmp;
    tmp=tmp1;
   }
  }
 }
 else
 {
  printf("\nInvalid Position!!!");
 }
}//end of function

void del(int a[],int *size,int pos)
{
 if((pos-1)<0||(pos-1)>*size)
 {
  printf("\nInvalid Position!!!");
 }
 else
 {
  int i,tmp,tmp1;
  *size=*size-1;
  tmp=a[pos-1];
  for(i=pos-1;i<*size;++i)
  {
   a[i]=a[i+1];
  }
  printf("\nDeleted the element %d!!!",tmp);
 }
}//end of function
