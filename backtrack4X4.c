#include<stdio.h>
int backtrack(int);
int player[4][4];
	int chess[4][4]={[0][2]=1,[1][0]=1,[2][3]=1,[3][1]=1};
 int	queencheck();
short i,j;
int main()
{
	short l,m;
    short i,j,column,count,label=1,bti,btc;
	int choice;
	printf("\n*****************************************************************4X4 QUEEN's PROBLEM*****************************************************************\n\n");
	printf("Place 4 QUEEN in the board such that no queen should attack each other in any ways.");
	printf("\nNOTE!! The position value should always be less than 5 since it is a 4X4 CHESS Board.\n");
    do
    {
    for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			player[i][j]=0;
		}
	}
		backtrack:
		label=1;
    	count=0;
    	printf("\n");
    	for(i=0;i<4;i++)
	{
    	printf("Enter the position do you want to place the queen in the %d row\n",label++);
    	scanf("%d",&column);
    	if((column>0)&&(column<=4))
    	player[i][column-1]=1;
    	else
    	{
    		printf("Please enter a valid position since it is a 4X4 CHESS board!\n");
    		goto error;
		}
	}
		for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",player[i][j]);
		}
		printf("\n");
	}
	backtrackcheck();
    /*    printf("\nDo you want to backtrack? If yes press '1' else '0'\n");
	    scanf("%d",&btc);
	    if(btc==1)
	    {
	       printf("\nFrom which row you have to backtrack?\n");
	       scanf("%d",&bti);
	       backtrack(bti);
		}
		else
		{
			queencheck();
		}*/
	error:
	printf("\nDo you want to play again? If yes PRESS '1' else PRESS '0''\n");
	scanf("%d",&choice);
	getch();
    }while(choice==1);
	getch();
	return 0;
}
int backtrack(int bti)
{
 short i,column;
 short temp=bti,er;
 for(i=temp;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			player[i-1][j-1]=0;
		}
	}
	printplayer();
 for(i=bti;bti<=4;bti++)
 {
 	printf("backtracking...,\nEnter the position do you want to place the queen in the %d row\n",bti);
    	scanf("%d",&column);
    //	bti++;
    if((column>0)&&(column<=4))
    	player[bti-1][column-1]=1;
    	else
    	{
    		printf("Please enter a valid position since it is a 8X8 CHESS board!\n");
    		printf("\nDo you want to continue? If YES press '1'\n");
    		scanf("%d",&er);
    		bti--;
    		if(er!=1)
    		exit(0);
		}
	 }	
	 backtrackcheck();
	 printplayer();
	 queencheck();
return 0;
}
int queencheck()
{
	short count=0,i,j;
		for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(player[i][j]==chess[i][j])
		    count++;
		}
	}	
	if(count==16)
	printf("\nWOW YOU WON!\n");
	else
	{
    	printf("OOPS YOU LOST\n");
    }
    return 0;
}
int printplayer()
{
	 for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",player[i][j]);
		}
		printf("\n");
	}
}
int backtrackcheck()
{
	short bti,btc;
	printf("\nDo you want to backtrack? If yes press '1' else '0'\n");
	    scanf("%d",&btc);
	    if(btc==1)
	    {
	       printf("\nFrom which row you have to backtrack?\n");
	       scanf("%d",&bti);
	       backtrack(bti);
		}
		else
		{
			queencheck();
			printplayer();
			exit(0);
		}
		return 0;
}
