
#ifndef	__DEBUG__
#define	debug_msg(fmt, args...)
#else
#define	debug_msg(fmt, args...)	printf(fmt, ##args)	
#endif