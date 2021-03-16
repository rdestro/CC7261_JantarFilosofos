//
//  JantarFilosofos
//
//  Created by Ricardo de Carvalho Destro on 08/09/20.
//  Copyright © 2020 Ricardo de Carvalho Destro. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define Filosofos 5


int Filosofo[Filosofos]; //numero do filosofo
pthread_cond_t condicao[Filosofos];


void *threadFilosofo(void *arg);

int main(int argc, char *argv[])
{
  /* Setup */
  pthread_t ph_thread[Filosofos];


  for (int i = 0; i < Filosofos; i++) {
    pthread_cond_init(&condicao[i], NULL);
    Filosofo[i] = i;
  }

  
  for (int i = 0; i < Filosofos; i++) {
    printf("%4d - Filosofo #%d sentou na mesa.\n",i, i + 1);
    pthread_create(&ph_thread[i], NULL, threadFilosofo, &Filosofo[i]);
    sleep(0);
  }
  for (int i = 0; i < Filosofos; i++)
    pthread_join(ph_thread[i], NULL);

  /* Cleanup */

  for (int i = 0; i < Filosofos; i++)
    pthread_cond_destroy(&condicao[i]);
  return(0);
}


void *threadFilosofo(void *arg)
{//função do filósofo... pensar e comer
  int *filosofo = arg;
  while(1) {
      //tempo pensando (sleep)
      //loop tenta pegar garfo Direita
      //loop tenta pegar garfo esquerda
      //tempo pensando (sleep)
      //tempo comendo
      //devolde garfos
  }
}
