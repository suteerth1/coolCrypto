//
// Created by suteerth on 3/18/16.
//

#ifndef CCRYPTO_CCWINDOW_H
#define CCRYPTO_CCWINDOW_H


#include <gtkmm-3.0/gtkmm.h>
#include <gtkmm-3.0/gtkmm/box.h>
#include<iostream>

class CoolCryptoWindow: public Gtk::Window{
        private:
                bool encrypt;

        public:
                CoolCryptoWindow();
                //	virtual ~CoolCryptoWindow();
        protected:
                //Signal handlers:
                void on_enc_button_clicked();
                void on_dec_button_clicked();
                void switch_enc_dec();
                void change_window_based_on_text();
                //Child widgets:
                //Buttons
                Gtk::Button swEncDec;

                //Text buffers
                Glib::RefPtr<Gtk::TextBuffer> m_refTxtBuffer;
                Glib::RefPtr<Gtk::TextBuffer> m_refTxtBufferDec;
                //Text Views
                Gtk::TextView m_TextViewEnc;
                Gtk::TextView m_TextViewDec;
                //Boxez
                Gtk::Box m_MainBox;
                Gtk::Box buttonAndViewBox;
                //Passphrase Box
                Gtk::Entry m_entry;
};

#endif //CCRYPTO_CCWINDOW_H
