
public class table{
    int size;
	int desc[][];
	int game_mod; // if mod = 1 X move, if mod = -1 O move
	table(int size_){
		size = size_;
		desc = new int [size] [size];
		game_mod = 1;
	}
	void show(){
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				System.out.print(desc[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}
	// TODO проверка на границы и на то, что клеточка уже заполнена
	void move(int x, int y) {
		desc[x][y] = game_mod; 
		game_mod = game_mod * -1;
	}
	
	public boolean checkWinner() {
	    return checkWinnerHorizontal() ||
	      checkWinnerVertical() ||
	      checkWinnerDiagonals();
	  }

	  private boolean checkWinnerHorizontal() {
	    for (int i = 0; i < size; i++) {
	      boolean res = true;
	      for (int j = 1; j < size && res; j++)
	        res = desc[i][j] == desc[i][0];
	      if (res)
	        return true;
	    }
	    return false;
	  }

	  private boolean checkWinnerVertical() {
	    for (int i = 0; i < size; i++) {
	      boolean res = true;
	      for (int j = 1; j < size && res; j++)
	        res = desc[j][i] == desc[0][i];
	      if (res)
	        return true;
	    }
	    return false;
	  }

	  private boolean checkWinnerDiagonals() {
	    boolean res = true;
	    for (int i = 1; i < size && res; i++)
	      res = desc[i][i] == desc[0][0];
	    if (res)
	      return true;
	    res = true;
	    for (int i = 1; i < size && res; i++)
	      res = desc[size - i - 1][i] == desc[size - 1][0];
	    return res;
	  }
	
	
}
