#include "gui.h"


Gui::Gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gui)
{
    m_leds = new gpio();

    m_state = 0;
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle); // verbindung Timer -> Gui Label
    m_timer->start(TIMEOUT);
    ui->setupUi(this);

}

// 0 - 1 - 0 - 1
void Gui::toggle()
{
    m_state = !m_state;
    ui->led_25 -> setNum(m_state);

    //m_leds->set(LEDS[3],m_state); // LEDS = {18,23,24,25}
    m_leds->set(10);


}

Gui::~Gui()
{
    delete m_leds;
    delete ui;
}



void Gui::on_f_Slider_valueChanged(int value)
{
    m_timer->start(1000/value); // T = 1000 ms ... 100 ms -> 1 ... 10 Hz
}
