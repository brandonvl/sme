#pragma once

namespace Sarene
{
    typedef enum class KeyCode : uint16_t
    {
        // From glfw3.h
        Space               = 32,
        Apostrophe          = 39,  /* ' */
        Comma               = 44,  /* , */
        Minus               = 45,  /* - */
        Period              = 46,  /* . */
        Slash               = 47,  /* / */

        D0                  = 48,  
        D1                  = 49,
        D2                  = 50,
        D3                  = 51,
        D4                  = 52,
        D5                  = 53,
        D6                  = 54,
        D7                  = 55,
        D8                  = 56,
        D9                  = 57,

        Semicolon           = 59,  /* ; */
        Equal               = 61,  /* = */

        A                   = 65,
        B                   = 66,
        C                   = 67,
        D                   = 68,
        E                   = 69,
        F                   = 70,
        G                   = 71,
        H                   = 72,
        I                   = 73,
        J                   = 74,
        K                   = 75,
        L                   = 76,
        M                   = 77,
        N                   = 78,
        O                   = 79,
        P                   = 80,
        Q                   = 81,
        R                   = 82,
        S                   = 83,
        T                   = 84,
        U                   = 85,
        V                   = 86,
        W                   = 87,
        X                   = 88,
        Y                   = 89,
        Z                   = 90,

        LeftBracket         = 91,  /* [ */
        Backslash           = 92,  /* \ */
        RightBracket        = 93,  /* ] */
        GraveAccent         = 96,  /* ` */

        World1              = 161, /* non-US #1 */
        World2              = 162, /* non-US #2 */

        /* Function keys */
        Escape              = 256,
        Enter               = 257,
        Tab                 = 258,
        Backspace           = 259,
        Insert              = 260,
        Delete              = 261,
        Right               = 262,
        Left                = 263,
        Down                = 264,
        Up                  = 265,
        PageUp              = 266,
        PageDown            = 267,
        Home                = 268,
        End                 = 269,
        CapsLock            = 280,
        ScrollLock          = 281,
        NumLock             = 282,
        PrintScreen         = 283,
        Pause               = 284,
        F1                  = 290,
        F2                  = 291,
        F3                  = 292,
        F4                  = 293,
        F5                  = 294,
        F6                  = 295,
        F7                  = 296,
        F8                  = 297,
        F9                  = 298,
        F10                 = 299,
        F11                 = 300,
        F12                 = 301,
        F13                 = 302,
        F14                 = 303,
        F15                 = 304,
        F16                 = 305,
        F17                 = 306,
        F18                 = 307,
        F19                 = 308,
        F20                 = 309,
        F21                 = 310,
        F22                 = 311,
        F23                 = 312,
        F24                 = 313,
        F25                 = 314,

        /* Keypad */
        KP0                 = 320,
        KP1                 = 321,
        KP2                 = 322,
        KP3                 = 323,
        KP4                 = 324,
        KP5                 = 325,
        KP6                 = 326,
        KP7                 = 327,
        KP8                 = 328,
        KP9                 = 329,
        KPDecimal           = 330,
        KPDivide            = 331,
        KPMultiply          = 332,
        KPSubtract          = 333,
        KPAdd               = 334,
        KPEnter             = 335,
        KPEqual             = 336,

        LeftShift           = 340,
        LeftControl         = 341,
        LeftAlt             = 342,
        LeftSuper           = 343,
        RightShift          = 344,
        RightControl        = 345,
        RightAlt            = 346,
        RightSuper          = 347,
        Menu                = 348
    } Key;

    inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
    {
        os << static_cast<int32_t>(keyCode);
        return os;
    }
};

// From glfw3.h
#define SAR_KEY_SPACE              ::Sarene::Key::Space
#define SAR_KEY_APOSTROPHE         ::Sarene::Key::Apostrophe    /* ' */
#define SAR_KEY_COMMA              ::Sarene::Key::Comma         /* , */
#define SAR_KEY_MINUS              ::Sarene::Key::Minus         /* - */
#define SAR_KEY_PERIOD             ::Sarene::Key::Period        /* . */
#define SAR_KEY_SLASH              ::Sarene::Key::Slash         /* / */
#define SAR_KEY_0                  ::Sarene::Key::D0
#define SAR_KEY_1                  ::Sarene::Key::D1
#define SAR_KEY_2                  ::Sarene::Key::D2
#define SAR_KEY_3                  ::Sarene::Key::D3
#define SAR_KEY_4                  ::Sarene::Key::D4
#define SAR_KEY_5                  ::Sarene::Key::D5
#define SAR_KEY_6                  ::Sarene::Key::D6
#define SAR_KEY_7                  ::Sarene::Key::D7
#define SAR_KEY_8                  ::Sarene::Key::D8
#define SAR_KEY_9                  ::Sarene::Key::D9
#define SAR_KEY_SEMICOLON          ::Sarene::Key::Semicolon     /* ; */
#define SAR_KEY_EQUAL              ::Sarene::Key::Equal         /* = */
#define SAR_KEY_A                  ::Sarene::Key::A
#define SAR_KEY_B                  ::Sarene::Key::B
#define SAR_KEY_C                  ::Sarene::Key::C
#define SAR_KEY_D                  ::Sarene::Key::D
#define SAR_KEY_E                  ::Sarene::Key::E
#define SAR_KEY_F                  ::Sarene::Key::F
#define SAR_KEY_G                  ::Sarene::Key::G
#define SAR_KEY_H                  ::Sarene::Key::H
#define SAR_KEY_I                  ::Sarene::Key::I
#define SAR_KEY_J                  ::Sarene::Key::J
#define SAR_KEY_K                  ::Sarene::Key::K
#define SAR_KEY_L                  ::Sarene::Key::L
#define SAR_KEY_M                  ::Sarene::Key::M
#define SAR_KEY_N                  ::Sarene::Key::N
#define SAR_KEY_O                  ::Sarene::Key::O
#define SAR_KEY_P                  ::Sarene::Key::P
#define SAR_KEY_Q                  ::Sarene::Key::Q
#define SAR_KEY_R                  ::Sarene::Key::R
#define SAR_KEY_S                  ::Sarene::Key::S
#define SAR_KEY_T                  ::Sarene::Key::T
#define SAR_KEY_U                  ::Sarene::Key::U
#define SAR_KEY_V                  ::Sarene::Key::V
#define SAR_KEY_W                  ::Sarene::Key::W
#define SAR_KEY_X                  ::Sarene::Key::X
#define SAR_KEY_Y                  ::Sarene::Key::Y
#define SAR_KEY_Z                  ::Sarene::Key::Z
#define SAR_KEY_LEFT_BRACKET       ::Sarene::Key::LeftBracket   /* [ */
#define SAR_KEY_BACKSLASH          ::Sarene::Key::Backslash     /* \ */
#define SAR_KEY_RIGHT_BRACKET      ::Sarene::Key::RightBracket  /* ] */
#define SAR_KEY_GRAVE_ACCENT       ::Sarene::Key::GraveAccent   /* ` */
#define SAR_KEY_WORLD_1            ::Sarene::Key::World1        /* non-US #1 */
#define SAR_KEY_WORLD_2            ::Sarene::Key::World2        /* non-US #2 */

/* Function keys */
#define SAR_KEY_ESCAPE             ::Sarene::Key::Escape
#define SAR_KEY_ENTER              ::Sarene::Key::Enter
#define SAR_KEY_TAB                ::Sarene::Key::Tab
#define SAR_KEY_BACKSPACE          ::Sarene::Key::Backspace
#define SAR_KEY_INSERT             ::Sarene::Key::Insert
#define SAR_KEY_DELETE             ::Sarene::Key::Delete
#define SAR_KEY_RIGHT              ::Sarene::Key::Right
#define SAR_KEY_LEFT               ::Sarene::Key::Left
#define SAR_KEY_DOWN               ::Sarene::Key::Down
#define SAR_KEY_UP                 ::Sarene::Key::Up
#define SAR_KEY_PAGE_UP            ::Sarene::Key::PageUp
#define SAR_KEY_PAGE_DOWN          ::Sarene::Key::PageDown
#define SAR_KEY_HOME               ::Sarene::Key::Home
#define SAR_KEY_END                ::Sarene::Key::End
#define SAR_KEY_CAPS_LOCK          ::Sarene::Key::CapsLock
#define SAR_KEY_SCROLL_LOCK        ::Sarene::Key::ScrollLock
#define SAR_KEY_NUM_LOCK           ::Sarene::Key::NumLock
#define SAR_KEY_PRINT_SCREEN       ::Sarene::Key::PrintScreen
#define SAR_KEY_PAUSE              ::Sarene::Key::Pause
#define SAR_KEY_F1                 ::Sarene::Key::F1
#define SAR_KEY_F2                 ::Sarene::Key::F2
#define SAR_KEY_F3                 ::Sarene::Key::F3
#define SAR_KEY_F4                 ::Sarene::Key::F4
#define SAR_KEY_F5                 ::Sarene::Key::F5
#define SAR_KEY_F6                 ::Sarene::Key::F6
#define SAR_KEY_F7                 ::Sarene::Key::F7
#define SAR_KEY_F8                 ::Sarene::Key::F8
#define SAR_KEY_F9                 ::Sarene::Key::F9
#define SAR_KEY_F10                ::Sarene::Key::F10
#define SAR_KEY_F11                ::Sarene::Key::F11
#define SAR_KEY_F12                ::Sarene::Key::F12
#define SAR_KEY_F13                ::Sarene::Key::F13
#define SAR_KEY_F14                ::Sarene::Key::F14
#define SAR_KEY_F15                ::Sarene::Key::F15
#define SAR_KEY_F16                ::Sarene::Key::F16
#define SAR_KEY_F17                ::Sarene::Key::F17
#define SAR_KEY_F18                ::Sarene::Key::F18
#define SAR_KEY_F19                ::Sarene::Key::F19
#define SAR_KEY_F20                ::Sarene::Key::F20
#define SAR_KEY_F21                ::Sarene::Key::F21
#define SAR_KEY_F22                ::Sarene::Key::F22
#define SAR_KEY_F23                ::Sarene::Key::F23
#define SAR_KEY_F24                ::Sarene::Key::F24
#define SAR_KEY_F25                ::Sarene::Key::F25

/* Keypad */
#define SAR_KEY_KP_0               ::Sarene::Key::KP0
#define SAR_KEY_KP_1               ::Sarene::Key::KP1
#define SAR_KEY_KP_2               ::Sarene::Key::KP2
#define SAR_KEY_KP_3               ::Sarene::Key::KP3
#define SAR_KEY_KP_4               ::Sarene::Key::KP4
#define SAR_KEY_KP_5               ::Sarene::Key::KP5
#define SAR_KEY_KP_6               ::Sarene::Key::KP6
#define SAR_KEY_KP_7               ::Sarene::Key::KP7
#define SAR_KEY_KP_8               ::Sarene::Key::KP8
#define SAR_KEY_KP_9               ::Sarene::Key::KP9
#define SAR_KEY_KP_DECIMAL         ::Sarene::Key::KPDecimal
#define SAR_KEY_KP_DIVIDE          ::Sarene::Key::KPDivide
#define SAR_KEY_KP_MULTIPLY        ::Sarene::Key::KPMultiply
#define SAR_KEY_KP_SUBTRACT        ::Sarene::Key::KPSubtract
#define SAR_KEY_KP_ADD             ::Sarene::Key::KPAdd
#define SAR_KEY_KP_ENTER           ::Sarene::Key::KPEnter
#define SAR_KEY_KP_EQUAL           ::Sarene::Key::KPEqual

#define SAR_KEY_LEFT_SHIFT         ::Sarene::Key::LeftShift
#define SAR_KEY_LEFT_CONTROL       ::Sarene::Key::LeftControl
#define SAR_KEY_LEFT_ALT           ::Sarene::Key::LeftAlt
#define SAR_KEY_LEFT_SUPER         ::Sarene::Key::LeftSuper
#define SAR_KEY_RIGHT_SHIFT        ::Sarene::Key::RightShift
#define SAR_KEY_RIGHT_CONTROL      ::Sarene::Key::RightControl
#define SAR_KEY_RIGHT_ALT          ::Sarene::Key::RightAlt
#define SAR_KEY_RIGHT_SUPER        ::Sarene::Key::RightSuper
#define SAR_KEY_MENU               ::Sarene::Key::Menu