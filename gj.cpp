#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const int TAM_MAX = 10; // Tamanho max para a matriz

void gaussJordan(double matriz[TAM_MAX][TAM_MAX + 1], int n) {
    for (int i = 0; i < n; i++) {
        int pivo = i;

        for (int j = i + 1; j < n; j++){
            if (fabs(matriz[j][i]) > fabs(matriz[pivo][i])){
                pivo = j;
            }
        }
            
        for (int k = 0; k <= n; k++) {
            double aux = matriz[i][k];
            matriz[i][k] = matriz[pivo][k];
            matriz[pivo][k] = aux;
        }

        double divisor = matriz[i][i];
        for (int j = 0; j <= n; j++){
            matriz[i][j] /= divisor;
        }

        for (int j = 0; j < n; j++){
            if (j != i) {
                double multiplier = matriz[j][i];
                for (int k = 0; k <= n; k++){
                    matriz[j][k] -= multiplier * matriz[i][k];
                }      
            }
        }
    }
}

void input(double matriz[TAM_MAX][TAM_MAX + 1], int &n) {
    int tipoInput;

    cout << "1. Entrada por arquivo (input1.txt, caso de teste pronto)\n";
    cout << "2. Entrada manual\n";
    cout << "Insira o tipo de entrada: ";
    cin >> tipoInput;

    if(tipoInput == 1){
        ifstream input("input1.txt");

        if(!input.is_open()){
            cout << "Erro ao abrir arquivo";
            exit(1);
        }

        input >> n;

        for (int i = 0; i < n; i++){
            for (int j = 0; j <= n; j++){
                input >> matriz[i][j];
            }
        }

        input.close();

    } else {
        cout << "Insira o tamanho da matriz: ";
        cin >> n;

        cout << "Insira os elementos da matriz aumentada:\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= n; j++){
                cin >> matriz[i][j];
            }
        }
    }
}

int main() {
    int n;
    double matriz[TAM_MAX][TAM_MAX + 1];

    input(matriz, n);
    gaussJordan(matriz, n);

    cout << "Solucao:\n";
    for (int i = 0; i < n; i++){
        cout << "x" << i + 1 << " = " << matriz[i][n] << endl;
    }
        
    return 0;
}
