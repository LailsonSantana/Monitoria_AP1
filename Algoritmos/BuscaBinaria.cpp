#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
void ordena(int vetor[],int tam);
int buscaBinaria(int vetor[],int tam,int chave);
int main()
{
    srand(time(0));
    int chave;
    int tam = 20;
    int vetor[tam];

    for(int i=0;i<tam;i++){ //Gerei os valores para que fosse mais fácil testar o código
        vetor[i] = rand() % 36;
    }

    ordena(vetor,tam);


     for(int i=0;i<tam;i++){
        cout<<setw(3)<<i<<" ";
    }
    cout<<endl;

    for(int i=0;i<tam;i++){
        cout<<setw(3)<<vetor[i]<<" ";
    }
    cout<<endl;

    cout<<"Informe a chave que vc quer procurar :";
    cin>>chave;

    cout<<buscaBinaria(vetor,tam,chave);


    return 0;
}
void ordena(int vetor[],int tam){
    for(int i=0;i<tam;i++){
        for(int k=i+1;k<tam;k++){
            if(vetor[i] > vetor[k]){
                int temp = vetor[i];
                vetor[i] = vetor[k];
                vetor[k] = temp;
            }
        }
    }
}

int buscaBinaria(int vetor[],int tam,int chave){
    int inicio = 0;
    int fim = tam;
    int meio=1;
    int posicao = -1; // Se o algoritmo retornar -1 significa que o valor não foi encontrado
    int k = 0;//Criei essa variável para que seja possível o algoritmo parar o loop
    while(k != meio){
        k = meio;
        meio = (inicio + fim) / 2;
        if(vetor[meio] == chave){
            posicao = meio;
            break;
        }
        else if(vetor[meio] > chave){
            fim = meio;
        }
        else{
            inicio = meio;
        }
    }
    return posicao;
}
