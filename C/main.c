#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void randommuf(int desk[3][3], int type )
{
	
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


}


int inputCoordinates(int desk[3][3], int type)
{
	int x = -1;
	int y = -1;

	int error_x = scanf("%d", &x);
	int error_y = scanf("%d", &y);
	if ( (error_x != 1) || (error_y != 1) )
	{
		printf("incorrect input\n");
		return 1;
	}

	if  ( ( x < 0) || ( y < 0) || ( x > 2)|| ( y  > 2) )
	{
		printf("error: out of bound! \n");
		return 1;
	}

	if (desk[x][y] != 0){
		printf("error: already exist! \n");
		return 1;
	}

	desk[x][y] = type;

 return 0;
}

void watchDesk(int desk[3][3])
{
	printf("------------------\n");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (desk[i][j] == 1)
			{
				printf("X ");
			} else 
			if (desk[i][j] == -1)
			{
				printf("O ");
			}
			else 
			{
				printf("- ");
			}
		}
		printf("\n");
	}
		printf("------------------\n");
}


int cheek_1(int desk[3][3])
{
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
	if (cheek_1(desk) != 0)
		return cheek_1(desk);

	if (cheek_2(desk) != 0)
		return cheek_2(desk);

	if (cheek_3(desk) != 0)
		return cheek_3(desk);
	return 0;
}

void smartPlay(int desk[3][3], int type, int difficult )
{
	
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
				randommuf(copyDesk, type_copy);
				moves ++;
				type_copy *= -1;
			
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

}
int main()
{
	srand(time(0));
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



	printf ( "выберите уровень сложности \n 1   2   3\n" );
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
		difficult = 100 * pow(10, h	);

	}
	printf("difficult: %d, %d \n", difficult, h);
	printf("vyberite storonu\n 1 - kerstiku; -1 - noliki\n");
	int user_type ;
	scanf ("%d", &user_type);
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
				printf("крестики выиграли\n ");
			}
			else if (super_check(desk) == -1)
			{
				printf("нолики выиграли\n ");
			} else{
			printf("ничья \n");
		}
			return 0;
		}
	}

	if (super_check(desk) == 1)
		printf("крестики выиграли\n ");
	if (super_check(desk) == -1)
		printf("нолики выиграли\n ");
	
}


