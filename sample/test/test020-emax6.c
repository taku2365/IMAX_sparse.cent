static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/sample/mm_cnn_lf/RCS/mm.c,v 1.4 2018/02/04 10:28:53 nakashim Exp nakashim $";
typedef unsigned char Uchar;
typedef unsigned short Ushort;
typedef unsigned int Uint;
typedef unsigned long long Ull;
typedef long long int Sll;
typedef long double Dll;
typedef long unsigned int size_t;
typedef __builtin_va_list __gnuc_va_list;
typedef long int ptrdiff_t;
typedef unsigned int wchar_t;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short int __int16_t;
typedef short unsigned int __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long int __int64_t;
typedef long unsigned int __uint64_t;
typedef signed char __int_least8_t;
typedef unsigned char __uint_least8_t;
typedef short int __int_least16_t;
typedef short unsigned int __uint_least16_t;
typedef int __int_least32_t;
typedef unsigned int __uint_least32_t;
typedef long int __int_least64_t;
typedef long unsigned int __uint_least64_t;
typedef long int __intptr_t;
typedef long unsigned int __uintptr_t;
typedef long signed int _ssize_t;
typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
typedef long _off_t;
typedef short __dev_t;
typedef unsigned short __uid_t;
typedef unsigned short __gid_t;
__extension__ typedef long long _off64_t;
typedef long _fpos_t;
typedef unsigned int wint_t;
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;
typedef _LOCK_RECURSIVE_T _flock_t;
typedef void *_iconv_t;
typedef unsigned int __ULong;
struct _reent;
struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};
struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};
struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];
 __ULong _fntypes;
 __ULong _is_cxa;
};
struct _atexit {
 struct _atexit *_next;
 int _ind;
 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
struct __sbuf {
 unsigned char *_base;
 int _size;
};
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;
  void * _cookie;
  int (* _read) (struct _reent *, void *, char *, int);
  int (* _write) (struct _reent *, void *, const char *, int);
  _fpos_t (* _seek) (struct _reent *, void *, _fpos_t, int);
  int (* _close) (struct _reent *, void *);
  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;
  unsigned char _ubuf[3];
  unsigned char _nbuf[1];
  struct __sbuf _lb;
  int _blksize;
  _off_t _offset;
  struct _reent *_data;
  _flock_t _lock;
  _mbstate_t _mbstate;
  int _flags2;
};
typedef struct __sFILE __FILE;
struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;
};
struct _reent
{
  int _errno;
  __FILE *_stdin, *_stdout, *_stderr;
  int _inc;
  char _emergency[25];
  int _current_category;
  const char *_current_locale;
  int __sdidinit;
  void (* __cleanup) (struct _reent *);
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;
  int _cvtlen;
  char *_cvtbuf;
  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;
      struct
        {
          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;
  struct _atexit *_atexit;
  struct _atexit _atexit0;
  void (**(_sig_func))(int);
  struct _glue __sglue;
  __FILE __sf[3];
};
extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;
void _reclaim_reent (struct _reent *);
typedef long int __off_t;
typedef int __pid_t;
__extension__ typedef long long int __loff_t;
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long clock_t;
typedef long time_t;
struct timespec {
  time_t tv_sec;
  long tv_nsec;
};
struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};
typedef long daddr_t;
typedef char * caddr_t;
typedef unsigned short ino_t;
typedef _off_t off_t;
typedef __dev_t dev_t;
typedef __uid_t uid_t;
typedef __gid_t gid_t;
typedef int pid_t;
typedef long key_t;
typedef _ssize_t ssize_t;
typedef unsigned int mode_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned short nlink_t;
typedef long fd_mask;
typedef struct _types_fd_set {
 fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8))-1))/((sizeof (fd_mask) * 8)))];
} _types_fd_set;
typedef unsigned long clockid_t;
typedef unsigned long timer_t;
typedef unsigned long useconds_t;
typedef long suseconds_t;
typedef __FILE FILE;
typedef _fpos_t fpos_t;
FILE * tmpfile (void);
char * tmpnam (char *);
int fclose (FILE *);
int fflush (FILE *);
FILE * freopen (const char *__restrict, const char *__restrict, FILE *__restrict);
void setbuf (FILE *__restrict, char *__restrict);
int setvbuf (FILE *__restrict, char *__restrict, int, size_t);
int fprintf (FILE *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
int fscanf (FILE *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));
int printf (const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 1, 2)));
int scanf (const char *__restrict, ...) __attribute__ ((__format__ (__scanf__, 1, 2)));
int sscanf (const char *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));
int vfprintf (FILE *__restrict, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int vprintf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)));
int vsprintf (char *__restrict, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int fgetc (FILE *);
char * fgets (char *__restrict, int, FILE *__restrict);
int fputc (int, FILE *);
int fputs (const char *__restrict, FILE *__restrict);
int getc (FILE *);
int getchar (void);
char * gets (char *);
int putc (int, FILE *);
int putchar (int);
int puts (const char *);
int ungetc (int, FILE *);
size_t fread (void * __restrict, size_t _size, size_t _n, FILE *__restrict);
size_t fwrite (const void * __restrict , size_t _size, size_t _n, FILE *);
int fgetpos (FILE *__restrict, fpos_t *__restrict);
int fseek (FILE *, long, int);
int fsetpos (FILE *, const fpos_t *);
long ftell ( FILE *);
void rewind (FILE *);
void clearerr (FILE *);
int feof (FILE *);
int ferror (FILE *);
void perror (const char *);
FILE * fopen (const char *__restrict _name, const char *__restrict _type);
int sprintf (char *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
int remove (const char *);
int rename (const char *, const char *);
int fseeko (FILE *, off_t, int);
off_t ftello ( FILE *);
int asiprintf (char **, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
char * asniprintf (char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
char * asnprintf (char *__restrict, size_t *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int asprintf (char **__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
int diprintf (int, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
int fcloseall (void);
int fiprintf (FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
int fiscanf (FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));
int iprintf (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)));
int iscanf (const char *, ...) __attribute__ ((__format__ (__scanf__, 1, 2)));
int siprintf (char *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
int siscanf (const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));
int snprintf (char *__restrict, size_t, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int sniprintf (char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
char * tempnam (const char *, const char *);
int vasiprintf (char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
char * vasniprintf (char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
char * vasnprintf (char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int vasprintf (char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int vdiprintf (int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int vfiprintf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int vfiscanf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));
int vfscanf (FILE *__restrict, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));
int viprintf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)));
int viscanf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)));
int vscanf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)));
int vsiprintf (char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int vsiscanf (const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));
int vsniprintf (char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int vsnprintf (char *__restrict, size_t, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int vsscanf (const char *__restrict, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));
FILE * fdopen (int, const char *);
int fileno (FILE *);
int getw (FILE *);
int pclose (FILE *);
FILE * popen (const char *, const char *);
int putw (int, FILE *);
void setbuffer (FILE *, char *, int);
int setlinebuf (FILE *);
int getc_unlocked (FILE *);
int getchar_unlocked (void);
void flockfile (FILE *);
int ftrylockfile (FILE *);
void funlockfile (FILE *);
int putc_unlocked (int, FILE *);
int putchar_unlocked (int);
int dprintf (int, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
FILE * fmemopen (void *__restrict, size_t, const char *__restrict);
FILE * open_memstream (char **, size_t *);
int vdprintf (int, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int _asiprintf_r (struct _reent *, char **, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
char * _asniprintf_r (struct _reent *, char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)));
char * _asnprintf_r (struct _reent *, char *__restrict, size_t *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 4, 5)));
int _asprintf_r (struct _reent *, char **__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int _diprintf_r (struct _reent *, int, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int _dprintf_r (struct _reent *, int, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int _fclose_r (struct _reent *, FILE *);
int _fcloseall_r (struct _reent *);
FILE * _fdopen_r (struct _reent *, int, const char *);
int _fflush_r (struct _reent *, FILE *);
int _fgetc_r (struct _reent *, FILE *);
char * _fgets_r (struct _reent *, char *__restrict, int, FILE *__restrict);
int _fgetpos_r (struct _reent *, FILE *, fpos_t *);
int _fsetpos_r (struct _reent *, FILE *, const fpos_t *);
int _fiprintf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int _fiscanf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)));
FILE * _fmemopen_r (struct _reent *, void *__restrict, size_t, const char *__restrict);
FILE * _fopen_r (struct _reent *, const char *__restrict, const char *__restrict);
FILE * _freopen_r (struct _reent *, const char *__restrict, const char *__restrict, FILE *__restrict);
int _fprintf_r (struct _reent *, FILE *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int _fpurge_r (struct _reent *, FILE *);
int _fputc_r (struct _reent *, int, FILE *);
int _fputs_r (struct _reent *, const char *__restrict, FILE *__restrict);
size_t _fread_r (struct _reent *, void * __restrict, size_t _size, size_t _n, FILE *__restrict);
int _fscanf_r (struct _reent *, FILE *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__scanf__, 3, 4)));
int _fseek_r (struct _reent *, FILE *, long, int);
int _fseeko_r (struct _reent *, FILE *, _off_t, int);
long _ftell_r (struct _reent *, FILE *);
_off_t _ftello_r (struct _reent *, FILE *);
void _rewind_r (struct _reent *, FILE *);
size_t _fwrite_r (struct _reent *, const void * __restrict, size_t _size, size_t _n, FILE *__restrict);
int _getc_r (struct _reent *, FILE *);
int _getc_unlocked_r (struct _reent *, FILE *);
int _getchar_r (struct _reent *);
int _getchar_unlocked_r (struct _reent *);
char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
int _iscanf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));
FILE * _open_memstream_r (struct _reent *, char **, size_t *);
void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
int _putc_r (struct _reent *, int, FILE *);
int _putc_unlocked_r (struct _reent *, int, FILE *);
int _putchar_unlocked_r (struct _reent *, int);
int _putchar_r (struct _reent *, int);
int _puts_r (struct _reent *, const char *);
int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *, const char *_old, const char *_new);
int _scanf_r (struct _reent *, const char *__restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));
int _siprintf_r (struct _reent *, char *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int _siscanf_r (struct _reent *, const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)));
int _sniprintf_r (struct _reent *, char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)));
int _snprintf_r (struct _reent *, char *__restrict, size_t, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 4, 5)));
int _sprintf_r (struct _reent *, char *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));
int _sscanf_r (struct _reent *, const char *__restrict, const char *__restrict, ...) __attribute__ ((__format__ (__scanf__, 3, 4)));
char * _tempnam_r (struct _reent *, const char *, const char *);
FILE * _tmpfile_r (struct _reent *);
char * _tmpnam_r (struct _reent *, char *);
int _ungetc_r (struct _reent *, int, FILE *);
int _vasiprintf_r (struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
char * _vasniprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)));
char * _vasnprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)));
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int _vdiprintf_r (struct _reent *, int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int _vdprintf_r (struct _reent *, int, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfiprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfiscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)));
int _vfprintf_r (struct _reent *, FILE *__restrict, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfscanf_r (struct _reent *, FILE *__restrict, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)));
int _viprintf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int _viscanf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));
int _vprintf_r (struct _reent *, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));
int _vscanf_r (struct _reent *, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));
int _vsiprintf_r (struct _reent *, char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int _vsiscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)));
int _vsniprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)));
int _vsnprintf_r (struct _reent *, char *__restrict, size_t, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)));
int _vsprintf_r (struct _reent *, char *__restrict, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));
int _vsscanf_r (struct _reent *, const char *__restrict, const char *__restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)));
int fpurge (FILE *);
ssize_t __getdelim (char **, size_t *, int, FILE *);
ssize_t __getline (char **, size_t *, FILE *);
int __srget_r (struct _reent *, FILE *);
int __swbuf_r (struct _reent *, int, FILE *);
FILE *funopen (const void * __cookie, int (*__readfn)(void * __cookie, char *__buf, int __n), int (*__writefn)(void * __cookie, const char *__buf, int __n), fpos_t (*__seekfn)(void * __cookie, fpos_t __off, int __whence), int (*__closefn)(void * __cookie));
FILE *_funopen_r (struct _reent *, const void * __cookie, int (*__readfn)(void * __cookie, char *__buf, int __n), int (*__writefn)(void * __cookie, const char *__buf, int __n), fpos_t (*__seekfn)(void * __cookie, fpos_t __off, int __whence), int (*__closefn)(void * __cookie));
typedef ssize_t cookie_read_function_t(void *__cookie, char *__buf, size_t __n);
typedef ssize_t cookie_write_function_t(void *__cookie, const char *__buf,
     size_t __n);
typedef int cookie_seek_function_t(void *__cookie, off_t *__off, int __whence);
typedef int cookie_close_function_t(void *__cookie);
typedef struct
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
FILE *fopencookie (void *__cookie, const char *__mode, cookie_io_functions_t __functions);
FILE *_fopencookie_r (struct _reent *, void *__cookie, const char *__mode, cookie_io_functions_t __functions);
typedef struct
{
  int quot;
  int rem;
} div_t;
typedef struct
{
  long quot;
  long rem;
} ldiv_t;
typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;
typedef int (*__compar_fn_t) (const void *, const void *);
int __locale_mb_cur_max (void);
void abort (void) __attribute__ ((noreturn));
int abs (int);
int atexit (void (*__func)(void));
double atof (const char *__nptr);
float atoff (const char *__nptr);
int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void * __key, const void * __base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
void * calloc (size_t __nmemb, size_t __size) ;
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((noreturn));
void free (void *) ;
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);
char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);
extern char *suboptarg;
int getsubopt (char **, char * const *, char **);
long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void * malloc (size_t __size) ;
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *__restrict, const char *__restrict, size_t);
int _mbtowc_r (struct _reent *, wchar_t *__restrict, const char *__restrict, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *__restrict, const char *__restrict, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *__restrict, const char *__restrict, size_t, _mbstate_t *);
size_t wcstombs (char *__restrict, const wchar_t *__restrict, size_t);
size_t _wcstombs_r (struct _reent *, char *__restrict, const wchar_t *__restrict, size_t, _mbstate_t *);
char * mkdtemp (char *);
int mkostemp (char *, int);
int mkostemps (char *, int, int);
int mkstemp (char *);
int mkstemps (char *, int);
char * mktemp (char *) __attribute__ ((__warning__ ("the use of `mktemp' is dangerous; use `mkstemp' instead")));
char * _mkdtemp_r (struct _reent *, char *);
int _mkostemp_r (struct _reent *, char *, int);
int _mkostemps_r (struct _reent *, char *, int, int);
int _mkstemp_r (struct _reent *, char *);
int _mkstemps_r (struct _reent *, char *, int);
char * _mktemp_r (struct _reent *, char *) __attribute__ ((__warning__ ("the use of `mktemp' is dangerous; use `mkstemp' instead")));
void qsort (void * __base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
int rand (void);
void * realloc (void * __r, size_t __size) ;
void * reallocf (void * __r, size_t __size);
char * realpath (const char *__restrict path, char *__restrict resolved_path);
void srand (unsigned __seed);
double strtod (const char *__restrict __n, char **__restrict __end_PTR);
double _strtod_r (struct _reent *,const char *__restrict __n, char **__restrict __end_PTR);
float strtof (const char *__restrict __n, char **__restrict __end_PTR);
long strtol (const char *__restrict __n, char **__restrict __end_PTR, int __base);
long _strtol_r (struct _reent *,const char *__restrict __n, char **__restrict __end_PTR, int __base);
unsigned long strtoul (const char *__restrict __n, char **__restrict __end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *__restrict __n, char **__restrict __end_PTR, int __base);
int system (const char *__string);
long a64l (const char *__input);
char * l64a (long __input);
char * _l64a_r (struct _reent *,long __input);
int on_exit (void (*__func)(int, void *),void * __arg);
void _Exit (int __status) __attribute__ ((noreturn));
int putenv (char *__string);
int _putenv_r (struct _reent *, char *__string);
void * _reallocf_r (struct _reent *, void *, size_t);
int setenv (const char *__string, const char *__value, int __overwrite);
int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);
char * gcvt (double,int,char *);
char * gcvtf (float,int,char *);
char * fcvt (double,int,int *,int *);
char * fcvtf (float,int,int *,int *);
char * ecvt (double,int,int *,int *);
char * ecvtbuf (double, int, int*, int*, char *);
char * fcvtbuf (double, int, int*, int*, char *);
char * ecvtf (float,int,int *,int *);
char * dtoa (double, int, int, int *, int*, char**);
int rand_r (unsigned *__seed);
double drand48 (void);
double _drand48_r (struct _reent *);
double erand48 (unsigned short [3]);
double _erand48_r (struct _reent *, unsigned short [3]);
long jrand48 (unsigned short [3]);
long _jrand48_r (struct _reent *, unsigned short [3]);
void lcong48 (unsigned short [7]);
void _lcong48_r (struct _reent *, unsigned short [7]);
long lrand48 (void);
long _lrand48_r (struct _reent *);
long mrand48 (void);
long _mrand48_r (struct _reent *);
long nrand48 (unsigned short [3]);
long _nrand48_r (struct _reent *, unsigned short [3]);
unsigned short *
       seed48 (unsigned short [3]);
unsigned short *
       _seed48_r (struct _reent *, unsigned short [3]);
void srand48 (long);
void _srand48_r (struct _reent *, long);
long long atoll (const char *__nptr);
long long _atoll_r (struct _reent *, const char *__nptr);
long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);
long long strtoll (const char *__restrict __n, char **__restrict __end_PTR, int __base);
long long _strtoll_r (struct _reent *, const char *__restrict __n, char **__restrict __end_PTR, int __base);
unsigned long long strtoull (const char *__restrict __n, char **__restrict __end_PTR, int __base);
unsigned long long _strtoull_r (struct _reent *, const char *__restrict __n, char **__restrict __end_PTR, int __base);
void cfree (void *);
int unsetenv (const char *__string);
int _unsetenv_r (struct _reent *, const char *__string);
char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);
void * _malloc_r (struct _reent *, size_t) ;
void * _calloc_r (struct _reent *, size_t, size_t) ;
void _free_r (struct _reent *, void *) ;
void * _realloc_r (struct _reent *, void *, size_t) ;
void _mstats_r (struct _reent *, char *);
int _system_r (struct _reent *, const char *);
void __eprintf (const char *, const char *, unsigned int, const char *);
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};
clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);
char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);
size_t strftime (char *__restrict _s, size_t _maxsize, const char *__restrict _fmt, const struct tm *__restrict _t);
char *asctime_r (const struct tm *__restrict, char *__restrict);
char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *__restrict, struct tm *__restrict);
struct tm *localtime_r (const time_t *__restrict, struct tm *__restrict);
char *strptime (const char *__restrict, const char *__restrict, struct tm *__restrict);
void tzset (void);
void _tzset_r (struct _reent *);
typedef struct __tzrule_struct
{
  char ch;
  int m;
  int n;
  int d;
  int s;
  time_t change;
  long offset;
} __tzrule_type;
typedef struct __tzinfo_struct
{
  int __tznorth;
  int __tzyear;
  __tzrule_type __tzrule[2];
} __tzinfo_type;
__tzinfo_type *__gettzinfo (void);
extern long _timezone;
extern int _daylight;
extern char *_tzname[2];
struct flock {
 short l_type;
 short l_whence;
 long l_start;
 long l_len;
 short l_pid;
 short l_xxx;
};
struct eflock {
 short l_type;
 short l_whence;
 long l_start;
 long l_len;
 short l_pid;
 short l_xxx;
 long l_rpid;
 long l_rsys;
};
struct stat
{
  dev_t st_dev;
  ino_t st_ino;
  mode_t st_mode;
  nlink_t st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  dev_t st_rdev;
  off_t st_size;
  time_t st_atime;
  long st_spare1;
  time_t st_mtime;
  long st_spare2;
  time_t st_ctime;
  long st_spare3;
  long st_blksize;
  long st_blocks;
  long st_spare4[2];
};
int chmod ( const char *__path, mode_t __mode );
int fchmod (int __fd, mode_t __mode);
int fstat ( int __fd, struct stat *__sbuf );
int mkdir ( const char *_path, mode_t __mode );
int mkfifo ( const char *__path, mode_t __mode );
int stat ( const char *__restrict __path, struct stat *__restrict __sbuf );
mode_t umask ( mode_t __mask );
extern int open (const char *, int, ...);
extern int creat (const char *, mode_t);
extern int fcntl (int, int, ...);
union __dmath
{
  double d;
  __ULong i[2];
};
union __fmath
{
  float f;
  __ULong i[1];
};
union __ldmath
{
  long double ld;
  __ULong i[4];
};
extern double atan (double);
extern double cos (double);
extern double sin (double);
extern double tan (double);
extern double tanh (double);
extern double frexp (double, int *);
extern double modf (double, double *);
extern double ceil (double);
extern double fabs (double);
extern double floor (double);
extern double acos (double);
extern double asin (double);
extern double atan2 (double, double);
extern double cosh (double);
extern double sinh (double);
extern double exp (double);
extern double ldexp (double, int);
extern double log (double);
extern double log10 (double);
extern double pow (double, double);
extern double sqrt (double);
extern double fmod (double, double);
    typedef float float_t;
    typedef double double_t;
extern int __isinff (float x);
extern int __isinfd (double x);
extern int __isnanf (float x);
extern int __isnand (double x);
extern int __fpclassifyf (float x);
extern int __fpclassifyd (double x);
extern int __signbitf (float x);
extern int __signbitd (double x);
extern double infinity (void);
extern double nan (const char *);
extern int finite (double);
extern double copysign (double, double);
extern double logb (double);
extern int ilogb (double);
extern double asinh (double);
extern double cbrt (double);
extern double nextafter (double, double);
extern double rint (double);
extern double scalbn (double, int);
extern double exp2 (double);
extern double scalbln (double, long int);
extern double tgamma (double);
extern double nearbyint (double);
extern long int lrint (double);
extern long long int llrint (double);
extern double round (double);
extern long int lround (double);
extern long long int llround (double);
extern double trunc (double);
extern double remquo (double, double, int *);
extern double fdim (double, double);
extern double fmax (double, double);
extern double fmin (double, double);
extern double fma (double, double, double);
extern double log1p (double);
extern double expm1 (double);
extern double acosh (double);
extern double atanh (double);
extern double remainder (double, double);
extern double gamma (double);
extern double lgamma (double);
extern double erf (double);
extern double erfc (double);
extern double log2 (double);
extern double hypot (double, double);
extern float atanf (float);
extern float cosf (float);
extern float sinf (float);
extern float tanf (float);
extern float tanhf (float);
extern float frexpf (float, int *);
extern float modff (float, float *);
extern float ceilf (float);
extern float fabsf (float);
extern float floorf (float);
extern float acosf (float);
extern float asinf (float);
extern float atan2f (float, float);
extern float coshf (float);
extern float sinhf (float);
extern float expf (float);
extern float ldexpf (float, int);
extern float logf (float);
extern float log10f (float);
extern float powf (float, float);
extern float sqrtf (float);
extern float fmodf (float, float);
extern float exp2f (float);
extern float scalblnf (float, long int);
extern float tgammaf (float);
extern float nearbyintf (float);
extern long int lrintf (float);
extern long long llrintf (float);
extern float roundf (float);
extern long int lroundf (float);
extern long long int llroundf (float);
extern float truncf (float);
extern float remquof (float, float, int *);
extern float fdimf (float, float);
extern float fmaxf (float, float);
extern float fminf (float, float);
extern float fmaf (float, float, float);
extern float infinityf (void);
extern float nanf (const char *);
extern int finitef (float);
extern float copysignf (float, float);
extern float logbf (float);
extern int ilogbf (float);
extern float asinhf (float);
extern float cbrtf (float);
extern float nextafterf (float, float);
extern float rintf (float);
extern float scalbnf (float, int);
extern float log1pf (float);
extern float expm1f (float);
extern float acoshf (float);
extern float atanhf (float);
extern float remainderf (float, float);
extern float gammaf (float);
extern float lgammaf (float);
extern float erff (float);
extern float erfcf (float);
extern float log2f (float);
extern float hypotf (float, float);
extern double drem (double, double);
extern void sincos (double, double *, double *);
extern double gamma_r (double, int *);
extern double lgamma_r (double, int *);
extern double y0 (double);
extern double y1 (double);
extern double yn (int, double);
extern double j0 (double);
extern double j1 (double);
extern double jn (int, double);
extern float dremf (float, float);
extern void sincosf (float, float *, float *);
extern float gammaf_r (float, int *);
extern float lgammaf_r (float, int *);
extern float y0f (float);
extern float y1f (float);
extern float ynf (int, float);
extern float j0f (float);
extern float j1f (float);
extern float jnf (int, float);
extern double exp10 (double);
extern double pow10 (double);
extern float exp10f (float);
extern float pow10f (float);
extern int *__signgam (void);
struct exception
{
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
  int err;
};
extern int matherr (struct exception *e);
enum __fdlibm_version
{
  __fdlibm_ieee = -1,
  __fdlibm_svid,
  __fdlibm_xopen,
  __fdlibm_posix
};
extern enum __fdlibm_version __fdlib_version;
int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;
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
Ull nanosec_sav;
Ull nanosec[NANOS_CLASS];
reset_nanosec()
{
  int i;
  for (i=0; i<NANOS_CLASS; i++)
    nanosec[i] = 0;
  nanosec_sav = _getclk(0);
}
get_nanosec(int class)
{
  Ull nanosec_now;
  nanosec_now = _getclk(0);
  nanosec[class] += nanosec_now - nanosec_sav;
  nanosec[NANOS_TOTAL] += nanosec_now - nanosec_sav;
  nanosec_sav = nanosec_now;
}
show_nanosec()
{
  printf("SIML_cycle: ARM:%llu DRAIN:%llu CONF:%llu REGV:%llu RANGE:%llu LOAD:%llu EXEC:%llu total:%llu\n",
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
  emax_pre_with_keep_cache();
}
emax6_pre_with_drain_cache()
{
  emax_pre_with_drain_cache();
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
    offset1 = offset2&0x00000000ffffffffLL;
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
  if (adr < top || adr >= top+len*sizeof(Uint)+12) {
    printf("mmp: adr=%08.8x_%08.8x out of range (top=%08.8x_%08.8x len=%dB)\n", (Uint)(adr>>32), (Uint)adr, (Uint)(top>>32), (Uint)top, len*sizeof(Uint));
    fflush((_impure_ptr->_stdout));
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
Uchar* membase;
sysinit(memsize, alignment) Uint memsize, alignment;
{
  membase = (void*)malloc(memsize+alignment);
  if ((int)membase & (alignment-1))
    membase = (void*)(((int)membase & ~(alignment-1))+alignment);
  emax_info.dma_phys = 0x50000000;
  emax_info.dma_mmap = emax_info.dma_phys;
  emax_info.reg_phys = 0x50100000;
  emax_info.reg_mmap = emax_info.reg_phys;
  emax_info.lmm_phys = 0x60000000;
  emax_info.lmm_mmap = emax_info.lmm_phys;
  emax_info.ddr_phys = membase;
  emax_info.ddr_mmap = emax_info.ddr_phys;
  emax6.dma_ctrl = emax_info.dma_mmap;
  emax6.reg_ctrl = emax_info.reg_mmap;
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].cmd = CMD_RESET;
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].adtr = emax_info.ddr_mmap - emax_info.lmm_phys;
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = 0LL;
}
Uint *A;
Uint *B;
Uint *C0;
Uint *C1;
int row, col, n;
int top, blk;
int w, h;
int count0, count1, count2;
Uint Z[(320*240)];
main()
{
  sysinit((Uint)(480LL*480LL*sizeof(Uint)
                +480LL*480LL*sizeof(Uint)
                +480LL*480LL*sizeof(Uint)
                +480LL*480LL*sizeof(Uint)),32);
  printf("membase: %08.8x\n", (Uint)membase);
  A = (Uint*)membase;
  B = (Uint*)((Uchar*)A + 480LL*480LL*sizeof(Uint));
  C0 = (Uint*)((Uchar*)B + 480LL*480LL*sizeof(Uint));
  C1 = (Uint*)((Uchar*)C0 + 480LL*480LL*sizeof(Uint));
  printf("A : %08.8x\n", A);
  printf("B : %08.8x\n", B);
  printf("C0: %08.8x\n", C0);
  printf("C1: %08.8x\n", C1);
  for (row=0; row<480LL; row++) {
    for (col=0; col<480LL; col++)
      *(float*)&A[row*480LL +col] = row%120+1;
  }
  for (row=0; row<480LL; row++) {
    for (col=0; col<480LL; col++)
      *(float*)&B[row*480LL +col] = col%120+1;
  }
  reset_nanosec();
  orig();
  get_nanosec(0);
  show_nanosec();
  reset_nanosec();
  imax();
  get_nanosec(0);
  show_nanosec();
  copy_Z(0, C1); _copyX(0, Z);
  copy_Z(1, C1); _copyX(1, Z);
  copy_Z(4, C1); _copyX(4, Z);
  copy_Z(5, C1); _copyX(5, Z);
  copy_Z(8, C1); _copyX(8, Z);
  copy_Z(9, C1); _copyX(9, Z);
  _updateX();
  printf("Num of MULT: orig=%d imax=%d\n", count0, count1);
  for (row=0; row<480LL; row++) {
    for (col=0; col<480LL; col++) {
      if (C0[row*480LL +col] != C1[row*480LL +col]) {
        count2++;
        printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row, col, (double)*(float*)&C0[row*480LL +col],
                                                row, col, (double)*(float*)&C1[row*480LL +col]);
      }
    }
  }
  if (count2)
    printf("Num of diffs: %d\n", count2);
  else
    printf("Results are equal\n");
  show_nanosec();
}
copy_Z(id, from)
     int id;
     unsigned int *from;
{
  int i, j;
  volatile unsigned int *to = Z;
  unsigned int *offs;
  switch (id) {
  case 0: offs = from; break;
  case 1: offs = from + WD; break;
  case 2: offs = from + WD*2; break;
  case 3: offs = from + WD*3; break;
  case 4: offs = from + 480LL*HT; break;
  case 5: offs = from + 480LL*HT+WD; break;
  case 6: offs = from + 480LL*HT+WD*2; break;
  case 7: offs = from + 480LL*HT+WD*3; break;
  case 8: offs = from + 480LL*HT*2; break;
  case 9: offs = from + 480LL*HT*2+WD; break;
  case 10: offs = from + 480LL*HT*2+WD*2; break;
  case 11: offs = from + 480LL*HT*2+WD*3; break;
  case 12: offs = from + 480LL*HT*3; break;
  case 13: offs = from + 480LL*HT*3+WD; break;
  case 14: offs = from + 480LL*HT*3+WD*2; break;
  case 15: offs = from + 480LL*HT*3+WD*3; break;
  }
  for (i=0; i<HT; i++, offs+=480LL) {
    if (offs<from+480LL*480LL) {
      for (j=0; j<WD; j++) {
 if (j+(id%4)*WD<480LL) *to++ = (*(offs+j))>>0;
 else *to++ = 0;
      }
    }
    else {
      for (j=0; j<WD; j++)
 *to++ = 0;
    }
  }
}
orig() {
  printf("<<<ORIG>>>\n");
  for (row=0; row<480LL; row++) {
    for (col=0; col<480LL; col++) {
      for (n=0; n<480LL; n++) {
        if (n==0) *(float*)&C0[row*480LL +col] = *(float*)&A[row*480LL +n] * *(float*)&B[n*480LL +col];
        else *(float*)&C0[row*480LL +col] += *(float*)&A[row*480LL +n] * *(float*)&B[n*480LL +col];
        count0++;
      }
    }
  }
}
imax() {
  Ull CHIP;
  Ull LOOP1, LOOP0;
  Ull INIT1, INIT0;
  Ull AR[64][4];
  Ull BR[64][4][4];
  Ull r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull cc0, cc1, cc2, cc3, ex0, ex1;
  Ull cofs, rofs, oofs, k;
  printf("<<<IMAX>>>\n");
  for (top=0; top<480LL/4; top+=15) {
    for (blk=0; blk<480LL; blk+=60) {
      typedef struct {Uint i[8]} Ui8;
      Uint *a0[4];
      Uint *a[60][4];
      Ui8 *b[60], *b0[60], *b1[60], *b2[60], *b3[60];
      Ui8 *c0[4];
      Ui8 *c00[4], *c01[4], *c02[4], *c03[4];
      for (k=0; k<60; k++) {
 b[k] = B+(blk+k)*480LL; b0[k] = b[k]; b1[k] = (Uint*)b[k]+2; b2[k] = (Uint*)b[k]+4; b3[k] = (Uint*)b[k]+6;
      }
      for (CHIP=0; CHIP<4; CHIP++) {
 a0[CHIP] = A+(CHIP*480LL/4 +top)*480LL;
 for (k=0; k<60; k++)
   a[k][CHIP] = a0[CHIP]+blk+k;
 c0[CHIP] = C1+(CHIP*480LL/4 +top)*480LL;
 c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP]= (Uint*)c0[CHIP]+2; c02[CHIP]= (Uint*)c0[CHIP]+4; c03[CHIP]= (Uint*)c0[CHIP]+6;
      }
volatile emax6_conf_mm();
	  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].mcid = 3; // NCHIP-1
	LOOP1 = ((15));
	rofs = (((0-480LL*4)<<32|((0-480LL*4)&0xffffffff)));
	LOOP0 = ((480LL/4LL/2));
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
	emax6.lmmio = emax6.lmmic;
	emax6.lmmic = 1-emax6.lmmic;
	emax6.mapdist = 0;
	emax6.lastdist = 0;
	*(Uint*)&emax6.lmmi[0][1][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][1][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][1][0][emax6.lmmic].top = b[0];
	*(Uint*)&emax6.lmmi[0][2][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][2][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][2][0][emax6.lmmic].top = b[1];
	*(Uint*)&emax6.lmmi[0][3][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][3][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][3][0][emax6.lmmic].top = b[2];
	*(Uint*)&emax6.lmmi[0][4][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][4][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][4][0][emax6.lmmic].top = b[3];
	*(Uint*)&emax6.lmmi[0][5][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][5][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][5][0][emax6.lmmic].top = b[4];
	*(Uint*)&emax6.lmmi[0][6][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][6][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][6][0][emax6.lmmic].top = b[5];
	*(Uint*)&emax6.lmmi[0][7][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][7][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][7][0][emax6.lmmic].top = b[6];
	*(Uint*)&emax6.lmmi[0][8][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][8][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][8][0][emax6.lmmic].top = b[7];
	*(Uint*)&emax6.lmmi[0][9][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][9][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][9][0][emax6.lmmic].top = b[8];
	*(Uint*)&emax6.lmmi[0][10][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][10][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][10][0][emax6.lmmic].top = b[9];
	*(Uint*)&emax6.lmmi[0][11][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][11][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][11][0][emax6.lmmic].top = b[10];
	*(Uint*)&emax6.lmmi[0][12][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][12][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][12][0][emax6.lmmic].top = b[11];
	*(Uint*)&emax6.lmmi[0][13][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][13][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][13][0][emax6.lmmic].top = b[12];
	*(Uint*)&emax6.lmmi[0][14][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][14][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][14][0][emax6.lmmic].top = b[13];
	*(Uint*)&emax6.lmmi[0][15][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][15][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][15][0][emax6.lmmic].top = b[14];
	*(Uint*)&emax6.lmmi[0][16][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][16][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][16][0][emax6.lmmic].top = b[15];
	*(Uint*)&emax6.lmmi[0][17][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][17][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][17][0][emax6.lmmic].top = b[16];
	*(Uint*)&emax6.lmmi[0][18][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][18][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][18][0][emax6.lmmic].top = b[17];
	*(Uint*)&emax6.lmmi[0][19][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][19][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][19][0][emax6.lmmic].top = b[18];
	*(Uint*)&emax6.lmmi[0][20][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][20][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][20][0][emax6.lmmic].top = b[19];
	*(Uint*)&emax6.lmmi[0][21][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][21][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][21][0][emax6.lmmic].top = b[20];
	*(Uint*)&emax6.lmmi[0][22][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][22][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][22][0][emax6.lmmic].top = b[21];
	*(Uint*)&emax6.lmmi[0][23][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][23][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][23][0][emax6.lmmic].top = b[22];
	*(Uint*)&emax6.lmmi[0][24][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][24][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][24][0][emax6.lmmic].top = b[23];
	*(Uint*)&emax6.lmmi[0][25][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][25][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][25][0][emax6.lmmic].top = b[24];
	*(Uint*)&emax6.lmmi[0][26][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][26][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][26][0][emax6.lmmic].top = b[25];
	*(Uint*)&emax6.lmmi[0][27][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][27][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][27][0][emax6.lmmic].top = b[26];
	*(Uint*)&emax6.lmmi[0][28][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][28][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][28][0][emax6.lmmic].top = b[27];
	*(Uint*)&emax6.lmmi[0][29][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][29][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][29][0][emax6.lmmic].top = b[28];
	*(Uint*)&emax6.lmmi[0][30][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][30][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][30][0][emax6.lmmic].top = b[29];
	*(Uint*)&emax6.lmmi[0][31][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][31][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][31][0][emax6.lmmic].top = b[30];
	*(Uint*)&emax6.lmmi[0][32][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][32][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][32][0][emax6.lmmic].top = b[31];
	*(Uint*)&emax6.lmmi[0][33][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][33][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][33][0][emax6.lmmic].top = b[32];
	*(Uint*)&emax6.lmmi[0][34][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][34][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][34][0][emax6.lmmic].top = b[33];
	*(Uint*)&emax6.lmmi[0][35][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][35][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][35][0][emax6.lmmic].top = b[34];
	*(Uint*)&emax6.lmmi[0][36][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][36][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][36][0][emax6.lmmic].top = b[35];
	*(Uint*)&emax6.lmmi[0][37][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][37][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][37][0][emax6.lmmic].top = b[36];
	*(Uint*)&emax6.lmmi[0][38][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][38][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][38][0][emax6.lmmic].top = b[37];
	*(Uint*)&emax6.lmmi[0][39][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][39][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][39][0][emax6.lmmic].top = b[38];
	*(Uint*)&emax6.lmmi[0][40][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][40][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][40][0][emax6.lmmic].top = b[39];
	*(Uint*)&emax6.lmmi[0][41][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][41][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][41][0][emax6.lmmic].top = b[40];
	*(Uint*)&emax6.lmmi[0][42][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][42][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][42][0][emax6.lmmic].top = b[41];
	*(Uint*)&emax6.lmmi[0][43][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][43][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][43][0][emax6.lmmic].top = b[42];
	*(Uint*)&emax6.lmmi[0][44][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][44][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][44][0][emax6.lmmic].top = b[43];
	*(Uint*)&emax6.lmmi[0][45][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][45][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][45][0][emax6.lmmic].top = b[44];
	*(Uint*)&emax6.lmmi[0][46][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][46][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][46][0][emax6.lmmic].top = b[45];
	*(Uint*)&emax6.lmmi[0][47][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][47][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][47][0][emax6.lmmic].top = b[46];
	*(Uint*)&emax6.lmmi[0][48][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][48][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][48][0][emax6.lmmic].top = b[47];
	*(Uint*)&emax6.lmmi[0][49][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][49][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][49][0][emax6.lmmic].top = b[48];
	*(Uint*)&emax6.lmmi[0][50][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][50][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][50][0][emax6.lmmic].top = b[49];
	*(Uint*)&emax6.lmmi[0][51][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][51][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][51][0][emax6.lmmic].top = b[50];
	*(Uint*)&emax6.lmmi[0][52][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][52][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][52][0][emax6.lmmic].top = b[51];
	*(Uint*)&emax6.lmmi[0][53][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][53][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][53][0][emax6.lmmic].top = b[52];
	*(Uint*)&emax6.lmmi[0][54][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][54][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][54][0][emax6.lmmic].top = b[53];
	*(Uint*)&emax6.lmmi[0][55][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][55][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][55][0][emax6.lmmic].top = b[54];
	*(Uint*)&emax6.lmmi[0][56][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][56][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][56][0][emax6.lmmic].top = b[55];
	*(Uint*)&emax6.lmmi[0][57][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][57][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][57][0][emax6.lmmic].top = b[56];
	*(Uint*)&emax6.lmmi[0][58][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][58][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][58][0][emax6.lmmic].top = b[57];
	*(Uint*)&emax6.lmmi[0][59][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][59][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][59][0][emax6.lmmic].top = b[58];
	*(Uint*)&emax6.lmmi[0][60][0][emax6.lmmic] = 0x01df0021|(0<<2);
	emax6.lmmi[0][60][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][60][0][emax6.lmmic].top = b[59];
	*(Uint*)&emax6.lmmi[0][60][2][emax6.lmmic] = 0x1c1f1001|(0<<2);
	emax6.lmmi[0][60][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][60][2][emax6.lmmic].top = a0[0];
	*(Uint*)&emax6.lmmi[1][60][2][emax6.lmmic] = 0x1c1f1001|(0<<2);
	emax6.lmmi[1][60][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[1][60][2][emax6.lmmic].top = a0[1];
	*(Uint*)&emax6.lmmi[2][60][2][emax6.lmmic] = 0x1c1f1001|(0<<2);
	emax6.lmmi[2][60][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[2][60][2][emax6.lmmic].top = a0[2];
	*(Uint*)&emax6.lmmi[3][60][2][emax6.lmmic] = 0x1c1f1001|(0<<2);
	emax6.lmmi[3][60][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[3][60][2][emax6.lmmic].top = a0[3];
	*(Uint*)&emax6.lmmi[0][62][0][emax6.lmmic] = 0x1c1f10e7|(1<<2);
	emax6.lmmi[0][62][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][62][0][emax6.lmmic].top = c0[0];
	*(Uint*)&emax6.lmmi[1][62][0][emax6.lmmic] = 0x1c1f10e7|(1<<2);
	emax6.lmmi[1][62][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[1][62][0][emax6.lmmic].top = c0[1];
	*(Uint*)&emax6.lmmi[2][62][0][emax6.lmmic] = 0x1c1f10e7|(1<<2);
	emax6.lmmi[2][62][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[2][62][0][emax6.lmmic].top = c0[2];
	*(Uint*)&emax6.lmmi[3][62][0][emax6.lmmic] = 0x1c1f10e7|(1<<2);
	emax6.lmmi[3][62][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[3][62][0][emax6.lmmic].top = c0[3];
	emax6.lmmi_bitmap[0] = 0x5ffffffffffffffeLL;
	emax6.lmmi_bitmap[1] = 0x0000000000000000LL;
	emax6.lmmi_bitmap[2] = 0x1000000000000000LL;
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
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[0] = (((4LL)*(8))<<(32))|((4LL)*(8));
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[1] = rofs;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[2] = (((480LL)*(4))<<(32))|((480LL)*(4));
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][0].ea0b = b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][0].ea1b = b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][1].ea0b = b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][1].ea1b = b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][2].ea1b = a[0][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[1][2].ea1b = a[0][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[1][2].ea1b = a[0][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[1][2].ea1b = a[0][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][0].ea0b = b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][0].ea1b = b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][1].ea0b = b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][1].ea1b = b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][2].ea1b = a[1][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[2][2].ea1b = a[1][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[2][2].ea1b = a[1][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[2][2].ea1b = a[1][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][0].ea0b = b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][0].ea1b = b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][1].ea0b = b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][1].ea1b = b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][2].ea1b = a[2][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[3][2].ea1b = a[2][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[3][2].ea1b = a[2][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[3][2].ea1b = a[2][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][0].ea0b = b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][0].ea1b = b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][1].ea0b = b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][1].ea1b = b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][2].ea1b = a[3][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[4][2].ea1b = a[3][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[4][2].ea1b = a[3][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[4][2].ea1b = a[3][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][0].ea0b = b1[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][0].ea1b = b0[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][1].ea0b = b3[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][1].ea1b = b2[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][2].ea1b = a[4][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[5][2].ea1b = a[4][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[5][2].ea1b = a[4][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[5][2].ea1b = a[4][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][0].ea0b = b1[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][0].ea1b = b0[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][1].ea0b = b3[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][1].ea1b = b2[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][2].ea1b = a[5][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[6][2].ea1b = a[5][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[6][2].ea1b = a[5][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[6][2].ea1b = a[5][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][0].ea0b = b1[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][0].ea1b = b0[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][1].ea0b = b3[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][1].ea1b = b2[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][2].ea1b = a[6][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[7][2].ea1b = a[6][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[7][2].ea1b = a[6][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[7][2].ea1b = a[6][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][0].ea0b = b1[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][0].ea1b = b0[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][1].ea0b = b3[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][1].ea1b = b2[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][2].ea1b = a[7][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[8][2].ea1b = a[7][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[8][2].ea1b = a[7][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[8][2].ea1b = a[7][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][0].ea0b = b1[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][0].ea1b = b0[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][1].ea0b = b3[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][1].ea1b = b2[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][2].ea1b = a[8][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[9][2].ea1b = a[8][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[9][2].ea1b = a[8][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[9][2].ea1b = a[8][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][0].ea0b = b1[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][0].ea1b = b0[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][1].ea0b = b3[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][1].ea1b = b2[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][2].ea1b = a[9][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[10][2].ea1b = a[9][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[10][2].ea1b = a[9][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[10][2].ea1b = a[9][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][0].ea0b = b1[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][0].ea1b = b0[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][1].ea0b = b3[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][1].ea1b = b2[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][2].ea1b = a[10][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[11][2].ea1b = a[10][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[11][2].ea1b = a[10][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[11][2].ea1b = a[10][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][0].ea0b = b1[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][0].ea1b = b0[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][1].ea0b = b3[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][1].ea1b = b2[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][2].ea1b = a[11][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[12][2].ea1b = a[11][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[12][2].ea1b = a[11][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[12][2].ea1b = a[11][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][0].ea0b = b1[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][0].ea1b = b0[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][1].ea0b = b3[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][1].ea1b = b2[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][2].ea1b = a[12][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[13][2].ea1b = a[12][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[13][2].ea1b = a[12][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[13][2].ea1b = a[12][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][0].ea0b = b1[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][0].ea1b = b0[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][1].ea0b = b3[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][1].ea1b = b2[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][2].ea1b = a[13][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[14][2].ea1b = a[13][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[14][2].ea1b = a[13][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[14][2].ea1b = a[13][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][0].ea0b = b1[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][0].ea1b = b0[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][1].ea0b = b3[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][1].ea1b = b2[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][2].ea1b = a[14][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[15][2].ea1b = a[14][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[15][2].ea1b = a[14][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[15][2].ea1b = a[14][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][0].ea0b = b1[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][0].ea1b = b0[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][1].ea0b = b3[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][1].ea1b = b2[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][2].ea1b = a[15][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[16][2].ea1b = a[15][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[16][2].ea1b = a[15][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[16][2].ea1b = a[15][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][0].ea0b = b1[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][0].ea1b = b0[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][1].ea0b = b3[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][1].ea1b = b2[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][2].ea1b = a[16][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[17][2].ea1b = a[16][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[17][2].ea1b = a[16][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[17][2].ea1b = a[16][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][0].ea0b = b1[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][0].ea1b = b0[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][1].ea0b = b3[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][1].ea1b = b2[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][2].ea1b = a[17][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[18][2].ea1b = a[17][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[18][2].ea1b = a[17][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[18][2].ea1b = a[17][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][0].ea0b = b1[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][0].ea1b = b0[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][1].ea0b = b3[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][1].ea1b = b2[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][2].ea1b = a[18][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[19][2].ea1b = a[18][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[19][2].ea1b = a[18][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[19][2].ea1b = a[18][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][0].ea0b = b1[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][0].ea1b = b0[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][1].ea0b = b3[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][1].ea1b = b2[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][2].ea1b = a[19][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[20][2].ea1b = a[19][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[20][2].ea1b = a[19][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[20][2].ea1b = a[19][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][0].ea0b = b1[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][0].ea1b = b0[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][1].ea0b = b3[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][1].ea1b = b2[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][2].ea1b = a[20][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[21][2].ea1b = a[20][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[21][2].ea1b = a[20][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[21][2].ea1b = a[20][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][0].ea0b = b1[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][0].ea1b = b0[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][1].ea0b = b3[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][1].ea1b = b2[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][2].ea1b = a[21][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[22][2].ea1b = a[21][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[22][2].ea1b = a[21][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[22][2].ea1b = a[21][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][0].ea0b = b1[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][0].ea1b = b0[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][1].ea0b = b3[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][1].ea1b = b2[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][2].ea1b = a[22][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[23][2].ea1b = a[22][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[23][2].ea1b = a[22][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[23][2].ea1b = a[22][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][0].ea0b = b1[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][0].ea1b = b0[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][1].ea0b = b3[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][1].ea1b = b2[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][2].ea1b = a[23][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[24][2].ea1b = a[23][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[24][2].ea1b = a[23][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[24][2].ea1b = a[23][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][0].ea0b = b1[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][0].ea1b = b0[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][1].ea0b = b3[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][1].ea1b = b2[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][2].ea1b = a[24][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[25][2].ea1b = a[24][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[25][2].ea1b = a[24][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[25][2].ea1b = a[24][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][0].ea0b = b1[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][0].ea1b = b0[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][1].ea0b = b3[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][1].ea1b = b2[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][2].ea1b = a[25][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[26][2].ea1b = a[25][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[26][2].ea1b = a[25][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[26][2].ea1b = a[25][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][0].ea0b = b1[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][0].ea1b = b0[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][1].ea0b = b3[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][1].ea1b = b2[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][2].ea1b = a[26][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[27][2].ea1b = a[26][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[27][2].ea1b = a[26][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[27][2].ea1b = a[26][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][0].ea0b = b1[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][0].ea1b = b0[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][1].ea0b = b3[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][1].ea1b = b2[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][2].ea1b = a[27][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[28][2].ea1b = a[27][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[28][2].ea1b = a[27][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[28][2].ea1b = a[27][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][0].ea0b = b1[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][0].ea1b = b0[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][1].ea0b = b3[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][1].ea1b = b2[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][2].ea1b = a[28][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[29][2].ea1b = a[28][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[29][2].ea1b = a[28][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[29][2].ea1b = a[28][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][0].ea0b = b1[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][0].ea1b = b0[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][1].ea0b = b3[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][1].ea1b = b2[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][2].ea1b = a[29][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[30][2].ea1b = a[29][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[30][2].ea1b = a[29][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[30][2].ea1b = a[29][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][0].ea0b = b1[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][0].ea1b = b0[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][1].ea0b = b3[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][1].ea1b = b2[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][2].ea1b = a[30][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[31][2].ea1b = a[30][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[31][2].ea1b = a[30][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[31][2].ea1b = a[30][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][0].ea0b = b1[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][0].ea1b = b0[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][1].ea0b = b3[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][1].ea1b = b2[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][2].ea1b = a[31][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[32][2].ea1b = a[31][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[32][2].ea1b = a[31][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[32][2].ea1b = a[31][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][0].ea0b = b1[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][0].ea1b = b0[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][1].ea0b = b3[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][1].ea1b = b2[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][2].ea1b = a[32][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[33][2].ea1b = a[32][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[33][2].ea1b = a[32][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[33][2].ea1b = a[32][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][0].ea0b = b1[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][0].ea1b = b0[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][1].ea0b = b3[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][1].ea1b = b2[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][2].ea1b = a[33][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[34][2].ea1b = a[33][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[34][2].ea1b = a[33][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[34][2].ea1b = a[33][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][0].ea0b = b1[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][0].ea1b = b0[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][1].ea0b = b3[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][1].ea1b = b2[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][2].ea1b = a[34][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[35][2].ea1b = a[34][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[35][2].ea1b = a[34][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[35][2].ea1b = a[34][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][0].ea0b = b1[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][0].ea1b = b0[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][1].ea0b = b3[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][1].ea1b = b2[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][2].ea1b = a[35][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[36][2].ea1b = a[35][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[36][2].ea1b = a[35][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[36][2].ea1b = a[35][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][0].ea0b = b1[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][0].ea1b = b0[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][1].ea0b = b3[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][1].ea1b = b2[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][2].ea1b = a[36][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[37][2].ea1b = a[36][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[37][2].ea1b = a[36][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[37][2].ea1b = a[36][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][0].ea0b = b1[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][0].ea1b = b0[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][1].ea0b = b3[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][1].ea1b = b2[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][2].ea1b = a[37][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[38][2].ea1b = a[37][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[38][2].ea1b = a[37][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[38][2].ea1b = a[37][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][0].ea0b = b1[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][0].ea1b = b0[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][1].ea0b = b3[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][1].ea1b = b2[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][2].ea1b = a[38][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[39][2].ea1b = a[38][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[39][2].ea1b = a[38][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[39][2].ea1b = a[38][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][0].ea0b = b1[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][0].ea1b = b0[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][1].ea0b = b3[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][1].ea1b = b2[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][2].ea1b = a[39][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[40][2].ea1b = a[39][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[40][2].ea1b = a[39][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[40][2].ea1b = a[39][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][0].ea0b = b1[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][0].ea1b = b0[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][1].ea0b = b3[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][1].ea1b = b2[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][2].ea1b = a[40][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[41][2].ea1b = a[40][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[41][2].ea1b = a[40][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[41][2].ea1b = a[40][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][0].ea0b = b1[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][0].ea1b = b0[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][1].ea0b = b3[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][1].ea1b = b2[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][2].ea1b = a[41][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[42][2].ea1b = a[41][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[42][2].ea1b = a[41][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[42][2].ea1b = a[41][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][0].ea0b = b1[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][0].ea1b = b0[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][1].ea0b = b3[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][1].ea1b = b2[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][2].ea1b = a[42][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[43][2].ea1b = a[42][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[43][2].ea1b = a[42][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[43][2].ea1b = a[42][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][0].ea0b = b1[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][0].ea1b = b0[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][1].ea0b = b3[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][1].ea1b = b2[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][2].ea1b = a[43][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[44][2].ea1b = a[43][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[44][2].ea1b = a[43][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[44][2].ea1b = a[43][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][0].ea0b = b1[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][0].ea1b = b0[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][1].ea0b = b3[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][1].ea1b = b2[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][2].ea1b = a[44][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[45][2].ea1b = a[44][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[45][2].ea1b = a[44][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[45][2].ea1b = a[44][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][0].ea0b = b1[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][0].ea1b = b0[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][1].ea0b = b3[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][1].ea1b = b2[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][2].ea1b = a[45][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[46][2].ea1b = a[45][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[46][2].ea1b = a[45][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[46][2].ea1b = a[45][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][0].ea0b = b1[46];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][0].ea1b = b0[46];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][1].ea0b = b3[46];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][1].ea1b = b2[46];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[47][2].ea1b = a[46][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[47][2].ea1b = a[46][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[47][2].ea1b = a[46][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[47][2].ea1b = a[46][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][0].ea0b = b1[47];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][0].ea1b = b0[47];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][1].ea0b = b3[47];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][1].ea1b = b2[47];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][2].ea1b = a[47][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][2].ea1b = a[47][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][2].ea1b = a[47][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][2].ea1b = a[47][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][0].ea0b = b1[48];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][0].ea1b = b0[48];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][1].ea0b = b3[48];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][1].ea1b = b2[48];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[49][2].ea1b = a[48][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[49][2].ea1b = a[48][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[49][2].ea1b = a[48][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[49][2].ea1b = a[48][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][0].ea0b = b1[49];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][0].ea1b = b0[49];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][1].ea0b = b3[49];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][1].ea1b = b2[49];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[50][2].ea1b = a[49][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[50][2].ea1b = a[49][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[50][2].ea1b = a[49][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[50][2].ea1b = a[49][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][0].ea0b = b1[50];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][0].ea1b = b0[50];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][1].ea0b = b3[50];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][1].ea1b = b2[50];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[51][2].ea1b = a[50][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[51][2].ea1b = a[50][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[51][2].ea1b = a[50][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[51][2].ea1b = a[50][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[52][0].ea0b = b1[51];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[52][0].ea1b = b0[51];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[52][1].ea0b = b3[51];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[52][1].ea1b = b2[51];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[52][2].ea1b = a[51][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[52][2].ea1b = a[51][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[52][2].ea1b = a[51][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[52][2].ea1b = a[51][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][0].ea0b = b1[52];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][0].ea1b = b0[52];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][1].ea0b = b3[52];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][1].ea1b = b2[52];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[53][2].ea1b = a[52][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[53][2].ea1b = a[52][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[53][2].ea1b = a[52][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[53][2].ea1b = a[52][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][0].ea0b = b1[53];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][0].ea1b = b0[53];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][1].ea0b = b3[53];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][1].ea1b = b2[53];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[54][2].ea1b = a[53][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[54][2].ea1b = a[53][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[54][2].ea1b = a[53][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[54][2].ea1b = a[53][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][0].ea0b = b1[54];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][0].ea1b = b0[54];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][1].ea0b = b3[54];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][1].ea1b = b2[54];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[55][2].ea1b = a[54][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[55][2].ea1b = a[54][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[55][2].ea1b = a[54][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[55][2].ea1b = a[54][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][0].ea0b = b1[55];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][0].ea1b = b0[55];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][1].ea0b = b3[55];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][1].ea1b = b2[55];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[56][2].ea1b = a[55][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[56][2].ea1b = a[55][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[56][2].ea1b = a[55][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[56][2].ea1b = a[55][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][0].ea0b = b1[56];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][0].ea1b = b0[56];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][1].ea0b = b3[56];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][1].ea1b = b2[56];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[57][2].ea1b = a[56][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[57][2].ea1b = a[56][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[57][2].ea1b = a[56][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[57][2].ea1b = a[56][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][0].ea0b = b1[57];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][0].ea1b = b0[57];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][1].ea0b = b3[57];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][1].ea1b = b2[57];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[58][2].ea1b = a[57][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[58][2].ea1b = a[57][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[58][2].ea1b = a[57][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[58][2].ea1b = a[57][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[59][0].ea0b = b1[58];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[59][0].ea1b = b0[58];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[59][1].ea0b = b3[58];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[59][1].ea1b = b2[58];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[59][2].ea1b = a[58][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[59][2].ea1b = a[58][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[59][2].ea1b = a[58][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[59][2].ea1b = a[58][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[60][0].ea0b = b1[59];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[60][0].ea1b = b0[59];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[60][1].ea0b = b3[59];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[60][1].ea1b = b2[59];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[60][2].ea1b = a[59][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[60][2].ea1b = a[59][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[60][2].ea1b = a[59][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[60][2].ea1b = a[59][3];
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
	*(Ull*)&(reg_ctrl->i[0].addr[1][0].top) = ((Ull)(emax6.lmmi[0][1][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][1][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][1][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[1][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[1][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[1][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[1][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[2][0].top) = ((Ull)(emax6.lmmi[0][2][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][2][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][2][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[2][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[2][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[2][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[2][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[3][0].top) = ((Ull)(emax6.lmmi[0][3][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][3][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][3][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[3][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[3][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[3][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[3][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[4][0].top) = ((Ull)(emax6.lmmi[0][4][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][4][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][4][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[4][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[4][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[4][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[4][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[5][0].top) = ((Ull)(emax6.lmmi[0][5][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][5][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][5][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[5][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[5][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[5][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[5][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[6][0].top) = ((Ull)(emax6.lmmi[0][6][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][6][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][6][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[6][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[6][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[6][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[6][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[7][0].top) = ((Ull)(emax6.lmmi[0][7][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][7][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][7][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[7][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[7][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[7][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[7][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[8][0].top) = ((Ull)(emax6.lmmi[0][8][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][8][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][8][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[8][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[8][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[8][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[8][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[9][0].top) = ((Ull)(emax6.lmmi[0][9][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][9][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][9][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[9][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[9][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[9][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[9][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[10][0].top) = ((Ull)(emax6.lmmi[0][10][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][10][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][10][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[10][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[10][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[10][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[10][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[11][0].top) = ((Ull)(emax6.lmmi[0][11][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][11][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][11][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[11][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[11][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[11][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[11][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[12][0].top) = ((Ull)(emax6.lmmi[0][12][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][12][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][12][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[12][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[12][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[12][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[12][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[13][0].top) = ((Ull)(emax6.lmmi[0][13][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][13][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][13][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[13][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[13][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[13][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[13][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[14][0].top) = ((Ull)(emax6.lmmi[0][14][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][14][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][14][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[14][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[14][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[14][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[14][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[15][0].top) = ((Ull)(emax6.lmmi[0][15][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][15][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][15][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[15][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[15][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[15][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[15][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[16][0].top) = ((Ull)(emax6.lmmi[0][16][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][16][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][16][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[16][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[16][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[16][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[16][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[17][0].top) = ((Ull)(emax6.lmmi[0][17][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][17][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][17][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[17][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[17][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[17][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[17][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[18][0].top) = ((Ull)(emax6.lmmi[0][18][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][18][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][18][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[18][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[18][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[18][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[18][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[19][0].top) = ((Ull)(emax6.lmmi[0][19][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][19][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][19][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[19][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[19][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[19][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[19][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[20][0].top) = ((Ull)(emax6.lmmi[0][20][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][20][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][20][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[20][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[20][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[20][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[20][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[21][0].top) = ((Ull)(emax6.lmmi[0][21][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][21][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][21][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[21][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[21][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[21][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[21][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[22][0].top) = ((Ull)(emax6.lmmi[0][22][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][22][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][22][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[22][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[22][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[22][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[22][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[23][0].top) = ((Ull)(emax6.lmmi[0][23][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][23][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][23][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[23][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[23][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[23][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[23][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[24][0].top) = ((Ull)(emax6.lmmi[0][24][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][24][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][24][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[24][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[24][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[24][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[24][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[25][0].top) = ((Ull)(emax6.lmmi[0][25][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][25][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][25][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[25][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[25][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[25][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[25][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[26][0].top) = ((Ull)(emax6.lmmi[0][26][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][26][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][26][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[26][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[26][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[26][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[26][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[27][0].top) = ((Ull)(emax6.lmmi[0][27][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][27][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][27][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[27][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[27][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[27][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[27][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[28][0].top) = ((Ull)(emax6.lmmi[0][28][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][28][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][28][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[28][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[28][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[28][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[28][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[29][0].top) = ((Ull)(emax6.lmmi[0][29][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][29][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][29][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[29][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[29][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[29][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[29][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[30][0].top) = ((Ull)(emax6.lmmi[0][30][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][30][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][30][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[30][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[30][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[30][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[30][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[31][0].top) = ((Ull)(emax6.lmmi[0][31][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][31][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][31][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[31][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[31][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[31][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[31][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[32][0].top) = ((Ull)(emax6.lmmi[0][32][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][32][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][32][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[32][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[32][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[32][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[32][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[33][0].top) = ((Ull)(emax6.lmmi[0][33][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][33][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][33][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[33][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[33][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[33][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[33][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[34][0].top) = ((Ull)(emax6.lmmi[0][34][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][34][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][34][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[34][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[34][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[34][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[34][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[35][0].top) = ((Ull)(emax6.lmmi[0][35][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][35][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][35][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[35][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[35][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[35][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[35][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[36][0].top) = ((Ull)(emax6.lmmi[0][36][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][36][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][36][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[36][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[36][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[36][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[36][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[37][0].top) = ((Ull)(emax6.lmmi[0][37][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][37][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][37][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[37][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[37][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[37][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[37][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[38][0].top) = ((Ull)(emax6.lmmi[0][38][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][38][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][38][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[38][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[38][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[38][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[38][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[39][0].top) = ((Ull)(emax6.lmmi[0][39][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][39][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][39][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[39][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[39][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[39][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[39][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[40][0].top) = ((Ull)(emax6.lmmi[0][40][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][40][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][40][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[40][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[40][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[40][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[40][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[41][0].top) = ((Ull)(emax6.lmmi[0][41][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][41][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][41][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[41][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[41][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[41][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[41][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[42][0].top) = ((Ull)(emax6.lmmi[0][42][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][42][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][42][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[42][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[42][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[42][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[42][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[43][0].top) = ((Ull)(emax6.lmmi[0][43][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][43][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][43][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[43][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[43][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[43][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[43][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[44][0].top) = ((Ull)(emax6.lmmi[0][44][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][44][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][44][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[44][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[44][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[44][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[44][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[45][0].top) = ((Ull)(emax6.lmmi[0][45][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][45][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][45][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[45][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[45][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[45][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[45][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[46][0].top) = ((Ull)(emax6.lmmi[0][46][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[46][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[46][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[46][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[46][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[47][0].top) = ((Ull)(emax6.lmmi[0][47][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][47][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][47][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[47][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[47][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[47][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[47][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[48][0].top) = ((Ull)(emax6.lmmi[0][48][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][48][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][48][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[48][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[48][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[48][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[48][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[49][0].top) = ((Ull)(emax6.lmmi[0][49][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][49][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][49][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[49][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[49][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[49][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[49][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[50][0].top) = ((Ull)(emax6.lmmi[0][50][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][50][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][50][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[50][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[50][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[50][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[50][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[51][0].top) = ((Ull)(emax6.lmmi[0][51][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][51][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][51][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[51][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[51][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[51][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[51][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[52][0].top) = ((Ull)(emax6.lmmi[0][52][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][52][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][52][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[52][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[52][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[52][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[52][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[53][0].top) = ((Ull)(emax6.lmmi[0][53][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][53][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][53][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[53][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[53][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[53][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[53][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[54][0].top) = ((Ull)(emax6.lmmi[0][54][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][54][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][54][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[54][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[54][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[54][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[54][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[55][0].top) = ((Ull)(emax6.lmmi[0][55][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][55][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[55][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[55][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[55][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[55][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[56][0].top) = ((Ull)(emax6.lmmi[0][56][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][56][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][56][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[56][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[56][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[56][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[56][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[57][0].top) = ((Ull)(emax6.lmmi[0][57][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][57][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][57][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[57][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[57][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[57][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[57][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[58][0].top) = ((Ull)(emax6.lmmi[0][58][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][58][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][58][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[58][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[58][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[58][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[58][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[59][0].top) = ((Ull)(emax6.lmmi[0][59][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][59][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][59][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[59][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[59][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[59][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[59][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[60][0].top) = ((Ull)(emax6.lmmi[0][60][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[60][2].top) = ((Ull)(emax6.lmmi[0][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[60][2].top) = ((Ull)(emax6.lmmi[1][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[60][2].top) = ((Ull)(emax6.lmmi[2][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[60][2].top) = ((Ull)(emax6.lmmi[3][60][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][60][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][60][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[62][0].top) = ((Ull)(emax6.lmmi[0][62][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][62][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][62][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[62][0].top) = ((Ull)(emax6.lmmi[1][62][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][62][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][62][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[62][0].top) = ((Ull)(emax6.lmmi[2][62][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][62][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][62][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[62][0].top) = ((Ull)(emax6.lmmi[3][62][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][62][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][62][0][lmmic].top;
	}
	get_nanosec(NANOS_RANGE);
	emax6.status = STATUS_LOAD;
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 1, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 2, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 3, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 4, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 5, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 6, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 7, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 8, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 9, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 10, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 11, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 12, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 13, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 14, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 15, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 16, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 17, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 18, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 19, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 20, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 21, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 22, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 23, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 24, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 25, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 26, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 27, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 28, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 29, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 30, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 31, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 32, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 33, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 34, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 35, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 36, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 37, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 38, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 39, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 40, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 41, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 42, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 43, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 44, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 45, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 46, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 47, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 48, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 49, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 50, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 51, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 52, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 53, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 54, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 55, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 56, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 57, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 58, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 59, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 60, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 60, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 1, 60, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 2, 60, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 3, 60, 2);/*load*/
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
"	.word	0x03adc0ad, 0x00000000\n"
"	.word	0xffff0000, 0xa0d81d81\n"
"	.word	0x0080a000, 0x0003017e\n"
"	.word	0xffffffff, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0xa0d81d81\n"
"	.word	0x00200e00, 0x0003005e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0xe0d83000\n"
"	.word	0x00000000, 0x00030018\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039c2027, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039c0027, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00806000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039ca027, 0x00000000\n"
"	.word	0xffff0000, 0x60d83000\n"
"	.word	0x00020002, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x039c8027, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc39cc021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
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
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd79d4021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00000000, 0x00030078\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xd39dc021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xc79c4021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00020003, 0x00000064\n"
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
"	.word	0x031c0025, 0x00000800\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab826002, 0x0006811c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x035c6025, 0x00000800\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab82e00a, 0x0006811c\n"
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
