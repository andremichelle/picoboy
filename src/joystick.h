class Joystick {
   private:
    unsigned long active[5];

   public:
    static const int CENTER = 0;
    static const int UP = 1;
    static const int RIGHT = 2;
    static const int DOWN = 3;
    static const int LEFT = 4;

    Joystick() {
        for (int i = 0; i < 5; i++) {
            active[i] = 0;
        }
    }

    void setup() {
        for (int i = 0; i < 5; i++) {
            pinMode(i, INPUT_PULLUP);
        }
    }

    void pull() {
        for (int i = 0; i < 5; i++) {
            if (digitalRead(i) == LOW) {
                active[i]++;
            } else {
                active[i] = 0;
            }
        }
    }

    bool get(int index) { return active[index] > 0; }
    bool just(int index) { return active[index] == 1; }
    unsigned int duration(int index) { return active[index]; }
};