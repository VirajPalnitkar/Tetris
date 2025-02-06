#include <stdio.h>
#include <stdlib.h>
int main()
{
	//void display(char [10][10]);
	//char input(void);
	int flag=1,column,score=0;
	char shape,x;
	printf("---------------->>Welcome to tetris game<<---------------------\n");
	printf("The shapes available are:-\n square\n* * *\n* * *\n* * *\nhorizontal line\n* * * *");
	printf("\nvertical line\n*\n*\n*\n*\n");
	char screen[10][10];
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			screen[i][j]=' ';
		}
	}
	while(flag)
	{
	
	for(int i=0;i<10;i++)
	{
		printf("-%d",i);
	}
	printf("\n");
	for(int i=0;i<10;i++)
	{
	printf("%d",i);	
		for(int j=0;j<10;j++)
		{
			printf("%c ",screen[i][j]);
		}
	printf("\n");
	}
	for(int i=0;i<10;i++)
	{
		printf("- ");
	}
	
	
	column=rand()%10;
	printf("\nThe block is to be inserted with its left most element in %d column\n",column);
	printf("Select a shape:\nEnter-\ns for square(15 points)\nv for vertical line(20 points)\nh for horizontal line(5 points)\n");
	
	printf("Warning: your shape cannot enter the 9th row ofr the game will end!!\n");
	scanf("%c",&shape);
	switch (shape)
	{
	case 's':
	{
	if (column>7)
		printf("Invalid Input Space\n");
	else
	{
		for(int i=0;i<8;i++)
		{
			if(screen[i][column]==' ' && screen[i][column+1]==' ' && screen[i][column+2]==' ')
			{
				screen[i][column]=screen[i][column+1]=screen[i][column+2]=screen[i+1][column]=screen[i+1][column+1]=screen[i+1][column+2]=screen[i+2][column]=screen[i+2][column+1]=screen[i+2][column+2]='*';
			score+=15;
			break;
			}
		}
	}
	}
	break;
	case 'v':
	{
		for(int i=0;i<7;i++)
		{
			if (screen[i][column]==' ' && screen[i+1][column]==' ' && screen[i+2][column]==' ' && screen[i+3][column]==' ')
			{
				screen[i][column]=screen[i+1][column]=screen[i+2][column]=screen[i+3][column]='*';
				score+=20;
				break;
			}
		}
	}
	break;
	case 'h':
	{
		if (column>6)
			printf("\nIvalid Shape Input\n");
		else{
		for(int i=0;i<10;i++)
		{
			if (screen[i][column]==' ' && screen[i][column+1]==' ' && screen[i][column+2]==' ' && screen[i][column+3]==' ')
			{
				screen[i][column]=screen[i][column+1]=screen[i][column+2]=screen[i][column+3]='*';
				score+=5;
				break;
			}
		}
		}
	}
	break;
//default: printf("This is Invalid Shape Input\n");
	}
	printf("\nLive score tracker ---------- score=%d\n",score);
	if(screen[9][1]=='*' || screen[9][2]=='*' || screen[9][3]=='*' ||screen[9][4]=='*' || screen[9][0]=='*' || screen[9][5]=='*' || screen[9][6]=='*' ||screen[9][7]=='*' || screen[9][8]=='*' || screen[9][9]=='*')
	flag=0;
}
printf("\n\nThe Game has ended\n");
printf("Your score is %d",score);
return 0;
}
