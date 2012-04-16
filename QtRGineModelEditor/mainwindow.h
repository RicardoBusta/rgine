#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

#include "glwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void resizeEvent(QResizeEvent *);
private:
    Ui::MainWindow *ui;

    GLWidget *glwidget;
    void updateLists();

    QString filename;

    Model *currentmodel;

    /* Control Variables */
    QString previousObject;
private slots:
    //GLWidget


    //General Control Functions
    void save();
    void load();
    void newModel();

    void modelSelect(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    //Object Control Functions
    void objectAddClicked();
    void objectRemoveClicked();
    void objectNameChanged();
    void objectTextureChanged();

    //Material Control Functions
    void materialAddClicked();
    void materialRemoveClicked();
    void materialSetType();
    void materialSlider1Changed();
    void materialSlider2Changed();
    void materialSlider3Changed();
    void materialSlider4Changed();

    //Face Control Functions
    void faceAddClicked();
    void faceRemoveClicked();
    void faceVertex1Changed();
    void faceVertex2Changed();
    void faceVertex3Changed();
    void faceNormal1Changed();
    void faceNormal2Changed();
    void faceNormal3Changed();
    void faceTexture1Changed();
    void faceTexture2Changed();
    void faceTexture3Changed();

    //Vertex Control Functions
    void vertexAddClicked();
    void vertexRemoveClicked();
    void vertexXChanged(double v);
    void vertexYChanged(double v);
    void vertexZChanged(double v);

    //Texture Control Functions
    void textureAddClicked();
    void textureRemoveClicked();
    void textureUChanged(double v);
    void textureVChanged(double v);

    //Normal Control Functions
    void normalAddClicked();
    void normalRemoveClicked();
    void normalAChanged();
    void normalTChanged();
};

#endif // MAINWINDOW_H