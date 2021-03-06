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

#ifndef HGBRANCHDIALOG_H
#define HGBRANCHDIALOG_H

#include <QString>
#include "dialogbase.h"

class KComboBox;
class QLabel;

/**
 * Implements dialog to list & create branches and update/switch working 
 * directory to different branch.
 */
class HgBranchDialog : public DialogBase
{
    Q_OBJECT

public:
    explicit HgBranchDialog(QWidget *parent = 0);

public slots:
    void slotUpdateDialog(const QString &text);
    void slotCreateBranch();
    void slotSwitch();

private:
    void updateInitialDialog();

private:
    KComboBox           *m_branchComboBox;
    QPushButton         *m_createBranch;
    QPushButton         *m_updateBranch;
    QLabel              *m_currentBranchLabel;

    QStringList          m_branchList;
};

#endif // HGBRANCHDIALOG_H

