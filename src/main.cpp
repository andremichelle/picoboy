#include <Arduino.h>
#include <U8g2lib.h>
#include <fps.h>
#include <joystick.h>
#include <led.h>

LED led;
Joystick joystick;
U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/10, /* dc=*/8,
                                           /* reset=*/9);
int frame = 0;

void setup() {
    led.setup();
    joystick.setup();

    u8g2.begin();
    u8g2.setFont(u8g2_font_3x5im_mr);
}

void loop() {
    joystick.pull();
    u8g2.clearBuffer();

    led.power(LED::Red, joystick.just(Joystick::LEFT));
    led.power(LED::Yellow, joystick.just(Joystick::CENTER));
    led.power(LED::Green, joystick.just(Joystick::RIGHT));

    u8g2.setCursor(0, 5);
    u8g2.println("FPS");
    u8g2.setCursor(u8g2.getStrWidth("FPS") + 3, 5);
    u8g2.println(fps());

    if (joystick.get(Joystick::CENTER)) {
        u8g2.drawFilledEllipse(104, 32, 5, 5);
    } else {
        u8g2.drawEllipse(104, 32, 5, 5);
    }
    if (joystick.get(Joystick::UP)) {
        u8g2.drawFilledEllipse(104, 20, 5, 5);
    } else {
        u8g2.drawEllipse(104, 20, 5, 5);
    }
    if (joystick.get(Joystick::LEFT)) {
        u8g2.drawFilledEllipse(92, 32, 5, 5);
    } else {
        u8g2.drawEllipse(92, 32, 5, 5);
    }
    if (joystick.get(Joystick::DOWN)) {
        u8g2.drawFilledEllipse(104, 44, 5, 5);
    } else {
        u8g2.drawEllipse(104, 44, 5, 5);
    }
    if (joystick.get(Joystick::RIGHT)) {
        u8g2.drawFilledEllipse(116, 32, 5, 5);
    } else {
        u8g2.drawEllipse(116, 32, 5, 5);
    }

    u8g2.sendBuffer();
    frame++;
}