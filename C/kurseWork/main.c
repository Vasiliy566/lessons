#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


int RandomMove(int desk[3][3], int type )
{
  if (desk == NULL ) 
    return 1;
  int n = 0;
  int x[9];
  int y[9];
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {

      if (desk[i][j] == 0)
      {
        x[n]=i;
        y[n]=j;
        n++;
      }
    }
  }

  int r = (rand() % 10) % n; 

  desk[ x[r] ][ y[r] ] = type;

  return 0;
}


int inputCoordinates(int desk[3][3], int type)
{
  if (desk == NULL ) 
    return 1;

  int x = -1;
  int y = -1;

  int error_x = scanf("%d", &x);
  int error_y = scanf("%d", &y);
  if ( (error_x != 1) || (error_y != 1) )
  {
    return 2;
  }

  if  ( ( x < 0) || ( y < 0) || ( x > 2)|| ( y  > 2) )
  {
    return 3;
  }

  if (desk[x][y] != 0){ 
    return 4;
  }

  desk[x][y] = type;

 return 0;
}



int watchDesk(int desk[3][3])
{
  int err = 0;
  if (desk == NULL ) 
    return 1;
  
  err = printf("------------------\n");
  if ( err < 0)
    return 2;
  
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      if (desk[i][j] == 1)
      {
        err = printf("X ");
        if ( err < 0)
          return 3;
      } else 
      if (desk[i][j] == -1)
      {
        err = printf("O ");
        if ( err < 0)
          return 4;
      }
      else 
      {
        err = printf("- ");
        if (err < 0)
          return 5;
      }
    }
    err = printf("\n");
    if ( err < 0)
      return 6;
  }
  err = printf("------------------\n");
  if ( err < 0)
    return 7;
  return 0;
}


int cheek_1(int desk[3][3])
{
  if (desk == NULL ) 
    return 1;
  
  for (int i=0; i<3; i++)
  {
    if( (desk[0][i] == desk[1][i]) && (desk[0][i] == desk[2][i]))
    {
      return desk[0][i];
    }
  }
  return 0;
}
int cheek_2(int desk[3][3])
{
  if (desk == NULL ) 
    return 1;
  for (int i=0; i<3; i++)
  {
    if( (desk[i][0] == desk[i][1]) && (desk[i][0] == desk[i][2]))
    {
      return desk[i][0];
    }
  }
  return 0;
}

int cheek_3(int desk[3][3])
{
  if (desk == NULL ) 
    return 1;

  if( (desk[0][0] == desk[1][1]) && (desk[0][0] == desk[2][2]))
  {
    return desk[0][0];
  }
  if( (desk[0][2] == desk[1][1]) && (desk[0][2] == desk[2][0]))
  {
    return desk[2][0];
  }
  return 0;
}


int super_check(int desk[3][3])
{
  if (desk == NULL ) 
    return 1;
  if (cheek_1(desk) != 0)
    return cheek_1(desk);

  if (cheek_2(desk) != 0)
    return cheek_2(desk);

  if (cheek_3(desk) != 0)
    return cheek_3(desk);
  return 0;
}

int smartPlay(int desk[3][3], int type, int difficult )
{
  if (desk == NULL ) 
    return 1;
  if ( type * type != 1 )
    return 2;

  int n = 0;
  int x[9];
  int y[9];
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {

      if (desk[i][j] == 0)
      {
        x[n]=i;
        y[n]=j;
        n++;
      }
    }
  }

  int copyDesk[3][3];

  int results[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};


  for( int i = 0; i < n; i ++)
  {
    int result = 0;

    for(int j = 0; j < difficult; j ++)
    {
      int moves = 9 - n + 1;


      int type_copy = type;

      for(int z = 0; z < 3; z ++)
      {
        for(int k = 0; k < 3; k ++)
        {
          copyDesk[z][k] = desk[z][k];
        }
      }
      copyDesk[ x[i] ][ y[i] ] = type_copy;
      type_copy *= -1;

      while(super_check(copyDesk) == 0)
      {
        if (moves >= 9)
        {
          break;
        }
        if(RandomMove(copyDesk, type_copy) == 1){
          printf("Error, something went wrong with array\n");
          break;
        } else {
          moves ++;
          type_copy *= -1;
        } 
      }

      result +=  10 * type * super_check(copyDesk);
      if (super_check(copyDesk) == 0)
        result += 7;


    }
    results[i] = result;
  }

  int max = 0;
  for( int i = 0; i < n; i ++)
  {

    if (results[i] > results[max])
      max = i;
  }
  desk[ x[max] ][ y[max] ] = type;
  return 0;
}

int test(){

  int status = 0;
  int desk[3][3] =  { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
  int desk1[3][3] = { {-1,-1,-1}, {0,0,0}, {0, 0, 0} };
  int desk2[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };
  //assert(status(RandomMove(desk) != 0);
  // check not-winning position
  assert(cheek_1(desk) == 0);
  assert(cheek_2(desk) == 0);
  assert(cheek_3(desk) == 0);
  assert(super_check(desk) == 0);
  //check common wining of O(-1)
  assert(cheek_1(desk1) == 0);
  assert(cheek_2(desk1) == -1);
  assert(cheek_3(desk1) == 0);
  assert(super_check(desk1) == -1);
  // check diagonal win of X(1)
  assert(cheek_1(desk2) == 0);
  assert(cheek_2(desk2) == 0);
  assert(cheek_3(desk2) == 1);
  assert(super_check(desk2) == 1);

  return status;
   
}

int main()
{
  int mode = 1;
  if (mode == 1){
  printf("test status: %x \n", test());
  return 0;
  }
  srand(time(NULL));
  int desk[3][3];
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      desk[i][j] = 0;
    }
  }
  int type = 1;
  int moves = 0;
  int error = 0;
  int difficult = 100;



  int err = printf ( "choose difficulty level\n 1   2   3\n" );
  if ( err < 0)
    return 1;

  int h;
  scanf ("%d", &h);
  if ( h > 3 )
  {
    difficult = 10000;
  } else  
  if ( h < 1)
  {
    difficult = 100;

  }
  else 
  {
    difficult = 100 * pow(10, h );
  }
  err = printf("difficult: %d, %d \n", difficult, h);
  if ( err < 0)
    return 1;
  err = printf("vyberite storonu\n 1 - kerstiku; -1 - noliki\n");
  if ( err < 0)
      return 1;


  int user_type ;
  err = scanf ("%d", &user_type);
  if( err != 1)
    return 1;
    watchDesk(desk);
  while(super_check(desk) == 0){
    if(type == user_type)
    {
      error = inputCoordinates(desk, type);

      if(error == 0)
      {
        moves ++;
      } 
    } else {
      if (error == 0)
      {
      smartPlay(desk, type, difficult);

      moves ++;
      }
    }
    type *= -1;
    watchDesk(desk);

    if (moves >= 9)
    {
      if (super_check(desk) == 1)
      {
        err = printf("krestiki win\n ");
        if ( err < 0)
          return 1;
      }
      else if (super_check(desk) == -1)
      {
        err = printf("noliki win\n ");
        if ( err < 0)
          return 1;
      } else{
        err = printf("draw \n");
        if ( err < 0)
        return 1;
    }
      return 0;
    }
  }

  if (super_check(desk) == 1){
    err = printf("krestiki win\n ");
    if ( err < 0)
          return 1;
  }
  if (super_check(desk) == -1){
    err = printf("noliki win\n ");
    if ( err < 0)
          return 1;
  }

}
