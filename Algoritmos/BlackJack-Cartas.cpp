/*(1) Crie um jogo 21 (BlackJack) em C++. Existe uma infinidade de formas de se jogar 21; o objetivo sempre
é formar 21 pontos com cartas (ou chegar o mais próximo possível). O nosso jogo será uma versão
simplificada, para um jogador solitário. Ele deve ter a chance de permanecer no jogando uma rodada
após a outra até decidir parar. Veja as regras:
1. Valor das cartas: todas as cartas com figura (valete, dama e rei) valem 10 pontos; o ás, vale 1; e as
demais cartas valem o seu próprio número.

3

2. Incialmente, o jogador recebe 3 cartas (e calcula a soma de pontos).
3. Se a soma de seus pontos der 21, ele já vence no início.
4. Se ele ultrapassar os 21 pontos, já perde no início.
5. Se passar do início, para formar os 21 pontos, o jogador pode “comprar” uma carta do monte,
quantas vezes quiser, e somar os pontos desta carta aos seus pontos atuais. Mas ele deve fazer isso
com cautela. Se em algum momento seus pontos ultrapassarem 21, ele perde o jogo.
6. O jogador deve informar quando quiser para de comprar cartas e encerrar a rodada (caso não tenha
atingido (vence) ou ultrapassado (perde) os 21 pontos. Se ele parar sem atingir os 21, ele deve ver
uma mensagem informando os seus pontos e o recorde atual – o maior número de pontos já atingido
considerando todas as rodadas.
O seu programa deve atender aos seguintes requisitos:
• Use uma função compra_carta que sorteia um número de 1 a 13 representando uma carta
(ás, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, valete, dama, rei) e retorna o número de pontos correspondente
à carta;
• Use uma função recorde que
o registra a pontuação atingida em cada rodada;
o atualiza o recorde, se necessário; e
o mostra essa a pontuação da rodada comparando com o recorde.
DICA: use uma variável estática aqui ??.
• Use uma função jogo que, com a ajuda das funções acima implementa o jogo.
• Chame a função jogo a partir do programa principal provendo nele uma estrutura de repetição
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
