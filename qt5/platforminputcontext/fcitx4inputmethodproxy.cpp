/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -N -p fcitx4inputmethodproxy -c
 * Fcitx4InputMethodProxy org.fcitx.Fcitx.InputMethod.xml
 * org.fcitx.Fcitx.InputMethod
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "fcitx4inputmethodproxy.h"

namespace fcitx {
/*
 * Implementation of interface class Fcitx4InputMethodProxy
 */

Fcitx4InputMethodProxy::Fcitx4InputMethodProxy(
    const QString &service, const QString &path,
    const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection,
                             parent) {}

Fcitx4InputMethodProxy::~Fcitx4InputMethodProxy() {}

} // namespace fcitx