

int leds[5] = { 12 ,11, 10, 9, 8}; 
int i; 


void setup() {
  i = 0;
  while (i < 5) {
    pinMode(leds[i], OUTPUT);
    i++; 
  }
}

void loop() {
    // for(int i=0;i<5;i++){
    //   for(int j=0;j<256;j++){
    //     analogWrite(leds[i], j);
    //     delay(5);
    //   }
    // }


    // for(int i=0;i<5;i++){
    //   for(int j=255;j>=0;j--){
    //     analogWrite(leds[i], j);
    //     delay(5);
    //   }
    // }
  int brightness;
  i = 0;
while(i < 5) {
  brightness = 0;
  while(brightness < 256) {
    analogWrite(leds[i], brightness);
    delay(4);
    brightness++;
  }
  i++;
}

i = 0;
while(i < 5) {
  brightness = 255;
  while(brightness > -1) {
    analogWrite(leds[i], brightness);
    delay(4);
    brightness--;
  }
  i++;
}
  delay(1000);
}
