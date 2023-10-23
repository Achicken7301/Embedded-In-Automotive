#define SDA 21
#define SCL 22

#define Tfull 500*1000
#define Thalf Tfull/2

#define SDA_MODE(m) (pinMode(SDA, m))
#define SCL_MODE(m) (pinMode(SCL, m))

#define readPin(p) (digitalRead(p))
#define writePin(p, m) (digitalWrite(p, m))

void setup() {
  Serial.begin(115200);
  
}

void loop() {
  uint8_t d;
  d = readByte_I2C(0x55);
  Serial.print("\tREV: ");Serial.println(d);
  delay(1000);
  
}

uint8_t readByte_I2C(uint8_t address) {
  SDA_MODE(INPUT);
  SCL_MODE(INPUT);

  // Wait for ideal condition
  while (readPin(SDA) != 1 || readPin(SCL) != 1);

  while (readPin(SDA) == 1);
  delayMicroseconds(Thalf / 2);
  // Start condition
  if (readPin(SCL) == 1)
  {
    // Read 8-bit data
    uint8_t rev = 0x00;
    while (readPin(SCL) == 1); // waiting for SCL goes LOW
    for (uint8_t ibit = 0x80; ibit > 0 ; ibit = ibit >> 1) {
      while (readPin(SCL) == 0); // waiting for SCL goes HIGH - start read bit
      // read SDA
      if (readPin(SDA) == 1) {
        Serial.print("1");
        rev |= ibit;
      }else{Serial.print("0");}
      while (readPin(SCL) == 1);
    }

    // Send ACK to master
    SDA_MODE(OUTPUT);
    writePin(SDA, HIGH);
    // Wait for end 1 cycle
    while (readPin(SCL) == 0);
    while (readPin(SCL) == 1);
    SDA_MODE(INPUT);

    return rev;
  }
}