/*(23) Faça uma função MAX que recebe como entrada um inteiro n, uma matriz inteira Am×n e devolve três
inteiros: k, Lin e Col. O inteiro k é o maior elemento de A e é igual a A[Lin,Col].
Por exemplo, se A = [3 7 1 1 2 8 5 3 4 ] então k = 8; Lin = 1; Col = 2 .
Obs.: Se o elemento máximo ocorrer mais de uma vez, indique em Lin e Col qualquer uma das possíveis
posições.
Faça um programa que, dado um inteiro n e uma matriz quadrada de ordem n, cujos elementos são todos
inteiros positivos, imprime uma tabela onde os elementos são listados em ordem decrescente, acompanhados
da indicação de linha e coluna a que pertencem. Havendo repetições de elementos na matriz, a ordem é
irrelevante. Utilize, obrigatoriamente, a função MAX. */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
const int tam = 20;
void MAX(int[][tam], int, int, int &, int &, int &);

int main(){
    srand(time(0));


	int Ma[tam][tam];
	int n = 3;
	int m = 3;
	int k = 0;
	int lin = 0; int col = 0;

	cout << "\nDigite os elementos da matriz" << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			 Ma[i][j] = rand() % 31; // Aqui eu gerei os elementos pra facilitar os testes
			}
		}
    cout<<endl;
    cout<<"Matriz gerada"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<Ma[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int x  = n * m; // A quantidade de vezes que vou chamar a função corresponde a quantidade
    // de elementos que existe na matriz
    cout<<setw(3)<<"Ele"<<setw(3)<<" Linha"<<setw(3)<<" Col";
    cout<<endl;
	for(int i=0;i<x;i++){
        MAX (Ma,  n,  m,  k,  lin,  col);
        cout<<setw(3)<<k<<" "<<setw(3)<<lin<<" "<<setw(3)<<col<<" ";
        cout<<endl;
	}


	return 0;
}


void MAX(int Ma[][tam], int n, int m, int &k, int &lin, int &col){
    int maior = -2;
	for(int i = 0; i < n; i++){
		for(int g = 0; g < m; g++){
			if(Ma[i][g] > maior){
				maior = Ma[i][g];
				lin = i;
				col = g;
			}
		}
	}
	k = maior;
	Ma[lin][col] = -1;
}
