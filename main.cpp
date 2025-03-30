#include "prime.h"
#include <QApplication>
#include <QMessageBox>
#include <QSharedMemory>
#include <QSystemSemaphore>
#include <QProcess>
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QCoreApplication>
#include"hwhandler.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prime p;
    hwhandler h;
    h.speaker_off();
    // Create a QLabel to display the GIF animation
    QLabel *splashLabel = new QLabel;

    // Load the GIF using QMovie
    QMovie *movie = new QMovie(":/images/newedsplash.png"); // Use the correct path to your GIF

    // Set the QLabel to the desired size (1280x720)
    splashLabel->setFixedSize(1920, 1080);
    splashLabel->move(0,0);

    // Scale the movie to fit the QLabel size
    movie->setScaledSize(splashLabel->size());

    // Connect the signal to ensure the label size matches the movie frame (optional)
    QObject::connect(movie, &QMovie::frameChanged, [=]() {
        splashLabel->setFixedSize(splashLabel->size()); // Ensure consistent size
    });

    splashLabel->setMovie(movie);
    movie->start();  // Start the GIF animation

    // Show the QLabel as the splash screen
    splashLabel->show();

    // Close the QLabel splash screen and show the main window after 5 seconds
    QTimer::singleShot(5000, splashLabel, SLOT(close()));
    QTimer::singleShot(5000, &p, SLOT(show()));

//    // Shared memory and semaphore to handle single instance
//    QSharedMemory sharedMemory;
//    QSystemSemaphore semaphore("unique_application_semaphore", 1);

//    // Try to acquire the semaphore (lock it)
//    if (!semaphore.acquire()) {
//        // If another instance is running, show a message and exit
////        QMessageBox::warning(nullptr, "Application Already Running",
////                             "Another instance of this application is already running.");
//        return 0;  // Exit the application
//    }

//    // Set a unique key for the shared memory segment
//    sharedMemory.setKey("unique_application_key");

//    // Check if shared memory already exists, meaning another instance is running
//    if (sharedMemory.attach()) {
//        // Shared memory already attached, exit the application
////        QMessageBox::warning(nullptr, "Application Already Running",
////                             "Another instance of this application is already running.");
//        return 0;  // Exit this instance
//    }

//    // If the memory is not yet created, create it
//    if (!sharedMemory.create(1)) {
//        // If creation fails, show an error message
//      //  QMessageBox::critical(nullptr, "Error", "Unable to create shared memory segment.");
//        return -1;  // Exit with error
//    }

    // Proceed with the rest of your application logic here
    // This will only run if the first instance is successfully created

    // Show your prime window (assuming prime is a QWidget-based class)
   // p.show();

//    // Capture the exit event and restart the application if it closes
//    QObject::connect(&a, &QApplication::aboutToQuit, [&]() {
//        // Restart the application using QProcess
//        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
//    });

    // Run the application
    return a.exec();
}
