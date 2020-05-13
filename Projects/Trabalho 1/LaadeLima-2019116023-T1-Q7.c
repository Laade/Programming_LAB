// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Laade da Costa Lima Modesto
//  email: laade09@gmail.com
//  Matrícula: 2019116023
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################


#include <stdio.h>

int verificarVencedor(char vet[]);
void tela(char vet[]);

int main()
{
   int jogador = 1, i, num;
   char c, vet[10] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9' };

   do
   {
       tela(vet);
       jogador = (jogador % 2) ? 1 : 2;

       printf("Jogador %d, escolha uma posicao:  ", jogador);
       scanf("%d", &num);

       c = (jogador == 1) ? 'X' : 'O';

       if (vet[num] == num + '0')
           vet[num] = c;

       else
       {
           printf("Posicao invalida");
           jogador--;
           getch();
       }
       i =  verificarVencedor(vet);

       jogador++;
   }while (i == -1);

   tela(vet);

   if (i == 1)
       printf("  Jogador %d ganhou ", --jogador);

   getch();

   return 0;
}

int verificarVencedor(char vet[])
{
   if (vet[1] == vet[2] && vet[2] == vet[3])
       return 1;

   else if (vet[4] == vet[5] && vet[5] == vet[6])
       return 1;

   else if (vet[7] == vet[8] && vet[8] == vet[9])
       return 1;

   else if (vet[1] == vet[4] && vet[4] == vet[7])
       return 1;

   else if (vet[2] == vet[5] && vet[5] == vet[8])
       return 1;

   else if (vet[3] == vet[6] && vet[6] == vet[9])
       return 1;

   else if (vet[1] == vet[5] && vet[5] == vet[9])
       return 1;

   else if (vet[3] == vet[5] && vet[5] == vet[7])
       return 1;

   else if (vet[1] != '1' && vet[2] != '2' && vet[3] != '3' &&
       vet[4] != '4' && vet[5] != '5' && vet[6] != '6' && vet[7]
       != '7' && vet[8] != '8' && vet[9] != '9')

       return 0;
   else
       return  - 1;
}

void tela(char vet[])
{
   printf("\n\n*************\nJogo da Velha\n\n");
   printf("Jogador 1 [X]  -  Jogador 2 [O]\n\n\n");
   printf("  %c  |  %c  |  %c \n", vet[1], vet[2], vet[3]);
   printf("_____|_____|_____\n");
   printf("  %c  |  %c  |  %c \n", vet[4], vet[5], vet[6]);
   printf("_____|_____|_____\n");
   printf("  %c  |  %c  |  %c \n\n", vet[7], vet[8], vet[9]);
}
