#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_B3  247
#define NOTE_G3  196
#define NOTE_A3  220

#define LED_ROJO 0
#define LED_AZUL 1
#define LED_VERDE 2
#define LED_AMARILLO 3
#define NUM_LEDS 4
#define MAX_NIVEL 32

 int leds[NUM_LEDS] = {2, 3, 4, 5};
int botones[NUM_LEDS] = {8, 9, 10, 11};
int buzz = 6;

int secuencia[MAX_NIVEL], nivelActual = 0, indiceNivel = 0;
int jugada = 0;
int nuevoJuego = 1;

int notas[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4
};
int melodia[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int duraciones[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void setup() {
  int i;

  for (i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(botones[i], INPUT);
  }
  
  pinMode(buzz, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  if (nuevoJuego) {
    iniciarNuevoJuego();
  }
  
  efectoBarrido(30, 2);
  mostrarSecuencia(nivelActual, 200);

  while (!nuevoJuego && indiceNivel <= nivelActual) {
      Serial.println(" Inicio de juego");
      Serial.println(" Mostrando secuencia");
      Serial.println(" Leyendo botones");
	  Serial.println("Nivel " + String(secuencia[indiceNivel]));
      jugada = leerBotones();
      Serial.println(" botones ingresados " + String(jugada));
      encenderLed(jugada);
      delay(150);
      apagarLed(jugada);

    if (secuencia[indiceNivel] != jugada) {
      gameOver();
    } else {
      indiceNivel++;
      delay(400);
    }
  }
  
  indiceNivel = 0;
  nivelActual++;
}

void encenderLed(int led) {
  digitalWrite(leds[led], HIGH);
  tone(buzz, notas[led], 100); 
}

void apagarLed(int led) {
  digitalWrite(leds[led], LOW);
}

void encenderTodos() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);
  }
}

void apagarTodos() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void efectoBarrido(int demora, int repeticiones) {
  apagarTodos();
  
  for (int i = 0; i <= repeticiones; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      encenderLed(j);
      
      if (j != 0) {
        apagarLed(j - 1);
      }
      
      delay(demora);
    }
    
    for (int j = NUM_LEDS - 2; j >= 0; j--) {
      encenderLed(j);
      apagarLed(j + 1);
      delay(demora);
    }
  }
  
  apagarTodos();
}

void gameOver() {
  apagarTodos();
  efectoBaliza(150, 4);
  Serial.println("Game Over");
  nuevoJuego = 1;
  delay(600);
  
}

void iniciarNuevoJuego() {
  llenarSecuencia();
  nivelActual = 0;
  nuevoJuego = 0;
  ejecutarMelodia();
}

void llenarSecuencia() {
  for (int i = 0; i < MAX_NIVEL; i++) {
    secuencia[i] = random(NUM_LEDS);
  }
}

void mostrarSecuencia(int hasta, int demora) {
  for (int i = 0; i <= hasta; i++) {
    delay(demora);
    encenderLed(secuencia[i]);
    
    delay(demora);
    apagarLed(secuencia[i]);
    delay(demora);
  }
}

int leerBotones() {
  
   int btn = -1; 
  bool flag = false;btn;
  while (!flag)
  {    
    if(digitalRead(botones[LED_ROJO]) && !flag)
    {
      flag = true;
      btn = LED_ROJO;
    }
    if(digitalRead(botones[LED_VERDE]) && !flag)
    {
      flag = true;
      btn = LED_VERDE;
    }
    if(digitalRead(botones[LED_AZUL]) && !flag)
    {
      flag = true;
      btn = LED_AZUL;
    }
    if(digitalRead(botones[LED_AMARILLO]) && !flag)
    {
      flag = true;
      btn = LED_AMARILLO;
    }    
  }
 return btn;
}

void ejecutarMelodia() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / 4; 
    tone(buzz, melodia[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzz);
  }
}

void efectoBaliza(int demora, int repeticiones) {
  int i;
  for (i = 0; i <= repeticiones; i++) {
    apagarTodos();
    delay(demora);
    encenderTodos();
    
    
    tone(buzz, melodia[0], 200); 
    delay(250); 
    noTone(buzz);

    

    noTone(buzz);
    delay(demora);
  }
  apagarTodos();
  delay(demora);
}