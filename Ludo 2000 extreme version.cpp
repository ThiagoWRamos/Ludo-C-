#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>
#include <cstdlib>
#define NUM_JOGADORES 2
#define LADO 6
#define TRILHA 5

using namespace std;

int jogo(){
	int pecaJ1[TRILHA] = {0}, pecaJ2[TRILHA] = {0}, p, dado, pontuacaoJ1 = 0, pontuacaoJ2  = 0, i, dadoJ1, dadoJ2;
	string nomeJogador[NUM_JOGADORES];
	bool fimPartida = false, vencedor1, vencedor2;

	//nome dos jogadores
	for (i = 0; i < NUM_JOGADORES; i++){
		cout << "Qual o nome do " << i+1 << "� jogador? ";
		cin >> nomeJogador[i];
	}
	cout << "Bem vindo ao Ludo 2000\n";
	cout << "\nCerto, vamos come�ar!\n";
	system ("pause");
	system ("cls");

	while(!fimPartida) {
		// jogador 1
		system ("cls");
		cout << pontuacaoJ1 << endl;

		cout << "\\TABULEIRO/\n\n";
		cout << "Pe�as de " << nomeJogador[0] << endl;
		for (p = 1; p < TRILHA; p++){
			cout << "Pe�a " << p << "= " << pecaJ1[p] << endl;		
		}
		cout << "\n\n";
		
		cout << "Pe�as de " << nomeJogador[1] << endl;
		for (p = 1; p < TRILHA; p++){
			cout << "Pe�a " << p << "= " << pecaJ2[p] << endl;		
		}
		cout << "\n\n";
		
		
		cout << "Vez de " << nomeJogador[0] << endl << endl;
		dado = rand() % 6 + 1;
		cout << "dado = " << dado << endl;
		do {
			cout << "qual pe�a deseja mover " << nomeJogador[0] << "?\n";
			cin >> p;
		} while (pecaJ1[p] >= 20); // testar a posicao 20
		pecaJ1[p] += dado;
		pontuacaoJ1 += dado;
		
		if (pecaJ1[p] >= 20){
			pecaJ1[p] = 20;
		}

		//arena
		if (pecaJ1[p] >= 16 && pecaJ1[p] <= 19){
			cout << "Voc� acaba de entrar na Arena. Cuidado, sua vida est� em risco\n";
				// disputa
				if (pecaJ1[p] == pecaJ2[p] && pecaJ1[p] != 20 && pecaJ2[p] != 20){
					dadoJ1 = rand() % 6 + 1;
					cout << nomeJogador[0] << " tirou " << dadoJ1 << " no dado\n";
					
					dadoJ2 = rand() % 6 + 1;
					cout << nomeJogador[1] << " tirou " << dadoJ2 << " no dado\n";
					
					if (dadoJ1 > dadoJ2){
						cout << nomeJogador[0] << " � mais forte que " << nomeJogador[1] << ", ent�o este teve que voltar ao inicio por conta de seus ferimentos\n\n";
						cout << "Pe�a " << p << " de " << nomeJogador[1] << " retona a 0\n";
						pecaJ2[p] = 0;
						system("pause");
					} else if (dadoJ1 < dadoJ2){
						cout << nomeJogador[1] << " � mais forte que " << nomeJogador[0] << ", ent�o este teve que voltar ao inicio por conta de seus ferimentos\n\n";
						cout << "Pe�a " << p << " de " << nomeJogador[0] << " retona a 0\n";
						pecaJ1[p] = 0;
						system("pause");
					}else if (dadoJ1 == dadoJ2){
						cout << "Ambos jogadores s�o muito fortes e causaram graves ferimentos no advers�rio, portanto ambos retornam ao inicio\n\n";
						cout << "Pe�a " << p << " de " << nomeJogador[0] << " retona a 0\n";
						cout << "Pe�a " << p << " de " << nomeJogador[1] << " retona a 0\n";
						pecaJ1[p] = 0;
						pecaJ2[p] = 0;
						system("pause");
					}
				}
				
				if (dado == 1){
				cout << "Escolha um pe�o do advers�rio para retorn�-lo ao inicio: ";       
				cin >> p;
				cout << "Pe�a " << p << " de " << nomeJogador[1] << " retona a 0 e " << nomeJogador[1] << " perde 20 pontos\n";
				pecaJ2[p] = 0;
				pontuacaoJ2 -= 20;
				system("pause");
				}		
		}else{
			// comer pe�a
			if(pecaJ1[p] == pecaJ2[p] && pecaJ1[p] != 20 && pecaJ2[p] != 20){
				pecaJ2[p] = 0;
				
				cout << "A trilha " << p << " de " << nomeJogador[1] << " retornou a casa inicial\n";
				system("pause");
			}
			
			//regra do 1 no dado
			if (dado == 1){
				cout << "Escolha um pe�o do advers�rio para retorn�-lo ao inicio: ";       
				cin >> p;
				if (pecaJ2[p] != 20){			
					pecaJ2[p] = 0;
					cout << "Pe�a " << p << " de " << nomeJogador[1] << " retona a 0\n";
					system("pause");
				}else{
					cout << "A pe�a que voc� escolheu est� na casa final e voc� n�o pode retir�-la de l�!\n";
				}
				system("pause");
			}		
		}

		
		vencedor1 = true;
		for (p = 1; p < TRILHA; p++){
			vencedor1 = vencedor1 && (pecaJ1[p] >= 20);
		}

		// jogador 2
		
		system ("cls");
		cout << "\\TABULEIRO/\n\n";
		cout << "Pe�as de " << nomeJogador[0] << endl;
		for (p = 1; p < TRILHA; p++){
			cout << "Pe�a " << p << "= " << pecaJ1[p] << endl;		
		}
		cout << "\n\n";
		
		cout << "Pe�as de " << nomeJogador[1] << endl;
		for (p = 1; p < TRILHA; p++){
			cout << "Pe�a " << p << "= " << pecaJ2[p] << endl;		
		}
		cout << "\n\n";
		
		
		
		cout << "Vez de " << nomeJogador[1] << endl << endl;
		dado = rand() % 6 + 1;
		cout << "dado = " << dado << endl;
		do {
			cout << "qual pe�a deseja mover " << nomeJogador[1] << "?\n";
			cin >> p;
		} while (pecaJ2[p] >= 20); // testar a posicao 20
		pecaJ2[p] += dado;
		pontuacaoJ2 += dado;
		
		if (pecaJ2[p] >= 20){
			pecaJ2[p] = 20;
		}

		//arena
		if (pecaJ2[p] >= 16 && pecaJ2[p] <= 19){
			cout << "Voc� acaba de entrar na Arena. Cuidado, sua vida est� em risco\n\n";
				// disputa
				if (pecaJ2[p] == pecaJ1[p] && pecaJ1[p] != 20 && pecaJ2[p] != 20){
					dadoJ1 = rand() % 6 + 1;
					cout << nomeJogador[0] << " tirou " << dadoJ1 << " no dado\n";
					
					dadoJ2 = rand() % 6 + 1;
					cout << nomeJogador[1] << " tirou " << dadoJ2 << " no dado\n";
					
					if (dadoJ1 > dadoJ2){
						cout << nomeJogador[0] << " � mais forte que " << nomeJogador[1] << ", ent�o este teve que voltar ao inicio por conta de seus ferimentos\n\n";
						cout << "Pe�a " << p << " de " << nomeJogador[1] << " retona a 0\n";
						pecaJ2[p] = 0;
						system("pause");
					} else if (dadoJ1 < dadoJ2){
						cout << nomeJogador[1] << " � mais forte que " << nomeJogador[0] << ", ent�o este teve que voltar ao inicio por conta de seus ferimentos\n\n";
						cout << "Pe�a " << p << " de " << nomeJogador[0] << " retona a 0\n";
						pecaJ1[p] = 0;
						system("pause");
					}else if (dadoJ1 == dadoJ2){
						cout << "Ambos jogadores s�o muito fortes e causaram graves ferimentos no advers�rio, portanto ambos retornam ao inicio\n\n";
						cout << "Pe�a " << p << " de " << nomeJogador[0] << " retona a 0\n";
						cout << "Pe�a " << p << " de " << nomeJogador[1] << " retona a 0\n";
						pecaJ1[p] = 0;
						pecaJ2[p] = 0;
						system("pause");
					}
				}
				
				if (dado == 1){
				cout << "Escolha um pe�o do advers�rio para retorn�-lo ao inicio: ";       
				cin >> p;
				cout << "Pe�a " << p << " de " << nomeJogador[0] << " retona a 0 e " << nomeJogador[0] << " perde 20 pontos\n";
				pecaJ1[p] = 0;
				pontuacaoJ1 -= 20;
				system("pause");
				}		
		}else{
			// comer pe�a
			if(pecaJ2[p] == pecaJ1[p] && pecaJ1[p] != 20 && pecaJ2[p] != 20){
				pecaJ1[p] = 0;
				
				cout << "A trilha " << p << " de " << nomeJogador[0] << " retornou a casa inicial\n";
				system("pause");
			}
			
			// Regra do 1 no dado		
			if (dado == 1){
				cout << "Escolha um pe�o do advers�rio para retorn�-lo ao inicio: ";       
				cin >> p;
				if (pecaJ1[p] != 20){			
					pecaJ1[p] = 0;
					cout << "Pe�a " << p << " de " << nomeJogador[0] << " retona a 0\n";
					system("pause");
				}else{
					cout << "A pe�a que voc� escolheu est� na casa final e voc� n�o pode retir�-la de l�!\n";
					system("pause");
				}
			}		
		}
		
		vencedor2 = true;
		for (p = 1; p < TRILHA; p++){
			vencedor2 = vencedor2 && (pecaJ2[p] >= 20);
		}
		
		fimPartida = vencedor1 || vencedor2;	
	}
	// determinar quem venceu
	
	cout << "\n\nA partida est� encerrada! Ambos competidores foram muito bons, mas s� pode haver um Vencedor!!!\n";
	cout << "E o vencedor �...\n\n";
	
	if (pontuacaoJ1 > pontuacaoJ2){ //se o jogador 1 ganhar
		cout << nomeJogador[0] << " com " << pontuacaoJ1 << " pontos!!\n\n";
		cout << "Parab�ns " << nomeJogador[0] << " por sua vit�ria";
	} else if (pontuacaoJ1 < pontuacaoJ2){ //se o jogador 2 ganhar
		cout << nomeJogador[1] << " com " << pontuacaoJ2 << " pontos!!\n\n";
		cout << "Parab�ns " << nomeJogador[1] << " por sua vit�ria\n\n";
	}
	
	usleep(100000);
	cout << "CODIGO: THIAGO W. DE RAMOS\n";
	usleep(100000);
	cout << "DISCIPLINA: PROGRAMA��O DE COMPUTADORES 1\n";
	usleep(100000);
	cout << "PROFESSOR: SANDRO RAUTENBERG\n\n";
	
	return 0;
	system("pause");
		
}

int regra(){
	usleep(300000);
	// regras do jogo
	cout << "BEM VINDO AS REGRAS\n";
	system ("pause");
	
	usleep(200000);
	cout << "As regras s�o as seguintes:\n\n\n";
	usleep(100000);
	cout << "1. O jogo � disputado por dois jogadores, identificados por seus nomes\n\n";
	usleep(100000);
	cout << "2. O jogo tem quatro trilhas e em cada trilha h� dois pe�es, representando os dois jogadores. Ou seja, cada pe�o percorre uma trilha, concorrentemente com o pe�o equivalente do advers�rio\n\n";
	usleep(100000);
	cout << "3. Para cada jogada, o jogador lan�a o dado e escolhe a trilha em que o pe�o deve ser movimentado, de acordo com a face do dado\n\n";
	usleep(100000);
	cout << "4. A pontua��o total de cada jogador � incrementada conforme o valor da face do dado em cada jogada (crit�rio futuro de desempate)\n\n";
	usleep(100000);
	cout << "5. N�o � permitido movimentar um pe�o que j� alcan�ou a casa final\n\n";
	usleep(100000);
	cout << "6. Em uma jogada, quando o jogador igualar a posi��o (disputar a casa) do pe�o advers�rio, o pe�o advers�rio volta � casa inicial, exceto quando atingirem a casa final\n\n";
	usleep(100000);
	cout << "7. Quando o valor do dado for maior do que diferen�a para que o pe�o chegue � casa final, toda a pontua��o � considerada. Por exemplo, se o pe�o da trilha 2 estiver na 17 a casa e o valor do dado tenha sido 4,\no pe�o alcan�a a casa final e a pontua��o � acrescida em 4 pontos, embora o pe�o s� tenha se movido 3 casas\n\n";
	usleep(100000);
	cout << "8. A partida termina quando todos os pe�es de pelo menos um jogador atingirem as 20 a casas (as casas finais)\n\n";
	usleep(100000);
	cout << "9. Um jogador ganha, de modo exclusivo, quando s� os seus pe�es atingem as casas finais ao final da rodada\n\n";
	usleep(100000);
	cout << "10. Se todos os jogadores tiverem completado as trilhas, ganha o jogador que tiver a maior pontua��o total\n\n";
	usleep(100000);
	cout << "11. Ocorre empate quando, al�m de todos os pe�es dos jogadores atingirem a casa final, os jogadores tiverem obtido a mesma pontua��o total\n\n";
	usleep(100000);
	cout << "12. Se um jogador tirar 1 no dado, ele pode escolher uma pe�a do advers�rio para voltar pra casa inicial\n\n";
	usleep(100000);
	cout << "13. Da casa 16 � casa 19 h� a arena, sendo assim, se os jogadores se encontrarem na mesma posi��o, eles disputaram no dado quem voltar� para a casa inicial, sendo quem tirar o menor numero q voltar�\n\n";
	usleep(100000);
	cout << "14. � poss�vel remover uma pe�a advers�ria da casa final (casa 20) conforme a regra 1 se voce estiver na arena (e tamb�m 20 pontos ser�o retirados do jogador advers�rio, independente da casa em que o pe�o\nescolhido est�)\n\n";
	
	usleep(500000);
	cout << "Ap�s ter lidos as regras, pressione qualquer tecla para ir ao jogo\n\n\n";
	system ("pause");
		system ("cls");
	jogo();
}

int menu(){ //menu do jogo
	int opcao;
	cout << "Digite um numero para ir para um menu\n";
	usleep(100000);
	cout << "1. JOGAR\n";
	usleep(100000);
	cout << "2. REGRAS\n";
	usleep(100000);
	cout << "3. SAIR\n\n";
	usleep(100000);
	cout << "Qual sua escolha? ";
	
	cin >> opcao;
	system ("cls");
		
	switch (opcao){
		case 1:
			system ("cls");
			jogo();
			break;
		case 2:
			system ("cls");
			regra();
			break;
		case 3:
			return 0;
			break;
		default:
			system ("cls");
			return menu();
	}
}
 
int inicio(){ //titulo do jogo
	int g;
	
	for (g = 0; g <= 100; g++){ //fake loading
		cout << "loading " << g << "%...\r";
		usleep(30000);
	}
	cout << "      :::       :::    ::: :::::::::   ::::::::           ::::::::   :::::::   :::::::   ::::::: \n";
	usleep(200000);
	cout << "     :+:       :+:    :+: :+:    :+: :+:    :+:         :+:    :+: :+:   :+: :+:   :+: :+:   :+: \n";
	usleep(200000);
	cout << "    +:+       +:+    +:+ +:+    +:+ +:+    +:+               +:+  +:+   +:+ +:+   +:+ +:+   +:+  \n";
	usleep(200000);
	cout << "   +#+       +#+    +:+ +#+    +:+ +#+    +:+             +#+    +#+   +:+ +#+   +:+ +#+   +:+   \n";
	usleep(200000);
	cout << "  +#+       +#+    +#+ +#+    +#+ +#+    +#+           +#+      +#+   +#+ +#+   +#+ +#+   +#+    \n";
	usleep(200000);
	cout << " #+#       #+#    #+# #+#    #+# #+#    #+#          #+#       #+#   #+# #+#   #+# #+#   #+#     \n";
	usleep(200000);
	cout << "########## ########  #########   ########          ##########  #######   #######   #######        \n\n\n\n";
	cout <<"                       ";
	system ("pause");
}

int main(){
	srand(time(NULL));
	setlocale(LC_ALL,"Portuguese");
	inicio();
	menu();
	return 0;	
}
