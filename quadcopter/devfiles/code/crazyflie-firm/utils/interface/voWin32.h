/* This is Win32-specific supplement of some Unix features used by
   Virtuos, but not defined in VC's corresponding header files (mainly
   sys/types.h & sys/stat.h).
*/

#ifndef voWin32_h
#define voWin32_h

//#include <types.h>//comment by titron

/* Make sure ino_t, dev_t, and off_t are always available */

#ifndef ino_t
#define ino_t	_ino_t
#endif

#ifndef dev_t
#define dev_t	_dev_t
#endif

#ifndef off_t
#define off_t	_off_t
#endif

typedef long           uid_t;
typedef long           gid_t;
typedef long           pid_t;
/* typedef unsigned short mode_t; */
typedef int	       mode_t;	/* VC expects "int" for mode arg */
typedef short          nlink_t;
typedef char*          caddr_t;

typedef unsigned char  u_char;
typedef unsigned short u_short;
typedef unsigned int   u_int;
typedef unsigned long  u_long;
typedef u_int          uint;
typedef u_short        ushort;


//#include <sys/stat.h>//comment by titron

#define S_IRUSR _S_IREAD
#define S_IWUSR _S_IWRITE
#define S_IXUSR _S_IEXEC
#define S_IRWXU S_IRUSR|S_IWUSR|S_IXUSR

#define S_IRGRP _S_IREAD
#define S_IWGRP _S_IWRITE
#define S_IXGRP _S_IEXEC
#define S_IRWXG S_IRGRP|S_IWGRP|S_IXGRP

#define S_IROTH _S_IREAD
#define S_IWOTH _S_IWRITE
#define S_IXOTH _S_IEXEC
#define S_IRWXO S_IROTH|S_IWOTH|S_IXOTH

#define S_ISDIR(file_Mode)  ((file_Mode&_S_IFDIR) == _S_IFDIR)
#define S_ISCHR(file_Mode)  ((file_Mode&_S_IFCHR) == _S_IFCHR)
#define S_ISREG(file_Mode)  ((file_Mode&_S_IFREG) == _S_IFREG)
#define S_ISBLK(file_Mode)  ((file_Mode&_S_IFBLK) == _S_IFBLK)
#define S_ISREG(file_Mode)  ((file_Mode&_S_IFREG) == _S_IFREG)
#define S_ISFIFO(file_Mode) ((file_Mode&_S_IFFIFO) == _S_IFFIFO)
#define S_ISUID(file_Mode)  (1)
#define S_ISGID(file_Mode)  (1)

/* VC's native mkdir as declared in <direct.h> takes only one arg */
#define mkdir(d, m)	win32_mkdir(d, m)

/* Prototype stuff ***********************************************************/
extern int win32_mkdir(const char* dname, mode_t permission);

/* VC's chmod is defined in <io.h>, but it has too much stuff there */
/* _CRTIMP int __cdecl chmod(const char *fname, mode_t permission); */
/* VC5 does not like duplicate declaration of chmod */
//#include <io.h>//comment by titron

#endif /* !voWin32_h */
