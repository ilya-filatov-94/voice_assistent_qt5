#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QObject>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDesktopServices>
#include "datamapper.h"

class SettingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
private:
    QWidget* widget;
    QVBoxLayout* vlayout;

    QHBoxLayout* hLayoutInputs[4];
    QLineEdit* inputLine[4];
    QPushButton* visibleLine[4];

    QPushButton* backBtn;
    QPushButton* btn_commandList;
    QLabel* labelVkToken;
    QLabel* labelYandexSpeechToken;
    QLabel* labelYandexGeoToken;
    QLabel* labelPathFfmpeg;
    QPushButton* saveBtn;
    QSqlDatabase db;
    Datamapper* dataMapper;
    QDesktopServices desktopService;
    QTemporaryFile temporaryFile;

    void createInputLines();
    void changeVisibleLine1();
    void changeVisibleLine2();
    void changeVisibleLine3();
    void changeVisibleLine4();
    void loadReference();
    void writeSettings();

signals:
    void showMainWindow(bool);

private slots:
    void switchWindow();
    void showReference();

public slots:
    void getSettingsData(QString, QString, QString, QString);
};

#endif // SETTINGSWINDOW_H
