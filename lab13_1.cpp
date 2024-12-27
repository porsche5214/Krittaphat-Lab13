#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum1 , sum2 , sum3 = 1 , sum4 ;
    double max = 0 , min = 20 ;
    for (int i = 0 ; i < N ; i ++){
        sum1 += A[i] ;
        sum3 *= A[i] ;
        sum4 += 1 / A[i] ;
    }
    B[0] = sum1 / N ;

    for (int j = 0 ; j < N ; j ++){
        if (A[j] > max){
            max = A[j] ;
        }
        if (A[j] < min){
            min = A[j] ;
        }
    }
    
    for (int k = 0 ; k < N ; k ++){
        sum2 += pow(A[k] - B[0] , 2) / N ;
    }
    
    B[1] = sqrt(sum2) ;
    B[2] = pow (sum3 , 1.0/N) ;
    B[3] = N / sum4 ;
    B[4] = max ;
    B[5] = min ;
}