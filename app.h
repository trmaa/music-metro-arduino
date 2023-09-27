class App {
  private:
    //inputs y outputs
    uint8_t boton = 2;
    uint8_t potenciometro = A5;
    uint8_t ultrasonidos = A0;
    
    uint8_t zumbador = 4;

    //math
    float entrada = 0;
    float nota = 0;
c:\Users\Pablo Trik Marín\Documents\Arduino\musicometro\BQcode
    //logicas
    float iter = 0;
    float index = 0;

    int notas[16];
  
  public:
    App(){
      pinMode(this->boton, INPUT);
      pinMode(this->zumbador, OUTPUT);
      pinMode(this->potenciometro, INPUT);
      pinMode(this->ultrasonidos, INPUT);

      notas[15] = 129;
      notas[14] = 147;
      notas[13] = 165;
      notas[12] = 175;
      notas[11] = 196;
      notas[10] = 220;
      notas[9] = 247;
      notas[8] = 262;
      notas[7] = 270;
      notas[6] = 294;
      notas[5] = 330;
      notas[4] = 350;
      notas[3] = 394;
      notas[2] = 440;
      notas[1] = 494;
      notas[0] = 524;
    }
    void update(){
      if (digitalRead(this->boton)) {
        this->entrada = (analogRead(this->potenciometro) / 100) * analogRead(this->ultrasonidos) + 100;
        this->iter = 15;
        this->nota = 0;
        for (int i = 0; i < 16; i += 1) {
          if (this->entrada <= this->notas[(int) this->iter]) {
            this->nota = this->notas[(int) this->iter];
          }
          else {
            this->iter = (this->iter - 1);
          }
        }
        tone(this->zumbador, this->nota, 100);
      }
    }
};