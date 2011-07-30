/***************************************************************************
 *   Copyright (C) 2011 by Vishesh Yadav <vishesh3y@gmail.com>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef HGIMPORTDIALOG_H
#define HGIMPORTDIALOG_H

#include <kdialog.h>

class QListWidget;
class QCheckBox;
class QGroupBox;
class KLineEdit;

class HgImportDialog : public KDialog
{
    Q_OBJECT

public:
    HgImportDialog(QWidget *parent=0);

public slots:
    void done(int r);

private slots:
    void saveGeometry();
    void slotAddPatches();
    void slotRemovePatches();

private:
    void setupUI();
    void getPatchInfo(const QString &fileName);

private:
    QListWidget *m_patchList;
    KPushButton *m_addPatches;
    KPushButton *m_removePatches;

    //options
    QGroupBox *m_optionGroup;
    QCheckBox *m_optNoCommit;
    QCheckBox *m_optBypass;
    QCheckBox *m_optExact;
    QCheckBox *m_optForce;
};

#endif /* HGIMPORTDIALOG_H */ 

