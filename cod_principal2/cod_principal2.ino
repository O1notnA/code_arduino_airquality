
#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

File myFile;
File root;

LiquidCrystal_I2C lcd(0x27,16,2);


 
  const int pinoSS = 10;

  const int g_btn = 2;
  const int y_btn = 3;
  const int r_btn = 4;
  const int b_btn = 5;
  int op = 0; 


 

void val(){
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Valor do sensor:");
  lcd.setCursor(0,1);
  lcd.print("XXX");
  delay(500);
}

void val2(){


  /*
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Valor do sensor:");
  lcd.setCursor(0,1);
  lcd.print("XXX2");
  delay(500);
  */
}

void val3(){
  
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Valor do sensor:");
  lcd.setCursor(0,1);
  lcd.print("XXX3");
  delay(500);
}

void val4(){
  
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Valor do sensor:");
  lcd.setCursor(0,1);
  lcd.print("XXX4");
  delay(500);
}

void checkSD(){
   if (SD.begin()) {
    lcd.setBacklight(HIGH);
    lcd.setCursor(1,0);
    lcd.print("Cartao SD, OK!");
    delay(3500);
    op = 1;
  }
  else {
    lcd.setBacklight(HIGH);
    lcd.setCursor(0,0);
    lcd.print("Falha de comunicacao no Cartao SD");
    lcd.autoscroll();
    return;
  }
}


void setup() { 
  pinMode(g_btn, INPUT_PULLUP);
  pinMode(y_btn, INPUT_PULLUP);
  pinMode(r_btn, INPUT_PULLUP);
  pinMode(b_btn, INPUT_PULLUP);
  lcd.init();
  
Serial.begin(9600); // Define BaundRate

 

/*
pinMode(pinoSS, OUTPUT); // Declara pinoSS como saída

 
  if (SD.begin()) { // Inicializa o SD Card
    Serial.println("SD Card pronto para uso."); // Imprime na tela
  }
  else {
    Serial.println("Falha na inicialização do SD Card.");
    return;
  }
 
myFile = SD.open("usina.txt", FILE_WRITE); // Cria / Abre arquivo .txt
 
  if (myFile) { // Se o Arquivo abrir imprime:
    Serial.println("Escrevendo no Arquivo .txt"); // Imprime na tela
    myFile.println("Usinainfo 1, 2 ,3 ..."); // Escreve no Arquivo
    myFile.close(); // Fecha o Arquivo após escrever
    Serial.println("Terminado."); // Imprime na tela
    Serial.println(" ");
  }
  else {     // Se o Arquivo não abrir
    Serial.println("Erro ao Abrir Arquivo .txt"); // Imprime na tela
  }
 
myFile = SD.open("usina.txt"); // Abre o Arquivo
 
  if (myFile) {
    Serial.println("Conteúdo do Arquivo:"); // Imprime na tela
 
    while (myFile.available()) { // Exibe o conteúdo do Arquivo
      Serial.write(myFile.read());
    }
    myFile.close(); // Fecha o Arquivo após ler
  }
 
  else {
    Serial.println("Erro ao Abrir Arquivo .txt"); // Imprime na tela
  }
 */


}
 
void loop() {
  


  int btn_gr = digitalRead(g_btn);
  int btn_ye = digitalRead(y_btn);
  int btn_re = digitalRead(r_btn);
  int btn_bl = digitalRead(b_btn);

  if (btn_gr == LOW){
    op = 1;
  }
  if(btn_ye == LOW){w
    op = 2;
  }
   if(btn_re == LOW){
    op = 3;
  }
   if(btn_bl == LOW){
    op = 4;
  }

  switch (op){
    case 0:
      checkSD();
      break;

    case 1:
      val();
      break;
    
    case 2:
      val2();
      break;

    case 3:
      val3();
      break;

    case 4:
      val4();
      break;
  }

 
  Serial.println(op);

}