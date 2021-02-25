#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Negatyw.c"
#include"FiltrUsredniajacy.c"
#include"KonwercjaDoSzarosci.c"

#define DL_LINII 1024      /*bufor pomocniczy do czytania naglowka i komentarzy*/

/*wprowadzanie zmiennych obrazu*/
  int **obraz;	
  int wymx,wymy,odcieni;
  int p2 = 0;
  int p3 = 0;
  
int czytaj(FILE *plik_we) {
  char buf[DL_LINII];      /*bufor pomocniczy do czytania naglowka i komentarzy*/
  int znak;                /*zmienna pomocnicza do czytania komentarzy*/
  int koniec=0;            /*czy napotkano koniec danych w pliku*/
  int i,j;
  int numerOpcji; /*Mo¿liwe opcje programu*/
  char nazwa_zapisu[50]; /*pod jaka nazwa zapisac plik wyjsciowy*/

  
  /*Sprawdzenie czy podano prawid³owy uchwyt pliku */
  if (plik_we==NULL) {
    fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
    return(0);
  }
  
  /* Sprawdzenie numeru z pierwszej lini */
  if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Wczytanie pierwszej linii pliku do bufora */
    koniec=1;                              /* Nie udalo sie? Koniec danych! */

  if (koniec) { 
    fprintf(stderr,"Blad: To nie jest plik PGM ani PPM\n");
    return(0);
  }
  
  if((buf[0]=='P') && (buf[1]=='2')){
	  p2 = 1;
  }else{
	  if((buf[0]=='P') && (buf[1]=='3')){
		p3 = 1;
	}else{
		fprintf(stderr,"Blad: To nie jest plik PGM ani PPM\n");
		return(0);
	}
  }	
  
  
  
  /* Pominiecie komentarzy */
  do {
    if ((znak=fgetc(plik_we))=='#') {         /* Czy linia rozpoczyna sie od znaku '#'? */
      if (fgets(buf,DL_LINII,plik_we)==NULL)  /* Przeczytaj ja do bufora                */
	koniec=1;                   /* Zapamietaj ewentualny koniec danych */
    }  else {
      ungetc(znak,plik_we);                   /* Gdy przeczytany znak z poczatku linii */
    }                                         /* nie jest '#' zwroc go                 */
  } while (znak=='#' && !koniec);   /* Powtarzaj dopoki sa linie komentarza */
                                    /* i nie nastapil koniec danych         */


  /* Pobranie wymiarow obrazu i liczby odcieni */
  if (fscanf(plik_we,"%d %d %d",&wymx,&wymy,&odcieni)!=3) {
    fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni odcieni\n");
    return(0);
  }

  
  /* deklaracja tablicy*/
  if (p3== 1){
	  wymx = wymx*3;
  }
  obraz = malloc(wymy  * sizeof(*obraz));
  if ( obraz == NULL ) 
    { 
        /* sprawdzamy czy pamiêæ zosta³a przydzielona */ 
        printf("Nie moge przydzielic pamieci!\n"); 
		return 0;
    } 
	for ( i = 0; i < wymy; i++ ) 
    { 
        obraz[i] = malloc( wymx * sizeof(*obraz) ); 
        if ( obraz[i] == NULL ) 
        { 
            /*  i sprawdzamy czy zosta³a przydzielona */ 
            printf("Nie moge przydzielic pamieci!\n");
            return 0;
        } 
    } 
  
  
  
  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
  for (i=0;i<wymy;i++) {
    for (j=0;j<wymx;j++) {
      if (fscanf(plik_we,"%d",&(obraz[i][j]))!=1) {
		fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
		return(0);
      }
    }
  }
  return wymx*wymy;   /* Czytanie zakonczone sukcesem    */
}                       /* Zwroc liczbe wczytanych pikseli */


/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(char *n_pliku) {
  char polecenie[DL_LINII];      /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie,"display ");  /* konstrukcja polecenia postaci */
  strcat(polecenie,n_pliku);     /* display "nazwa_pliku" &       */
  strcat(polecenie," &");
  printf("%s\n",polecenie);      /* wydruk kontrolny polecenia */
  system(polecenie);             /* wykonanie polecenia        */
}


/* Zapisywanie obrazu  */
int zapisz() {
	FILE *fp = NULL;
	char nazwa_zapisu[50];
	printf("Pod jaka nazwa zapisac plik\n");
	scanf("%s",nazwa_zapisu);
	fp = fopen(nazwa_zapisu, "wa"); /*Zapisywanie pliku o zadanej nazwie, badz go nadpisywanie jezeli istnieje taka nazwa*/
	int i,j;
	if(p2 == 1){
		fprintf(fp, "P2\n"); /*dodawanie informacji z otwieranego pliku na zapisywanym przez nas*/
	}else{
		if(p3 == 1){	
			fprintf(fp, "P3\n"); /*dodawanie informacji z otwieranego pliku na zapisywanym przez nas*/
		}else{
			printf("B³¹d asercji- niew³aœciwy format obrazka podczas zapisu\n");
			return(0);
		}
	}	
	if(p3 == 1){	
		fprintf(fp, "%d %d\n", wymx/3, wymy);
	}else{
		fprintf(fp, "%d %d\n", wymx, wymy);
	}
	fprintf(fp, "%d\n", odcieni);
	
	for (i=0;i<wymy;i++) { /*wzor matematyczny na przedstawienie obrazu w postaci negatywu*/
		for (j=0;j<wymx;j++) {
			fprintf(fp, "%d ", obraz[i][j]);
		}
	}
  	fclose(fp);
	printf("Utworzono plik \n");
	return(1);
}

	
int main() {

  int i, j;  /*zmienne pomocnicze */
  int odczytano = 0;
  FILE *plik;
  char nazwa[100];  /*nazwa pliku jako komentarz*/
  char nazwaDisplay [100]; /*nazwa pliku do wyswietlenia za pomoca Display*/
  int numerOpcji; /*mo¿liwe opcje programu*/
  char nazwa_zapisu[50]; /*pod jaka nazwa zapisac plik wyjsciowy*/

  /* Wczytanie zawartosci wskazanego pliku do pamieci */
  printf("Podaj nazwe pliku:\n");
  scanf("%s",nazwa);
  		printf("\n odczytuje plik\n");
  plik=fopen(nazwa,"r");

  if (plik != NULL) {       
      odczytano = czytaj(plik);
	  if(odczytano == NULL){
		  printf("Blad asercji: procedura odczytu\n");  /*Asercja odczytu*/
	  }else{
      fclose(plik);
	  }
  }
  
	do{   /*Uruchamianie menu programu*/
		printf("Prosze wybrac opcje programu graficznego poprzez wpisanie:\n");
		printf("1 - aby utworzyc negatyw\n");
		printf("2 - aby wlaczyc filtr usredniajacy\n");
		printf("3 - aby przekonwertowac obraz ppm do formatu pgm\n");
		printf("4 - aby zapisac\n");
		printf("5 - aby wyswietlic obraz za pomoca display\n");
		printf("6 - aby podac dane wczytanego obrazu\n");
		printf("7 - aby zamknac program\n");
		scanf("%d", &numerOpcji);
		
		
	 
		printf("wybrales opcja nr %d\n", numerOpcji);

		switch(numerOpcji){ /*segmentowanie wyboru uzytkownika*/

			case 1:	/*Tworzenie negatywu pliku*/
			negatyw(); 
			printf("Negatyw obrazu zostal wykonany\n");
			break;
			
			
			case 2:	/*Przetwarzanie punktowe obrazu*/
			if(p2==1){
				filtrUsredniajacy(); 
				printf("Filtr usredniajacy zostal wykonany\n");
			}else{
				if(p3==1){
					printf("Filtr usredniajacy mozliwy jest tylko dla obrazow PGM\n");
				}else{
					printf("B³ad asercji - niewlasciwy typ obrazu\n");
				}
			}
			break;
			
			
			case 3: /*Konwercja do szarosci*/
			if(p3==1){
				konwertujDoSzarosci();
				p2=1;
				p3=0;
				
				printf("Konwersja do szarosci zostala wykonana\n");
			}else{
				if(p2==1){
					printf("Filtr usredniajacy mo¿liwy jest tylko dla obrazow PGM\n");
				}else{
					printf("Blad asercji - niewlasciwy typ obrazu\n");
				}
			}		
			break;


			case 4:  /* Zapisywanie do pliku */
			if (odczytano != 0)
			  zapisz();
			break;


			case 5: /*otwieranie zapisanego pliku za pomoca display*/
			printf("Podaj nazwe pliku ktory mam wyswietlic:\n");
			scanf("%s",nazwaDisplay);
			wyswietl(nazwaDisplay);
			break;
			
			case 6: /*podawanie danych obrazu*/
			printf("\n wymiary obrazu to:\n szerokosc %d\n wysokosc %d\n skala odcieni %d\n\n",wymx,wymy,odcieni);
			break;
			

			
			case 7: /*zamykanie programu*/
			free(obraz);
			printf("Zamykam program\n");
			return 0;
			break;
			
			
			
			default: /*Jezeli komenda jest niepoprawna*/
			printf("Prosze wpisac poprawna opcje\n");
			break;
		}
	}while(numerOpcji!=7); /*powtarza petle dopuki nie otrzyma komendy 4 konczacej program*/
 
  return odczytano;
}
