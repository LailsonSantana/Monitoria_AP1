/*(1) Escreva um programa para jogar pedra-papel-tesoura com o computador. O seu programa deve pedir
ao jogador para escolher entre pedra, papel e tesoura (um número entre 1 e 3, inclusive). Em seguida,
um número aleatório entre 1 e 3 (inclusive) deve ser gerado para representar a jogada do computador.
O programa então deve dizer quem ganhou e perguntar se o jogador quer outra rodada. Caso ele
informe que sim, o processo se repete. Um placar também deve ser mantido e apresentado pelo
programa.
REGRAS DO JOGO:


PAPEL enrola PEDRA TESOURA corta PAPEL PEDRA quebra TESOURA
isto é:
PAPEL vence PEDRA; TESOURA vence PAPEL; PEDRA vence TESOURA.
RESTRIÇÕES:
1. O programa deve chamar as seguintes funções:
-> jogo
-solicita ao jogador que escolha pedra-papel-tesoura (1 para pedra, 2 para papel e 3 para tesoura);
- chama a função jogada_computador.
- verifica quem ganhou a rodada e retorna 'j' para jogador e 'c' para computador.
- mostra a jogada de cada um (jogador e computador);
-> jogada_computador
- gera um número aleatório entre 0 e 10 e retorna esse número.
-> placar
- recebe o ganhador da rodada (j ou c);
- mostra o vencedor da rodada (jogador ou computador);
- atualiza e mostra o placar.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int jogada_computador();
void jogo();
void placar(char vencedor);
int main()
{

    srand(time(0));

    jogo();

    return 0;
}
int jogada_computador(){
    int gerador = (rand() % 3) + 1;

    return gerador;
}
void jogo(){

    int op;
    int comp;
    char vencedor,rdd;

    while(true){
        cout<<"Pedra papel ou tesoura ?"<<endl;
        cout<<"1 - Pedra "<<endl;
        cout<<"2 - Papel "<<endl;
        cout<<"3 - Tesoura "<<endl;
        cin>>op; // Numero da gente
        comp = jogada_computador(); // Numero gerado

        if(op == comp){
            vencedor = 'e';
        }
        else if(op == 1 && comp == 2){
            vencedor = 'c';
        }
        else if(op == 1 && comp == 3){
            vencedor = 'j';
        }
        else if(op == 2 && comp == 1){
            vencedor = 'j';
        }
        else if(op == 2 && comp == 3){
            vencedor = 'c';
        }
        else if(op == 3 && comp == 1){
            vencedor = 'c';
        }
        else{
            vencedor = 'j';
        }
        cout<<"Sua jogada "<<op<<endl;
        cout<<"Jogada computador "<<comp<<endl;
        placar(vencedor);
        cout<<endl;
        cout<<"Mais uma rodada [S]/[N] ? :";
        cin>>rdd;
        if(rdd == 'N'){
            break;
        }
        cout<<endl;
    }

}
void placar(char vencedor){
    static int cont_comp = 0;
    static int cont_jogador = 0;
    if(vencedor == 'c'){
        cout<<"Vencedor da rodada : computador"<<endl;
        cont_comp = cont_comp + 1;
    }
    else if(vencedor == 'j'){
        cout<<"Vencedor da rodada : voce"<<endl;
        cont_jogador = cont_jogador + 1;
    }
    else{
        cout<<"Empate"<<endl;
    }
    cout<<"----------PLACAR---------------"<<endl;
    cout<<"Voce : "<<cont_jogador;
    cout<<"        Computador :"<<cont_comp;
}
