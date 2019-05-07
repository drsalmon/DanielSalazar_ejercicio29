#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
  double C=0.5;  
  double t_max = 6;
  double delta_t = 0.01;
  double t;
  double L =1.0;
  double delta_x = 0.01;
  double C_prima;
  double antiguo[100][100];
  double nuevo[100][100];
  int i, j;
  int iteracion=0;
  ofstream outfile;

  for (i=0; i<100; i++){
      for (j = 0; j<=5; j++){
       antiguo[i][i] = 0.0;
      }
  }
  
  C_prima = delta_x/delta_t;
    
  outfile.open("ejemplo.dat");
  while(t < t_max){
     for(i=1;i<=100;i++){
       nuevo[i][j] = antiguo[i][1] + (C*C/(2*(C_prima*C_prima))) * (antiguo[i+1][1]+antiguo[i-1][1]-2.0*antiguo[i][1]);
     }      
     for(i=0;i<100;i++){
       outfile << nuevo[i][i] << " ";
     }
     outfile << "\n";

     for(i=1;i<99;i++){
       antiguo[i][j] = nuevo[i][j];
     }
     t = t + delta_t;
  }
  outfile.close();
  return 0;
}
      
 