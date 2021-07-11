#include <stdio.h>

char matrix[3][3];                // tic tac toe matrix
int flag = 0 ;                    // to check the availability of space
char check(void);                 // to check winner
void get_player_move1(void);      //  to record player 1 move
void get_player_move2(void);      // to record player 2 move
void disp_matrix(void);           // to display game status
int main(void)
{
  char done = '\a' ;        //  to check the winning status
  int i = 0 ;               // counter to 2D array
  int j = 0 ;               // counter to 2D array
  printf("\n\t\t\tTic Tac Toe Game\n\n");
  printf("\t\t\tPlayer 1 : X\n\t\t\tPlayer 2 : O\n");
  for(i = 0; i<3 ; i++)
  {
        for(j=0; j<3; j++)
        {
            matrix[i][j] =  ' ' ;  //matrix initialization
        }
  }
  disp_matrix();
  do
  {
    get_player_move1();
    disp_matrix();
    done = check();         // see if winner
    if(done == ' ')         // not winner
    {
        get_player_move2();
        if(flag == 0)
        {
          disp_matrix();  //space was available and move is done, displaying move
        }

        done = check(); // see if winner
    }
  } while(done == ' ' /*&& flag == 0*/);
  if(done == 'X')
  {
      printf("\nPlayer 1 won!\n");
  }
  else if(done == 'O')
  {
      printf("\nPlayer 2 won!\n");
  }
  else
  {
      printf("\nIt's tie!\n");
  }
  return 0;
}
void get_player_move2(void)
{
  int x = 0 ;
  int y = 0 ;
  int i = 0 ;
  int j = 0 ;
  for(i=0; i<3; i++)
  {
    for(j=0; j<3; j++)
    {
       if(matrix[i][j] == ' ')
        {
           flag = 0 ;  //space available
           i = 3 ;     // loop termination
           j = 3 ;
        }
        else
        {
            flag = 1 ;   // no space available
        }
     }
   }
   if(flag == 0)
   {
     printf("\nEnter X,Y coordinates for player 2 move: ");
     scanf("%d%*c%d", &x, &y);
     x--;
     y--;
     if(matrix[x][y]!= ' ')
     {
       printf("\nInvalid move, try again.\n");
       get_player_move2();
     }
    else
    {
      matrix[x][y] = 'O';
    }
  }
}
void get_player_move1(void)
{
    int x = 0 ;
    int y = 0 ;
    printf("\nEnter X,Y coordinates for Player 1 move: ");
    scanf("%d%*c%d", &x, &y);
    x--;
    y--;
    if(matrix[x][y]!= ' ')
    {
       printf("Invalid move, try again.\n");
       get_player_move1();
    }
    else
    {
      matrix[x][y] = 'X';
    }
}
void disp_matrix(void)
{
  int t = 0 ;
  for(t=0; t<3; t++)
    {
       printf(" %c | %c | %c ",matrix[t][0],matrix[t][1], matrix [t][2]);
       if(t!=2)
       {
           printf("\n---|---|---\n");
       }
  }
  printf("\n");
}
char check(void)
{
  int i = 0;
  for(i=0; i<3; i++)  /* check rows */
  {
    if(matrix[i][0]== matrix[i][1] && matrix[i][0]==matrix[i][2])
    {
      return matrix[i][0];
    }
  }
  for(i=0; i<3; i++)  /* check columns */
  {
    if(matrix[0][i]== matrix[1][i] && matrix[0][i]== matrix[2][i])
    {
        return matrix[0][i];
    }
  }
  /* test diagonals */
  if(matrix[0][0]== matrix[1][1] && matrix[1][1]== matrix[2][2])
  {
       return matrix[0][0];
  }

  if(matrix[0][2]== matrix[1][1] && matrix[1][1]== matrix[2][0])
  {
    return matrix[0][2];
  }
  return ' ';
}
