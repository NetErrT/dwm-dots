#include <X11/XF86keysym.h>

// Appearance
static const unsigned int borderpx = 2;
static const unsigned int snap = 10;
static const int showbar = 1;
static const int topbar = 1;
static const char *fonts[] = {"Hack:size=10"};
// fg bg border
static const char theme[3][8] = {
    "#dbc1b2",
    "#170d07",
    "#29170c",
};

static const char *colors[][3] = {
    [SchemeNorm] = {theme[0], theme[1], theme[1]},
    [SchemeSel] = {theme[0], theme[2], theme[2]},
};

// Tags
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

static const Rule rules[] = {
    /* xprop:
     * WM_CLASS = instance, class.
     * WM_NAME = title.
     * settings: class, instance, title, tags index, isfloating, monitor */
    {"Firefox", NULL, NULL, 1 << 9, 0, -1},
    {"Godot_Editor", NULL, NULL, 1 << 8, 0, -1},
    {"Godot_Engine", NULL, NULL, 1 << 8, 1, -1},
    {"Blender", NULL, NULL, 1 << 7, 0, -1},
};

// Layouts
static const float mfact = 0.5;
static const int nmaster = 1;
static const int resizehints = 1;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
    {"Tile", tile},
    {"Float", NULL},
    {"Monocle[M]", monocle},
};

// Key definitions
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}}, {                      \
    MODKEY | ControlMask | ShiftMask, KEY, toggletag, { .ui = 1 << TAG }       \
  }
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

static const char *launchercmd[] = {"dmenu_run", "-nb", theme[1], "-nf",
                                    theme[0],    "-sb", theme[2], "-sf",
                                    theme[0],    NULL};
static const char *terminalcmd[] = {"alacritty", NULL};

static const Key keys[] = {
    // Appearance
    {MODKEY, XK_b, togglebar, {0}},

    // Applications
    {MODKEY, XK_p, spawn, {.v = launchercmd}},
    {MODKEY, XK_Return, spawn, {.v = terminalcmd}},

    // Layout
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY | ShiftMask, XK_h, incnmaster, {.i = +1}},
    {MODKEY | ShiftMask, XK_l, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},

    // Tags
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_f, togglefullscreen, {0}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0),
    TAGKEYS(XK_2, 1),
    TAGKEYS(XK_3, 2),
    TAGKEYS(XK_4, 3),
    TAGKEYS(XK_5, 4),
    TAGKEYS(XK_6, 5),
    TAGKEYS(XK_7, 6),
    TAGKEYS(XK_8, 7),
    TAGKEYS(XK_9, 8),
    TAGKEYS(XK_0, 9),

    // Basics
    {MODKEY, XK_w, killclient, {0}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY | ShiftMask, XK_r, spawn, SHCMD("pkexec reboot")},
    {MODKEY | ShiftMask, XK_p, spawn, SHCMD("pkexec poweroff")},

    // Fns
    {0, XF86XK_MonBrightnessUp, spawn, SHCMD("brightnessctl set 5%+")},
    {0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 5%-")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("amixer sset Master 5%+")},
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("amixer sset Master 5%-")},
    {0, XF86XK_AudioMute, spawn, SHCMD("amixer sset Master toggle")},
    {0, XF86XK_AudioMicMute, spawn, SHCMD("amixer sset Speaker toggle")},
    {0, XK_Print, spawn,
     SHCMD("scrot \"$(xdg-user-dir PICTURES)/screenshots/$(date "
           "+'%Y.%m.%d_%H.%M.%S').png\" -q 100")},
    {0 | ShiftMask, XK_Print, spawn,
     SHCMD("scrot -s \"$(xdg-user-dir PICTURES)/screenshots/$(date "
           "+'%Y.%m.%d_%H.%M.%S').png\" -q 100")},
};
static const Button buttons[] = {
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button2, spawn, {.v = launchercmd}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
