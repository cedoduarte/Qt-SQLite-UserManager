#ifndef SHA256JEREMY_GLOBAL_H
#define SHA256JEREMY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SHA256JEREMY_LIBRARY)
#define SHA256JEREMY_EXPORT Q_DECL_EXPORT
#else
#define SHA256JEREMY_EXPORT Q_DECL_IMPORT
#endif

#endif // SHA256JEREMY_GLOBAL_H
