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
/* Eine Bibliothek, die das Arbeiten mit dem Infrarotsensor
deutlich erleichtert */

#define IR_PIN 3
// Am 3ten Pin, ist der Infrarotempfänger eingesteckt

IRrecv irrecv(IR_PIN);
//Für die Bibliothek wird der Infrarotsensor definiert
decode_results results;
//Die Empfangendaten werden in der Variabel results gespeichert

/**
 * @brief LED's
 *
 */

#define LED1 5
//Die Erste LED ist im 5ten Pin eingesteckt
#define LED2 6
//Die Zweite LED ist im 6ten Pin eingesteckt
#define LED4 9
//Die Dritte LED ist im 9ten Pin eingesteckt
#define LED8 10
//Die Vierte LED ist im 10ten Pin eingesteckt

/**
 * @brief Variabeln etc
 *
 */

int bin[] = {0, 1, 0, 0};
//Eine Array(Liste), in der die Werte der LEDs gespeichert werden
int input;
//Eine Variabel, in der die Eingabe des Nutzers gespeichert wird
int num;
// Eine Variabel, die den Wert in Dezimal gespeichert wird
bool status;

void setup() {
    /**
     * @brief LED's
     *
     */

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED8, OUTPUT);
    //Alle 4 LEDs werden als Output Geräte definiert

    setLEDs();

    /**
     * @brief Infrarotsensor
     *
     */

    pinMode(IR_PIN, INPUT);

    irrecv.enableIRIn();
}

int decToBin() {
    //Die Funktion wandelt den Dezimalwert in Binär um

    for (int i = 0; i < 5; i++) {
    //Eine Schleife die sich 4mal wiederholt

        if (num % 2 == 0) {
            //Wenn die Zahl gerade ist:
            bin[i] = 0;
            /*Der Wert der entsprechenden Position wird auf
            0(aus) gesetzt*/
        }
        else {
            //Wenn die Zahl ungerade ist:
            bin[i] = 1;
            /*Der Wert der entsprechenden Position wird auf
            1(an) gesetzt*/
        }

        num = num / 2;
        //Die Zahl wird halbiert
    }

    return 0;
}

int getNum() {
    /*Eine Funktion,
    die den Dezimalwert der Zahl zurück gibt*/
    int red;
    //Eine Interne Variabel

    if(irrecv.decode(&results)) {
        /*Eine Bedinung, die Überprüft,
        ob ein Wert empfangen wurde*/

        switch (results.value) {
        /*Ein Schalter, der den Wert der Fehrbedinung erkennt
        und die die Variabel red auf den Dezimalwert setzt*/
        case 16753245:  red = 1;
                        break;
        case 16736925:  red = 2;
                        break;
        case 16769565:  red = 3;
                        break;
        case 16720605:  red = 4;
                        break;
        case 16712445:  red = 5;
                        break;
        case 16761405:  red = 6;
                        break;
        case 16769055:  red = 7;
                        break;
        case 16754775:  red = 8;
                        break;
        case 16748655:  red = 9;
                        break;
        case 16750695:  red = 0;
                        break;
        
        default:        red = -1;
                        break;
        }

        irrecv.resume();
        if(red != -1) {
            status = true;
            return red; //Die Variabel red wird zurück gegeben
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
    //Jede LED wird einzelnd auf ihen Wert aus der Array(Liste) gesetzte, also entweder an oder aus.

    return 0;
}

void loop() {
    /*Die Funktion Loop wird immer wieder vom Arduino ausgeführt.
    Funktionen die ausserhalb dieser Stehen und nicht gecalled werden, werden nicht berücksichtigt*/

    num = getNum();
    //Die Variabel num wird auf den Input des Nutzers gesetzt
    if(status) {
        decToBin();
        //Unsere Zahl wird umgewandelt

        setLEDs();
        //Die LED's werden aktualisiert
        status = false;
    }
    
}