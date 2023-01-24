#include <Arduino.h>
// #include <DFRobot_LCD.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Hotboards_leds.h>                       // Librerias para imprimir los numeros Binarios
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7
//* Variables De Pines
byte FlechaIndicadora[] = {
    0x00,
    0x04,
    0x06,
    0x1F,
    0x1F,
    0x06,
    0x04,
    0x00};
byte CaritaFeliz[] = {
    0x00,
    0x0A,
    0x0A,
    0x00,
    0x04,
    0x11,
    0x0E,
    0x00};
byte CaritaTroste[] = {
    0x00,
    0x00,
    0x0A,
    0x00,
    0x04,
    0x00,
    0x0E,
    0x11};
byte CandadoCerrado[] = {
    0x0E,
    0x0A,
    0x0A,
    0x1F,
    0x1F,
    0x1B,
    0x1B,
    0x1F};
byte CandadoAbierto[] = {
    0x0E,
    0x08,
    0x08,
    0x1F,
    0x1F,
    0x1B,
    0x1B,
    0x1F};

int push1 = 8;  // INPUT
int push2 = 12; // INPUT
int push3 = 13; // INPUT
int push4 = 7;  // INPUT

int a = 9;       // OUTPUT
int b = 10;      // OUTPUT
int c = 11;      // OUTPUT
int d = 6;       // OUTPUT
int e = 5;       // OUTPUT
int f = 3;       // OUTPUT
int g = 2;       // OUTPUT
int h = 4;       // OUTPUT
int buzzer = A3; // OUTPUT

float analogico1 = A0; // INPUT
float analogico2 = A1; // INPUT
float analogico3 = A2; // INPUT

Hotboards_leds binarios(a, b, c, d, e, f, g, h);
//* Variables De Control
int i, j = 0;
int releestado1, releestado2 = 0;
int ascendente, descentente = 0;
String r1, r2;
int posicion = 1;
int inicio = 0;
bool estado = 0;
int ledon, ledoff = 0;
float valor1, valor2 = 0;
// int PCF1 = 5; // Posicion CANDADO FILA 1
// int PCF2 = 15; // Posicion CANDADO FILA 2
long int numbers[] =
    {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001,
     1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001,
     10010, 10011, 10100, 10101, 10110, 10111, 11000,
     11001, 11010, 11011, 11100, 11101, 11110, 11111,
     100000, 100001, 100010, 100011, 100100, 100101,
     100110, 100111, 101000, 101001, 101010, 101011,
     101100, 101101, 101110, 101111, 110000, 110001,
     110010, 110011, 110100, 110101, 110110, 110111,
     111000, 111001, 111010, 111011, 111100, 111101,
     111110, 111111, 1000000, 1000001, 1000010, 1000011,
     1000100, 1000101, 1000110, 1000111, 1001000, 1001001,
     1001010, 1001011, 1001100, 1001101, 1001110, 1001111,
     1010000, 1010001, 1010010, 1010011, 1010100, 1010101,
     1010110, 1010111, 1011000, 1011001, 1011010, 1011011,
     1011100, 1011101, 1011110, 1011111, 1100000, 1100001,
     1100010, 1100011, 1100100};
void setup()
{
  // lcd.init();
  // lcd.clear();                      // limpia pantalla
  lcd.setBacklightPin(3, POSITIVE); // puerto P3 de PCF8574 como positivo
  lcd.setBacklight(HIGH);           // habilita iluminacion posterior de LCD
  lcd.begin(16, 2);
  lcd.createChar(0, FlechaIndicadora);
  lcd.createChar(1, CaritaFeliz);
  lcd.createChar(2, CaritaTroste);
  lcd.createChar(3, CandadoCerrado);
  lcd.createChar(4, CandadoAbierto);
  lcd.clear(); // limpia pantalla
  pinMode(push1, INPUT);
  pinMode(push2, INPUT);
  pinMode(push3, INPUT);
  pinMode(push4, INPUT);
  pinMode(analogico1, INPUT);
  pinMode(analogico2, INPUT);
  pinMode(analogico3, INPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.setCursor(0, 0); // FILA - COLUMNA
  lcd.print("  BIENVENIDOS ");
  lcd.setCursor(0, 1);
  lcd.print("   PRUEBA LCD ");
  delay(2000);
  lcd.clear();         //
  lcd.setCursor(0, 0); //  COLUMNA - FILA
  lcd.print("ELIJA UNA OPCION");
  delay(2000);
  lcd.clear();
  posicion = 1;
}
void opciones()
{
  lcd.setCursor(0, 0);
  lcd.print(" DIGITAL");
  lcd.setCursor(9, 0);
  lcd.print(" ANALOG");
  lcd.setCursor(0, 1);
  lcd.print(" RELAYS");
  lcd.setCursor(9, 1);
  lcd.print(" CONT");
}
void buzzeron()
{
  digitalWrite(buzzer, 1);
  delay(50);
  digitalWrite(buzzer, 0);
}
void selector()
{
  if (digitalRead(push1))
  {
    buzzeron();
    while (digitalRead(push1))
      ;
    delay(100);
    posicion = posicion + 1;
    Serial.println(posicion);
  }

  if (digitalRead(push2))
  {
    buzzeron();
    while (digitalRead(push2))
      ;
    delay(100);
    posicion = posicion - 1;
    Serial.println(posicion);
  }
  if (posicion = 4)
  {
    posicion = 1;
  }
  else if (posicion < 1)
  {
    posicion = 4;
  }
}
void ledsON()
{
  if (digitalRead(push1))
  {
    while (digitalRead(push1))
      ;
    delay(100);
    ledon = ledon + 1;
    Serial.print(" Encender LED  ");
    Serial.println(ledon);
  }
}
void ledsOFF()
{

  if (digitalRead(push2))
  {
    while (digitalRead(push2))
      ;
    delay(100);
    ledoff = ledon - 1;
    ledon = ledoff;

    if (ledon <= 0 && ledoff <= 0)
    {
      ledon = 0;
      ledoff = 0;
    }
    ledon = ledon;
    ledoff = ledoff;
    Serial.print("Apagar LED  ");
    Serial.println(ledoff);
    // Serial.print("Valor LedON ");
    // Serial.println(ledon);
  }
}

void pantallacontador()
{
  lcd.setCursor(0, 0);
  lcd.print("CONTADOR: ");
  lcd.setCursor(10, 0);
  lcd.print(descentente);
  lcd.setCursor(0, 1);
  lcd.print("BINARIO: ");
}
void contador()
{
  if (digitalRead(push1) == 1)
  {
    while (digitalRead(push1) == 1)
      ;
    descentente = descentente + 1;
    if (descentente > 100)
    {
      descentente = 0;
    }
  }
  if (digitalRead(push2))
  {
    while (digitalRead(push2) == 1)
    {
    }
    descentente = descentente - 1;
    if (descentente <= 0)
    {
      descentente = 0;
      lcd.clear();
    }
  }
  lcd.setCursor(8, 1),
      lcd.print(numbers[descentente]);
  Serial.print("Contador Binario: ");
  Serial.println(descentente);
}
void reset()
{
  if (digitalRead(push4) == 1)
  {
    estado = false;
    lcd.clear();
    opciones();
    digitalWrite(b, 0);
    digitalWrite(c, 0);
    digitalWrite(d, 0);
    digitalWrite(e, 0);
    digitalWrite(g, 0);
    digitalWrite(h, 0);
    digitalWrite(f, 0);
    digitalWrite(a, 0);
    buzzeron();
    digitalWrite(buzzer, 0);
    i = 0;
    descentente = 0;
  }
}
void leds()
{
  lcd.setCursor(0, 0);
  lcd.print("LED1");
  lcd.setCursor(9, 0);
  lcd.print("LED2");
  lcd.setCursor(0, 1);
  lcd.print("LED3");
  lcd.setCursor(9, 1);
  lcd.print("LED4");
}

void loop()
{

  selector();
  if (posicion == 1)
  {
    lcd.clear();
    opciones();
    delay(100);
    while (posicion == 1)
    {
      selector();
      lcd.setCursor(0, 0);
      lcd.write(byte(0)); // Imprmir Caracter

      if (posicion == 1 && digitalRead(push3) == 1)
      {
        estado = true;
        lcd.clear();
        buzzeron();
        while (estado == true)
        {
          leds();
          ledsON();
          ledsOFF();
          switch (ledon)
          {

          case 0:
            digitalWrite(b, 0);
            digitalWrite(c, 0);
            digitalWrite(d, 0);
            digitalWrite(e, 0);
            lcd.setCursor(6, 0);
            lcd.write(byte(3));
            lcd.setCursor(15, 0);
            lcd.write(byte(3));
            lcd.setCursor(6, 1);
            lcd.write(byte(3));
            lcd.setCursor(15, 1);
            lcd.write(byte(3));
            break;
          case 1:
            digitalWrite(b, 1);
            digitalWrite(c, 0);
            digitalWrite(d, 0);
            digitalWrite(e, 0);
            lcd.setCursor(6, 0);
            lcd.write(byte(4));
            lcd.setCursor(15, 0);
            lcd.write(byte(3));
            lcd.setCursor(6, 1);
            lcd.write(byte(3));
            lcd.setCursor(15, 1);
            lcd.write(byte(3));
            break;
          case 2:
            digitalWrite(b, 1);
            digitalWrite(c, 1);
            digitalWrite(d, 0);
            digitalWrite(e, 0);
            lcd.setCursor(6, 0);
            lcd.write(byte(4));
            lcd.setCursor(15, 0);
            lcd.write(byte(4));
            lcd.setCursor(6, 1);
            lcd.write(byte(3));
            lcd.setCursor(15, 1);
            lcd.write(byte(3));
            break;
          case 3:
            digitalWrite(b, 1);
            digitalWrite(c, 1);
            digitalWrite(d, 1);
            digitalWrite(e, 0);
            lcd.setCursor(6, 0);
            lcd.write(byte(4));
            lcd.setCursor(15, 0);
            lcd.write(byte(4));
            lcd.setCursor(6, 1);
            lcd.write(byte(4));
            lcd.setCursor(15, 1);
            lcd.write(byte(3));
            break;
          case 4:
            digitalWrite(b, 1);
            digitalWrite(c, 1);
            digitalWrite(d, 1);
            digitalWrite(e, 1);
            lcd.setCursor(6, 0);
            lcd.write(byte(4));
            lcd.setCursor(15, 0);
            lcd.write(byte(4));
            lcd.setCursor(6, 1);
            lcd.write(byte(4));
            lcd.setCursor(15, 1);
            lcd.write(byte(4));
            break;
          }
          if (ledon > 4)
          {
            digitalWrite(b, 0);
            digitalWrite(c, 0);
            digitalWrite(d, 0);
            digitalWrite(e, 0);
            ledon = 0;
          }
          reset();
        }
      }
    }
  }
  if (posicion == 2)
  {
    lcd.clear();
    opciones();
    while (posicion == 2)
    {
      selector();
      lcd.setCursor(9, 0);
      lcd.write(byte(0)); // Imprmir Caracter
      if (posicion == 2 && digitalRead(push3) == 1)
      {
        estado = true;
        lcd.clear();
        buzzeron();
        while (estado == true)
        {
          valor1 = analogRead(analogico1) * (5.0 / 1023.0);
          valor2 = analogRead(analogico2);
          lcd.setCursor(0, 0);
          lcd.print("ANALOG 1= ");
          lcd.setCursor(10, 0);
          lcd.print(valor1);
          lcd.setCursor(0, 1);
          lcd.print("ANALOG 2= ");
          lcd.setCursor(10, 1);
          lcd.print(valor2);
          reset();
        }
      }
    }
  }

  if (posicion == 3)
  {
    lcd.clear();
    opciones();
    while (posicion == 3)
    {
      selector();
      lcd.setCursor(0, 1);
      lcd.write(byte(0)); // Imprmir Caracter
      if (posicion == 3 && digitalRead(push3) == 1)
      {
        estado = true;
        lcd.clear();
        releestado1 = 0;
        releestado2 = 0;
        lcd.setCursor(0, 0);
        lcd.print("RELE 1: ");
        lcd.setCursor(8, 0);
        lcd.print("OFF");
        lcd.setCursor(0, 1);
        lcd.print("RELE 2: ");
        lcd.setCursor(8, 1);
        lcd.print("OFF");
        lcd.setCursor(12, 0);
        lcd.write(byte(2));
        lcd.setCursor(12, 1);
        lcd.write(byte(2));
        buzzeron();
        while (estado == true)
        {

          if (digitalRead(push1))
          {
            while (digitalRead(push1))
              ;
            releestado1 = releestado1 + 1;

            if (releestado1 == 1)
            {
              digitalWrite(g, 1);
              Serial.println("Rele 1 Activado");
              r1 = "ON  ";
              lcd.setCursor(12, 0);
              lcd.write(byte(1));
            }
            else if (releestado1 == 2 || releestado1 == 0)
            {
              digitalWrite(g, 0);
              Serial.println("Rele 1 Desactivado");
              r1 = "OFF";
              lcd.setCursor(12, 0);
              lcd.write(byte(2));
            }
            Serial.println(releestado1);
          }
          if (digitalRead(push2))
          {
            while (digitalRead(push2))
              ;
            releestado2 = releestado2 + 1;

            if (releestado2 == 1)
            {
              digitalWrite(f, 1);
              Serial.println("Rele 2 Activado");
              r2 = "ON  ";
              lcd.setCursor(12, 1);
              lcd.write(byte(1));
            }
            else if (releestado2 == 2 || releestado2 == 0)
            {
              digitalWrite(f, 0);
              Serial.println("Rele 2 Desactivado");
              r2 = "OFF";
              lcd.setCursor(12, 1);
              lcd.write(byte(2));
            }

            Serial.println(releestado2);
          }
          if (releestado1 >= 2)
          {
            releestado1 = 0;
          }

          if (releestado2 >= 2)
          {
            releestado2 = 0;
          }
          if (digitalRead(push4))
          {
            digitalWrite(g, 0);
            digitalWrite(h, 0);
          }
          lcd.setCursor(0, 0);
          lcd.print("RELE 1: ");
          lcd.setCursor(8, 0);
          lcd.print(r1);
          lcd.setCursor(0, 1);
          lcd.print("RELE 2: ");
          lcd.setCursor(8, 1);
          lcd.print(r2);
          reset();
        }
      }
    }
  }
  if (posicion == 4)
  {
    lcd.clear();
    opciones();
    while (posicion == 4)
    {
      selector();
      lcd.setCursor(9, 1);
      lcd.write(byte(0)); // Imprmir Caracter
      if (posicion == 4 && digitalRead(push3) == 1)
      {
        estado = true;
        lcd.clear();
        buzzeron();
        while (estado == true)
        {
          contador();
          pantallacontador();
          binarios.write(descentente);
          reset();
        }
      }
    }
  }
}
