class App {
  private:
    int potenciometro = A0;
    int led = 4;
  public:
    App(){
      pinMode(potenciometro, INPUT);
      pinMode(led, OUTPUT);
    }
    void update(){
      analogWrite(led,analogRead(potenciometro));
    }
};

class Main {
  public:
    static App app;

    static void main(){
      Main::app = App();
    }
    static void update(){
      app.update();
    }
};
App Main::app; 

//mierdas de arduino
void setup(){Main::main();}
void loop(){Main::update();}