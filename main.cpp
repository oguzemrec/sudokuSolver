#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

struct RunOnce {
  template <typename T>
  RunOnce(T &&f)
  {
    f();
  }
};

void foo()
{
  for (int i = 0; i < 9; i++)
    {
      static RunOnce a([]() {
                       qDebug() << "Hello";
      });

      static RunOnce b([]() {
                       qDebug() << "World";
      });
    }
}

int main(int argc, char *argv[])
{
  foo();
  foo();
  QApplication a(argc, argv);
  MainWindow w;

  w.show();


  return a.exec();
}
