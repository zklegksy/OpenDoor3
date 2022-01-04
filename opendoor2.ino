/**
 * @file opendoor.ino
 * @author Leon Kalliardos
 * @brief Ein Binärdisplay bestehend aus 4 LEDs zeigt die jeweilige Zahl an, die der Infrarotsensor übermittelt
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright Copyright (c) 2021
 *
 */

/**
 * @brief Infrarot sensor
 *
 */

#include <IRremote.h>

#define IR_PIN 3

IRrecv irrecv(IR_PIN);
decode_results results;

/**
 * @brief LED's
 *
 */

#define LED1 5
#define LED2 6
#define LED4 9
#define LED8 10

/**
 * @brief Variabeln etc
 *
 */

int bin[] = {0, 1, 0, 0};
int input;
int num;
bool status;
int ranNum;

void setup() {
    /**
     * @brief LED's
     *
     */

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED8, OUTPUT);

    setLEDs();

    /**
     * @brief Infrarotsensor
     *
     */

    pinMode(IR_PIN, INPUT);

    irrecv.enableIRIn();
}

int returnNum() {
    return num;
}

int decToBin() {

    for (int i = 0; i < 5; i++) {

        if (num % 2 == 0) {

            bin[i] = 0;
        }
        else {

            bin[i] = 1;
        }

        num = num / 2;
    }

    return 0;
}

int getNum() {
    int red;
    

    if(irrecv.decode(&results)) {

        switch (results.value) {
        case 16753245:  red = 1;
        //1 gedrückt
                        break;
        case 16736925:  red = 2;
        //2 gedrückt
                        break;
        case 16769565:  red = 3;
        //3 gedrückt
                        break;
        case 16720605:  red = 4;
        //4 gedrückt
                        break;
        case 16712445:  red = 5;
        //5 gedrückt
                        break;
        case 16761405:  red = 6;
        //6 gedrückt
                        break;
        case 16769055:  red = 7;
        //7 gedrückt
                        break;
        case 16754775:  red = 8;
        //8 gedrückt
                        break;
        case 16748655:  red = 9;
        //9 gedrückt
                        break;
        case 16750695:  red = 0;
        //0 gedrückt
                        break;
        case 16756815:  red = rand()%(15+1-0)+0;
        //# gedrückt, zufälliger Wert
                        break;
        
        default:        red = -1;
                        break;
        }

        irrecv.resume();
        if(red != -1) {
            status = true;
            return red;
        } 
        
    }
    if(red != -1) {
        status = true;
    } 
    return 0;
}

int setLEDs() {

    digitalWrite(LED1, bin[0]);
    digitalWrite(LED2, bin[1]); 
    digitalWrite(LED4, bin[2]); 
    digitalWrite(LED8, bin[3]); 

    return 0;
}

void loop() {

    num = getNum();
    if(status) {
        decToBin();

        setLEDs();
        status = false;
    }
    
}
