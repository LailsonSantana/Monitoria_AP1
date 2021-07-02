/*(3) Escreva um programa que recebe 50 valores inteiros positivos do teclado e armazena 25 desses
valores no vetor A e 25 no vetor B. Em seguida, deve chamar uma função que recebe os dois
vetores como argumentos e preenche um terceiro vetor, C, que é a intersecção de A e B.*/

#include <iostream>

using namespace std;
void interseccao(int A[] ,int B[] ,int C[],int tam);
int tamInt(int A[],int B[],int tam);
int main()
{
    int tam=50;
    int A[tam];
    int B[tam];

    cout<<"Informe os valores do vetor A :";
    for(int i=0;i<tam;i++){
        cin>>A[i];
    }
    cout<<endl;
    cout<<"Informe os valores do vator B :";
    for(int i=0;i<tam;i++){
        cin>>B[i];
    }
    cout<<endl;
    int t = tamInt(A,B,tam);
    int C[t];

    interseccao(A,B,C,tam);


    cout<<"Os valores do vetor interseccao sao :";
    for(int i=0;i<t;i++){
        cout<<C[i]<<" ";
    }
    cout<<endl;


    return 0;
}
void interseccao(int A[],int B[],int C[],int tam){
    int cont = 0;
    for(int i=0;i<tam;i++){
        for(int k=0;k<tam;k++){
            if(A[i] == B[k]){
                C[cont] = A[i];
                cont = cont + 1;
                break;
            }
        }
    }
}

// Fiz essa função somente para verificar a quantidade de elementos que tem no vetor A
// e também tem no vetor b , mas seria possível resolver o problema sem ela , basicamente ela
// seria uma forma de resolver esse algoritmo se a descrição do problema fosse mais restrita
int tamInt(int A[],int B[],int tam){
    int cont = 0;
    for(int i=0;i<tam;i++){
        for(int k=0;k<tam;k++){
            if(A[i] == B[k]){
                cont = cont + 1;
                break;
            }
        }
    }
    return cont;
}
