/*
 * SPDX-FileCopyrightText: 2021~2021 CSSlayer <wengxt@gmail.com>
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _PLATFORMINPUTCONTEXT_FCITXCANDIDATEWINDOW_H_
#define _PLATFORMINPUTCONTEXT_FCITXCANDIDATEWINDOW_H_

#include "fcitxflags.h"
#include "fcitxqtdbustypes.h"
#include <QBackingStore>
#include <QGuiApplication>
#include <QPainter>
#include <QPointer>
#include <QTextLayout>
#include <QWindow>

namespace fcitx {

struct FcitxQtICData;
class FcitxTheme;
class MultilineText;

class FcitxCandidateWindow : public QWindow {
    Q_OBJECT
public:
    explicit FcitxCandidateWindow(FcitxQtICData *data, FcitxTheme *theme);
    ~FcitxCandidateWindow();

    void render(QPainter *painter);

public Q_SLOTS:
    void renderLater();
    void renderNow();
    void updateClientSideUI(const FcitxQtFormattedPreeditList &preedit,
                            int cursorpos,
                            const FcitxQtFormattedPreeditList &auxUp,
                            const FcitxQtFormattedPreeditList &auxDown,
                            const FcitxQtStringKeyValueList &candidates,
                            int candidateIndex, int layoutHint, bool hasPrev,
                            bool hasNext);

    QSize sizeHint();

Q_SIGNALS:
    void candidateSelected(int i);
    void prevClicked();
    void nextClicked();

protected:
    bool event(QEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void wheelEvent(QWheelEvent *) override;

    int highlight() const {
        int highlightIndex = (hoverIndex_ >= 0) ? hoverIndex_ : highlight_;
        return highlightIndex;
    }

private:
    const bool isWayland_ =
        QGuiApplication::platformName().startsWith("wayland");
    QSize actualSize_;
    QPointer<FcitxTheme> theme_;
    QBackingStore *backingStore_;
    QTextLayout upperLayout_;
    QTextLayout lowerLayout_;
    std::vector<std::unique_ptr<MultilineText>> candidateLayouts_;
    std::vector<std::unique_ptr<MultilineText>> labelLayouts_;
    int cursor_ = -1;
    int highlight_ = -1;
    int hoverIndex_ = -1;
    int accAngle_ = 0;
    bool prevHovered_ = false;
    bool nextHovered_ = false;
    bool hasPrev_ = false;
    bool hasNext_ = false;
    FcitxCandidateLayoutHint layoutHint_ = FcitxCandidateLayoutHint::NotSet;
    int candidatesHeight_ = 0;
    QRect prevRegion_;
    QRect nextRegion_;
    std::vector<QRect> candidateRegions_;
    QPointer<QWindow> parent_;
    QPointer<QWindow> dummyParent_;
};

} // namespace fcitx

#endif // _PLATFORMINPUTCONTEXT_FCITXCANDIDATEWINDOW_H_
