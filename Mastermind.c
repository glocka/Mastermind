#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main()
{
  printf("-----Mastermind-----\n Farben:\n\033[31m1...ROT\033[0m\n\033[32m2...GRÜN\033[0m\n\033[33m3...GELB\033[0m\n\033[34m4...BLAU\033[0m\n\033[35m5...VIOLET\033[0m\n\033[36m6...TÜRKIS\033[0m\n\nO...Weder Farbe noch Position Korrekt\n\033[47m*\033[0m...Farbe korrekt, Position falsch\n\033[40m*\033[0m...Farbe korrekt, Position Korrekt\n\n");
  
  int spielfeld [12][8];
  char losung[4];
  int rated[4];
  int sol[4];
  //char answer ;
  int i;
  int k;
  int l;
  int buf;
  int pos;
  int j;
  for (i=0;i<4;i++)
  {
    srand ( clock() * i );
    losung[i] =(rand() % 6)+1;
  }
  /*printf("ANTWORT:");
  for (i=0;i<4;i++)
  {
    printf("%d ",losung[i]);
  }*/
  
  for(i = 0; i < 12; i++)
  {
    for(k =0; k < 8; k++)
    {
      spielfeld [i][k] = 0;
    }
  }
  
  
  printf("The Game is ready. Lets play!\n\n");
  
  for(j = 0; j < 12;j++)
  {
    printf("\033[31m1...ROT\033[0m \033[32m2...GRÜN \033[0m\033[33m3...GELB \033[0m\033[34m4...BLAU \033[0m\033[35m5...VIOLET \033[0m\033[36m6...TÜRKIS\033[0m\n");
    for (i=0;i<4;i++)
    {
      printf("Your guese for Position %d:",i+1);
      scanf ("%d",&spielfeld [j][i]);
      if(spielfeld [j][i] < 1 || spielfeld [j][i]>6)
      {
        printf("You enterd a non-valide Number. Please reenter a  valide Number\n");
        i--;
        continue;
      }
    }
    
    
    /*printf("\nYour guese: %d %d %d %d\nIs that correct (Y/N)?\n",spielfeld [j][0],spielfeld [j][1],spielfeld [j][2],spielfeld [j][3]);
    while ((answer = getchar()) != '\n')
    {
      if (answer =='Y' ||answer =='y')
      {
        break;
      }
      else
      {
        printf("You can reenter a new guese\n");
        i = 0;
        continue;
      }
    }*/
    
    
    
    rated [0] = 0;
    rated [1] = 0;
    rated [2] = 0;
    rated [3] = 0;
    
    sol [0] = 0;
    sol [1] = 0;
    sol [2] = 0;
    sol [3] = 0;
    
    pos = 4;
    for(i = 0; i < 4; i++)
    {
      if (spielfeld [j][i] == losung[i] )
      {
        spielfeld [j][pos] = 2;
        pos++;
        rated [i] = 1;
        sol [i] = 1;
        continue;
      }
    }
    
    for(i = 0; i < 4; i++)
    {
      if(rated[i] ==1)
      {
        continue;
      }
      
      for(k =0; k < 4; k++)
      { 
      if(sol[k] ==1)
      {
        continue;
      }
        if (spielfeld [j][i] == losung[k])
        {
          spielfeld [j][pos] = 1;
          pos++;
          rated [i] = 1;
          sol [k] = 1;
          break;
        }
      }
    }
    


    
  /*for (i=4;i<8;i++)
  {
    
  }*/
    
    
    for(i = 11; i >= 0; i--)
    {
      for(k =0; k < 8; k++)
      {
        if (k <=3)
        {
          switch(spielfeld [i][k]) 
          {
            case 1: printf("\033[31m1\033[0m "); break;
            case 2: printf("\033[32m2\033[0m "); break;
            case 3: printf("\033[33m3\033[0m "); break;
            case 4: printf("\033[34m4\033[0m "); break;
            case 5: printf("\033[35m5\033[0m "); break;
            case 6: printf("\033[36m6\033[0m "); break;
            default: printf("O "); break;
          }
        }
        if (k >3)
        {
          switch(spielfeld [i][k]) 
          {
            case 0: printf("  "); break;
            case 1: printf("\033[47m*\033[0m "); break;
            case 2: printf("\033[40m*\033[0m "); break;
          }
        }
        
        if (k ==3)
        {
          printf("|| ");
        }
      }
      printf("\n");
    }
    printf("\033[0m\n\nO...Weder Farbe noch Position Korrekt\n\033[47m*\033[0m...Farbe korrekt, Position falsch\n\033[40m*\033[0m...Farbe korrekt, Position Korrekt\n\n");
    
    if(spielfeld [j][4] == 2 && spielfeld [j][5] == 2 && spielfeld [j][6] == 2 && spielfeld [j][7] == 2)
    {
      printf("!!!CONGRATULATION!!!\n You won the game!\n");
      return 0;
    }
  
  
  }
  
  printf("You Lose\nAnswer:");
  for (i=0;i<4;i++)
  {
    printf("%d ",losung[i]);
  }
  printf("\n");
  return 0;


}
