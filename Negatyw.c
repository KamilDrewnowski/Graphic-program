FiltrUsredniajacy.c        
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
                                                                                                                                                                                                                                                                                                                                                                                 KonwercjaDoSzarosci.c                                                                               0000644 0035411 0001771 00000002032 13213465050 0016043 0                                                                                                    ustar 00kdrewnow                        ar2017                          0000555 0034306                                                                                                                                                                        int **obraz;	
int wymx,wymy,odcieni; /*wprowadzanie zmiennych obrazu*/
int konwertujDoSzarosci(){
	
	/* deklaracja talbicy pomocniczej */
	int **obrazPomocniczy;	
	/* deklaracja tablicy*/
	int wymPomocniczneY = wymy;
	int wymPomocniczneX = (wymx/3);
	int i, y, x; /*zmienna pomocnicza */

	obrazPomocniczy = malloc(wymPomocniczneY  * sizeof(*obrazPomocniczy));
	if ( obrazPomocniczy == NULL ) 
	{ 
		/* sprawdzamy czy pamięć została przydzielona */ 
		printf("Nie moge przydzielic pamieci!\n"); 
		return 0;
	} 
	for ( i = 0; i < wymPomocniczneY; i++ ) 
	{ 
		obrazPomocniczy[i] = malloc( wymPomocniczneX * sizeof(*obrazPomocniczy) ); 
		if ( obrazPomocniczy[i] == NULL ) 
		{ 
			/*  i sprawdzamy czy została przydzielona */ 
			printf("Nie moge przydzielic pamieci!\n");
			return 0;
		} 
	} 
  
	for (y=0;y<wymy;y++) { 
		for (x=0;x<wymx+2;x=x+3) {
			obrazPomocniczy[y][x/3] = (obraz[y][x] + obraz[y][x+1] + obraz[y][x+2])/3;		
		}
	}
    free(obraz);
	obraz = obrazPomocniczy;
	wymx= wymPomocniczneX;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
