/*(24) Escreva uma fun��o que recebe como par�metros uma matriz de caracteres NOMES m�n , os �ndices i e j
de duas linhas e que troca os elementos da linha i com os da linha j.
Escreva uma fun��o que recebe como par�metros uma matriz NOMES m�n, os �ndices i e j de duas linhas e
que devolve valor 1 se o nome na linha i � maior ou igual ao da linha j (ordem alfab�tica) e 0 caso contr�rio.
S�o dados n nomes que ser�o armazenados em uma matriz NOMESm�n. Coloque os nomes dessa matriz em
ordem alfab�tica usando as fun��es descritas acima.*/




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
            nomes[i][k] = nomes1[rand()%12]; // Gerei os nomes para n�o ter que escrever
        }
    }

    for(int i=0;i<tam1;i++){ // teste pra ver se os nomes est�o sendo impressos corretamente
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
