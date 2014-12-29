#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QThread>

class MainWindow;

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread(MainWindow *pWindow);
    ~WorkerThread();

    const QImage *getResultImage() const;

signals:
    void canceled();

public slots:
    void startScharr(const QImage &image);
    void stop();

private:
    MainWindow *m_pWindow;
    QScopedPointer <QImage> m_ptrInput, m_ptrResult;
    virtual void run();

};

#endif // THREADWORKER_H
