#ifndef _DMR_MPV_GLWIDGET_H
#define _DMR_MPV_GLWIDGET_H 

#include <QtWidgets>
#include <mpv/opengl_cb.h>
#undef Bool
#include <mpv/qthelper.hpp>

namespace dmr {
class MpvGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    MpvGLWidget(QWidget *parent, mpv::qt::Handle h);
    virtual ~MpvGLWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

public slots:
    void onNewFrame();

private:
    mpv::qt::Handle _handle;
    mpv_opengl_cb_context *_gl_ctx {nullptr};
};

}

#endif /* ifndef _DMR_MPV_GLWIDGET_H */

