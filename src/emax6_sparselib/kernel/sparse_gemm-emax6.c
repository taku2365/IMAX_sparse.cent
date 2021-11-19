typedef long unsigned int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef struct _IO_FILE __FILE;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t; struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE {
  int _flags;
  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;
typedef _G_fpos_t fpos_t;
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern FILE *tmpfile (void) ;
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;
extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;
extern int scanf (const char *__restrict __format, ...) ;
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void perror (const char *__s);
extern int sys_nerr;
extern const char *const sys_errlist[];
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *popen (const char *__command, const char *__modes) ;
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
typedef unsigned int wchar_t;
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;
extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;
extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __time_t time_t;
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
typedef int __sig_atomic_t;
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
typedef __sigset_t sigset_t;
struct timespec
  {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
  };
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef unsigned long int pthread_t;
union pthread_attr_t
{
  char __size[64];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    int __spins;
    __pthread_list_t __list;
  } __data;
  char __size[48];
  long int __align;
} pthread_mutex_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_mutexattr_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  long int __align;
} pthread_cond_t;
typedef union
{
  char __size[8];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    unsigned long int __pad1;
    unsigned long int __pad2;
    unsigned int __flags;
  } __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[8];
  int __align;
} pthread_barrierattr_t;
extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));
extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;
extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));
extern void cfree (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));
extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2))) ;
extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int system (const char *__command) ;
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;
typedef int (*__compar_fn_t) (const void *, const void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
typedef struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
} *__locale_t;
typedef __locale_t locale_t;
extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void bcopy (const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
typedef unsigned char Uchar;
typedef unsigned short Ushort;
typedef unsigned int Uint;
typedef unsigned long long Ull;
typedef long long int Sll;
typedef long double Dll;
void cex(Uint, Ull*, Ull, Ull, Ull, Ull, Ushort);
void ex4(Uint, Ull*, Ull*, Uint, Ull*, Uint, Ull*, Uint, Uint, Ull*, Uint, Ull*);
int exe(Uint, Ull*, Ull, Uint, Ull, Uint, Ull, Uint, Uint, Ull, Uint, Ull);
void mo4(Uint, Ull, Ull*, Ull, Ull, Uchar, Ull, Uint, Uint, Uchar, Ull, Uint);
void mop(Uint, Ull, Ull*, Ull, Ull, Uchar, Ull, Uint, Uint, Uchar, Ull, Uint);
void mo2(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset1, Ull offset2, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen);
void eag(Ull*, Ull, Ull, Uchar);
void eag1(Ull *adr, Ull base, Ull offset1,Ull offset2, Uchar msk);
void mmp(Uint, Ull, Ull*, Ull, Ull, Uint, Uint);
int current_prefix;
int current_mapdist;
int current_nchip;
int current_lmmwb;
int last_insn;
struct insn {
  struct header {
    char type ;
    char row ;
    char col ;
    char rdep ;
    char fixed ;
  } iheader;
  struct cex {
    char op ;
    char bit0v ;
    int bit0h ;
    char bit1v ;
    int bit1h ;
    char bit2v ;
    int bit2h ;
    char bit3v ;
    int bit3h ;
    Ull table :16;
    char cexdv ;
    int cexdh ;
  } icex;
  struct exe {
    char op1 ;
    char op2 ;
    char op3 ;
    Ull updt : 1;
    Ull init : 2;
    char src1v ;
    int src1h ;
    char src1s ;
    char src1e ;
    char src2v ;
    int src2h ;
    char src2s ;
    char src2e ;
    char src3v ;
    int src3h ;
    char src3s ;
    char src3e ;
    char src4v ;
    int src4h ;
    char src4s ;
    char src5v ;
    int src5h ;
    char src5s ;
    char exedv ;
    int exedh ;
    char exeds ;
  } iexe;
  struct mop {
    char op ;
    char mtype ;
    Ull updt : 1;
    char exv ;
    int exh ;
    char mopdv ;
    int mopdh ;
    char mopds ;
    char basev ;
    int baseh ;
    char bases ;
    char offsv ;
    int offsh ;
    char offss ;
    char offsm ;
    char topv ;
    int toph ;
    int lenv ;
    int lenh ;
    char blk ;
    int forcev ;
    int forceh ;
    char ptopv ;
    int ptoph ;
    int plenv ;
    int plenh ;
  } imop;
} insn[(4*64*4)];
struct dec {
  struct cex dcex;
  struct exu {
    char op1 ;
    char op2 ;
    char op3 ;
    Ull updt : 1;
    Ull init : 2;
    Ull fold : 1;
    char ex1v ;
    int ex1h ;
    char ex1s ;
    char ex1e ;
    char ex2v ;
    int ex2h ;
    char ex2s ;
    char ex2e ;
    char ex3v ;
    int ex3h ;
    char ex3s ;
    char ex3e ;
    char e2iv ;
    int e2ih ;
    char e2is ;
    char e3iv ;
    int e3ih ;
    char e3is ;
    char exdv ;
    int exdh ;
    char exds ;
  } dexu;
  struct mop dmop0;
  struct mop dmop1;
} dec[64][4];
struct bus {
  char cexdv ;
  int cexdh ;
  char exdrv ;
  int exdrh ;
  char exdrs ;
  char ea0brv ;
  int ea0brh ;
  char ea0orv ;
  int ea0orh ;
  char ea0drv ;
  int ea0drh ;
  char ea1brv ;
  int ea1brh ;
  char ea1orv ;
  int ea1orh ;
  char ea1drv ;
  int ea1drh ;
  struct {
    char v ;
    int h ;
    char s ;
  } lmwd[4], lmrd[4];
  struct {
    char v ;
    int h ;
    char s ;
  } tr[4];
  struct {
    char v ;
    int h ;
    char s ;
  } mw[4];
  struct {
    char v ;
    int h ;
    char s ;
  } br[4];
} bus[64][4];
struct conf {
  struct cdw0 {
    Ull v : 1;
    Ull op1 : 6;
    Ull op2 : 3;
    Ull op3 : 3;
    Ull ex1brs : 4;
    Ull ex1s : 1;
    Ull ex1exp : 2;
    Ull ex2brs : 4;
    Ull ex2exp : 2;
    Ull ex3brs : 4;
    Ull ex3exp : 2;
    Ull e2is : 2;
    Ull e3imm : 6;
    Ull e3is : 1;
    Ull init : 2;
    Ull fold : 1;
    Ull dmy00 : 20;
  } cdw0;
  struct cdw1 {
    Ull cs0 : 4;
    Ull cs1 : 4;
    Ull cs2 : 4;
    Ull cs3 : 4;
    Ull cex_tab: 16;
    Ull ea0op : 5;
    Ull ea0bs : 2;
    Ull ea0os : 1;
    Ull ea0msk : 4;
    Ull ea1op : 5;
    Ull ea1bs : 2;
    Ull ea1os : 1;
    Ull ea1msk : 4;
    Ull eabbrs : 4;
    Ull eaobrs : 4;
  } cdw1;
  struct cdw2 {
    Ull ts0 : 4;
    Ull ts1 : 4;
    Ull ts2 : 4;
    Ull ts3 : 4;
    Ull trs0 : 2;
    Ull trs1 : 2;
    Ull trs2 : 2;
    Ull trs3 : 2;
    Ull mwsa : 1;
    Ull mws0 : 2;
    Ull mws1 : 2;
    Ull mws2 : 2;
    Ull mws3 : 2;
    Ull brs0 : 2;
    Ull brs1 : 2;
    Ull brs2 : 2;
    Ull brs3 : 2;
    Ull mapdist: 6;
    Ull lmm_mode: 2;
    Ull lmm_axiw: 1;
    Ull lmm_axir: 1;
    Ull dmy20 : 13;
  } cdw2;
  struct cdw3 {
    Ull e2imm : 64;
  } cdw3;
} conf[64][4];
struct lmmi {
  Ull v : 1;
  Ull rw : 1;
  Ull f : 1;
  Ull p : 1;
  Ull bcas : 4;
  Ull hcopy: 1;
  Ull vcopy: 1;
  Ull blk : 2;
  Ull cidx : 1;
  Ull dmy : 3;
  Ull len :16;
  Ull ofs :32;
  Ull top :64;
} lmmi[64][4];
int lmmi_first_loc;
Ull lmmi_bitmap[4];
Ull range_bitmap[4];
Uchar range_link[64][4];
struct lmmx {
  int forcev ;
  int forceh ;
  int lenv ;
  int lenh ;
} lmmx[64][4];
struct {
  struct {
    int v;
    int h;
    int s;
  } br[4];
  int ea0b_v;
  int ea0b_h;
  int ea0b_s;
  int ea0o_v;
  int ea0o_h;
  int ea0o_s;
  int ea1b_v;
  int ea1b_h;
  int ea1b_s;
  int ea1o_v;
  int ea1o_h;
  int ea1o_s;
} regv[64][4];
int trans_pc;
struct trans {
  Ull rw : 1;
  Ull base_type : 2;
  Ull base_num : 3;
  char *base_symbol;
  Ull offset_type : 1;
  Ull offset : 4;
  Ull offset_suffix : 3;
  Ull offset_sll : 3;
  Ull op_type : 3;
  Ull op_val_type : 2;
  Ull op_val_num;
  char *op_val_symbol;
  Ull t_action_type : 2;
  Ull t_action : 4;
  Ull f_action_type : 2;
  Ull f_action : 4;
  Ull reg_type : 1;
  Ull reg_num : 3;
  char *reg_symbol;
} trans[16];
struct tconf {
  Ull rw : 1;
  Ull base_type : 2;
  Ull offset_type : 1;
  Ull offset : 4;
  Ull offset_suffix : 3;
  Ull offset_sll : 3;
  Ull op_type : 3;
  Ull op_val_type : 1;
  Ull t_action_type : 2;
  Ull t_action : 4;
  Ull f_action_type : 2;
  Ull f_action : 4;
  Ull reg_type : 1;
  Ull dmy : 1;
  Ull base;
  Ull op_val;
  Ull reg;
} tconf[16];
typedef struct {
    int nnz;
    int col_normal_size;
    int row_normal_size;
    int* row_p;
    int* col_index;
    Uint* val;
    int* paddings;
} emax6_sparse;
typedef struct {
    int nnz;
    int col_normal_size;
    int row_normal_size;
    int* col_p;
    int* col_index;
    Ull* val_index_set;
    Uint* sort_index;
    int* col_num;
    int* paddings;
    Ull* margin;
} emax6_sparse1;
typedef struct {
    int nnz;
    int col_normal_size;
    int row_normal_size;
    int* col_p;
    int* col_index;
    Uint* val_index_set;
    Uint* sort_index;
    int* col_num;
    int* paddings;
    Ull* margin;
} emax6_sparse2;
typedef struct {
    int H_param;
    int W_param;
    int RMGRP_param;
    int NCHIP_param;
} emax6_param;
emax6_sparse2* sparse_format4(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param);
emax6_sparse2* sparse_format5(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
int sparse_multiply_imax3(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
enum { NANOS_ARM, NANOS_DRAIN, NANOS_CONF, NANOS_REGV, NANOS_RANGE, NANOS_LOAD, NANOS_EXEC, NANOS_TOTAL, NANOS_CLASS };
typedef struct {
  Uint f : 23;
  Uint e : 8;
  Uint s : 1;
} f32bit;
typedef struct {
  Uint e : 6;
  Uint b : 1;
  Uint s : 1;
} u7bit;
typedef struct {
  Uint e : 7;
  Uint s : 1;
} u8bit;
typedef struct {
  Uchar u[8];
} u64bit;
struct dma_ctrl {
  Uint ZDMA_ERR_CTRL;
  Uint dmy0[63];
  Uint ZDMA_CH_ISR;
  Uint ZDMA_CH_IMR;
  Uint ZDMA_CH_IEN;
  Uint ZDMA_CH_IDS;
  Uint ZDMA_CH_CTRL0;
  Uint ZDMA_CH_CTRL1;
  Uint ZDMA_CH_FCI;
  Uint ZDMA_CH_STATUS;
  Uint ZDMA_CH_DATA_ATTR;
  Uint ZDMA_CH_DSCR_ATTR;
  Uint ZDMA_CH_SRC_DSCR_WORD0;
  Uint ZDMA_CH_SRC_DSCR_WORD1;
  Uint ZDMA_CH_SRC_DSCR_WORD2;
  Uint ZDMA_CH_SRC_DSCR_WORD3;
  Uint ZDMA_CH_DST_DSCR_WORD0;
  Uint ZDMA_CH_DST_DSCR_WORD1;
  Uint ZDMA_CH_DST_DSCR_WORD2;
  Uint ZDMA_CH_DST_DSCR_WORD3;
  Uint ZDMA_CH_WR_ONLY_WORD0;
  Uint ZDMA_CH_WR_ONLY_WORD1;
  Uint ZDMA_CH_WR_ONLY_WORD2;
  Uint ZDMA_CH_WR_ONLY_WORD3;
  Uint ZDMA_CH_SRC_START_LSB;
  Uint ZDMA_CH_SRC_START_MSB;
  Uint ZDMA_CH_DST_START_LSB;
  Uint ZDMA_CH_DST_START_MSB;
  Uint dmy1[9];
  Uint ZDMA_CH_RATE_CTRL;
  Uint ZDMA_CH_IRQ_SRC_ACCT;
  Uint ZDMA_CH_IRQ_DST_ACCT;
  Uint dmy2[26];
  Uint ZDMA_CH_CTRL2;
};
enum { EXRING_IDLE, EXRING_BUSY};
enum { LMRING_IDLE, LMRING_BUSY};
enum { CMD_NOP, CMD_RESET, CMD_SCON, CMD_EXEC};
struct reg_ctrl {
  struct i0 {
    Ull stat;
    Uint mcid;
    Uint dmy0;
    Uint cmd;
    Uint dmy1;
    Ull dmy2;
    Ull adtr;
    Ull dmy3;
    Ull csel;
    Ull dmrp;
    Ull dmy4[1016];
    struct conf conf[64][4];
    struct {Ull br[4];} breg[64][4];
    struct {Uint ea0b ;
        Uint ea0o ;
        Uint ea1b ;
        Uint ea1o ;
        Uint top ;
        Uint bot ;
        Ull dmy6 ;} addr[64][4];
    struct {Ull reg[4];} lddmrw[64][4];
    Ull dmy5[3072];
  } i[4];
};
enum { STATUS_IDLE, STATUS_CONF, STATUS_SCON, STATUS_REGV, STATUS_RANGE, STATUS_DRAIN, STATUS_LOAD, STATUS_START, STATUS_EXEC, STATUS_TERM };
struct emax6 {
  volatile Ull dma_ctrl;
  volatile Ull reg_ctrl;
  Ull status : 4;
  Ull csel_save : 2;
  Ull last_conf ;
  Ull lmmic : 1;
  Ull lmmio : 1;
  Ull mapdist : 6;
  Ull lastdist : 6;
  struct lmmi lmmi[4][64][4][2];
  Ull lmmi_bitmap[4];
  Uchar lmmd[64][4];
  Ull plist ;
  Ull blkcount : 7;
  Ull blksize : 9;
  Ull lmmblktop ;
  Ull lmmblklen ;
  Ull rw ;
  Ull ddraddr ;
  Ull lmmaddr ;
  Ull dmalen ;
  Ull fsm_busy : 1;
  Ull lmwd_valid : 1;
  Ull tcureg_valid : 1;
  Ull tcureg_ready : 1;
  Ull tcureg_last : 1;
  Ull tcureg_term : 1;
  Ull tcureg[4] ;
} emax6;
volatile struct emax_info {
  Ull dma_phys;
  Ull dma_vadr;
  Ull dma_mmap;
  Ull reg_phys;
  Ull reg_vadr;
  Ull reg_mmap;
  Ull lmm_phys;
  Ull lmm_vadr;
  Ull lmm_mmap;
  Ull ddr_phys;
  Ull ddr_vadr;
  Ull ddr_mmap;
  int driver_use_1;
  int driver_use_2;
} emax_info;
extern void *mmap (void *__addr, size_t __len, int __prot,
     int __flags, int __fd, __off_t __offset) __attribute__ ((__nothrow__ , __leaf__));
extern int munmap (void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int mprotect (void *__addr, size_t __len, int __prot) __attribute__ ((__nothrow__ , __leaf__));
extern int msync (void *__addr, size_t __len, int __flags);
extern int madvise (void *__addr, size_t __len, int __advice) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_madvise (void *__addr, size_t __len, int __advice) __attribute__ ((__nothrow__ , __leaf__));
extern int mlock (const void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int munlock (const void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int mlockall (int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int munlockall (void) __attribute__ ((__nothrow__ , __leaf__));
extern int mincore (void *__start, size_t __len, unsigned char *__vec)
     __attribute__ ((__nothrow__ , __leaf__));
extern int shm_open (const char *__name, int __oflag, mode_t __mode);
extern int shm_unlink (const char *__name);
struct stat
  {
    __dev_t st_dev;
    __ino_t st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    __dev_t __pad1;
    __off_t st_size;
    __blksize_t st_blksize;
    int __pad2;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    int __glibc_reserved[2];
  };
extern int stat (const char *__restrict __file,
   struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fstat (int __fd, struct stat *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int fstatat (int __fd, const char *__restrict __file,
      struct stat *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int lstat (const char *__restrict __file,
    struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int chmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lchmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__ , __leaf__));
extern int fchmodat (int __fd, const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__ , __leaf__));
extern int mkdir (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkdirat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mknodat (int __fd, const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mkfifo (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkfifoat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int utimensat (int __fd, const char *__path,
        const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int futimens (int __fd, const struct timespec __times[2]) __attribute__ ((__nothrow__ , __leaf__));
extern int __fxstat (int __ver, int __fildes, struct stat *__stat_buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int __xstat (int __ver, const char *__filename,
      struct stat *__stat_buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int __lxstat (int __ver, const char *__filename,
       struct stat *__stat_buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int __fxstatat (int __ver, int __fildes, const char *__filename,
         struct stat *__stat_buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4)));
extern int __xmknod (int __ver, const char *__path, __mode_t __mode,
       __dev_t *__dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int __xmknodat (int __ver, int __fd, const char *__path,
         __mode_t __mode, __dev_t *__dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 5)));
struct flock
  {
    short int l_type;
    short int l_whence;
    __off_t l_start;
    __off_t l_len;
    __pid_t l_pid;
  };
extern int fcntl (int __fd, int __cmd, ...);
extern int open (const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
extern int openat (int __fd, const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
extern int creat (const char *__file, mode_t __mode) __attribute__ ((__nonnull__ (1)));
extern int lockf (int __fd, int __cmd, off_t __len);
extern int posix_fadvise (int __fd, off_t __offset, off_t __len,
     int __advise) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_fallocate (int __fd, off_t __offset, off_t __len);
typedef __useconds_t useconds_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
extern int close (int __fd);
extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;
extern ssize_t write (int __fd, const void *__buf, size_t __n) ;
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset) ;
extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset) ;
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;
extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
extern char **__environ;
extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
  };
extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));
extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;
extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;
extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3))) ;
extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));
extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__));
extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));
extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));
extern int fsync (int __fd);
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fdatasync (int __fildes);
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;
struct dirent
  {
    __ino_t d_ino;
    __off_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };
enum
  {
    DT_UNKNOWN = 0,
    DT_FIFO = 1,
    DT_CHR = 2,
    DT_DIR = 4,
    DT_BLK = 6,
    DT_REG = 8,
    DT_LNK = 10,
    DT_SOCK = 12,
    DT_WHT = 14
  };
typedef struct __dirstream DIR;
extern DIR *opendir (const char *__name) __attribute__ ((__nonnull__ (1)));
extern DIR *fdopendir (int __fd);
extern int closedir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern struct dirent *readdir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern int readdir_r (DIR *__restrict __dirp,
        struct dirent *__restrict __entry,
        struct dirent **__restrict __result)
     __attribute__ ((__nonnull__ (1, 2, 3))) __attribute__ ((__deprecated__));
extern void rewinddir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void seekdir (DIR *__dirp, long int __pos) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int telldir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int dirfd (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int scandir (const char *__restrict __dir,
      struct dirent ***__restrict __namelist,
      int (*__selector) (const struct dirent *),
      int (*__cmp) (const struct dirent **,
      const struct dirent **))
     __attribute__ ((__nonnull__ (1, 2)));
extern int alphasort (const struct dirent **__e1,
        const struct dirent **__e2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern __ssize_t getdirentries (int __fd, char *__restrict __buf,
    size_t __nbytes,
    __off_t *__restrict __basep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
static int filter(struct dirent *dir)
{
  return dir->d_name[0] == '.' ? 0 : 1;
}
static void trim(char *d_name)
{
  char *p = strchr(d_name, '\n');
  if (p != ((void *)0)) *p = '\0';
}
static int is_dma_dev(char *d_name)
{
  char path[32];
  char name[32];
  FILE *fp;
  sprintf(path, "/sys/class/uio/%s/name", d_name);
  if ((fp = fopen(path, "r")) == ((void *)0)) return 0;
  if (fgets(name, sizeof(name), fp) == ((void *)0)) {
    fclose(fp);
    return 0;
  }
  fclose(fp);
  if (strcmp(name, "dma\n") != 0) return 0;
  return 1;
}
static int get_reg_size(char *d_name)
{
  char path[32];
  char size[32];
  FILE *fp;
  sprintf(path, "/sys/class/uio/%s/maps/map0/size", d_name);
  if ((fp = fopen(path, "r")) == ((void *)0)) return 0;
  if (fgets(size, sizeof(size), fp) == ((void *)0)) {
    fclose(fp);
    return 0;
  }
  fclose(fp);
  return strtoull(size, ((void *)0), 16);
}
emax6_open()
{
  struct dirent **namelist;
  int num_dirs, dir;
  int reg_size;
  int fd_dma_found = 0;
  char path[1024];
  int fd_dma;
  int fd_reg;
  int fd_ddr;
  if ((fd_reg = open("/dev/uio8", 02 | 04010000)) == -1) {
    printf("open(\"/dev/uio8\", ...) failed.\n");
    return (((void *)0));
  }
  if ((fd_ddr = open("/dev/uio9", 02 | 04010000)) == -1) {
    printf("open(\"/dev/uio9\", ...) failed.\n");
    return (((void *)0));
  }
  emax_info.reg_phys = 0x0000000400000000LL;
  emax_info.reg_mmap = (Ull)mmap(((void *)0), 0x0000000100000000LL, 0x1|0x2, 0x01, fd_reg, 0);
  if (emax_info.reg_mmap == ((void *) -1)) {
    printf("fd_reg mmap() failed.\n");
    return (((void *)0));
  }
  emax_info.lmm_phys = 0x0000000480000000LL;
  emax_info.lmm_mmap = emax_info.reg_mmap + (0x0000000480000000LL - 0x0000000400000000LL);
  emax_info.ddr_phys = 0x0000000800000000LL;
  emax_info.ddr_mmap = (Ull)mmap(((void *)0), 0x0000000080000000LL, 0x1|0x2, 0x01, fd_ddr, 0);
  if (emax_info.ddr_mmap == ((void *) -1)) {
    printf("fd_ddr mmap() failed.\n");
    return (((void *)0));
  }
  if ((num_dirs = scandir("/sys/class/uio", &namelist, filter, alphasort)) == -1)
    return (((void *)0));
  for (dir = 0; dir < num_dirs; ++dir) {
    trim(namelist[dir]->d_name);
    if (!is_dma_dev(namelist[dir]->d_name)) {
      free(namelist[dir]);
      continue;
    }
    if ((reg_size = get_reg_size(namelist[dir]->d_name)) == 0) {
      free(namelist[dir]);
      continue;
    }
    sprintf(path, "/dev/%s", namelist[dir]->d_name);
    free(namelist[dir]);
    if ((fd_dma = open(path, 02 | 04010000)) == -1)
      continue;
    emax_info.dma_phys = 0x00000000fd500000LL;
    emax_info.dma_mmap = (Ull)mmap(((void *)0), reg_size, 0x1|0x2, 0x01, fd_dma, 0);
    close(fd_dma);
    if (emax_info.dma_mmap == ((void *) -1))
      continue;
    fd_dma_found++;
    break;
  }
  free(namelist);
  if (fd_dma_found) {
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_ERR_CTRL = 0x00000001;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_ISR = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IMR = 0x00000FFF;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IEN = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IDS = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_CTRL0 = 0x00000080;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_CTRL1 = 0x000003FF;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_FCI = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_STATUS = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DATA_ATTR = 0x04C3D30F;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DSCR_ATTR = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_DSCR_WORD0 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_DSCR_WORD1 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_DSCR_WORD2 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_DSCR_WORD3 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_DSCR_WORD0 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_DSCR_WORD1 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_DSCR_WORD2 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_DSCR_WORD3 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_WR_ONLY_WORD0 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_WR_ONLY_WORD1 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_WR_ONLY_WORD2 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_WR_ONLY_WORD3 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_START_LSB = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_START_MSB = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_START_LSB = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_START_MSB = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_RATE_CTRL = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IRQ_SRC_ACCT = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IRQ_DST_ACCT = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_CTRL2 = 0x00000000;
  }
  return (1);
}
Ull nanosec_sav;
Ull nanosec[NANOS_CLASS];
reset_nanosec()
{
  int i;
  for (i=0; i<NANOS_CLASS; i++)
    nanosec[i] = 0;
  struct timespec ts;
  clock_gettime(0, &ts);
  nanosec_sav = 1000000000*ts.tv_sec + ts.tv_nsec;
}
get_nanosec(int class)
{
  Ull nanosec_now;
  struct timespec ts;
  clock_gettime(0, &ts);
  nanosec_now = 1000000000*ts.tv_sec + ts.tv_nsec;
  nanosec[class] += nanosec_now - nanosec_sav;
  nanosec[NANOS_TOTAL] += nanosec_now - nanosec_sav;
  nanosec_sav = nanosec_now;
}
show_nanosec()
{
  printf("nanosec: ARM:%llu DRAIN:%llu CONF:%llu REGV:%llu RANGE:%llu LOAD:%llu EXEC:%llu total:%llu\n",
  nanosec[NANOS_ARM],
  nanosec[NANOS_DRAIN],
  nanosec[NANOS_CONF],
  nanosec[NANOS_REGV],
  nanosec[NANOS_RANGE],
  nanosec[NANOS_LOAD],
  nanosec[NANOS_EXEC],
  nanosec[NANOS_TOTAL]);
}
emax6_check_lmmi_and_dma(int mode, int phase, int lastdist, int c, int i, int j)
{
  int k, m = (i+lastdist)%64;
  int lmmc_topz;
  int lmmc_ofsz;
  int lmmo_stat;
  int lmmc_stat;
  int lmm_ready;
  int lmm_readz;
  int mark;
  if ((mode==0 && phase == 1) || phase == 2 || phase == 3) {
    lmmc_topz = (emax6.lmmi[c][i][j][emax6.lmmic].top == 0);
    lmmc_ofsz = (emax6.lmmi[c][i][j][emax6.lmmic].ofs == 0);
    lmmo_stat = ((emax6.lmmi[c][m][j][emax6.lmmio].v)<<3)
         |(emax6.lmmi[c][m][j][emax6.lmmio].rw<<2)|(emax6.lmmi[c][m][j][emax6.lmmio].f<<1)|(emax6.lmmi[c][m][j][emax6.lmmio].p);
    lmmc_stat = ((emax6.lmmi[c][i][j][emax6.lmmic].v & ~emax6.lmmi[c][i][j][emax6.lmmic].hcopy & ~emax6.lmmi[c][i][j][emax6.lmmic].vcopy & ((emax6.lmmi[c][i][j][emax6.lmmic].f&emax6.lmmi[c][i][j][emax6.lmmic].p) | !lmmc_topz))<<3)
         |(emax6.lmmi[c][i][j][emax6.lmmic].rw<<2)|(emax6.lmmi[c][i][j][emax6.lmmic].f<<1)|(emax6.lmmi[c][i][j][emax6.lmmic].p);
    lmm_ready = (emax6.lmmi[c][m][j][emax6.lmmio].v && emax6.lmmi[c][m][j][emax6.lmmio].blk == emax6.lmmi[c][i][j][emax6.lmmic].blk
                                       && emax6.lmmi[c][m][j][emax6.lmmio].len == emax6.lmmi[c][i][j][emax6.lmmic].len
                                                     && emax6.lmmi[c][m][j][emax6.lmmio].top == emax6.lmmi[c][i][j][emax6.lmmic].top);
    lmm_readz = (emax6.lmmi[c][m][j][emax6.lmmio].v && emax6.lmmi[c][m][j][emax6.lmmio].blk == emax6.lmmi[c][i][j][emax6.lmmic].blk
                                       && emax6.lmmi[c][m][j][emax6.lmmio].len == emax6.lmmi[c][i][j][emax6.lmmic].len
                                       &&(emax6.lmmi[c][m][j][emax6.lmmio].top+(Sll)(int)emax6.lmmi[c][m][j][emax6.lmmio].ofs) == emax6.lmmi[c][i][j][emax6.lmmic].top);
  }
  if (mode==0 && phase == 1) {
    if (lmmo_stat==12 && lmmc_stat!=13 && (emax6.lmmd[m][j]&1<<c)) { mark = 1; emax6.lmmd[m][j] &= ~(1<<c);}
    else if (lmmo_stat==14 && !lmm_ready && (emax6.lmmd[m][j]&1<<c)) { mark = 1; emax6.lmmd[m][j] &= ~(1<<c);}
    else { mark = 0; }
  }
  else if (mode==1 && phase == 1) {
    if ( (emax6.lmmd[i][j]&1<<c)) { mark = 1; emax6.lmmd[i][j] &= ~(1<<c);}
    else { mark = 0; }
  }
  else if (phase == 2) {
    if (lmmc_stat== 8 && !lmm_ready) { mark = 1; }
    else if (lmmc_stat== 9 && !lmmc_ofsz && !lmm_readz) { mark = 1; }
    else if (lmmc_stat==10) { mark = 1; }
    else if (lmmc_stat==14 && !lmm_ready) { mark = 1; }
    else { mark = 0; }
  }
  else if (phase == 3) {
    if (lmmc_stat== 9 ) { mark = 1; }
    else if (lmmc_stat==12 || lmmc_stat==14 ) { mark = 0; emax6.lmmd[i][j] |= (1<<c);}
    else if (lmmc_stat==13) { mark = (emax6.lmmd[m][j]&1<<c); emax6.lmmd[m][j] |= ((!lastdist)<<c);}
    else { mark = 0; }
  }
  if (mark) {
    if (phase == 1) {
      emax6.rw = 1;
      emax6.ddraddr = (mode==0)?emax6.lmmi[c][m][j][emax6.lmmio].top:emax6.lmmi[c][i][j][emax6.lmmic].top;
      emax6.lmmaddr = emax6.ddraddr;
      emax6.dmalen = (mode==0)?emax6.lmmi[c][m][j][emax6.lmmio].len:emax6.lmmi[c][i][j][emax6.lmmic].len;
    }
    else if (phase == 3 && emax6.lmmi[c][i][j][emax6.lmmic].rw==1) {
      emax6.rw = 1;
      emax6.ddraddr = emax6.lmmi[c][i][j][emax6.lmmic].top+(Sll)(int)emax6.lmmi[c][i][j][emax6.lmmic].ofs;
      emax6.lmmaddr = emax6.ddraddr;
      emax6.dmalen = emax6.lmmi[c][i][j][emax6.lmmic].len;
    }
    else if (phase == 2
   ||(phase == 3 && emax6.lmmi[c][i][j][emax6.lmmic].rw==0)) {
      emax6.rw = 0;
      if (emax6.lmmi[c][i][j][emax6.lmmic].blk==0) {
 if (phase == 2)
   emax6.ddraddr = emax6.lmmi[c][i][j][emax6.lmmic].top;
 else
   emax6.ddraddr = emax6.lmmi[c][i][j][emax6.lmmic].top+(Sll)(int)emax6.lmmi[c][i][j][emax6.lmmic].ofs;
 emax6.lmmaddr = emax6.ddraddr;
 emax6.dmalen = emax6.lmmi[c][i][j][emax6.lmmic].len;
 emax6.blksize = 0;
      }
      else {
 if (phase == 2)
   emax6.plist = emax6.lmmi[c][i][j][emax6.lmmic].top+emax6.blkcount*8;
 else
   emax6.plist = emax6.lmmi[c][i][j][emax6.lmmic].top+emax6.blkcount*8+(Sll)(int)emax6.lmmi[c][i][j][emax6.lmmic].ofs;
 emax6.blksize = 32<<emax6.lmmi[c][i][j][emax6.lmmic].blk;
 if (emax6.blkcount==0) {
   emax6.lmmblktop = 0;
   emax6.lmmblklen = emax6.lmmi[c][i][j][emax6.lmmic].len;
 }
 emax6.ddraddr = emax6.plist;
 emax6.lmmaddr = emax6.lmmblktop;
 emax6.dmalen = (emax6.lmmblklen<emax6.blksize)?emax6.lmmblklen:emax6.blksize-1;
 emax6.lmmblktop += emax6.blksize*sizeof(Ull);
 emax6.lmmblklen = (emax6.lmmblklen<emax6.blksize)?0:(emax6.lmmblklen-emax6.blksize);
 if (emax6.lmmblklen==0)
   emax6.blkcount = 0;
 else
   emax6.blkcount++;
      }
    }
    emax6_kick_dma(j);
  }
}
emax6_kick_dma(int j)
{
  int status;
  Ull dst, src;
  Uint pio_words, pio_loop, pio_i, pio_b4, pio_b8, pio_b16, pio_e4, pio_e8, pio_e16;
  if (!emax6.ddraddr)
    return (0);
  if (j != emax6.csel_save) {
    ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].csel = j;
    emax6.csel_save = j;
  }
  if (emax6.dmalen > 0) {
    if (emax6.rw == 0) {
      do {
 status = ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_STATUS & 3;
      } while (status != 0 && status != 3);
      *(Ull*)&(((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_SRC_DSCR_WORD0) = emax6.ddraddr-emax_info.ddr_mmap+emax_info.ddr_phys;
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_SRC_DSCR_WORD2 = (emax6.dmalen+1)*sizeof(Uint);
      *(Ull*)&(((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_DST_DSCR_WORD0) = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_phys;
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_DST_DSCR_WORD2 = (emax6.dmalen+1)*sizeof(Uint);
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_CTRL2 = 1;
      do {
 status = ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_STATUS & 3;
      } while (status != 0 && status != 3);
    }
    else {
      do {
 status = ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_STATUS & 3;
      } while (status != 0 && status != 3);
      ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = (1LL<<63)|((emax6.dmalen+1)*sizeof(Uint)<<40)|(emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_phys);
      *(Ull*)&(((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_SRC_DSCR_WORD0) = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_phys;
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_SRC_DSCR_WORD2 = (emax6.dmalen+1)*sizeof(Uint);
      *(Ull*)&(((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_DST_DSCR_WORD0) = emax6.ddraddr-emax_info.ddr_mmap+emax_info.ddr_phys;
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_DST_DSCR_WORD2 = (emax6.dmalen+1)*sizeof(Uint);
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_CTRL2 = 1;
      do {
 status = ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_STATUS & 3;
      } while (status != 0 && status != 3);
      ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = (0LL<<63);
    }
    switch (status) {
    case 0:
      break;
    default:
      printf("emax6_check_lmmi_and_dma(): ZDMA_CH_STATUS=%d (malfunction)\n", status);
      return (0);
    }
  }
  else {
    if (emax6.rw == 0) {
      dst = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_mmap;
      src = emax6.ddraddr;
    }
    else {
      dst = emax6.ddraddr;
      src = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_mmap;
    }
    *(Uint*)dst = *(Uint*)src;
  }
  return (0);
}
emax6_pre_with_keep_cache()
{
}
emax6_pre_with_drain_cache()
{
}
void
cex(Uint op_cx, Ull *ex, Ull c3, Ull c2, Ull c1, Ull c0, Ushort pattern)
{
  Uint index1, index0;
  switch (op_cx) {
  case 0x00:
    if (ex)
      *ex = 3;
    break;
  case 0x01:
    index1 = ((c3>>32&1)<<3)|((c2>>32&1)<<2)|((c1>>32&1)<<1)|(c0>>32&1);
    index0 = ((c3 &1)<<3)|((c2 &1)<<2)|((c1 &1)<<1)|(c0 &1);
    *ex = 0;
    if (pattern>>index1&1) *ex |= 2;
    if (pattern>>index0&1) *ex |= 1;
    break;
  default:
    printf("emax6lib: cex: undefined op_cx=%d\n", op_cx);
    break;
  }
}
void
ex4(Uint op_ex1, Ull *d, Ull *r1, Uint exp1, Ull *r2, Uint exp2, Ull *r3, Uint exp3, Uint op_ex2, Ull *r4, Uint op_ex3, Ull *r5)
{
  switch (op_ex1) {
  case 0x08:
    exe(op_ex1, (d+0), (Ull)r1, exp1, *(r2+0), exp2, *(r3+0), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+1), exp2, *(r3+1), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+2), exp2, *(r3+2), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+3), exp2, *(r3+3), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    break;
  case 0x00:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
    exe(op_ex1, (d+0), *(r1+0), exp1, *(r2+0), exp2, *(r3+0), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+1), *(r1+1), exp1, *(r2+1), exp2, *(r3+1), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+2), *(r1+2), exp1, *(r2+2), exp2, *(r3+2), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+3), *(r1+3), exp1, *(r2+3), exp2, *(r3+3), exp3, 0x00, 0LL, 0x00, 0LL);
    break;
  default:
    printf("emax6lib: ex4: undefined op_ex1=%d\n", op_ex1);
    break;
  }
  switch (op_ex2) {
  case 0x00:
    break;
  default:
    printf("emax6lib: ex4: illegal op_ex2=%d\n", op_ex2);
    break;
  }
  switch (op_ex3) {
  case 0x00:
    break;
  default:
    printf("emax6lib: ex4: illegal op_ex3=%d\n", op_ex3);
    break;
  }
}
int convf32tou7(u7bit *out, float in)
{
  f32bit in_f32;
  *(float*)&in_f32 = in;
  out->s = in_f32.s;
  out->b = 0;
  in = ((in)> 0 ? (in) :-(in) );
  if (in >= 1.0) out->e = 63;
  else out->e = in*64;
}
int convf32tou8(u8bit *out, float in)
{
  f32bit in_f32;
  *(float*)&in_f32 = in;
  out->s = in_f32.s;
  in = ((in)> 0 ? (in) :-(in) );
  if (in >= 2.0) out->e = 127;
  else out->e = in*64;
}
int convu8tof32(float *out, u8bit in)
{
  f32bit out_f32;
  *(float*)&out_f32 = (float)in.e/64;
  out_f32.s = in.s;
  *out = *(float*)&out_f32;
}
Ull urand(int no)
{
  static Ull urand_seed[8]
    = {0xc3c3c3c3a5a5a5a5LL, 0x123456789abcdef0LL, 0xe1e1e1e1d4d4d4d4LL, 0x8888777766665555LL,
       0x8787878796969696LL, 0xfedcba9876543210LL, 0x5a5a5a5a3c3c3c3cLL, 0xbbbbccccddddeeeeLL};
  Ull retval = urand_seed[no];
  urand_seed[no] ^= (urand_seed[no]<<29);
  urand_seed[no] ^= (urand_seed[no]>>27);
  urand_seed[no] ^= (urand_seed[no]<<37);
  return (retval);
}
Ull shfl(Ull in, Ull r)
{
  int i;
  for (i=0; i<32; i++) {
    if (r&(1LL<<(i+16)))
      in = (in&~(1LL<<(i+32)|1LL<<i)) | (in>>i&1)<<(i+32) | (in>>(i+32)&1)<<i;
  }
  for (i=0; i<48; i++) {
    if (r&(1LL<<(i+8)))
      in = (in&~(1LL<<(i+16)|1LL<<i)) | (in>>i&1)<<(i+16) | (in>>(i+16)&1)<<i;
  }
  for (i=0; i<56; i++) {
    if (r&(1LL<<(i+4)))
      in = (in&~(1LL<<(i+ 8)|1LL<<i)) | (in>>i&1)<<(i+ 8) | (in>>(i+ 8)&1)<<i;
  }
  for (i=0; i<60; i++) {
    if (r&(1LL<<(i+2)))
      in = (in&~(1LL<<(i+ 4)|1LL<<i)) | (in>>i&1)<<(i+ 4) | (in>>(i+ 4)&1)<<i;
  }
  for (i=0; i<62; i++) {
    if (r&(1LL<<(i+1)))
      in = (in&~(1LL<<(i+ 2)|1LL<<i)) | (in>>i&1)<<(i+ 2) | (in>>(i+ 2)&1)<<i;
  }
  for (i=0; i<63; i++) {
    if (r&(1LL<<(i+0)))
      in = (in&~(1LL<<(i+ 1)|1LL<<i)) | (in>>i&1)<<(i+ 1) | (in>>(i+ 1)&1)<<i;
  }
  return(in);
}
int enable_x11;
void x11_softu64_dist(float, float);
int softu64(int stage, Ull *o1, Ull *o2, Ull *o3, Ull r1, Ull r2, Ull r3, Ull r4)
{
  int i, j;
  Ull u[8];
  Ull ss[8];
  Ull s2[8], s3[8];
  int pc, nc;
  int os, oc;
  switch (stage) {
  case 1:
    for (i=0; i<8; i++)
      u[i] = urand(i);
    for (i=0; i<8; i++) {
      ss[i] = (r2>>(i*8+7))&1 ^ (r3>>(i*8+7))&1;
  int s2e = (r2>>(i*8))&0x7f; s2e = s2e<15?s2e:15;
  int s3e = (r3>>(i*8))&0x7f; s3e = s3e<15?s3e:15;
      s2[i] = 0LL;
      s3[i] = 0LL;
      for (j=0; j<12; j++) {
 int k = j * 4;
 s2[i] |= ((u[(i+0)%8]>>k&15)<=s2e)<<j;
 s3[i] |= ((u[(i+1)%8]>>k&15)<=s3e)<<j;
      }
      o1[i] = s2[i] & s3[i];
      o1[i] = ss[i]<<63|(o1[i]&0x7fffffffffffffffLL);
    }
    break;
  case 2:
    pc = 0;
    nc = 0;
    for (j=0; j<12; j++) {
      for (i=0; i<8; i++) {
 if (!(o1[i]>>63)) pc += (o1[i] & (1LL<<j))!=0;
 else nc += (o1[i] & (1LL<<j))!=0;
      }
    }
    pc = pc>>r4;
    nc = nc>>r4;
    *o2 = (Ull)(pc&0xffff)<<32 | (Ull)(nc&0xffff);
    break;
  case 3:
    pc = *o2>>32&0xffff;
    nc = *o2 &0xffff;
    if (!(r1&0x80)) pc += (r1&0x7f);
    else nc += (r1&0x7f);
    if (pc >= nc) {
      os = 0x00;
      oc = pc-nc;
    }
    else {
      os = 0x80;
      oc = nc-pc;
    }
    if (oc >= 128) oc = 127;
    *o3 = os|oc;
    break;
  }
  return (0);
}
int
exe(Uint op_ex1, Ull *d, Ull r1, Uint exp1, Ull r2, Uint exp2, Ull r3, Uint exp3, Uint op_ex2, Ull r4, Uint op_ex3, Ull r5)
{
  union { Uint i; float f; } f3, f2, f1, f0;
  Ull t3, t2, t1, t0;
  Ull c1, c0;
  Ull ex1_outd;
  Ull ex1_outd_sfma[8];
  Ull ex2_outd;
  int retval = 0;
  switch (exp1) {
  case 3: break;
  case 2: r1 = (r1>>8&0x00ff000000ff0000LL) | (r1>>16&0x000000ff000000ffLL); break;
  case 1: r1 = (r1<<8&0x00ff000000ff0000LL) | (r1 &0x000000ff000000ffLL); break;
  }
  switch (exp2) {
  case 3: break;
  case 2: r2 = (r2>>8&0x00ff000000ff0000LL) | (r2>>16&0x000000ff000000ffLL); break;
  case 1: r2 = (r2<<8&0x00ff000000ff0000LL) | (r2 &0x000000ff000000ffLL); break;
  }
  switch (exp3) {
  case 3: break;
  case 2: r3 = (r3>>8&0x00ff000000ff0000LL) | (r3>>16&0x000000ff000000ffLL); break;
  case 1: r3 = (r3<<8&0x00ff000000ff0000LL) | (r3 &0x000000ff000000ffLL); break;
  }
  switch (op_ex1) {
  case 0x00:
    ex1_outd = r1;
    break;
  case 0x01:
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
    break;
  case 0x02:
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
    break;
  case 0x08:
    softu64(1, ex1_outd_sfma, ((void *)0), ((void *)0), r1, r2, r3, r4);
    break;
  case 0x10:
  case 0x11:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32)^(op_ex1==0x10?0:0x80000000);
    f3.i = (Uint)(r3>>32);
    f0.f = f1.f + (f2.f * f3.f);
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2)^(op_ex1==0x10?0:0x80000000);
    f3.i = (Uint)(r3);
    f0.f = f1.f + (f2.f * f3.f);
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x12:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f0.f = f1.f + f2.f;
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f0.f = f1.f + f2.f;
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x13:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f0.f = f1.f * f2.f;
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f0.f = f1.f * f2.f;
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x14:
    t2 = (r1>>32&0x00000000ffffffffLL)+((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)+((r2 &0x00000000ffffffffLL)+(r3 &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x15:
    t2 = (r1>>32&0x00000000ffffffffLL)-((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)-((r2 &0x00000000ffffffffLL)+(r3 &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x16:
    t2 = (r1>>32&0x00000000ffffffffLL)+(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)+(r2 &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x17:
    t2 = (r1>>32&0x00000000ffffffffLL)-(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)-(r2 &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x18:
    c1 = (r1>>32&0x00000000ffffffffLL) == (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) == (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x19:
    c1 = (r1>>32&0x00000000ffffffffLL) != (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) != (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1a:
    c1 = (r1>>32&0x00000000ffffffffLL) < (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) < (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1b:
    c1 = (r1>>32&0x00000000ffffffffLL) <= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) <= (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1c:
    c1 = (r1>>32&0x00000000ffffffffLL) > (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) > (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1d:
    c1 = (r1>>32&0x00000000ffffffffLL) >= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) >= (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1e:
    c1 = r1>>32&1;
    c0 = r1 &1;
    t2 = c1 ? (r2&0xffffffff00000000LL) : (r3&0xffffffff00000000LL);
    t0 = c0 ? (r2&0x00000000ffffffffLL) : (r3&0x00000000ffffffffLL);
    ex1_outd = t2 | t0;
    break;
  case 0x20:
    t3 = (r1>>48&0x000000000000ffffLL)+((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL)+((r2 &0x000000000000ffffLL)+(r3 &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x21:
    t3 = (r1>>48&0x000000000000ffffLL)+(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL)+(r2 &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x22:
    t3 = (r1>>48&0x000000000000ffffLL)-((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1 &0x000000000000ffffLL)-((r2 &0x000000000000ffffLL)+(r3 &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x23:
    t3 = (r1>>48&0x000000000000ffffLL)-(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1 &0x000000000000ffffLL)-(r2 &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x24:
    t3 = (r1>>48&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x25:
    ex1_outd = ((r1&0x000000ff00000000LL)<<24) | ((r2&0x000000ff00000000LL)<<16) | ((r3&0x000000ff00000000LL)<<8)
             | ((r1&0x00000000000000ffLL)<<24) | ((r2&0x00000000000000ffLL)<<16) | ((r3&0x00000000000000ffLL)<<8);
    break;
  case 0x26:
    t3 = (r1>>48&0x000000000000ffffLL) + ((r2>>56&0x00000000000000ffLL)<(r3>>56&0x00000000000000ffLL)?(r3>>56&0x00000000000000ffLL)-(r2>>56&0x00000000000000ffLL):(r2>>56&0x00000000000000ffLL)-(r3>>56&0x00000000000000ffLL)) + ((r2>>48&0x00000000000000ffLL)<(r3>>48&0x00000000000000ffLL)?(r3>>48&0x00000000000000ffLL)-(r2>>48&0x00000000000000ffLL):(r2>>48&0x00000000000000ffLL)-(r3>>48&0x00000000000000ffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL) + ((r2>>40&0x00000000000000ffLL)<(r3>>40&0x00000000000000ffLL)?(r3>>40&0x00000000000000ffLL)-(r2>>40&0x00000000000000ffLL):(r2>>40&0x00000000000000ffLL)-(r3>>40&0x00000000000000ffLL)) + ((r2>>32&0x00000000000000ffLL)<(r3>>32&0x00000000000000ffLL)?(r3>>32&0x00000000000000ffLL)-(r2>>32&0x00000000000000ffLL):(r2>>32&0x00000000000000ffLL)-(r3>>32&0x00000000000000ffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL) + ((r2>>24&0x00000000000000ffLL)<(r3>>24&0x00000000000000ffLL)?(r3>>24&0x00000000000000ffLL)-(r2>>24&0x00000000000000ffLL):(r2>>24&0x00000000000000ffLL)-(r3>>24&0x00000000000000ffLL)) + ((r2>>16&0x00000000000000ffLL)<(r3>>16&0x00000000000000ffLL)?(r3>>16&0x00000000000000ffLL)-(r2>>16&0x00000000000000ffLL):(r2>>16&0x00000000000000ffLL)-(r3>>16&0x00000000000000ffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL) + ((r2>> 8&0x00000000000000ffLL)<(r3>> 8&0x00000000000000ffLL)?(r3>> 8&0x00000000000000ffLL)-(r2>> 8&0x00000000000000ffLL):(r2>> 8&0x00000000000000ffLL)-(r3>> 8&0x00000000000000ffLL)) + ((r2 &0x00000000000000ffLL)<(r3 &0x00000000000000ffLL)?(r3 &0x00000000000000ffLL)-(r2 &0x00000000000000ffLL):(r2 &0x00000000000000ffLL)-(r3 &0x00000000000000ffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x27:
    t3 = ((r1>>56&0x00000000000000ffLL)<(r2>>56&0x00000000000000ffLL)?(r2>>56&0x00000000000000ffLL)-(r1>>56&0x00000000000000ffLL):(r1>>56&0x00000000000000ffLL)-(r2>>56&0x00000000000000ffLL)) + ((r1>>48&0x00000000000000ffLL)<(r2>>48&0x00000000000000ffLL)?(r2>>48&0x00000000000000ffLL)-(r1>>48&0x00000000000000ffLL):(r1>>48&0x00000000000000ffLL)-(r2>>48&0x00000000000000ffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = ((r1>>40&0x00000000000000ffLL)<(r2>>40&0x00000000000000ffLL)?(r2>>40&0x00000000000000ffLL)-(r1>>40&0x00000000000000ffLL):(r1>>40&0x00000000000000ffLL)-(r2>>40&0x00000000000000ffLL)) + ((r1>>32&0x00000000000000ffLL)<(r2>>32&0x00000000000000ffLL)?(r2>>32&0x00000000000000ffLL)-(r1>>32&0x00000000000000ffLL):(r1>>32&0x00000000000000ffLL)-(r2>>32&0x00000000000000ffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = ((r1>>24&0x00000000000000ffLL)<(r2>>24&0x00000000000000ffLL)?(r2>>24&0x00000000000000ffLL)-(r1>>24&0x00000000000000ffLL):(r1>>24&0x00000000000000ffLL)-(r2>>24&0x00000000000000ffLL)) + ((r1>>16&0x00000000000000ffLL)<(r2>>16&0x00000000000000ffLL)?(r2>>16&0x00000000000000ffLL)-(r1>>16&0x00000000000000ffLL):(r1>>16&0x00000000000000ffLL)-(r2>>16&0x00000000000000ffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = ((r1>> 8&0x00000000000000ffLL)<(r2>> 8&0x00000000000000ffLL)?(r2>> 8&0x00000000000000ffLL)-(r1>> 8&0x00000000000000ffLL):(r1>> 8&0x00000000000000ffLL)-(r2>> 8&0x00000000000000ffLL)) + ((r1 &0x00000000000000ffLL)<(r2 &0x00000000000000ffLL)?(r2 &0x00000000000000ffLL)-(r1 &0x00000000000000ffLL):(r1 &0x00000000000000ffLL)-(r2 &0x00000000000000ffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x28:
    t3 = r3>>48&0x000000000000ffffLL;
    t2 = r3>>32&0x000000000000ffffLL;
    t1 = r3>>16&0x000000000000ffffLL;
    t0 = r3 &0x000000000000ffffLL;
    if (t3<t2) t2 = (r1&0xffff000000000000LL)|(r3>>16&0x0000ffff00000000LL);
    else t2 = (r2&0xffff000000000000LL)|(r3 &0x0000ffff00000000LL);
    if (t1<t0) t0 = (r1&0x00000000ffff0000LL)|(r3>>16&0x000000000000ffffLL);
    else t0 = (r2&0x00000000ffff0000LL)|(r3 &0x000000000000ffffLL);
    ex1_outd = t2 | t0;
    break;
  case 0x29:
    if ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL)) t2 = r1&0xffffffff00000000LL;
    else t2 = r2&0xffffffff00000000LL;
    if ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL)) t0 = r1&0x00000000ffffffffLL;
    else t0 = r2&0x00000000ffffffffLL;
    ex1_outd = t2 | t0;
   break;
  case 0x2a:
    ex1_outd = (((r1>>48&0x000000000000ff00LL) ? 255 : (r1>>48&0x00000000000000ffLL))<<56)
             | (((r1>>32&0x000000000000ff00LL) ? 255 : (r1>>32&0x00000000000000ffLL))<<48)
             | (((r2>>48&0x000000000000ff00LL) ? 255 : (r2>>48&0x00000000000000ffLL))<<40)
             | (((r2>>32&0x000000000000ff00LL) ? 255 : (r2>>32&0x00000000000000ffLL))<<32)
             | (((r1>>16&0x000000000000ff00LL) ? 255 : (r1>>16&0x00000000000000ffLL))<<24)
             | (((r1 &0x000000000000ff00LL) ? 255 : (r1 &0x00000000000000ffLL))<<16)
             | (((r2>>16&0x000000000000ff00LL) ? 255 : (r2>>16&0x00000000000000ffLL))<< 8)
             | (((r2 &0x000000000000ff00LL) ? 255 : (r2 &0x00000000000000ffLL)) );
    break;
  case 0x2b:
    t2 = ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL))?0:0x000000ff00000000LL;
    t0 = ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL))?0:0x00000000000000ffLL;
    ex1_outd = t2 | t0;
    break;
  case 0x2c:
    t1 = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    t2 = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((r3&0xff00000000000000LL)<(t1&0xff00000000000000LL)?(t1&0xff00000000000000LL):((r3&0xff00000000000000LL)<(t2&0xff00000000000000LL)?(r3&0xff00000000000000LL):(t2&0xff00000000000000LL)))
             | ((r3&0x00ff000000000000LL)<(t1&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):((r3&0x00ff000000000000LL)<(t2&0x00ff000000000000LL)?(r3&0x00ff000000000000LL):(t2&0x00ff000000000000LL)))
             | ((r3&0x0000ff0000000000LL)<(t1&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):((r3&0x0000ff0000000000LL)<(t2&0x0000ff0000000000LL)?(r3&0x0000ff0000000000LL):(t2&0x0000ff0000000000LL)))
             | ((r3&0x000000ff00000000LL)<(t1&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):((r3&0x000000ff00000000LL)<(t2&0x000000ff00000000LL)?(r3&0x000000ff00000000LL):(t2&0x000000ff00000000LL)))
             | ((r3&0x00000000ff000000LL)<(t1&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):((r3&0x00000000ff000000LL)<(t2&0x00000000ff000000LL)?(r3&0x00000000ff000000LL):(t2&0x00000000ff000000LL)))
             | ((r3&0x0000000000ff0000LL)<(t1&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):((r3&0x0000000000ff0000LL)<(t2&0x0000000000ff0000LL)?(r3&0x0000000000ff0000LL):(t2&0x0000000000ff0000LL)))
             | ((r3&0x000000000000ff00LL)<(t1&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):((r3&0x000000000000ff00LL)<(t2&0x000000000000ff00LL)?(r3&0x000000000000ff00LL):(t2&0x000000000000ff00LL)))
             | ((r3&0x00000000000000ffLL)<(t1&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):((r3&0x00000000000000ffLL)<(t2&0x00000000000000ffLL)?(r3&0x00000000000000ffLL):(t2&0x00000000000000ffLL)));
    break;
  case 0x2d:
    t1 = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((t1&0xff00000000000000LL)>(r3&0xff00000000000000LL)?(t1&0xff00000000000000LL):(r3&0xff00000000000000LL))
             | ((t1&0x00ff000000000000LL)>(r3&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):(r3&0x00ff000000000000LL))
             | ((t1&0x0000ff0000000000LL)>(r3&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):(r3&0x0000ff0000000000LL))
             | ((t1&0x000000ff00000000LL)>(r3&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):(r3&0x000000ff00000000LL))
             | ((t1&0x00000000ff000000LL)>(r3&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):(r3&0x00000000ff000000LL))
             | ((t1&0x0000000000ff0000LL)>(r3&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):(r3&0x0000000000ff0000LL))
             | ((t1&0x000000000000ff00LL)>(r3&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):(r3&0x000000000000ff00LL))
             | ((t1&0x00000000000000ffLL)>(r3&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):(r3&0x00000000000000ffLL));
    break;
  case 0x2e:
    t1 = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((t1&0xff00000000000000LL)<(r3&0xff00000000000000LL)?(t1&0xff00000000000000LL):(r3&0xff00000000000000LL))
             | ((t1&0x00ff000000000000LL)<(r3&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):(r3&0x00ff000000000000LL))
             | ((t1&0x0000ff0000000000LL)<(r3&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):(r3&0x0000ff0000000000LL))
             | ((t1&0x000000ff00000000LL)<(r3&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):(r3&0x000000ff00000000LL))
             | ((t1&0x00000000ff000000LL)<(r3&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):(r3&0x00000000ff000000LL))
             | ((t1&0x0000000000ff0000LL)<(r3&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):(r3&0x0000000000ff0000LL))
             | ((t1&0x000000000000ff00LL)<(r3&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):(r3&0x000000000000ff00LL))
             | ((t1&0x00000000000000ffLL)<(r3&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):(r3&0x00000000000000ffLL));
    break;
  case 0x2f:
    ex1_outd = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  case 0x30:
    ex1_outd = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  default:
    printf("emax6lib: exe: undefined op_ex1=%d\n", op_ex1);
    break;
  }
  switch (op_ex2) {
  case 0x00:
    if (op_ex1 == 0x08)
      softu64(2, ex1_outd_sfma, &ex2_outd, ((void *)0), r1, r2, r3, r4);
    else
      ex2_outd = ex1_outd;
    break;
  case 0x01:
    ex2_outd = ex1_outd & r4;
    break;
  case 0x02:
    ex2_outd = ex1_outd | r4;
    break;
  case 0x03:
    ex2_outd = ex1_outd ^ r4;
    break;
  case 0x04:
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd &0x000000000000ffffLL;
    t3 += t2;
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t1 += t0;
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    ex2_outd = (t3<<48)|(t1<<16);
    break;
  case 0x05:
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd &0x000000000000ffffLL;
    t2 += t3;
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t0 += t1;
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex2_outd = (t2<<32)|(t0);
    break;
  default:
    printf("emax6lib: exe: undefined op_ex2=%d\n", op_ex2);
    break;
  }
  switch (op_ex3) {
  case 0x00:
    if (op_ex1 == 0x08)
      softu64(3, ((void *)0), &ex2_outd, d, r1, r2, r3, r4);
    else
      if (d) *d = ex2_outd;
    break;
  case 0x01:
    t1 = (Ull)(ex2_outd &0xffffffff00000000LL)<<r5;
    t0 = (Ull)(ex2_outd<<r5&0x00000000ffffffffLL);
    if (d) *d = t1 | t0;
    break;
  case 0x02:
    t1 = (Ull)(ex2_outd>>r5&0xffffffff00000000LL);
    t0 = (Ull)(ex2_outd &0x00000000ffffffffLL)>>r5;
    if (d) *d = t1 | t0;
    break;
  case 0x03:
    t1 = (Sll)(ex2_outd )>>r5&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<32)>>r5&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case 0x04:
    t1 = (Sll)(ex2_outd<< 8)>>(r5+8)&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<40)>>(r5+8)&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case 0x07:
    t3 = (Ull)(ex2_outd )>>r5&0xffff000000000000LL;
    t2 = (Ull)(ex2_outd<<16)>>r5&0xffff000000000000LL;
    t1 = (Ull)(ex2_outd<<32)>>r5&0xffff000000000000LL;
    t0 = (Ull)(ex2_outd<<48)>>r5&0xffff000000000000LL;
    if (d) *d = t3 | (t2>>16) | (t1>>32) | (t0>>48);
    break;
  default:
    printf("emax6lib: exe: undefined op_ex3=%d\n", op_ex3);
    break;
  }
  return (retval);
}
void
eag(Ull *adr, Ull base, Ull offset, Uchar msk)
{
  switch (msk) {
  case 14:
    break;
  case 13:
    offset = offset>>32;
    break;
  case 12:
    offset = offset&0x00000000ffffffffLL;
    break;
  case 11:
    offset = offset>>48&0x000000000000ffffLL;
    break;
  case 10:
    offset = offset>>32&0x000000000000ffffLL;
    break;
  case 9:
    offset = offset>>16&0x000000000000ffffLL;
    break;
  case 8:
    offset = offset&0x000000000000ffffLL;
    break;
  case 7:
    offset = offset>>56&0x00000000000000ffLL;
    break;
  case 6:
    offset = offset>>48&0x00000000000000ffLL;
    break;
  case 5:
    offset = offset>>40&0x00000000000000ffLL;
    break;
  case 4:
    offset = offset>>32&0x00000000000000ffLL;
    break;
  case 3:
    offset = offset>>24&0x00000000000000ffLL;
    break;
  case 2:
    offset = offset>>16&0x00000000000000ffLL;
    break;
  case 1:
    offset = offset>>8&0x00000000000000ffLL;
    break;
  case 0:
    offset = offset&0x00000000000000ffLL;
    break;
  default:
    printf("emax6lib: eag: undefined msk=%d\n", msk);
    break;
  }
  *adr = base + offset;
}
void
eag1(Ull *adr, Ull base, Ull offset1,Ull offset2, Uchar msk)
{
  switch (msk) {
  case 14:
    break;
  case 13:
    offset1 = offset1>>32;
    offset2 = offset2>>32;
    break;
  case 12:
    offset1 = offset1&0x00000000ffffffffLL;
    offset2 = offset2&0x00000000ffffffffLL;
    break;
  case 11:
    offset1 = offset1>>48&0x000000000000ffffLL;
    offset2 = offset2>>48&0x000000000000ffffLL;
    break;
  case 10:
    offset1 = offset1>>32&0x000000000000ffffLL;
    offset2 = offset2>>32&0x000000000000ffffLL;
    break;
  case 9:
    offset1 = offset1>>16&0x000000000000ffffLL;
    offset2 = offset2>>16&0x000000000000ffffLL;
    break;
  case 8:
    offset1 = offset1&0x000000000000ffffLL;
    offset2 = offset2&0x000000000000ffffLL;
    break;
  case 7:
    offset1 = offset1>>56&0x00000000000000ffLL;
    offset2 = offset2>>56&0x00000000000000ffLL;
    break;
  case 6:
    offset1 = offset1>>48&0x00000000000000ffLL;
    offset2 = offset2>>48&0x00000000000000ffLL;
    break;
  case 5:
    offset1 = offset1>>40&0x00000000000000ffLL;
    offset2 = offset2>>40&0x00000000000000ffLL;
    break;
  case 4:
    offset1 = offset1>>32&0x00000000000000ffLL;
    offset2 = offset2>>32&0x00000000000000ffLL;
    break;
  case 3:
    offset1 = offset1>>24&0x00000000000000ffLL;
    offset2 = offset2>>24&0x00000000000000ffLL;
    break;
  case 2:
    offset1 = offset1>>16&0x00000000000000ffLL;
    offset2 = offset2>>16&0x00000000000000ffLL;
    break;
  case 1:
    offset1 = offset1>>8&0x00000000000000ffLL;
    offset2 = offset2>>8&0x00000000000000ffLL;
    break;
  case 0:
    offset1 = offset1&0x00000000000000ffLL;
    offset2 = offset2&0x00000000000000ffLL;
    break;
  default:
    printf("emax6lib: eag: undefined msk=%d\n", msk);
    break;
  }
  *adr = base + offset1 + offset2;
}
void
mop(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr;
  eag(&adr, base, offset, msk);
  mmp(op_mm, ex, d, adr, top, len, blk);
}
void
mop_debug(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr,*load64;
  Uint *load32;
  Uint tmp,tmp1;
  eag(&adr, base, offset, msk);
  switch(op_mm){
    case 0x01:
      load64 = (Ull*)(adr&~7LL);
      tmp = (Uint)(*load64>>32);
      tmp1 = (Uint)(*load64);
      float load64_left = *(float*)&(tmp) ;
      float load64_right = *(float*)&(tmp1) ;
      load64_left += 1.0;
      load64_right += 1.0;
      *((Uint*)(adr&~7LL)+1) = *(Uint*)&load64_left;
      *((Uint*)(adr&~7LL) ) = *(Uint*)&load64_right;
      break;
    case 0x03:
      load32 = (Uint*)(adr&~3LL);
      float load32_1 = *(float*)&(*load32) ;
      load32_1 += 1.0;
      *((Uint*)(adr&~3LL) ) = *(Uint*)&load32_1;
      break;
  }
}
void
mop2_debug(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset1,Ull offset2, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr,*load64;
  Uint *load32;
  Uint tmp,tmp1;
  eag1(&adr, base, offset1, offset2, msk);
  switch(op_mm){
    case 0x01:
      load64 = (Ull*)(adr&~7LL);
      tmp = (Uint)(*load64>>32);
      tmp1 = (Uint)(*load64);
      float load64_left = *(float*)&(tmp) ;
      float load64_right = *(float*)&(tmp1) ;
      load64_left += 1.0;
      load64_right += 1.0;
      *((Uint*)(adr&~7LL)+1) = *(Uint*)&load64_left;
      *((Uint*)(adr&~7LL) ) = *(Uint*)&load64_right;
      break;
    case 0x03:
      load32 = (Uint*)(adr&~3LL);
      float load32_1 = *(float*)&(*load32) ;
      load32_1 += 1.0;
      *((Uint*)(adr&~3LL) ) = *(Uint*)&load32_1;
      break;
  }
}
void
mo2(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset1, Ull offset2, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr;
  eag1(&adr, base, offset1,offset2, msk);
  mmp(op_mm, ex, d, adr, top, len, blk);
}
void
mo4(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr;
  eag(&adr, base, offset, msk);
  mmp(op_mm, ex, d, adr, top, len, blk);
}
int emax6_unaligned_load_valid;
Ull emax6_unaligned_load_high;
void
mmp(Uint op_mm, Ull ex, Ull *d, Ull adr, Ull top, Uint len, Uint blk)
{
  Ull c1, c0, load64;
  if (!adr || !top) return;
  if (adr < top || adr >= top+len*sizeof(Uint)) {
    printf("mmp: adr=%08.8x_%08.8x out of range (top=%08.8x_%08.8x len=%dB)\n", (Uint)(adr>>32), (Uint)adr, (Uint)(top>>32), (Uint)top, len*sizeof(Uint));
    fflush(stdout);
  }
  c1 = ex>>1&1;
  c0 = ex &1;
  switch (op_mm) {
  case 0x00:
    break;
  case 0x01:
    load64 = *(Ull*)(adr&~7LL);
    if ((adr&7) == 0)
      *d = load64;
    else if (!emax6_unaligned_load_valid) {
      emax6_unaligned_load_valid = 1;
      emax6_unaligned_load_high = load64;
      *d = load64 >> (adr&7)*8;
    }
    else {
      emax6_unaligned_load_valid = 0;
      *d = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
    }
    break;
  case 0x02:
    *d = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
    break;
  case 0x03:
    *d = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
    break;
  case 0x06:
    *d = (Ull)(Uint)(int)*(char*)adr<<32 | (Ull)(Uint)(int)*(char*)adr;
    break;
  case 0x07:
    *d = (Ull)(Uint)*(Uchar*)adr<<32 | (Ull)(Uint)*(Uchar*)adr;
    break;
  case 0x11:
    if (c1) *((Uint*)(adr&~7LL)+1) = *d>>32;
    if (c0) *((Uint*)(adr&~7LL) ) = *d;
    break;
  case 0x12:
    if (c0) *(Uint*)(adr&~3LL) = *d;
    break;
  case 0x14:
    if (c0) *(Uchar*)adr = *d;
    break;
  case 0x08:
    switch (blk) {
    case 0:
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
      break;
    case 1:
      *(d+0) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 3);
      break;
    case 2:
      *(d+0) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 3);
      break;
    default:
      *(d+0) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 3);
      break;
    }
    break;
  case 0x18:
    if (c0) {
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
    }
    break;
  case 0x15:
    *((Ull*)(adr&~31LL)+0) = *(d+0);
    *((Ull*)(adr&~31LL)+1) = *(d+1);
    *((Ull*)(adr&~31LL)+2) = *(d+2);
    *((Ull*)(adr&~31LL)+3) = *(d+3);
    break;
  case 0x19:
    if (c0) {
      Ull (*trans)() = top;
      (trans)(*(d+0), *(d+1), *(d+2), *(d+3));
    }
    break;
  default:
    printf("emax6lib: mmp: undefined op_mm=%d\n", op_mm);
    break;
  }
}
void sparse_gemm_736(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sysinit(Uint memsize,Uint alignment,Uchar** membase);
void sysinit(Uint memsize,Uint alignment,Uchar** membase)
{
    if (emax6_open() == ((void *)0))
      exit(1);
    *membase = emax_info.ddr_mmap;
    {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)*membase+i)=0;}
    emax6.dma_ctrl = emax_info.dma_mmap;
    emax6.reg_ctrl = emax_info.reg_mmap;
    ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].cmd = CMD_RESET;
    usleep(1);
    ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].adtr = emax_info.ddr_mmap - emax_info.lmm_phys;
    ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = 0LL;
}
void sparse_gemm_736(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse) {
  Ull CHIP;
  Ull LOOP1, LOOP0;
  Ull INIT1, INIT0;
  Ull AR[64][4];
  Ull BR[64][4][4];
  Ull r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull cc0, cc1, cc2, cc3, ex0, ex1;
  Ull cofs, rofs, oofs, k;
  Uint blk_iter,A_margin_tmp;
  Ull* A_margin = A_sparse->margin;
  Uint* val_index_set = A_sparse->val_index_set;
  Uint* A_sort_index= A_sparse->sort_index;
  Uint top,blk;
  Ull x,y,z,t;
  Ull x0,y0,z0,t0;
  Ull x1,y1,z1,t1;
  Ull x2,y2,z2,t2;
  Ull x3,y3,z3,t3;
  Ull x4,y4,z4,t4;
  Ull x5,y5,z5,t5;
  Ull x6,y6,z6,t6;
  printf("<<<IMAX>>>\n");
  for (top=0; top<736LL/4; top+=8) {
    for (blk=0,blk_iter=0; blk<736LL; blk+=46,blk_iter+=1) {
      if((A_margin_tmp=A_margin[blk_iter])==0) break;
      typedef struct {Uint i[8]} Ui8;
      Uint *a[46],*a_index[46],*a_debug[46 +1];
      Ui8 *b[4], *b0[4], *b1[4], *b2[4], *b3[4];
      Ui8 *c0[4],*c0_debug[4];
      Ui8 *c00[4], *c01[4], *c02[4], *c03[4];
      for (CHIP=0; CHIP<4; CHIP++) {
        b[CHIP] = B+(CHIP*736LL/4 +top)*736LL;
        b0[CHIP] = b[CHIP]+0; b1[CHIP] = (Uint*)b[CHIP]+736LL*2; b2[CHIP] = (Uint*)b[CHIP]+736LL*4; b3[CHIP] = (Uint*)b[CHIP]+736LL*6;
        c0[CHIP] = C+(CHIP*736LL/4 +top)*768LL;
        c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP] = (Uint*)c0[CHIP]+768LL*2; c02[CHIP] = (Uint*)c0[CHIP]+768LL*4; c03[CHIP] = (Uint*)c0[CHIP]+768LL*6;
      }
      for (k=0; k<46; k++) a[k] = (Uint*)val_index_set+(blk+k)*768LL;
      for (k=0; k<46/2; k++) a_index[k] = (Uint*)val_index_set+blk/2*768LL*2+k*768LL*2+736LL*768LL;
volatile emax6_conf_mm();
	  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].mcid = 3; // NCHIP-1
	LOOP1 = ((A_margin_tmp));
	rofs = (((0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff)));
	LOOP0 = ((8/(4LL*2)));
	cofs = (((0-4LL*4*2*736LL)<<32|((0-4LL*4*2*736LL)&0xffffffff)));
	emax6.lmmio = emax6.lmmic;
	emax6.lmmic = 1-emax6.lmmic;
	emax6.mapdist = 0;
	*(Uint*)&emax6.lmmi[0][3][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][3][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][3][2][emax6.lmmic].top = a[0];
	*(Uint*)&emax6.lmmi[0][4][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][4][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][4][2][emax6.lmmic].top = a[1];
	*(Uint*)&emax6.lmmi[0][5][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][5][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][5][2][emax6.lmmic].top = a[2];
	*(Uint*)&emax6.lmmi[0][6][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][6][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][6][2][emax6.lmmic].top = a[3];
	*(Uint*)&emax6.lmmi[0][7][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][7][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][7][2][emax6.lmmic].top = a[4];
	*(Uint*)&emax6.lmmi[0][8][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][8][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][8][2][emax6.lmmic].top = a[5];
	*(Uint*)&emax6.lmmi[0][9][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][9][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][9][2][emax6.lmmic].top = a[6];
	*(Uint*)&emax6.lmmi[0][10][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][10][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][10][2][emax6.lmmic].top = a[7];
	*(Uint*)&emax6.lmmi[0][11][1][emax6.lmmic] = 0x2fff0041|(0<<2);
	emax6.lmmi[0][11][1][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][11][1][emax6.lmmic].top = a_index[0];
	*(Uint*)&emax6.lmmi[0][13][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][13][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][13][2][emax6.lmmic].top = a[8];
	*(Uint*)&emax6.lmmi[0][14][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][14][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][14][2][emax6.lmmic].top = a[9];
	*(Uint*)&emax6.lmmi[0][15][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][15][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][15][2][emax6.lmmic].top = a[10];
	*(Uint*)&emax6.lmmi[0][16][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][16][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][16][2][emax6.lmmic].top = a[11];
	*(Uint*)&emax6.lmmi[0][17][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][17][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][17][2][emax6.lmmic].top = a[12];
	*(Uint*)&emax6.lmmi[0][18][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][18][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][18][2][emax6.lmmic].top = a[13];
	*(Uint*)&emax6.lmmi[0][19][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][19][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][19][2][emax6.lmmic].top = a[14];
	*(Uint*)&emax6.lmmi[0][20][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][20][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][20][2][emax6.lmmic].top = a[15];
	*(Uint*)&emax6.lmmi[0][23][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][23][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][23][2][emax6.lmmic].top = a[16];
	*(Uint*)&emax6.lmmi[0][24][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][24][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][24][2][emax6.lmmic].top = a[17];
	*(Uint*)&emax6.lmmi[0][25][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][25][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][25][2][emax6.lmmic].top = a[18];
	*(Uint*)&emax6.lmmi[0][26][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][26][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][26][2][emax6.lmmic].top = a[19];
	*(Uint*)&emax6.lmmi[0][27][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][27][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][27][2][emax6.lmmic].top = a[20];
	*(Uint*)&emax6.lmmi[0][28][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][28][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][28][2][emax6.lmmic].top = a[21];
	*(Uint*)&emax6.lmmi[0][29][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][29][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][29][2][emax6.lmmic].top = a[22];
	*(Uint*)&emax6.lmmi[0][30][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][30][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][30][2][emax6.lmmic].top = a[23];
	*(Uint*)&emax6.lmmi[0][31][1][emax6.lmmic] = 0x2fff0041|(0<<2);
	emax6.lmmi[0][31][1][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][31][1][emax6.lmmic].top = a_index[8];
	*(Uint*)&emax6.lmmi[0][33][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][33][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][33][2][emax6.lmmic].top = a[24];
	*(Uint*)&emax6.lmmi[0][34][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][34][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][34][2][emax6.lmmic].top = a[25];
	*(Uint*)&emax6.lmmi[0][35][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][35][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][35][2][emax6.lmmic].top = a[26];
	*(Uint*)&emax6.lmmi[0][36][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][36][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][36][2][emax6.lmmic].top = a[27];
	*(Uint*)&emax6.lmmi[0][37][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][37][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][37][2][emax6.lmmic].top = a[28];
	*(Uint*)&emax6.lmmi[0][38][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][38][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][38][2][emax6.lmmic].top = a[29];
	*(Uint*)&emax6.lmmi[0][39][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][39][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][39][2][emax6.lmmic].top = a[30];
	*(Uint*)&emax6.lmmi[0][40][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][40][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][40][2][emax6.lmmic].top = a[31];
	*(Uint*)&emax6.lmmi[0][43][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][43][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][43][2][emax6.lmmic].top = a[32];
	*(Uint*)&emax6.lmmi[0][44][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][44][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][44][2][emax6.lmmic].top = a[33];
	*(Uint*)&emax6.lmmi[0][45][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][45][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][45][2][emax6.lmmic].top = a[34];
	*(Uint*)&emax6.lmmi[0][46][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][46][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][46][2][emax6.lmmic].top = a[35];
	*(Uint*)&emax6.lmmi[0][47][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][47][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][47][2][emax6.lmmic].top = a[36];
	*(Uint*)&emax6.lmmi[0][48][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][48][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][48][2][emax6.lmmic].top = a[37];
	*(Uint*)&emax6.lmmi[0][49][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][49][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][49][2][emax6.lmmic].top = a[38];
	*(Uint*)&emax6.lmmi[0][50][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][50][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][50][2][emax6.lmmic].top = a[39];
	*(Uint*)&emax6.lmmi[0][51][1][emax6.lmmic] = 0x2fff0041|(0<<2);
	emax6.lmmi[0][51][1][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][51][1][emax6.lmmic].top = a_index[16];
	*(Uint*)&emax6.lmmi[0][53][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][53][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][53][2][emax6.lmmic].top = a[40];
	*(Uint*)&emax6.lmmi[0][54][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][54][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][54][2][emax6.lmmic].top = a[41];
	*(Uint*)&emax6.lmmi[0][55][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][55][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][55][2][emax6.lmmic].top = a[42];
	*(Uint*)&emax6.lmmi[0][56][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][56][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][56][2][emax6.lmmic].top = a[43];
	*(Uint*)&emax6.lmmi[0][57][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][57][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][57][2][emax6.lmmic].top = a[44];
	*(Uint*)&emax6.lmmi[0][58][0][emax6.lmmic] = 0x16ff1021|(0<<2);
	emax6.lmmi[0][58][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][58][0][emax6.lmmic].top = b[0];
	*(Uint*)&emax6.lmmi[1][58][0][emax6.lmmic] = 0x16ff1021|(0<<2);
	emax6.lmmi[1][58][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[1][58][0][emax6.lmmic].top = b[1];
	*(Uint*)&emax6.lmmi[2][58][0][emax6.lmmic] = 0x16ff1021|(0<<2);
	emax6.lmmi[2][58][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[2][58][0][emax6.lmmic].top = b[2];
	*(Uint*)&emax6.lmmi[3][58][0][emax6.lmmic] = 0x16ff1021|(0<<2);
	emax6.lmmi[3][58][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[3][58][0][emax6.lmmic].top = b[3];
	*(Uint*)&emax6.lmmi[0][58][2][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][58][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][58][2][emax6.lmmic].top = a[45];
	*(Uint*)&emax6.lmmi[0][59][0][emax6.lmmic] = 0x02ff0001|(0<<2);
	emax6.lmmi[0][59][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][59][0][emax6.lmmic].top = A_sort_index;
	*(Uint*)&emax6.lmmi[0][62][0][emax6.lmmic] = 0x17ff10e7|(1<<2);
	emax6.lmmi[0][62][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][62][0][emax6.lmmic].top = c0[0];
	*(Uint*)&emax6.lmmi[1][62][0][emax6.lmmic] = 0x17ff10e7|(1<<2);
	emax6.lmmi[1][62][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[1][62][0][emax6.lmmic].top = c0[1];
	*(Uint*)&emax6.lmmi[2][62][0][emax6.lmmic] = 0x17ff10e7|(1<<2);
	emax6.lmmi[2][62][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[2][62][0][emax6.lmmic].top = c0[2];
	*(Uint*)&emax6.lmmi[3][62][0][emax6.lmmic] = 0x17ff10e7|(1<<2);
	emax6.lmmi[3][62][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[3][62][0][emax6.lmmic].top = c0[3];
	emax6.lmmi_bitmap[0] = 0x4c00000000000000LL;
	emax6.lmmi_bitmap[1] = 0x0008000080000800LL;
	emax6.lmmi_bitmap[2] = 0x07e7f9fe7f9fe7f8LL;
	emax6.lmmi_bitmap[3] = 0x0000000000000000LL;
	emax6_pre_with_drain_cache();
	get_nanosec(NANOS_ARM);
	if (emax6.last_conf == emax6_conf_mm) {
	  emax6.status = STATUS_DRAIN;
	  emax6_check_lmmi_and_dma(0, 1, 0, 0, 62, 0);/*drain*/
	  emax6_check_lmmi_and_dma(0, 1, 0, 1, 62, 0);/*drain*/
	  emax6_check_lmmi_and_dma(0, 1, 0, 2, 62, 0);/*drain*/
	  emax6_check_lmmi_and_dma(0, 1, 0, 3, 62, 0);/*drain*/
	}
	get_nanosec(NANOS_DRAIN);
	if (emax6.last_conf != emax6_conf_mm) {
	  Dll *dst, *src;
	  int i,j;
	  emax6.status = STATUS_CONF;
	  emax6.last_conf = emax6_conf_mm;
	  emax6.lastdist = 0;
	  dst = (Dll*)(((struct reg_ctrl*)emax6.reg_ctrl)->i[0].conf);
	  src = (Dll*)emax6_conf_mm;
	  for (i=0; i<sizeof(conf)/sizeof(Dll); i++)
	    *dst++ = *src++;
	  for (i=0; i<64; i++) {
	    for (j=0; j<4; j++)
	      emax6.lmmi[0][i][j][emax6.lmmio].v = 0;
	  }
	  while (((struct reg_ctrl*)emax6.reg_ctrl)->i[0].stat & 0xf0); //LMRING_BUSY 
	}
	get_nanosec(NANOS_CONF);
	emax6.status = STATUS_REGV;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][0].br[0] = LOOP1;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][0].br[1] = -1LL;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][0].br[2] = LOOP0;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][0].br[3] = cofs;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[0] = (((((4LL)*(4))*(2))*(736LL))<<(32))|((((4LL)*(4))*(2))*(736LL));
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[1] = rofs;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[2] = (((1)*(8))<<(32))|((1)*(4));
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][1].ea0b = a_index[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][1].ea1b = a_index[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][2].ea0b = a_index[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][2].ea1b = a_index[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[3][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[3][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[3][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[3][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[3][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[3][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[3][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[3][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[3][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[3][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[3][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[3][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][2].ea1b = a[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[4][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[4][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[4][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[4][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[4][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[4][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[4][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[4][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[4][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[4][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[4][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[4][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][2].ea1b = a[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[5][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[5][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[5][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[5][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[5][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[5][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[5][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[5][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[5][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[5][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[5][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[5][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][2].ea1b = a[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[6][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[6][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[6][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[6][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[6][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[6][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[6][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[6][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[6][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[6][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[6][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[6][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][2].ea1b = a[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[7][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[7][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[7][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[7][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[7][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[7][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[7][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[7][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[7][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[7][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[7][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[7][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][2].ea1b = a[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[8][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[8][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[8][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[8][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[8][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[8][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[8][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[8][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[8][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[8][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[8][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[8][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][2].ea1b = a[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[9][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[9][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[9][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[9][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[9][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[9][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[9][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[9][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[9][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[9][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[9][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[9][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][2].ea1b = a[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[10][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[10][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[10][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[10][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[10][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[10][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[10][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[10][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[10][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[10][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[10][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[10][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][2].ea1b = a[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][1].ea0b = a_index[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][1].ea1b = a_index[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][2].ea0b = a_index[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][2].ea1b = a_index[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[13][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[13][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[13][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[13][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[13][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[13][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[13][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[13][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[13][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[13][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[13][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[13][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][2].ea1b = a[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[14][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[14][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[14][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[14][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[14][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[14][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[14][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[14][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[14][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[14][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[14][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[14][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][2].ea1b = a[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[15][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[15][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[15][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[15][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[15][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[15][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[15][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[15][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[15][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[15][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[15][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[15][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][2].ea1b = a[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[16][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[16][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[16][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[16][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[16][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[16][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[16][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[16][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[16][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[16][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[16][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[16][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][2].ea1b = a[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[17][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[17][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[17][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[17][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[17][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[17][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[17][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[17][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[17][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[17][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[17][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[17][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][2].ea1b = a[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[18][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[18][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[18][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[18][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[18][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[18][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[18][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[18][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[18][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[18][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[18][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[18][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][2].ea1b = a[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[19][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[19][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[19][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[19][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[19][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[19][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[19][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[19][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[19][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[19][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[19][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[19][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][2].ea1b = a[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[20][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[20][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[20][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[20][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[20][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[20][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[20][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[20][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[20][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[20][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[20][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[20][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][2].ea1b = a[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][1].ea0b = a_index[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][1].ea1b = a_index[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][2].ea0b = a_index[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][2].ea1b = a_index[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[23][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[23][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[23][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[23][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[23][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[23][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[23][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[23][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[23][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[23][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[23][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[23][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][2].ea1b = a[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[24][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[24][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[24][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[24][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[24][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[24][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[24][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[24][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[24][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[24][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[24][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[24][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][2].ea1b = a[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[25][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[25][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[25][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[25][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[25][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[25][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[25][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[25][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[25][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[25][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[25][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[25][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][2].ea1b = a[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[26][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[26][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[26][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[26][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[26][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[26][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[26][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[26][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[26][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[26][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[26][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[26][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][2].ea1b = a[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[27][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[27][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[27][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[27][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[27][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[27][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[27][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[27][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[27][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[27][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[27][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[27][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][2].ea1b = a[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[28][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[28][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[28][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[28][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[28][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[28][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[28][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[28][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[28][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[28][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[28][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[28][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][2].ea1b = a[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[29][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[29][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[29][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[29][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[29][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[29][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[29][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[29][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[29][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[29][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[29][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[29][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][2].ea1b = a[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[30][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[30][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[30][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[30][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[30][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[30][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[30][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[30][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[30][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[30][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[30][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[30][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][2].ea1b = a[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][1].ea0b = a_index[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][1].ea1b = a_index[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][2].ea0b = a_index[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][2].ea1b = a_index[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[33][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[33][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[33][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[33][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[33][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[33][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[33][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[33][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[33][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[33][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[33][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[33][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][2].ea1b = a[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[34][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[34][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[34][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[34][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[34][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[34][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[34][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[34][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[34][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[34][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[34][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[34][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][2].ea1b = a[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[35][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[35][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[35][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[35][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[35][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[35][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[35][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[35][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[35][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[35][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[35][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[35][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][2].ea1b = a[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[36][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[36][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[36][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[36][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[36][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[36][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[36][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[36][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[36][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[36][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[36][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[36][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][2].ea1b = a[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[37][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[37][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[37][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[37][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[37][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[37][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[37][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[37][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[37][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[37][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[37][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[37][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][2].ea1b = a[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[38][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[38][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[38][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[38][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[38][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[38][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[38][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[38][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[38][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[38][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[38][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[38][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][2].ea1b = a[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[39][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[39][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[39][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[39][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[39][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[39][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[39][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[39][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[39][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[39][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[39][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[39][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][2].ea1b = a[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[40][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[40][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[40][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[40][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[40][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[40][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[40][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[40][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[40][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[40][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[40][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[40][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][2].ea1b = a[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][1].ea0b = a_index[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][1].ea1b = a_index[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][2].ea0b = a_index[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][2].ea1b = a_index[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[43][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[43][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[43][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[43][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[43][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[43][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[43][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[43][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[43][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[43][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[43][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[43][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][2].ea1b = a[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[44][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[44][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[44][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[44][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[44][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[44][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[44][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[44][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[44][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[44][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[44][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[44][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][2].ea1b = a[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[45][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[45][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[45][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[45][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[45][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[45][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[45][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[45][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[45][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[45][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[45][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[45][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][2].ea1b = a[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[46][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[46][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[46][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[46][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[46][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[46][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[46][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[46][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[46][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[46][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[46][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[46][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][2].ea1b = a[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[47][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[47][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[47][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[47][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[47][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[47][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[47][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[47][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[47][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[47][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[47][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[47][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][2].ea1b = a[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][2].ea1b = a[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[49][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[49][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[49][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[49][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[49][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[49][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[49][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[49][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[49][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[49][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[49][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[49][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][2].ea1b = a[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[50][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[50][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[50][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[50][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[50][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[50][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[50][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[50][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[50][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[50][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[50][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[50][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][2].ea1b = a[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][1].ea0b = a_index[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][1].ea1b = a_index[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][2].ea0b = a_index[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][2].ea1b = a_index[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[53][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[53][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[53][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[53][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[53][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[53][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[53][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[53][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[53][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[53][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[53][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[53][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][2].ea1b = a[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[54][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[54][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[54][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[54][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[54][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[54][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[54][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[54][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[54][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[54][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[54][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[54][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][2].ea1b = a[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[55][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[55][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[55][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[55][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[55][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[55][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[55][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[55][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[55][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[55][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[55][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[55][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][2].ea1b = a[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[56][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[56][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[56][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[56][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[56][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[56][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[56][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[56][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[56][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[56][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[56][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[56][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][2].ea1b = a[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[57][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[57][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[57][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[57][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[57][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[57][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[57][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[57][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[57][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[57][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[57][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[57][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][2].ea1b = a[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[58][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[58][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[58][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[58][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[58][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[58][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[58][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[58][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[58][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[58][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[58][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[58][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][2].ea1b = a[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[59][0].ea1b = A_sort_index;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[62][0].ea0o = c00[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[62][0].ea0o = c00[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[62][0].ea0o = c00[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[62][0].ea0o = c00[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[62][0].ea1b = c00[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[62][0].ea1b = c00[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[62][0].ea1b = c00[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[62][0].ea1b = c00[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[62][1].ea0o = c01[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[62][1].ea0o = c01[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[62][1].ea0o = c01[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[62][1].ea0o = c01[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[62][1].ea1b = c01[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[62][1].ea1b = c01[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[62][1].ea1b = c01[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[62][1].ea1b = c01[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[62][2].ea0o = c02[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[62][2].ea0o = c02[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[62][2].ea0o = c02[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[62][2].ea0o = c02[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[62][2].ea1b = c02[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[62][2].ea1b = c02[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[62][2].ea1b = c02[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[62][2].ea1b = c02[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[62][3].ea0o = c03[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[62][3].ea0o = c03[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[62][3].ea0o = c03[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[62][3].ea0o = c03[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[62][3].ea1b = c03[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[62][3].ea1b = c03[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[62][3].ea1b = c03[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[62][3].ea1b = c03[3];
	get_nanosec(NANOS_REGV);
	emax6.status = STATUS_RANGE;
	{struct reg_ctrl *reg_ctrl = emax6.reg_ctrl;
	 Uint            lmmic     = emax6.lmmic;
	*(Ull*)&(reg_ctrl->i[0].addr[1][1].top) = ((Ull)(emax6.lmmi[0][11][1][lmmic].top+*((Ushort*)&emax6.lmmi[0][11][1][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][11][1][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[3][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[3][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[3][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[3][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[3][2].top) = ((Ull)(emax6.lmmi[0][3][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][3][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][3][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[4][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[4][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[4][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[4][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[4][2].top) = ((Ull)(emax6.lmmi[0][4][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][4][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][4][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[5][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[5][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[5][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[5][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[5][2].top) = ((Ull)(emax6.lmmi[0][5][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][5][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][5][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[6][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[6][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[6][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[6][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[6][2].top) = ((Ull)(emax6.lmmi[0][6][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][6][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][6][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[7][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[7][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[7][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[7][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[7][2].top) = ((Ull)(emax6.lmmi[0][7][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][7][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][7][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[8][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[8][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[8][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[8][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[8][2].top) = ((Ull)(emax6.lmmi[0][8][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][8][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][8][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[9][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[9][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[9][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[9][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[9][2].top) = ((Ull)(emax6.lmmi[0][9][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][9][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][9][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[10][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[10][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[10][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[10][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[10][2].top) = ((Ull)(emax6.lmmi[0][10][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][10][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[11][1].top) = ((Ull)(emax6.lmmi[0][11][1][lmmic].top+*((Ushort*)&emax6.lmmi[0][11][1][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][11][1][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[13][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[13][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[13][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[13][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[13][2].top) = ((Ull)(emax6.lmmi[0][13][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][13][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][13][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[14][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[14][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[14][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[14][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[14][2].top) = ((Ull)(emax6.lmmi[0][14][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][14][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][14][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[15][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[15][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[15][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[15][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[15][2].top) = ((Ull)(emax6.lmmi[0][15][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][15][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][15][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[16][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[16][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[16][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[16][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[16][2].top) = ((Ull)(emax6.lmmi[0][16][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][16][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][16][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[17][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[17][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[17][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[17][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[17][2].top) = ((Ull)(emax6.lmmi[0][17][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][17][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][17][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[18][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[18][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[18][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[18][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[18][2].top) = ((Ull)(emax6.lmmi[0][18][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][18][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][18][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[19][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[19][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[19][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[19][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[19][2].top) = ((Ull)(emax6.lmmi[0][19][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][19][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[20][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[20][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[20][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[20][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[20][2].top) = ((Ull)(emax6.lmmi[0][20][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][20][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][20][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[21][1].top) = ((Ull)(emax6.lmmi[0][31][1][lmmic].top+*((Ushort*)&emax6.lmmi[0][31][1][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][31][1][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[23][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[23][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[23][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[23][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[23][2].top) = ((Ull)(emax6.lmmi[0][23][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][23][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][23][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[24][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[24][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[24][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[24][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[24][2].top) = ((Ull)(emax6.lmmi[0][24][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][24][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][24][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[25][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[25][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[25][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[25][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[25][2].top) = ((Ull)(emax6.lmmi[0][25][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][25][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][25][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[26][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[26][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[26][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[26][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[26][2].top) = ((Ull)(emax6.lmmi[0][26][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][26][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][26][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[27][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[27][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[27][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[27][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[27][2].top) = ((Ull)(emax6.lmmi[0][27][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][27][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][27][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[28][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[28][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[28][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[28][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[28][2].top) = ((Ull)(emax6.lmmi[0][28][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][28][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[29][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[29][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[29][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[29][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[29][2].top) = ((Ull)(emax6.lmmi[0][29][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][29][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][29][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[30][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[30][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[30][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[30][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[30][2].top) = ((Ull)(emax6.lmmi[0][30][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][30][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][30][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[31][1].top) = ((Ull)(emax6.lmmi[0][31][1][lmmic].top+*((Ushort*)&emax6.lmmi[0][31][1][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][31][1][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[33][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[33][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[33][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[33][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[33][2].top) = ((Ull)(emax6.lmmi[0][33][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][33][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][33][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[34][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[34][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[34][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[34][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[34][2].top) = ((Ull)(emax6.lmmi[0][34][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][34][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][34][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[35][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[35][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[35][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[35][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[35][2].top) = ((Ull)(emax6.lmmi[0][35][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][35][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][35][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[36][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[36][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[36][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[36][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[36][2].top) = ((Ull)(emax6.lmmi[0][36][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][36][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][36][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[37][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[37][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[37][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[37][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[37][2].top) = ((Ull)(emax6.lmmi[0][37][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][37][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[38][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[38][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[38][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[38][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[38][2].top) = ((Ull)(emax6.lmmi[0][38][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][38][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][38][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[39][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[39][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[39][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[39][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[39][2].top) = ((Ull)(emax6.lmmi[0][39][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][39][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][39][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[40][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[40][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[40][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[40][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[40][2].top) = ((Ull)(emax6.lmmi[0][40][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][40][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][40][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[41][1].top) = ((Ull)(emax6.lmmi[0][51][1][lmmic].top+*((Ushort*)&emax6.lmmi[0][51][1][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][51][1][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[43][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[43][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[43][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[43][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[43][2].top) = ((Ull)(emax6.lmmi[0][43][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][43][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][43][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[44][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[44][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[44][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[44][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[44][2].top) = ((Ull)(emax6.lmmi[0][44][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][44][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][44][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[45][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[45][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[45][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[45][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[45][2].top) = ((Ull)(emax6.lmmi[0][45][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][45][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][45][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[46][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[46][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[46][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[46][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[46][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[47][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[47][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[47][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[47][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[47][2].top) = ((Ull)(emax6.lmmi[0][47][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][47][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][47][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[48][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[48][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[48][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[48][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[48][2].top) = ((Ull)(emax6.lmmi[0][48][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][48][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][48][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[49][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[49][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[49][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[49][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[49][2].top) = ((Ull)(emax6.lmmi[0][49][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][49][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][49][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[50][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[50][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[50][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[50][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[50][2].top) = ((Ull)(emax6.lmmi[0][50][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][50][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][50][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[51][1].top) = ((Ull)(emax6.lmmi[0][51][1][lmmic].top+*((Ushort*)&emax6.lmmi[0][51][1][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][51][1][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[53][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[53][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[53][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[53][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[53][2].top) = ((Ull)(emax6.lmmi[0][53][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][53][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][53][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[54][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[54][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[54][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[54][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[54][2].top) = ((Ull)(emax6.lmmi[0][54][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][54][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][54][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[55][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[55][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[55][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[55][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[55][2].top) = ((Ull)(emax6.lmmi[0][55][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][55][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[56][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[56][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[56][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[56][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[56][2].top) = ((Ull)(emax6.lmmi[0][56][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][56][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][56][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[57][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[57][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[57][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[57][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[57][2].top) = ((Ull)(emax6.lmmi[0][57][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][57][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][57][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[58][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[58][0].top) = ((Ull)(emax6.lmmi[1][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[58][0].top) = ((Ull)(emax6.lmmi[2][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[58][0].top) = ((Ull)(emax6.lmmi[3][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[58][2].top) = ((Ull)(emax6.lmmi[0][58][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[59][0].top) = ((Ull)(emax6.lmmi[0][59][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][59][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][59][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[62][0].top) = ((Ull)(emax6.lmmi[0][62][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][62][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][62][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[62][0].top) = ((Ull)(emax6.lmmi[1][62][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][62][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][62][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[62][0].top) = ((Ull)(emax6.lmmi[2][62][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][62][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][62][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[62][0].top) = ((Ull)(emax6.lmmi[3][62][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][62][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][62][0][lmmic].top;
	}
	get_nanosec(NANOS_RANGE);
	emax6.status = STATUS_LOAD;
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 3, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 4, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 5, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 6, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 7, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 8, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 9, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 10, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 11, 1);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 13, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 14, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 15, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 16, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 17, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 18, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 19, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 20, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 23, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 24, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 25, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 26, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 27, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 28, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 29, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 30, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 31, 1);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 33, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 34, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 35, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 36, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 37, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 38, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 39, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 40, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 43, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 44, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 45, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 46, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 47, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 48, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 49, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 50, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 51, 1);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 53, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 54, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 55, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 56, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 57, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 58, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 1, 58, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 2, 58, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 3, 58, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 58, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 59, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 62, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 1, 62, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 2, 62, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 3, 62, 0);/*load*/
	get_nanosec(NANOS_LOAD);
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].cmd = 3LL; // EXEC
	{struct reg_ctrl *reg_ctrl = emax6.reg_ctrl;
	 Uint            lmmic     = emax6.lmmic;
	}
	emax6.lmmd[62][0] = 0xff>>4;
	while (((struct reg_ctrl*)emax6.reg_ctrl)->i[0].stat); //LMRING_BUSY|EXRING_BUSY
	get_nanosec(NANOS_EXEC);
asm volatile("b emax6_conf_end_mm\n"
".align 5\n"
".global emax6_conf_mm\n"
"emax6_conf_mm:\n"
"	.word	0x031e4005, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x031e0005, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x034e60ad, 0x00000200\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0xffffffff, 0xffffffff\n"
"	.word	0x036ea02d, 0x00000400\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x000a00ea, 0x00000014\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0xe0d81d81\n"
"	.word	0x00000000, 0x0002801e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0xe0d81d81\n"
"	.word	0x00000000, 0x0002801e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030ca02d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x000a0001, 0x00000074\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030c802d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d202d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d002d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a00200, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a0a600, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00c82000\n"
"	.word	0x0022010e, 0x0003005c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039c2027, 0x00000000\n"
"	.word	0xffff0000, 0x20d81d81\n"
"	.word	0x00806000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039c0027, 0x00000000\n"
"	.word	0xffff0000, 0x20d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039ca027, 0x00000000\n"
"	.word	0xffff0000, 0x30c82000\n"
"	.word	0x00828007, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039c8027, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000a, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000c, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082c00b, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0002000b, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00000000, 0x00030078\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x000a0037, 0x00000074\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030ca02d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a6021, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030c802d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a00ea, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d202d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d002d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a03100, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a05400, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00c82000\n"
"	.word	0x00a26002, 0x0003015c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x002a07ea, 0x00000054\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080b000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39c6021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080a000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79cc021, 0x00000000\n"
"	.word	0xffff0000, 0xa0c82000\n"
"	.word	0x0082d00c, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39ce021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000e, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000c, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082c00b, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0002000b, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00000000, 0x00030078\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x000a0037, 0x00000074\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030ca02d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a6021, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030c802d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a00ea, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d202d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d002d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a03100, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a05400, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00c82000\n"
"	.word	0x00a26002, 0x0003015c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x002a07ea, 0x00000054\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080b000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39c6021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080a000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79cc021, 0x00000000\n"
"	.word	0xffff0000, 0xa0c82000\n"
"	.word	0x0082d00c, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39ce021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000e, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000c, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082c00b, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0002000b, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00000000, 0x00030078\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x000a0037, 0x00000074\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030ca02d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a6021, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030c802d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a00ea, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d202d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d002d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a03100, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a05400, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00c82000\n"
"	.word	0x00a26002, 0x0003015c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x002a07ea, 0x00000054\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080b000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39c6021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080a000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79cc021, 0x00000000\n"
"	.word	0xffff0000, 0xa0c82000\n"
"	.word	0x0082d00c, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39ce021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000e, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000c, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082c00b, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0002000b, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00000000, 0x00030078\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x000a0037, 0x00000074\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030ca02d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a6021, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030c802d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a00ea, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d202d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d002d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a03100, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a05400, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00c82000\n"
"	.word	0x00a26002, 0x0003015c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x002a07ea, 0x00000054\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080b000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39c6021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080a000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79cc021, 0x00000000\n"
"	.word	0xffff0000, 0xa0c82000\n"
"	.word	0x0082d00c, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39ce021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000e, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000c, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082c00b, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0002000b, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00000000, 0x00030078\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x000a0037, 0x00000074\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0002807e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030ca02d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a6021, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030c802d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008a00ea, 0x00000174\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d202d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030d002d, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a03100, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00a05400, 0x0003015e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00c82000\n"
"	.word	0x00a26002, 0x0003015c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x000a007a, 0x00000014\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080b000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39c6021, 0x00000000\n"
"	.word	0xffff0000, 0x80d81d81\n"
"	.word	0x0080a000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79cc021, 0x00000000\n"
"	.word	0xffff0000, 0xa0c82000\n"
"	.word	0x0082d00c, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39ce021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0082b008, 0x0003017c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x0002000b, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70c82000\n"
"	.word	0x00000000, 0x00030078\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30c82000\n"
"	.word	0x00020007, 0x0002807c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x030c20ad, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x008aa062, 0x00000174\n"
"	.word	0xffffffff, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x0002000e, 0x00000004\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00aa3102, 0x00000154\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00020004, 0x00000004\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x031c0025, 0x00000800\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab822001, 0x0006811c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x035c6025, 0x00000800\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab824003, 0x0006811c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039c8025, 0x00000800\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab020000, 0x0006801c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x03dce025, 0x00000800\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab000000, 0x00068018\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
".global emax6_conf_end_mm\n"
"emax6_conf_end_mm:\n"
);
    }
  }
	emax6_pre_with_drain_cache();
	get_nanosec(NANOS_ARM);
	{
	  struct reg_ctrl *reg_ctrl = emax6.reg_ctrl;
	  Uint   lmmic              = emax6.lmmic;
	  Uint   mapdist            = emax6.mapdist;
	  int    c,i,j;
	  emax6.status = STATUS_DRAIN;
	  for (i=0; i<64; i++) {
	    for (j=0; j<4; j++) {
	      if (emax6.lmmi_bitmap[j] & (1LL<<i) && emax6.lmmi[0][i][j][lmmic].rw) {
	        for (c=0; c<4; c++) {
	          if (emax6.lmmi[0][i][j][lmmic].ofs)
	            *(Ull*)&(reg_ctrl->i[c].addr[i][j].top) = ((Ull)(emax6.lmmi[c][i][j][lmmic].top+*((Ushort*)&emax6.lmmi[c][i][j][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[c][i][j][lmmic].top;
	          emax6_check_lmmi_and_dma(1, 1, mapdist, c, i, j);/*drain*/
	        }
	      }
	    }
	  }
	}
	get_nanosec(NANOS_DRAIN);
}
