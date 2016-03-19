#include <iostream>
#include "CCWindow.h"



using namespace std;

int main(int argc,char** argv) {

    Gtk::Main kit(argc,argv);
    CoolCryptoWindow window;
    Gtk::Main::run(window);
    return 0;
}