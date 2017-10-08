#include <stdio.h>
//using namespace std;
int main()
{
	int i,j,inFloor;
	printf("Please, enter number of floors: \n");
	scanf("%d",&inFloor);
	printf("\nFist floor:\n");
	//fist floor
	for (i=0;i<inFloor;i++)
	{
		printf("*");
		for (j=1;j<=i;j++)
			printf("*");			
		printf("\n");
	}	
	printf("\nSecond floor:\n");
	//second floor
	for (i=inFloor;i>0;i--)
	{
		printf("*");
		for (j=1;j<i;j++)
			printf("*");
		printf("\n");
	}
	printf("\nFir-tree:\n");
	//fir-tree
	for (i=0;i<inFloor;i++)
	{
		if (i<=inFloor)
		{	
			for (j=0;j<=inFloor-i;j++)
				printf(" ");
			for (j=0;j<=2*i;j++)
				printf("*");
		} 
	 	printf("\n");
	}
	//stump
	for(i=1;i<=inFloor;i++)
		if (i<=inFloor)
			printf(" ");
	printf(" *");
	return 0;
}
