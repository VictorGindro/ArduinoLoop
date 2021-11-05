#include <SPI.h>
int quantidade;
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

//status aberto azul
//status fechado marrom
//comum status branco/azul
//abre branco/marrom
//fecha verde
//cumum abrir branco/verde
//closing laranja/branco laranja
//comum subir/descer branco/verde
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
    pinMode(48, OUTPUT);
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
    Serial.println("iniciando reconhecimento de cancelas, espere um momento por favor :D");
    quantidade = getCancelas();
    Serial.println("Reconhecimento terminado");
    Serial.println("Quantidade de cancelas: "+quantidade);
    if (Serial.available()) {
      /*Codigo para testar somente o sensor da cancela 1
       * str = Serial.readStringUntil('\n');
        if (str != "") {
          ciclos = str.substring(str.indexOf(" ") + 1).toInt();
            if (ciclos > 0) {
              Serial.println(digitalRead(cancela[0].subiu));
            }
        }
    }*/
    Serial.println("Digite a quantidade de ciclos a ser executado");
        str = Serial.readStringUntil('\n');
        if (str != "") {
            ciclos = str.substring(str.indexOf(" ") + 1).toInt();
            if (ciclos > 0) {
                for (int i = 0; i < ciclos; i++) {
                  Serial.println("Inicio do ciclo "+ ciclos+1);
                    Serial.println("Subindo todos os braços.");
                    sobeTudo(2600, quantidade);
                    if(checkSubiu(quantidade)==true){
                    Serial.println("Subiu");
                    Serial.println("Descendo todos os braços.");
                    desceTudo(2600,quantidade);
                    if(checkDesceu(quantidade)==true){
                    Serial.println("Desceu");
                    Serial.println("Subindo todos os braços.");
                    sobeTudo(2600,quantidade);
                    //reverte(cancela[0],300); fazer o metedo de revers'ao sem o closing
                    if(checkSubiu(quantidade)==true){
                    Serial.println("Subiu");
                    Serial.println("Descendo e revertendo todos os braços.");
                    desceTudo(100,quantidade);
                    reverteTudo(2500,quantidade);
                    if(checkDesceu(quantidade)==true){
                    Serial.println("Desceu");
                    Serial.println("Subindo braços para posição final");
                    sobeTudo(2600,quantidade); 
                    }
                    }
                    }
                    }
                }
                Serial.println("Fim do ciclo "+ ciclos+1);
            }
        }
    }
}

void sobe(C cancela,int tempo){
  digitalWrite(cancela.sobe, HIGH);
  delay(tempo);
  digitalWrite(cancela.sobe, LOW);
}

void desce(C cancela,int tempo){
  digitalWrite(cancela.desce, HIGH);
  delay(tempo);
  digitalWrite(cancela.desce, LOW);
}

void reverte(C cancela,int tempo){
  digitalWrite(cancela.reverte, HIGH);
  delay(tempo);
  digitalWrite(cancela.reverte, LOW);

}

bool checkS(C cancela){
  if(digitalRead(cancela.subiu)==false){
    return true;
  }else{
      return false;
  }
}
bool checkD(C cancela){
  if(digitalRead(cancela.desceu)==false){
    return true;
  }else{
      return false;
  }
}

int getCancelas (){
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
  int confirmadas = 0;
  int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  for(int i=0;i<arrSize;i++){
    sobe(cancela[i],200);
    delay(2600);
    bool s = checkS(cancela[i]);
    desce(cancela[i],200);
    delay(2600);
    bool d = checkD(cancela[i]);
    if(s == true && d==true){
      confirmadas++;
    }
  }
  return confirmadas;
}

void sobeTudo(int tempo,int quantidade){
    C cancela[8];
  cancela[0] = {2, 3, 29, 30, 31};
  cancela[1] = {4, 5, 32, 33, 34};
  cancela[2] = {6, 7, 35, 36, 37};
  cancela[3] = {8, 9, 38, 39, 40};
  cancela[4] = {10, 11, 41, 42, 43};
  cancela[5] = {12, 13, 44, 45, 46};
  cancela[6] = {22, 23, 47, 48,49};
  cancela[7] = {24, 25, 50, 51, 52};
  cancela[8] = {0, 0, 0, 0, 0};
  //int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  for(int i=0;i<quantidade;i++){
    digitalWrite(cancela[i].sobe, HIGH);
  }
    delay(200);
  for(int i=0;i<quantidade;i++){
    digitalWrite(cancela[i].sobe, LOW);
    //Serial.println(cancela[i].sobe);
  }
      delay(tempo);
}

void desceTudo(int tempo,int quantidade){
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
 // int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  for(int i=0;i<quantidade;i++){
  digitalWrite(cancela[i].desce, HIGH);
  }
  delay(200);
  for(int i=0;i<quantidade;i++){
    digitalWrite(cancela[i].desce, LOW);
  }
      delay(tempo);
}

void reverteTudo(int tempo, int quantidade){
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
  //int arrSize = sizeof(cancela)/sizeof(cancela[0]);
  for(int i=0;i<quantidade;i++){
    digitalWrite(cancela[i].reverte, HIGH);
  }
    delay(250);
  for(int i=0;i<quantidade;i++){ 
    digitalWrite(cancela[i].reverte, LOW);
   // Serial.println(cancela[i].reverte);
  }
      delay(tempo);
}

int checkSubiu(int quantidade){
    C cancela[7];
  cancela[0] = {2, 3, 29, 30, 31};
  cancela[1] = {4, 5, 32, 33, 34};
  cancela[2] = {6, 7, 35, 36, 37};
  cancela[3] = {8, 9, 38, 39, 40};
  cancela[4] = {10, 11, 41, 42, 43};
  cancela[5] = {12, 13, 44, 45, 46};
  cancela[6] = {22, 23, 47, 48, 49};
  cancela[7] = {24, 25, 50, 51, 52};
  int confirmadas;
  for(int i=0;i<quantidade;i++){
    bool s = checkS(cancela[i]);
    if(s == true){
      confirmadas++;
    }
  }
  if(confirmadas == quantidade){    
    return true;
  }else{
      return false;
  }
}
int checkDesceu(int quantidade){
    C cancela[7];
  cancela[0] = {2, 3, 29, 30, 31};
  cancela[1] = {4, 5, 32, 33, 34};
  cancela[2] = {6, 7, 35, 36, 37};
  cancela[3] = {8, 9, 38, 39, 40};
  cancela[4] = {10, 11, 41, 42, 43};
  cancela[5] = {12, 13, 44, 45, 46};
  cancela[6] = {22, 23, 47, 48, 49};
  cancela[7] = {24, 25, 50, 51, 52};
  int confirmadas;
  for(int i=0;i<quantidade;i++){
    bool d = checkD(cancela[i]);
    if(d == true){
      confirmadas++;
    }
  }
  if(confirmadas == quantidade){    
    return true;
  }else{
      return false;
  }
}
