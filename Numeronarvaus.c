#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

//Numeronarvauspeli jossa kone arpoo numeron 1-100 ja käyttäjä koittaa arvata tuon numeron vihjeiden perusteella.
void arvaus(void);


void arvaus(){
  //Austetaan muuttujat
        int N = 100; 
        int arvaus = 0;
        int vihje = 0;
        int i = 1;     
        int vihjeraw;
        //käytettään rand:ia random-luvun generointiin.
        time_t t;
        srand((unsigned) time(&t));
        int randomi = rand() % (N + 1);

 //Toiminnallisuus alkaa. Ohjelma vertaa käyttäjän antamaa lukua random lukuun ja ohjailee vihjeillä jatko arvauksia.
        do{
//Kysytään käyttäjältä luku ja talletaan se 'arvaus' - muuttujaan.
        printf("\nArvaa Numero 1-100 väliltä \n");
        scanf("%d",&arvaus);
//lasketaan arvauksen ja randomin ero ja talletetaan tuo vihje - muuttajaan joka pakotetaan positiiviseksi
        int vihjeraw = randomi - arvaus;
        vihje = abs(vihjeraw);
        
// määritellään vihjeet if -haaraksi sitä mukaa menikö arvaus yli vai ali. Annetaan vihje sitä mukaa paljonko 
//arvaus eroaa generoidusta satunnaisluvusta.
        if (arvaus > randomi)
    {
        switch (vihje)
        {
            case 16 ... 100:
            printf("\nMeni tosi paljo yli");
            break;
        case 10 ... 15:
            printf("\nMeni yli kymmenen yli");
            break;
        case 8 ... 9:
          printf("\nMeni noin kymmenen yli");
            break;
        case 4 ... 7:
          printf("\nvielä muutama yli");
            break;
        case 1 ... 3:
          printf("\nNyt on tosi lähellä..vielä vähän yli");
            break;
        default:
            break;
        }
    }
     else if (arvaus < randomi)
    {
        switch (vihje)
        {
             case 16 ... 100:
            printf("\nMeni tosi paljo alle");
            break;
        case 10 ... 15:
            printf("\nMeni yli kymmenen alle");
            break;
        case 8 ... 9:
          printf("\nMeni noin kymmenen alle");
            break;
        case 4 ... 7:
          printf("\nvielä muutama alle");
            break;
        case 1 ... 3:
          printf("\nNyt on tosi lähellä..vielä vähän ali");
            break;
        default:
            break;
        }
    }
    //Kun arvaus osuu.
    else if(randomi == arvaus){
        printf("oikein!!!Arvauksia kului %d",i);
    }
    //Lisätään kerta arvauksiin aina kun arvaus ei osu.
        i++;
        }while (randomi != arvaus);
}

int main(){
  //Kutsutaan arvaus - funktiota.
      arvaus();  
}