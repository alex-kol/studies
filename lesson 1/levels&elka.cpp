//program drawing the floor and christmas-tree

#include <stdio.h>

int main()
{
	int level = 0;
	
	printf("Please, enter the number of floors: \n");
	scanf("%d",&level);
	
	//first level
	printf("\nFirst level:\n");
	for (int i = 0; i < level; i++){
		printf("*");
		for (int j = 1; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}

	//second level
	printf("\nSecond level:\n");
	for (int i = level; i > 0; i--){
		printf("*");
		for (int j = 1; j < i; j++){
			printf("*");
		}
		printf("\n");
	}

	//christmas-tree
	printf("\nChristmas-tree:\n");
	for (int i = 0; i < level; i++){
		for (int j = 0; j <= level-i; j++){
			printf(" ");
		}
		for (int j = 0; j <= 2*i; j++){
			printf("*");
		}
		printf("\n");
	}
	
	//stump
	for (int i = 1; i <= level; i++){
		printf(" ");
	}
	printf(" *");
	return 0;
}
