// neatvi configuration file 

#define MKFILE_MODE	0600

static struct filetype {
	char *ft;		// file type 
	char *pat;		// file name pattern
} filetypes[] = {
	{"sh", "\\.sh$"},				// shell script
	{"c", "\\.(h|c)$"},				// C 
	{"roff", "\\.(t|aux|[1-9]|bib)$|tmac\\."},	// troff
	{"msg", "(mutt|COMMIT)"},			// email
	{"mk", "\\.(d|mk)$|[Mm]akefile$"},		// makefile
	{"diff", "\\.(patch|diff)$"}			// diff
};

#define COMMENT 7 | SYN_IT
#define STRING  9 | SYN_IT
#define KEYWORD 4
#define OTHER 3

static struct highlight {
	char *ft;		// the filetype of this pattern
	int att[16];		// attributes of the matched groups 
	char *pat;		// regular expression 
	int end;		// the group ending this pattern 
} highlights[] = {
	// c code
	{"c", {COMMENT}, "//.*$"},
	{"c", {STRING}, "\"[^\"]*\""},
	{"c", {KEYWORD}, "\\<(return|for|while|if|else|do|sizeof|goto|switch|case|default|break|continue)\\>"},
	{"c", {KEYWORD}, "\\<(auto|char|short|int|long|float|double|void|struct|enum|union|typedef)\\>"},
	{"c", {KEYWORD}, "\\<(signed|volatile|unsigned|static|inline|const|extern|register)\\>"},
	{"c", {OTHER}, "^#.*$"},
	{"c", {OTHER}, "[A-Z_]+"},
	{"c", {OTHER}, "[-+]?\\<(0[xX][0-9a-fA-F]+|0[bB][0-1]+|[0-9]+)\\>"},
	{"c", {OTHER}, "'\\\\?.'" },

	// roff
	{"roff", {SYN_BD | KEYWORD}, "^[%.][ \t]*[^ \t$]+" },
	{"roff", {OTHER}, "\\$[^$]+\\$"},
	{"roff", {STRING}, "\\\\[\\]?[AbBCDhHlLNRsSvwxXZ]'[^']+'"},
	{"roff", {OTHER}, "\\\\[\\]?[\\*fFgkmMnsVY]?[+-]?(\\[[^\\]+\\]|\\(..)"},
	{"roff", {OTHER}, "\\\\[\\]?([a-zA-Z]+|\\$.)"},

	// mail
	{"msg", {COMMENT}, "#.*$" },
	{"msg", {SYN_BD}, "^.+:"},
	{"msg", {OTHER | SYN_IT}, "^> .*$"},

	// makefile 
	{"mk", {COMMENT}, "#.*$"},
	{"mk", {KEYWORD}, "^[^\t]+[^\t ]*="},
	{"mk", {SYN_BD}, "^[^\t]+:"},
	{"mk", {OTHER}, "\\$[\\{\\(][^ \t\\}\\)]+[\\}\\)]"},
	{"mk", {OTHER}, "\\$."},

	// diff
	{"diff", {COMMENT}, "^@.*$"},
	{"diff", {SYN_BD}, "^diff .*$"},
	{"diff", {1}, "^-.*$"},
	{"diff", {2}, "^\\+.*$"},

	// sh
	{"sh", {COMMENT}, "#.*$"},
	{"sh", {STRING}, "'[^']*'"},
	{"sh", {STRING}, "\"[^\"]*\""},
	{"sh", {OTHER}, "\\$[\\{\\(][^\\}\\)]+[\\}\\)]"},
	{"sh", {OTHER}, "\\$[^ \t$/]+"},
	{"sh", {KEYWORD}, "\\<(break|case|continue|do|done|elif|else|esac|fi|for|if|in|then|until|while|return)\\>"},
	{"sh", {SYN_BD}, "^\\. .*$"},
};

#define SYN_LINE	(SYN_BGMK(11))
#define SYN_REVDIR	(SYN_BGMK(7))
#define LNPREF		""
#define CNEUT		"-!\"#$%&'()*+,./:;<=>?@^_`{|}~ "

// direction context patterns; specifies the direction of a whole line 
static struct dircontext {
	int dir;
	char *pat;
} dircontexts[] = {
	{+1, "^[a-zA-Z_0-9]"},
};

// direction marks; the direction of a few words in a line 
static struct dirmark {
	int ctx;	// the direction context for this mark; 0 means any 
	int dir;	// the direction of the matched text 
	int grp;	// the nested subgroup; 0 means no groups 
	char *pat;
} dirmarks[] = {
	{+0, +1, 1, "\\\\\\*\\[([^]]+)\\]"},
	{+0, +1, 0, "\\$([^$]+)\\$"},
	{+0, +1, 1, "\\\\[a-zA-Z0-9_]+\\{([^}]+)\\}"},
};

// character placeholders 
static struct placeholder {
	char *s;	// the source character 
	char *d;	// the placeholder 
	int wid;	// the width of the placeholder 
} placeholders[] = {
	{"‌", "-", 1},
	{"‍", "-", 1},
};
