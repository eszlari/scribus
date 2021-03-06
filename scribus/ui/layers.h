/*
For general Scribus (>=1.3.2) copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Scribus 1.3.2
for which a new license (GPL+exception) is in place.
*/
#ifndef LAYERPALETTE_H
#define LAYERPALETTE_H

#include <QList>

#include "scribusapi.h"
#include "ui/scdockpalette.h"
#include "scribusstructs.h"
#include "sclayer.h"

class CheckBox;
class QComboBox;
class QEvent;
class QHBoxLayout;
class QHeaderView;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
class QToolButton;
class QVBoxLayout;
class ScrSpinBox;
class ScribusDoc;

class SCRIBUS_API LayerPalette : public ScDockPalette
{
	Q_OBJECT

public:
	LayerPalette(QWidget* parent);
	~LayerPalette() {};

	void setDoc(ScribusDoc* doc);
	void rebuildList();
	
	QTableWidget* Table { nullptr };	//public for the event filter in scribus.cpp.. TODO

public slots:
	void addLayer();
	void dupLayer();
	void removeLayer();
	void upLayer();
	void downLayer();
	void changeName(int row, int col);
	void visibleLayer();
	void printLayer();
	void lockLayer();
	void flowToggleLayer();
	void outlineToggleLayer();
	void selectToggleLayer();
	void toggleAllfromHeader(int index);
	void markLayer();
	void changeOpacity();
	void changeBlendMode(int blend);
	void setActiveLayer(int row, int col);
	void clearContent();
	void markActiveLayer(int layerID=-1);
	void iconSetChange();
	void languageChange();

signals:
	void LayerChanged();
	void LayerActivated(int);

protected:
	QWidget* containerWidget { nullptr };
	ScribusDoc* m_Doc { nullptr };
	QVBoxLayout* LayerPaletteLayout { nullptr };
	QHBoxLayout* Layout1 { nullptr };
	QHBoxLayout* layout1 { nullptr };
	QLabel* textLabel1 { nullptr };
	QComboBox* blendMode { nullptr };
	QLabel* textLabel2 { nullptr };
	ScrSpinBox* opacitySpinBox { nullptr };
	QHeaderView* Header { nullptr };
	QPushButton* newLayerButton { nullptr };
	QPushButton* duplicateLayerButton { nullptr };
	QPushButton* deleteLayerButton { nullptr };
	QPushButton* raiseLayerButton { nullptr };
	QPushButton* lowerLayerButton { nullptr };
	ScLayers *layers { nullptr };

	void changeEvent(QEvent *e) override;
};

#endif // LAYERPALETTE_H
