#include "temporarydatamanager.h"
#include <QDir>
#include <QStringList>
#include <QDebug>
TemporaryDataManager::TemporaryDataManager(QObject *parent) : QObject(parent)
{

}

void TemporaryDataManager::cleanUpDirectory(bool delete_locals)
{
    // clear files stored in memory
    mFileWatcher.blockSignals(true);
    QStringList dirs = mFileWatcher.directories();
    QStringList files = mFileWatcher.files();
    if(delete_locals) // if declared to delete local files
    {
        for(int index(0); files.length(); index++)
        {
            QFile current(files.at(index));
            if(current.exists())
            {
                if(!current.remove())
                    qDebug() << "Failed to remove file at " << files.at(index);
            }
        }
        for(int index(0); dirs.length(); index++)
        {
            QDir current(dirs.at(index));
            if(current.exists())
            {
                if(!current.rmdir(dirs.at(index)))
                    qDebug() << "Failed to remove directory " << dirs.at(index);
            }
        }
    }
    mFileWatcher.removePaths(files);
    mFileWatcher.removePaths(dirs);
    mFileWatcher.blockSignals(false);


}

void TemporaryDataManager::setRootDirectory(QString directory, bool copy_old, bool delete_old)
{
    if(!mTemporaryDirectory.isEmpty() && (mTemporaryDirectory.compare(directory) != 0))
    {
        // clear the directory that is currently in use
        cleanUpDirectory();
    }
    QDir  dir(directory);
    if(dir.exists())
    {
        // load the files from the existing directory
        QStringList  directory_list = dir.entryList(QDir::AllDirs);
        QStringList  file_list = dir.entryList(QDir::Files);
        mFileWatcher.addPath(directory);
        mFileWatcher.addPaths(directory_list);
        mFileWatcher.addPaths(file_list);
    }
    else
    {
        // creates the directory
        if(!dir.mkdir(directory))
            qDebug() << "Failed to create " << directory;
    }
}


void TemporaryDataManager::addFile(QString file_path, QString parent_dir)
{
    // check if the file is under the temporary directory
    // if not copy it into the tree
    // destination is parent_dir, if parent_dir is empty default to root
    if(parent_dir.isEmpty())
        parent_dir = mTemporaryDirectory;
}

void TemporaryDataManager::addDirectory(QString directory)
{

}

void TemporaryDataManager::removeDirectory(QString directory)
{

}

void TemporaryDataManager::removeFile(QString file_path)
{

}

void TemporaryDataManager::requestCleanDirectory()
{

}
