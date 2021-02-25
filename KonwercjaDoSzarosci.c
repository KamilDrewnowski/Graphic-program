int **obraz;	
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
		/* sprawdzamy czy pamiec zostala przydzielona */ 
		printf("Nie moge przydzielic pamieci!\n"); 
		return 0;
	} 
	for ( i = 0; i < wymPomocniczneY; i++ ) 
	{ 
		obrazPomocniczy[i] = malloc( wymPomocniczneX * sizeof(*obrazPomocniczy) ); 
		if ( obrazPomocniczy[i] == NULL ) 
		{ 
			/*  i sprawdzamy czy zostala przydzielona */ 
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
