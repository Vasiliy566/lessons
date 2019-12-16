#include <stdio.h>
#include <stdlib.h>




void randommuf(int desk[3][3], int type ){
	// найдем свободные клетки и запишем их координаты в массивы Х и У
	int n = 0;
	int x[9];
	int y[9];
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){

			if (desk[i][j] == 0){
				x[n]=i;
				y[n]=j;
				n++;
			}
		}
	}
	//  нашли свободные клетки
	// выберем случайную пустую клетку
	

	int r = (rand() % 10) % n; // !!! Костыль, в macOS %7 возвращает одно и то же !!!

	desk[ x[r] ][ y[r] ] = type;// делаем случайный ход


}


int inputCoordinates(int desk[3][3], int type){
	int x = -1;
	int y = -1;

	int error_x = scanf("%d", &x);
	int error_y = scanf("%d", &y);
	if ( (error_x != 1) || (error_y != 1) ){
		printf("incorrect input\n");
		return 1;
	}

	if  ( ( x < 0) || ( y < 0) || ( x > 2)|| ( y  > 2) ){
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

void watchDesk(int desk[3][3]){
	printf("------------------\n");
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (desk[i][j] == 1){
				printf("X ");
			} else 
			if (desk[i][j] == -1){
				printf("O ");
			}else {
				printf("- ");
			}
		}
		printf("\n");
	}
		printf("------------------\n");
}


int cheek_1(int desk[3][3]){
	for (int i=0; i<3; i++){
		if( (desk[0][i] == desk[1][i]) && (desk[0][i] == desk[2][i])){
			return desk[0][i];
		}
	}
	return 0;
}
int cheek_2(int desk[3][3]){
	for (int i=0; i<3; i++){
		if( (desk[i][0] == desk[i][1]) && (desk[i][0] == desk[i][2])){
			return desk[i][0];
		}
	}
	return 0;
}

int cheek_3(int desk[3][3]){
	
	if( (desk[0][0] == desk[1][1]) && (desk[0][0] == desk[2][2])){
		return desk[0][0];
	}
	if( (desk[0][2] == desk[1][1]) && (desk[0][2] == desk[2][0])){
		return desk[2][0];
	}
	return 0;
}

int super_check(int desk[3][3]){
	if (cheek_1(desk) != 0)
		return cheek_1(desk);

	if (cheek_2(desk) != 0)
		return cheek_2(desk);

	if (cheek_3(desk) != 0)
		return cheek_3(desk);
	return 0;
}

void smartPlay(int desk[3][3], int type ){
	// найдем свободные клетки и запишем их координаты в массивы Х и У
	
	int n = 0;
	int x[9];
	int y[9];
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){

			if (desk[i][j] == 0){
				x[n]=i;
				y[n]=j;
				n++;
			}
		}
	}

	int copyDesk[3][3];

	int results[n];
	for( int i = 0; i < n; i ++)
	{
		results[i] = 0;
	}
	

	for( int i = 0; i < n; i ++)
	{
		int result = 0;
		
		for(int j = 0; j < 10; j ++){
			int moves = 9 - n + 1;
			//sleep(1);
			
			int type_copy = type;
			// make copy of desk
			for(int z = 0; z < 3; z ++){
				for(int k = 0; k < 3; k ++){
					copyDesk[z][k] = desk[z][k];
				}
			}
			copyDesk[ x[i] ][ y[i] ] = type_copy;

			
			while(super_check(copyDesk) == 0){
				if (moves >= 9){
					break;
				}
				randommuf(copyDesk, type_copy);
				moves ++;
				type_copy *= -1;
			
			}
		
			watchDesk(copyDesk);
			result += -1 * super_check(copyDesk);
			printf("%d %d\n", -1 * super_check(copyDesk), moves);

		}
		results[i] = result;
	}

	int max = 0;
	for( int i = 0; i < n; i ++)
	{
		printf("move %d %d reting %d\n", x[i], y[i], results[i]);
		if (results[i] > results[max])
			max = i;
	}
	desk[ x[max] ][ y[max] ] = type;

}
int main()
{
	srand(time(0));
	int desk[3][3];
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			desk[i][j] = 0;
		}
	}
	int type = 1;
	int moves = 0;
	int error = 0;
	watchDesk(desk);
	while(super_check(desk) == 0){
		if(type == 1){
			 error = inputCoordinates(desk, type);
			if(error == 0){
				moves ++;
			} 
		} else {
			if (error == 0){
			smartPlay(desk, type);
			//randommuf(desk, type);
			moves ++;
			}
		}
		type *= -1;
		watchDesk(desk);
		
		if (moves >= 9){
			printf("ничья \n");
			return 0;
		}
	}

	if (super_check(desk) == 1)
		printf("крестики выиграли\n ");
	if (super_check(desk) == -1)
		printf("нолики выиграли\n ");
}


