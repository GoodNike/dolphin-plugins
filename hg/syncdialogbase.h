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

#ifndef HGSYNCDIALOGBASE_H
#define HGSYNCDIALOGBASE_H

#include "hgwrapper.h"

#include <QString>
#include <QProcess>
#include <QSize>
#include <QMap>
#include "dialogbase.h"

class QLabel;
class QCheckBox;
class QGroupBox;
class QProgressBar;
class QTextEdit;
class QComboBox;
class HgPathSelector;

//TODO: Save/Load dialog geometry
//TODO: HTTPS login
//

/**
 * Abstract class which implements common features of Push and Pull dialog.
 * Inherited by HgPushDialog and HgPullDialog.
 */
class HgSyncBaseDialog : public DialogBase
{
    Q_OBJECT

public:
    enum DialogType {PushDialog, PullDialog};

    explicit HgSyncBaseDialog(DialogType dialogType, QWidget *parent = 0);

signals:
    void changeListAvailable();

protected:
    void done(int r) override;
    void setupUI();
    void createOptionGroup();
    void setup();
    void loadSmallSize();
    void loadBigSize();
    /** Changes text of @p m_optionsButton to 'Options >>' (true) or 'Options <<' (false) */
    void switchOptionsButton(bool switchOn);

    virtual void setOptions() = 0;
    virtual void createChangesGroup() = 0;
    virtual void parseUpdateChanges(const QString &input) = 0;
    virtual void appendOptionArguments(QStringList &args) = 0;
    virtual void getHgChangesArguments(QStringList &args) = 0;
    virtual void noChangesMessage() = 0;

protected slots:
    void slotGetChanges();
    void slotChangesProcessComplete(int exitCode, QProcess::ExitStatus status);
    void slotChangesProcessError();
    void slotOperationComplete(int exitCode, QProcess::ExitStatus status);
    void slotOperationError();
    void slotUpdateBusy(QProcess::ProcessState state);
    void slotWriteBigSize();
    void slotOptionsButtonClick();
    virtual void writeBigSize() = 0;
    virtual void readBigSize() = 0;

protected:
    HgPathSelector          *m_pathSelector;
    QProgressBar            *m_statusProg;
    bool                     m_haveChanges;
    bool                     m_terminated;
    HgWrapper               *m_hgw;
    DialogType               m_dialogType;

    // Options
    QList<QCheckBox*>        m_options;
    QGroupBox               *m_optionGroup;

    // geometry
    QSize                    m_smallSize;
    QSize                    m_bigSize;

    // changes
    QPushButton             *m_changesButton;
    QPushButton             *m_optionsButton;
    QGroupBox               *m_changesGroup;
    QProcess                 m_process;
    QProcess                 m_main_process; //should I use another process?

};

#endif // HGSYNCDIALOGBASE_H

