#include "app.h"

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