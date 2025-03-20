const int REPEAT = 3;
const int PERIOD = 1000;
const byte ON = 1;
const byte OFF = 0;

struct lantern {
    byte pin;
    int illuminate;
    int blink;
    byte on;
    byte off;
};

void exe_signal(byte pin, byte on, int light, byte off) {
    digitalWrite(pin, on);
    delay(light);
    digitalWrite(pin, off);
};

void exe_blink_signal(byte pin, byte on, int blink, byte off, int period, int repeat) {
    delay(period);
    for (int i = 0; i < repeat; i++) {
        exe_signal(pin, on, blink, off);
        delay(period);
    }
}

lantern red = {13, 10000, 0, ON, OFF};
lantern yellow = {12, 2000, 0, ON, OFF};
lantern green = {8, 7000, 1000, ON, OFF};

void setup() {
    pinMode(red.pin, OUTPUT);
    pinMode(yellow.pin, OUTPUT);
    pinMode(green.pin, OUTPUT);
};

void loop() {
    exe_signal(red.pin, red.on, red.illuminate, red.off);
    exe_signal(yellow.pin, yellow.on, yellow.illuminate, yellow.off);
    exe_signal(green.pin, green.on, green.illuminate, green.off);
    exe_blink_signal(green.pin, green.on, green.blink, green.off, PERIOD, REPEAT);
    exe_signal(yellow.pin, yellow.on, yellow.illuminate - PERIOD, yellow.off);
};

