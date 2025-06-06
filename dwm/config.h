/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int snap           = 0;  /* snap pixel */
static const unsigned int gappih         = 5;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 5;  /* vert inner gap between windows */
static const unsigned int gappoh         = 5;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 5;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 0;   /* 0 means derive from font, >= 1 explicit height */
static const int focusonwheel            = 0;
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const char buttonbar[]            = "󰣇";

static const unsigned int systrayspacing = 1;   /* systray spacing */
static const int showsystray             = 0;   /* 0 means no systray */
static const unsigned int ulinepad = 15;         /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 0;     /* thickness / height of the underline */
static const unsigned int ulinevoffset = -2;     /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;                  /* 1 to show underline on all tags, 0 for just the active ones */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const int quit_empty_window_count = 0;   /* only allow dwm to quit if no (<= count) windows are open */
static const char *fonts[]               = { 
	"Iosevka NF:size=14:style=bold",
	"Material Design Icons Desktop:size=12",
};
static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#faedff";
static char normbgcolor[]                = "#000000"; // statusbar bg
static char normbordercolor[]            = "#000000";
static char normfloatcolor[]             = "#000000";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#faedff";
static char selfloatcolor[]              = "#faedff";

static char titlenormfgcolor[]           = "#9c9c9c";
static char titlenormbgcolor[]           = "#faedff";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#000000";
static char titleselbgcolor[]            = "#faedff";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#faedff";
static char tagsnormbgcolor[]            = "#000000";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#000000";
static char tagsselbgcolor[]             = "#faedff";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#0420bd";
static char hidnormbgcolor[]             = "#faedff";
static char hidselbgcolor[]              = "#faedff";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#870e00";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";
//

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

static const char *const autostart[] = {
	"xrdb","-load","$HOME/.Xresources", NULL,
	"xss-lock","--","slock", NULL,
	"sh","-c","$HOME/.dotfiles/scripts/wal-sync.sh", NULL,
	"sh","-c","$HOME/.dotfiles/scripts/autostart.sh", NULL,
	"sh","-c","$HOME/.dotfiles/scripts/batteryCheck.sh", NULL,
	"sxhkd", NULL,
	NULL /* terminate */
};


/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */

static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "󰅩", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)


	RULE(.class = "Gpick", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Lxappearance", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Pavucontrol", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Sxiv", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Nitrogen", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Thunar", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Nautilus", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Zathura", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Xarchiver", .isfloating = 1, .iscentered = 1)
	RULE(.class = "vlc", .isfloating = 1, .iscentered = 1)
	RULE(.class = "TablePlus", .isfloating = 1, .iscentered = 1)
	RULE(.class = "transmission-gtk", .isfloating = 1, .iscentered = 1)
	RULE(.class = "snapshot", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Bijiben", .isfloating = 1, .iscentered = 1)
	RULE(.class = "zoom", .switchtag = 0, .isfloating = 1, .iscentered = 1)
	RULE(.class = "Bijiben", .isfloating = 1, .iscentered = 1)
	RULE(.class = "obsidian", .isfloating = 1, .iscentered = 1)

	RULE(.class = "Code", .tags = 1 << 1, .switchtag = 1) // tag-2
	RULE(.class = "jetbrains-studio", .tags = 1 << 1, .switchtag = 1) // tag-2

	// browsers
	RULE(.class = "Chromium", .tags = 1 << 2, .switchtag = 1, .iscentered = 1) // tag-8
	RULE(.class = "Google-chrome", .tags = 1 << 2, .switchtag = 1, .iscentered = 1) // tag-8
	RULE(.class = "firefox", .tags = 1 << 2, .switchtag = 1, .iscentered = 1)
	RULE(.class = "zen", .tags = 1 << 2, .switchtag = 1, .iscentered = 1)
	RULE(.class = "Microsoft-edge", .tags = 1 << 2, .switchtag = 1, .iscentered = 1)

	RULE(.class = "Spotify", .tags = 1 << 3, .switchtag = 1)
	RULE(.class = "spotify", .tags = 1 << 3, .switchtag = 1)

	RULE(.class = "calibre", .tags = 1 << 4, .switchtag = 1) // tag-5

	RULE(.class = "qbittorrent", .tags = 1 << 4, .isfloating = 1, .iscentered = 1) // tag-5
	RULE(.class = "qBittorrent", .tags = 1 << 4, .isfloating = 1, .iscentered = 1) // tag-5
	RULE(.class = "Steam", .tags = 1 << 4, .isfloating = 1, .iscentered = 1) // tag-5
	RULE(.class = "Steam", .tags = 1 << 4, .isfloating = 1, .iscentered = 1) // tag-5
	RULE(.class = "steam", .tags = 1 << 4, .isfloating = 1, .iscentered = 1) // tag-5
	RULE(.class = "steamwebhelper", .tags = 1 << 4, .isfloating = 1, .iscentered = 1 ) // tag-5

	RULE(.class = "discord", .tags = 1 << 5) // tag-6
	RULE(.class = "vesktop", .tags = 1 << 5) // tag-6
	
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_stbutton,           draw_stbutton,          click_stbutton,          NULL,                    "statusbutton" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_status2d,          NULL,                    "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
	/* symbol     arrange function */
  /* first entry is default */
	{ "[]=",      tile },    
	{ "><>",      NULL },    /* no layout function means floating behavior */
	// { "[M]",      monocle },
	{ "[D]",      deck },
	// { "[\\]",     dwindle },
	{ "---",      horizgrid },
	{ NULL,       NULL },
};


/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *roficmd[] = { "rofi", "-show", "drun", "-sorting-method", "fzf", "-sort", "-matching", "fuzzy", NULL };
static const char *termcmd[]  = { "kitty", NULL };



static Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_p,          spawn,                  {.v = roficmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|ShiftMask,             XK_f,          togglefullscr,          {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|ControlMask,           XK_z,          showhideclient,         {0} },
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,                   {1} },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period,     cyclelayout,            {.i = +1 } },
	{ Mod4Mask,                       XK_F5,     xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkButton,            0,                   Button1,        spawn,          {.v = roficmd } },
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};


