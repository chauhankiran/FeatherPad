/*
 * Copyright (C) Pedram Pourang (aka Tsu Jan) 2014 <tsujan2000@gmail.com>
 *
 * FeatherPad is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FeatherPad is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @license GPL-3.0+ <https://spdx.org/licenses/GPL-3.0+.html>
 */

#ifndef LOADING_H
#define LOADING_H

#include <QThread>

namespace FeatherPad {

class Loading : public QThread {
    Q_OBJECT

public:
    Loading (const QString& fname, const QString& charset, bool reload,
             bool saveCursor, bool forceUneditable, bool multiple);
    ~Loading();

signals:
    void completed (const QString& text = QString(),
                    const QString& fname = QString(),
                    const QString& charset = QString(),
                    bool enforceEncod = false,
                    bool reload = false,
                    bool saveCursor = false,
                    bool uneditable = false,
                    bool multiple = false);

private:
    void run();

    QString fname_;
    QString charset_;
    bool reload_; // Is this a reloading?
    bool saveCursor_; // Should the cursor position be saved?
    bool forceUneditable_; // Should the doc be always uneditable?
    bool multiple_; // Are there multiple files to load?
};

}

#endif // LOADING_H
