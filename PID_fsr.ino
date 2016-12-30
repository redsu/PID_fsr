// 首先定義腳位
#define led_pin 11
#define fsr_pin A0
int input_fsr = 0;
int fsr_value, led_value, angle;
float P, I, D;
void setup()
{
  P = I = D = 0.0f;
  P = 1.0f;
  angle = 90;
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
}

void loop()
{
  while(Serial.available()>0){
      byte readbuffer[5];
      Serial.readBytes(readbuffer, 2);
      input_fsr = readbuffer[0];
  }
  
  fsr_value = analogRead(fsr_pin); // 讀取FSR
  led_value = map(fsr_value, 0, 1023, 0, 255); // 從0~1023映射到0~255

  angle += (fsr_value-input_fsr) * P;
  
  analogWrite(led_pin, led_value); // 改變LED亮度
  Serial.println(fsr_value);
  //Serial.println(led_value);
  Serial.println("-------------");
  delay(100);
}

