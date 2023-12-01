#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int lin1, col1;
    cout << "Insira o numero de linhas da primeira matriz: ";
    cin >> lin1;
    cout << "Insira o numero de colunas da primeira matriz: ";
    cin >> col1;


    int lin2, col2;
    cout << "Insira o numero de linhas da segunda matriz: ";
    cin >> lin2;
    cout << "Insira o numero de colunas da segunda matriz: ";
    cin >> col2;

    if(col1 != lin2){
        cout << "O numero de colunas da primeira matriz deve ser igual ao numero de linhas da segunda";
        return 1;
    }

    float matriz1[lin1][col1], matriz2[lin2][col2];

    cout << "Insira os dados da primeira matriz" << endl;
    for(int i=0; i<lin1; i++){
        for(int j=0; j<col1; j++){
            cin >> matriz1[i][j];
        }
    }

    cout << "Insira os dados da segunda matriz" << endl;
    for(int i=0; i<lin2; i++){
        for(int j=0; j<col2; j++){
            cin >> matriz2[i][j];
        }
    }

    float matrizResultado[lin1][col2];
    for(int i=0; i<lin1; i++){
        for(int j=0; j<col2; j++){
            float somaMult=0;
            for(int k=0; k<col1; k++){
                somaMult = somaMult + (matriz1[i][k] * matriz2[k][j]);
            }
            matrizResultado[i][j] = somaMult;
        }
    }

    cout << "Matriz Resultado:\n";
    for(int i=0; i<lin1; i++){
        for(int j=0; j<col2; j++){
            cout << setw(3) << matrizResultado[i][j] << " ";
        }
        cout << endl;
    }

}