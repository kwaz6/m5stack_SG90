#include <M5Stack.h>

int led1 = 16;

//PWMの設定
const double PWM_Hz = 50;   //PWM周波数
const uint8_t PWM_level = 16; // PWM 16bit(0～65535)

void setup() {
  Serial.begin(115200);
  m5.begin();
  pinMode(led1, OUTPUT);
  //モータのPWMのチャンネル、周波数の設定
  ledcSetup((uint8_t)1, PWM_Hz, PWM_level);

  //モータのピンとチャンネルの設定
  ledcAttachPin(led1, 1);
}
void loop() {
  // 1600から9000の間で回転するように指令。
  // i=i+10は更新ごとに10パルス増やすので(9000-1600)/10=740回
  // 740*10ms=7.4sに-90degから90degまで回転、逆回転も7.4sでいく
  for (int i = 1600; i <= 9000; i=i+10) {
    ledcWrite(1, i);
    delay(10);  //20msの遅延
    Serial.printf("%d\n", i);
  }
  for (int i = 9000; i > 1600; i=i-10) {
    ledcWrite(1, i);
    delay(10);
    Serial.printf("%d\n", i);
  }
  // ひたすら-90deg⇔0deg⇔90degまでを1秒ごとに繰り返す動作
  /*
  int deg=1638;
  ledcWrite(1, deg);
  Serial.printf("%d\n", deg);
  delay(1000);
  deg = 4751;
  ledcWrite(1, deg);
  Serial.printf("%d\n", deg);
  delay(1000);
  deg = 7864;
  ledcWrite(1, deg);
  Serial.printf("%d\n", deg);
  delay(1000);
  deg=4751;
  ledcWrite(1, deg);
  Serial.printf("%d\n", deg);
  delay(1000);
  deg = 1638;
  ledcWrite(1, deg);
  Serial.printf("%d\n", deg);
  delay(1000);
  deg = 4751;
  ledcWrite(1, deg);
  Serial.printf("%d\n", deg);
  delay(1000);
  deg = 7864;
  ledcWrite(1, deg);
  Serial.printf("%d\n", deg);
  delay(1000);
  deg = 4751;
  ledcWrite(1, deg);
  Serial.printf("%d\n", deg);
  delay(1000);
  */
}
