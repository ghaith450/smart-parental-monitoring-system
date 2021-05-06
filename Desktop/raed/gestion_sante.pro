QT       += core gui sql
QT       += network multimedia multimediawidgets
QT += printsupport
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    argent.cpp \
    connection.cpp \
    cours.cpp \
    examen.cpp \
    gestion_argent.cpp \
    gestion_exam.cpp \
    main.cpp \
    medicament.cpp \
    accueil.cpp \
    produit.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    statacceuil.cpp \
    statistiques.cpp \
    suivi_medical.cpp \
    utilisateur.cpp

HEADERS += \
    argent.h \
    connection.h \
    cours.h \
    examen.h \
    gestion_argent.h \
    gestion_exam.h \
    medicament.h \
    accueil.h \
    produit.h \
    qcustomplot.h \
    smtp.h \
    statacceuil.h \
    statistiques.h \
    suivi_medical.h \
    utilisateur.h

FORMS += \
    accueil.ui \
    gestion_argent.ui \
    gestion_exam.ui \
    statacceuil.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \




