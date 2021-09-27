#include <SPI.h>

int desceu;
int subiu;
int ciclos;
String str;
struct C {
    int subiu;
    int desceu;
    int sobe;
    int desce;
    int reverte;
};
/*C cancela[]={{2, 3, 29, 30, 31},
              {4, 5, 32, 33, 34},
              {6, 7, 35, 36, 37},
              {8, 9, 38, 39, 40},
              {10, 11, 41, 42, 43},
              {12, 13, 44, 45, 46},
              {22, 23, 47, 48, 49},
              {24, 25, 50, 51, 52}
              };*/
/*cancela[0] = {2, 3, 29, 30, 31};
cancela[1] = {4, 5, 32, 33, 34};
cancela[2] = {6, 7, 35, 36, 37};
cancela[3] = {8, 9, 38, 39, 40};
cancela[4] = {10, 11, 41, 42, 43};
cancela[5] = {12, 13, 44, 45, 46};
cancela[6] = {22, 23, 47, 48, 49};
cancela[7] = {24, 25, 50, 51, 52};*/

void setup() {

    pinMode(29, OUTPUT);
    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
    pinMode(3, INPUT);
    pinMode(2, INPUT);

    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(34, OUTPUT);
    pinMode(5, INPUT);
    pinMode(4, INPUT);

    pinMode(35, OUTPUT);
    pinMode(36, OUTPUT);
    pinMode(37, OUTPUT);
    pinMode(7, INPUT);
    pinMode(6, INPUT);

    pinMode(38, OUTPUT);
    pinMode(39, OUTPUT);
    pinMode(40, OUTPUT);
    pinMode(9, INPUT);
    pinMode(8, INPUT);

    pinMode(41, OUTPUT);
    pinMode(42, OUTPUT);
    pinMode(43, OUTPUT);
    pinMode(11, INPUT);
    pinMode(10, INPUT);

    pinMode(44, OUTPUT);
    pinMode(45, OUTPUT);
    pinMode(46, OUTPUT);
    pinMode(13, INPUT);
    pinMode(12, INPUT);

    pinMode(47, OUTPUT);
    pinMode(47, OUTPUT);
    pinMode(49, OUTPUT);
    pinMode(23, INPUT);
    pinMode(22, INPUT);

    pinMode(50, OUTPUT);
    pinMode(51, OUTPUT);
    pinMode(52, OUTPUT);
    pinMode(25, INPUT);
    pinMode(24, INPUT);

    Serial.begin(9600);
    Serial.print("start\r\n");
}


void loop() {
    C cancela[7];
    cancela[0] =   {2, 3, 29, 30, 31};
    cancela[1] =   {4, 5, 32, 33, 34};
    cancela[2] =   {6, 7, 35, 36, 37};
    cancela[3] =   {8, 9, 38, 39, 40};
    cancela[4] = {10, 11, 41, 42, 43};
    cancela[5] = {12, 13, 44, 45, 46};
    cancela[6] = {22, 23, 47, 48, 49};
    cancela[7] = {24, 25, 50, 51, 52};

    if (Serial.available()) {
        str = Serial.readStringUntil('\n');
        if (str != "") {
            ciclos = str.substring(str.indexOf(" ") + 1).toInt();
            if (ciclos > 0) {
                for (int i = 0; i < ciclos; i++) {
                    sobeTudo(300);
                    Serial.println("");
                    //while(checkSubiu()==false){}
                    desceTudo(300);
                    Serial.println("");
                    //while(checkDesceu()==false){}
                    sobeTudo(300);
                    Serial.println("");
                    delay(1500);
                    reverteTudo(300);
                    Serial.println("");
                    //while(checkSubiu()==false){}
                    desceTudo(300);
                    Serial.println("");
                    delay(1500);
                    reverteTudo(300);
                    Serial.println("");
                    //while(checkDesceu()==false){}*/
                }
            }
        }
    }
}
void sobe(C cancela,int tempo){
  //digitalWrite(cancela.sobe, HIGH);
  //delay(tempo);
  //digitalWrite(cancela.sobe, LOW);
  Serial.println("Subindo"+ cancela.sobe);
}

void desce(C cancela,int tempo){
  digitalWrite(cancela.desce, HIGH);
  delay(tempo);
  digitalWrite(cancela.desce, LOW);
}

void reverte(C cancela,int tempo){
  digitalWrite(cancela.reverte, HIGH);
  delay(50);
  digitalWrite(cancela.reverte, LOW);
  delay(tempo);
  digitalWrite(cancela.reverte, LOW);
  delay(50);
  digitalWrite(cancela.reverte, HIGH);
}

void sobeTudo(int tempo){
    C cancela[8];
  cancela[0] = {2, 3, 29, 30, 31};
  cancela[1] = {4, 5, 32, 33, 34};
  cancela[2] = {6, 7, 35, 36, 37};
  cancela[3] = {8, 9, 38, 39, 40};
  cancela[4] = {10, 11, 41, 42, 43};
  cancela[5] = {12, 13, 44, 45, 46};
  cancela[6] = {22, 23, 47, 48, 49};
  cancela[7] = {24, 25, 50, 51, 52};
  cancela[8] = {0, 0, 0, 0, 0};
  int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  for(int i=0;i<arrSize;i++){
    digitalWrite(cancela[i].sobe, HIGH);
    delay(tempo);
    digitalWrite(cancela[i].sobe, LOW);
    Serial.println(cancela[i].sobe);
  }
  
}

void desceTudo(int tempo){
    C cancela[8];
  cancela[0] = {2, 3, 29, 30, 31};
  cancela[1] = {4, 5, 32, 33, 34};
  cancela[2] = {6, 7, 35, 36, 37};
  cancela[3] = {8, 9, 38, 39, 40};
  cancela[4] = {10, 11, 41, 42, 43};
  cancela[5] = {12, 13, 44, 45, 46};
  cancela[6] = {22, 23, 47, 48, 49};
  cancela[7] = {24, 25, 50, 51, 52};
  cancela[8] = {0, 0, 0, 0, 0};
  int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  for(int i=0;i<arrSize;i++){
  digitalWrite(cancela[i].desce, HIGH);
    delay(tempo);
    digitalWrite(cancela[i].desce, LOW);
    Serial.println(cancela[i].desce);
  }
}

void reverteTudo(int tempo){
    C cancela[8];
  cancela[0] = {2, 3, 29, 30, 31};
  cancela[1] = {4, 5, 32, 33, 34};
  cancela[2] = {6, 7, 35, 36, 37};
  cancela[3] = {8, 9, 38, 39, 40};
  cancela[4] = {10, 11, 41, 42, 43};
  cancela[5] = {12, 13, 44, 45, 46};
  cancela[6] = {22, 23, 47, 48, 49};
  cancela[7] = {24, 25, 50, 51, 52};
  cancela[8] = {0, 0, 0, 0, 0};
  int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  for(int i=0;i<arrSize;i++){
    digitalWrite(cancela[i].reverte, HIGH);
    delay(tempo);
    digitalWrite(cancela[i].reverte, LOW);
    Serial.println(cancela[i].reverte);
  }
}

int checkSubiu(){
    C cancela[7];
  cancela[0] = {2, 3, 29, 30, 31};
  cancela[1] = {4, 5, 32, 33, 34};
  cancela[2] = {6, 7, 35, 36, 37};
  cancela[3] = {8, 9, 38, 39, 40};
  cancela[4] = {10, 11, 41, 42, 43};
  cancela[5] = {12, 13, 44, 45, 46};
  cancela[6] = {22, 23, 47, 48, 49};
  cancela[7] = {24, 25, 50, 51, 52};
  int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  if(cancela[0].subiu == true && cancela[1].subiu == true && cancela[2].subiu == true && cancela[3].subiu == true && cancela[4].subiu == true && cancela[5].subiu == true && cancela[6].subiu == true && cancela[7].subiu == true){
    return 1;
  }else{
      return 0;
  }
}
int checkDesceu(){
    C cancela[7];
  cancela[0] = {2, 3, 29, 30, 31};
  cancela[1] = {4, 5, 32, 33, 34};
  cancela[2] = {6, 7, 35, 36, 37};
  cancela[3] = {8, 9, 38, 39, 40};
  cancela[4] = {10, 11, 41, 42, 43};
  cancela[5] = {12, 13, 44, 45, 46};
  cancela[6] = {22, 23, 47, 48, 49};
  cancela[7] = {24, 25, 50, 51, 52};
  int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  if(cancela[0].desceu == true && cancela[1].desceu == true && cancela[2].desceu == true && cancela[3].desceu == true && cancela[4].desceu == true && cancela[5].desceu == true && cancela[6].desceu == true && cancela[7].desceu == true){
    return 1;
  }else{
      return 0;
  }
}
