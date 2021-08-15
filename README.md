Advertencia: La descripción del proyecto se encuentra en construcción, pueden faltar detalles que explicar y errores de ortografía. Igualmente el código esta funcionando correctamente con Guitarix.

# SIMPLE-MIDI-GUITARIX-PEDALBOARD (MIDI Input - MIDI Output)
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-1.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-2.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-SimulIDE.png" width="100%"></img> 

# FUNCIONAMIENTO
Descargue la ultima versión SimulIDE que incluye soporte para Arduino: https://www.simulide.com/p/downloads.html

Abrir el archivo SIMULIDE-PedalBoardMIDI.simu que se encuentra en la carpeta del proyecto. De no iniciar la simulación haga click derecho sobre la placa Arduino y LOAD FIRMWARE, luego seleccione alguno de los archivos con extensión HEX que están en la carpeta principal del proyecto.

La versión simple y económica de este proyecto esta limitada a 4 Bancos (con 4 preset cada uno, total: 16 presets), ya que son la cantidad de LEDs disponibles para mostrar el estado de los mismos. Se esta trabajando en otra versión con display de 7 segmentos que incrementará el costo. A futuro se espera diseñar una pedalera mas grande con pantalla LCD GRAFICA. Igualmente en el código se ofrece la posibilidad de usar un LCD 16x2 a quienes tengan un Arduinoo Mega. 

# MEDIDAS
Entrar a: https://app.sketchup.com

Abrir el archivo SKETCHUP-SIMPLE-MIDI-GUITARIX-PEDALBOARD.skp que se encuentra en la carpeta del proyecto.

# MATERIALES
Este proyecto pretende usar materiales reciclados, quien escribe no responde por lo daños económicos que puedan causar los detalles descriptos en este apartado:

1- Arduino Nano: la conexión a la PC se hace por USB, luego usar ttymidi (en GNU/Linux https://github.com/moddevices/mod-ttymidi es fácil de compilar) para simular un puerto MIDI (o Hairless MIDI to Serial).

2- Perfil de Metal de 40,5 x 9,7 cm (Los suelen tirar en la obras de construcción)

3- Tuvo PVC 110x2,5 mm (se corta y da la forma del pedal con calor, por ejemplo con una plancha para ropa)

4- Un retazo de madera para dar la forma interna del pedal (lijando), se usará para moldear el PVC.

5- Chapa fina (puede ser de lata de gaseosa o cerveza, lijar pintura para asegurarse de que conducirá energía) que se pegara (con Cianoacrilato – Gotita en algunos países) por encima del PVC y conducirá la señal Digital de los Pines. Esta chapa chocara con el perfil de metal (punto 2) que conducirá GND y así encenderá y apagará el Pedal. Si pinta el perfil de metal entonces tendrá que, colocar otra chapa fina por debajo del pedal de PVC que conducirá el GND para que puede tomar contacto con la señal digital.

6- 10 LEDs. (para los Pedales se usaron LEDs Blancos provenientes de una Luz de Emergencia en desuso, para el resto se usaron LEDs azules de mouse óptico y Joystick de PS2)

7- Resistencias 220ohms (o mayor valor si no tiene disponibles estas), puede colocar o no estas resistencias a los LEDS (entre la salida del PIN digital de Arduino y el LED), en general es recomendable colocarlas pero, si tiene muchos LEDs para reciclar puede probar esto: si los LEDs calientan coloque resistencias, de lo contrario no serían necesarias.

8- Un pulsador de CPU que se usara para el cambio entre MODO BANCO y MODO INDIVIDUAL.

9- Herramientas (caladora de mano o eléctrica, taladro, lijadora, limas, etc.) y mechas para taladro de distintas medidas

# ADVERTENCIAS/ACLARACIONES
-

-

# OTRA INFORMACIÓN
Abra el archivo SIMPLE_MIDI_GUITARIX_PEDALBOARD.ino con Arduino IDE. En la primer pestaña encontrara los pines asignados a LEDs y Pedales. Todos los Pines y señales MIDI CC son modificables pero, no realice ningún cambio sin antes hacer una copia de los archivos. Puede usar simuladores (SimulIDE) y el Debug de Hairless MIDI to Serial para probar los cambios que realice. 
Tenga la gentileza de informarme sobre los avances significativos que haga usted en el proyecto.

Si usa ttymidi en GNU/Linux ejecutelo así (de no funcionar o funcionar mal en primera instancia):

$ ttymidi -s /dev/ttyUSB0 --baudrate=115200

Si usa Hairless-Midiserial (en formato compilado solo esta disponible para sistemas operativos de 32 bits en GNU/Linux) habilite la linea MIDI.turnThruOff() en la pestaña SETUP;

Diseñado por:

Fernando Omar Serrano (fernando-inf@hotmail.com)

2021 @CopyLeft
