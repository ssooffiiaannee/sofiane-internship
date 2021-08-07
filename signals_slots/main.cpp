#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QObject>
#include <QSlider>
#include <QProgressBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // [1] create a window and set its (x, y, width, height)
    QMainWindow *window = new QMainWindow();
    window->setGeometry(0, 0, 400, 300);

    // [2] create the widgets
    QPushButton *button = new QPushButton(window);
    QSlider *slider = new QSlider(window);
    QProgressBar *progress_bar = new QProgressBar(window);
    QMessageBox *message_box = new QMessageBox();

    // [3] set dimensions, locations text for the button and a message for the message box
    slider->setGeometry(100, 50, 50, 50);
    progress_bar->setGeometry(150, 70, 100, 30);
    button->setText("Button");
    message_box->setText("The button has been clicked !");

    // [4] connect the widgets
    QObject::connect(button, SIGNAL(clicked()), message_box, SLOT(open())); // button --> message box
    QObject::connect(slider, SIGNAL(valueChanged(int)), progress_bar, SLOT(setValue(int))); // slider --> progress bar

    // [5] open the window
    window->show();
    return a.exec();
}
