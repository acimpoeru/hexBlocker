/*
Copyright 2012, 2013
Author Nicolas Edh,
Nicolas.Edh@gmail.com,
or user "nsf" at cfd-online.com

This file is part of hexBlocker.

    hexBlocker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    hexBlocker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with hexBlocker.  If not, see <http://www.gnu.org/licenses/>.

    The license is included in the file COPYING.
*/
#ifndef MainWindow_H
#define MainWindow_H

#include "vtkSmartPointer.h"    // Required for smart pointer internal ivars.
#include <QMainWindow>



// Forward Qt class declarations
class Ui_MainWindow;

// Forward VTK class declarations
class vtkRenderer;
class vtkRenderWindow;
class vtkPolyData;
class vtkPoints;
class HexBlocker;
class vtkRenderWindowInteractor;
class vtkAxesActor;
class vtkOrientationMarkerWidget;
class vtkAreaPicker;
class InteractorStyleVertPick;
class InteractorStylePatchPick;
class InteractorStyleEdgePick;
class vtkInteractorStyleTrackballCamera;
class ToolBoxWidget;
class vtkIdList;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:

  // Constructor/Destructor
  MainWindow();
  ~MainWindow();


  vtkSmartPointer<InteractorStyleVertPick> styleVertPick;
  vtkSmartPointer<InteractorStylePatchPick> stylePatchPick;
  vtkSmartPointer<InteractorStyleEdgePick> styleEdgePick;
public slots:

  virtual void slotOpenFile();
  virtual void slotExit();
  virtual void slotCreateHexBlock();
  virtual void slotOpenCreateHexBlockDialog();
  virtual void slotPrintHexBlocks();
  virtual void slotStartExtrudePatch();
  virtual void slotExtrudePatch(vtkIdList *selectedPatches);
  virtual void slotOpenMoveVerticesDialog();
  virtual void slotMoveVertices();
  virtual void slotResetInteractor();
  virtual void slotOpenSetBCsDialog();
  virtual void slotPatchSelectionDone();
  void slotStartSelectPatches(vtkIdType bcID);
  void slotExportBlockMeshDict();
  void slotRender();
  void slotShowStatusText(QString text);
  void slotStartSelectEdges();
  void slotEdgeSelectionDone(vtkIdType edgeId);
  virtual void slotAboutDialog();

  void slotReadBlockMeshDict();
  //virtual void slotSetBCs();


protected:
   
protected slots:

private:
  vtkRenderWindow                         *renwin;
  HexBlocker                              *hexBlocker;
  vtkSmartPointer<vtkInteractorStyleTrackballCamera> defStyle;
  vtkSmartPointer<vtkAxesActor> axes;
  vtkSmartPointer<vtkOrientationMarkerWidget> widget;
  vtkSmartPointer<vtkAreaPicker> areaPicker;

  ToolBoxWidget *toolbox;
  // Designer form
  Ui_MainWindow *ui;
};

#endif // MainWindow_H
