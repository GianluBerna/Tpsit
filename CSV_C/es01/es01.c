/*Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui può essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.

Bernardi Gianluca 4AROB
es01
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DIM 1000
#define G 17000

typedef struct videogame{
    int rank;
    char* name;         //dichiarazione di un puntatore a grandezza da definire
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float na_sales;
    float eu_sales;
    float jp_sales;
    float other_sales;
    float global_sales;


}Videogame;

void loadTable(Videogame gl[], int n, int *max, int x){
    FILE *fp;
    int k=0;
    char appg[x];
    char riga1[x];
    char* buffer;

    fp=fopen("vgsales.csv", "r");
    fgets(riga1, x, fp);
    printf("%s\n", riga1);

    if(fp!=NULL){
        while(k<n && fgets(appg, x, fp)!=NULL){
           buffer =strtok(appg , ",");              //divisione della stringa grande in pezzi più piccoli
            gl[k].rank = atoi(buffer);              //atoi : trasforma la stringa in un intero
            buffer=strtok(NULL, ",");
            gl[k].name = malloc((strlen(buffer)+1)*sizeof(char));       //malloc : alloca la memoria del puntatore inserito 
                                                                        //strlen : lunghezza della stringa
                                                                        //sizeof : lunghezza del tipo di variabile
            strcpy(gl[k].name , buffer);
            buffer=strtok(NULL, ",");
            gl[k].platform = malloc((strlen(buffer)+1)*sizeof(char));
            strcpy(gl[k].platform , buffer);
            buffer=strtok(NULL, ",");
            gl[k].year = atoi(buffer);
            buffer=strtok(NULL, ",");
            gl[k].genre= malloc((strlen(buffer)+1)*sizeof(char));
            strcpy(gl[k].genre , buffer);
            buffer=strtok(NULL, ",");
            gl[k].publisher = malloc((strlen(buffer)+1)*sizeof(char));
            strcpy(gl[k].publisher , buffer);
            buffer=strtok(NULL, ",");
            gl[k].na_sales = atof(buffer);          //atof : trasforma la stringa in un float
            buffer=strtok(NULL, ",");
            gl[k].eu_sales = atof(buffer);
            buffer=strtok(NULL, ",");
            gl[k].jp_sales = atof(buffer);
            buffer=strtok(NULL, ",");
            gl[k].other_sales = atof(buffer);
            buffer=strtok(NULL, ",");
            gl[k].global_sales = atof(buffer);

        k++;
        }
    }
    else{
        printf("Il file non esiste");

        }
        *max=k;

    for(k=0;k<*max;k++){
        printf("%d %s %s %d %s %s %.2f %.2f %.2f %.2f %.2f\n", gl[k].rank, gl[k].name, gl[k].platform, gl[k].year, gl[k].genre, gl[k].publisher, gl[k].na_sales, gl[k].eu_sales, gl[k].jp_sales, gl[k].other_sales, gl[k].global_sales);
    }
    fclose(fp);
}

int main(){

    Videogame gameList[G];
    int n;
    loadTable(gameList, G , &n, DIM);

    return 0;
}
