#define SCK_PIN 21
#define SS_PIN 19
#define MISO_PIN 18
#define MOSI_PIN 15

uint8_t SPI_transfer(uint8_t byte_out) {
  uint8_t byte_in = 0;
  uint8_t ibit, res;
  // Init protocol - Wait for ss LOW
  while (digitalRead(SS_PIN) == HIGH);

  // MSB first
  for (ibit = 0x80; ibit > 0; ibit = ibit >> 1) {
    res = (byte_out & ibit) ? HIGH : LOW; // =0 or !=0
    digitalWrite(MISO_PIN, res);

    // Wait for SCK goes high
    while (digitalRead(SCK_PIN) == LOW);
    if (digitalRead(MOSI_PIN) == HIGH) {
      Serial.print("1");
      byte_in |= ibit;
    }else{
      Serial.print("0");
    }

    // Wait for SCK goes low - End 1 cycle
    while (digitalRead(SCK_PIN) == HIGH);
  }

  return byte_in;
}

void setup() {
  Serial.begin(115200);
  pinMode(SCK_PIN, INPUT);
  pinMode(SS_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(MOSI_PIN, INPUT);
}

void loop() {
  uint8_t rev;
  rev = SPI_transfer(0x77);

  Serial.print("\tREV\t");Serial.println(rev);
  delay(2000);
}