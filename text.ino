int schaltplan() {

    if(ersteLED == an) {

        addToNum(8)
    }
    if(zweiteLED == an) {

        addToNum(4)
    }
    if(dritteLED == an) {

        addToNum(2)
    }
    if(vierteLED == an) {

        addToNum(1)
    }

}


/* Die vier LED's sind alle über die
weiße Leitung gegrounded und jede
einzelnd ist mit dem Arduino verbunden.
Der IR Sensor ist ebenfals gegrounded,
übers grau Kabel an 5v angeschlossen,
wie auch an den Arduino*/

/*Die vier LED's stellen ei Binär
Display da. Von Rechts nach Links
beträgt der Wert der Lampen */
int wert[4] = { 1 , 2 , 4 , 8 };
/*Wenn man nun die Binärzahl lesen
möchte,muss man nur den Wert aller
angeschaltenen Lampen addieren.
Eine ausgeschaltene Lampe wird als
0 und eine angeschaltene Lampe als
1 dargestellt*/

int remote() {
    /*Die Fehrbedinung sendet via Infrarot ein Singnal an den Empfänger,
    wenn eine Taste gedrückt wird.Das Programm, entcoded diese Nachricht
    dann und führt jenach Wert unterschiedliche Funktionen aus*/

    if(Button.press == 0-9) {
        /*Die Knöpfe 0-9 zeigen den jeweiligen Wert in Binär an*/
        schowNum(Button.pressed());
    }

    if(Button.press == #) {
        /*Der Knopf # generiert einen zufälligen Wert zwischen 0 und 15.
        Dieser wird dann angezeigt*/
        randomNum(0-15);
    }

}

int base10(int 0,1,2,3,4,5,6,7,8,9) {}