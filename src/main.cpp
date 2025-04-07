#include <Arduino.h>
// 1) realizar dos semaforo utilizando matrices y arrays 
// 2) cambiar los delays por millis
int t_anterior1=0;
int t_anterior2=0;
int t_delayvr=10000;
int t_delaya=4000;
int pines1[3]={1,2,3};
int pines2[3]={4,5,6};
int sem1[4][3]{
  {1,0,0},
  {1,1,0},
  {0,0,1},
  {0,1,0}
};
int sem2[4][3]{
  {0,0,1},
  {0,1,0},
  {1,0,0},
  {1,1,0}
};
void setup() {
  for(int p=0;p<2;p++){
    pinMode(pines1[p],OUTPUT);
    pinMode(pines2[p],OUTPUT);
  }
}
void loop() {
  int t_actual=millis();
  for(int j=0; j<3; j++){
    if(sem1[j][1]==1||sem2[j][1]==1){
      for (int i=0; i<4; i++){
        if(t_actual-t_anterior1 >= t_delaya){ //si la resta entre tiempo actual(0) y tiempo anterior es menor a lo requerido (1500) se saltea esta orden
          t_anterior1 = t_actual;             //si es mayor o igual funciona bien y al terminar de ejecutar todo se igualan los tiempos haciendo que se saltee la orden
          digitalWrite(pines1[j], sem1[i][j]);
          digitalWrite(pines2[j], sem2[i][j]);
        } 
      }
    }else{
      for (int i=0; i<4; i++){
        if(t_actual-t_anterior2 >= t_delayvr){
            t_anterior2 = t_actual;
            digitalWrite(pines1[j], sem1[i][j]);
            digitalWrite(pines2[j], sem2[i][j]);
        }
      }
    }
    
  }
}