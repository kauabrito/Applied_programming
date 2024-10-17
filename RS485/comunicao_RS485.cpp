#include <Wire.h>
#include <SoftwareSerial.h>


#define ENB_PIN   4   // Pino do modo de operação do RS485
#define PinLED    13  // Pino do LED

SoftwareSerial serialRS(2, 3);    // RO, DI

char ledStatus;                   // Status do LED
const int BUFFER_SIZE = 100;
char buf[BUFFER_SIZE];
String strTemp = "";

/**
 * @brief setup
 */
void setup() {
  Serial.begin(9600);
  serialRS.begin(9600);  
  pinMode(PinLED, OUTPUT);        
  pinMode(ENB_PIN, OUTPUT);       
  digitalWrite(ENB_PIN, LOW);     // Habilitar o recebimento do RS485

  delay(1500);
}

/**
 * @brief Loop
 */
void loop() {
  if (serialRS.available() > 0)
  {
    
    
    // Ler os dados recebidos até encontrar o '\n', armazena no buf e em rlen o tamanho
    int rlen = serialRS.readBytesUntil('\n', buf, BUFFER_SIZE);

    for(int i = 0; i < rlen-1; i++)
    {
      strTemp += buf[i];  // Escreve os dados recebidos na String strTemp
    }
    
    
  }
  
  strTemp = "";           // limpa a String strTemp
}

/**
 * @brief Função para acender ou apagar o LED e imprimir
 * no LCD o status atual do LED
 * @params char ledNewStatus Estado de LED recebido via RS485
 */
void ledFunc(String ledNewStatus)
{
  if (ledNewStatus == "LED ON" || ledNewStatus == "LED On")
  {
    digitalWrite(PinLED,HIGH);
    
  }
  else if (ledNewStatus == "LED OFF" || ledNewStatus == "LED Off")
  {
    digitalWrite(PinLED,LOW);
    
  }
}