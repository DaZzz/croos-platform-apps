#include <cassert>
#include "workerthread.h"
#include "mainwindow.h"

WorkerThread::WorkerThread(MainWindow *pWindow)
  : QThread(pWindow),
    m_pWindow(pWindow)
{
    //
}

WorkerThread::~WorkerThread()
{
  //
}

const QImage *WorkerThread::getResultImage() const
{
  assert(isFinished());
  return m_ptrResult.data();
}

void WorkerThread::startScharr(const QImage &image)
{

}

void WorkerThread::run()
{

}

void WorkerThread::stop()
{

}
