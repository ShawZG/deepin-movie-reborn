/* 
 * (c) 2017, Deepin Technology Co., Ltd. <support@deepin.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * is provided AS IS, WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, and
 * NON-INFRINGEMENT.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
#ifndef _DMR_PLAYLIST_WIDGET_H
#define _DMR_PLAYLIST_WIDGET_H 

#include <DPlatformWindowHandle>
#include <QtWidgets>

namespace Dtk
{
namespace Widget
{
    class DImageButton;
}
}

DWIDGET_USE_NAMESPACE

namespace dmr {

class PlayerEngine;
class MainWindow;
class PlayItemWidget;

class PlaylistWidget: public QListWidget {
    Q_OBJECT
public:
    enum State {
        Opened,
        Closed,
    };
    PlaylistWidget(QWidget *, PlayerEngine*);
    virtual ~PlaylistWidget();
    State state() const { return _state; }
    bool toggling() const { return _toggling; }

public slots:
    void togglePopup();
    void loadPlaylist();
    void openItemInFM();
    void showItemInfo();
    void removeClickedItem();

protected:
    void contextMenuEvent(QContextMenuEvent *cme) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void showEvent(QShowEvent *se) override;

protected slots:
    void updateItemStates();
    void updateItemInfo(int);
    void appendItems();
    void removeItem(int);

private:

    PlayerEngine *_engine {nullptr};
    MainWindow *_mw {nullptr};
    QWidget *_mouseItem {nullptr};
    QWidget *_clickedItem {nullptr};
    QSignalMapper *_closeMapper {nullptr};
    QSignalMapper *_activateMapper {nullptr};
    State _state {Closed};
    bool _toggling {false};
    /// < original row, data>
    QPair<int, PlayItemWidget*> _lastDragged {-1, nullptr}; 

    void batchUpdateSizeHints();
};
}

#endif /* ifndef _DMR_PLAYLIST_WIDGET_H */
