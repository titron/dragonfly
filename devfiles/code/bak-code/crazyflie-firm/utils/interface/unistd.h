/*****************************************************************************
 *                                                                           *
 * sys/unistd.h (03/04/96 <wu> modified)                                     *
 *                                                                           *
 * Freely redistributable and modifiable.  Use at your own risk.             *
 *                                                                           *
 * Copyright 1994 The Downhill Project                                       *
 *                                                                           *
 *****************************************************************************/

#if !defined(_DOWNHILL_SYS_UNISTD_H)
#define _DOWNHILL_SYS_UNISTD_H

/* Include stuff *************************************************************/
#include <stdio.h>
#include "voWin32.h"		/* included <io.h> */

/* 03/03/95 <wu> quick hack for read/write etc. */
#define fsync		_commit	/* hack */

#ifdef chdir			/* mapped to voChdir in voUnistd.h */
#define need_voChdir
#undef chdir
#endif

#ifdef getcwd			/* mapped to voGetcwd in voUnistd.h */
#define need_voGetcwd
#undef getcwd
#endif

#ifdef mkdir			/* mapped to win32_mkdir in voWin32.h */
#define need_win32_mkdir
#undef mkdir
#endif

//#include <direct.h>//comment by titron

#ifdef need_voChdir
#define chdir		voChdir
extern int chdir(const char *);
#endif

#ifdef need_voGetcwd
#define getcwd		voGetcwd
extern char *getcwd(char *, size_t);	/* POSIX type, not the same as WIN32's */
#endif

#ifdef need_win32_mkdir
#define mkdir		win32_mkdir
/* extern int win32_mkdir(const char* dname, mode_t permission); */
#endif

/* Define stuff **************************************************************/

/* File premissions ======================================================== */
#define F_OK 0
#define X_OK 0
#define W_OK 2
#define R_OK 4

/* lseek() positions ======================================================= */
#if (_DOWNHILL_POSIX_SOURCE == 0)
#define L_SET  SEEK_SET
#define L_INCR SEEK_CUR
#define L_XTND SEEK_END
#endif

/* for some MSVC defined Unix compatibility stuff, e.g. getpid() */

//#include <process.h>//comment by titron

/* for locally defined Unix compatibility utilities */

char 	    *getlogin(void);
uid_t        getuid(void);
struct passwd* getpwuid(uid_t);
struct passwd* getpwnam(char*); 
uid_t        geteuid(void);
int          setuid(uid_t user_Id);
gid_t        getgid(void);
gid_t        getegid(void);
int          getgroups(int group_Max,gid_t group_Id[]);
int          setgid(gid_t group_Id);
unsigned int sleep(unsigned int sleep_Duration);
int          pause(void);
int          chown(char* file_Name,uid_t file_User,gid_t file_Group);

#define _DOWNHILL_POSIX_SOURCE !0//defined by titron
#if (_DOWNHILL_POSIX_SOURCE == 0)
int          setruid(uid_t user_Id);
int          seteuid(uid_t user_Id);
int          setrgid(gid_t group_Id);
int          setegid(gid_t group_Id);
int          fchown(int file_Fd,uid_t file_User,gid_t file_Group);
int          getopt(int arg_Count,char* arg_Value[],char flag_List[]);
int          readlink(char* file_Name,char* buf_Mem,int buf_Size);
int          ftruncate(int file_Fd,off_t file_Size);
int          truncate(char* file_Name,off_t file_Size);
#endif


#endif /* _DOWNHILL_SYS_UNISTD_H */
