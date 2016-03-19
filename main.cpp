#include <iostream>
#include "CCWindow.h"
#include <gtkmm/main.h>


using namespace std;

int main(int argc,char** argv) {
    Gtk::Main kit(argc,argv);

    CoolCryptoWindow window;

    Gtk::Main::run(window);

    cout << "Hello, World!" << endl;
    return 0;
}