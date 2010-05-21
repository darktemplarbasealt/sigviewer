#ifndef LABEL_WIDGET_H
#define LABEL_WIDGET_H

#include "../base/user_types.h"
#include "signal_browser_model_4.h"

#include <QMap>
#include <QWidget>

namespace BioSig_
{

//-----------------------------------------------------------------------------
class LabelWidget : public QWidget
{
    Q_OBJECT
public:
    LabelWidget(SignalBrowserModel& model);

    void addChannel(int32 channel_nr, const QString& label);
    void removeChannel(int32 channel_nr);

public slots:
    void changeYStart (int32 y_start);

protected:
    void paintEvent(QPaintEvent* pe);

private:
    SignalBrowserModel& signal_browser_model_;

    unsigned signal_height_;
    unsigned signal_spacing_;

    QMap<int32, QString> channel_nr2label_;
    int32 y_start_;
};

} // namespace BioSig_

#endif
