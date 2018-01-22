#include <iostream>
using namespace std;

class Perceptron{
  public:
    double eta;   // Tasa de aprendizaje
    int n_iter;   // Numero de iteraciones
  void fit(float *X,float *y,int n,int m){//dataset, Real , # samples,features
    float W[m+1]={0}; // Vector de pesos
    int  Errors[n_iter]={0}; // VEctor de errores
    for (int ii=0; ii<n_iter; ii++){
      for (int kk=0; kk<n ; kk++ ){
        float xi[m]={0};
        for (int jj=0;jj<m;jj++){
          xi[jj]=X[kk][jj];
        }
        float update=eta * (y[kk] - predict(xi)) ;
        W[0]+=update;
        for (int jj=1;jj<m+1;jj){
          W[jj]+=update*xi[jj-1];
          Errors[ii]+= int(update!=0);
        }
      }
    }
  }
  float  net_input(float *X,float *W){
    float z=W[0];
    for(int kk=1;kk<m+1;kk++){
      z+=X[kk-1]*W[kk];
    }
    return z;
  }
  int predict(float *X, float *W){
    if (net_input(X,W)>=0){
      return 1;
    }
    return -1;
  }
}
