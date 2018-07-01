//-----------------------------------------------------------------//
//---IRLED e ReceptorClone--- PINOS COM A PROGRMACAO --------------//
//_________________________________________________________________//
//-----------------------------------------------------------------//
// IR led  ________________________________________________________//
//_____ GND PIN -  ------------------------------------------------//
//_____ S PIN 3 c/ resistor ---------------------------------------//
//Receptor IR  ____________________________________________________//
//-----------------------------------------------------------------//
//_____ GND PIN - -------------------------------------------------//
//_____ 2 PIN 5V --------------------------------------------------//
//_____ S PIN 11 --------------------------------------------------//
//__________________________________________________________________//
//------------------------------------------------------------------//
//******************************************************************//


#include <IRremote.h>

IRsend irsend;


const PROGMEM unsigned int irSignal_OnAr[] = {8900, 4450, 550, 600, 550, 600, 550, 1700, 550, 550, 600, 1650, 550, 600, 550, 600, 550, 600, 550, 550, 600, 1650, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 1650, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 550}; //AnalysIR Batch Export (IRremote) - RAW
const PROGMEM unsigned int irSignal_OffAr[] = {8850, 4500, 550, 600, 550, 600, 550, 1650, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 1650, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 550, 1700, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 1650, 550, 600, 550, 600, 550, 600, 550}; //AnalysIR Batch Export (IRremote) - RAW
const PROGMEM unsigned int irSignaltemp16[] = {8900, 4450, 550, 600, 550, 550, 600, 1650, 600, 550, 600, 1650, 550, 600, 550, 550, 600, 550, 600, 550, 600, 1650, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 1650, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 550, 600};
const PROGMEM unsigned int irSignaltemp17[] = {8900, 4450, 550, 600, 550, 600, 550, 1650, 600, 600, 550, 1650, 600, 550, 600, 500, 600, 550, 600, 550, 550, 1700, 600, 550, 550, 600, 550, 550, 600, 550, 550, 1700, 550, 600, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 550, 600, 600, 500, 600, 550, 600, 550, 600, 550, 550, 600, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 550, 600, 550, 600, 1650, 600, 1600, 600, 1650, 550, 1700, 550};
const PROGMEM unsigned int irSignaltemp18[] = {8900, 4500, 550, 600, 500, 600, 600, 1650, 550, 600, 550, 1700, 550, 600, 550, 550, 550, 600, 550, 600, 550, 1700, 550, 600, 500, 600, 550, 600, 550, 600, 550, 1700, 500, 1700, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 600, 550, 550, 600, 1650, 550, 1650, 600, 1700, 550, 550, 550};
const PROGMEM unsigned int irSignaltemp19[] = {8900, 4450, 550, 600, 550, 600, 550, 1700, 550, 550, 550, 1700, 550, 600, 550, 600, 550, 600, 550, 550, 600, 1650, 550, 600, 550, 600, 550, 600, 550, 1650, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 500, 600, 550, 600, 550, 600, 550, 600, 550, 600, 500, 600, 600, 1650, 550, 1700, 500, 650, 550, 1650, 550};
const PROGMEM unsigned int irSignaltemp20[] = {8900, 4450, 550, 600, 550, 550, 600, 1650, 550, 600, 550, 1700, 550, 600, 550, 550, 550, 600, 550, 600, 600, 1650, 550, 600, 550, 550, 600, 550, 550, 1700, 550, 600, 550, 1650, 600, 550, 550, 600, 550, 600, 600, 550, 550, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 1650, 550, 1700, 600, 550, 550, 600, 550};
const PROGMEM unsigned int irSignaltemp21[] = {8900, 4450, 600, 550, 600, 550, 600, 1650, 550, 600, 550, 1650, 550, 600, 600, 550, 550, 600, 550, 600, 550, 1650, 600, 550, 600, 550, 600, 550, 550, 1650, 550, 1700, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 550, 600, 550, 600, 600, 550, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 1700, 550, 600, 550, 1650, 550, 1700, 550};
const PROGMEM unsigned int irSignaltemp22[] = {8850, 4500, 600, 550, 600, 550, 550, 1650, 600, 600, 550, 1650, 600, 550, 550, 550, 600, 600, 550, 600, 550, 1650, 600, 550, 600, 550, 550, 550, 600, 1700, 500, 1700, 550, 1650, 600, 550, 600, 550, 600, 600, 550, 550, 600, 550, 550, 550, 600, 550, 600, 550, 550, 600, 600, 550, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 550, 650, 550, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 550, 1700, 550, 550, 600, 1650, 550, 600, 550};
const PROGMEM unsigned int irSignaltemp23[] = {8850, 4500, 550, 600, 550, 550, 550, 1700, 550, 600, 550, 1700, 550, 550, 600, 550, 550, 600, 550, 600, 550, 1700, 550, 550, 600, 550, 550, 1700, 550, 600, 550, 550, 600, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 550, 600, 550, 550, 600, 550, 600, 550, 600, 550, 600, 550, 1650, 550, 600, 550, 600, 550, 1700, 550};




void setup()
{
  Serial.begin(9600);
}


String leStringSerial() {
  String conteudo = "";
  char caractere;

  // Enquanto receber algo pela serial
  while (Serial.available() > 0) {
    // Lê byte da serial
    caractere = Serial.read();
    // Ignora caractere de quebra de linha
    if (caractere != '\n') {
      // Concatena valores
      conteudo.concat(caractere);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }

  Serial.print("Recebi: ");
  Serial.println(conteudo);

  return conteudo;
}


void loop() {

  if (Serial.available()) {

    unsigned int irSignalon[91];

    String token = leStringSerial();

    Serial.println(token);

    int khz = 38 ; // 38kHz carrier frequency for the NEC protocol

    if (token == "on") {


      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignal_OnAr + i);
      }

      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.
    } else if (token == "off") {

      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignal_OffAr + i);
      }

      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.
    }
    else if (token == "16") {
      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignaltemp16 + i);
      }

      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.

    } else if (token == "17") {
      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignaltemp17 + i);
      }
      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.
    } else if (token == "18") {

      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignaltemp18 + i);
      }

      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.
    }
    else if (token == "19") {
      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignaltemp19 + i);
      }
      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.

    }
    else if (token == "20") {

      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignaltemp20 + i);
      }
      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.
    }
    else if (token == "21") {

      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignaltemp21 + i);
      }
      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.

    }
    else if (token == "22") {

      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignaltemp22 + i);
      }
      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.

    }
    else if (token == "23") {

      for (int i = 0; i < 91; i++) {
        irSignalon[i] = pgm_read_word_near(irSignaltemp23 + i);
      }
      irsend.sendRaw(irSignalon, sizeof(irSignalon) / sizeof(irSignalon[0]), khz); //Note the approach used to automatically calculate the size of the array.

      delay(50); //In this example, the signal will be repeated every 5 seconds, approximately.

    }
  }

}
