static const Rule rules[] = {
	/* ACTION    SUBSYSTEM      other env variables   command to run */
	{  "add",    NULL,          "DEVNAME",            "/bin/smdev" },
	{  "add",    NULL,          NULL,                 "/usr/libexec/libudev-zero/helper" },
	{  "remove", NULL,          NULL,                 "/usr/libexec/libudev-zero/helper" },
	{  "bind",   NULL,          NULL,                 "/usr/libexec/libudev-zero/helper" },
	{  "change", NULL,          NULL,                 "/usr/libexec/libudev-zero/helper" },
};
