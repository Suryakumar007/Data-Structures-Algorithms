#include <iostream>
#include<bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void merge(int a[],int lb, int mid, int ub)
{
	
	int n=(ub-lb)+1;
	int temp[n];
	
	cout<<"n value is - "<<n<<endl;
	
	int i=lb,j=mid+1,k=0;
	
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			k++;i++;
		}
		
		
		else
		{
			temp[k]=a[j];
			k++;j++;
		}
		
	}
	
	while(i<=mid)
	{
		temp[k]=a[i];
		k++;i++;
	}
	
	while(j<=ub)
	{
		temp[k]=a[j];
		k++;j++;
	}
	
	
	for(int m=lb;m<=ub;m++)
	{
		a[m]=temp[m-lb];
	}
	
}

void mergeSort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mergeSort(a,lb,mid);
		mergeSort(a,mid+1,ub);
		
		merge(a,lb,mid,ub);
	}
}


int main(int argc, char** argv) 
{

	int a[]={8,7,6,5};
	int n=sizeof(a)/sizeof(a[0]);
		
	mergeSort(a,0,n-1);
	
	cout<<"Sorted array : "<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		
	}
	return 0;
}
