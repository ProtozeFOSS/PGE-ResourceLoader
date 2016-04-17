#ifndef TEMPORARYDATAMANAGER_H
#define TEMPORARYDATAMANAGER_H

#include <QObject>
#include <QFileSystemWatcher>
// Temporary Data Manager will house the file system structure for a project.
// Files can be added or removed. However, the files are copied to the directory if they are not already
// in the file tree. Any work done afterwards will be written to the internal files not their originals.


class TemporaryDataManager : public QObject
{
    Q_OBJECT
public:
    explicit TemporaryDataManager(QObject *parent = 0);
    QString getTemporaryDirectory()
    {
        return mTemporaryDirectory;
    }
    void setTemporaryDirectory(QString new_directory)
    {
        //if it exists?
        // clear it
        // if it doesnt create it
        //clean existing one
        //change directory
        mTemporaryDirectory = new_directory;
        //setup new directory for project
    }

signals:
    // file added, removed, or changed that is managed by the project
    void fileAdded(QString string_path);
    void fileChanged(QString string_path, bool user_changed);
    void fileRemoved(QString string_path);
    // directories added, removed, or changed within the temporary directory
    void directoryAdded(QString directory);
    void directoryChanged(QString directory);
    void directoryRemoved(QString directory);

public slots:
    void addFile(QString file_path, QString parent_dir = "");
    void addDirectory(QString directory);
    void removeDirectory(QString directory);
    void removeFile(QString file_path);
    void requestCleanDirectory();
    void setRootDirectory(QString directory, bool copy_old = false, bool delete_old = false);

private:
    QFileSystemWatcher mFileWatcher;
    QString mTemporaryDirectory; // [temp directory]/[project name]
    void cleanUpDirectory(bool delete_locals = false);   // totally wipes the existing directory
};

#endif // TEMPORARYDATAMANAGER_H
