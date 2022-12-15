#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//funzione che cerchera' l'elemento e memorizzera' la sua frequenza
int cercaElemento(int x, int v[], int lunghezza, int index[]) {
  int i, counter = 0;

  for (i = 0; i < lunghezza; i++) {
    //se trova l'elemento richiesto:
    if (x == v[i]) {
      //salva la sua posizione
      index[counter] = i;
      //memorizza la sua frequenza
      counter++;
    }
  }
   return counter;
  //la funzione ritornera' la frequenza
}


//crea un vettore di lunghezza x con valori compresi tra minval e maxval
void creaVettore(int v[], int lunghezza, int minVal, int maxVal) {
  int i;

  srand(time(NULL));

  for (i = 0; i < lunghezza; i++)
    // randomizza i valori del vettore da minval a maxval
    v[i] = rand() % (maxVal - minVal + 1) + minVal;
}

int main() {
  int lunghezza = 100, v[lunghezza], x, index[lunghezza], i, ricorrenza;


  // richiamo la funzione creaVettore
  creaVettore(v, lunghezza, 1, 100);


  //stampo il vettore randomizzato
  for (i = 0; i < lunghezza; i++) {
    if (i == 0)
      printf("[%d", v[0]);
    else if (i == lunghezza - 1)
      printf(" %d]\n\n", v[i]);
    else
      printf(" %d", v[i]);
  }
  printf("Inserisci il numero che vuoi cercare: ");
  scanf("%d", &x);


  // La funzione ritorna quante volte e' comparso il numero da cercare
  ricorrenza = cercaElemento(x, v, lunghezza, index);

  //stampa il risultato:
  if (ricorrenza == 0) {
    // if (ricorrenza == 0): L'elemento da cercare non compare nel vettore
    printf("\nL'elemento che voleva cercare non e' all'interno dell'array.");
  } else if (ricorrenza == 1) {
// if (ricorrenza == 1): L'elemento da cercare si trova una volta nel vettore
    printf("\nL'elemento che voleva cercare e' comparso 1 volta ");
    printf("e si trova nella seguente posizione dell'array: %d.", index[0]);
  } else {
    // L'elemento da cercare si trova diverse volte nel vettore
    printf("\nL'elemento compare %d volte ", ricorrenza);
    printf("e i numeri si trovano nelle posizioni dell'array:\n");
    for (i = 0; i < ricorrenza; i++)
      printf("%d\n", index[i]);
  }
  return 0;
}