#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


typedef struct carta{
    int valor;
    int nipe;
    int indice;
    struct carta *proximo;
}carta;

typedef struct pilha{
	
	carta *topo;
	int tam;
}pilha;

typedef struct lista{
	
	carta carta[5];
	int quant;
	
}lista;

typedef struct player{
	
	char nome[50];
	lista *mao;
	int vida;
	int meta;
	int feito;
	int id;
	
}player;

typedef struct fila{
	
	int inicio;
	int fim;
	int tamanho;
	int vetor[8];
	
}fila;

typedef struct mesa{
	carta carta;
	player player;
}mesa;



pilha *criapilha();
void empilha(pilha *baralho, int x, int y, int z);
void criadeck(pilha *baralho );
void desempilha(pilha *baralho, int *carta_aux, int *nipe_aux, int *indice_aux);



fila *criafila();
int estacheia(fila *f , int quantplayer);
void insere(fila *f, int n, int quantplayer);
int estavazia(fila *f);
void retira(fila *f, int quantplayer);



// listas
lista *crialista();
int insereU(lista *l ,int auxNipe,int auxValor, int auxIndic);
int Lestacheia(lista *l);
int Lestavazia(lista *l);
int removePOS(lista *l, int posicao, carta *x);


void puxacarta(pilha *baralho, lista *mao, int nCarta, player player[], int n);
void maoPrint(player player[],int n, int nCarta,FILE *arq);
void criaPlayer(player player[], int i);

int maiorCarta(carta cartaUm, carta cartaDois);

void mesaJogo(mesa mesa[], int n, player player[], int posCarta, FILE *arq);
void confereTurno(mesa mesa[],player player[], int quantplayer, FILE *arq);
void verificaVida(player player[],int quantplayer, FILE *arq);

int temvida(player player[], int quantplayer);
int vez(int *cont);

int main(){
	
	pilha *baralho;
	
	baralho= criapilha();
	int quantplayer;
	printf("Digite o numero de jogadores\n");
	scanf("%d", &quantplayer);
	
	FILE *arq; // cria variável ponteiro para o arquivo
  	arq = fopen("log.txt", "w");
	
		//fprintf(arq, "O jogo comeca com 2 jogadores\n");
		
		player player[8];
		
		mesa mesa[quantplayer];   // cria a mesa do jogo
		int i=0;
		
		for(i=0;i<8;i++){ // cria os dados dos jogadores
			criaPlayer(player, i);
			
		}
		for(i=0;i<quantplayer;i++){ // cria os dados dos jogadores
			printf("Qual o nome do jogador %d\n", player[i].id+1);
    		gets(player[i].nome);
    		fprintf(arq, "Jogador %d: %s\n", player[i].id,player[i].nome);
		}
		
		
		lista *mao; 
		int nCarta=5, escolha=0, sobe=0;
		/////////////
		int carta_aux,nipe_aux, cont=0, contRodada=0,contTurno=0;

		criadeck(baralho); 
	
		int jj=0, saiDerrota=0;
		
		int contadora=1, turno=0, contMao=0, contFaz=0, aux=0,confereRodada=0;
		
		while(temvida(player, quantplayer)){         // repetição que termina apos os jogadores ficarem sem vidas
			
			
			
			if(quantplayer>0&&player[0].vida!=0){//vez jogador 1
				if(contMao<quantplayer){ // verifica se o jogador possui cartas na mão
					puxacarta(baralho, mao, nCarta, player, 0);
					contMao++;
				}
				if(contFaz<quantplayer){
				maoPrint(player,0,nCarta, arq);
				printf("Quantas cartas voce faz?\n");
				scanf("%d", &player[0].meta);
				fprintf(arq, "O jogador %s definiu sua meta como %d", player[0].nome, player[0].meta);
				contFaz++;
				}
				if(jj>0){ // verifica se os jogadores já definiram suas metas
					maoPrint(player,0,nCarta, arq);
					printf("Qual carta deseja jogar?\n");
					scanf("%d", &aux);
					mesaJogo(mesa, player[0].id, player,aux, arq); // faz a jogada da carta
					contTurno++;	
				}
				
				
	
			}
			if(quantplayer>1&&player[1].vida!=0){//vez jogador 2
				if(contMao<quantplayer){ // verifica se o jogador possui cartas na mão
					puxacarta(baralho, mao, nCarta, player, 1);
					contMao++;
				}
				if(contFaz<quantplayer){
				maoPrint(player,1,nCarta, arq);
				printf("Quantas cartas voce faz?\n");
				scanf("%d", &player[1].meta);
				fprintf(arq, "O jogador %s definiu sua meta como %d", player[1].nome, player[1].meta);
				contFaz++;
				}
				if(jj>0){ // verifica se os jogadores já definiram suas metas
					maoPrint(player,1,nCarta, arq);
					printf("Qual carta deseja jogar?\n");
					scanf("%d", &aux);
					mesaJogo(mesa, player[1].id, player,aux, arq); // faz a jogada da carta
					contTurno++;	
				}
				
			}
			if(quantplayer>2&&player[2].vida!=0){//vez jogador 2
				if(contMao<quantplayer){ // verifica se o jogador possui cartas na mão
					puxacarta(baralho, mao, nCarta, player, 2);
					contMao++;
				}
				if(contFaz<quantplayer){
				maoPrint(player,2,nCarta, arq);
				printf("Quantas cartas voce faz?\n");
				scanf("%d", &player[2].meta);
				fprintf(arq, "O jogador %s definiu sua meta como %d", player[2].nome, player[2].meta);
				contFaz++;
				}
				if(jj>0){ // verifica se os jogadores já definiram suas metas
					maoPrint(player,2, nCarta, arq);
					printf("Qual carta deseja jogar?\n");
					scanf("%d", &aux);
					mesaJogo(mesa, player[2].id, player,aux, arq); // faz a jogada da carta
					contTurno++;	
				}
				
			}
			
			if(quantplayer>3&&player[3].vida!=0){//vez jogador 2
				if(contMao<quantplayer){ // verifica se o jogador possui cartas na mão
					puxacarta(baralho, mao, nCarta, player, 3);
					contMao++;
				}
				if(contFaz<quantplayer){
				maoPrint(player,3,nCarta, arq);
				printf("Quantas cartas voce faz?\n");
				scanf("%d", &player[3].meta);
				fprintf(arq, "O jogador %s definiu sua meta como %d", player[3].nome, player[3].meta);
				contFaz++;
				}
				if(jj>0){ // verifica se os jogadores já definiram suas metas
					maoPrint(player,3, nCarta, arq);
					printf("Qual carta deseja jogar?\n");
					scanf("%d", &aux);
					mesaJogo(mesa, player[3].id, player,aux, arq); // faz a jogada da carta
					contTurno++;	
				}
				
			}
			
			if(quantplayer>4&&player[4].vida!=0){//vez jogador 2
				if(contMao<quantplayer){ // verifica se o jogador possui cartas na mão
					puxacarta(baralho, mao, nCarta, player, 4);
					contMao++;
				}
				if(contFaz<quantplayer){
				maoPrint(player,4,nCarta, arq);
				printf("Quantas cartas voce faz?\n");
				scanf("%d", &player[4].meta);
				fprintf(arq, "O jogador %s definiu sua meta como %d", player[4].nome, player[4].meta);
				contFaz++;
				}
				if(jj>0){ // verifica se os jogadores já definiram suas metas
					maoPrint(player,4, nCarta, arq);
					printf("Qual carta deseja jogar?\n");
					scanf("%d", &aux);
					mesaJogo(mesa, player[4].id, player,aux, arq); // faz a jogada da carta
					contTurno++;	
				}
				
			}
			if(quantplayer>5&&player[5].vida!=0){//vez jogador 2
				if(contMao<quantplayer){ // verifica se o jogador possui cartas na mão
					puxacarta(baralho, mao, nCarta, player, 5);
					contMao++;
				}
				if(contFaz<quantplayer){
				maoPrint(player,5,nCarta, arq);
				printf("Quantas cartas voce faz?\n");
				scanf("%d", &player[5].meta);
				fprintf(arq, "O jogador %s definiu sua meta como %d", player[5].nome, player[5].meta);
				contFaz++;
				}
				if(jj>0){ // verifica se os jogadores já definiram suas metas
					maoPrint(player,5, nCarta, arq);
					printf("Qual carta deseja jogar?\n");
					scanf("%d", &aux);
					mesaJogo(mesa, player[5].id, player,aux, arq); // faz a jogada da carta
					contTurno++;	
				}
				
			}
			if(quantplayer>6&&player[6].vida!=0){//vez jogador 2
				if(contMao<quantplayer){ // verifica se o jogador possui cartas na mão
					puxacarta(baralho, mao, nCarta, player, 6);
					contMao++;
				}
				if(contFaz<quantplayer){
				maoPrint(player,6,nCarta, arq);
				printf("Quantas cartas voce faz?\n");
				scanf("%d", &player[6].meta);
				fprintf(arq, "O jogador %s definiu sua meta como %d", player[6].nome, player[6].meta);
				contFaz++;
				}
				if(jj>0){ // verifica se os jogadores já definiram suas metas
					maoPrint(player,6, nCarta, arq);
					printf("Qual carta deseja jogar?\n");
					scanf("%d", &aux);
					mesaJogo(mesa, player[6].id, player,aux, arq); // faz a jogada da carta
					contTurno++;	
				}
				
			}
			
			if(quantplayer>7&&player[7].vida!=0){//vez jogador 2
				if(contMao<quantplayer){ // verifica se o jogador possui cartas na mão
					puxacarta(baralho, mao, nCarta, player, 7);
					contMao++;
				}
				if(contFaz<quantplayer){
				maoPrint(player,7,nCarta, arq);
				printf("Quantas cartas voce faz?\n");
				scanf("%d", &player[7].meta);
				fprintf(arq, "O jogador %s definiu sua meta como %d", player[7].nome, player[7].meta);
				contFaz++;
				}
				if(jj>0){ // verifica se os jogadores já definiram suas metas
					maoPrint(player,7, nCarta, arq);
					printf("Qual carta deseja jogar?\n");
					scanf("%d", &aux);
					mesaJogo(mesa, player[7].id, player,aux, arq); // faz a jogada da carta
					contTurno++;	
				}
				
			}

			
			turno++;
			if(contTurno==quantplayer){
					confereTurno(mesa,player,quantplayer, arq);   // confere quem mandou a maior carta e faz a contagem de pontos
					int i=0;
					
					for(i=0;i<quantplayer;i++){
						printf("\n\n--Player:%d--meta:%d-feito:%d--\n\n", i,player[i].meta , player[i].feito);
					}
					
					
					
					contTurno=0;
					confereRodada++;
			}
			jj=1;
			if(turno>nCarta){
				//chama baralho
				
				verificaVida(player, quantplayer, arq);       // verifique quem esta no jogo
				confereRodada=0;
				contRodada=0;
			    cont=0;
			    jj=0;
			    criadeck(baralho );
			    contMao=0;
				contFaz=0;
				turno=0;
				if(nCarta==5){                        // faz a mudança da quantidade de cartas que os jogadores receberão
					sobe=0;
				}else if(nCarta==1){
					sobe=1;
					
				}
				if(sobe==0){
					nCarta--;
				}else if(sobe==1){
					nCarta++;
				}
				
			}
			
		}
		
		int ganhou=0;
		for(i=0;i<quantplayer;i++){       // procura o ganhador do jogo e exibe seu nome
			if(player[i].vida>0){
				printf("\nO vencedor foi o jogador %s\n", player[i].nome);
				fprintf(arq, "\nO vencedor foi o jogador %s\n", player[i].nome);
				ganhou=1;
			}
		}
		if(ganhou==0){
			printf("\nA partida nao teve vencedores\n");
			fprintf(arq, "\nA partida nao teve vencedores\n");
		}
		//ver quem ganhou
			
		
	
	
	
	

	
	fclose(arq);
	return 0;
}
int vez (int *cont){
	//if(cont%2)
}
int temvida(player player[], int quantplayer){
	int cont=0, i;
	switch(quantplayer){
		case 2:
			if(player[0].vida==0 || player[1].vida==0){
				return 0;
			}else{
				return 1;
			}
			break;
		case 3:
			for(i=0;i<3;i++){
				if(player[i].vida==0)
					cont++;
			}
			if(cont!=2){
				return 1;
			}else{
				return 0;
			}
			break;
		case 4:
			for(i=0;i<4;i++){
				if(player[i].vida==0)
					cont++;
			}
			if(cont!=3){
				return 1;
			}else{
				return 0;
			}
			break;
		case 5:
			for(i=0;i<5;i++){
				if(player[i].vida==0)
					cont++;
			}
			if(cont!=4){
				return 1;
			}else{
				return 0;
			}
			break;	
		case 6:
			for(i=0;i<6;i++){
				if(player[i].vida==0)
					cont++;
			}
			if(cont!=5){
				return 1;
			}else{
				return 0;
			}
			break;
		case 7:
			for(i=0;i<7;i++){
				if(player[i].vida==0)
					cont++;
			}
			if(cont!=6){
				return 1;
			}else{
				return 0;
			}
			break;	
		case 8:
			for(i=0;i<8;i++){
				if(player[i].vida==0)
					cont++;
			}
			if(cont!=7){
				return 1;
			}else{
				return 0;
			}
			break;
	}
	
	
	/*

	*/
}
pilha *criapilha(){ 
	pilha *p;
	p=(pilha*)malloc(sizeof(pilha));
	p->tam=0;
	p->topo=NULL;
	
	return p;
}



void empilha(pilha *baralho, int x, int y, int z){ // adiciona uma carta no topo do baralho

    carta *novacarta;
    novacarta= (carta*)malloc(sizeof(carta));


    novacarta->valor=x;
    novacarta->nipe=y;
    novacarta->indice=z;

    if(baralho->topo==NULL){
        novacarta->proximo=NULL;
        baralho->topo=novacarta;



    }else{

        novacarta->proximo=baralho->topo;
        baralho->topo=novacarta;

    }
        baralho->tam++; 

}


void desempilha(pilha* baralho, int *carta_aux, int *nipe_aux, int *indice_aux){
    // FUNÇÃO PUXA A CARTA DO TOPO DO BARALHO (DELETA E SALVA VALOR E NIPE)
    carta *aux;

    aux= (carta *) malloc(1*sizeof(carta));



    *carta_aux = baralho->topo->valor;
    *nipe_aux = baralho->topo->nipe;
    *indice_aux= baralho->topo->indice;

    aux=baralho->topo;
    baralho->topo=aux->proximo;
    baralho->tam--;

    free(aux);
}

void criadeck(pilha *baralho ){ // cria o baralho e o embaralha;

    int carta[40]={4,7,1,7,3,3,3,3,2,2,2,2,1,1,1,13,13,13,13,12,12,12,12,11,11,11,11,7,7,6,6,6,6,5,5,5,5,4,4,4};
    int nipe[40]={4,1,3,2,4,1,3,2,4,1,3,2,4,1,2,4,1,3,2,4,1,3,2,4,1,3,2,4,3,4,1,3,2,4,1,3,2,1,3,2};
    int indice[40]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39};
    int i=0, aux=0, auxN=0, auxI=0, result=0;
    srand(time(0));

    for(i=0;i<40;i++){
        result= rand() % 40;

        aux=carta[i];
        auxN=nipe[i];
        auxI=indice[i];

        carta[i]=carta[result];
        nipe[i]=nipe[result];
        indice[i]=indice[result];

        carta[result]=aux;
        nipe[result]=auxN;
        indice[result]=auxI;

    }

    for(i=0;i<40;i++){
        empilha(baralho,carta[i],nipe[i],indice[i]);
    }

}

//////////////////////////
// FILA REFERENTE AOS TURNOS

fila *criafila(){
	
	fila *f;
	f=(fila*)malloc(1*sizeof(fila));
	f->fim=0;
	f->inicio=0;
	f->tamanho=0;
	
	return f;
}

int estacheia(fila *f , int quantplayer){
	
	if(f->tamanho<quantplayer){
		return 0;
	}
	else{
		return 1;
	}
	
}

void insere(fila *f, int n, int quantplayer){
	
	
	int cheia =estacheia(f,quantplayer);
	if(cheia==0){
		f->fim=f->fim%quantplayer;
		f->vetor[f->fim]=n;
		f->fim++;
		f->tamanho++;
	}
	
}
int estavazia(fila *f){
	if(f->tamanho>0){
	//	printf("A fila esta vazia");
		return 0;
	}
	else{
		return 1;
	}
}
void retira(fila *f, int quantplayer){ //Remove o jogador
	
	int aux=0;
	aux=estavazia(f);
	if(aux==0){
		f->inicio=f->inicio%quantplayer;
		f->inicio++;
		f->tamanho--;
	}
	
}

//////////////////////////////


// criação das mãos /


void puxacarta(pilha *baralho, lista *mao, int nCarta, player player[], int n){ // puxa uma carta do topo do baralho

    int i=0;
    int auxNipe=0, auxValor=0, auxIndic=0;
    mao = crialista();

        for(i=0;i<nCarta;i++){


            desempilha(baralho,&auxValor,&auxNipe,&auxIndic);
            insereU(mao, auxValor, auxNipe, auxIndic);



    }


    player[n].mao=mao;
    //    printf("a carta eh:%d e nipe %d\n", player.mao->carta[1].valor, player.mao->carta[1].nipe);
//    printf("a carta eh:%d e nipe %d\n", player[0].mao->carta[0].valor, player[0].mao->carta[0].nipe);
}

void maoPrint(player player[], int n, int nCarta, FILE *arq){
	int i=0;
//	printf("--%d--", n);
	printf("------------------MAO DO JOGADOR %s---------------------\n", player[n].nome);
	fprintf(arq, "------------------MAO DO JOGADOR %s---------------------\n", player[n].nome);
	for(i=0;i<player[n].mao->quant;i++){
		
		printf("Carta %d:  Numero %d com o nipe %d\n", i+1,player[n].mao->carta[i].valor,player[n].mao->carta[i].nipe);
		fprintf(arq, "Carta %d:  Numero %d com o nipe %d\n", i+1,player[n].mao->carta[i].valor,player[n].mao->carta[i].nipe);
	}
	printf("-------------------------------------------------------\n");
	fprintf(arq, "-------------------------------------------------------\n");
}

void criaPlayer(player player[], int i){
	
	player[i].feito=0;
	player[i].meta=0;
	player[i].vida=5;
	player[i].id=i;
	
	setbuf(stdin, NULL);
    //printf("Qual o nome do jogador %d\n", player[i].id+1);
    //gets(player[i].nome);
	
}


void mesaJogo(mesa mesa[], int n, player player[], int posCarta,FILE *arq){ // remove a carta selecionada do jogador e aiciona ela na mesa
	carta x,y;
	mesa[n].player=player[n];
	player[n].mao->carta[posCarta];

	removePOS(player[n].mao, posCarta-1, &x); 
	mesa[n].carta.valor=x.valor;
	mesa[n].carta.nipe=x.nipe;
	mesa[n].carta.indice=x.indice;	
	printf("a carta %d de nipe %d foi jogada\n", x.valor,x.nipe);	
	fprintf(arq, "O jogador %s jogou a carta %d de nipe %d\n", player[n].nome, x.valor,x.nipe);
}
void confereTurno(mesa mesa[],player player[], int quantplayer, FILE *arq){
	//mesaJogo(mesa, player[turno->inicio-1].id, player,aux);
	int i=0,j=0, result=0, aux=0,cont=0; 
	carta maisForte;
	
	for(i=0;i<quantplayer;i++){
		
		if(i==0){
			maisForte=mesa[i].carta;
			aux=i;
		}
		
		if(mesa[i].carta.indice<maisForte.indice){
			maisForte=mesa[i].carta;
			aux=i;
		}
		
	}
	//printf("aux: %d\n", aux);
	player[aux].feito++;
	
	printf("\nA carta mais forte e: %d nipe %d do jogador %d\n",mesa[aux].carta.valor , mesa[aux].carta.nipe,player[aux].id+1); 
	
	fprintf(arq, "\nA carta mais forte e: %d nipe %d do jogador %d\n",mesa[aux].carta.valor , mesa[aux].carta.nipe,player[aux].id+1);
	//	printf("\nA carta e: %d nipe %d do jogador %d com um poder de %d\n",mesa[0].carta.valor , mesa[0].carta.nipe,player[0].id+1, mesa[0].carta.indice);
	
}
int maiorCarta(carta cartaUm, carta cartaDois){

    if(cartaUm.indice<cartaDois.indice){
        return 1;
    }else{
        return 0;
    }
}

void verificaVida(player player[],int quantplayer, FILE *arq){
	int i=0;
	for(i=0;i<quantplayer;i++){
		
		if(player[i].meta==player[i].feito){
			printf("O jogador %s NAO perdeu uma vida VIDAS RESTANTESD: %d\n", player[i].nome, player[i].vida);
			fprintf(arq, "O jogador %s NAO perdeu uma vida VIDAS RESTANTESD: %d\n", player[i].nome, player[i].vida);
		}else{
			if(player[i].vida!=0){
				player[i].vida--;
			}
			printf("O jogador %s perdeu uma vida VIDAS RESTANTESD: %d\n", player[i].nome, player[i].vida);
			fprintf(arq, "O jogador %s perdeu uma vida VIDAS RESTANTESD: %d\n", player[i].nome, player[i].vida);
			
		}
		player[i].feito=0;
	}
	
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



lista *crialista(){
	
	lista *l;
	l=(lista *)malloc(sizeof(lista));
	l->quant=0;
	
	return l;
}

int Lestacheia(lista *l){
	
	if(l->quant>=10){
		return 1;
	}else{
		return 0;
	}
	
}
int insereU(lista *l, int auxValor, int auxNipe, int auxIndic){ // pega a carta puxada e coloca na mao do jogador

     int cheia=Lestacheia(l);
     if(cheia==0){
     	
         l->carta[l->quant].valor=auxValor;
         l->carta[l->quant].nipe=auxNipe;
         l->carta[l->quant].indice=auxIndic;
         l->quant++;

         return 1;
     }else{

         return 0;
     }
}

int Lestavazia(lista *l){
	
	if(l->quant==0){
		return 1;
	}else{
		return 0;
	}
		
}


int removePOS(lista *l, int posicao, carta *x){
	
	int vazia=Lestavazia(l);
	int i;
	if(vazia==0){
		
		if(posicao<l->quant){
			*x=l->carta[posicao];
			for(i=posicao;i<l->quant;i++){
				
				l->carta[i]=l->carta[i+1];
				
				
			}
			l->quant--;
			return 1;
			
			
			
		}
				
	}else{
		return 0;
	}	
}

