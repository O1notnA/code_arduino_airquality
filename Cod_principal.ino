#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define col 16
#define lin 2
#define ende 0x27
LiquidCrystal_I2C lcd(ende, col, lin);

long randNumber;

/* microSD 
#include <SD.h>
#include <SPI.h> 
File myFile;
int pinoSS = 10;
*/

void setup() {

  /* executado somente uma vez, pois está no "void setup"

  Serial.begin(9600); // Define BaundRate
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

  lcd.init();
  lcd.backlight();
  lcd.clear();
}


void loop() {
  char numPrint[4] = " ";
  for (int i = 0; i < 15; i++) {
    int x = random(1, 11);
    snprintf(numPrint, sizeof(numPrint), "%d", x);
    lcd.setCursor(0, 0);
    lcd.print(numPrint);
    delay(1000);
  }

  // lcd.setCursor(0,1); //segunda linha
  //lcd.print("MELHOR LOJA 2022");
  //delay(1000);
  //lcd.clear();
}