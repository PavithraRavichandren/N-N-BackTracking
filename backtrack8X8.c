#include<stdio.h>
int backtrack(int);
int player[8][8];
int chess[8][8]={[0][5]=1,[1][3]=1,[2][6]=1,[3][0]=1,[4][7]=1,[5][1]=1,[6][4]=1,[7][2]=1};
int	queencheck();
short i,j;
int main()
{
	short l,m;
    short i,j,column,count,label=1,bti,btc;
	int choice;
	printf("\n*****************************************************************8X8 QUEEN's PROBLEM*****************************************************************\n\n");
	printf("Place 8 QUEEN in the board such that no queen should attack each other in any ways.");
	printf("\nNOTE!! The position value should always be less than 9 since it is a 8X8 CHESS Board.\n");
    do
    {
    for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			player[i][j]=0;
		}
	}
		backtrack:
		label=1;
    	count=0;
    	printf("\n");
    	for(i=0;i<8;i++)
	{
    	printf("Enter the position do you want to place the queen in the %d row\n",label++);
    	scanf("%d",&column);
    	if((column>0)&&(column<=8))
    	player[i][column-1]=1;
    	else
    	{
    		printf("Please enter a valid position since it is a 8X8 CHESS board!\n");
    		goto error;
		}
	}
		for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d ",player[i][j]);
		}
		printf("\n");
	}
	backtrackcheck();
       /* printf("\nDo you want to backtrack? If yes press '1' else '0'\n");
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
		} */
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
 short i,column,er;
 short temp=bti;
 for(i=temp;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			player[i-1][j-1]=0;
		}
	}
	printplayer();
 for(i=bti;bti<=8;bti++)
 {
 	printf("backtracking...,\nEnter the position do you want to place the queen in the %d row\n",bti);
    	scanf("%d",&column);
    //	bti++;
    if((column>0)&&(column<=8))
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
    	
    		
    		//goto error;
	 }	
	 backtrackcheck();
	 printplayer();
	 queencheck();
return 0;
}
int queencheck()
{
	short count=0,i,j;
		for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(player[i][j]==chess[i][j])
		    count++;
		}
	}	
	//printf(" \nCOUNT %d",count);
	if(count==64)
	printf("WOW YOU WON!\n");
	else
	{
    	printf("OOPS YOU LOST\n");
    }
 //   printplayer();
    return 0;
}
int printplayer()
{
	 for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
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
	       if((bti>0)&&(bti<=8))
	       backtrack(bti);
	       else
	       printf("\nPlease enter a valid position since it is a 8X8 CHESS board");
		}
		else
		{
			queencheck();
			printplayer();
			exit(0);
		}
		return 0;
}
