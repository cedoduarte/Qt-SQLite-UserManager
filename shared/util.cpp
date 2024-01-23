#include "util.h"

#include <windows.h>
#include <set>
#include <QKeyCombination>

bool Util::keyIsNotPrintable(int qtKey)
{
    static const std::set<int> nonPrintableKeyList {
        Qt::Key_Escape,
        Qt::Key_Tab,
        Qt::Key_Backtab,
        Qt::Key_Backspace,
        Qt::Key_Return,
        Qt::Key_Enter,
        Qt::Key_Insert,
        Qt::Key_Delete,
        Qt::Key_Pause,
        Qt::Key_Print,
        Qt::Key_SysReq,
        Qt::Key_Clear,
        Qt::Key_Home,
        Qt::Key_End,
        Qt::Key_Left,
        Qt::Key_Up,
        Qt::Key_Right,
        Qt::Key_Down,
        Qt::Key_PageUp,
        Qt::Key_PageDown,
        Qt::Key_Shift,
        Qt::Key_Control,
        Qt::Key_Meta,
        Qt::Key_Alt,
        Qt::Key_CapsLock,
        Qt::Key_NumLock,
        Qt::Key_ScrollLock,
        Qt::Key_F1,
        Qt::Key_F2,
        Qt::Key_F3,
        Qt::Key_F4,
        Qt::Key_F5,
        Qt::Key_F6,
        Qt::Key_F7,
        Qt::Key_F8,
        Qt::Key_F9,
        Qt::Key_F10,
        Qt::Key_F11,
        Qt::Key_F12,
        Qt::Key_F13,
        Qt::Key_F14,
        Qt::Key_F15,
        Qt::Key_F16,
        Qt::Key_F17,
        Qt::Key_F18,
        Qt::Key_F19,
        Qt::Key_F20,
        Qt::Key_F21,
        Qt::Key_F22,
        Qt::Key_F23,
        Qt::Key_F24,
        Qt::Key_F25,
        Qt::Key_F26,
        Qt::Key_F27,
        Qt::Key_F28,
        Qt::Key_F29,
        Qt::Key_F30,
        Qt::Key_F31,
        Qt::Key_F32,
        Qt::Key_F33,
        Qt::Key_F34,
        Qt::Key_F35,
        Qt::Key_Super_L,
        Qt::Key_Super_R,
        Qt::Key_Menu,
        Qt::Key_Hyper_L,
        Qt::Key_Hyper_R,
        Qt::Key_Help,
        Qt::Key_Direction_L,
        Qt::Key_Direction_R,
        Qt::Key_AltGr,
        Qt::Key_Multi_key,
        Qt::Key_Codeinput,
        Qt::Key_SingleCandidate,
        Qt::Key_MultipleCandidate,
        Qt::Key_PreviousCandidate
    };
    return nonPrintableKeyList.count(qtKey) == 1;
}

bool Util::capsLockIsActivated()
{
    bool isCapsLockOn = GetKeyState(VK_CAPITAL) == 1;
    return isCapsLockOn;
}
