
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
Ull __attribute__((always_inline)) exm(Ull, Uchar);
int exe(Uint, Ull*, Ull, Uint, Ull, Uint, Ull, Uint, Uint, Ull, Uint, Ull);
void mex(Uint, Uchar**, Uchar*, Ull, Ull, Ull);
void mo4(Uint, Ull, Ull*, Ull, Ull, Uchar, Ull, Uint, Uint, Uchar, Ull, Uint);
void mop(Uint, Ull, Ull*, Ull, Ull, Uchar, Ull, Uint, Uint, Uchar, Ull, Uint);
Ull __attribute__((always_inline)) eam(Ull, Uchar);
void eag(Ull*, Ull, Ull);
void mmp(Uint, Ull, Ull*, Ull, Ull, Uint, Uint);
int current_prefix;
int current_mapdist;
int current_nchip;
int current_lmmwb;
int last_insn;
char forinit[2][4][1024];
char forinit_cidx[2];
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
  struct mex {
    char op ;
    Ull init : 1;
    char src1v ;
    int src1h ;
    char src1s ;
    char src2v ;
    int src2h ;
    char src2s ;
    char distv ;
    int disth ;
    char src3v ;
    int src3h ;
    char src3s ;
    char src4v ;
    int src4h ;
    char src4s ;
    char mexdv ;
    int mexdh ;
    char mexds ;
  } imex;
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
  struct mex dmex0;
  struct mex dmex1;
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
    Ull ex1exp : 3;
    Ull ex2brs : 4;
    Ull ex2exp : 3;
    Ull ex3brs : 4;
    Ull ex3exp : 3;
    Ull e2is : 2;
    Ull e3imm : 6;
    Ull e3is : 1;
    Ull init : 2;
    Ull fold : 1;
    Ull mex0op : 2;
    Ull mex0init: 1;
    Ull mex0dist: 3;
    Ull mex1op : 2;
    Ull mex1init: 1;
    Ull mex1dist: 3;
    Ull dmy00 : 5;
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
    Uint* col_index;
    Uint* val_index_set;
    Uint* sort_index;
    int* col_num;
    int* paddings;
    Ull* margin;
    Ull* margin_sum;
} emax6_sparse2;
typedef struct {
    Uint mode;
    Sll H_param;
    Sll W_param;
    Sll B_col_blk_param ;
    Sll C_col_blk_param ;
    Sll NCHIP_param ;
    Sll A_col_blk_param ;
    Sll A_row_size_param ;
    Sll A_col_size_param ;
    Sll B_row_size_param ;
    Sll B_col_size_param ;
    float LMM_usage_kbyte;
    float LMM_usage_rate ;
} emax6_param;
typedef struct {
    int nnz;
    Uint* val;
    Uint* col_index;
    Uint* row_index;
    int row_size;
    int col_size;
} coo_format;
coo_format* make_sparse_mat(emax6_param* emax6_param,float sparsity);
void make_simd_random_mat(emax6_param* emax6_param,Uint* B,Uint* B_debug);
void free_sparse_format(emax6_sparse2* sparse_format);
void free_sparse_mat(coo_format* coo);
void orig_chip_divB(Uint* A_orig,Uint* B_orig,Uint* C_orig,emax6_param* emax6_param);
void mem_release(Uint memsize,Uchar** membase);
void IMAX_param_tunig(emax6_param* params);
emax6_sparse2* sparse_format(int nnz,Ull* val,Uint* val_tmp, const int* const col_index, const int* const row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
emax6_sparse2* sparse_format1(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
int sparse_multiply_imax3(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
int sparse_multiply_imax4(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
int sparse_multiply_imax5(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
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
void sparse_gemm_CHIP_div_B( Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
void sparse_gemm_CHIP_div_A( Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
void sysinit(Uint memsize,Uint alignment,Uchar** membase);
void gemm_normal_CHIP_div_B(Uint* C, const Uint* A, const Uint* B, emax6_param* params) {
  Ull top,blk;
  Ull CHIP;
  Ull LOOP1, LOOP0;
  Ull INIT1, INIT0;
  Ull AR[64][4];
  Ull BR[64][4][4];
  Ull r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull cc0, cc1, cc2, cc3, ex0, ex1;
  Ull cofs, rofs, oofs, k;
  Sll A_row_size = params->A_row_size_param;
  Sll A_col_size = params->A_col_size_param;
  Sll B_row_size = params->B_row_size_param;
  Sll B_col_size = params->B_col_size_param;
  Sll B_col_blk = params->B_col_blk_param;
  Sll W = params->W_param;
  Sll H = params->H_param;
  Sll A_col_blk = params->A_col_blk_param;
  Sll B_col_size_mul_B_col_blk = B_col_size*B_col_blk;
  Sll B_col_blk_mul_B_row_size = B_col_blk*B_row_size;
  Sll A_row_size_mul_2_mul_A_col_blk = A_row_size*2*A_col_blk;
  Sll A_col_size_mul_B_col_blk = A_col_size*B_col_blk;
  Sll A_row_size_mul_B_col_blk = A_row_size*B_col_blk;
  Sll A_row_size_mul_8 = A_row_size*8;
  Sll W_mul_8_64 = (W*8)<<32|(W*8);
  Sll cofs_init = (0-W*8)<<32|((0-W*8)&0xffffffff);
  Sll rofs_init = (0-A_col_size*4)<<32|((0-B_col_size*4)&0xffffffff);
  Sll A_row_size_mul_8_64 = (A_row_size_mul_8)<<32|(A_row_size_mul_8);
  Sll rofs_reverse = (A_col_size*4)<<32|(B_col_size*4);
  printf("<<<IMAX>>>\n");
  for (top=0; top<A_row_size/4; top+=B_col_blk) {
    for (blk=0; blk<B_row_size; blk+=H) {
      typedef struct {Uint i[8]} Ui8;
      Uint *a0[4];
      Uint *a[H][4];
      Ui8 *b[H], *b0[H], *b1[H], *b2[H], *b3[H];
      Ui8 *c0[4];
      Ui8 *c00[4], *c01[4], *c02[4], *c03[4];
      for (k=0; k<H; k++) {
 b[k] = B+(blk+k)*B_col_size; b0[k] = b[k]; b1[k] = (Uint*)b[k]+2; b2[k] = (Uint*)b[k]+4; b3[k] = (Uint*)b[k]+6;
      }
      for (CHIP=0; CHIP<4; CHIP++) {
 a0[CHIP] = A+(CHIP*A_row_size/4 +top)*A_col_size;
 for (k=0; k<H; k++)
   a[k][CHIP] = a0[CHIP]+blk+k;
 c0[CHIP] = C+(CHIP*A_row_size/4 +top)*B_col_size;
 c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP]= (Uint*)c0[CHIP]+2; c02[CHIP]= (Uint*)c0[CHIP]+4; c03[CHIP]= (Uint*)c0[CHIP]+6;
      }
/-EMAX5AB-/ mm0 0
/-EMAX5AS-/ for (CHIP=0; CHIP<4; CHIP++) {
/-EMAX5AS-/ for (INIT1=1,LOOP1=""B_col_blk"",rofs=""rofs_init""; LOOP1--; INIT1=0) {
/-EMAX5AS-/ for (INIT0=1,LOOP0=""B_col_size/W/2"",cofs=""cofs_init""; LOOP0--; INIT0=0) {
/-EMAX5AS-/ exe(0x16, &cofs, INIT0?cofs:cofs, 0, W_mul_8_64, 0, 0LL, 0, 0x01, 0xffffffffffffffffLL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x16, &rofs, rofs, 0, INIT0?rofs_reverse:0, 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x16, &oofs, rofs, 0, cofs, 0, 0, 0, 0x01, 0xffffffff, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x01, 3, &BR[1][0][1], (Ull)b0[0], (Ull)cofs, 13, (Ull)b[0], B_col_size, 0, 0, (Ull)((void *)0), B_col_size);
/-EMAX5AS-/ mop(0x01, 3, &BR[1][0][0], (Ull)b1[0], (Ull)cofs, 13, (Ull)b[0], B_col_size, 0, 0, (Ull)((void *)0), B_col_size);
/-EMAX5AS-/ mop(0x01, 3, &BR[1][1][1], (Ull)b2[0], (Ull)cofs, 13, (Ull)b[0], B_col_size, 0, 0, (Ull)((void *)0), B_col_size);
/-EMAX5AS-/ mop(0x01, 3, &BR[1][1][0], (Ull)b3[0], (Ull)cofs, 13, (Ull)b[0], B_col_size, 0, 0, (Ull)((void *)0), B_col_size);
/-EMAX5AS-/ mop(0x02,1, &BR[1][2][1], (Ull)a[0][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk);
/-EMAX5AS-/ exe(0x13, &AR[2][0], BR[1][0][1], 0, BR[1][2][1], 1, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x13, &AR[2][1], BR[1][0][0], 0, BR[1][2][1], 1, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x13, &AR[2][2], BR[1][1][1], 0, BR[1][2][1], 1, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ exe(0x13, &AR[2][3], BR[1][1][0], 0, BR[1][2][1], 1, 0LL, 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x01, 3, &BR[2][0][1], (Ull)b0[1], (Ull)cofs, 13, (Ull)b[1], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[2][0][0], (Ull)b1[1], (Ull)cofs, 13, (Ull)b[1], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[2][1][1], (Ull)b2[1], (Ull)cofs, 13, (Ull)b[1], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[2][1][0], (Ull)b3[1], (Ull)cofs, 13, (Ull)b[1], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[2][2][1], (Ull)a[1][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[3][0], AR[2][0], 0, BR[2][2][1], 1, BR[2][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[3][1], AR[2][1], 0, BR[2][2][1], 1, BR[2][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[3][2], AR[2][2], 0, BR[2][2][1], 1, BR[2][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[3][3], AR[2][3], 0, BR[2][2][1], 1, BR[2][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[3][0][1], (Ull)b0[2], (Ull)cofs, 13, (Ull)b[2], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[3][0][0], (Ull)b1[2], (Ull)cofs, 13, (Ull)b[2], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[3][1][1], (Ull)b2[2], (Ull)cofs, 13, (Ull)b[2], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[3][1][0], (Ull)b3[2], (Ull)cofs, 13, (Ull)b[2], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[3][2][1], (Ull)a[2][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[4][0], AR[3][0], 0, BR[3][2][1], 1, BR[3][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[4][1], AR[3][1], 0, BR[3][2][1], 1, BR[3][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[4][2], AR[3][2], 0, BR[3][2][1], 1, BR[3][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[4][3], AR[3][3], 0, BR[3][2][1], 1, BR[3][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[4][0][1], (Ull)b0[3], (Ull)cofs, 13, (Ull)b[3], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[4][0][0], (Ull)b1[3], (Ull)cofs, 13, (Ull)b[3], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[4][1][1], (Ull)b2[3], (Ull)cofs, 13, (Ull)b[3], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[4][1][0], (Ull)b3[3], (Ull)cofs, 13, (Ull)b[3], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[4][2][1], (Ull)a[3][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[5][0], AR[4][0], 0, BR[4][2][1], 1, BR[4][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[5][1], AR[4][1], 0, BR[4][2][1], 1, BR[4][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[5][2], AR[4][2], 0, BR[4][2][1], 1, BR[4][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[5][3], AR[4][3], 0, BR[4][2][1], 1, BR[4][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[5][0][1], (Ull)b0[4], (Ull)cofs, 13, (Ull)b[4], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[5][0][0], (Ull)b1[4], (Ull)cofs, 13, (Ull)b[4], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[5][1][1], (Ull)b2[4], (Ull)cofs, 13, (Ull)b[4], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[5][1][0], (Ull)b3[4], (Ull)cofs, 13, (Ull)b[4], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[5][2][1], (Ull)a[4][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[6][0], AR[5][0], 0, BR[5][2][1], 1, BR[5][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[6][1], AR[5][1], 0, BR[5][2][1], 1, BR[5][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[6][2], AR[5][2], 0, BR[5][2][1], 1, BR[5][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[6][3], AR[5][3], 0, BR[5][2][1], 1, BR[5][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[6][0][1], (Ull)b0[5], (Ull)cofs, 13, (Ull)b[5], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[6][0][0], (Ull)b1[5], (Ull)cofs, 13, (Ull)b[5], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[6][1][1], (Ull)b2[5], (Ull)cofs, 13, (Ull)b[5], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[6][1][0], (Ull)b3[5], (Ull)cofs, 13, (Ull)b[5], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[6][2][1], (Ull)a[5][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[7][0], AR[6][0], 0, BR[6][2][1], 1, BR[6][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[7][1], AR[6][1], 0, BR[6][2][1], 1, BR[6][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[7][2], AR[6][2], 0, BR[6][2][1], 1, BR[6][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[7][3], AR[6][3], 0, BR[6][2][1], 1, BR[6][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[7][0][1], (Ull)b0[6], (Ull)cofs, 13, (Ull)b[6], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[7][0][0], (Ull)b1[6], (Ull)cofs, 13, (Ull)b[6], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[7][1][1], (Ull)b2[6], (Ull)cofs, 13, (Ull)b[6], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[7][1][0], (Ull)b3[6], (Ull)cofs, 13, (Ull)b[6], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[7][2][1], (Ull)a[6][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[8][0], AR[7][0], 0, BR[7][2][1], 1, BR[7][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[8][1], AR[7][1], 0, BR[7][2][1], 1, BR[7][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[8][2], AR[7][2], 0, BR[7][2][1], 1, BR[7][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[8][3], AR[7][3], 0, BR[7][2][1], 1, BR[7][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[8][0][1], (Ull)b0[7], (Ull)cofs, 13, (Ull)b[7], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[8][0][0], (Ull)b1[7], (Ull)cofs, 13, (Ull)b[7], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[8][1][1], (Ull)b2[7], (Ull)cofs, 13, (Ull)b[7], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[8][1][0], (Ull)b3[7], (Ull)cofs, 13, (Ull)b[7], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[8][2][1], (Ull)a[7][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[9][0], AR[8][0], 0, BR[8][2][1], 1, BR[8][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[9][1], AR[8][1], 0, BR[8][2][1], 1, BR[8][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[9][2], AR[8][2], 0, BR[8][2][1], 1, BR[8][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[9][3], AR[8][3], 0, BR[8][2][1], 1, BR[8][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[9][0][1], (Ull)b0[8], (Ull)cofs, 13, (Ull)b[8], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[9][0][0], (Ull)b1[8], (Ull)cofs, 13, (Ull)b[8], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[9][1][1], (Ull)b2[8], (Ull)cofs, 13, (Ull)b[8], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[9][1][0], (Ull)b3[8], (Ull)cofs, 13, (Ull)b[8], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[9][2][1], (Ull)a[8][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[10][0], AR[9][0], 0, BR[9][2][1], 1, BR[9][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[10][1], AR[9][1], 0, BR[9][2][1], 1, BR[9][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[10][2], AR[9][2], 0, BR[9][2][1], 1, BR[9][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[10][3], AR[9][3], 0, BR[9][2][1], 1, BR[9][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[10][0][1], (Ull)b0[9], (Ull)cofs, 13, (Ull)b[9], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[10][0][0], (Ull)b1[9], (Ull)cofs, 13, (Ull)b[9], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[10][1][1], (Ull)b2[9], (Ull)cofs, 13, (Ull)b[9], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[10][1][0], (Ull)b3[9], (Ull)cofs, 13, (Ull)b[9], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[10][2][1], (Ull)a[9][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[11][0], AR[10][0], 0, BR[10][2][1], 1, BR[10][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[11][1], AR[10][1], 0, BR[10][2][1], 1, BR[10][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[11][2], AR[10][2], 0, BR[10][2][1], 1, BR[10][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[11][3], AR[10][3], 0, BR[10][2][1], 1, BR[10][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[11][0][1], (Ull)b0[10], (Ull)cofs, 13, (Ull)b[10], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[11][0][0], (Ull)b1[10], (Ull)cofs, 13, (Ull)b[10], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[11][1][1], (Ull)b2[10], (Ull)cofs, 13, (Ull)b[10], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[11][1][0], (Ull)b3[10], (Ull)cofs, 13, (Ull)b[10], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[11][2][1], (Ull)a[10][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[12][0], AR[11][0], 0, BR[11][2][1], 1, BR[11][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[12][1], AR[11][1], 0, BR[11][2][1], 1, BR[11][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[12][2], AR[11][2], 0, BR[11][2][1], 1, BR[11][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[12][3], AR[11][3], 0, BR[11][2][1], 1, BR[11][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[12][0][1], (Ull)b0[11], (Ull)cofs, 13, (Ull)b[11], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[12][0][0], (Ull)b1[11], (Ull)cofs, 13, (Ull)b[11], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[12][1][1], (Ull)b2[11], (Ull)cofs, 13, (Ull)b[11], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[12][1][0], (Ull)b3[11], (Ull)cofs, 13, (Ull)b[11], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[12][2][1], (Ull)a[11][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[13][0], AR[12][0], 0, BR[12][2][1], 1, BR[12][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[13][1], AR[12][1], 0, BR[12][2][1], 1, BR[12][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[13][2], AR[12][2], 0, BR[12][2][1], 1, BR[12][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[13][3], AR[12][3], 0, BR[12][2][1], 1, BR[12][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[13][0][1], (Ull)b0[12], (Ull)cofs, 13, (Ull)b[12], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[13][0][0], (Ull)b1[12], (Ull)cofs, 13, (Ull)b[12], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[13][1][1], (Ull)b2[12], (Ull)cofs, 13, (Ull)b[12], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[13][1][0], (Ull)b3[12], (Ull)cofs, 13, (Ull)b[12], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[13][2][1], (Ull)a[12][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[14][0], AR[13][0], 0, BR[13][2][1], 1, BR[13][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[14][1], AR[13][1], 0, BR[13][2][1], 1, BR[13][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[14][2], AR[13][2], 0, BR[13][2][1], 1, BR[13][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[14][3], AR[13][3], 0, BR[13][2][1], 1, BR[13][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[14][0][1], (Ull)b0[13], (Ull)cofs, 13, (Ull)b[13], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[14][0][0], (Ull)b1[13], (Ull)cofs, 13, (Ull)b[13], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[14][1][1], (Ull)b2[13], (Ull)cofs, 13, (Ull)b[13], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[14][1][0], (Ull)b3[13], (Ull)cofs, 13, (Ull)b[13], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[14][2][1], (Ull)a[13][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[15][0], AR[14][0], 0, BR[14][2][1], 1, BR[14][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[15][1], AR[14][1], 0, BR[14][2][1], 1, BR[14][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[15][2], AR[14][2], 0, BR[14][2][1], 1, BR[14][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[15][3], AR[14][3], 0, BR[14][2][1], 1, BR[14][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[15][0][1], (Ull)b0[14], (Ull)cofs, 13, (Ull)b[14], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[15][0][0], (Ull)b1[14], (Ull)cofs, 13, (Ull)b[14], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[15][1][1], (Ull)b2[14], (Ull)cofs, 13, (Ull)b[14], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[15][1][0], (Ull)b3[14], (Ull)cofs, 13, (Ull)b[14], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[15][2][1], (Ull)a[14][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[16][0], AR[15][0], 0, BR[15][2][1], 1, BR[15][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[16][1], AR[15][1], 0, BR[15][2][1], 1, BR[15][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[16][2], AR[15][2], 0, BR[15][2][1], 1, BR[15][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[16][3], AR[15][3], 0, BR[15][2][1], 1, BR[15][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[16][0][1], (Ull)b0[15], (Ull)cofs, 13, (Ull)b[15], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[16][0][0], (Ull)b1[15], (Ull)cofs, 13, (Ull)b[15], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[16][1][1], (Ull)b2[15], (Ull)cofs, 13, (Ull)b[15], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[16][1][0], (Ull)b3[15], (Ull)cofs, 13, (Ull)b[15], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[16][2][1], (Ull)a[15][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[17][0], AR[16][0], 0, BR[16][2][1], 1, BR[16][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[17][1], AR[16][1], 0, BR[16][2][1], 1, BR[16][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[17][2], AR[16][2], 0, BR[16][2][1], 1, BR[16][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[17][3], AR[16][3], 0, BR[16][2][1], 1, BR[16][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[17][0][1], (Ull)b0[16], (Ull)cofs, 13, (Ull)b[16], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[17][0][0], (Ull)b1[16], (Ull)cofs, 13, (Ull)b[16], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[17][1][1], (Ull)b2[16], (Ull)cofs, 13, (Ull)b[16], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[17][1][0], (Ull)b3[16], (Ull)cofs, 13, (Ull)b[16], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[17][2][1], (Ull)a[16][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[18][0], AR[17][0], 0, BR[17][2][1], 1, BR[17][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[18][1], AR[17][1], 0, BR[17][2][1], 1, BR[17][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[18][2], AR[17][2], 0, BR[17][2][1], 1, BR[17][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[18][3], AR[17][3], 0, BR[17][2][1], 1, BR[17][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[18][0][1], (Ull)b0[17], (Ull)cofs, 13, (Ull)b[17], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[18][0][0], (Ull)b1[17], (Ull)cofs, 13, (Ull)b[17], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[18][1][1], (Ull)b2[17], (Ull)cofs, 13, (Ull)b[17], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[18][1][0], (Ull)b3[17], (Ull)cofs, 13, (Ull)b[17], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[18][2][1], (Ull)a[17][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[19][0], AR[18][0], 0, BR[18][2][1], 1, BR[18][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[19][1], AR[18][1], 0, BR[18][2][1], 1, BR[18][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[19][2], AR[18][2], 0, BR[18][2][1], 1, BR[18][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[19][3], AR[18][3], 0, BR[18][2][1], 1, BR[18][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[19][0][1], (Ull)b0[18], (Ull)cofs, 13, (Ull)b[18], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[19][0][0], (Ull)b1[18], (Ull)cofs, 13, (Ull)b[18], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[19][1][1], (Ull)b2[18], (Ull)cofs, 13, (Ull)b[18], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[19][1][0], (Ull)b3[18], (Ull)cofs, 13, (Ull)b[18], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[19][2][1], (Ull)a[18][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[20][0], AR[19][0], 0, BR[19][2][1], 1, BR[19][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[20][1], AR[19][1], 0, BR[19][2][1], 1, BR[19][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[20][2], AR[19][2], 0, BR[19][2][1], 1, BR[19][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[20][3], AR[19][3], 0, BR[19][2][1], 1, BR[19][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[20][0][1], (Ull)b0[19], (Ull)cofs, 13, (Ull)b[19], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[20][0][0], (Ull)b1[19], (Ull)cofs, 13, (Ull)b[19], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[20][1][1], (Ull)b2[19], (Ull)cofs, 13, (Ull)b[19], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[20][1][0], (Ull)b3[19], (Ull)cofs, 13, (Ull)b[19], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[20][2][1], (Ull)a[19][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[21][0], AR[20][0], 0, BR[20][2][1], 1, BR[20][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[21][1], AR[20][1], 0, BR[20][2][1], 1, BR[20][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[21][2], AR[20][2], 0, BR[20][2][1], 1, BR[20][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[21][3], AR[20][3], 0, BR[20][2][1], 1, BR[20][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[21][0][1], (Ull)b0[20], (Ull)cofs, 13, (Ull)b[20], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[21][0][0], (Ull)b1[20], (Ull)cofs, 13, (Ull)b[20], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[21][1][1], (Ull)b2[20], (Ull)cofs, 13, (Ull)b[20], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[21][1][0], (Ull)b3[20], (Ull)cofs, 13, (Ull)b[20], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[21][2][1], (Ull)a[20][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[22][0], AR[21][0], 0, BR[21][2][1], 1, BR[21][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[22][1], AR[21][1], 0, BR[21][2][1], 1, BR[21][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[22][2], AR[21][2], 0, BR[21][2][1], 1, BR[21][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[22][3], AR[21][3], 0, BR[21][2][1], 1, BR[21][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[22][0][1], (Ull)b0[21], (Ull)cofs, 13, (Ull)b[21], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[22][0][0], (Ull)b1[21], (Ull)cofs, 13, (Ull)b[21], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[22][1][1], (Ull)b2[21], (Ull)cofs, 13, (Ull)b[21], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[22][1][0], (Ull)b3[21], (Ull)cofs, 13, (Ull)b[21], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[22][2][1], (Ull)a[21][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[23][0], AR[22][0], 0, BR[22][2][1], 1, BR[22][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[23][1], AR[22][1], 0, BR[22][2][1], 1, BR[22][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[23][2], AR[22][2], 0, BR[22][2][1], 1, BR[22][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[23][3], AR[22][3], 0, BR[22][2][1], 1, BR[22][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[23][0][1], (Ull)b0[22], (Ull)cofs, 13, (Ull)b[22], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[23][0][0], (Ull)b1[22], (Ull)cofs, 13, (Ull)b[22], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[23][1][1], (Ull)b2[22], (Ull)cofs, 13, (Ull)b[22], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[23][1][0], (Ull)b3[22], (Ull)cofs, 13, (Ull)b[22], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[23][2][1], (Ull)a[22][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[24][0], AR[23][0], 0, BR[23][2][1], 1, BR[23][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[24][1], AR[23][1], 0, BR[23][2][1], 1, BR[23][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[24][2], AR[23][2], 0, BR[23][2][1], 1, BR[23][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[24][3], AR[23][3], 0, BR[23][2][1], 1, BR[23][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[24][0][1], (Ull)b0[23], (Ull)cofs, 13, (Ull)b[23], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[24][0][0], (Ull)b1[23], (Ull)cofs, 13, (Ull)b[23], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[24][1][1], (Ull)b2[23], (Ull)cofs, 13, (Ull)b[23], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[24][1][0], (Ull)b3[23], (Ull)cofs, 13, (Ull)b[23], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[24][2][1], (Ull)a[23][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[25][0], AR[24][0], 0, BR[24][2][1], 1, BR[24][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[25][1], AR[24][1], 0, BR[24][2][1], 1, BR[24][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[25][2], AR[24][2], 0, BR[24][2][1], 1, BR[24][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[25][3], AR[24][3], 0, BR[24][2][1], 1, BR[24][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[25][0][1], (Ull)b0[24], (Ull)cofs, 13, (Ull)b[24], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[25][0][0], (Ull)b1[24], (Ull)cofs, 13, (Ull)b[24], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[25][1][1], (Ull)b2[24], (Ull)cofs, 13, (Ull)b[24], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[25][1][0], (Ull)b3[24], (Ull)cofs, 13, (Ull)b[24], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[25][2][1], (Ull)a[24][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[26][0], AR[25][0], 0, BR[25][2][1], 1, BR[25][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[26][1], AR[25][1], 0, BR[25][2][1], 1, BR[25][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[26][2], AR[25][2], 0, BR[25][2][1], 1, BR[25][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[26][3], AR[25][3], 0, BR[25][2][1], 1, BR[25][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[26][0][1], (Ull)b0[25], (Ull)cofs, 13, (Ull)b[25], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[26][0][0], (Ull)b1[25], (Ull)cofs, 13, (Ull)b[25], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[26][1][1], (Ull)b2[25], (Ull)cofs, 13, (Ull)b[25], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[26][1][0], (Ull)b3[25], (Ull)cofs, 13, (Ull)b[25], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[26][2][1], (Ull)a[25][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[27][0], AR[26][0], 0, BR[26][2][1], 1, BR[26][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[27][1], AR[26][1], 0, BR[26][2][1], 1, BR[26][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[27][2], AR[26][2], 0, BR[26][2][1], 1, BR[26][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[27][3], AR[26][3], 0, BR[26][2][1], 1, BR[26][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[27][0][1], (Ull)b0[26], (Ull)cofs, 13, (Ull)b[26], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[27][0][0], (Ull)b1[26], (Ull)cofs, 13, (Ull)b[26], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[27][1][1], (Ull)b2[26], (Ull)cofs, 13, (Ull)b[26], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[27][1][0], (Ull)b3[26], (Ull)cofs, 13, (Ull)b[26], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[27][2][1], (Ull)a[26][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[28][0], AR[27][0], 0, BR[27][2][1], 1, BR[27][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[28][1], AR[27][1], 0, BR[27][2][1], 1, BR[27][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[28][2], AR[27][2], 0, BR[27][2][1], 1, BR[27][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[28][3], AR[27][3], 0, BR[27][2][1], 1, BR[27][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[28][0][1], (Ull)b0[27], (Ull)cofs, 13, (Ull)b[27], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[28][0][0], (Ull)b1[27], (Ull)cofs, 13, (Ull)b[27], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[28][1][1], (Ull)b2[27], (Ull)cofs, 13, (Ull)b[27], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[28][1][0], (Ull)b3[27], (Ull)cofs, 13, (Ull)b[27], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[28][2][1], (Ull)a[27][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[29][0], AR[28][0], 0, BR[28][2][1], 1, BR[28][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[29][1], AR[28][1], 0, BR[28][2][1], 1, BR[28][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[29][2], AR[28][2], 0, BR[28][2][1], 1, BR[28][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[29][3], AR[28][3], 0, BR[28][2][1], 1, BR[28][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[29][0][1], (Ull)b0[28], (Ull)cofs, 13, (Ull)b[28], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[29][0][0], (Ull)b1[28], (Ull)cofs, 13, (Ull)b[28], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[29][1][1], (Ull)b2[28], (Ull)cofs, 13, (Ull)b[28], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[29][1][0], (Ull)b3[28], (Ull)cofs, 13, (Ull)b[28], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[29][2][1], (Ull)a[28][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[30][0], AR[29][0], 0, BR[29][2][1], 1, BR[29][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[30][1], AR[29][1], 0, BR[29][2][1], 1, BR[29][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[30][2], AR[29][2], 0, BR[29][2][1], 1, BR[29][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[30][3], AR[29][3], 0, BR[29][2][1], 1, BR[29][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[30][0][1], (Ull)b0[29], (Ull)cofs, 13, (Ull)b[29], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[30][0][0], (Ull)b1[29], (Ull)cofs, 13, (Ull)b[29], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[30][1][1], (Ull)b2[29], (Ull)cofs, 13, (Ull)b[29], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[30][1][0], (Ull)b3[29], (Ull)cofs, 13, (Ull)b[29], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[30][2][1], (Ull)a[29][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[31][0], AR[30][0], 0, BR[30][2][1], 1, BR[30][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[31][1], AR[30][1], 0, BR[30][2][1], 1, BR[30][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[31][2], AR[30][2], 0, BR[30][2][1], 1, BR[30][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[31][3], AR[30][3], 0, BR[30][2][1], 1, BR[30][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[31][0][1], (Ull)b0[30], (Ull)cofs, 13, (Ull)b[30], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[31][0][0], (Ull)b1[30], (Ull)cofs, 13, (Ull)b[30], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[31][1][1], (Ull)b2[30], (Ull)cofs, 13, (Ull)b[30], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[31][1][0], (Ull)b3[30], (Ull)cofs, 13, (Ull)b[30], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[31][2][1], (Ull)a[30][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[32][0], AR[31][0], 0, BR[31][2][1], 1, BR[31][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[32][1], AR[31][1], 0, BR[31][2][1], 1, BR[31][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[32][2], AR[31][2], 0, BR[31][2][1], 1, BR[31][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[32][3], AR[31][3], 0, BR[31][2][1], 1, BR[31][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[32][0][1], (Ull)b0[31], (Ull)cofs, 13, (Ull)b[31], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[32][0][0], (Ull)b1[31], (Ull)cofs, 13, (Ull)b[31], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[32][1][1], (Ull)b2[31], (Ull)cofs, 13, (Ull)b[31], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[32][1][0], (Ull)b3[31], (Ull)cofs, 13, (Ull)b[31], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[32][2][1], (Ull)a[31][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[33][0], AR[32][0], 0, BR[32][2][1], 1, BR[32][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[33][1], AR[32][1], 0, BR[32][2][1], 1, BR[32][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[33][2], AR[32][2], 0, BR[32][2][1], 1, BR[32][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[33][3], AR[32][3], 0, BR[32][2][1], 1, BR[32][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[33][0][1], (Ull)b0[32], (Ull)cofs, 13, (Ull)b[32], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[33][0][0], (Ull)b1[32], (Ull)cofs, 13, (Ull)b[32], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[33][1][1], (Ull)b2[32], (Ull)cofs, 13, (Ull)b[32], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[33][1][0], (Ull)b3[32], (Ull)cofs, 13, (Ull)b[32], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[33][2][1], (Ull)a[32][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[34][0], AR[33][0], 0, BR[33][2][1], 1, BR[33][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[34][1], AR[33][1], 0, BR[33][2][1], 1, BR[33][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[34][2], AR[33][2], 0, BR[33][2][1], 1, BR[33][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[34][3], AR[33][3], 0, BR[33][2][1], 1, BR[33][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[34][0][1], (Ull)b0[33], (Ull)cofs, 13, (Ull)b[33], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[34][0][0], (Ull)b1[33], (Ull)cofs, 13, (Ull)b[33], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[34][1][1], (Ull)b2[33], (Ull)cofs, 13, (Ull)b[33], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[34][1][0], (Ull)b3[33], (Ull)cofs, 13, (Ull)b[33], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[34][2][1], (Ull)a[33][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[35][0], AR[34][0], 0, BR[34][2][1], 1, BR[34][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[35][1], AR[34][1], 0, BR[34][2][1], 1, BR[34][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[35][2], AR[34][2], 0, BR[34][2][1], 1, BR[34][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[35][3], AR[34][3], 0, BR[34][2][1], 1, BR[34][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[35][0][1], (Ull)b0[34], (Ull)cofs, 13, (Ull)b[34], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[35][0][0], (Ull)b1[34], (Ull)cofs, 13, (Ull)b[34], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[35][1][1], (Ull)b2[34], (Ull)cofs, 13, (Ull)b[34], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[35][1][0], (Ull)b3[34], (Ull)cofs, 13, (Ull)b[34], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[35][2][1], (Ull)a[34][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[36][0], AR[35][0], 0, BR[35][2][1], 1, BR[35][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[36][1], AR[35][1], 0, BR[35][2][1], 1, BR[35][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[36][2], AR[35][2], 0, BR[35][2][1], 1, BR[35][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[36][3], AR[35][3], 0, BR[35][2][1], 1, BR[35][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[36][0][1], (Ull)b0[35], (Ull)cofs, 13, (Ull)b[35], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[36][0][0], (Ull)b1[35], (Ull)cofs, 13, (Ull)b[35], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[36][1][1], (Ull)b2[35], (Ull)cofs, 13, (Ull)b[35], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[36][1][0], (Ull)b3[35], (Ull)cofs, 13, (Ull)b[35], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[36][2][1], (Ull)a[35][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[37][0], AR[36][0], 0, BR[36][2][1], 1, BR[36][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[37][1], AR[36][1], 0, BR[36][2][1], 1, BR[36][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[37][2], AR[36][2], 0, BR[36][2][1], 1, BR[36][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[37][3], AR[36][3], 0, BR[36][2][1], 1, BR[36][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[37][0][1], (Ull)b0[36], (Ull)cofs, 13, (Ull)b[36], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[37][0][0], (Ull)b1[36], (Ull)cofs, 13, (Ull)b[36], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[37][1][1], (Ull)b2[36], (Ull)cofs, 13, (Ull)b[36], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[37][1][0], (Ull)b3[36], (Ull)cofs, 13, (Ull)b[36], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[37][2][1], (Ull)a[36][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[38][0], AR[37][0], 0, BR[37][2][1], 1, BR[37][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[38][1], AR[37][1], 0, BR[37][2][1], 1, BR[37][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[38][2], AR[37][2], 0, BR[37][2][1], 1, BR[37][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[38][3], AR[37][3], 0, BR[37][2][1], 1, BR[37][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[38][0][1], (Ull)b0[37], (Ull)cofs, 13, (Ull)b[37], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[38][0][0], (Ull)b1[37], (Ull)cofs, 13, (Ull)b[37], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[38][1][1], (Ull)b2[37], (Ull)cofs, 13, (Ull)b[37], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[38][1][0], (Ull)b3[37], (Ull)cofs, 13, (Ull)b[37], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[38][2][1], (Ull)a[37][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[39][0], AR[38][0], 0, BR[38][2][1], 1, BR[38][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[39][1], AR[38][1], 0, BR[38][2][1], 1, BR[38][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[39][2], AR[38][2], 0, BR[38][2][1], 1, BR[38][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[39][3], AR[38][3], 0, BR[38][2][1], 1, BR[38][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[39][0][1], (Ull)b0[38], (Ull)cofs, 13, (Ull)b[38], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[39][0][0], (Ull)b1[38], (Ull)cofs, 13, (Ull)b[38], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[39][1][1], (Ull)b2[38], (Ull)cofs, 13, (Ull)b[38], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[39][1][0], (Ull)b3[38], (Ull)cofs, 13, (Ull)b[38], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[39][2][1], (Ull)a[38][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[40][0], AR[39][0], 0, BR[39][2][1], 1, BR[39][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[40][1], AR[39][1], 0, BR[39][2][1], 1, BR[39][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[40][2], AR[39][2], 0, BR[39][2][1], 1, BR[39][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[40][3], AR[39][3], 0, BR[39][2][1], 1, BR[39][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[40][0][1], (Ull)b0[39], (Ull)cofs, 13, (Ull)b[39], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[40][0][0], (Ull)b1[39], (Ull)cofs, 13, (Ull)b[39], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[40][1][1], (Ull)b2[39], (Ull)cofs, 13, (Ull)b[39], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[40][1][0], (Ull)b3[39], (Ull)cofs, 13, (Ull)b[39], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[40][2][1], (Ull)a[39][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[41][0], AR[40][0], 0, BR[40][2][1], 1, BR[40][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[41][1], AR[40][1], 0, BR[40][2][1], 1, BR[40][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[41][2], AR[40][2], 0, BR[40][2][1], 1, BR[40][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[41][3], AR[40][3], 0, BR[40][2][1], 1, BR[40][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[41][0][1], (Ull)b0[40], (Ull)cofs, 13, (Ull)b[40], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[41][0][0], (Ull)b1[40], (Ull)cofs, 13, (Ull)b[40], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[41][1][1], (Ull)b2[40], (Ull)cofs, 13, (Ull)b[40], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[41][1][0], (Ull)b3[40], (Ull)cofs, 13, (Ull)b[40], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[41][2][1], (Ull)a[40][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[42][0], AR[41][0], 0, BR[41][2][1], 1, BR[41][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[42][1], AR[41][1], 0, BR[41][2][1], 1, BR[41][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[42][2], AR[41][2], 0, BR[41][2][1], 1, BR[41][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[42][3], AR[41][3], 0, BR[41][2][1], 1, BR[41][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[42][0][1], (Ull)b0[41], (Ull)cofs, 13, (Ull)b[41], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[42][0][0], (Ull)b1[41], (Ull)cofs, 13, (Ull)b[41], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[42][1][1], (Ull)b2[41], (Ull)cofs, 13, (Ull)b[41], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[42][1][0], (Ull)b3[41], (Ull)cofs, 13, (Ull)b[41], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[42][2][1], (Ull)a[41][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[43][0], AR[42][0], 0, BR[42][2][1], 1, BR[42][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[43][1], AR[42][1], 0, BR[42][2][1], 1, BR[42][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[43][2], AR[42][2], 0, BR[42][2][1], 1, BR[42][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[43][3], AR[42][3], 0, BR[42][2][1], 1, BR[42][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[43][0][1], (Ull)b0[42], (Ull)cofs, 13, (Ull)b[42], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[43][0][0], (Ull)b1[42], (Ull)cofs, 13, (Ull)b[42], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[43][1][1], (Ull)b2[42], (Ull)cofs, 13, (Ull)b[42], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[43][1][0], (Ull)b3[42], (Ull)cofs, 13, (Ull)b[42], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[43][2][1], (Ull)a[42][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[44][0], AR[43][0], 0, BR[43][2][1], 1, BR[43][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[44][1], AR[43][1], 0, BR[43][2][1], 1, BR[43][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[44][2], AR[43][2], 0, BR[43][2][1], 1, BR[43][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[44][3], AR[43][3], 0, BR[43][2][1], 1, BR[43][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[44][0][1], (Ull)b0[43], (Ull)cofs, 13, (Ull)b[43], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[44][0][0], (Ull)b1[43], (Ull)cofs, 13, (Ull)b[43], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[44][1][1], (Ull)b2[43], (Ull)cofs, 13, (Ull)b[43], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[44][1][0], (Ull)b3[43], (Ull)cofs, 13, (Ull)b[43], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[44][2][1], (Ull)a[43][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[45][0], AR[44][0], 0, BR[44][2][1], 1, BR[44][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[45][1], AR[44][1], 0, BR[44][2][1], 1, BR[44][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[45][2], AR[44][2], 0, BR[44][2][1], 1, BR[44][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[45][3], AR[44][3], 0, BR[44][2][1], 1, BR[44][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[45][0][1], (Ull)b0[44], (Ull)cofs, 13, (Ull)b[44], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[45][0][0], (Ull)b1[44], (Ull)cofs, 13, (Ull)b[44], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[45][1][1], (Ull)b2[44], (Ull)cofs, 13, (Ull)b[44], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[45][1][0], (Ull)b3[44], (Ull)cofs, 13, (Ull)b[44], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[45][2][1], (Ull)a[44][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[46][0], AR[45][0], 0, BR[45][2][1], 1, BR[45][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[46][1], AR[45][1], 0, BR[45][2][1], 1, BR[45][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[46][2], AR[45][2], 0, BR[45][2][1], 1, BR[45][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[46][3], AR[45][3], 0, BR[45][2][1], 1, BR[45][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[46][0][1], (Ull)b0[45], (Ull)cofs, 13, (Ull)b[45], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[46][0][0], (Ull)b1[45], (Ull)cofs, 13, (Ull)b[45], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[46][1][1], (Ull)b2[45], (Ull)cofs, 13, (Ull)b[45], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[46][1][0], (Ull)b3[45], (Ull)cofs, 13, (Ull)b[45], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[46][2][1], (Ull)a[45][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[47][0], AR[46][0], 0, BR[46][2][1], 1, BR[46][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[47][1], AR[46][1], 0, BR[46][2][1], 1, BR[46][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[47][2], AR[46][2], 0, BR[46][2][1], 1, BR[46][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[47][3], AR[46][3], 0, BR[46][2][1], 1, BR[46][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[47][0][1], (Ull)b0[46], (Ull)cofs, 13, (Ull)b[46], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[47][0][0], (Ull)b1[46], (Ull)cofs, 13, (Ull)b[46], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[47][1][1], (Ull)b2[46], (Ull)cofs, 13, (Ull)b[46], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[47][1][0], (Ull)b3[46], (Ull)cofs, 13, (Ull)b[46], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[47][2][1], (Ull)a[46][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[48][0], AR[47][0], 0, BR[47][2][1], 1, BR[47][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[48][1], AR[47][1], 0, BR[47][2][1], 1, BR[47][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[48][2], AR[47][2], 0, BR[47][2][1], 1, BR[47][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[48][3], AR[47][3], 0, BR[47][2][1], 1, BR[47][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[48][0][1], (Ull)b0[47], (Ull)cofs, 13, (Ull)b[47], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[48][0][0], (Ull)b1[47], (Ull)cofs, 13, (Ull)b[47], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[48][1][1], (Ull)b2[47], (Ull)cofs, 13, (Ull)b[47], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[48][1][0], (Ull)b3[47], (Ull)cofs, 13, (Ull)b[47], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[48][2][1], (Ull)a[47][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[49][0], AR[48][0], 0, BR[48][2][1], 1, BR[48][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[49][1], AR[48][1], 0, BR[48][2][1], 1, BR[48][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[49][2], AR[48][2], 0, BR[48][2][1], 1, BR[48][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[49][3], AR[48][3], 0, BR[48][2][1], 1, BR[48][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[49][0][1], (Ull)b0[48], (Ull)cofs, 13, (Ull)b[48], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[49][0][0], (Ull)b1[48], (Ull)cofs, 13, (Ull)b[48], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[49][1][1], (Ull)b2[48], (Ull)cofs, 13, (Ull)b[48], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[49][1][0], (Ull)b3[48], (Ull)cofs, 13, (Ull)b[48], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[49][2][1], (Ull)a[48][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[50][0], AR[49][0], 0, BR[49][2][1], 1, BR[49][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[50][1], AR[49][1], 0, BR[49][2][1], 1, BR[49][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[50][2], AR[49][2], 0, BR[49][2][1], 1, BR[49][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[50][3], AR[49][3], 0, BR[49][2][1], 1, BR[49][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[50][0][1], (Ull)b0[49], (Ull)cofs, 13, (Ull)b[49], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[50][0][0], (Ull)b1[49], (Ull)cofs, 13, (Ull)b[49], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[50][1][1], (Ull)b2[49], (Ull)cofs, 13, (Ull)b[49], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[50][1][0], (Ull)b3[49], (Ull)cofs, 13, (Ull)b[49], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[50][2][1], (Ull)a[49][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[51][0], AR[50][0], 0, BR[50][2][1], 1, BR[50][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[51][1], AR[50][1], 0, BR[50][2][1], 1, BR[50][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[51][2], AR[50][2], 0, BR[50][2][1], 1, BR[50][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[51][3], AR[50][3], 0, BR[50][2][1], 1, BR[50][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[51][0][1], (Ull)b0[50], (Ull)cofs, 13, (Ull)b[50], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[51][0][0], (Ull)b1[50], (Ull)cofs, 13, (Ull)b[50], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[51][1][1], (Ull)b2[50], (Ull)cofs, 13, (Ull)b[50], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[51][1][0], (Ull)b3[50], (Ull)cofs, 13, (Ull)b[50], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[51][2][1], (Ull)a[50][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[52][0], AR[51][0], 0, BR[51][2][1], 1, BR[51][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[52][1], AR[51][1], 0, BR[51][2][1], 1, BR[51][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[52][2], AR[51][2], 0, BR[51][2][1], 1, BR[51][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[52][3], AR[51][3], 0, BR[51][2][1], 1, BR[51][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[52][0][1], (Ull)b0[51], (Ull)cofs, 13, (Ull)b[51], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[52][0][0], (Ull)b1[51], (Ull)cofs, 13, (Ull)b[51], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[52][1][1], (Ull)b2[51], (Ull)cofs, 13, (Ull)b[51], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[52][1][0], (Ull)b3[51], (Ull)cofs, 13, (Ull)b[51], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[52][2][1], (Ull)a[51][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[53][0], AR[52][0], 0, BR[52][2][1], 1, BR[52][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[53][1], AR[52][1], 0, BR[52][2][1], 1, BR[52][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[53][2], AR[52][2], 0, BR[52][2][1], 1, BR[52][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[53][3], AR[52][3], 0, BR[52][2][1], 1, BR[52][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[53][0][1], (Ull)b0[52], (Ull)cofs, 13, (Ull)b[52], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[53][0][0], (Ull)b1[52], (Ull)cofs, 13, (Ull)b[52], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[53][1][1], (Ull)b2[52], (Ull)cofs, 13, (Ull)b[52], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[53][1][0], (Ull)b3[52], (Ull)cofs, 13, (Ull)b[52], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[53][2][1], (Ull)a[52][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[54][0], AR[53][0], 0, BR[53][2][1], 1, BR[53][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[54][1], AR[53][1], 0, BR[53][2][1], 1, BR[53][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[54][2], AR[53][2], 0, BR[53][2][1], 1, BR[53][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[54][3], AR[53][3], 0, BR[53][2][1], 1, BR[53][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[54][0][1], (Ull)b0[53], (Ull)cofs, 13, (Ull)b[53], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[54][0][0], (Ull)b1[53], (Ull)cofs, 13, (Ull)b[53], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[54][1][1], (Ull)b2[53], (Ull)cofs, 13, (Ull)b[53], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[54][1][0], (Ull)b3[53], (Ull)cofs, 13, (Ull)b[53], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[54][2][1], (Ull)a[53][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[55][0], AR[54][0], 0, BR[54][2][1], 1, BR[54][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[55][1], AR[54][1], 0, BR[54][2][1], 1, BR[54][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[55][2], AR[54][2], 0, BR[54][2][1], 1, BR[54][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[55][3], AR[54][3], 0, BR[54][2][1], 1, BR[54][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[55][0][1], (Ull)b0[54], (Ull)cofs, 13, (Ull)b[54], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[55][0][0], (Ull)b1[54], (Ull)cofs, 13, (Ull)b[54], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[55][1][1], (Ull)b2[54], (Ull)cofs, 13, (Ull)b[54], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[55][1][0], (Ull)b3[54], (Ull)cofs, 13, (Ull)b[54], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[55][2][1], (Ull)a[54][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[56][0], AR[55][0], 0, BR[55][2][1], 1, BR[55][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[56][1], AR[55][1], 0, BR[55][2][1], 1, BR[55][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[56][2], AR[55][2], 0, BR[55][2][1], 1, BR[55][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[56][3], AR[55][3], 0, BR[55][2][1], 1, BR[55][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[56][0][1], (Ull)b0[55], (Ull)cofs, 13, (Ull)b[55], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[56][0][0], (Ull)b1[55], (Ull)cofs, 13, (Ull)b[55], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[56][1][1], (Ull)b2[55], (Ull)cofs, 13, (Ull)b[55], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[56][1][0], (Ull)b3[55], (Ull)cofs, 13, (Ull)b[55], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[56][2][1], (Ull)a[55][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[57][0], AR[56][0], 0, BR[56][2][1], 1, BR[56][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[57][1], AR[56][1], 0, BR[56][2][1], 1, BR[56][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[57][2], AR[56][2], 0, BR[56][2][1], 1, BR[56][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[57][3], AR[56][3], 0, BR[56][2][1], 1, BR[56][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[57][0][1], (Ull)b0[56], (Ull)cofs, 13, (Ull)b[56], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[57][0][0], (Ull)b1[56], (Ull)cofs, 13, (Ull)b[56], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[57][1][1], (Ull)b2[56], (Ull)cofs, 13, (Ull)b[56], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[57][1][0], (Ull)b3[56], (Ull)cofs, 13, (Ull)b[56], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[57][2][1], (Ull)a[56][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[58][0], AR[57][0], 0, BR[57][2][1], 1, BR[57][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[58][1], AR[57][1], 0, BR[57][2][1], 1, BR[57][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[58][2], AR[57][2], 0, BR[57][2][1], 1, BR[57][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[58][3], AR[57][3], 0, BR[57][2][1], 1, BR[57][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[58][0][1], (Ull)b0[57], (Ull)cofs, 13, (Ull)b[57], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[58][0][0], (Ull)b1[57], (Ull)cofs, 13, (Ull)b[57], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[58][1][1], (Ull)b2[57], (Ull)cofs, 13, (Ull)b[57], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[58][1][0], (Ull)b3[57], (Ull)cofs, 13, (Ull)b[57], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[58][2][1], (Ull)a[57][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[59][0], AR[58][0], 0, BR[58][2][1], 1, BR[58][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[59][1], AR[58][1], 0, BR[58][2][1], 1, BR[58][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[59][2], AR[58][2], 0, BR[58][2][1], 1, BR[58][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[59][3], AR[58][3], 0, BR[58][2][1], 1, BR[58][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[59][0][1], (Ull)b0[58], (Ull)cofs, 13, (Ull)b[58], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[59][0][0], (Ull)b1[58], (Ull)cofs, 13, (Ull)b[58], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[59][1][1], (Ull)b2[58], (Ull)cofs, 13, (Ull)b[58], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[59][1][0], (Ull)b3[58], (Ull)cofs, 13, (Ull)b[58], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[59][2][1], (Ull)a[58][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[60][0], AR[59][0], 0, BR[59][2][1], 1, BR[59][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[60][1], AR[59][1], 0, BR[59][2][1], 1, BR[59][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[60][2], AR[59][2], 0, BR[59][2][1], 1, BR[59][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[60][3], AR[59][3], 0, BR[59][2][1], 1, BR[59][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/ mop(0x01, 3, &BR[60][0][1], (Ull)b0[59], (Ull)cofs, 13, (Ull)b[59], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[60][0][0], (Ull)b1[59], (Ull)cofs, 13, (Ull)b[59], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[60][1][1], (Ull)b2[59], (Ull)cofs, 13, (Ull)b[59], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x01, 3, &BR[60][1][0], (Ull)b3[59], (Ull)cofs, 13, (Ull)b[59], B_col_size, 0, 0, (Ull)((void *)0), B_col_size); mop(0x02,1, &BR[60][2][1], (Ull)a[59][CHIP], (Ull)rofs, 13, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)((void *)0), A_col_size_mul_B_col_blk); exe(0x10, &AR[61][0], AR[60][0], 0, BR[60][2][1], 1, BR[60][0][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[61][1], AR[60][1], 0, BR[60][2][1], 1, BR[60][0][0], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[61][2], AR[60][2], 0, BR[60][2][1], 1, BR[60][1][1], 0, 0x00, 0LL, 0x00, 0LL); exe(0x10, &AR[61][3], AR[60][3], 0, BR[60][2][1], 1, BR[60][1][0], 0, 0x00, 0LL, 0x00, 0LL);
/-EMAX5AS-/
/-EMAX5AS-/
/-EMAX5AS-/ mop(0x01, 3, &BR[62][0][1], (Ull)c00[CHIP], (Ull)oofs, 12, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)((void *)0), B_col_size_mul_B_col_blk); mop(0x01, 3, &BR[62][1][1], (Ull)c01[CHIP], (Ull)oofs, 12, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)((void *)0), B_col_size_mul_B_col_blk); mop(0x01, 3, &BR[62][2][1], (Ull)c02[CHIP], (Ull)oofs, 12, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)((void *)0), B_col_size_mul_B_col_blk); mop(0x01, 3, &BR[62][3][1], (Ull)c03[CHIP], (Ull)oofs, 12, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)((void *)0), B_col_size_mul_B_col_blk); exe(0x12, &AR[62][0], AR[61][0], 0, BR[62][0][1], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x12, &AR[62][1], AR[61][1], 0, BR[62][1][1], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x12, &AR[62][2], AR[61][2], 0, BR[62][2][1], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); exe(0x12, &AR[62][3], AR[61][3], 0, BR[62][3][1], 0, 0LL, 0, 0x00, 0LL, 0x00, 0LL); mop(0x11, 3, &AR[62][0], (Ull)oofs, (Ull)c00[CHIP], 14, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)((void *)0), B_col_size_mul_B_col_blk); mop(0x11, 3, &AR[62][1], (Ull)oofs, (Ull)c01[CHIP], 14, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)((void *)0), B_col_size_mul_B_col_blk); mop(0x11, 3, &AR[62][2], (Ull)oofs, (Ull)c02[CHIP], 14, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)((void *)0), B_col_size_mul_B_col_blk); mop(0x11, 3, &AR[62][3], (Ull)oofs, (Ull)c03[CHIP], 14, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)((void *)0), B_col_size_mul_B_col_blk);
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AS-/ }
/-EMAX5AE-/
    }
  }
/-EMAX5AD-/
}
