#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
// Ohjelman sisäisten funktioiden esittely
void lottoKone(void);
//muuttujat
int omatNumerot[7];
int arvotutNumerot[7];
int i1;
int i2;

// Pääfunktion toteutus
int main() {
//alustetaan rand()
   time_t t;
   srand(time(NULL));

//Funktio kutsu
   lottoKone();
}

//Lotto funktio
void lottoKone(void) {
//Annetaan omia numeroita kunnes 7 on annettu, talletetaa omatnumerot arrayhin
  for (int i1 = 0; i1 < 7; i1++)
  {
    printf("\nAnna numero 1-40 välillä (%d) : ", i1 + 1);
    scanf("%d", &omatNumerot[i1]);
  }
  printf("\nOnnea Arvontaan!\n\n");
  
//arvotaan 7 numeroa väliltä 1-40 ja talletaan arvotutnumerot arrayhin.
  for (int i2 = 0; i2 < 7; i2++)
  {
    arvotutNumerot[i2] = rand() % (40 + 2 - 2) + 1;
  }

//Sortataaan molemmat rivit ja tulostetaan ne.
//Omat numerot
   int temp, i, j, k;
   for (j = 0; j < 7; ++j)
   {
      for (k = j + 1; k < 7; ++k)
      {
         if (omatNumerot[j] > omatNumerot[k])
         {
            temp = omatNumerot[j];
            omatNumerot[j] = omatNumerot[k];
            omatNumerot[k] = temp;
         }
      }
   }
   printf("Oma rivi :   ");
   for (i = 0; i < 7; ++i)
      printf("%d ", omatNumerot[i]);

//Arvotut numerot
 int temp1, i3, j1, k1;
   for (j1 = 0; j1 < 7; ++j1)
   {
      for (k1 = j1 + 1; k1 < 7; ++k1)
      {
         if (arvotutNumerot[j1] > arvotutNumerot[k1])
         {
            temp1 = arvotutNumerot[j1];
            arvotutNumerot[j1] = arvotutNumerot[k1];
            arvotutNumerot[k1] = temp1;
         }
      }
   } 
//tulostetaan 'oikea' rivi.
  printf("\nOikea rivi : ");
  for(i3 = 0; i3 < 7; ++i3){
   printf("%d ", arvotutNumerot[i3]);
   }
// Vertaillaan rivit ja kerrotaan montako oikein.
int i4, ii, count=0;
    for (i4=0;i4<7;i4++) for (ii=0;ii<7;ii++) 
        if (omatNumerot[i4]==arvotutNumerot[ii]) count++;
    printf("\n%d oikein!\n",count);

//Tekstit eri tuloksille.
switch (count)
{
case 0:
   printf("Harmi, ei yhtään oikein.");
   break;
case 1:
   printf("No edes yksi.");
   break;
case 2:
   printf("Kaksi on parempi kuin ei yhtään....");
   break;
case 3:
   printf("Ei tuolla vielä rahoiksi lyödä");
   break;
case 4:
   printf("Vähän taskurahaa");
   break;
case 5:
   printf("Oltermannia pirkan sijaan...");
   break;
case 6:
   printf("Äkkilähtöjä katteleen");
   break;
case 7:
   printf("Täyspotti -> soitto pomolle.");
   break;

default:
   break;
}
 return;
} 


