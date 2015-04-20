######################################################################
# Automatically generated by qmake (2.01a) ?? 4? 20 19:54:08 2015
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . \
              aboutDialog \
              audioPlayDockWidget \
              checkCodeAudioDialog \
              chooseCpAlFileDialog \
              link \
              mainWindow \
              node \
              propertiesDialog \
              selectCodeDialog \
              setNodeInfoDialog \
              setupAudioDialog \
              setupCodeDialog \
              setupDefaultAudioDialog \
              mainWindow/mtFileProtoSourceFiles
INCLUDEPATH += . \
               mainWindow \
               node \
               link \
               chooseCpAlFileDialog \
               audioPlayDockWidget \
               checkCodeAudioDialog \
               setNodeInfoDialog \
               mainWindow/mtFileProtoSourceFiles \
               propertiesDialog \
               aboutDialog \
               setupCodeDialog \
               setupAudioDialog \
               setupDefaultAudioDialog \
               selectCodeDialog

# Input
HEADERS += ui_previewNodeWidget.h \
           aboutDialog/aboutDialog.h \
           audioPlayDockWidget/audioPlayWidget.h \
           checkCodeAudioDialog/checkCodeAudioDialog.h \
           chooseCpAlFileDialog/chooseCpAlDialog.h \
           link/link.h \
           mainWindow/GraphicsView.h \
           mainWindow/mainWindow.h \
           node/node.h \
           propertiesDialog/propertiesdialog.h \
           selectCodeDialog/createCodeDialog.h \
           selectCodeDialog/selectCodeDialog.h \
           setNodeInfoDialog/getTablePair.h \
           setNodeInfoDialog/getTablePairDialog.h \
           setNodeInfoDialog/setNodeInfo.h \
           setNodeInfoDialog/setNodeInfoDialog.h \
           setupAudioDialog/setupAudioDialog.h \
           setupCodeDialog/setupCodeDialog.h \
           setupDefaultAudioDialog/setupDefaultAudioDialog.h \
           mainWindow/mtFileProtoSourceFiles/modeTable.pb.h
FORMS += aboutDialog/aboutDialog.ui \
         audioPlayDockWidget/audioPlayWidget.ui \
         checkCodeAudioDialog/checkCodeAudioDialog.ui \
         chooseCpAlFileDialog/chooseCpAlDialog.ui \
         propertiesDialog/propertiesdialog.ui \
         selectCodeDialog/createCodeDialog.ui \
         selectCodeDialog/selectCodeDialog.ui \
         setNodeInfoDialog/getTablePairDialog.ui \
         setNodeInfoDialog/setNodeInfoDialog.ui \
         setupAudioDialog/setupAudioDialog.ui \
         setupCodeDialog/setupCodeDialog.ui \
         setupDefaultAudioDialog/setupDefaultAudioDialog.ui
SOURCES += main.cc \
           audioPlayDockWidget/audioPlayWidget.cc \
           checkCodeAudioDialog/checkCodeAudioDialog.cc \
           chooseCpAlFileDialog/chooseCpAlDialog.cc \
           link/link.cc \
           mainWindow/GraphicsView.cc \
           mainWindow/mainWindow.cc \
           node/node.cc \
           propertiesDialog/propertiesdialog.cc \
           selectCodeDialog/createCodeDialog.cc \
           selectCodeDialog/selectCodeDialog.cc \
           setNodeInfoDialog/getTablePair.cc \
           setNodeInfoDialog/setNodeInfo.cc \
           setupAudioDialog/setupAudioDialog.cc \
           setupCodeDialog/setupCodeDialog.cc \
           setupDefaultAudioDialog/setupDefaultAudioDialog.cc \
           mainWindow/mtFileProtoSourceFiles/modeTable.pb.cc
RESOURCES += resources.qrc
CONFIG += qt debug warn_on
QT+=phonon
LIBS+=-lprotobuf