/*Algorytm dla filtru usredniajacego*/
int **obraz;	
int wymx,wymy,odcieni; /*wprowadzanie zmiennych obrazu*/
void filtrUsredniajacy() {
	int y,x;
	
	int przeksztalcenie[3][3]; 
	przeksztalcenie[0][0] =1;
	przeksztalcenie[0][1] =1;
	przeksztalcenie[0][2] =1;
	przeksztalcenie[1][0] =1;
	przeksztalcenie[1][1] =1;
	przeksztalcenie[1][2] =1;
	przeksztalcenie[2][0] =1;
	przeksztalcenie[2][1] =1;
	przeksztalcenie[2][2] =1;
	
	
	for (y=0;y<wymy;y++) { /*petla dla filtru usredniajacego*/
		for (x=0;x<wymx;x++) {
		
			
			if (y==0 && x ==0){   /*schemat dzialania dla punktu 0 x 0*/
				obraz[y][x]= 
				(obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y][x+1]*przeksztalcenie[1][2]+
				obraz[y+1][x]*przeksztalcenie[2][1]+
				obraz[y+1][x+1]*przeksztalcenie[2][2])/4;
			}
			
			if (y==0 && x >0 && x<(wymx-1)){   /*schemat dzialania dla punktu 1 x 0*/
				obraz[y][x]= 
				(
				obraz[y][x-1]*przeksztalcenie[1][0]+
				obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y][x+1]*przeksztalcenie[1][2]+
				obraz[y+1][x-1]*przeksztalcenie[2][0]+
				obraz[y+1][x]*przeksztalcenie[2][1]+
				obraz[y+1][x+1]*przeksztalcenie[2][2])/6;
			}
			
			if (y==0 && x==(wymx-1)){      /*schemat dzialania dla punktu 2 x 0*/
				obraz[y][x]= 
				(
				obraz[y][x-1]*przeksztalcenie[1][0]+
				obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y+1][x-1]*przeksztalcenie[2][0]+
				obraz[y+1][x]*przeksztalcenie[2][1])/4;
			}
			
			
			if (y>0 && y<(wymy-1) && x==0){   /*schemat dzialania dla punktu 0 x 1*/
				obraz[y][x]= 
				(
				obraz[y-1][x]*przeksztalcenie[0][1]+
				obraz[y-1][x+1]*przeksztalcenie[0][2]+
				obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y][x+1]*przeksztalcenie[1][2]+
				obraz[y+1][x]*przeksztalcenie[2][1]+
				obraz[y+1][x+1]*przeksztalcenie[2][2])/6;
			}
			
			if( y>0 && y<(wymy-1) && x>0 && x<(wymx-1)){   /*schemat dzialania dla punktu 1 x 1*/
			obraz[y][x]= 
				(
				obraz[y-1][x-1]*przeksztalcenie[0][0]+
				obraz[y-1][x]*przeksztalcenie[0][1]+
				obraz[y-1][x+1]*przeksztalcenie[0][2]+
				obraz[y][x-1]*przeksztalcenie[1][0]+
				obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y][x+1]*przeksztalcenie[1][2]+
				obraz[y+1][x-1]*przeksztalcenie[2][0]+
				obraz[y+1][x]*przeksztalcenie[2][1]+
				obraz[y+1][x+1]*przeksztalcenie[2][2])/9;
			}
			
			if (y>0 && y<(wymy-1) && x==(wymx-1)){  /*schemat dzialania dla punktu 2 x 1*/
				obraz[y][x]= 
				(
				obraz[y-1][x-1]*przeksztalcenie[0][0]+
				obraz[y-1][x]*przeksztalcenie[0][1]+
				obraz[y][x-1]*przeksztalcenie[1][0]+
				obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y+1][x-1]*przeksztalcenie[2][0]+
				obraz[y+1][x]*przeksztalcenie[2][1])/6;
			}
			
			
			
			if (y==(wymy-1) && x==0){       /*schemat dzialania dla punktu 0 x 2*/
				obraz[y][x]= 
				(
				obraz[y-1][x]*przeksztalcenie[0][1]+
				obraz[y-1][x+1]*przeksztalcenie[0][2]+
				obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y][x+1]*przeksztalcenie[1][2])/4;
				
			}
			
			
			if (y==(wymy-1) && x>0 && x<(wymx-1)){    /*schemat dzialania dla punktu 1 x 2*/
				obraz[y][x]= 
				(
				obraz[y][x-1]*przeksztalcenie[1][0]+
				obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y][x+1]*przeksztalcenie[1][2]+
				obraz[y-1][x-1]*przeksztalcenie[2][0]+
				obraz[y-1][x]*przeksztalcenie[2][1]+
				obraz[y-1][x+1]*przeksztalcenie[2][2])/6;
				
			}
			
			if (y==(wymy-1) && x==(wymx-1)){      /*schemat dzialania dla punktu 2 x 2*/
				obraz[y][x]= 
				(
				obraz[y][x-1]*przeksztalcenie[1][0]+
				obraz[y][x]*przeksztalcenie[1][1]+
				obraz[y-1][x-1]*przeksztalcenie[2][0]+
				obraz[y-1][x]*przeksztalcenie[2][1])/4;
								
				
			}
		}
	}
}
