//
// Created by suteerth on 3/18/16.
//


#include "CCWindow.h"
#include "SpinEnc.h"

CoolCryptoWindow::CoolCryptoWindow() : m_MainBox(Gtk::ORIENTATION_HORIZONTAL),
                                       buttonAndViewBox(Gtk::ORIENTATION_VERTICAL),
                                        swEncDec("Enc/Dec"){


    set_title("Encrypt All the Things!!!");
    set_border_width(5);
    this->encrypt = true;

    //Taking care of child widgets
    //This is initializing the passphase box.
    m_entry.set_max_length(50);
    m_entry.set_text("passphrase");
    m_entry.select_region(0, m_entry.get_text_length());

    //This adds the encrypt button, the m_entry and the decrypt
    // button from left to rigth horizontally
    buttonAndViewBox.add(m_entry);
    buttonAndViewBox.add(swEncDec);

    //Preparing the text view and the reference buffer

    m_refTxtBuffer = Gtk::TextBuffer::create();
    m_refTxtBufferDec = Gtk::TextBuffer::create();
    m_refTxtBuffer->set_text("Encrypt");
    m_refTxtBufferDec->set_text("Decrypt");

    m_TextViewEnc.set_buffer(m_refTxtBuffer);
    m_TextViewDec.set_buffer(m_refTxtBufferDec);

    //This adds the text view and the previously made box to the main
    m_MainBox.add(m_TextViewEnc);
    m_MainBox.add(buttonAndViewBox);
    m_MainBox.add(m_TextViewDec);

///*Unsure what this does*/m_VBox.pack_start(m_dec_button);

    //This creates the reference buffer for the text view
    this->add(m_MainBox);
    show_all_children();

    //Connect Sognals
    m_refTxtBuffer->signal_changed().connect(sigc::mem_fun(*this,
                                                           &CoolCryptoWindow::on_enc_button_clicked));

    m_refTxtBufferDec->signal_changed().connect(sigc::mem_fun(*this,
                                                              &CoolCryptoWindow::on_dec_button_clicked));

    swEncDec.signal_pressed().connect(sigc::mem_fun(*this,
                                                               &CoolCryptoWindow::switch_enc_dec));
}

void CoolCryptoWindow::on_enc_button_clicked() {

    if(!this->encrypt)return;
    Gtk::TextBuffer::iterator tit = m_refTxtBuffer->begin();
    string in = tit.get_text(m_refTxtBuffer->end());
    string out = in;

    Vigenere encryptor(m_entry.get_text());
    out = encryptor.encrypt(in);
    m_refTxtBufferDec->set_text(out);
}

void CoolCryptoWindow::on_dec_button_clicked() {

    if(this->encrypt)return;
    Gtk::TextBuffer::iterator tit = m_refTxtBufferDec->begin();
    string in = tit.get_text(m_refTxtBufferDec->end());
    string out = in;
    Vigenere decryptor(m_entry.get_text());
    out = decryptor.decrypt(in);
    m_refTxtBuffer->set_text(out);
}

void CoolCryptoWindow::switch_enc_dec() {
    this->encrypt = ! this->encrypt;
    if(this->encrypt){ on_enc_button_clicked();this->swEncDec.set_label("Encrypt");}
    else{ on_dec_button_clicked();this->swEncDec.set_label("Decrypt");}
}
