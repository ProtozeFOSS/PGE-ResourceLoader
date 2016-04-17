#ifndef RESOURCEWRITEMANAGER_H
#define RESOURCEWRITEMANAGER_H

#include <QObject>

class ResourceWriteManager : public QObject
{
    Q_OBJECT
public:
    explicit ResourceWriteManager(QObject *parent = 0);

signals:
    void resourceSuccesfullyGenerated();
    void failedToCreateResource(int error, QString error_str, QString error_ext);

public slots:
  //  void startResourceGeneration();
 //   void stopResourceGeneration();


private:

};

#endif // RESOURCEWRITEMANAGER_H
