#ifndef APPLICATION1_HPP
#define APPLICATION1_HPP

#include <QtQuickTemplates2/private/qquickapplicationwindow_p.h>

class Application1  : public QQuickApplicationWindow
{
    Q_OBJECT
public:
    Application1();

    bool nativeEvent(const QByteArray &eventType,
                           void *message,
                           long *result) override;
};

#endif // APPLICATION1_HPP
