/**
 * BLEThermo
 * 
 * Allen Snook
 * December 2020
 * 
 * Reads temperature from a DS18B20 one wire thermometer connected
 * to pin 5 on a Adafruit Feather nRF52840.
 */


/**
 * To reset the bus, hold the bus low for 480 us, release for 70 us,
 * and then "sample" for 410 us
 */
void oneWire_reset(uint8_t pin) {
  digitalWrite(pin, LOW);
  pinMode(pin, OUTPUT);
  delayMicroseconds(480);

  pinMode(pin, INPUT);
  delayMicroseconds(70);

  delayMicroseconds(410);
}

/**
 * Send the LSb first
 * To write a 0 on the bus, hold low for 60 us then release for 10 us
 * To write a 1 on the bus, hold low for 5 us then release for 65 us
 */
void oneWire_writeByte(uint8_t pin, uint8_t value) {
  for (uint8_t i = 0; i < 8; i++) {
    if (value & 0x01) {
      digitalWrite(pin, LOW);
      pinMode(pin, OUTPUT);
      delayMicroseconds(5);

      pinMode(pin, INPUT);
      delayMicroseconds(65);
    } else {
      digitalWrite(pin, LOW);
      pinMode(pin, OUTPUT);
      delayMicroseconds(60);

      pinMode(pin, INPUT);
      delayMicroseconds(10);
    }
    value = value >> 1;
  }
  delayMicroseconds(200);
}

/**
 * The LSb is the first bit to arrive
 */
uint8_t oneWire_readByte(uint8_t pin) {
  uint8_t value = 0;
  
  for (uint8_t i = 0; i < 8; i++) {
    value = value >> 1;
    digitalWrite(pin, LOW);
    pinMode(pin, OUTPUT);
    delayMicroseconds(5);

    pinMode(pin, INPUT);
    delayMicroseconds(5);

    if (digitalRead(pin)) {
      value |= 0x80;
    }

    delayMicroseconds(50);
  }
  return value;
}

void dallas_startMeasurement(uint8_t pin) {
  oneWire_reset(pin);
  oneWire_writeByte(pin, 0xCC);
  oneWire_writeByte(pin, 0x44);

  // TODO - wait for high instead of this hardcoded delay
  delayMicroseconds(410);
}

double dallas_readTemperature(uint8_t pin) {
  oneWire_reset(pin);
  oneWire_writeByte(pin, 0xCC);
  oneWire_writeByte(pin, 0xBE);

  uint8_t scratchpad[9];
  for (uint8_t i=0; i < 9; i++) {
    scratchpad[i] = oneWire_readByte(pin);
    Serial.print(scratchpad[i], HEX);
    Serial.print(" ");
  }
  Serial.println("");

  int16_t rawTemp = 0;
  rawTemp |= scratchpad[1] << 8;
  rawTemp |= scratchpad[0];

  double tempC = 1.0 * rawTemp / 16.0;

  return (tempC * 9.0 / 5.0) + 32.0;
}

void setup() {
  // put your setup code here, to run once
}

void loop() {
  // put your main code here, to run repeatedly
  dallas_startMeasurement(5);
  delayMicroseconds(400);
  double tempF = dallas_readTemperature(5);
  Serial.print("Temperature: ");
  Serial.print(tempF, 3);
  Serial.println("");
  delay(1000);
}
