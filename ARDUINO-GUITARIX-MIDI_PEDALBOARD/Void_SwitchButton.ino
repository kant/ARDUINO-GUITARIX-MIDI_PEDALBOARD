Bounce2::Button pedal_0 = Bounce2::Button();  //pedal_0 = Pulsador 0

void SwitchButton() {  //Cambio de MODO.
  pedal_0.update();    // Bounce2- Lee el pulsador y actualiza su estado.

  if (pedal_0.pressed()) {  //Bounce2- pressed= Devuelve True si el botón fue presionado físicamente
    tgSt[0]++;
    if (tgSt[0] > tgSt_0_Max) tgSt[0] = 0;  //Incrementa Valor de tgSt[0] de 0 a TgSt_0_Max. Si supera a TgSt_0_Max vuelve a 0

    //MODO BANCO
    if (tgSt[0] == 0) {
      digitalWrite(LED[1], LOW);

      digitalWrite(LED[0], LOW);  //APAGAR Primer LED = Indica encendido de MODO BANCO
      LCD_OLED();                 //Escribe en el LCD/OLED.
      LEDBank_Preset();           //LEDs indicadores de BANCO y PRESET. Ver pestaña "VoidLEDBank_Preset"
    }

    //MODO INDIVIDUAL
    else if (tgSt[0] == 1) {
      digitalWrite(LED[1], LOW);

      digitalWrite(LED[0], HIGH);  //ENCENDER Primer LED = Indica encendido de MODO INDIVIDUAL
      LCD_OLED();                  //Escribe en el LCD/OLED.
#if NO_USE_MIDI_INPUT
      for (byte i = 0; i <= 5; i++) {
        MIDI.sendControlChange(CC[i], valOff, Ch);   //Habilite esta Linea si no usa MIDIInput/ Apaga todos los pedales al pasar al MODO INDIVIDUAL, esto evita confuciones al pasar de un banco a otro y volver al MODO INDIVIDUAL, indicando al usuario en forma directa que todos los pedales estan apagados. Asi queda en evidencia que el MODO BANCO y el INDIVIDUAL solo son totalmente compatibles/viables si se tiene MIDIInput y Output juntos.Ver "void loop" : while (MIDI.read()).
        digitalWrite(LED[i + 1], LOW);
        tgSt[i + 1] = 1;
      }

#else
      //Cambia el estado de TgStB (TgSt solo para MODO Banco), su objetivo es encender o apagar los LED cuando se pasa del MODO BANCO al MODO INDIVIDUAL, mostrando asi el estado de los pedales en el MODO INDIVIDUAL provocado cuando se estaba en el MODO BANCO, para esto se usa otros TgSt denominados "TgStB"
      for (byte i = 0; i <= 5; i++) {
        if (tgStB[i] == 0) {
          digitalWrite(LED[i + 1], HIGH);
          tgSt[i + 1] = 0;
        } else {
          digitalWrite(LED[i + 1], LOW);
          tgSt[i + 1] = 1;
        }
      }
#endif
      for (byte i = 7; i <= 10; i++) {
        digitalWrite(LED[i], LOW);  //Apaga LEDs BANCO.
      }
    }
    //MODO LOOPD
    else if (tgSt[0] == 2) {
      digitalWrite(LED[1], LOW);

      LCD_OLED();  //Escribe en el LCD/OLED.
    }
  }
}
