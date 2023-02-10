/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  :ZHANG ZHIRUI
 * Student ID    :1155174021
 * Class/Section :ENGG1110F
 * Date          :24/11/2021
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2


/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
    int a,b;
 for(a=0;a<6;a++)
 {
     for(b=0;b<7;b++)
     gameBoard[a][b]=EMPTY;
 }
 return;
 }


/* Display the game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
 /*printf("|%d|%d|%d|%d|%d|%d|%d|\n",gameBoard[5][0],gameBoard[5][1],gameBoard[5][2],gameBoard[5][3],gameBoard[5][4],gameBoard[5][5],gameBoard[5][6]);
 printf("|%d|%d|%d|%d|%d|%d|%d|\n",gameBoard[4][0],gameBoard[4][1],gameBoard[4][2],gameBoard[4][3],gameBoard[4][4],gameBoard[4][5],gameBoard[4][6]);
 printf("|%d|%d|%d|%d|%d|%d|%d|\n",gameBoard[3][0],gameBoard[3][1],gameBoard[3][2],gameBoard[3][3],gameBoard[3][4],gameBoard[3][5],gameBoard[3][6]);
 printf("|%d|%d|%d|%d|%d|%d|%d|\n",gameBoard[2][0],gameBoard[2][1],gameBoard[2][2],gameBoard[2][3],gameBoard[2][4],gameBoard[2][5],gameBoard[2][6]);
 printf("|%d|%d|%d|%d|%d|%d|%d|\n",gameBoard[1][0],gameBoard[1][1],gameBoard[1][2],gameBoard[1][3],gameBoard[1][4],gameBoard[1][5],gameBoard[1][6]);
 printf("|%d|%d|%d|%d|%d|%d|%d|\n",gameBoard[0][0],gameBoard[0][1],gameBoard[0][2],gameBoard[0][3],gameBoard[0][4],gameBoard[0][5],gameBoard[0][6]);
 printf(" 1 2 3 4 5 6 7\n");*/
 int a,b;
 for(b=5;b>=0;b--){
   printf("|");
   for(a=0;a<7;a++){
     if(gameBoard[b][a]==EMPTY)
      printf(" |");
     if(gameBoard[b][a]==CIRCLE)
      printf("O|");
     if(gameBoard[b][a]==CROSS)
      printf("X|");
   }
 printf("\n");
 }
 printf(" 1 2 3 4 5 6 7\n");
 return;
 }
 /* Ask the human player to place the mark.
   You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {

    // TODO : Complete this part
 int place;
 if(mark==CIRCLE){
      //  int place;

      scanf("%d",&place);
      place--;
      while(place<0||place>6){
        printf("Input out of range. Please input again:\n");
        scanf("%d",&place);
        place--;
      }
      for(int clu=0;gameBoard[clu][place]!=EMPTY;clu++){
        if(clu>5){
        printf("Column is full. Please input again:\n");
        scanf("%d",&place);
        place--;
      }}
  }
 else{

      scanf("%d",&place);
      place--;
      while(place<0||place>6){
        printf("Input out of range. Please input again:\n");
        scanf("%d",&place);
        place--;
      }
      for(int clu=0;gameBoard[clu][place]!=EMPTY;clu++){
        if(clu>5){
        printf("Column is full. Please input again:\n");
        scanf("%d",&place);
        place--;
      }}
 }
 //不要动下面的
 int a,b;
 a=place;//a指列
 b=0;//b指行
 while(1){
  if(gameBoard[b][a]==EMPTY)
   break;
  else
   b++;
 }
 gameBoard[b][a]=mark;
 return;
 }


 /* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[6][7]){

    // TODO : Complete this part
   for(int a=0;a<6;a++){//同一行
     for(int b=0;b<4;b++){
       if(gameBoard[a][b]==gameBoard[a][b+1]&&gameBoard[a][b+1]==gameBoard[a][b+2]&&gameBoard[a][b+2]==gameBoard[a][b+3]){
         if(gameBoard[a][b]==CIRCLE)
          return 88;
         if(gameBoard[a][b]==CROSS)
          return 99;
       }

     }
   }
   for(int a=0;a<3;a++){//同一列
     for(int b=0;b<7;b++){
       if(gameBoard[a][b]==gameBoard[a+1][b]&&gameBoard[a+1][b]==gameBoard[a+2][b]&&gameBoard[a+2][b]==gameBoard[a+3][b]){
          if(gameBoard[a][b]==CIRCLE)
          return 88;
         if(gameBoard[a][b]==CROSS)
          return 99;
       }

     }
   }
   for(int a=0;a<3;a++){//同一/
     for(int b=0;b<4;b++){
       if(gameBoard[a][b]==gameBoard[a+1][b+1]&&gameBoard[a+1][b+1]==gameBoard[a+2][b+2]&&gameBoard[a+2][b+2]==gameBoard[a+3][b+3]){
          if(gameBoard[a][b]==CIRCLE)
          return 88;
         if(gameBoard[a][b]==CROSS)
          return 99;
       }

     }
   }
   for(int a=3;a<6;a++){//同一、
     for(int b=0;b<4;b++){
       if(gameBoard[a][b]==gameBoard[a-1][b+1]&&gameBoard[a-1][b+1]==gameBoard[a-2][b+2]&&gameBoard[a-2][b+2]==gameBoard[a-3][b+3]){
          if(gameBoard[a][b]==CIRCLE)
          return 88;
         if(gameBoard[a][b]==CROSS)
          return 99;
       }

     }
   }
 return 666;
 }



 /* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {

    // TODO : Complete this part
 int a,b,c=0;
 for(a=0;a<6;a++){
  for(b=0;b<5;b++){
 if(gameBoard[a][b]==0){
  c++;
 }
  }
 }
 if(c>=42)
 return 1;
 else
 return 0;
 }


 /* Determine the next move of the computer player.
   You are required to exactly follow the strategy mentioned in the project specification.
   Using other strategies will result in mark deduction. */

 // TODO : Write the placeMarkByComputerPlayer(...) function here
void placeMarkByHumanComputer(int gameBoard[6][7], int mark){
  //让电脑赢
  int STEP=7;
  for(int a=0;a<6;a++){
    for(int b=0;b<7;b++){
      if(gameBoard[a][b]==EMPTY){
        gameBoard[a][b]=CROSS;
        int KEYNUM=hasWinner(gameBoard);
        if(KEYNUM==99&&STEP>b){
          STEP=b;
        }
        gameBoard[a][b]=EMPTY;
      }
    }
  }
  if(STEP<7){
    int a,b;
 a=STEP;//a指列
 b=0;//b指行
 while(1){
  if(gameBoard[b][a]==EMPTY)
   break;
  else
   b++;
 }
 gameBoard[b][a]=mark;
 return;
  }
  //不让对手赢
  int step=7;
  for(int a=0;a<6;a++){
    for(int b=0;b<7;b++){
      if(gameBoard[a][b]==EMPTY){
        gameBoard[a][b]=CIRCLE;
        int KEYNUM=hasWinner(gameBoard);
        if(KEYNUM==88&&step>b){
          step=b;
        }
        gameBoard[a][b]=EMPTY;
      }
    }
  }
  if(step<7){
    int a,b;
 a=step;//a指列
 b=0;//b指行
 while(1){
  if(gameBoard[b][a]==EMPTY)
   break;
  else
   b++;
 }
 gameBoard[b][a]=mark;
 return;
  }
  //随便下
  int k=6,l=0;//k指列，l指行
  for(l=0;l<6;l++){
   k=6;
  for(k=6;k>=0;k--){
   if(gameBoard[l][k]==EMPTY){
      int a,b;
 a=k;//a指列
 b=0;//b指行
 while(1){
  if(gameBoard[b][a]==EMPTY)
   break;
  else
   b++;
 }
 gameBoard[b][a]=mark;
 return;
   }
 }}
 }

 /* The main function */
int main()
 {
    /* Local variables */
    int gameBoard[6][7];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameContinue;       // 1: The game continues   0: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameContinue = 1;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid
    printGameBoard(gameBoard);
    /* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
       are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
    //printGameBoard(gameBoard);
    //printf("Player 1's turn:\n");
    //placeMarkByHumanPlayer(gameBoard, CIRCLE);
    //printGameBoard(gameBoard);
    //printf("Player 2's turn:\n");
    //placeMarkByHumanPlayer(gameBoard, CROSS);
    //printGameBoard(gameBoard);

    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer player
       For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
       Hint: use a while loop */

    // TODO : Complete this part
    int KEYNUM=0,full=0;


    while(1){
      if(numOfHumanPlayers==1){
      printf("Player 1's turn:\n");
      placeMarkByHumanPlayer(gameBoard, CIRCLE);
      printGameBoard(gameBoard);
      KEYNUM=hasWinner(gameBoard);
    full=isFull(gameBoard);
    if(KEYNUM==88){
      printf("Congratulations! Player 1 wins!\n");
      break;
    }
    if(KEYNUM==99){
      printf("Computer wins!\n");
      break;
    }
    if(full==1)
    {printf("Draw game.\n");
     break;}
//电脑开始
      printf("Computer's turn:\n");
      placeMarkByHumanComputer(gameBoard, CROSS);
      printGameBoard(gameBoard);
      KEYNUM=hasWinner(gameBoard);
    full=isFull(gameBoard);
    if(KEYNUM==88){
      printf("Congratulations! Player 1 wins!\n");
      break;
    }
    if(KEYNUM==99){
      printf("Computer wins!\n");
      break;
    }
    if(full==1)
    {printf("Draw game.\n");
     break;}}


  else{
      printf("Player 1's turn:\n");
      placeMarkByHumanPlayer(gameBoard, CIRCLE);
      printGameBoard(gameBoard);
      KEYNUM=hasWinner(gameBoard);
    full=isFull(gameBoard);
    if(KEYNUM==88){
      printf("Congratulations! Player 1 wins!\n");
      break;
    }
    if(KEYNUM==99){
      printf("Congratulations! Player 2 wins!\n");
      break;
    }
    if(full==1)
    {printf("Draw game.\n");
     break;}

      printf("Player 2's turn:\n");
      placeMarkByHumanPlayer(gameBoard, CROSS);
      printGameBoard(gameBoard);
      KEYNUM=hasWinner(gameBoard);
    full=isFull(gameBoard);
    if(KEYNUM==88){
      printf("Congratulations! Player 1 wins!\n");
      break;
    }
    if(KEYNUM==99){
      printf("Congratulations! Player 2 wins!\n");
      break;
    }
    if(full==1)
    {printf("Draw game.\n");
     break;}

    }}


    return 0;
}

