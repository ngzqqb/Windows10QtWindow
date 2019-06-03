#ifndef X11X_HPP
#define X11X_HPP

#include <QWindow>

class X11x : public QWindow  {
public:
    X11x();


    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;

};

#endif // X11X_HPP
