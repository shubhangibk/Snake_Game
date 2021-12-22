#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct snake     //DECLARATION OF NODE OF SNAKE
{
   int x;
   int y;
   char symbol;
   struct snake *next;
}*head=NULL, *tail=NULL;
int fruit_x,fruit_y,GameOver=3;   //DECLARATION OF VARIABLES
int count=0,m;

void createsnakehead()  //DECLARATION OF HEAD OF SNAKE
{
    struct snake *s=(struct snake*)malloc(sizeof(struct snake));
    s->symbol='o';
    s->x=20;
    s->y=20;
    s->next=NULL;
    head=s;
}
void createsnakebody() //DECLARATION OF BODY OF SNAKE
{
    struct snake *s=(struct snake*)malloc(sizeof(struct snake));
    s->symbol='o';
    tail->next=s;
    s->next=NULL;
    tail=s;
}
void createsnaketail() //DECLARATION OF TAIL OF SNAKE
{
    struct snake *s=(struct snake*)malloc(sizeof(struct snake));
    struct snake *temp=head;
    s->symbol='o';
    s->x=19;
    s->y=20;

    while(temp->next!=NULL)
    {
       temp=temp->next;
    }
    temp->next=s;
    s->next=NULL;
    tail=s;
}

void createfield() //DECLRATION OF CREATION OF FIELD
{
    system ("cls");
   int i,j;
   for(i=0;i<=40;i++)
   {
      for(j=0;j<=40;j++)
      {
        m=0;
        if(i==0||i==40||j==0||j==40)
        {
            printf("*");
        }
        else
         {
             if(((j==10)&&(i<30)&&(i>10))||((j==30)&&(i<30)&&(i>10)))
            printf("#");
        else
        {
         if(i==head->y&&j==head->x)
            printf("%c",head->symbol);
         else
         {

           if(i==tail->y && j==tail->x)
           {
               printf("%c",tail->symbol);
            for(m=0;m<count;m++)
            {
            printf("%c",tail->symbol);
            }

           }
             else
           {
               if(i==fruit_y && j==fruit_x)  //PRINTING OF FRUIT
                  printf("F");
               else
                  printf(" ");
           }
         }
         }
         }
         j=j+m;
        }
      printf("\n");
      }
   printf("\tSCORE : %d\t LIFE: %d",5*count,GameOver);  //TO PRINT SCORE AND LIFE
}
void fruit () //DECLRATION OF FRUIT USING RANDOM FUNCTION
{
    fan1:
    fruit_x=rand()%40;
    if(fruit_x==0 || fruit_x==head->x || fruit_x==10|| fruit_x>=30)
       goto fan1;

    fan2:
    fruit_y=rand()%40;
    if(fruit_y==0||fruit_y==head->y)
        goto fan2;

}
void keys() //DECLARATION OF KEYS TO PLAY THE GAME
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':  //CLICK a TO MOVE
				tail->x=head->x;
				tail->y=head->y;
				(head->x)--;
                break;
			case 'd': //CLICK d TO MOVE
				tail->x=head->x;
				tail->y=head->y;
				(head->x)++;
				break;
			case 's': //CLICK s TO MOVE
				tail->x=head->x;
				tail->y=head->y;
				(head->y)++;
				break;
			case 'w':  //CLICK w TO MOVE
				tail->x=head->x;
				tail->y=head->y;
				(head->y)--;
				break;
			case 'x':  //IF YOU CLICK x THEN GAME WILL EXIT
				GameOver=0;
				break;
		}
		createfield();  //FUNCTION CALL TO CREATE FIELD
	}
}
void logic()
{
	if((head->x==fruit_x && head->y==fruit_y)||(tail->x==fruit_x && tail->y==fruit_y))
	{
        createsnakebody(); //FUNCTION CALL OF SNAKEBODY
		fruit(); //FUNCTION CALL TO DISPLAY FRUIT
		count++; //TO ADD THE FRUIT EATEN

	}
}
int main()
{
  int i,j,k;
  printf("*************INSTRUCUTIONS**************\n");  //DISPLAY OF INSTRUCTIONS OF HOW TO PLAY GAME
  printf("1.Use 'W' to move UP.\n");
  printf("2.Use 'S' to move DOWN.\n");
  printf("3.Use 'A' to move LEFT.\n");
  printf("4.Use 'D' to move RIGHT.\n");
  printf("5.You will have 3 lives per game.\n");
  printf("6.If your snake touches the boarder of the field you will loose 1 LIFE!!\n");
  printf("7.If your snake gets touched to any obstacles in the field, you will loose 1 of LIFE!!\n");
  printf("8.If your snake consumes fruit(F) your score will increase along with length of snake.\n");
  printf("\tENJOY THE GAME!\n");
  printf("\n.......Press '1' and enter to continue.......\n");
  scanf("%d",&k);
  if(k=1) //TO CONTINUE THE GAME AFTER THE INSTRUCTIONS
  {
      pan:
      createsnakehead(); //FUNCTION CALL TO CREATE SNAKE HEAD
      createsnaketail(); //FUNCTION CALL TO CREATE SNAKE TAIL
      fruit(); //FUNCTION CALL TO DISPLAY FRUIT
      createfield();//FUNCTION CALL TO CREATE FIELD
  while(GameOver) //TO PLAY THE GAME UNTIL GAME IS NOT OVER
   {
   	keys();//  TO CALL KEYS TO PLAY THE GAME
   	if (head->x==0||head->x==40||head->y==0||head->y==40||tail->x==0||tail->x==40||tail->y==0||tail->y==40||((head->x==10)&&((head->y)<30)&&((head->y)>10))||((head->x==30)&&((head->y)<30)&&((head->y)>10)))
		{
		    system("cls");// IF THE GAME IS OVER THEN CLEAR SCREEN
			GameOver--; // TO REDUCE THE CHANCES TO PLAY THE GAME
			goto pan;
		}
    logic();
   }
   }
   system("cls");
   printf("\n\n\t\tGAME OVER!!\n\n\t\tYOUR SCORE IS :%d\n\n",5*count); //TO PRINT THE FINAL SCORE
  return 0;
}

