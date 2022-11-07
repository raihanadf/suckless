/* user and group to drop privileges to */
static const char *user  = "raihan";
static const char *group = "nobody"; // use "nobody" for arch

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
	[CAPS] =   "red",       /* CapsLock on */
	[BLOCKS] = "#ffffff",   /* key feedback block */
};

/* default message */
/* static const char * message = "Locked!: ketik langsung aja passwordnya \njangan aneh-aneh -R"; */
static const char * message = "";

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
static const char * font_name = "6x13";

/* Background image path, should be available to the user above */
static const char * background_image = "/home/raihan/Pictures/Wallpapers/bluescreen.jpg";




/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;







static short int blocks_enabled = 1; // 0 = don't show blocks
static const int blocks_width = 0; // 0 = full width
static const int blocks_height = 10;

// position
static const int blocks_x = 0;
static const int blocks_y = 0;

// Number of blocks
static const int blocks_count = 10;


