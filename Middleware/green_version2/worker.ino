#include "green.h"

green stepper1(13, 11, 12, 4000);
green stepper2(4, 5, 6, 1100);

#define dirmaker 34
#define periodmaker 64
#define periodmakerL 96

char ch;
int result_dir;
int count;

int accel = 0;

void setup() {
  Serial.begin(115200);
}


//43.44.45 = + , -
//35.36 = # $
// A ~ = 65 ~
// a ~ = 97 ~
void loop() {
  if (Serial.available()) {
    if (count == 4) {count = stepper1.setting(3);}
    ch = Serial.read();
    if (ch == 35 || ch == 36) {
      result_dir = (ch - dirmaker);
      stepper1.setting(result_dir);
      stepper1.procWork(accel);
    } else if (ch >=  48 && ch <= 57) {
      stepper1.procWork(accel); 
      count = stepper1.asciino(ch, count);
    } else if (ch >=43 && ch <= 45) {
      
    } else if (ch == 65) {
      stepper1.idle(accel, 2);
    }
  } else {
    if (count != 4) {
      count = stepper1.setting(4); //operation end
    }
  }
}

