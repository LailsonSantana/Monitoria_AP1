/*(24) Escreva uma função que recebe como parâmetros uma matriz de caracteres NOMES m×n , os índices i e j
de duas linhas e que troca os elementos da linha i com os da linha j.
Escreva uma função que recebe como parâmetros uma matriz NOMES m×n, os índices i e j de duas linhas e
que devolve valor 1 se o nome na linha i é maior ou igual ao da linha j (ordem alfabética) e 0 caso contrário.
São dados n nomes que serão armazenados em uma matriz NOMESm×n. Coloque os nomes dessa matriz em
ordem alfabética usando as funções descritas acima.*/




#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
const int tam = 10;
void troca(string nomes[][tam],int i,int j,int k,int l);
int maior(string nomes[][tam],int i,int j,int k,int l);
int main()
{

    srand(time(0));
    string nomes1[12] = {"lai","ama","ped","car","mar","jes","yas","rog","vil","san","jos","men"};
    // Lista de nomes que podem ser gerados
    int tam1 = 3;
    string nomes[tam][tam];

    for(int i=0;i<tam1;i++){
        for(int k=0;k<tam1;k++){
            nomes[i][k] = nomes1[rand()%12]; // Gerei os nomes para não ter que escrever
        }
    }

    for(int i=0;i<tam1;i++){ // teste pra ver se os nomes estão sendo impressos corretamente
        for(int k=0;k<tam1;k++){
            cout<<setw(3)<<nomes[i][k]<<" ";
        }
    cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<tam1;i++){
        for(int k=0;k<tam1;k++){
            for(int a=0;a<tam1;a++){
                for(int b=0;b<tam1;b++){
                    if(maior(nomes,i,k,a,b) == 1){
                        troca(nomes,i,k,a,b);
                    }

                }
            }
        }
    }
    cout<<endl;
    for(int i=0;i<tam1;i++){
        for(int k=0;k<tam1;k++){
            cout<<setw(3)<<nomes[i][k]<<" ";
        }
    cout<<endl;
    }


    return 0;
}
void troca(string nomes[][tam],int i,int j,int k,int l){

    string temp = nomes[i][j];
    nomes[i][j] = nomes[k][l];
    nomes[k][l] = temp;
}
int maior(string nomes[][tam],int i,int j,int k,int l){
    if(nomes[i][j] < nomes[k][l]){
        return 1;
    }
    else{
        return 0;
    }
}
