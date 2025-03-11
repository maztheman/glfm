#pragma once

// So we can use this file standalone
#ifndef GLFM_DEPRECATED
#ifdef __GNUC__
#  define GLFM_DEPRECATED(message) __attribute__((deprecated(message)))
#else
#  define GLFM_DEPRECATED(message)
#endif
#endif

typedef enum {
    GLFMRenderingAPIOpenGLES2,
    GLFMRenderingAPIOpenGLES3,
    GLFMRenderingAPIOpenGLES31,
    GLFMRenderingAPIOpenGLES32,
    GLFMRenderingAPIMetal,
} GLFMRenderingAPI;

typedef enum {
    GLFMColorFormatRGBA8888,
    GLFMColorFormatRGB565,
} GLFMColorFormat;

typedef enum {
    GLFMDepthFormatNone,
    GLFMDepthFormat16,
    GLFMDepthFormat24,
    GLFMDepthFormat32,   ///< 32-bit floating point depth in Metal, 24-bit in OpenGL.
} GLFMDepthFormat;

typedef enum {
    GLFMStencilFormatNone,
    GLFMStencilFormat8,
} GLFMStencilFormat;

typedef enum {
    GLFMMultisampleNone,
    GLFMMultisample4X,
} GLFMMultisample;

typedef enum {
    GLFMSwapBehaviorPlatformDefault,
    GLFMSwapBehaviorBufferDestroyed,
    GLFMSwapBehaviorBufferPreserved,
} GLFMSwapBehavior;

/// Defines whether system UI chrome (status bar, navigation bar) is shown.
typedef enum {
    /// Displays the app with the navigation bar.
    ///  - Android: Show the navigation bar.
    ///  - iOS: Show the home indicator.
    GLFMUserInterfaceChromeNavigation,
    /// Displays the app with both the navigation bar and the status bar.
    ///  - Android: Show the navigation bar and status bar.
    ///  - iOS: Show both the home indicator and the status bar.
    GLFMUserInterfaceChromeNavigationAndStatusBar,
    /// Displays the app without any UI chrome.
    ///  - Android 2.3: Fullscreen.
    ///  - Android 4.0 - 4.3: Navigation bar dimmed.
    ///  - Android 4.4: Fullscreen immersive mode.
    ///  - iOS: Show the home indicator dimmed.
    GLFMUserInterfaceChromeNone,
} GLFMUserInterfaceChrome;

enum {
    GLFMUserInterfaceChromeFullscreen GLFM_DEPRECATED("Replaced with GLFMUserInterfaceChromeNone") = GLFMUserInterfaceChromeNone,
};

typedef enum {
    GLFMInterfaceOrientationUnknown = 0,
    GLFMInterfaceOrientationPortrait = (1 << 0),
    GLFMInterfaceOrientationPortraitUpsideDown = (1 << 1),
    GLFMInterfaceOrientationLandscapeLeft = (1 << 2),
    GLFMInterfaceOrientationLandscapeRight = (1 << 3),
    GLFMInterfaceOrientationLandscape = (GLFMInterfaceOrientationLandscapeLeft |
                                         GLFMInterfaceOrientationLandscapeRight),
    GLFMInterfaceOrientationAll = (GLFMInterfaceOrientationPortrait |
                                   GLFMInterfaceOrientationPortraitUpsideDown |
                                   GLFMInterfaceOrientationLandscapeLeft |
                                   GLFMInterfaceOrientationLandscapeRight),
    GLFMInterfaceOrientationAllButUpsideDown = (GLFMInterfaceOrientationPortrait |
                                                GLFMInterfaceOrientationLandscapeLeft |
                                                GLFMInterfaceOrientationLandscapeRight),
} GLFMInterfaceOrientation;

/// *Deprecated:* See ``GLFMInterfaceOrientation``.
typedef enum {
    GLFMUserInterfaceOrientationAny GLFM_DEPRECATED("Replaced with GLFMInterfaceOrientationAll") = GLFMInterfaceOrientationAll,
    GLFMUserInterfaceOrientationPortrait GLFM_DEPRECATED("Replaced with GLFMInterfaceOrientationPortrait") = GLFMInterfaceOrientationPortrait,
    GLFMUserInterfaceOrientationLandscape GLFM_DEPRECATED("Replaced with GLFMInterfaceOrientationLandscape") = GLFMInterfaceOrientationLandscape,
} GLFMUserInterfaceOrientation GLFM_DEPRECATED("Replaced with GLFMInterfaceOrientation");

typedef enum {
    GLFMTouchPhaseHover,
    GLFMTouchPhaseBegan,
    GLFMTouchPhaseMoved,
    GLFMTouchPhaseEnded,
    GLFMTouchPhaseCancelled,
} GLFMTouchPhase;

typedef enum {
    GLFMMouseCursorAuto,
    GLFMMouseCursorNone,
    GLFMMouseCursorDefault,
    GLFMMouseCursorPointer,
    GLFMMouseCursorCrosshair,
    GLFMMouseCursorText,
    GLFMMouseCursorVerticalText,
} GLFMMouseCursor;

typedef enum {
    GLFMMouseWheelDeltaPixel,
    GLFMMouseWheelDeltaLine,
    GLFMMouseWheelDeltaPage
} GLFMMouseWheelDeltaType;

typedef enum {
    GLFMKeyCodeUnknown           = 0x00,

    // The key codes below have the same values as ASCII codes (uppercase)

    GLFMKeyCodeBackspace         = 0x08, ///< Backspace key ("delete" on Apple platforms).
    GLFMKeyCodeTab               = 0x09,
    GLFMKeyCodeEnter             = 0x0D, ///< Enter key ("return" on Apple platforms).
    GLFMKeyCodeEscape            = 0x1B,
    GLFMKeyCodeSpace             = 0x20,
    GLFMKeyCodeQuote             = 0x27,
    GLFMKeyCodeComma             = 0x2C,
    GLFMKeyCodeMinus             = 0x2D,
    GLFMKeyCodePeriod            = 0x2E,
    GLFMKeyCodeSlash             = 0x2F,
    GLFMKeyCode0                 = 0x30,
    GLFMKeyCode1                 = 0x31,
    GLFMKeyCode2                 = 0x32,
    GLFMKeyCode3                 = 0x33,
    GLFMKeyCode4                 = 0x34,
    GLFMKeyCode5                 = 0x35,
    GLFMKeyCode6                 = 0x36,
    GLFMKeyCode7                 = 0x37,
    GLFMKeyCode8                 = 0x38,
    GLFMKeyCode9                 = 0x39,
    GLFMKeyCodeSemicolon         = 0x3B,
    GLFMKeyCodeEqual             = 0x3D,
    GLFMKeyCodeA                 = 0x41,
    GLFMKeyCodeB                 = 0x42,
    GLFMKeyCodeC                 = 0x43,
    GLFMKeyCodeD                 = 0x44,
    GLFMKeyCodeE                 = 0x45,
    GLFMKeyCodeF                 = 0x46,
    GLFMKeyCodeG                 = 0x47,
    GLFMKeyCodeH                 = 0x48,
    GLFMKeyCodeI                 = 0x49,
    GLFMKeyCodeJ                 = 0x4A,
    GLFMKeyCodeK                 = 0x4B,
    GLFMKeyCodeL                 = 0x4C,
    GLFMKeyCodeM                 = 0x4D,
    GLFMKeyCodeN                 = 0x4E,
    GLFMKeyCodeO                 = 0x4F,
    GLFMKeyCodeP                 = 0x50,
    GLFMKeyCodeQ                 = 0x51,
    GLFMKeyCodeR                 = 0x52,
    GLFMKeyCodeS                 = 0x53,
    GLFMKeyCodeT                 = 0x54,
    GLFMKeyCodeU                 = 0x55,
    GLFMKeyCodeV                 = 0x56,
    GLFMKeyCodeW                 = 0x57,
    GLFMKeyCodeX                 = 0x58,
    GLFMKeyCodeY                 = 0x59,
    GLFMKeyCodeZ                 = 0x5A,
    GLFMKeyCodeBracketLeft       = 0x5B,
    GLFMKeyCodeBackslash         = 0x5C,
    GLFMKeyCodeBracketRight      = 0x5D,
    GLFMKeyCodeBackquote         = 0x60, ///< Backquote, AKA grave.
    GLFMKeyCodeDelete            = 0x7F, ///< Delete key ("forward delete" on Apple platforms).

    // Non-ASCII keys. These values may change in the future.

    GLFMKeyCodeCapsLock          = 0x80,
    GLFMKeyCodeShiftLeft         = 0x81,
    GLFMKeyCodeShiftRight        = 0x82,
    GLFMKeyCodeControlLeft       = 0x83,
    GLFMKeyCodeControlRight      = 0x84,
    GLFMKeyCodeAltLeft           = 0x85, ///< Left alt key (option key on Apple platforms).
    GLFMKeyCodeAltRight          = 0x86, ///< Right alt key (option key on Apple platforms).
    GLFMKeyCodeMetaLeft          = 0x87, ///< Left meta key (command key on Apple platforms).
    GLFMKeyCodeMetaRight         = 0x88, ///< Right meta key (command key on Apple platforms).
    GLFMKeyCodeMenu              = 0x89, ///< Menu key, AKA context menu.

    GLFMKeyCodeInsert            = 0x90,
    GLFMKeyCodePageUp            = 0x91,
    GLFMKeyCodePageDown          = 0x92,
    GLFMKeyCodeEnd               = 0x93,
    GLFMKeyCodeHome              = 0x94,
    GLFMKeyCodeArrowLeft         = 0x95,
    GLFMKeyCodeArrowUp           = 0x96,
    GLFMKeyCodeArrowRight        = 0x97,
    GLFMKeyCodeArrowDown         = 0x98,

    GLFMKeyCodePower             = 0x99,
    GLFMKeyCodeFunction          = 0x9A, ///< Fn key on Apple platforms.
    GLFMKeyCodePrintScreen       = 0x9B, ///< Print Screen or System Request key.
    GLFMKeyCodeScrollLock        = 0x9C,
    GLFMKeyCodePause             = 0x9D, ///< Pause/Break key.

    GLFMKeyCodeNumLock           = 0xA0, ///< NumLock key ("clear" on Apple platforms).
    GLFMKeyCodeNumpadDecimal     = 0xA1,
    GLFMKeyCodeNumpadMultiply    = 0xA2,
    GLFMKeyCodeNumpadAdd         = 0xA3,
    GLFMKeyCodeNumpadDivide      = 0xA4,
    GLFMKeyCodeNumpadEnter       = 0xA5,
    GLFMKeyCodeNumpadSubtract    = 0xA6,
    GLFMKeyCodeNumpadEqual       = 0xA7,

    GLFMKeyCodeNumpad0           = 0xB0,
    GLFMKeyCodeNumpad1           = 0xB1,
    GLFMKeyCodeNumpad2           = 0xB2,
    GLFMKeyCodeNumpad3           = 0xB3,
    GLFMKeyCodeNumpad4           = 0xB4,
    GLFMKeyCodeNumpad5           = 0xB5,
    GLFMKeyCodeNumpad6           = 0xB6,
    GLFMKeyCodeNumpad7           = 0xB7,
    GLFMKeyCodeNumpad8           = 0xB8,
    GLFMKeyCodeNumpad9           = 0xB9,

    GLFMKeyCodeF1                = 0xC1,
    GLFMKeyCodeF2                = 0xC2,
    GLFMKeyCodeF3                = 0xC3,
    GLFMKeyCodeF4                = 0xC4,
    GLFMKeyCodeF5                = 0xC5,
    GLFMKeyCodeF6                = 0xC6,
    GLFMKeyCodeF7                = 0xC7,
    GLFMKeyCodeF8                = 0xC8,
    GLFMKeyCodeF9                = 0xC9,
    GLFMKeyCodeF10               = 0xD0,
    GLFMKeyCodeF11               = 0xD1,
    GLFMKeyCodeF12               = 0xD2,
    GLFMKeyCodeF13               = 0xD3,
    GLFMKeyCodeF14               = 0xD4,
    GLFMKeyCodeF15               = 0xD5,
    GLFMKeyCodeF16               = 0xD6,
    GLFMKeyCodeF17               = 0xD7,
    GLFMKeyCodeF18               = 0xD8,
    GLFMKeyCodeF19               = 0xD9,
    GLFMKeyCodeF20               = 0xDA,
    GLFMKeyCodeF21               = 0xDB,
    GLFMKeyCodeF22               = 0xDC,
    GLFMKeyCodeF23               = 0xDD,
    GLFMKeyCodeF24               = 0xDE,

    GLFMKeyCodeNavigationBack    = 0xE0, ///< Back button on Android, menu/back button on tvOS remote.
    GLFMKeyCodeMediaSelect       = 0xE1, ///< Select button on tvOS remote.
    GLFMKeyCodeMediaPlayPause    = 0xE2, ///< Play/pause button on tvOS remote.
} GLFMKeyCode;

typedef GLFMKeyCode GLFMKey GLFM_DEPRECATED("Replaced with GLFMKeyCode");

enum {
    GLFMKeyBackspace GLFM_DEPRECATED("Replaced with GLFMKeyCodeBackspace") = GLFMKeyCodeBackspace,
    GLFMKeyTab GLFM_DEPRECATED("Replaced with GLFMKeyCodeTab") = GLFMKeyCodeTab,
    GLFMKeyEnter GLFM_DEPRECATED("Replaced with GLFMKeyCodeEnter") = GLFMKeyCodeEnter,
    GLFMKeyEscape GLFM_DEPRECATED("Replaced with GLFMKeyCodeEscape") = GLFMKeyCodeEscape,
    GLFMKeySpace GLFM_DEPRECATED("Replaced with GLFMKeyCodeSpace") = GLFMKeyCodeSpace,
    GLFMKeyPageUp GLFM_DEPRECATED("Replaced with GLFMKeyCodePageUp") = GLFMKeyCodePageUp,
    GLFMKeyPageDown GLFM_DEPRECATED("Replaced with GLFMKeyCodePageDown") = GLFMKeyCodePageDown,
    GLFMKeyEnd GLFM_DEPRECATED("Replaced with GLFMKeyCodeEnd") = GLFMKeyCodeEnd,
    GLFMKeyHome GLFM_DEPRECATED("Replaced with GLFMKeyCodeHome") = GLFMKeyCodeHome,
    GLFMKeyLeft GLFM_DEPRECATED("Replaced with GLFMKeyCodeArrowLeft") = GLFMKeyCodeArrowLeft,
    GLFMKeyUp GLFM_DEPRECATED("Replaced with GLFMKeyCodeArrowUp") = GLFMKeyCodeArrowUp,
    GLFMKeyRight GLFM_DEPRECATED("Replaced with GLFMKeyCodeArrowRight") = GLFMKeyCodeArrowRight,
    GLFMKeyDown GLFM_DEPRECATED("Replaced with GLFMKeyCodeArrowDown") = GLFMKeyCodeArrowDown,
    GLFMKeyDelete GLFM_DEPRECATED("Replaced with GLFMKeyCodeDelete") = GLFMKeyCodeDelete,
    GLFMKeyNavBack GLFM_DEPRECATED("Replaced with GLFMKeyCodeNavigationBack") = GLFMKeyCodeNavigationBack,
    GLFMKeyNavMenu GLFM_DEPRECATED("Replaced with GLFMKeyCodeMenu") = GLFMKeyCodeMenu,
    GLFMKeyNavSelect GLFM_DEPRECATED("Replaced with GLFMKeyCodeMediaSelect") = GLFMKeyCodeMediaSelect,
    GLFMKeyPlayPause GLFM_DEPRECATED("Replaced with GLFMKeyCodeMediaPlayPause") = GLFMKeyCodeMediaPlayPause,
};

typedef enum {
    GLFMKeyModifierShift    = (1 << 0), ///< Flag indicating a shift key is down.
    GLFMKeyModifierControl  = (1 << 1), ///< Flag indicating a control (ctrl) key is down.
    GLFMKeyModifierAlt      = (1 << 2), ///< Flag indicating an alt key is down (option key on Apple platforms).
    GLFMKeyModifierMeta     = (1 << 3), ///< Flag indicating a meta key is down (command key on Apple platforms).
    GLFMKeyModifierFunction = (1 << 4), ///< Flag indicating a function (fn) key is down on Apple platforms.
} GLFMKeyModifier;

enum {
    GLFMKeyModifierCtrl GLFM_DEPRECATED("Replaced with GLFMKeyModifierControl") = GLFMKeyModifierControl,
};

typedef enum {
    GLFMKeyActionPressed,
    GLFMKeyActionRepeated,
    GLFMKeyActionReleased,
} GLFMKeyAction;

/// The hardware sensor type. See ``glfmIsSensorAvailable`` and ``glfmSetSensorFunc``.
typedef enum {
    /// Accelerometer sensor.
    /// In ``GLFMSensorFunc``, the `GLFMSensorEvent` vector is the acceleration in G's.
    GLFMSensorAccelerometer,
    /// Magnetometer sensor.
    /// In ``GLFMSensorFunc``, the `GLFMSensorEvent` vector is the magnetic field in microteslas.
    GLFMSensorMagnetometer,
    /// Gyroscope sensor.
    /// In ``GLFMSensorFunc``, the `GLFMSensorEvent` vector is the rotation rate in radians/second.
    GLFMSensorGyroscope,
    /// Rotation sensor.
    /// In ``GLFMSensorFunc``, the `GLFMSensorEvent` matrix is the rotation matrix where the
    /// X axis points North and the Z axis is vertical.
    GLFMSensorRotationMatrix,
} GLFMSensor;

typedef enum {
    GLFMHapticFeedbackLight,
    GLFMHapticFeedbackMedium,
    GLFMHapticFeedbackHeavy,
} GLFMHapticFeedbackStyle;