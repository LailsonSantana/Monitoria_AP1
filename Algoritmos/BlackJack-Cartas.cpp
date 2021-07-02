/*(1) Crie um jogo 21 (BlackJack) em C++. Existe uma infinidade de formas de se jogar 21; o objetivo sempre
� formar 21 pontos com cartas (ou chegar o mais pr�ximo poss�vel). O nosso jogo ser� uma vers�o
simplificada, para um jogador solit�rio. Ele deve ter a chance de permanecer no jogando uma rodada
ap�s a outra at� decidir parar. Veja as regras:
1. Valor das cartas: todas as cartas com figura (valete, dama e rei) valem 10 pontos; o �s, vale 1; e as
demais cartas valem o seu pr�prio n�mero.

3

2. Incialmente, o jogador recebe 3 cartas (e calcula a soma de pontos).
3. Se a soma de seus pontos der 21, ele j� vence no in�cio.
4. Se ele ultrapassar os 21 pontos, j� perde no in�cio.
5. Se passar do in�cio, para formar os 21 pontos, o jogador pode �comprar� uma carta do monte,
quantas vezes quiser, e somar os pontos desta carta aos seus pontos atuais. Mas ele deve fazer isso
com cautela. Se em algum momento seus pontos ultrapassarem 21, ele perde o jogo.
6. O jogador deve informar quando quiser para de comprar cartas e encerrar a rodada (caso n�o tenha
atingido (vence) ou ultrapassado (perde) os 21 pontos. Se ele parar sem atingir os 21, ele deve ver
uma mensagem informando os seus pontos e o recorde atual � o maior n�mero de pontos j� atingido
considerando todas as rodadas.
O seu programa deve atender aos seguintes requisitos:
� Use uma fun��o compra_carta que sorteia um n�mero de 1 a 13 representando uma carta
(�s, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, valete, dama, rei) e retorna o n�mero de pontos correspondente
� carta;
� Use uma fun��o recorde que
o registra a pontua��o atingida em cada rodada;
o atualiza o recorde, se necess�rio; e
o mostra essa a pontua��o da rodada comparando com o recorde.
DICA: use uma vari�vel est�tica aqui ??.
� Use uma fun��o jogo que, com a ajuda das fun��es acima implementa o jogo.
� Chame a fun��o jogo a partir do programa principal provendo nele uma estrutura de repeti��o
que permita ao jogador repetir o jogo (iniciar uma nova rodada) sempre que desejar.*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void jogo();
int compra_carta();
void recorde(int pont);
int main()
{
    srand(time(0));

    while(true){
        char resp;
        jogo();
        cout<<"Deseja iniciar uma nova rodada ? [S]/[N] :";
        cin>>resp;
        cout<<endl;
        if(resp == 'N' || resp == 'n'){
            break;
        }
    }

    return 0;
}


int compra_carta(){
    int gerado;
    gerado = rand() % 14;
    if(gerado == 13 || gerado == 12 || gerado == 11){
        gerado = 10;
    }
    else if(gerado == 0){
        gerado = 1;
    }
    return gerado;
}
void recorde(int pont){
    static int maior_pont=0;
    if(maior_pont < pont){
        maior_pont = pont;
    }
    cout<<"Sua pontuacao na rodada foi :"<<pont<<endl;
    cout<<"Seu record atual eh :"<<maior_pont<<endl;
}
void jogo(){
    int pont_atual = 0;
    cout<<"Cartas sorteadas :";
    for(int i=0;i<3;i++){
        int x = compra_carta();
        cout<<x<<" ";
        pont_atual = pont_atual + x;
    }
    cout<<endl;
    while(true){
        if(pont_atual > 21){
            cout<<"Voce perdeu !!!"<<endl;
            recorde(0);
            break;
        }
        else if(pont_atual == 21){
            cout<<"Parabens voce venceu !"<<endl;
            recorde(21);
            break;
        }
        else{
            char r;
            cout<<"Voce esta com "<<pont_atual<<" pontos ! Deseja pegar mais uma carta ?[S]/[N]:";
            cin>>r;
            if(r == 'S'){
                int i = compra_carta();
                cout<<"Carta comprada : "<<i<<endl;
                pont_atual = pont_atual + i;
            }
            else{
                cout<<"Voce venceu !!!"<<endl;
                recorde(pont_atual);
                break;
            }
        }
    }
}
