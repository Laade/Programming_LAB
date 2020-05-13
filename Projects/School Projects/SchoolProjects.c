#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

#define Aluno_MAX 2
#define Professores_MAX 2
#define Disciplinas_MAX 2
#define Matriculados_MAX 2

typedef struct {
	int dia;
	int mes;
	int ano;	
}data;

typedef struct {
	int matricula;
	char nome[50];
	char sexo;
	char dataNascimento;
	char cpf;
} Alunos;

typedef struct {
	int matricula;
	char nome[50];
	char sexo;
	char dataNascimento;
	char cpf;
} Professor;

typedef struct {
	int Codigo;
	char nome[50];
	Professor prof;
	int semestre;
} Disciplina; 

Alunos aluno[Aluno_MAX];
Professor professores[Professores_MAX];
Disciplina Disciplinas[Disciplinas_MAX];

void Menu();
void validarNome();
void validarSexo();
int validarDataNasc();
int validarCpf();
void CadastroAlunos();
void CadastroProfessores();
void CadastroDisciplinas();

void Relatorios();
void listar_alunos();
void listar_professor();
void listar_disciplina();
void remover_alunos();
void remover_professor();
void remover_disciplina();
void listar_aluno_alfabetica();


int main (int argc, char *argv[]){

	Menu();

return 0;	
}
void Menu(){
	
	//system("pause");
	
	setlocale(LC_ALL, "Portuguese");
	
	int contador = 0;
	
	int opcao;
	int cadastro=0;
	int cadastroAluno=1;
	int cadastroProfessor=2;
	int retorno=0;
	
	//static int linha;
	do {
		system("cls");

	     	printf("|\n-----------------   CADASTRO DE PESSOAS   -------------------|");
			printf("|\n-------------------   Menu Principal   ----------------------|");
			printf("|\n1 - Cadastrar Aluno                                          |");
			printf("|\n2 - Cadastrar Professor                                      |");
			printf("|\n3 - Cadastrar Disciplina                                     |");
			printf("|\n4 - Relatórios                                                   |");
			printf("|\n5 - Excluir                                                  |");
			printf("|\n0 - Sair          											|");			
		
		printf("\n\nEscolha uma Opcao: ");
		scanf("%d", &opcao);
		getchar();
		
	
	switch (opcao)	
	{
		case 1: if(opcao==cadastroAluno)	{		
			if(opcao==cadastroAluno){
			scanf("%d", &cadastroAluno);
				do{
					CadastroAlunos();
					}
					while(opcao == 1);
					break;
		}
		case 2: if (opcao==cadastroProfessor){
				scanf("%d", &cadastroProfessor);
				do{
					CadastroProfessores();
 					}
 					while (opcao == 2);
 					break;
 		}
 		case 3: {
 			
 			CadastroDisciplinas();
 		break;	
		}
		case 4:{
			
			Relatorios();
		break;
		case 5:
			do{
				system("cls");
				printf("\n1 - Excluir Alunos ");
				printf("\n2 - Excluir Professor ");
				printf("\n3 - Excluir Disciplina ");
				
				printf("\n\nEscolha uma Opcao: ");
				scanf("%d", &opcao);
				getchar;
				if(opcao==1){
						remover_alunos();
				}
				else if(opcao==2){
						remover_professor();
				}
				else if(opcao==3){
						remover_disciplina();
				}
			} while (opcao!=0 && opcao<=3);
	}
}	//while (opcao!=0);
}
}while (opcao!=0);
}

void CadastroAlunos() {
	
	char opcao;
	int i;
/*	int contador=0;
	int qtd=0;
	int cadastros=0;
	
	system("cls");	
	printf("Quantos funcionarios deseja cadastrar: ");
	scanf("%d", &qtd);
	getchar();
	if(qtd > 5 || qtd == 0)
	{
		printf("\n\n");
		printf("A quantidade deve estar entre 1 e 5. ");
		printf("\n\n");
		system("pause > NULL");
		CadastroAlunos();
	}
	else 
	{
		cadastros=qtd-1;
		printf("\n\n");
		
		for(contador=0; contador<qtd; contador++)
		{*/
		//	printf("Cadastrar o aluno %d:", ontador+1);
		
		//Armazenando os dados do cadastro dentro da struct cad_cliente
		for(i=0; i<Aluno_MAX; i++){
		
		//	do{	printf("\n\n");
				system("cls");	
			printf("\n\n -------- Cadastro dos Alunos --------\n\n ");
			
			printf("Informe a matricula do aluno: ");
			scanf("%d", &aluno[i].matricula);
		//	scanf("%d", &matricula);
			printf("\nDigite o nome do aluno: ");
			fflush(stdin);
			gets(aluno[i].nome);
			validarNome();
			printf("\nInforme o sexo do aluno (F - Feminino M - Masculino): ");
			fflush(stdin);//	gets(aluno[Aluno_MAX].sexo);
			scanf("%s", &aluno[i].sexo);
			validarSexo();
			fflush(stdin);
			validarDataNasc();
			fflush(stdin);
			validarCpf();
			
			getchar();
	//	}while (opcao!=0);
	}
	printf("Cadastro realizado com sucesso! Deseja voltar ao menu? (s/n)");
	scanf("%c", &opcao);
	getchar();
	
	if (opcao=='s')
	{
		Menu();
	} else {
		printf("\n\n");
		printf("Seu programa pode ser fechado");
	}
}

void CadastroProfessores(){
	
	int matricula[50];
	char nome[50];
	char sexo;
	char DataNasc;
	char cpf[15];
	
	int opcao;
	
	for (int i=0; i<Professores_MAX; i++){
		system("cls");	
		printf("\n\n -------- Cadastro dos Professores --------\n\n ");
	printf("\nInforme o numero de matricula do professor ");
	scanf("%d", &professores[i].matricula);
	printf("\nDigite o nome do Professor: ");
	fflush(stdin);
	gets(professores[i].nome);
	validarNome();
	printf("\nInforme o sexo do professor (F - Feminino M - Masculino): ");
	validarSexo();
	
	validarDataNasc();
	
	validarCpf();

	getch();
}
	printf("Cadastro realizado com sucesso! Deseja voltar ao menu? (s/n)");
	scanf("%c", &opcao);
	getchar();
	
	if (opcao=='s')
	{
		Menu();
	} else {
		printf("\n\n");
		printf("Seu programa pode ser fechado");
	}
	

}

void CadastroDisciplinas(){
	int opcao;
	Disciplina disc;
/*	int codigo;
	char nome[50];
	char professor[50];
	int semestre;
	*/
	
	//Armazenando no vetor de struct
	for(int i=0; i < Disciplinas_MAX; i++){
		
		system("cls");	
		printf("\n\n -------- Cadastro das Disciplinas --------\n\n ");
		printf("\nInforme o codigo da disciplina que deseja cadastrar ");
		scanf("%d", &Disciplinas[i].Codigo);
		printf("\nDigite o nome da disciplina para cadastrar: ");
		fflush(stdin);
		gets(Disciplinas[i].nome);
		validarNome();
		printf("\nDigite o nome do professor da disciplina: ");
		fflush(stdin);
		gets(Disciplinas[i].prof.nome);
		validarNome();
		printf("\nInforme o semestre: ");
		scanf("%d", &Disciplinas[i].semestre);
	}
	printf("Cadastro realizado com sucesso! Deseja voltar ao menu? (s/n)");
	scanf("%c", &opcao);
	getchar();
	
	if (opcao=='s')
	{
		Menu();
	} else {
		printf("\n\n");
		printf("Seu programa pode ser fechado");
	}
}

void Relatorios(){
	
	int opcao;
	int retorno=0;
	
	do {
	system("cls");
		printf("\n1 - Listar Alunos" );
		printf("\n2 - Listar Professores" );
		printf("\n3 - Listar Disciplinas ");
		printf("\n4 - Listar Aniversariantes do mes" );
		printf("\n0 - Sair" );	
	printf("\n\nEscolha uma opcao: ");
	scanf("%d", &opcao);
	getchar();

	switch(opcao)
	{
		case 1: 
			//	printf("\nLista de Alunos " );
				listar_alunos();
				listar_aluno_alfabetica()
			break;
		case 2: 
				listar_professor();
			break;
		case 3: 
				listar_disciplina();
			break;
		case 0:	
				Relatorios();
			printf("\n0 - Retornar" );
		break;
	}
		//	printf("\n\nInforme a opcao escolhida: ");
		//	scanf("%d", &opcao);
			getchar();
	}while(opcao!=0);
}

void listar_alunos(){
	
	int i, opcao, retorno=0;
	system("cls");
		printf("\nLista de Alunos " );
	for(i = 0; i< Aluno_MAX; i++){
 			printf("\nSexo: %c", aluno[i].sexo);
			printf("\nNome: %s", aluno[i].nome);
			printf("\nData de nascimento: %d/%d/%d", aluno[i].dataNascimento);
	}
}
void listar_professor(){
	
	int i, opcao;
	system("cls");
		printf("\nLista de Professores " );
		
		for(i=0; i<Professores_MAX; i++){
			printf("\nSexo: %c", professores[i].sexo);
			printf("\nNome: %s", professores[i].nome);
			printf("\nData de nascimento: %d/%d/%d", professores[i].dataNascimento);
			
		}
}

void listar_disciplina(){
	
		//Percorrendo o vetor de struct
	for (int i = 0; i<Disciplinas_MAX; i++){
		printf("\nCódigo: ", Disciplinas[i].Codigo);
		printf("\nDisciplina: ", Disciplinas[i].nome);
		printf("\nProfessor: ", Disciplinas[i].prof.nome);
		printf("\nSemestre: ", Disciplinas[i].semestre);		
		
	}
}

void remover_alunos(){
	
	int matricula;
		listar_alunos();
		printf("\nInforme a matricula do aluno a ser removido: ");
		scanf("%d", &matricula);
		aluno[Aluno_MAX].matricula=0;
		printf("\nAluno excluido com sucesso!");
	getchar();
}
	

void remover_professor(){
		int matricula;
		listar_professor();
		printf("\nInforme a matricula do Professor a ser removido: ");
		scanf("%d", &matricula);
		professores[Professores_MAX].matricula=0;
		printf("\nProfessor excluido com sucesso!");
	getchar();
	
}
void remover_disciplina(){
	
	int matricula;
		listar_disciplina();
		printf("\nInforme a matricula da disciplina a ser removida: ");
		scanf("%d", &matricula);
		Disciplinas[Disciplinas_MAX].Codigo=0;
		printf("\nDisciplina excluida com sucesso!");
	getchar();
	
}

void listar_aluno_alfabetica(){

	system("cls");
	 int i, j, result;
	 char aux[50];//Guarda provisoriamente o nome do aluno
	 
	 printf("\nALUNOS ORDENADOS POR NOME");
	 for(i = 0; i < Alunos_MAX; i++)//Bubble Sort para ordenar os nomes
	 {
	 for(j = i + 1; j < Alunos_MAX; j++)
	 {
	 result = strcmp(aluno[i].nome, aluno[j].nome);//Compara os nomes
	 if(result > 0)//Se o resultado da comparação for maior que zero, é porque os nomes não estão em ordem alfabetica
	 {
	 strcpy(aux, alunos[i].nome);
	 strcpy(aluno[i].nome, aluno[j].nome);
	 strcpy(aluno[j].nome, aux);
	 }
	 }
	 printf("%s\n", aluno[i].nome);
	 }

}

void validarNome(){
	char nome[50];
	char c;
	int i=0;
	
	//	printf("Digite o nome: ");
		do 
		{
			c=getch();
			if(isalpha(c)!=0 || c==32)
			{
				nome[i]=c;
				i++;
				printf("%c", c);
			}
		/*	else if(c==8&&i)
			{
				nome[i]='\0';
				i--;
				printf("\b\b");
			}*/
		} while (c!=13);
		nome[i]='\0';
	//	printf("\n\n%s\n\n", nome);
}
void validarSexo(){
	
	char sexo;
	
	scanf("%s", &sexo);
	if (sexo == 'f' || sexo == 'F')
	{
		printf("Sexo Feminino\n");		
	}
	else {
	
		if (sexo == 'm' || sexo == 'M')
		{
			printf("Sexo Masculino\n");
		} 
		else 
		{
			printf("\nSexo Invalido (So existe macho e femea): ");
		}	
	}
}
int validarDataNasc(){

int dd, mm, yy;

printf("\nInforme a data (formato dd/mm/aaaa): ");
scanf("%d/%d/%d", &dd, &mm, &yy);

//checar ano
if (yy >= 1900 && yy <= 9999)
{
	//checar mes
   if (mm >= 1 && mm <= 12)
        {
            //check days
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                printf("Date is valid.\n");
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                printf("Date is valid.\n");
            else if ((dd >= 1 && dd <= 28) && (mm == 2))
                printf("Date is valid.\n");
            else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
                printf("Date is valid.\n");
            else
                printf("Day is invalid.\n");
        }
	else
		{
               printf("Month is not valid.\n");
        }
    }
    else
    {
        printf("Year is not valid.\n");
    }

    return 0;
} 

int validarCpf(){
	
	int soma=0, resultado, num, cont;
	char digito10, digito11, cpf[11];
	
	printf("\nDigite o CPF (sem pontos e traços) ");
	scanf("%s", &cpf);
	
	//Validar o primeiro digito
	for (cont = 0; cont < 9; cont++)
	{
		num=cpf[cont] - 48;
		soma=soma+(num*(10-cont));
	}
	resultado=11-(soma%11);
	
	if((resultado==0) || (resultado==11))
	{
		digito10='0';
		
	} else 
		digito10 = resultado+48;
		
	soma = 0;
	for (cont=0; cont<10; cont++)
	{
		num=cpf[cont]-48;
		soma=soma+(num*(11-cont));
	}
	resultado=11-(soma%11);
	if ((resultado==10) || (resultado==11))
		digito11 = '0';
	else
		digito11 = resultado+48;
		
	//comparacao entre os calculos
	if((digito10==cpf[9]) && (digito11==cpf[10]))
		printf("\nCpf Valido");
	else
		printf("\nCpf Invalido");
	getch();
	
}
