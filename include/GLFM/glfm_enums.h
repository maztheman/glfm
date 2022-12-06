#ifndef GLFM_ENUMS_H
#define GLFM_ENUMS_H

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

/// GLFMUserInterfaceChrome defines whether system UI chrome (status bar, navigation bar) is shown.
/// This value is ignored on Emscripten.
/// GLFMUserInterfaceChromeNavigation (default)
///  - Android: Show the navigation bar
///  - iOS: Show the home indicator on iPhone X
/// GLFMUserInterfaceChromeNavigationAndStatusBar:
///  - Android: Show the navigation bar and status bar
///  - iOS: Show status bar, and show the home indicator on iPhone X
/// GLFMUserInterfaceChromeFullscreen
///  - Android 2.3: Fullscreen
///  - Android 4.0 - 4.3: Navigation bar dimmed
///  - Android 4.4: Fullscreen immersive mode
///  - iOS: Fullscreen
typedef enum {
    GLFMUserInterfaceChromeNavigation,
    GLFMUserInterfaceChromeNavigationAndStatusBar,
    GLFMUserInterfaceChromeFullscreen,
} GLFMUserInterfaceChrome;

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
    GLFMMouseCursorText
} GLFMMouseCursor;

typedef enum {
    GLFMMouseWheelDeltaPixel,
    GLFMMouseWheelDeltaLine,
    GLFMMouseWheelDeltaPage
} GLFMMouseWheelDeltaType;

typedef enum {
    GLFMKeyBackspace = 0x08,
    GLFMKeyTab = 0x09,
    GLFMKeyEnter = 0x0d,
    GLFMKeyEscape = 0x1b,
    GLFMKeySpace = 0x20,
    GLFMKeyPageUp = 0x21,
    GLFMKeyPageDown = 0x22,
    GLFMKeyEnd = 0x23,
    GLFMKeyHome = 0x24,
    GLFMKeyLeft = 0x25,
    GLFMKeyUp = 0x26,
    GLFMKeyRight = 0x27,
    GLFMKeyDown = 0x28,
    GLFMKeyDelete = 0x2E,
    GLFMKeyNavBack = 0x1000,
    GLFMKeyNavMenu = 0x1001,
    GLFMKeyNavSelect = 0x1002,
    GLFMKeyPlayPause = 0x2000,
} GLFMKey;

typedef enum {
    GLFMKeyModifierShift = (1 << 0),
    GLFMKeyModifierCtrl = (1 << 1),
    GLFMKeyModifierAlt = (1 << 2),
    GLFMKeyModifierMeta = (1 << 3),
} GLFMKeyModifier;

typedef enum {
    GLFMKeyActionPressed,
    GLFMKeyActionRepeated,
    GLFMKeyActionReleased,
} GLFMKeyAction;

typedef enum {
    GLFMSensorAccelerometer, // Events are a vector in G's
    GLFMSensorMagnetometer, // Events are a vector in microteslas
    GLFMSensorGyroscope, // Events are a vector in radians/sec
    GLFMSensorRotationMatrix, // Events are a rotation matrix (X axis points North, Z axis is vertical)
} GLFMSensor;

typedef enum {
    GLFMHapticFeedbackLight,
    GLFMHapticFeedbackMedium,
    GLFMHapticFeedbackHeavy,
} GLFMHapticFeedbackStyle;

#endif