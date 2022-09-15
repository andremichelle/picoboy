class LED {
   private:
    int pins[3] = {5, 6, 7};
    bool powered[3] = {false, false, false};

   public:
    static const int Red = 0;
    static const int Yellow = 1;
    static const int Green = 2;

    LED() {}

    void setup() {
        for (int i = 0; i < 3; i++) {
            pinMode(pins[i], OUTPUT);
        }
    }

    void power(int which, bool value) {
        if (powered[which] == value) {
            return;
        }
        powered[which] = value;
        digitalWrite(pins[which], value);
    }
};