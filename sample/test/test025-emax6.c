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
struct mallinfo {
  size_t arena;
  size_t ordblks;
  size_t smblks;
  size_t hblks;
  size_t hblkhd;
  size_t usmblks;
  size_t fsmblks;
  size_t uordblks;
  size_t fordblks;
  size_t keepcost;
};
extern void * malloc (size_t);
extern void * _malloc_r (struct _reent *, size_t);
extern void free (void *);
extern void _free_r (struct _reent *, void *);
extern void * realloc (void *, size_t);
extern void * _realloc_r (struct _reent *, void *, size_t);
extern void * calloc (size_t, size_t);
extern void * _calloc_r (struct _reent *, size_t, size_t);
extern void * memalign (size_t, size_t);
extern void * _memalign_r (struct _reent *, size_t, size_t);
extern struct mallinfo mallinfo (void);
extern struct mallinfo _mallinfo_r (struct _reent *);
extern void malloc_stats (void);
extern void _malloc_stats_r (struct _reent *);
extern int mallopt (int, int);
extern int _mallopt_r (struct _reent *, int, int);
extern size_t malloc_usable_size (void *);
extern size_t _malloc_usable_size_r (struct _reent *, void *);
extern void * valloc (size_t);
extern void * _valloc_r (struct _reent *, size_t);
extern void * pvalloc (size_t);
extern void * _pvalloc_r (struct _reent *, size_t);
extern int malloc_trim (size_t);
extern int _malloc_trim_r (struct _reent *, size_t);
extern void mstats (char *);
extern void _mstats_r (struct _reent *, char *);
extern void cfree (void *);
int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;
void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void * , const void * , size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *, const char *);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *, const char *);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *, const char *, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *, const char *, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *, const char *);
size_t strxfrm (char *, const char *, size_t);
char *strtok_r (char *, const char *, char **);
int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
int ffs (int);
char *index (const char *, int);
void * memccpy (void * , const void * , int, size_t);
void * mempcpy (void *, const void *, size_t);
void * memmem (const void *, size_t, const void *, size_t);
void * memrchr (const void *, int, size_t);
void * rawmemchr (const void *, int);
char *rindex (const char *, int);
char *stpcpy (char *, const char *);
char *stpncpy (char *, const char *, size_t);
int strcasecmp (const char *, const char *);
char *strcasestr (const char *, const char *);
char *strchrnul (const char *, int);
char *strdup (const char *);
char *_strdup_r (struct _reent *, const char *);
char *strndup (const char *, size_t);
char *_strndup_r (struct _reent *, const char *, size_t);
int strerror_r (int, char *, size_t) __asm__ ("" "__xpg_strerror_r");
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
int strncasecmp (const char *, const char *, size_t);
size_t strnlen (const char *, size_t);
char *strsep (char **, const char *);
char *strlwr (char *);
char *strupr (char *);
char *strsignal (int __signo);
char * _strerror_r (struct _reent *, int, int, int *);
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
    int H_param;
    int W_param;
    int RMGRP_param;
    int NCHIP_param;
    int A_col_blk_param;
} emax6_param;
emax6_sparse2* sparse_format5(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
emax6_sparse2* sparse_format6(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
emax6_sparse2* sparse_format7(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
emax6_sparse2* sparse_format8(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
emax6_sparse2* sparse_format9(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
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
  case 0x0a:
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
Ull __attribute__((always_inline))
exm(Ull s, Uchar exp)
{
  switch (exp) {
  case 0: return ( s );
  case 1: return ((s<<32&0xffffffff00000000LL) | (s &0x00000000ffffffffLL));
  case 2: return ((s &0xffffffff00000000LL) | (s>>32&0x00000000ffffffffLL));
  case 4: return ((s>> 8&0x00ff000000ff0000LL) | (s>>16&0x000000ff000000ffLL));
  case 3: return ((s<< 8&0x00ff000000ff0000LL) | (s &0x000000ff000000ffLL));
  default: return ( s );
  }
}
int
exe(Uint op_ex1, Ull *d, Ull s1, Uint exp1, Ull s2, Uint exp2, Ull s3, Uint exp3, Uint op_ex2, Ull r4, Uint op_ex3, Ull r5)
{
  union { Uint i; float f; } f3, f2, f1, f0;
  Ull r1, r2, r3;
  Ull t3, t2, t1, t0;
  Ull c1, c0;
  Ull ex1_outd;
  Ull ex1_outd_sfma[8];
  Ull ex2_outd;
  int retval = 0;
  r1 = exm(s1, exp1);
  r2 = exm(s2, exp2);
  r3 = exm(s3, exp3);
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
  case 0x0a:
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2>>32);
    f3.i = (Uint)(r3>>32);
    if (f2.i != -1 && f2.i == f3.i) {
      f2.i = (Uint)(r2);
      f3.i = (Uint)(r3);
      f0.f = f1.f + (f2.f * f3.f);
    }
    else {
      f0.f = f1.f;
    }
    t0 = f0.i;
    ex1_outd = t0;
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
mex(Uint op_mx, Uchar **d, Uchar *base, Ull ofs, Ull s2, Ull s1)
{
  Uint ss2 = s2>>32;
  Uint ss1 = s1>>32;
  switch (op_mx) {
  case 0x00:
    *d = base;
    break;
  case 1:
    *d = base + ((ss1!=0xffffffff && ss2<=ss1) ? ofs:0);
    break;
  case 2:
    *d = base + ((ss2!=0xffffffff && ss2>=ss1) ? ofs:0);
    break;
  case 3:
    *d = base + ofs;
    break;
  default:
    printf("emax6lib: mex: undefined op_mx=%d\n", op_mx);
    break;
  }
}
Ull __attribute__((always_inline))
eam(Ull ofs, Uchar msk)
{
  switch (msk) {
  case 14: return (ofs);
  case 13: return (ofs>>32);
  case 12: return (ofs&0x00000000ffffffffLL);
  case 11: return (ofs>>48&0x000000000000ffffLL);
  case 10: return (ofs>>32&0x000000000000ffffLL);
  case 9: return (ofs>>16&0x000000000000ffffLL);
  case 8: return (ofs&0x000000000000ffffLL);
  case 7: return (ofs>>56&0x00000000000000ffLL);
  case 6: return (ofs>>48&0x00000000000000ffLL);
  case 5: return (ofs>>40&0x00000000000000ffLL);
  case 4: return (ofs>>32&0x00000000000000ffLL);
  case 3: return (ofs>>24&0x00000000000000ffLL);
  case 2: return (ofs>>16&0x00000000000000ffLL);
  case 1: return (ofs>>8&0x00000000000000ffLL);
  case 0: return (ofs&0x00000000000000ffLL);
  default: printf("emax6lib: eag: undefined msk=%d\n", msk); return (0LL);;
  }
}
void
eag(Ull *adr, Ull base, Ull ofs)
{
  *adr = base + ofs;
}
void
mop(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr, ofs;
  eag(&adr, base, eam(offset, msk));
  mmp(op_mm, ex, d, adr, top, len, blk);
}
void
mo4(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr, ofs;
  eag(&adr, base, eam(offset, msk));
  mmp(op_mm, ex, d, adr, top, len, blk);
}
int emax6_unaligned_load_valid;
Ull emax6_unaligned_load_high;
void
mmp(Uint op_mm, Ull ex, Ull *d, Ull adr, Ull top, Uint len, Uint blk)
{
  Ull c1, c0, load64;
  if (!((op_mm==0x08 && blk) || op_mm==0x18 || op_mm==0x19) && (!adr || !top)) return;
  if (!((op_mm==0x08 && blk) || op_mm==0x18 || op_mm==0x19) && (adr < top || adr >= top+len*sizeof(Uint)+12)) {
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
  printf("malloc size %d \n",malloc_usable_size(membase));
  printf("membase_before_align: %08.8x\n", (Uint)membase);
  if ((Ull)membase & (Ull)(alignment-1))
  membase = (void*)(((Ull)membase & ~(Ull)(alignment-1))+alignment);
  int i;
  for(i=0;i<memsize/sizeof(Uint);i++) *((Uint*)membase+i) = (Uint)0;
  printf("membase_after_align: %08.8x\n", (Uint)membase);
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
Uint *A_debug;
Uint *B_debug;
Uint *C_debug;
emax6_sparse2* A_sparse;
emax6_param* params;
int blk_iter;
int row,row1, col, col1, n, n1;
int top, blk;
int w, h;
int count0, count1, count2;
int nnz_A,nnz_B,nnz_B_debug;
double sum=0,sum1=0;
Uint Z[(320*240)];
main()
{
  sysinit((Uint)(2*((736LL +1)*736LL)*sizeof(Uint)
                +736LL*736LL*sizeof(Uint)
                +736LL*736LL*sizeof(Uint)
                +736LL*736LL*sizeof(Uint)
                ),32);
  printf("membase: %08.8x\n", (Uint)membase);
  A = (Uint*)membase;
  B = (Uint*)((Uchar*)A + 2*((736LL)*736LL)*sizeof(Uint));
  C0 = (Uint*)((Uchar*)B + 736LL*736LL*sizeof(Uint));
  C1 = (Uint*)((Uchar*)C0 + 736LL*736LL*sizeof(Uint));
  A_debug = (Uint*)calloc(736LL*736LL,sizeof(Uint));
  B_debug = (Uint*)calloc(2*((736LL +1)*736LL),sizeof(Uint));
  C_debug = (Uint*)calloc(736LL*736LL,sizeof(Uint));
  params = (emax6_param*) malloc(sizeof(emax6_param)*1);
  params->RMGRP_param = 8;
  params->NCHIP_param = 4;
  params->H_param = 46;
  params->W_param= 4LL*2;
  printf("A : %08.8x\n", A);
  printf("B : %08.8x\n", B);
  printf("C0: %08.8x\n", C0);
  printf("C1: %08.8x\n", C1);
  int tmp = 0,num = 0;
  int* col_index_A = (int *)calloc(736LL*736LL,sizeof(int));
  int* row_index_A = (int *)calloc(736LL*736LL,sizeof(int));
  Uint* A_tmp = (Uint *)calloc(736LL*736LL,sizeof(Uint));
  for (row=0; row<736LL; row++) {
    for (col=0; col<736LL; col++)
      *(float*)&A[row*736LL +col] = row%120+1;
  }
  for (row=0; row<736LL; row++) {
    for (col=0; col<736LL; col++)
      *(float*)&B[row*736LL +col] = col%120+1;
  }
  orig();
  reset_nanosec();
  imax();
  get_nanosec(0);
  show_nanosec();
  for (row=0; row<736LL; row++) {
    for (col=0; col<736LL; col++) {
      if (C0[row*736LL +col] != C1[row*736LL +col]) {
        count2++;
        printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row, col, (double)*(float*)&C0[row*736LL +col],
                                                row, col, (double)*(float*)&C1[row*736LL +col]);
      }
    }
  }
}
orig() {
  printf("<<<ORIG>>>\n");
  for (row=0; row<736LL; row++) {
    for (col=0; col<736LL; col++) {
      for (n=0; n<736LL; n++) {
        if (n==0) *(float*)&C0[row*736LL +col] = *(float*)&A[row*736LL +n] * *(float*)&B[n*736LL +col];
        else *(float*)&C0[row*736LL +col] += *(float*)&A[row*736LL +n] * *(float*)&B[n*736LL +col];
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
  for (top=0; top<736LL/4; top+=8) {
    for (blk=0; blk<736LL; blk+=46) {
      typedef struct {Uint i[8]} Ui8;
      Uint *a0[4];
      Uint *a[46][4];
      Ui8 *b[46], *b0[46], *b1[46], *b2[46], *b3[46];
      Ui8 *c0[4];
      Ui8 *c00[4], *c01[4], *c02[4], *c03[4];
      for (k=0; k<46; k++) {
 b[k] = B+(blk+k)*736LL; b0[k] = b[k]; b1[k] = (Uint*)b[k]+2; b2[k] = (Uint*)b[k]+4; b3[k] = (Uint*)b[k]+6;
      }
      for (CHIP=0; CHIP<4; CHIP++) {
 a0[CHIP] = A+(CHIP*736LL/4 +top)*736LL;
 for (k=0; k<46; k++)
   a[k][CHIP] = a0[CHIP]+blk+k;
 c0[CHIP] = C1+(CHIP*736LL/4 +top)*736LL;
 c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP]= (Uint*)c0[CHIP]+2; c02[CHIP]= (Uint*)c0[CHIP]+4; c03[CHIP]= (Uint*)c0[CHIP]+6;
      }
#ifndef EMAXSC
volatile emax6_conf_mm();
#endif
#ifndef EMAXSC
	  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].mcid = 3; // NCHIP-1
#endif
	LOOP1 = ((8));
#ifndef EMAXSC
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
#endif
	LOOP0 = ((736LL/4LL/2));
#ifndef EMAXSC
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
#endif
#ifdef EMAXSC
/* EMAXSC start */
#define EMAX_NCHIP 4
#define EMAX_DEPTH 64
#define EMAX_WIDTH 4
#define UNIT_WIDTH 4
struct {Ull b[EMAX_NCHIP][EMAX_WIDTH],o[EMAX_NCHIP][EMAX_WIDTH],awoo[EMAX_NCHIP][EMAX_WIDTH],d[EMAX_NCHIP][EMAX_WIDTH][2];} SCM0[EMAX_DEPTH] __attribute__((aligned(64)));
struct {Ull b[EMAX_NCHIP][EMAX_WIDTH],o[EMAX_NCHIP][EMAX_WIDTH],awoo[EMAX_NCHIP][EMAX_WIDTH],d[EMAX_NCHIP][EMAX_WIDTH][2];} SCM1[EMAX_DEPTH] __attribute__((aligned(64)));
struct {Ull r[EMAX_NCHIP][EMAX_WIDTH];}                                                                                     SCAR[EMAX_DEPTH] __attribute__((aligned(64)));
struct {Ull r[EMAX_NCHIP][2][EMAX_WIDTH*UNIT_WIDTH],enq[EMAX_NCHIP],d0[4],deq[EMAX_NCHIP],d1[4];}                           SCBR[EMAX_DEPTH] __attribute__((aligned(64)));
#undef  EMAX_NCHIP
#undef  EMAX_DEPTH
#undef  EMAX_WIDTH
#undef  UNIT_WIDTH
Uint uLOOP1, uLOOP0;
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((0 && SCBR[63].enq[CHIP]==SCBR[63].deq[CHIP]) || SCBR[63].deq[CHIP]!=SCBR[0].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1&&INIT0)||((1&1)&&INIT0) ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][3] : SCAR[0].r[CHIP][2], 0);
ex2 = exm(((1&2)&&INIT0) ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][4] : 0, 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0xffffffffffffffffLL : 0==1 ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][4] : SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
SCAR[0].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1&&INIT0)||((2&1)&&INIT0) ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][5] : SCAR[0].r[CHIP][3], 0);
ex2 = exm(((2&2)&&INIT0) ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][6] : 0, 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[0].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
}
{
}
{
SCBR[0].r[CHIP][SCBR[0].enq[CHIP]][10] = SCAR[0].r[CHIP][2];
}
{
SCBR[0].r[CHIP][SCBR[0].enq[CHIP]][14] = SCAR[0].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((1 && SCBR[0].enq[CHIP]==SCBR[0].deq[CHIP]) || SCBR[0].deq[CHIP]!=SCBR[1].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[1].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM1[1].b[CHIP][0]) : SCM1[1].awoo[CHIP][0];
SCM1[1].o[CHIP][0] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][10] : SCM1[1].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[1].awoo[CHIP][0] = (Ull)(INIT0?SCM1[1].b[CHIP][0]:SCM1[1].awoo[CHIP][0]);
adr = (Uint)(SCM1[1].awoo[CHIP][0] + SCM1[1].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][1] = SCM1[1].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][1] = SCM1[1].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][1] = SCM1[1].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[1].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM0[1].b[CHIP][0]) : SCM0[1].awoo[CHIP][0];
SCM0[1].o[CHIP][0] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][10] : SCM0[1].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[1].awoo[CHIP][0] = (Ull)(INIT0?SCM0[1].b[CHIP][0]:SCM0[1].awoo[CHIP][0]);
adr = (Uint)(SCM0[1].awoo[CHIP][0] + SCM0[1].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0] = SCM0[1].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0] = SCM0[1].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0] = SCM0[1].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[1].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM1[1].b[CHIP][1]) : SCM1[1].awoo[CHIP][1];
SCM1[1].o[CHIP][1] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][10] : SCM1[1].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[1].awoo[CHIP][1] = (Ull)(INIT0?SCM1[1].b[CHIP][1]:SCM1[1].awoo[CHIP][1]);
adr = (Uint)(SCM1[1].awoo[CHIP][1] + SCM1[1].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][5] = SCM1[1].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][5] = SCM1[1].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][5] = SCM1[1].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[1].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM0[1].b[CHIP][1]) : SCM0[1].awoo[CHIP][1];
SCM0[1].o[CHIP][1] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][10] : SCM0[1].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[1].awoo[CHIP][1] = (Ull)(INIT0?SCM0[1].b[CHIP][1]:SCM0[1].awoo[CHIP][1]);
adr = (Uint)(SCM0[1].awoo[CHIP][1] + SCM0[1].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][4] = SCM0[1].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][4] = SCM0[1].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][4] = SCM0[1].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[1].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM1[1].b[CHIP][2]) : SCM1[1].awoo[CHIP][2];
SCM1[1].o[CHIP][2] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][14] : SCM1[1].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[1].awoo[CHIP][2] = (Ull)(INIT0?SCM1[1].b[CHIP][2]:SCM1[1].awoo[CHIP][2]);
adr = (Uint)(SCM1[1].awoo[CHIP][2] + SCM1[1].o[CHIP][2]);
SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[0].r[CHIP][SCBR[1].enq[CHIP]][14] : SCAR[1].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[0].r[CHIP][SCBR[1].enq[CHIP]][10] : 0, 1);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x00000000ffffffffLL : 0==1 ? SCBR[0].r[CHIP][SCBR[1].enq[CHIP]][10] : SCBR[0].r[CHIP][SCBR[1].enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
SCAR[1].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][2] = SCAR[1].r[CHIP][0];
SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][3] = SCBR[0].r[CHIP][SCBR[10].enq[CHIP]][1];
}
{
SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][6] = SCBR[0].r[CHIP][SCBR[14].enq[CHIP]][1];
}
{
}
{
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((2 && SCBR[1].enq[CHIP]==SCBR[1].deq[CHIP]) || SCBR[1].deq[CHIP]!=SCBR[2].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[2].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM1[2].b[CHIP][0]) : SCM1[2].awoo[CHIP][0];
SCM1[2].o[CHIP][0] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][3] : SCM1[2].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[2].awoo[CHIP][0] = (Ull)(INIT0?SCM1[2].b[CHIP][0]:SCM1[2].awoo[CHIP][0]);
adr = (Uint)(SCM1[2].awoo[CHIP][0] + SCM1[2].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][1] = SCM1[2].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][1] = SCM1[2].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][1] = SCM1[2].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[2].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM0[2].b[CHIP][0]) : SCM0[2].awoo[CHIP][0];
SCM0[2].o[CHIP][0] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][3] : SCM0[2].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[2].awoo[CHIP][0] = (Ull)(INIT0?SCM0[2].b[CHIP][0]:SCM0[2].awoo[CHIP][0]);
adr = (Uint)(SCM0[2].awoo[CHIP][0] + SCM0[2].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0] = SCM0[2].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0] = SCM0[2].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0] = SCM0[2].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[2].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM1[2].b[CHIP][1]) : SCM1[2].awoo[CHIP][1];
SCM1[2].o[CHIP][1] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][3] : SCM1[2].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[2].awoo[CHIP][1] = (Ull)(INIT0?SCM1[2].b[CHIP][1]:SCM1[2].awoo[CHIP][1]);
adr = (Uint)(SCM1[2].awoo[CHIP][1] + SCM1[2].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][5] = SCM1[2].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][5] = SCM1[2].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][5] = SCM1[2].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[2].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM0[2].b[CHIP][1]) : SCM0[2].awoo[CHIP][1];
SCM0[2].o[CHIP][1] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][3] : SCM0[2].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[2].awoo[CHIP][1] = (Ull)(INIT0?SCM0[2].b[CHIP][1]:SCM0[2].awoo[CHIP][1]);
adr = (Uint)(SCM0[2].awoo[CHIP][1] + SCM0[2].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][4] = SCM0[2].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][4] = SCM0[2].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][4] = SCM0[2].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[2].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM1[2].b[CHIP][2]) : SCM1[2].awoo[CHIP][2];
SCM1[2].o[CHIP][2] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][6] : SCM1[2].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[2].awoo[CHIP][2] = (Ull)(INIT0?SCM1[2].b[CHIP][2]:SCM1[2].awoo[CHIP][2]);
adr = (Uint)(SCM1[2].awoo[CHIP][2] + SCM1[2].o[CHIP][2]);
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][1] : SCAR[2].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][9] : 0, 2);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[2].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][0] : SCAR[2].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][9] : 0, 2);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[2].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][5] : SCAR[2].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][9] : 0, 2);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[2].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][4] : SCAR[2].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][9] : 0, 2);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[2].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][2] = SCAR[2].r[CHIP][0];
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][3] = SCBR[1].r[CHIP][SCBR[3].enq[CHIP]][3];
}
{
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][6] = SCAR[2].r[CHIP][1];
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][7] = SCBR[1].r[CHIP][SCBR[6].enq[CHIP]][3];
}
{
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][8] = SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][3];
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][10] = SCAR[2].r[CHIP][2];
}
{
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][14] = SCAR[2].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((3 && SCBR[2].enq[CHIP]==SCBR[2].deq[CHIP]) || SCBR[2].deq[CHIP]!=SCBR[3].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[3].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM1[3].b[CHIP][0]) : SCM1[3].awoo[CHIP][0];
SCM1[3].o[CHIP][0] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] : SCM1[3].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[3].awoo[CHIP][0] = (Ull)(INIT0?SCM1[3].b[CHIP][0]:SCM1[3].awoo[CHIP][0]);
adr = (Uint)(SCM1[3].awoo[CHIP][0] + SCM1[3].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][1] = SCM1[3].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][1] = SCM1[3].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][1] = SCM1[3].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[3].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM0[3].b[CHIP][0]) : SCM0[3].awoo[CHIP][0];
SCM0[3].o[CHIP][0] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] : SCM0[3].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[3].awoo[CHIP][0] = (Ull)(INIT0?SCM0[3].b[CHIP][0]:SCM0[3].awoo[CHIP][0]);
adr = (Uint)(SCM0[3].awoo[CHIP][0] + SCM0[3].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0] = SCM0[3].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0] = SCM0[3].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0] = SCM0[3].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[3].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM1[3].b[CHIP][1]) : SCM1[3].awoo[CHIP][1];
SCM1[3].o[CHIP][1] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] : SCM1[3].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[3].awoo[CHIP][1] = (Ull)(INIT0?SCM1[3].b[CHIP][1]:SCM1[3].awoo[CHIP][1]);
adr = (Uint)(SCM1[3].awoo[CHIP][1] + SCM1[3].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][5] = SCM1[3].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][5] = SCM1[3].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][5] = SCM1[3].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[3].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM0[3].b[CHIP][1]) : SCM0[3].awoo[CHIP][1];
SCM0[3].o[CHIP][1] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] : SCM0[3].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[3].awoo[CHIP][1] = (Ull)(INIT0?SCM0[3].b[CHIP][1]:SCM0[3].awoo[CHIP][1]);
adr = (Uint)(SCM0[3].awoo[CHIP][1] + SCM0[3].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][4] = SCM0[3].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][4] = SCM0[3].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][4] = SCM0[3].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[3].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM1[3].b[CHIP][2]) : SCM1[3].awoo[CHIP][2];
SCM1[3].o[CHIP][2] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][7] : SCM1[3].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[3].awoo[CHIP][2] = (Ull)(INIT0?SCM1[3].b[CHIP][2]:SCM1[3].awoo[CHIP][2]);
adr = (Uint)(SCM1[3].awoo[CHIP][2] + SCM1[3].o[CHIP][2]);
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][2] : SCAR[3].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][9] : 0, 3);
ex3 = exm(SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][1], 3);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[3].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][6] : SCAR[3].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][9] : 0, 3);
ex3 = exm(SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][0], 3);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[3].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][10] : SCAR[3].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][9] : 0, 3);
ex3 = exm(SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][5], 3);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[3].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][14] : SCAR[3].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][9] : 0, 3);
ex3 = exm(SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][4], 3);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[3].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][2] = SCAR[3].r[CHIP][0];
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] = SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][6] = SCAR[3].r[CHIP][1];
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][7] = SCBR[2].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][8] = SCBR[2].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][10] = SCAR[3].r[CHIP][2];
}
{
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][14] = SCAR[3].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((4 && SCBR[3].enq[CHIP]==SCBR[3].deq[CHIP]) || SCBR[3].deq[CHIP]!=SCBR[4].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[4].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM1[4].b[CHIP][0]) : SCM1[4].awoo[CHIP][0];
SCM1[4].o[CHIP][0] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][3] : SCM1[4].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[4].awoo[CHIP][0] = (Ull)(INIT0?SCM1[4].b[CHIP][0]:SCM1[4].awoo[CHIP][0]);
adr = (Uint)(SCM1[4].awoo[CHIP][0] + SCM1[4].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][1] = SCM1[4].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][1] = SCM1[4].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][1] = SCM1[4].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[4].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM0[4].b[CHIP][0]) : SCM0[4].awoo[CHIP][0];
SCM0[4].o[CHIP][0] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][3] : SCM0[4].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[4].awoo[CHIP][0] = (Ull)(INIT0?SCM0[4].b[CHIP][0]:SCM0[4].awoo[CHIP][0]);
adr = (Uint)(SCM0[4].awoo[CHIP][0] + SCM0[4].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0] = SCM0[4].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0] = SCM0[4].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0] = SCM0[4].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[4].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM1[4].b[CHIP][1]) : SCM1[4].awoo[CHIP][1];
SCM1[4].o[CHIP][1] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][3] : SCM1[4].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[4].awoo[CHIP][1] = (Ull)(INIT0?SCM1[4].b[CHIP][1]:SCM1[4].awoo[CHIP][1]);
adr = (Uint)(SCM1[4].awoo[CHIP][1] + SCM1[4].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][5] = SCM1[4].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][5] = SCM1[4].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][5] = SCM1[4].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[4].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM0[4].b[CHIP][1]) : SCM0[4].awoo[CHIP][1];
SCM0[4].o[CHIP][1] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][3] : SCM0[4].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[4].awoo[CHIP][1] = (Ull)(INIT0?SCM0[4].b[CHIP][1]:SCM0[4].awoo[CHIP][1]);
adr = (Uint)(SCM0[4].awoo[CHIP][1] + SCM0[4].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][4] = SCM0[4].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][4] = SCM0[4].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][4] = SCM0[4].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[4].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM1[4].b[CHIP][2]) : SCM1[4].awoo[CHIP][2];
SCM1[4].o[CHIP][2] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][7] : SCM1[4].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[4].awoo[CHIP][2] = (Ull)(INIT0?SCM1[4].b[CHIP][2]:SCM1[4].awoo[CHIP][2]);
adr = (Uint)(SCM1[4].awoo[CHIP][2] + SCM1[4].o[CHIP][2]);
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][2] : SCAR[4].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][9] : 0, 4);
ex3 = exm(SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][1], 4);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[4].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][6] : SCAR[4].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][9] : 0, 4);
ex3 = exm(SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][0], 4);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[4].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][10] : SCAR[4].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][9] : 0, 4);
ex3 = exm(SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][5], 4);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[4].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][14] : SCAR[4].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][9] : 0, 4);
ex3 = exm(SCBR[3].r[CHIP][SCBR[4].enq[CHIP]][4], 4);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[4].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][2] = SCAR[4].r[CHIP][0];
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][3] = SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][6] = SCAR[4].r[CHIP][1];
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][7] = SCBR[3].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][8] = SCBR[3].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][10] = SCAR[4].r[CHIP][2];
}
{
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][14] = SCAR[4].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((5 && SCBR[4].enq[CHIP]==SCBR[4].deq[CHIP]) || SCBR[4].deq[CHIP]!=SCBR[5].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[5].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM1[5].b[CHIP][0]) : SCM1[5].awoo[CHIP][0];
SCM1[5].o[CHIP][0] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][3] : SCM1[5].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[5].awoo[CHIP][0] = (Ull)(INIT0?SCM1[5].b[CHIP][0]:SCM1[5].awoo[CHIP][0]);
adr = (Uint)(SCM1[5].awoo[CHIP][0] + SCM1[5].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][1] = SCM1[5].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][1] = SCM1[5].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][1] = SCM1[5].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[5].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM0[5].b[CHIP][0]) : SCM0[5].awoo[CHIP][0];
SCM0[5].o[CHIP][0] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][3] : SCM0[5].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[5].awoo[CHIP][0] = (Ull)(INIT0?SCM0[5].b[CHIP][0]:SCM0[5].awoo[CHIP][0]);
adr = (Uint)(SCM0[5].awoo[CHIP][0] + SCM0[5].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0] = SCM0[5].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0] = SCM0[5].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0] = SCM0[5].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[5].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM1[5].b[CHIP][1]) : SCM1[5].awoo[CHIP][1];
SCM1[5].o[CHIP][1] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][3] : SCM1[5].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[5].awoo[CHIP][1] = (Ull)(INIT0?SCM1[5].b[CHIP][1]:SCM1[5].awoo[CHIP][1]);
adr = (Uint)(SCM1[5].awoo[CHIP][1] + SCM1[5].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][5] = SCM1[5].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][5] = SCM1[5].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][5] = SCM1[5].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[5].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM0[5].b[CHIP][1]) : SCM0[5].awoo[CHIP][1];
SCM0[5].o[CHIP][1] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][3] : SCM0[5].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[5].awoo[CHIP][1] = (Ull)(INIT0?SCM0[5].b[CHIP][1]:SCM0[5].awoo[CHIP][1]);
adr = (Uint)(SCM0[5].awoo[CHIP][1] + SCM0[5].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][4] = SCM0[5].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][4] = SCM0[5].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][4] = SCM0[5].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[5].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM1[5].b[CHIP][2]) : SCM1[5].awoo[CHIP][2];
SCM1[5].o[CHIP][2] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][7] : SCM1[5].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[5].awoo[CHIP][2] = (Ull)(INIT0?SCM1[5].b[CHIP][2]:SCM1[5].awoo[CHIP][2]);
adr = (Uint)(SCM1[5].awoo[CHIP][2] + SCM1[5].o[CHIP][2]);
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][2] : SCAR[5].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][9] : 0, 5);
ex3 = exm(SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][1], 5);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[5].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][6] : SCAR[5].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][9] : 0, 5);
ex3 = exm(SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][0], 5);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[5].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][10] : SCAR[5].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][9] : 0, 5);
ex3 = exm(SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][5], 5);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[5].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][14] : SCAR[5].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][9] : 0, 5);
ex3 = exm(SCBR[4].r[CHIP][SCBR[5].enq[CHIP]][4], 5);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[5].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][2] = SCAR[5].r[CHIP][0];
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][3] = SCBR[4].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][6] = SCAR[5].r[CHIP][1];
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][7] = SCBR[4].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][8] = SCBR[4].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][10] = SCAR[5].r[CHIP][2];
}
{
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][14] = SCAR[5].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((6 && SCBR[5].enq[CHIP]==SCBR[5].deq[CHIP]) || SCBR[5].deq[CHIP]!=SCBR[6].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[6].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM1[6].b[CHIP][0]) : SCM1[6].awoo[CHIP][0];
SCM1[6].o[CHIP][0] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][3] : SCM1[6].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[6].awoo[CHIP][0] = (Ull)(INIT0?SCM1[6].b[CHIP][0]:SCM1[6].awoo[CHIP][0]);
adr = (Uint)(SCM1[6].awoo[CHIP][0] + SCM1[6].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][1] = SCM1[6].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][1] = SCM1[6].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][1] = SCM1[6].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[6].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM0[6].b[CHIP][0]) : SCM0[6].awoo[CHIP][0];
SCM0[6].o[CHIP][0] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][3] : SCM0[6].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[6].awoo[CHIP][0] = (Ull)(INIT0?SCM0[6].b[CHIP][0]:SCM0[6].awoo[CHIP][0]);
adr = (Uint)(SCM0[6].awoo[CHIP][0] + SCM0[6].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0] = SCM0[6].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0] = SCM0[6].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0] = SCM0[6].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[6].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM1[6].b[CHIP][1]) : SCM1[6].awoo[CHIP][1];
SCM1[6].o[CHIP][1] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][3] : SCM1[6].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[6].awoo[CHIP][1] = (Ull)(INIT0?SCM1[6].b[CHIP][1]:SCM1[6].awoo[CHIP][1]);
adr = (Uint)(SCM1[6].awoo[CHIP][1] + SCM1[6].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][5] = SCM1[6].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][5] = SCM1[6].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][5] = SCM1[6].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[6].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM0[6].b[CHIP][1]) : SCM0[6].awoo[CHIP][1];
SCM0[6].o[CHIP][1] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][3] : SCM0[6].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[6].awoo[CHIP][1] = (Ull)(INIT0?SCM0[6].b[CHIP][1]:SCM0[6].awoo[CHIP][1]);
adr = (Uint)(SCM0[6].awoo[CHIP][1] + SCM0[6].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][4] = SCM0[6].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][4] = SCM0[6].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][4] = SCM0[6].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[6].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM1[6].b[CHIP][2]) : SCM1[6].awoo[CHIP][2];
SCM1[6].o[CHIP][2] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][7] : SCM1[6].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[6].awoo[CHIP][2] = (Ull)(INIT0?SCM1[6].b[CHIP][2]:SCM1[6].awoo[CHIP][2]);
adr = (Uint)(SCM1[6].awoo[CHIP][2] + SCM1[6].o[CHIP][2]);
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][2] : SCAR[6].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][9] : 0, 6);
ex3 = exm(SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][1], 6);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[6].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][6] : SCAR[6].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][9] : 0, 6);
ex3 = exm(SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][0], 6);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[6].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][10] : SCAR[6].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][9] : 0, 6);
ex3 = exm(SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][5], 6);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[6].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][14] : SCAR[6].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][9] : 0, 6);
ex3 = exm(SCBR[5].r[CHIP][SCBR[6].enq[CHIP]][4], 6);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[6].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][2] = SCAR[6].r[CHIP][0];
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][3] = SCBR[5].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][6] = SCAR[6].r[CHIP][1];
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][7] = SCBR[5].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][8] = SCBR[5].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][10] = SCAR[6].r[CHIP][2];
}
{
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][14] = SCAR[6].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((7 && SCBR[6].enq[CHIP]==SCBR[6].deq[CHIP]) || SCBR[6].deq[CHIP]!=SCBR[7].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[7].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM1[7].b[CHIP][0]) : SCM1[7].awoo[CHIP][0];
SCM1[7].o[CHIP][0] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][3] : SCM1[7].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[7].awoo[CHIP][0] = (Ull)(INIT0?SCM1[7].b[CHIP][0]:SCM1[7].awoo[CHIP][0]);
adr = (Uint)(SCM1[7].awoo[CHIP][0] + SCM1[7].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][1] = SCM1[7].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][1] = SCM1[7].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][1] = SCM1[7].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[7].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM0[7].b[CHIP][0]) : SCM0[7].awoo[CHIP][0];
SCM0[7].o[CHIP][0] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][3] : SCM0[7].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[7].awoo[CHIP][0] = (Ull)(INIT0?SCM0[7].b[CHIP][0]:SCM0[7].awoo[CHIP][0]);
adr = (Uint)(SCM0[7].awoo[CHIP][0] + SCM0[7].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0] = SCM0[7].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0] = SCM0[7].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0] = SCM0[7].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[7].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM1[7].b[CHIP][1]) : SCM1[7].awoo[CHIP][1];
SCM1[7].o[CHIP][1] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][3] : SCM1[7].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[7].awoo[CHIP][1] = (Ull)(INIT0?SCM1[7].b[CHIP][1]:SCM1[7].awoo[CHIP][1]);
adr = (Uint)(SCM1[7].awoo[CHIP][1] + SCM1[7].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][5] = SCM1[7].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][5] = SCM1[7].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][5] = SCM1[7].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[7].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM0[7].b[CHIP][1]) : SCM0[7].awoo[CHIP][1];
SCM0[7].o[CHIP][1] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][3] : SCM0[7].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[7].awoo[CHIP][1] = (Ull)(INIT0?SCM0[7].b[CHIP][1]:SCM0[7].awoo[CHIP][1]);
adr = (Uint)(SCM0[7].awoo[CHIP][1] + SCM0[7].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][4] = SCM0[7].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][4] = SCM0[7].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][4] = SCM0[7].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[7].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM1[7].b[CHIP][2]) : SCM1[7].awoo[CHIP][2];
SCM1[7].o[CHIP][2] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][7] : SCM1[7].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[7].awoo[CHIP][2] = (Ull)(INIT0?SCM1[7].b[CHIP][2]:SCM1[7].awoo[CHIP][2]);
adr = (Uint)(SCM1[7].awoo[CHIP][2] + SCM1[7].o[CHIP][2]);
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][2] : SCAR[7].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][9] : 0, 7);
ex3 = exm(SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][1], 7);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[7].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][6] : SCAR[7].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][9] : 0, 7);
ex3 = exm(SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][0], 7);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[7].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][10] : SCAR[7].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][9] : 0, 7);
ex3 = exm(SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][5], 7);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[7].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][14] : SCAR[7].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][9] : 0, 7);
ex3 = exm(SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][4], 7);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[7].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][2] = SCAR[7].r[CHIP][0];
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][3] = SCBR[6].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][6] = SCAR[7].r[CHIP][1];
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][7] = SCBR[6].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][8] = SCBR[6].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][10] = SCAR[7].r[CHIP][2];
}
{
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][14] = SCAR[7].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((8 && SCBR[7].enq[CHIP]==SCBR[7].deq[CHIP]) || SCBR[7].deq[CHIP]!=SCBR[8].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[8].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM1[8].b[CHIP][0]) : SCM1[8].awoo[CHIP][0];
SCM1[8].o[CHIP][0] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][3] : SCM1[8].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[8].awoo[CHIP][0] = (Ull)(INIT0?SCM1[8].b[CHIP][0]:SCM1[8].awoo[CHIP][0]);
adr = (Uint)(SCM1[8].awoo[CHIP][0] + SCM1[8].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][1] = SCM1[8].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][1] = SCM1[8].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][1] = SCM1[8].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[8].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM0[8].b[CHIP][0]) : SCM0[8].awoo[CHIP][0];
SCM0[8].o[CHIP][0] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][3] : SCM0[8].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[8].awoo[CHIP][0] = (Ull)(INIT0?SCM0[8].b[CHIP][0]:SCM0[8].awoo[CHIP][0]);
adr = (Uint)(SCM0[8].awoo[CHIP][0] + SCM0[8].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0] = SCM0[8].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0] = SCM0[8].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0] = SCM0[8].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[8].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM1[8].b[CHIP][1]) : SCM1[8].awoo[CHIP][1];
SCM1[8].o[CHIP][1] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][3] : SCM1[8].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[8].awoo[CHIP][1] = (Ull)(INIT0?SCM1[8].b[CHIP][1]:SCM1[8].awoo[CHIP][1]);
adr = (Uint)(SCM1[8].awoo[CHIP][1] + SCM1[8].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][5] = SCM1[8].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][5] = SCM1[8].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][5] = SCM1[8].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[8].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM0[8].b[CHIP][1]) : SCM0[8].awoo[CHIP][1];
SCM0[8].o[CHIP][1] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][3] : SCM0[8].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[8].awoo[CHIP][1] = (Ull)(INIT0?SCM0[8].b[CHIP][1]:SCM0[8].awoo[CHIP][1]);
adr = (Uint)(SCM0[8].awoo[CHIP][1] + SCM0[8].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][4] = SCM0[8].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][4] = SCM0[8].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][4] = SCM0[8].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[8].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM1[8].b[CHIP][2]) : SCM1[8].awoo[CHIP][2];
SCM1[8].o[CHIP][2] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][7] : SCM1[8].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[8].awoo[CHIP][2] = (Ull)(INIT0?SCM1[8].b[CHIP][2]:SCM1[8].awoo[CHIP][2]);
adr = (Uint)(SCM1[8].awoo[CHIP][2] + SCM1[8].o[CHIP][2]);
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][2] : SCAR[8].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][9] : 0, 8);
ex3 = exm(SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][1], 8);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[8].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][6] : SCAR[8].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][9] : 0, 8);
ex3 = exm(SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][0], 8);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[8].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][10] : SCAR[8].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][9] : 0, 8);
ex3 = exm(SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][5], 8);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[8].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][14] : SCAR[8].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][9] : 0, 8);
ex3 = exm(SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][4], 8);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[8].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][2] = SCAR[8].r[CHIP][0];
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][3] = SCBR[7].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][6] = SCAR[8].r[CHIP][1];
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][7] = SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][8] = SCBR[7].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][10] = SCAR[8].r[CHIP][2];
}
{
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][14] = SCAR[8].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((9 && SCBR[8].enq[CHIP]==SCBR[8].deq[CHIP]) || SCBR[8].deq[CHIP]!=SCBR[9].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[9].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM1[9].b[CHIP][0]) : SCM1[9].awoo[CHIP][0];
SCM1[9].o[CHIP][0] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][3] : SCM1[9].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[9].awoo[CHIP][0] = (Ull)(INIT0?SCM1[9].b[CHIP][0]:SCM1[9].awoo[CHIP][0]);
adr = (Uint)(SCM1[9].awoo[CHIP][0] + SCM1[9].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][1] = SCM1[9].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][1] = SCM1[9].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][1] = SCM1[9].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[9].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM0[9].b[CHIP][0]) : SCM0[9].awoo[CHIP][0];
SCM0[9].o[CHIP][0] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][3] : SCM0[9].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[9].awoo[CHIP][0] = (Ull)(INIT0?SCM0[9].b[CHIP][0]:SCM0[9].awoo[CHIP][0]);
adr = (Uint)(SCM0[9].awoo[CHIP][0] + SCM0[9].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0] = SCM0[9].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0] = SCM0[9].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0] = SCM0[9].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[9].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM1[9].b[CHIP][1]) : SCM1[9].awoo[CHIP][1];
SCM1[9].o[CHIP][1] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][3] : SCM1[9].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[9].awoo[CHIP][1] = (Ull)(INIT0?SCM1[9].b[CHIP][1]:SCM1[9].awoo[CHIP][1]);
adr = (Uint)(SCM1[9].awoo[CHIP][1] + SCM1[9].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][5] = SCM1[9].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][5] = SCM1[9].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][5] = SCM1[9].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[9].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM0[9].b[CHIP][1]) : SCM0[9].awoo[CHIP][1];
SCM0[9].o[CHIP][1] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][3] : SCM0[9].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[9].awoo[CHIP][1] = (Ull)(INIT0?SCM0[9].b[CHIP][1]:SCM0[9].awoo[CHIP][1]);
adr = (Uint)(SCM0[9].awoo[CHIP][1] + SCM0[9].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][4] = SCM0[9].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][4] = SCM0[9].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][4] = SCM0[9].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[9].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM1[9].b[CHIP][2]) : SCM1[9].awoo[CHIP][2];
SCM1[9].o[CHIP][2] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][7] : SCM1[9].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[9].awoo[CHIP][2] = (Ull)(INIT0?SCM1[9].b[CHIP][2]:SCM1[9].awoo[CHIP][2]);
adr = (Uint)(SCM1[9].awoo[CHIP][2] + SCM1[9].o[CHIP][2]);
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][2] : SCAR[9].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][9] : 0, 9);
ex3 = exm(SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][1], 9);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[9].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][6] : SCAR[9].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][9] : 0, 9);
ex3 = exm(SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][0], 9);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[9].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][10] : SCAR[9].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][9] : 0, 9);
ex3 = exm(SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][5], 9);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[9].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][14] : SCAR[9].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][9] : 0, 9);
ex3 = exm(SCBR[8].r[CHIP][SCBR[9].enq[CHIP]][4], 9);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[9].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][2] = SCAR[9].r[CHIP][0];
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][3] = SCBR[8].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][6] = SCAR[9].r[CHIP][1];
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][7] = SCBR[8].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][8] = SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][10] = SCAR[9].r[CHIP][2];
}
{
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][14] = SCAR[9].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((10 && SCBR[9].enq[CHIP]==SCBR[9].deq[CHIP]) || SCBR[9].deq[CHIP]!=SCBR[10].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[10].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM1[10].b[CHIP][0]) : SCM1[10].awoo[CHIP][0];
SCM1[10].o[CHIP][0] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][3] : SCM1[10].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[10].awoo[CHIP][0] = (Ull)(INIT0?SCM1[10].b[CHIP][0]:SCM1[10].awoo[CHIP][0]);
adr = (Uint)(SCM1[10].awoo[CHIP][0] + SCM1[10].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][1] = SCM1[10].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][1] = SCM1[10].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][1] = SCM1[10].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[10].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM0[10].b[CHIP][0]) : SCM0[10].awoo[CHIP][0];
SCM0[10].o[CHIP][0] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][3] : SCM0[10].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[10].awoo[CHIP][0] = (Ull)(INIT0?SCM0[10].b[CHIP][0]:SCM0[10].awoo[CHIP][0]);
adr = (Uint)(SCM0[10].awoo[CHIP][0] + SCM0[10].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0] = SCM0[10].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0] = SCM0[10].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0] = SCM0[10].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[10].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM1[10].b[CHIP][1]) : SCM1[10].awoo[CHIP][1];
SCM1[10].o[CHIP][1] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][3] : SCM1[10].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[10].awoo[CHIP][1] = (Ull)(INIT0?SCM1[10].b[CHIP][1]:SCM1[10].awoo[CHIP][1]);
adr = (Uint)(SCM1[10].awoo[CHIP][1] + SCM1[10].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][5] = SCM1[10].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][5] = SCM1[10].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][5] = SCM1[10].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[10].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM0[10].b[CHIP][1]) : SCM0[10].awoo[CHIP][1];
SCM0[10].o[CHIP][1] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][3] : SCM0[10].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[10].awoo[CHIP][1] = (Ull)(INIT0?SCM0[10].b[CHIP][1]:SCM0[10].awoo[CHIP][1]);
adr = (Uint)(SCM0[10].awoo[CHIP][1] + SCM0[10].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][4] = SCM0[10].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][4] = SCM0[10].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][4] = SCM0[10].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[10].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM1[10].b[CHIP][2]) : SCM1[10].awoo[CHIP][2];
SCM1[10].o[CHIP][2] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][7] : SCM1[10].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[10].awoo[CHIP][2] = (Ull)(INIT0?SCM1[10].b[CHIP][2]:SCM1[10].awoo[CHIP][2]);
adr = (Uint)(SCM1[10].awoo[CHIP][2] + SCM1[10].o[CHIP][2]);
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][2] : SCAR[10].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][9] : 0, 10);
ex3 = exm(SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][1], 10);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[10].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][6] : SCAR[10].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][9] : 0, 10);
ex3 = exm(SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][0], 10);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[10].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][10] : SCAR[10].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][9] : 0, 10);
ex3 = exm(SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][5], 10);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[10].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][14] : SCAR[10].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][9] : 0, 10);
ex3 = exm(SCBR[9].r[CHIP][SCBR[10].enq[CHIP]][4], 10);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[10].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][2] = SCAR[10].r[CHIP][0];
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][3] = SCBR[9].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][6] = SCAR[10].r[CHIP][1];
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][7] = SCBR[9].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][8] = SCBR[9].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][10] = SCAR[10].r[CHIP][2];
}
{
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][14] = SCAR[10].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((11 && SCBR[10].enq[CHIP]==SCBR[10].deq[CHIP]) || SCBR[10].deq[CHIP]!=SCBR[11].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[11].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM1[11].b[CHIP][0]) : SCM1[11].awoo[CHIP][0];
SCM1[11].o[CHIP][0] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][3] : SCM1[11].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[11].awoo[CHIP][0] = (Ull)(INIT0?SCM1[11].b[CHIP][0]:SCM1[11].awoo[CHIP][0]);
adr = (Uint)(SCM1[11].awoo[CHIP][0] + SCM1[11].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][1] = SCM1[11].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][1] = SCM1[11].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][1] = SCM1[11].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[11].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM0[11].b[CHIP][0]) : SCM0[11].awoo[CHIP][0];
SCM0[11].o[CHIP][0] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][3] : SCM0[11].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[11].awoo[CHIP][0] = (Ull)(INIT0?SCM0[11].b[CHIP][0]:SCM0[11].awoo[CHIP][0]);
adr = (Uint)(SCM0[11].awoo[CHIP][0] + SCM0[11].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0] = SCM0[11].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0] = SCM0[11].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0] = SCM0[11].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[11].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM1[11].b[CHIP][1]) : SCM1[11].awoo[CHIP][1];
SCM1[11].o[CHIP][1] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][3] : SCM1[11].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[11].awoo[CHIP][1] = (Ull)(INIT0?SCM1[11].b[CHIP][1]:SCM1[11].awoo[CHIP][1]);
adr = (Uint)(SCM1[11].awoo[CHIP][1] + SCM1[11].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][5] = SCM1[11].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][5] = SCM1[11].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][5] = SCM1[11].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[11].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM0[11].b[CHIP][1]) : SCM0[11].awoo[CHIP][1];
SCM0[11].o[CHIP][1] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][3] : SCM0[11].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[11].awoo[CHIP][1] = (Ull)(INIT0?SCM0[11].b[CHIP][1]:SCM0[11].awoo[CHIP][1]);
adr = (Uint)(SCM0[11].awoo[CHIP][1] + SCM0[11].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][4] = SCM0[11].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][4] = SCM0[11].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][4] = SCM0[11].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[11].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM1[11].b[CHIP][2]) : SCM1[11].awoo[CHIP][2];
SCM1[11].o[CHIP][2] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][7] : SCM1[11].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[11].awoo[CHIP][2] = (Ull)(INIT0?SCM1[11].b[CHIP][2]:SCM1[11].awoo[CHIP][2]);
adr = (Uint)(SCM1[11].awoo[CHIP][2] + SCM1[11].o[CHIP][2]);
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][2] : SCAR[11].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][9] : 0, 11);
ex3 = exm(SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][1], 11);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[11].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][6] : SCAR[11].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][9] : 0, 11);
ex3 = exm(SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][0], 11);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[11].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][10] : SCAR[11].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][9] : 0, 11);
ex3 = exm(SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][5], 11);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[11].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][14] : SCAR[11].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][9] : 0, 11);
ex3 = exm(SCBR[10].r[CHIP][SCBR[11].enq[CHIP]][4], 11);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[11].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][2] = SCAR[11].r[CHIP][0];
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][3] = SCBR[10].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][6] = SCAR[11].r[CHIP][1];
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][7] = SCBR[10].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][8] = SCBR[10].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][10] = SCAR[11].r[CHIP][2];
}
{
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][14] = SCAR[11].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((12 && SCBR[11].enq[CHIP]==SCBR[11].deq[CHIP]) || SCBR[11].deq[CHIP]!=SCBR[12].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[12].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM1[12].b[CHIP][0]) : SCM1[12].awoo[CHIP][0];
SCM1[12].o[CHIP][0] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][3] : SCM1[12].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[12].awoo[CHIP][0] = (Ull)(INIT0?SCM1[12].b[CHIP][0]:SCM1[12].awoo[CHIP][0]);
adr = (Uint)(SCM1[12].awoo[CHIP][0] + SCM1[12].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][1] = SCM1[12].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][1] = SCM1[12].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][1] = SCM1[12].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[12].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM0[12].b[CHIP][0]) : SCM0[12].awoo[CHIP][0];
SCM0[12].o[CHIP][0] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][3] : SCM0[12].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[12].awoo[CHIP][0] = (Ull)(INIT0?SCM0[12].b[CHIP][0]:SCM0[12].awoo[CHIP][0]);
adr = (Uint)(SCM0[12].awoo[CHIP][0] + SCM0[12].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0] = SCM0[12].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0] = SCM0[12].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0] = SCM0[12].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[12].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM1[12].b[CHIP][1]) : SCM1[12].awoo[CHIP][1];
SCM1[12].o[CHIP][1] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][3] : SCM1[12].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[12].awoo[CHIP][1] = (Ull)(INIT0?SCM1[12].b[CHIP][1]:SCM1[12].awoo[CHIP][1]);
adr = (Uint)(SCM1[12].awoo[CHIP][1] + SCM1[12].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][5] = SCM1[12].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][5] = SCM1[12].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][5] = SCM1[12].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[12].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM0[12].b[CHIP][1]) : SCM0[12].awoo[CHIP][1];
SCM0[12].o[CHIP][1] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][3] : SCM0[12].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[12].awoo[CHIP][1] = (Ull)(INIT0?SCM0[12].b[CHIP][1]:SCM0[12].awoo[CHIP][1]);
adr = (Uint)(SCM0[12].awoo[CHIP][1] + SCM0[12].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][4] = SCM0[12].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][4] = SCM0[12].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][4] = SCM0[12].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[12].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM1[12].b[CHIP][2]) : SCM1[12].awoo[CHIP][2];
SCM1[12].o[CHIP][2] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][7] : SCM1[12].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[12].awoo[CHIP][2] = (Ull)(INIT0?SCM1[12].b[CHIP][2]:SCM1[12].awoo[CHIP][2]);
adr = (Uint)(SCM1[12].awoo[CHIP][2] + SCM1[12].o[CHIP][2]);
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][2] : SCAR[12].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][9] : 0, 12);
ex3 = exm(SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][1], 12);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[12].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][6] : SCAR[12].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][9] : 0, 12);
ex3 = exm(SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][0], 12);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[12].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][10] : SCAR[12].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][9] : 0, 12);
ex3 = exm(SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][5], 12);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[12].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][14] : SCAR[12].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][9] : 0, 12);
ex3 = exm(SCBR[11].r[CHIP][SCBR[12].enq[CHIP]][4], 12);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[12].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][2] = SCAR[12].r[CHIP][0];
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][3] = SCBR[11].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][6] = SCAR[12].r[CHIP][1];
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][7] = SCBR[11].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][8] = SCBR[11].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][10] = SCAR[12].r[CHIP][2];
}
{
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][14] = SCAR[12].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((13 && SCBR[12].enq[CHIP]==SCBR[12].deq[CHIP]) || SCBR[12].deq[CHIP]!=SCBR[13].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[13].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM1[13].b[CHIP][0]) : SCM1[13].awoo[CHIP][0];
SCM1[13].o[CHIP][0] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][3] : SCM1[13].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[13].awoo[CHIP][0] = (Ull)(INIT0?SCM1[13].b[CHIP][0]:SCM1[13].awoo[CHIP][0]);
adr = (Uint)(SCM1[13].awoo[CHIP][0] + SCM1[13].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][1] = SCM1[13].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][1] = SCM1[13].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][1] = SCM1[13].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[13].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM0[13].b[CHIP][0]) : SCM0[13].awoo[CHIP][0];
SCM0[13].o[CHIP][0] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][3] : SCM0[13].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[13].awoo[CHIP][0] = (Ull)(INIT0?SCM0[13].b[CHIP][0]:SCM0[13].awoo[CHIP][0]);
adr = (Uint)(SCM0[13].awoo[CHIP][0] + SCM0[13].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0] = SCM0[13].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0] = SCM0[13].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0] = SCM0[13].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[13].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM1[13].b[CHIP][1]) : SCM1[13].awoo[CHIP][1];
SCM1[13].o[CHIP][1] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][3] : SCM1[13].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[13].awoo[CHIP][1] = (Ull)(INIT0?SCM1[13].b[CHIP][1]:SCM1[13].awoo[CHIP][1]);
adr = (Uint)(SCM1[13].awoo[CHIP][1] + SCM1[13].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][5] = SCM1[13].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][5] = SCM1[13].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][5] = SCM1[13].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[13].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM0[13].b[CHIP][1]) : SCM0[13].awoo[CHIP][1];
SCM0[13].o[CHIP][1] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][3] : SCM0[13].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[13].awoo[CHIP][1] = (Ull)(INIT0?SCM0[13].b[CHIP][1]:SCM0[13].awoo[CHIP][1]);
adr = (Uint)(SCM0[13].awoo[CHIP][1] + SCM0[13].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][4] = SCM0[13].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][4] = SCM0[13].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][4] = SCM0[13].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[13].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM1[13].b[CHIP][2]) : SCM1[13].awoo[CHIP][2];
SCM1[13].o[CHIP][2] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][7] : SCM1[13].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[13].awoo[CHIP][2] = (Ull)(INIT0?SCM1[13].b[CHIP][2]:SCM1[13].awoo[CHIP][2]);
adr = (Uint)(SCM1[13].awoo[CHIP][2] + SCM1[13].o[CHIP][2]);
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][2] : SCAR[13].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][9] : 0, 13);
ex3 = exm(SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][1], 13);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[13].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][6] : SCAR[13].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][9] : 0, 13);
ex3 = exm(SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][0], 13);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[13].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][10] : SCAR[13].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][9] : 0, 13);
ex3 = exm(SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][5], 13);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[13].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][14] : SCAR[13].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][9] : 0, 13);
ex3 = exm(SCBR[12].r[CHIP][SCBR[13].enq[CHIP]][4], 13);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[13].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][2] = SCAR[13].r[CHIP][0];
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][3] = SCBR[12].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][6] = SCAR[13].r[CHIP][1];
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][7] = SCBR[12].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][8] = SCBR[12].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][10] = SCAR[13].r[CHIP][2];
}
{
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][14] = SCAR[13].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((14 && SCBR[13].enq[CHIP]==SCBR[13].deq[CHIP]) || SCBR[13].deq[CHIP]!=SCBR[14].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[14].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM1[14].b[CHIP][0]) : SCM1[14].awoo[CHIP][0];
SCM1[14].o[CHIP][0] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][3] : SCM1[14].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[14].awoo[CHIP][0] = (Ull)(INIT0?SCM1[14].b[CHIP][0]:SCM1[14].awoo[CHIP][0]);
adr = (Uint)(SCM1[14].awoo[CHIP][0] + SCM1[14].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][1] = SCM1[14].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][1] = SCM1[14].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][1] = SCM1[14].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[14].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM0[14].b[CHIP][0]) : SCM0[14].awoo[CHIP][0];
SCM0[14].o[CHIP][0] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][3] : SCM0[14].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[14].awoo[CHIP][0] = (Ull)(INIT0?SCM0[14].b[CHIP][0]:SCM0[14].awoo[CHIP][0]);
adr = (Uint)(SCM0[14].awoo[CHIP][0] + SCM0[14].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0] = SCM0[14].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0] = SCM0[14].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0] = SCM0[14].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[14].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM1[14].b[CHIP][1]) : SCM1[14].awoo[CHIP][1];
SCM1[14].o[CHIP][1] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][3] : SCM1[14].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[14].awoo[CHIP][1] = (Ull)(INIT0?SCM1[14].b[CHIP][1]:SCM1[14].awoo[CHIP][1]);
adr = (Uint)(SCM1[14].awoo[CHIP][1] + SCM1[14].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][5] = SCM1[14].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][5] = SCM1[14].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][5] = SCM1[14].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[14].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM0[14].b[CHIP][1]) : SCM0[14].awoo[CHIP][1];
SCM0[14].o[CHIP][1] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][3] : SCM0[14].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[14].awoo[CHIP][1] = (Ull)(INIT0?SCM0[14].b[CHIP][1]:SCM0[14].awoo[CHIP][1]);
adr = (Uint)(SCM0[14].awoo[CHIP][1] + SCM0[14].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][4] = SCM0[14].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][4] = SCM0[14].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][4] = SCM0[14].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[14].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM1[14].b[CHIP][2]) : SCM1[14].awoo[CHIP][2];
SCM1[14].o[CHIP][2] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][7] : SCM1[14].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[14].awoo[CHIP][2] = (Ull)(INIT0?SCM1[14].b[CHIP][2]:SCM1[14].awoo[CHIP][2]);
adr = (Uint)(SCM1[14].awoo[CHIP][2] + SCM1[14].o[CHIP][2]);
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][2] : SCAR[14].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][9] : 0, 14);
ex3 = exm(SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][1], 14);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[14].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][6] : SCAR[14].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][9] : 0, 14);
ex3 = exm(SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][0], 14);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[14].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][10] : SCAR[14].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][9] : 0, 14);
ex3 = exm(SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][5], 14);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[14].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][14] : SCAR[14].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][9] : 0, 14);
ex3 = exm(SCBR[13].r[CHIP][SCBR[14].enq[CHIP]][4], 14);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[14].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][2] = SCAR[14].r[CHIP][0];
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][3] = SCBR[13].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][6] = SCAR[14].r[CHIP][1];
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][7] = SCBR[13].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][8] = SCBR[13].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][10] = SCAR[14].r[CHIP][2];
}
{
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][14] = SCAR[14].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((15 && SCBR[14].enq[CHIP]==SCBR[14].deq[CHIP]) || SCBR[14].deq[CHIP]!=SCBR[15].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[15].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM1[15].b[CHIP][0]) : SCM1[15].awoo[CHIP][0];
SCM1[15].o[CHIP][0] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][3] : SCM1[15].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[15].awoo[CHIP][0] = (Ull)(INIT0?SCM1[15].b[CHIP][0]:SCM1[15].awoo[CHIP][0]);
adr = (Uint)(SCM1[15].awoo[CHIP][0] + SCM1[15].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][1] = SCM1[15].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][1] = SCM1[15].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][1] = SCM1[15].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[15].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM0[15].b[CHIP][0]) : SCM0[15].awoo[CHIP][0];
SCM0[15].o[CHIP][0] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][3] : SCM0[15].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[15].awoo[CHIP][0] = (Ull)(INIT0?SCM0[15].b[CHIP][0]:SCM0[15].awoo[CHIP][0]);
adr = (Uint)(SCM0[15].awoo[CHIP][0] + SCM0[15].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0] = SCM0[15].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0] = SCM0[15].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0] = SCM0[15].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[15].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM1[15].b[CHIP][1]) : SCM1[15].awoo[CHIP][1];
SCM1[15].o[CHIP][1] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][3] : SCM1[15].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[15].awoo[CHIP][1] = (Ull)(INIT0?SCM1[15].b[CHIP][1]:SCM1[15].awoo[CHIP][1]);
adr = (Uint)(SCM1[15].awoo[CHIP][1] + SCM1[15].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][5] = SCM1[15].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][5] = SCM1[15].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][5] = SCM1[15].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[15].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM0[15].b[CHIP][1]) : SCM0[15].awoo[CHIP][1];
SCM0[15].o[CHIP][1] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][3] : SCM0[15].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[15].awoo[CHIP][1] = (Ull)(INIT0?SCM0[15].b[CHIP][1]:SCM0[15].awoo[CHIP][1]);
adr = (Uint)(SCM0[15].awoo[CHIP][1] + SCM0[15].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][4] = SCM0[15].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][4] = SCM0[15].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][4] = SCM0[15].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[15].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM1[15].b[CHIP][2]) : SCM1[15].awoo[CHIP][2];
SCM1[15].o[CHIP][2] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][7] : SCM1[15].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[15].awoo[CHIP][2] = (Ull)(INIT0?SCM1[15].b[CHIP][2]:SCM1[15].awoo[CHIP][2]);
adr = (Uint)(SCM1[15].awoo[CHIP][2] + SCM1[15].o[CHIP][2]);
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][2] : SCAR[15].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][9] : 0, 15);
ex3 = exm(SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][1], 15);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[15].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][6] : SCAR[15].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][9] : 0, 15);
ex3 = exm(SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][0], 15);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[15].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][10] : SCAR[15].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][9] : 0, 15);
ex3 = exm(SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][5], 15);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[15].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][14] : SCAR[15].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][9] : 0, 15);
ex3 = exm(SCBR[14].r[CHIP][SCBR[15].enq[CHIP]][4], 15);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[15].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][2] = SCAR[15].r[CHIP][0];
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][3] = SCBR[14].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][6] = SCAR[15].r[CHIP][1];
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][7] = SCBR[14].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][8] = SCBR[14].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][10] = SCAR[15].r[CHIP][2];
}
{
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][14] = SCAR[15].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((16 && SCBR[15].enq[CHIP]==SCBR[15].deq[CHIP]) || SCBR[15].deq[CHIP]!=SCBR[16].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[16].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM1[16].b[CHIP][0]) : SCM1[16].awoo[CHIP][0];
SCM1[16].o[CHIP][0] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][3] : SCM1[16].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[16].awoo[CHIP][0] = (Ull)(INIT0?SCM1[16].b[CHIP][0]:SCM1[16].awoo[CHIP][0]);
adr = (Uint)(SCM1[16].awoo[CHIP][0] + SCM1[16].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][1] = SCM1[16].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][1] = SCM1[16].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][1] = SCM1[16].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[16].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM0[16].b[CHIP][0]) : SCM0[16].awoo[CHIP][0];
SCM0[16].o[CHIP][0] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][3] : SCM0[16].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[16].awoo[CHIP][0] = (Ull)(INIT0?SCM0[16].b[CHIP][0]:SCM0[16].awoo[CHIP][0]);
adr = (Uint)(SCM0[16].awoo[CHIP][0] + SCM0[16].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0] = SCM0[16].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0] = SCM0[16].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0] = SCM0[16].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[16].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM1[16].b[CHIP][1]) : SCM1[16].awoo[CHIP][1];
SCM1[16].o[CHIP][1] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][3] : SCM1[16].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[16].awoo[CHIP][1] = (Ull)(INIT0?SCM1[16].b[CHIP][1]:SCM1[16].awoo[CHIP][1]);
adr = (Uint)(SCM1[16].awoo[CHIP][1] + SCM1[16].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][5] = SCM1[16].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][5] = SCM1[16].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][5] = SCM1[16].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[16].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM0[16].b[CHIP][1]) : SCM0[16].awoo[CHIP][1];
SCM0[16].o[CHIP][1] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][3] : SCM0[16].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[16].awoo[CHIP][1] = (Ull)(INIT0?SCM0[16].b[CHIP][1]:SCM0[16].awoo[CHIP][1]);
adr = (Uint)(SCM0[16].awoo[CHIP][1] + SCM0[16].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][4] = SCM0[16].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][4] = SCM0[16].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][4] = SCM0[16].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[16].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM1[16].b[CHIP][2]) : SCM1[16].awoo[CHIP][2];
SCM1[16].o[CHIP][2] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][7] : SCM1[16].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[16].awoo[CHIP][2] = (Ull)(INIT0?SCM1[16].b[CHIP][2]:SCM1[16].awoo[CHIP][2]);
adr = (Uint)(SCM1[16].awoo[CHIP][2] + SCM1[16].o[CHIP][2]);
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][2] : SCAR[16].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][9] : 0, 16);
ex3 = exm(SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][1], 16);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[16].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][6] : SCAR[16].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][9] : 0, 16);
ex3 = exm(SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][0], 16);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[16].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][10] : SCAR[16].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][9] : 0, 16);
ex3 = exm(SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][5], 16);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[16].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][14] : SCAR[16].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][9] : 0, 16);
ex3 = exm(SCBR[15].r[CHIP][SCBR[16].enq[CHIP]][4], 16);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[16].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][2] = SCAR[16].r[CHIP][0];
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][3] = SCBR[15].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][6] = SCAR[16].r[CHIP][1];
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][7] = SCBR[15].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][8] = SCBR[15].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][10] = SCAR[16].r[CHIP][2];
}
{
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][14] = SCAR[16].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((17 && SCBR[16].enq[CHIP]==SCBR[16].deq[CHIP]) || SCBR[16].deq[CHIP]!=SCBR[17].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[17].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM1[17].b[CHIP][0]) : SCM1[17].awoo[CHIP][0];
SCM1[17].o[CHIP][0] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][3] : SCM1[17].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[17].awoo[CHIP][0] = (Ull)(INIT0?SCM1[17].b[CHIP][0]:SCM1[17].awoo[CHIP][0]);
adr = (Uint)(SCM1[17].awoo[CHIP][0] + SCM1[17].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][1] = SCM1[17].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][1] = SCM1[17].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][1] = SCM1[17].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[17].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM0[17].b[CHIP][0]) : SCM0[17].awoo[CHIP][0];
SCM0[17].o[CHIP][0] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][3] : SCM0[17].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[17].awoo[CHIP][0] = (Ull)(INIT0?SCM0[17].b[CHIP][0]:SCM0[17].awoo[CHIP][0]);
adr = (Uint)(SCM0[17].awoo[CHIP][0] + SCM0[17].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0] = SCM0[17].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0] = SCM0[17].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0] = SCM0[17].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[17].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM1[17].b[CHIP][1]) : SCM1[17].awoo[CHIP][1];
SCM1[17].o[CHIP][1] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][3] : SCM1[17].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[17].awoo[CHIP][1] = (Ull)(INIT0?SCM1[17].b[CHIP][1]:SCM1[17].awoo[CHIP][1]);
adr = (Uint)(SCM1[17].awoo[CHIP][1] + SCM1[17].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][5] = SCM1[17].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][5] = SCM1[17].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][5] = SCM1[17].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[17].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM0[17].b[CHIP][1]) : SCM0[17].awoo[CHIP][1];
SCM0[17].o[CHIP][1] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][3] : SCM0[17].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[17].awoo[CHIP][1] = (Ull)(INIT0?SCM0[17].b[CHIP][1]:SCM0[17].awoo[CHIP][1]);
adr = (Uint)(SCM0[17].awoo[CHIP][1] + SCM0[17].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][4] = SCM0[17].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][4] = SCM0[17].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][4] = SCM0[17].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[17].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM1[17].b[CHIP][2]) : SCM1[17].awoo[CHIP][2];
SCM1[17].o[CHIP][2] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][7] : SCM1[17].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[17].awoo[CHIP][2] = (Ull)(INIT0?SCM1[17].b[CHIP][2]:SCM1[17].awoo[CHIP][2]);
adr = (Uint)(SCM1[17].awoo[CHIP][2] + SCM1[17].o[CHIP][2]);
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][2] : SCAR[17].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][9] : 0, 17);
ex3 = exm(SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][1], 17);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[17].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][6] : SCAR[17].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][9] : 0, 17);
ex3 = exm(SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][0], 17);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[17].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][10] : SCAR[17].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][9] : 0, 17);
ex3 = exm(SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][5], 17);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[17].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][14] : SCAR[17].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][9] : 0, 17);
ex3 = exm(SCBR[16].r[CHIP][SCBR[17].enq[CHIP]][4], 17);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[17].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][2] = SCAR[17].r[CHIP][0];
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][3] = SCBR[16].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][6] = SCAR[17].r[CHIP][1];
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][7] = SCBR[16].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][8] = SCBR[16].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][10] = SCAR[17].r[CHIP][2];
}
{
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][14] = SCAR[17].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((18 && SCBR[17].enq[CHIP]==SCBR[17].deq[CHIP]) || SCBR[17].deq[CHIP]!=SCBR[18].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[18].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM1[18].b[CHIP][0]) : SCM1[18].awoo[CHIP][0];
SCM1[18].o[CHIP][0] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][3] : SCM1[18].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[18].awoo[CHIP][0] = (Ull)(INIT0?SCM1[18].b[CHIP][0]:SCM1[18].awoo[CHIP][0]);
adr = (Uint)(SCM1[18].awoo[CHIP][0] + SCM1[18].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][1] = SCM1[18].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][1] = SCM1[18].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][1] = SCM1[18].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[18].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM0[18].b[CHIP][0]) : SCM0[18].awoo[CHIP][0];
SCM0[18].o[CHIP][0] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][3] : SCM0[18].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[18].awoo[CHIP][0] = (Ull)(INIT0?SCM0[18].b[CHIP][0]:SCM0[18].awoo[CHIP][0]);
adr = (Uint)(SCM0[18].awoo[CHIP][0] + SCM0[18].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0] = SCM0[18].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0] = SCM0[18].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0] = SCM0[18].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[18].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM1[18].b[CHIP][1]) : SCM1[18].awoo[CHIP][1];
SCM1[18].o[CHIP][1] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][3] : SCM1[18].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[18].awoo[CHIP][1] = (Ull)(INIT0?SCM1[18].b[CHIP][1]:SCM1[18].awoo[CHIP][1]);
adr = (Uint)(SCM1[18].awoo[CHIP][1] + SCM1[18].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][5] = SCM1[18].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][5] = SCM1[18].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][5] = SCM1[18].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[18].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM0[18].b[CHIP][1]) : SCM0[18].awoo[CHIP][1];
SCM0[18].o[CHIP][1] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][3] : SCM0[18].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[18].awoo[CHIP][1] = (Ull)(INIT0?SCM0[18].b[CHIP][1]:SCM0[18].awoo[CHIP][1]);
adr = (Uint)(SCM0[18].awoo[CHIP][1] + SCM0[18].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][4] = SCM0[18].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][4] = SCM0[18].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][4] = SCM0[18].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[18].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM1[18].b[CHIP][2]) : SCM1[18].awoo[CHIP][2];
SCM1[18].o[CHIP][2] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][7] : SCM1[18].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[18].awoo[CHIP][2] = (Ull)(INIT0?SCM1[18].b[CHIP][2]:SCM1[18].awoo[CHIP][2]);
adr = (Uint)(SCM1[18].awoo[CHIP][2] + SCM1[18].o[CHIP][2]);
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][2] : SCAR[18].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][9] : 0, 18);
ex3 = exm(SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][1], 18);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[18].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][6] : SCAR[18].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][9] : 0, 18);
ex3 = exm(SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][0], 18);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[18].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][10] : SCAR[18].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][9] : 0, 18);
ex3 = exm(SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][5], 18);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[18].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][14] : SCAR[18].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][9] : 0, 18);
ex3 = exm(SCBR[17].r[CHIP][SCBR[18].enq[CHIP]][4], 18);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[18].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][2] = SCAR[18].r[CHIP][0];
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][3] = SCBR[17].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][6] = SCAR[18].r[CHIP][1];
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][7] = SCBR[17].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][8] = SCBR[17].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][10] = SCAR[18].r[CHIP][2];
}
{
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][14] = SCAR[18].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((19 && SCBR[18].enq[CHIP]==SCBR[18].deq[CHIP]) || SCBR[18].deq[CHIP]!=SCBR[19].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[19].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM1[19].b[CHIP][0]) : SCM1[19].awoo[CHIP][0];
SCM1[19].o[CHIP][0] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][3] : SCM1[19].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[19].awoo[CHIP][0] = (Ull)(INIT0?SCM1[19].b[CHIP][0]:SCM1[19].awoo[CHIP][0]);
adr = (Uint)(SCM1[19].awoo[CHIP][0] + SCM1[19].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][1] = SCM1[19].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][1] = SCM1[19].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][1] = SCM1[19].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[19].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM0[19].b[CHIP][0]) : SCM0[19].awoo[CHIP][0];
SCM0[19].o[CHIP][0] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][3] : SCM0[19].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[19].awoo[CHIP][0] = (Ull)(INIT0?SCM0[19].b[CHIP][0]:SCM0[19].awoo[CHIP][0]);
adr = (Uint)(SCM0[19].awoo[CHIP][0] + SCM0[19].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0] = SCM0[19].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0] = SCM0[19].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0] = SCM0[19].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[19].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM1[19].b[CHIP][1]) : SCM1[19].awoo[CHIP][1];
SCM1[19].o[CHIP][1] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][3] : SCM1[19].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[19].awoo[CHIP][1] = (Ull)(INIT0?SCM1[19].b[CHIP][1]:SCM1[19].awoo[CHIP][1]);
adr = (Uint)(SCM1[19].awoo[CHIP][1] + SCM1[19].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][5] = SCM1[19].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][5] = SCM1[19].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][5] = SCM1[19].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[19].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM0[19].b[CHIP][1]) : SCM0[19].awoo[CHIP][1];
SCM0[19].o[CHIP][1] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][3] : SCM0[19].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[19].awoo[CHIP][1] = (Ull)(INIT0?SCM0[19].b[CHIP][1]:SCM0[19].awoo[CHIP][1]);
adr = (Uint)(SCM0[19].awoo[CHIP][1] + SCM0[19].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][4] = SCM0[19].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][4] = SCM0[19].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][4] = SCM0[19].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[19].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM1[19].b[CHIP][2]) : SCM1[19].awoo[CHIP][2];
SCM1[19].o[CHIP][2] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][7] : SCM1[19].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[19].awoo[CHIP][2] = (Ull)(INIT0?SCM1[19].b[CHIP][2]:SCM1[19].awoo[CHIP][2]);
adr = (Uint)(SCM1[19].awoo[CHIP][2] + SCM1[19].o[CHIP][2]);
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][2] : SCAR[19].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][9] : 0, 19);
ex3 = exm(SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][1], 19);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[19].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][6] : SCAR[19].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][9] : 0, 19);
ex3 = exm(SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][0], 19);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[19].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][10] : SCAR[19].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][9] : 0, 19);
ex3 = exm(SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][5], 19);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[19].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][14] : SCAR[19].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][9] : 0, 19);
ex3 = exm(SCBR[18].r[CHIP][SCBR[19].enq[CHIP]][4], 19);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[19].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][2] = SCAR[19].r[CHIP][0];
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][3] = SCBR[18].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][6] = SCAR[19].r[CHIP][1];
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][7] = SCBR[18].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][8] = SCBR[18].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][10] = SCAR[19].r[CHIP][2];
}
{
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][14] = SCAR[19].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((20 && SCBR[19].enq[CHIP]==SCBR[19].deq[CHIP]) || SCBR[19].deq[CHIP]!=SCBR[20].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[20].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM1[20].b[CHIP][0]) : SCM1[20].awoo[CHIP][0];
SCM1[20].o[CHIP][0] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][3] : SCM1[20].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[20].awoo[CHIP][0] = (Ull)(INIT0?SCM1[20].b[CHIP][0]:SCM1[20].awoo[CHIP][0]);
adr = (Uint)(SCM1[20].awoo[CHIP][0] + SCM1[20].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][1] = SCM1[20].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][1] = SCM1[20].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][1] = SCM1[20].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[20].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM0[20].b[CHIP][0]) : SCM0[20].awoo[CHIP][0];
SCM0[20].o[CHIP][0] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][3] : SCM0[20].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[20].awoo[CHIP][0] = (Ull)(INIT0?SCM0[20].b[CHIP][0]:SCM0[20].awoo[CHIP][0]);
adr = (Uint)(SCM0[20].awoo[CHIP][0] + SCM0[20].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0] = SCM0[20].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0] = SCM0[20].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0] = SCM0[20].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[20].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM1[20].b[CHIP][1]) : SCM1[20].awoo[CHIP][1];
SCM1[20].o[CHIP][1] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][3] : SCM1[20].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[20].awoo[CHIP][1] = (Ull)(INIT0?SCM1[20].b[CHIP][1]:SCM1[20].awoo[CHIP][1]);
adr = (Uint)(SCM1[20].awoo[CHIP][1] + SCM1[20].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][5] = SCM1[20].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][5] = SCM1[20].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][5] = SCM1[20].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[20].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM0[20].b[CHIP][1]) : SCM0[20].awoo[CHIP][1];
SCM0[20].o[CHIP][1] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][3] : SCM0[20].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[20].awoo[CHIP][1] = (Ull)(INIT0?SCM0[20].b[CHIP][1]:SCM0[20].awoo[CHIP][1]);
adr = (Uint)(SCM0[20].awoo[CHIP][1] + SCM0[20].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][4] = SCM0[20].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][4] = SCM0[20].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][4] = SCM0[20].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[20].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM1[20].b[CHIP][2]) : SCM1[20].awoo[CHIP][2];
SCM1[20].o[CHIP][2] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][7] : SCM1[20].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[20].awoo[CHIP][2] = (Ull)(INIT0?SCM1[20].b[CHIP][2]:SCM1[20].awoo[CHIP][2]);
adr = (Uint)(SCM1[20].awoo[CHIP][2] + SCM1[20].o[CHIP][2]);
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][2] : SCAR[20].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][9] : 0, 20);
ex3 = exm(SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][1], 20);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[20].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][6] : SCAR[20].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][9] : 0, 20);
ex3 = exm(SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][0], 20);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[20].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][10] : SCAR[20].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][9] : 0, 20);
ex3 = exm(SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][5], 20);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[20].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][14] : SCAR[20].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][9] : 0, 20);
ex3 = exm(SCBR[19].r[CHIP][SCBR[20].enq[CHIP]][4], 20);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[20].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][2] = SCAR[20].r[CHIP][0];
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][3] = SCBR[19].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][6] = SCAR[20].r[CHIP][1];
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][7] = SCBR[19].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][8] = SCBR[19].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][10] = SCAR[20].r[CHIP][2];
}
{
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][14] = SCAR[20].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((21 && SCBR[20].enq[CHIP]==SCBR[20].deq[CHIP]) || SCBR[20].deq[CHIP]!=SCBR[21].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[21].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM1[21].b[CHIP][0]) : SCM1[21].awoo[CHIP][0];
SCM1[21].o[CHIP][0] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][3] : SCM1[21].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[21].awoo[CHIP][0] = (Ull)(INIT0?SCM1[21].b[CHIP][0]:SCM1[21].awoo[CHIP][0]);
adr = (Uint)(SCM1[21].awoo[CHIP][0] + SCM1[21].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][1] = SCM1[21].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][1] = SCM1[21].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][1] = SCM1[21].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[21].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM0[21].b[CHIP][0]) : SCM0[21].awoo[CHIP][0];
SCM0[21].o[CHIP][0] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][3] : SCM0[21].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[21].awoo[CHIP][0] = (Ull)(INIT0?SCM0[21].b[CHIP][0]:SCM0[21].awoo[CHIP][0]);
adr = (Uint)(SCM0[21].awoo[CHIP][0] + SCM0[21].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0] = SCM0[21].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0] = SCM0[21].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0] = SCM0[21].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[21].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM1[21].b[CHIP][1]) : SCM1[21].awoo[CHIP][1];
SCM1[21].o[CHIP][1] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][3] : SCM1[21].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[21].awoo[CHIP][1] = (Ull)(INIT0?SCM1[21].b[CHIP][1]:SCM1[21].awoo[CHIP][1]);
adr = (Uint)(SCM1[21].awoo[CHIP][1] + SCM1[21].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][5] = SCM1[21].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][5] = SCM1[21].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][5] = SCM1[21].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[21].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM0[21].b[CHIP][1]) : SCM0[21].awoo[CHIP][1];
SCM0[21].o[CHIP][1] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][3] : SCM0[21].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[21].awoo[CHIP][1] = (Ull)(INIT0?SCM0[21].b[CHIP][1]:SCM0[21].awoo[CHIP][1]);
adr = (Uint)(SCM0[21].awoo[CHIP][1] + SCM0[21].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][4] = SCM0[21].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][4] = SCM0[21].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][4] = SCM0[21].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[21].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM1[21].b[CHIP][2]) : SCM1[21].awoo[CHIP][2];
SCM1[21].o[CHIP][2] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][7] : SCM1[21].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[21].awoo[CHIP][2] = (Ull)(INIT0?SCM1[21].b[CHIP][2]:SCM1[21].awoo[CHIP][2]);
adr = (Uint)(SCM1[21].awoo[CHIP][2] + SCM1[21].o[CHIP][2]);
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][2] : SCAR[21].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][9] : 0, 21);
ex3 = exm(SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][1], 21);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[21].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][6] : SCAR[21].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][9] : 0, 21);
ex3 = exm(SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][0], 21);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[21].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][10] : SCAR[21].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][9] : 0, 21);
ex3 = exm(SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][5], 21);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[21].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][14] : SCAR[21].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][9] : 0, 21);
ex3 = exm(SCBR[20].r[CHIP][SCBR[21].enq[CHIP]][4], 21);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[21].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][2] = SCAR[21].r[CHIP][0];
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][3] = SCBR[20].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][6] = SCAR[21].r[CHIP][1];
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][7] = SCBR[20].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][8] = SCBR[20].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][10] = SCAR[21].r[CHIP][2];
}
{
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][14] = SCAR[21].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((22 && SCBR[21].enq[CHIP]==SCBR[21].deq[CHIP]) || SCBR[21].deq[CHIP]!=SCBR[22].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[22].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM1[22].b[CHIP][0]) : SCM1[22].awoo[CHIP][0];
SCM1[22].o[CHIP][0] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][3] : SCM1[22].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[22].awoo[CHIP][0] = (Ull)(INIT0?SCM1[22].b[CHIP][0]:SCM1[22].awoo[CHIP][0]);
adr = (Uint)(SCM1[22].awoo[CHIP][0] + SCM1[22].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][1] = SCM1[22].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][1] = SCM1[22].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][1] = SCM1[22].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[22].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM0[22].b[CHIP][0]) : SCM0[22].awoo[CHIP][0];
SCM0[22].o[CHIP][0] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][3] : SCM0[22].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[22].awoo[CHIP][0] = (Ull)(INIT0?SCM0[22].b[CHIP][0]:SCM0[22].awoo[CHIP][0]);
adr = (Uint)(SCM0[22].awoo[CHIP][0] + SCM0[22].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0] = SCM0[22].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0] = SCM0[22].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0] = SCM0[22].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[22].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM1[22].b[CHIP][1]) : SCM1[22].awoo[CHIP][1];
SCM1[22].o[CHIP][1] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][3] : SCM1[22].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[22].awoo[CHIP][1] = (Ull)(INIT0?SCM1[22].b[CHIP][1]:SCM1[22].awoo[CHIP][1]);
adr = (Uint)(SCM1[22].awoo[CHIP][1] + SCM1[22].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][5] = SCM1[22].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][5] = SCM1[22].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][5] = SCM1[22].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[22].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM0[22].b[CHIP][1]) : SCM0[22].awoo[CHIP][1];
SCM0[22].o[CHIP][1] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][3] : SCM0[22].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[22].awoo[CHIP][1] = (Ull)(INIT0?SCM0[22].b[CHIP][1]:SCM0[22].awoo[CHIP][1]);
adr = (Uint)(SCM0[22].awoo[CHIP][1] + SCM0[22].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][4] = SCM0[22].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][4] = SCM0[22].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][4] = SCM0[22].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[22].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM1[22].b[CHIP][2]) : SCM1[22].awoo[CHIP][2];
SCM1[22].o[CHIP][2] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][7] : SCM1[22].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[22].awoo[CHIP][2] = (Ull)(INIT0?SCM1[22].b[CHIP][2]:SCM1[22].awoo[CHIP][2]);
adr = (Uint)(SCM1[22].awoo[CHIP][2] + SCM1[22].o[CHIP][2]);
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][2] : SCAR[22].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][9] : 0, 22);
ex3 = exm(SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][1], 22);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[22].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][6] : SCAR[22].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][9] : 0, 22);
ex3 = exm(SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][0], 22);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[22].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][10] : SCAR[22].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][9] : 0, 22);
ex3 = exm(SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][5], 22);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[22].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][14] : SCAR[22].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][9] : 0, 22);
ex3 = exm(SCBR[21].r[CHIP][SCBR[22].enq[CHIP]][4], 22);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[22].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][2] = SCAR[22].r[CHIP][0];
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][3] = SCBR[21].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][6] = SCAR[22].r[CHIP][1];
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][7] = SCBR[21].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][8] = SCBR[21].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][10] = SCAR[22].r[CHIP][2];
}
{
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][14] = SCAR[22].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((23 && SCBR[22].enq[CHIP]==SCBR[22].deq[CHIP]) || SCBR[22].deq[CHIP]!=SCBR[23].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[23].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM1[23].b[CHIP][0]) : SCM1[23].awoo[CHIP][0];
SCM1[23].o[CHIP][0] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][3] : SCM1[23].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[23].awoo[CHIP][0] = (Ull)(INIT0?SCM1[23].b[CHIP][0]:SCM1[23].awoo[CHIP][0]);
adr = (Uint)(SCM1[23].awoo[CHIP][0] + SCM1[23].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][1] = SCM1[23].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][1] = SCM1[23].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][1] = SCM1[23].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[23].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM0[23].b[CHIP][0]) : SCM0[23].awoo[CHIP][0];
SCM0[23].o[CHIP][0] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][3] : SCM0[23].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[23].awoo[CHIP][0] = (Ull)(INIT0?SCM0[23].b[CHIP][0]:SCM0[23].awoo[CHIP][0]);
adr = (Uint)(SCM0[23].awoo[CHIP][0] + SCM0[23].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0] = SCM0[23].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0] = SCM0[23].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0] = SCM0[23].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[23].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM1[23].b[CHIP][1]) : SCM1[23].awoo[CHIP][1];
SCM1[23].o[CHIP][1] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][3] : SCM1[23].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[23].awoo[CHIP][1] = (Ull)(INIT0?SCM1[23].b[CHIP][1]:SCM1[23].awoo[CHIP][1]);
adr = (Uint)(SCM1[23].awoo[CHIP][1] + SCM1[23].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][5] = SCM1[23].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][5] = SCM1[23].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][5] = SCM1[23].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[23].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM0[23].b[CHIP][1]) : SCM0[23].awoo[CHIP][1];
SCM0[23].o[CHIP][1] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][3] : SCM0[23].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[23].awoo[CHIP][1] = (Ull)(INIT0?SCM0[23].b[CHIP][1]:SCM0[23].awoo[CHIP][1]);
adr = (Uint)(SCM0[23].awoo[CHIP][1] + SCM0[23].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][4] = SCM0[23].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][4] = SCM0[23].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][4] = SCM0[23].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[23].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM1[23].b[CHIP][2]) : SCM1[23].awoo[CHIP][2];
SCM1[23].o[CHIP][2] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][7] : SCM1[23].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[23].awoo[CHIP][2] = (Ull)(INIT0?SCM1[23].b[CHIP][2]:SCM1[23].awoo[CHIP][2]);
adr = (Uint)(SCM1[23].awoo[CHIP][2] + SCM1[23].o[CHIP][2]);
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][2] : SCAR[23].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][9] : 0, 23);
ex3 = exm(SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][1], 23);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[23].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][6] : SCAR[23].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][9] : 0, 23);
ex3 = exm(SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][0], 23);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[23].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][10] : SCAR[23].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][9] : 0, 23);
ex3 = exm(SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][5], 23);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[23].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][14] : SCAR[23].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][9] : 0, 23);
ex3 = exm(SCBR[22].r[CHIP][SCBR[23].enq[CHIP]][4], 23);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[23].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][2] = SCAR[23].r[CHIP][0];
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][3] = SCBR[22].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][6] = SCAR[23].r[CHIP][1];
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][7] = SCBR[22].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][8] = SCBR[22].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][10] = SCAR[23].r[CHIP][2];
}
{
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][14] = SCAR[23].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((24 && SCBR[23].enq[CHIP]==SCBR[23].deq[CHIP]) || SCBR[23].deq[CHIP]!=SCBR[24].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[24].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM1[24].b[CHIP][0]) : SCM1[24].awoo[CHIP][0];
SCM1[24].o[CHIP][0] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][3] : SCM1[24].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[24].awoo[CHIP][0] = (Ull)(INIT0?SCM1[24].b[CHIP][0]:SCM1[24].awoo[CHIP][0]);
adr = (Uint)(SCM1[24].awoo[CHIP][0] + SCM1[24].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][1] = SCM1[24].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][1] = SCM1[24].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][1] = SCM1[24].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[24].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM0[24].b[CHIP][0]) : SCM0[24].awoo[CHIP][0];
SCM0[24].o[CHIP][0] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][3] : SCM0[24].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[24].awoo[CHIP][0] = (Ull)(INIT0?SCM0[24].b[CHIP][0]:SCM0[24].awoo[CHIP][0]);
adr = (Uint)(SCM0[24].awoo[CHIP][0] + SCM0[24].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0] = SCM0[24].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0] = SCM0[24].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0] = SCM0[24].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[24].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM1[24].b[CHIP][1]) : SCM1[24].awoo[CHIP][1];
SCM1[24].o[CHIP][1] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][3] : SCM1[24].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[24].awoo[CHIP][1] = (Ull)(INIT0?SCM1[24].b[CHIP][1]:SCM1[24].awoo[CHIP][1]);
adr = (Uint)(SCM1[24].awoo[CHIP][1] + SCM1[24].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][5] = SCM1[24].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][5] = SCM1[24].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][5] = SCM1[24].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[24].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM0[24].b[CHIP][1]) : SCM0[24].awoo[CHIP][1];
SCM0[24].o[CHIP][1] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][3] : SCM0[24].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[24].awoo[CHIP][1] = (Ull)(INIT0?SCM0[24].b[CHIP][1]:SCM0[24].awoo[CHIP][1]);
adr = (Uint)(SCM0[24].awoo[CHIP][1] + SCM0[24].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][4] = SCM0[24].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][4] = SCM0[24].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][4] = SCM0[24].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[24].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM1[24].b[CHIP][2]) : SCM1[24].awoo[CHIP][2];
SCM1[24].o[CHIP][2] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][7] : SCM1[24].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[24].awoo[CHIP][2] = (Ull)(INIT0?SCM1[24].b[CHIP][2]:SCM1[24].awoo[CHIP][2]);
adr = (Uint)(SCM1[24].awoo[CHIP][2] + SCM1[24].o[CHIP][2]);
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][2] : SCAR[24].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][9] : 0, 24);
ex3 = exm(SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][1], 24);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[24].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][6] : SCAR[24].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][9] : 0, 24);
ex3 = exm(SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][0], 24);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[24].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][10] : SCAR[24].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][9] : 0, 24);
ex3 = exm(SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][5], 24);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[24].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][14] : SCAR[24].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][9] : 0, 24);
ex3 = exm(SCBR[23].r[CHIP][SCBR[24].enq[CHIP]][4], 24);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[24].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][2] = SCAR[24].r[CHIP][0];
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][3] = SCBR[23].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][6] = SCAR[24].r[CHIP][1];
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][7] = SCBR[23].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][8] = SCBR[23].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][10] = SCAR[24].r[CHIP][2];
}
{
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][14] = SCAR[24].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((25 && SCBR[24].enq[CHIP]==SCBR[24].deq[CHIP]) || SCBR[24].deq[CHIP]!=SCBR[25].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[25].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM1[25].b[CHIP][0]) : SCM1[25].awoo[CHIP][0];
SCM1[25].o[CHIP][0] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][3] : SCM1[25].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[25].awoo[CHIP][0] = (Ull)(INIT0?SCM1[25].b[CHIP][0]:SCM1[25].awoo[CHIP][0]);
adr = (Uint)(SCM1[25].awoo[CHIP][0] + SCM1[25].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][1] = SCM1[25].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][1] = SCM1[25].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][1] = SCM1[25].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[25].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM0[25].b[CHIP][0]) : SCM0[25].awoo[CHIP][0];
SCM0[25].o[CHIP][0] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][3] : SCM0[25].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[25].awoo[CHIP][0] = (Ull)(INIT0?SCM0[25].b[CHIP][0]:SCM0[25].awoo[CHIP][0]);
adr = (Uint)(SCM0[25].awoo[CHIP][0] + SCM0[25].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0] = SCM0[25].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0] = SCM0[25].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0] = SCM0[25].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[25].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM1[25].b[CHIP][1]) : SCM1[25].awoo[CHIP][1];
SCM1[25].o[CHIP][1] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][3] : SCM1[25].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[25].awoo[CHIP][1] = (Ull)(INIT0?SCM1[25].b[CHIP][1]:SCM1[25].awoo[CHIP][1]);
adr = (Uint)(SCM1[25].awoo[CHIP][1] + SCM1[25].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][5] = SCM1[25].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][5] = SCM1[25].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][5] = SCM1[25].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[25].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM0[25].b[CHIP][1]) : SCM0[25].awoo[CHIP][1];
SCM0[25].o[CHIP][1] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][3] : SCM0[25].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[25].awoo[CHIP][1] = (Ull)(INIT0?SCM0[25].b[CHIP][1]:SCM0[25].awoo[CHIP][1]);
adr = (Uint)(SCM0[25].awoo[CHIP][1] + SCM0[25].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][4] = SCM0[25].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][4] = SCM0[25].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][4] = SCM0[25].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[25].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM1[25].b[CHIP][2]) : SCM1[25].awoo[CHIP][2];
SCM1[25].o[CHIP][2] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][7] : SCM1[25].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[25].awoo[CHIP][2] = (Ull)(INIT0?SCM1[25].b[CHIP][2]:SCM1[25].awoo[CHIP][2]);
adr = (Uint)(SCM1[25].awoo[CHIP][2] + SCM1[25].o[CHIP][2]);
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][2] : SCAR[25].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][9] : 0, 25);
ex3 = exm(SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][1], 25);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[25].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][6] : SCAR[25].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][9] : 0, 25);
ex3 = exm(SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][0], 25);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[25].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][10] : SCAR[25].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][9] : 0, 25);
ex3 = exm(SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][5], 25);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[25].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][14] : SCAR[25].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][9] : 0, 25);
ex3 = exm(SCBR[24].r[CHIP][SCBR[25].enq[CHIP]][4], 25);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[25].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][2] = SCAR[25].r[CHIP][0];
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][3] = SCBR[24].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][6] = SCAR[25].r[CHIP][1];
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][7] = SCBR[24].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][8] = SCBR[24].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][10] = SCAR[25].r[CHIP][2];
}
{
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][14] = SCAR[25].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((26 && SCBR[25].enq[CHIP]==SCBR[25].deq[CHIP]) || SCBR[25].deq[CHIP]!=SCBR[26].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[26].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM1[26].b[CHIP][0]) : SCM1[26].awoo[CHIP][0];
SCM1[26].o[CHIP][0] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][3] : SCM1[26].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[26].awoo[CHIP][0] = (Ull)(INIT0?SCM1[26].b[CHIP][0]:SCM1[26].awoo[CHIP][0]);
adr = (Uint)(SCM1[26].awoo[CHIP][0] + SCM1[26].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][1] = SCM1[26].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][1] = SCM1[26].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][1] = SCM1[26].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[26].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM0[26].b[CHIP][0]) : SCM0[26].awoo[CHIP][0];
SCM0[26].o[CHIP][0] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][3] : SCM0[26].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[26].awoo[CHIP][0] = (Ull)(INIT0?SCM0[26].b[CHIP][0]:SCM0[26].awoo[CHIP][0]);
adr = (Uint)(SCM0[26].awoo[CHIP][0] + SCM0[26].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0] = SCM0[26].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0] = SCM0[26].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0] = SCM0[26].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[26].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM1[26].b[CHIP][1]) : SCM1[26].awoo[CHIP][1];
SCM1[26].o[CHIP][1] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][3] : SCM1[26].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[26].awoo[CHIP][1] = (Ull)(INIT0?SCM1[26].b[CHIP][1]:SCM1[26].awoo[CHIP][1]);
adr = (Uint)(SCM1[26].awoo[CHIP][1] + SCM1[26].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][5] = SCM1[26].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][5] = SCM1[26].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][5] = SCM1[26].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[26].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM0[26].b[CHIP][1]) : SCM0[26].awoo[CHIP][1];
SCM0[26].o[CHIP][1] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][3] : SCM0[26].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[26].awoo[CHIP][1] = (Ull)(INIT0?SCM0[26].b[CHIP][1]:SCM0[26].awoo[CHIP][1]);
adr = (Uint)(SCM0[26].awoo[CHIP][1] + SCM0[26].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][4] = SCM0[26].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][4] = SCM0[26].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][4] = SCM0[26].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[26].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM1[26].b[CHIP][2]) : SCM1[26].awoo[CHIP][2];
SCM1[26].o[CHIP][2] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][7] : SCM1[26].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[26].awoo[CHIP][2] = (Ull)(INIT0?SCM1[26].b[CHIP][2]:SCM1[26].awoo[CHIP][2]);
adr = (Uint)(SCM1[26].awoo[CHIP][2] + SCM1[26].o[CHIP][2]);
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][2] : SCAR[26].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][9] : 0, 26);
ex3 = exm(SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][1], 26);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[26].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][6] : SCAR[26].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][9] : 0, 26);
ex3 = exm(SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][0], 26);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[26].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][10] : SCAR[26].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][9] : 0, 26);
ex3 = exm(SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][5], 26);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[26].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][14] : SCAR[26].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][9] : 0, 26);
ex3 = exm(SCBR[25].r[CHIP][SCBR[26].enq[CHIP]][4], 26);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[26].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][2] = SCAR[26].r[CHIP][0];
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][3] = SCBR[25].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][6] = SCAR[26].r[CHIP][1];
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][7] = SCBR[25].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][8] = SCBR[25].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][10] = SCAR[26].r[CHIP][2];
}
{
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][14] = SCAR[26].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((27 && SCBR[26].enq[CHIP]==SCBR[26].deq[CHIP]) || SCBR[26].deq[CHIP]!=SCBR[27].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[27].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM1[27].b[CHIP][0]) : SCM1[27].awoo[CHIP][0];
SCM1[27].o[CHIP][0] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][3] : SCM1[27].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[27].awoo[CHIP][0] = (Ull)(INIT0?SCM1[27].b[CHIP][0]:SCM1[27].awoo[CHIP][0]);
adr = (Uint)(SCM1[27].awoo[CHIP][0] + SCM1[27].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][1] = SCM1[27].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][1] = SCM1[27].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][1] = SCM1[27].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[27].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM0[27].b[CHIP][0]) : SCM0[27].awoo[CHIP][0];
SCM0[27].o[CHIP][0] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][3] : SCM0[27].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[27].awoo[CHIP][0] = (Ull)(INIT0?SCM0[27].b[CHIP][0]:SCM0[27].awoo[CHIP][0]);
adr = (Uint)(SCM0[27].awoo[CHIP][0] + SCM0[27].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0] = SCM0[27].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0] = SCM0[27].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0] = SCM0[27].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[27].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM1[27].b[CHIP][1]) : SCM1[27].awoo[CHIP][1];
SCM1[27].o[CHIP][1] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][3] : SCM1[27].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[27].awoo[CHIP][1] = (Ull)(INIT0?SCM1[27].b[CHIP][1]:SCM1[27].awoo[CHIP][1]);
adr = (Uint)(SCM1[27].awoo[CHIP][1] + SCM1[27].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][5] = SCM1[27].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][5] = SCM1[27].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][5] = SCM1[27].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[27].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM0[27].b[CHIP][1]) : SCM0[27].awoo[CHIP][1];
SCM0[27].o[CHIP][1] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][3] : SCM0[27].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[27].awoo[CHIP][1] = (Ull)(INIT0?SCM0[27].b[CHIP][1]:SCM0[27].awoo[CHIP][1]);
adr = (Uint)(SCM0[27].awoo[CHIP][1] + SCM0[27].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][4] = SCM0[27].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][4] = SCM0[27].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][4] = SCM0[27].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[27].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM1[27].b[CHIP][2]) : SCM1[27].awoo[CHIP][2];
SCM1[27].o[CHIP][2] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][7] : SCM1[27].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[27].awoo[CHIP][2] = (Ull)(INIT0?SCM1[27].b[CHIP][2]:SCM1[27].awoo[CHIP][2]);
adr = (Uint)(SCM1[27].awoo[CHIP][2] + SCM1[27].o[CHIP][2]);
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][2] : SCAR[27].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][9] : 0, 27);
ex3 = exm(SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][1], 27);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[27].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][6] : SCAR[27].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][9] : 0, 27);
ex3 = exm(SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][0], 27);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[27].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][10] : SCAR[27].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][9] : 0, 27);
ex3 = exm(SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][5], 27);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[27].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][14] : SCAR[27].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][9] : 0, 27);
ex3 = exm(SCBR[26].r[CHIP][SCBR[27].enq[CHIP]][4], 27);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[27].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][2] = SCAR[27].r[CHIP][0];
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][3] = SCBR[26].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][6] = SCAR[27].r[CHIP][1];
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][7] = SCBR[26].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][8] = SCBR[26].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][10] = SCAR[27].r[CHIP][2];
}
{
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][14] = SCAR[27].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((28 && SCBR[27].enq[CHIP]==SCBR[27].deq[CHIP]) || SCBR[27].deq[CHIP]!=SCBR[28].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[28].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM1[28].b[CHIP][0]) : SCM1[28].awoo[CHIP][0];
SCM1[28].o[CHIP][0] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][3] : SCM1[28].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[28].awoo[CHIP][0] = (Ull)(INIT0?SCM1[28].b[CHIP][0]:SCM1[28].awoo[CHIP][0]);
adr = (Uint)(SCM1[28].awoo[CHIP][0] + SCM1[28].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][1] = SCM1[28].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][1] = SCM1[28].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][1] = SCM1[28].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[28].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM0[28].b[CHIP][0]) : SCM0[28].awoo[CHIP][0];
SCM0[28].o[CHIP][0] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][3] : SCM0[28].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[28].awoo[CHIP][0] = (Ull)(INIT0?SCM0[28].b[CHIP][0]:SCM0[28].awoo[CHIP][0]);
adr = (Uint)(SCM0[28].awoo[CHIP][0] + SCM0[28].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0] = SCM0[28].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0] = SCM0[28].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0] = SCM0[28].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[28].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM1[28].b[CHIP][1]) : SCM1[28].awoo[CHIP][1];
SCM1[28].o[CHIP][1] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][3] : SCM1[28].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[28].awoo[CHIP][1] = (Ull)(INIT0?SCM1[28].b[CHIP][1]:SCM1[28].awoo[CHIP][1]);
adr = (Uint)(SCM1[28].awoo[CHIP][1] + SCM1[28].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][5] = SCM1[28].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][5] = SCM1[28].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][5] = SCM1[28].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[28].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM0[28].b[CHIP][1]) : SCM0[28].awoo[CHIP][1];
SCM0[28].o[CHIP][1] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][3] : SCM0[28].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[28].awoo[CHIP][1] = (Ull)(INIT0?SCM0[28].b[CHIP][1]:SCM0[28].awoo[CHIP][1]);
adr = (Uint)(SCM0[28].awoo[CHIP][1] + SCM0[28].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][4] = SCM0[28].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][4] = SCM0[28].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][4] = SCM0[28].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[28].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM1[28].b[CHIP][2]) : SCM1[28].awoo[CHIP][2];
SCM1[28].o[CHIP][2] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][7] : SCM1[28].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[28].awoo[CHIP][2] = (Ull)(INIT0?SCM1[28].b[CHIP][2]:SCM1[28].awoo[CHIP][2]);
adr = (Uint)(SCM1[28].awoo[CHIP][2] + SCM1[28].o[CHIP][2]);
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][2] : SCAR[28].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][9] : 0, 28);
ex3 = exm(SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][1], 28);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[28].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][6] : SCAR[28].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][9] : 0, 28);
ex3 = exm(SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][0], 28);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[28].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][10] : SCAR[28].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][9] : 0, 28);
ex3 = exm(SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][5], 28);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[28].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][14] : SCAR[28].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][9] : 0, 28);
ex3 = exm(SCBR[27].r[CHIP][SCBR[28].enq[CHIP]][4], 28);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[28].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][2] = SCAR[28].r[CHIP][0];
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][3] = SCBR[27].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][6] = SCAR[28].r[CHIP][1];
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][7] = SCBR[27].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][8] = SCBR[27].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][10] = SCAR[28].r[CHIP][2];
}
{
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][14] = SCAR[28].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((29 && SCBR[28].enq[CHIP]==SCBR[28].deq[CHIP]) || SCBR[28].deq[CHIP]!=SCBR[29].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[29].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM1[29].b[CHIP][0]) : SCM1[29].awoo[CHIP][0];
SCM1[29].o[CHIP][0] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][3] : SCM1[29].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[29].awoo[CHIP][0] = (Ull)(INIT0?SCM1[29].b[CHIP][0]:SCM1[29].awoo[CHIP][0]);
adr = (Uint)(SCM1[29].awoo[CHIP][0] + SCM1[29].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][1] = SCM1[29].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][1] = SCM1[29].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][1] = SCM1[29].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[29].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM0[29].b[CHIP][0]) : SCM0[29].awoo[CHIP][0];
SCM0[29].o[CHIP][0] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][3] : SCM0[29].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[29].awoo[CHIP][0] = (Ull)(INIT0?SCM0[29].b[CHIP][0]:SCM0[29].awoo[CHIP][0]);
adr = (Uint)(SCM0[29].awoo[CHIP][0] + SCM0[29].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0] = SCM0[29].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0] = SCM0[29].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0] = SCM0[29].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[29].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM1[29].b[CHIP][1]) : SCM1[29].awoo[CHIP][1];
SCM1[29].o[CHIP][1] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][3] : SCM1[29].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[29].awoo[CHIP][1] = (Ull)(INIT0?SCM1[29].b[CHIP][1]:SCM1[29].awoo[CHIP][1]);
adr = (Uint)(SCM1[29].awoo[CHIP][1] + SCM1[29].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][5] = SCM1[29].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][5] = SCM1[29].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][5] = SCM1[29].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[29].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM0[29].b[CHIP][1]) : SCM0[29].awoo[CHIP][1];
SCM0[29].o[CHIP][1] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][3] : SCM0[29].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[29].awoo[CHIP][1] = (Ull)(INIT0?SCM0[29].b[CHIP][1]:SCM0[29].awoo[CHIP][1]);
adr = (Uint)(SCM0[29].awoo[CHIP][1] + SCM0[29].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][4] = SCM0[29].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][4] = SCM0[29].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][4] = SCM0[29].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[29].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM1[29].b[CHIP][2]) : SCM1[29].awoo[CHIP][2];
SCM1[29].o[CHIP][2] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][7] : SCM1[29].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[29].awoo[CHIP][2] = (Ull)(INIT0?SCM1[29].b[CHIP][2]:SCM1[29].awoo[CHIP][2]);
adr = (Uint)(SCM1[29].awoo[CHIP][2] + SCM1[29].o[CHIP][2]);
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][2] : SCAR[29].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][9] : 0, 29);
ex3 = exm(SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][1], 29);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[29].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][6] : SCAR[29].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][9] : 0, 29);
ex3 = exm(SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][0], 29);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[29].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][10] : SCAR[29].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][9] : 0, 29);
ex3 = exm(SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][5], 29);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[29].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][14] : SCAR[29].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][9] : 0, 29);
ex3 = exm(SCBR[28].r[CHIP][SCBR[29].enq[CHIP]][4], 29);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[29].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][2] = SCAR[29].r[CHIP][0];
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][3] = SCBR[28].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][6] = SCAR[29].r[CHIP][1];
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][7] = SCBR[28].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][8] = SCBR[28].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][10] = SCAR[29].r[CHIP][2];
}
{
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][14] = SCAR[29].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((30 && SCBR[29].enq[CHIP]==SCBR[29].deq[CHIP]) || SCBR[29].deq[CHIP]!=SCBR[30].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[30].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM1[30].b[CHIP][0]) : SCM1[30].awoo[CHIP][0];
SCM1[30].o[CHIP][0] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][3] : SCM1[30].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[30].awoo[CHIP][0] = (Ull)(INIT0?SCM1[30].b[CHIP][0]:SCM1[30].awoo[CHIP][0]);
adr = (Uint)(SCM1[30].awoo[CHIP][0] + SCM1[30].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][1] = SCM1[30].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][1] = SCM1[30].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][1] = SCM1[30].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[30].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM0[30].b[CHIP][0]) : SCM0[30].awoo[CHIP][0];
SCM0[30].o[CHIP][0] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][3] : SCM0[30].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[30].awoo[CHIP][0] = (Ull)(INIT0?SCM0[30].b[CHIP][0]:SCM0[30].awoo[CHIP][0]);
adr = (Uint)(SCM0[30].awoo[CHIP][0] + SCM0[30].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0] = SCM0[30].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0] = SCM0[30].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0] = SCM0[30].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[30].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM1[30].b[CHIP][1]) : SCM1[30].awoo[CHIP][1];
SCM1[30].o[CHIP][1] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][3] : SCM1[30].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[30].awoo[CHIP][1] = (Ull)(INIT0?SCM1[30].b[CHIP][1]:SCM1[30].awoo[CHIP][1]);
adr = (Uint)(SCM1[30].awoo[CHIP][1] + SCM1[30].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][5] = SCM1[30].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][5] = SCM1[30].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][5] = SCM1[30].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[30].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM0[30].b[CHIP][1]) : SCM0[30].awoo[CHIP][1];
SCM0[30].o[CHIP][1] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][3] : SCM0[30].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[30].awoo[CHIP][1] = (Ull)(INIT0?SCM0[30].b[CHIP][1]:SCM0[30].awoo[CHIP][1]);
adr = (Uint)(SCM0[30].awoo[CHIP][1] + SCM0[30].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][4] = SCM0[30].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][4] = SCM0[30].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][4] = SCM0[30].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[30].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM1[30].b[CHIP][2]) : SCM1[30].awoo[CHIP][2];
SCM1[30].o[CHIP][2] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][7] : SCM1[30].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[30].awoo[CHIP][2] = (Ull)(INIT0?SCM1[30].b[CHIP][2]:SCM1[30].awoo[CHIP][2]);
adr = (Uint)(SCM1[30].awoo[CHIP][2] + SCM1[30].o[CHIP][2]);
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][2] : SCAR[30].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][9] : 0, 30);
ex3 = exm(SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][1], 30);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[30].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][6] : SCAR[30].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][9] : 0, 30);
ex3 = exm(SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][0], 30);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[30].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][10] : SCAR[30].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][9] : 0, 30);
ex3 = exm(SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][5], 30);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[30].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][14] : SCAR[30].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][9] : 0, 30);
ex3 = exm(SCBR[29].r[CHIP][SCBR[30].enq[CHIP]][4], 30);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[30].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][2] = SCAR[30].r[CHIP][0];
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][3] = SCBR[29].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][6] = SCAR[30].r[CHIP][1];
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][7] = SCBR[29].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][8] = SCBR[29].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][10] = SCAR[30].r[CHIP][2];
}
{
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][14] = SCAR[30].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((31 && SCBR[30].enq[CHIP]==SCBR[30].deq[CHIP]) || SCBR[30].deq[CHIP]!=SCBR[31].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[31].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM1[31].b[CHIP][0]) : SCM1[31].awoo[CHIP][0];
SCM1[31].o[CHIP][0] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][3] : SCM1[31].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[31].awoo[CHIP][0] = (Ull)(INIT0?SCM1[31].b[CHIP][0]:SCM1[31].awoo[CHIP][0]);
adr = (Uint)(SCM1[31].awoo[CHIP][0] + SCM1[31].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][1] = SCM1[31].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][1] = SCM1[31].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][1] = SCM1[31].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[31].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM0[31].b[CHIP][0]) : SCM0[31].awoo[CHIP][0];
SCM0[31].o[CHIP][0] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][3] : SCM0[31].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[31].awoo[CHIP][0] = (Ull)(INIT0?SCM0[31].b[CHIP][0]:SCM0[31].awoo[CHIP][0]);
adr = (Uint)(SCM0[31].awoo[CHIP][0] + SCM0[31].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0] = SCM0[31].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0] = SCM0[31].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0] = SCM0[31].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[31].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM1[31].b[CHIP][1]) : SCM1[31].awoo[CHIP][1];
SCM1[31].o[CHIP][1] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][3] : SCM1[31].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[31].awoo[CHIP][1] = (Ull)(INIT0?SCM1[31].b[CHIP][1]:SCM1[31].awoo[CHIP][1]);
adr = (Uint)(SCM1[31].awoo[CHIP][1] + SCM1[31].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][5] = SCM1[31].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][5] = SCM1[31].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][5] = SCM1[31].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[31].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM0[31].b[CHIP][1]) : SCM0[31].awoo[CHIP][1];
SCM0[31].o[CHIP][1] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][3] : SCM0[31].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[31].awoo[CHIP][1] = (Ull)(INIT0?SCM0[31].b[CHIP][1]:SCM0[31].awoo[CHIP][1]);
adr = (Uint)(SCM0[31].awoo[CHIP][1] + SCM0[31].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][4] = SCM0[31].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][4] = SCM0[31].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][4] = SCM0[31].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[31].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM1[31].b[CHIP][2]) : SCM1[31].awoo[CHIP][2];
SCM1[31].o[CHIP][2] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][7] : SCM1[31].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[31].awoo[CHIP][2] = (Ull)(INIT0?SCM1[31].b[CHIP][2]:SCM1[31].awoo[CHIP][2]);
adr = (Uint)(SCM1[31].awoo[CHIP][2] + SCM1[31].o[CHIP][2]);
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][2] : SCAR[31].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][9] : 0, 31);
ex3 = exm(SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][1], 31);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[31].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][6] : SCAR[31].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][9] : 0, 31);
ex3 = exm(SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][0], 31);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[31].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][10] : SCAR[31].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][9] : 0, 31);
ex3 = exm(SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][5], 31);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[31].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][14] : SCAR[31].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][9] : 0, 31);
ex3 = exm(SCBR[30].r[CHIP][SCBR[31].enq[CHIP]][4], 31);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[31].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][2] = SCAR[31].r[CHIP][0];
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][3] = SCBR[30].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][6] = SCAR[31].r[CHIP][1];
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][7] = SCBR[30].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][8] = SCBR[30].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][10] = SCAR[31].r[CHIP][2];
}
{
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][14] = SCAR[31].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((32 && SCBR[31].enq[CHIP]==SCBR[31].deq[CHIP]) || SCBR[31].deq[CHIP]!=SCBR[32].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[32].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM1[32].b[CHIP][0]) : SCM1[32].awoo[CHIP][0];
SCM1[32].o[CHIP][0] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][3] : SCM1[32].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[32].awoo[CHIP][0] = (Ull)(INIT0?SCM1[32].b[CHIP][0]:SCM1[32].awoo[CHIP][0]);
adr = (Uint)(SCM1[32].awoo[CHIP][0] + SCM1[32].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][1] = SCM1[32].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][1] = SCM1[32].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][1] = SCM1[32].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[32].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM0[32].b[CHIP][0]) : SCM0[32].awoo[CHIP][0];
SCM0[32].o[CHIP][0] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][3] : SCM0[32].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[32].awoo[CHIP][0] = (Ull)(INIT0?SCM0[32].b[CHIP][0]:SCM0[32].awoo[CHIP][0]);
adr = (Uint)(SCM0[32].awoo[CHIP][0] + SCM0[32].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0] = SCM0[32].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0] = SCM0[32].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0] = SCM0[32].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[32].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM1[32].b[CHIP][1]) : SCM1[32].awoo[CHIP][1];
SCM1[32].o[CHIP][1] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][3] : SCM1[32].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[32].awoo[CHIP][1] = (Ull)(INIT0?SCM1[32].b[CHIP][1]:SCM1[32].awoo[CHIP][1]);
adr = (Uint)(SCM1[32].awoo[CHIP][1] + SCM1[32].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][5] = SCM1[32].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][5] = SCM1[32].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][5] = SCM1[32].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[32].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM0[32].b[CHIP][1]) : SCM0[32].awoo[CHIP][1];
SCM0[32].o[CHIP][1] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][3] : SCM0[32].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[32].awoo[CHIP][1] = (Ull)(INIT0?SCM0[32].b[CHIP][1]:SCM0[32].awoo[CHIP][1]);
adr = (Uint)(SCM0[32].awoo[CHIP][1] + SCM0[32].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][4] = SCM0[32].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][4] = SCM0[32].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][4] = SCM0[32].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[32].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM1[32].b[CHIP][2]) : SCM1[32].awoo[CHIP][2];
SCM1[32].o[CHIP][2] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][7] : SCM1[32].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[32].awoo[CHIP][2] = (Ull)(INIT0?SCM1[32].b[CHIP][2]:SCM1[32].awoo[CHIP][2]);
adr = (Uint)(SCM1[32].awoo[CHIP][2] + SCM1[32].o[CHIP][2]);
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][2] : SCAR[32].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][9] : 0, 32);
ex3 = exm(SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][1], 32);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[32].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][6] : SCAR[32].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][9] : 0, 32);
ex3 = exm(SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][0], 32);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[32].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][10] : SCAR[32].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][9] : 0, 32);
ex3 = exm(SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][5], 32);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[32].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][14] : SCAR[32].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][9] : 0, 32);
ex3 = exm(SCBR[31].r[CHIP][SCBR[32].enq[CHIP]][4], 32);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[32].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][2] = SCAR[32].r[CHIP][0];
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][3] = SCBR[31].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][6] = SCAR[32].r[CHIP][1];
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][7] = SCBR[31].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][8] = SCBR[31].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][10] = SCAR[32].r[CHIP][2];
}
{
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][14] = SCAR[32].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((33 && SCBR[32].enq[CHIP]==SCBR[32].deq[CHIP]) || SCBR[32].deq[CHIP]!=SCBR[33].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[33].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM1[33].b[CHIP][0]) : SCM1[33].awoo[CHIP][0];
SCM1[33].o[CHIP][0] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][3] : SCM1[33].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[33].awoo[CHIP][0] = (Ull)(INIT0?SCM1[33].b[CHIP][0]:SCM1[33].awoo[CHIP][0]);
adr = (Uint)(SCM1[33].awoo[CHIP][0] + SCM1[33].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][1] = SCM1[33].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][1] = SCM1[33].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][1] = SCM1[33].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[33].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM0[33].b[CHIP][0]) : SCM0[33].awoo[CHIP][0];
SCM0[33].o[CHIP][0] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][3] : SCM0[33].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[33].awoo[CHIP][0] = (Ull)(INIT0?SCM0[33].b[CHIP][0]:SCM0[33].awoo[CHIP][0]);
adr = (Uint)(SCM0[33].awoo[CHIP][0] + SCM0[33].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0] = SCM0[33].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0] = SCM0[33].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0] = SCM0[33].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[33].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM1[33].b[CHIP][1]) : SCM1[33].awoo[CHIP][1];
SCM1[33].o[CHIP][1] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][3] : SCM1[33].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[33].awoo[CHIP][1] = (Ull)(INIT0?SCM1[33].b[CHIP][1]:SCM1[33].awoo[CHIP][1]);
adr = (Uint)(SCM1[33].awoo[CHIP][1] + SCM1[33].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][5] = SCM1[33].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][5] = SCM1[33].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][5] = SCM1[33].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[33].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM0[33].b[CHIP][1]) : SCM0[33].awoo[CHIP][1];
SCM0[33].o[CHIP][1] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][3] : SCM0[33].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[33].awoo[CHIP][1] = (Ull)(INIT0?SCM0[33].b[CHIP][1]:SCM0[33].awoo[CHIP][1]);
adr = (Uint)(SCM0[33].awoo[CHIP][1] + SCM0[33].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][4] = SCM0[33].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][4] = SCM0[33].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][4] = SCM0[33].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[33].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM1[33].b[CHIP][2]) : SCM1[33].awoo[CHIP][2];
SCM1[33].o[CHIP][2] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][7] : SCM1[33].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[33].awoo[CHIP][2] = (Ull)(INIT0?SCM1[33].b[CHIP][2]:SCM1[33].awoo[CHIP][2]);
adr = (Uint)(SCM1[33].awoo[CHIP][2] + SCM1[33].o[CHIP][2]);
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][2] : SCAR[33].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][9] : 0, 33);
ex3 = exm(SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][1], 33);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[33].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][6] : SCAR[33].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][9] : 0, 33);
ex3 = exm(SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][0], 33);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[33].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][10] : SCAR[33].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][9] : 0, 33);
ex3 = exm(SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][5], 33);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[33].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][14] : SCAR[33].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][9] : 0, 33);
ex3 = exm(SCBR[32].r[CHIP][SCBR[33].enq[CHIP]][4], 33);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[33].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][2] = SCAR[33].r[CHIP][0];
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][3] = SCBR[32].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][6] = SCAR[33].r[CHIP][1];
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][7] = SCBR[32].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][8] = SCBR[32].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][10] = SCAR[33].r[CHIP][2];
}
{
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][14] = SCAR[33].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((34 && SCBR[33].enq[CHIP]==SCBR[33].deq[CHIP]) || SCBR[33].deq[CHIP]!=SCBR[34].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[34].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM1[34].b[CHIP][0]) : SCM1[34].awoo[CHIP][0];
SCM1[34].o[CHIP][0] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][3] : SCM1[34].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[34].awoo[CHIP][0] = (Ull)(INIT0?SCM1[34].b[CHIP][0]:SCM1[34].awoo[CHIP][0]);
adr = (Uint)(SCM1[34].awoo[CHIP][0] + SCM1[34].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][1] = SCM1[34].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][1] = SCM1[34].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][1] = SCM1[34].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[34].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM0[34].b[CHIP][0]) : SCM0[34].awoo[CHIP][0];
SCM0[34].o[CHIP][0] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][3] : SCM0[34].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[34].awoo[CHIP][0] = (Ull)(INIT0?SCM0[34].b[CHIP][0]:SCM0[34].awoo[CHIP][0]);
adr = (Uint)(SCM0[34].awoo[CHIP][0] + SCM0[34].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0] = SCM0[34].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0] = SCM0[34].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0] = SCM0[34].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[34].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM1[34].b[CHIP][1]) : SCM1[34].awoo[CHIP][1];
SCM1[34].o[CHIP][1] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][3] : SCM1[34].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[34].awoo[CHIP][1] = (Ull)(INIT0?SCM1[34].b[CHIP][1]:SCM1[34].awoo[CHIP][1]);
adr = (Uint)(SCM1[34].awoo[CHIP][1] + SCM1[34].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][5] = SCM1[34].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][5] = SCM1[34].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][5] = SCM1[34].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[34].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM0[34].b[CHIP][1]) : SCM0[34].awoo[CHIP][1];
SCM0[34].o[CHIP][1] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][3] : SCM0[34].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[34].awoo[CHIP][1] = (Ull)(INIT0?SCM0[34].b[CHIP][1]:SCM0[34].awoo[CHIP][1]);
adr = (Uint)(SCM0[34].awoo[CHIP][1] + SCM0[34].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][4] = SCM0[34].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][4] = SCM0[34].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][4] = SCM0[34].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[34].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM1[34].b[CHIP][2]) : SCM1[34].awoo[CHIP][2];
SCM1[34].o[CHIP][2] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][7] : SCM1[34].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[34].awoo[CHIP][2] = (Ull)(INIT0?SCM1[34].b[CHIP][2]:SCM1[34].awoo[CHIP][2]);
adr = (Uint)(SCM1[34].awoo[CHIP][2] + SCM1[34].o[CHIP][2]);
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][2] : SCAR[34].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][9] : 0, 34);
ex3 = exm(SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][1], 34);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[34].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][6] : SCAR[34].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][9] : 0, 34);
ex3 = exm(SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][0], 34);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[34].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][10] : SCAR[34].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][9] : 0, 34);
ex3 = exm(SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][5], 34);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[34].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][14] : SCAR[34].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][9] : 0, 34);
ex3 = exm(SCBR[33].r[CHIP][SCBR[34].enq[CHIP]][4], 34);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[34].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][2] = SCAR[34].r[CHIP][0];
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][3] = SCBR[33].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][6] = SCAR[34].r[CHIP][1];
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][7] = SCBR[33].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][8] = SCBR[33].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][10] = SCAR[34].r[CHIP][2];
}
{
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][14] = SCAR[34].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((35 && SCBR[34].enq[CHIP]==SCBR[34].deq[CHIP]) || SCBR[34].deq[CHIP]!=SCBR[35].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[35].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM1[35].b[CHIP][0]) : SCM1[35].awoo[CHIP][0];
SCM1[35].o[CHIP][0] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][3] : SCM1[35].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[35].awoo[CHIP][0] = (Ull)(INIT0?SCM1[35].b[CHIP][0]:SCM1[35].awoo[CHIP][0]);
adr = (Uint)(SCM1[35].awoo[CHIP][0] + SCM1[35].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][1] = SCM1[35].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][1] = SCM1[35].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][1] = SCM1[35].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[35].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM0[35].b[CHIP][0]) : SCM0[35].awoo[CHIP][0];
SCM0[35].o[CHIP][0] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][3] : SCM0[35].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[35].awoo[CHIP][0] = (Ull)(INIT0?SCM0[35].b[CHIP][0]:SCM0[35].awoo[CHIP][0]);
adr = (Uint)(SCM0[35].awoo[CHIP][0] + SCM0[35].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0] = SCM0[35].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0] = SCM0[35].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0] = SCM0[35].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[35].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM1[35].b[CHIP][1]) : SCM1[35].awoo[CHIP][1];
SCM1[35].o[CHIP][1] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][3] : SCM1[35].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[35].awoo[CHIP][1] = (Ull)(INIT0?SCM1[35].b[CHIP][1]:SCM1[35].awoo[CHIP][1]);
adr = (Uint)(SCM1[35].awoo[CHIP][1] + SCM1[35].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][5] = SCM1[35].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][5] = SCM1[35].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][5] = SCM1[35].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[35].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM0[35].b[CHIP][1]) : SCM0[35].awoo[CHIP][1];
SCM0[35].o[CHIP][1] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][3] : SCM0[35].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[35].awoo[CHIP][1] = (Ull)(INIT0?SCM0[35].b[CHIP][1]:SCM0[35].awoo[CHIP][1]);
adr = (Uint)(SCM0[35].awoo[CHIP][1] + SCM0[35].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][4] = SCM0[35].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][4] = SCM0[35].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][4] = SCM0[35].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[35].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM1[35].b[CHIP][2]) : SCM1[35].awoo[CHIP][2];
SCM1[35].o[CHIP][2] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][7] : SCM1[35].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[35].awoo[CHIP][2] = (Ull)(INIT0?SCM1[35].b[CHIP][2]:SCM1[35].awoo[CHIP][2]);
adr = (Uint)(SCM1[35].awoo[CHIP][2] + SCM1[35].o[CHIP][2]);
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][2] : SCAR[35].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][9] : 0, 35);
ex3 = exm(SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][1], 35);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[35].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][6] : SCAR[35].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][9] : 0, 35);
ex3 = exm(SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][0], 35);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[35].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][10] : SCAR[35].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][9] : 0, 35);
ex3 = exm(SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][5], 35);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[35].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][14] : SCAR[35].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][9] : 0, 35);
ex3 = exm(SCBR[34].r[CHIP][SCBR[35].enq[CHIP]][4], 35);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[35].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][2] = SCAR[35].r[CHIP][0];
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][3] = SCBR[34].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][6] = SCAR[35].r[CHIP][1];
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][7] = SCBR[34].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][8] = SCBR[34].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][10] = SCAR[35].r[CHIP][2];
}
{
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][14] = SCAR[35].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((36 && SCBR[35].enq[CHIP]==SCBR[35].deq[CHIP]) || SCBR[35].deq[CHIP]!=SCBR[36].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[36].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM1[36].b[CHIP][0]) : SCM1[36].awoo[CHIP][0];
SCM1[36].o[CHIP][0] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][3] : SCM1[36].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[36].awoo[CHIP][0] = (Ull)(INIT0?SCM1[36].b[CHIP][0]:SCM1[36].awoo[CHIP][0]);
adr = (Uint)(SCM1[36].awoo[CHIP][0] + SCM1[36].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][1] = SCM1[36].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][1] = SCM1[36].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][1] = SCM1[36].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[36].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM0[36].b[CHIP][0]) : SCM0[36].awoo[CHIP][0];
SCM0[36].o[CHIP][0] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][3] : SCM0[36].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[36].awoo[CHIP][0] = (Ull)(INIT0?SCM0[36].b[CHIP][0]:SCM0[36].awoo[CHIP][0]);
adr = (Uint)(SCM0[36].awoo[CHIP][0] + SCM0[36].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0] = SCM0[36].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0] = SCM0[36].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0] = SCM0[36].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[36].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM1[36].b[CHIP][1]) : SCM1[36].awoo[CHIP][1];
SCM1[36].o[CHIP][1] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][3] : SCM1[36].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[36].awoo[CHIP][1] = (Ull)(INIT0?SCM1[36].b[CHIP][1]:SCM1[36].awoo[CHIP][1]);
adr = (Uint)(SCM1[36].awoo[CHIP][1] + SCM1[36].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][5] = SCM1[36].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][5] = SCM1[36].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][5] = SCM1[36].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[36].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM0[36].b[CHIP][1]) : SCM0[36].awoo[CHIP][1];
SCM0[36].o[CHIP][1] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][3] : SCM0[36].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[36].awoo[CHIP][1] = (Ull)(INIT0?SCM0[36].b[CHIP][1]:SCM0[36].awoo[CHIP][1]);
adr = (Uint)(SCM0[36].awoo[CHIP][1] + SCM0[36].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][4] = SCM0[36].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][4] = SCM0[36].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][4] = SCM0[36].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[36].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM1[36].b[CHIP][2]) : SCM1[36].awoo[CHIP][2];
SCM1[36].o[CHIP][2] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][7] : SCM1[36].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[36].awoo[CHIP][2] = (Ull)(INIT0?SCM1[36].b[CHIP][2]:SCM1[36].awoo[CHIP][2]);
adr = (Uint)(SCM1[36].awoo[CHIP][2] + SCM1[36].o[CHIP][2]);
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][2] : SCAR[36].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][9] : 0, 36);
ex3 = exm(SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][1], 36);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[36].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][6] : SCAR[36].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][9] : 0, 36);
ex3 = exm(SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][0], 36);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[36].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][10] : SCAR[36].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][9] : 0, 36);
ex3 = exm(SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][5], 36);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[36].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][14] : SCAR[36].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][9] : 0, 36);
ex3 = exm(SCBR[35].r[CHIP][SCBR[36].enq[CHIP]][4], 36);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[36].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][2] = SCAR[36].r[CHIP][0];
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][3] = SCBR[35].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][6] = SCAR[36].r[CHIP][1];
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][7] = SCBR[35].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][8] = SCBR[35].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][10] = SCAR[36].r[CHIP][2];
}
{
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][14] = SCAR[36].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((37 && SCBR[36].enq[CHIP]==SCBR[36].deq[CHIP]) || SCBR[36].deq[CHIP]!=SCBR[37].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[37].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM1[37].b[CHIP][0]) : SCM1[37].awoo[CHIP][0];
SCM1[37].o[CHIP][0] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][3] : SCM1[37].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[37].awoo[CHIP][0] = (Ull)(INIT0?SCM1[37].b[CHIP][0]:SCM1[37].awoo[CHIP][0]);
adr = (Uint)(SCM1[37].awoo[CHIP][0] + SCM1[37].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][1] = SCM1[37].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][1] = SCM1[37].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][1] = SCM1[37].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[37].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM0[37].b[CHIP][0]) : SCM0[37].awoo[CHIP][0];
SCM0[37].o[CHIP][0] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][3] : SCM0[37].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[37].awoo[CHIP][0] = (Ull)(INIT0?SCM0[37].b[CHIP][0]:SCM0[37].awoo[CHIP][0]);
adr = (Uint)(SCM0[37].awoo[CHIP][0] + SCM0[37].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0] = SCM0[37].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0] = SCM0[37].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0] = SCM0[37].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[37].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM1[37].b[CHIP][1]) : SCM1[37].awoo[CHIP][1];
SCM1[37].o[CHIP][1] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][3] : SCM1[37].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[37].awoo[CHIP][1] = (Ull)(INIT0?SCM1[37].b[CHIP][1]:SCM1[37].awoo[CHIP][1]);
adr = (Uint)(SCM1[37].awoo[CHIP][1] + SCM1[37].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][5] = SCM1[37].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][5] = SCM1[37].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][5] = SCM1[37].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[37].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM0[37].b[CHIP][1]) : SCM0[37].awoo[CHIP][1];
SCM0[37].o[CHIP][1] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][3] : SCM0[37].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[37].awoo[CHIP][1] = (Ull)(INIT0?SCM0[37].b[CHIP][1]:SCM0[37].awoo[CHIP][1]);
adr = (Uint)(SCM0[37].awoo[CHIP][1] + SCM0[37].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][4] = SCM0[37].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][4] = SCM0[37].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][4] = SCM0[37].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[37].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM1[37].b[CHIP][2]) : SCM1[37].awoo[CHIP][2];
SCM1[37].o[CHIP][2] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][7] : SCM1[37].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[37].awoo[CHIP][2] = (Ull)(INIT0?SCM1[37].b[CHIP][2]:SCM1[37].awoo[CHIP][2]);
adr = (Uint)(SCM1[37].awoo[CHIP][2] + SCM1[37].o[CHIP][2]);
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][2] : SCAR[37].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][9] : 0, 37);
ex3 = exm(SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][1], 37);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[37].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][6] : SCAR[37].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][9] : 0, 37);
ex3 = exm(SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][0], 37);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[37].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][10] : SCAR[37].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][9] : 0, 37);
ex3 = exm(SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][5], 37);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[37].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][14] : SCAR[37].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][9] : 0, 37);
ex3 = exm(SCBR[36].r[CHIP][SCBR[37].enq[CHIP]][4], 37);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[37].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][2] = SCAR[37].r[CHIP][0];
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][3] = SCBR[36].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][6] = SCAR[37].r[CHIP][1];
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][7] = SCBR[36].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][8] = SCBR[36].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][10] = SCAR[37].r[CHIP][2];
}
{
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][14] = SCAR[37].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((38 && SCBR[37].enq[CHIP]==SCBR[37].deq[CHIP]) || SCBR[37].deq[CHIP]!=SCBR[38].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[38].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM1[38].b[CHIP][0]) : SCM1[38].awoo[CHIP][0];
SCM1[38].o[CHIP][0] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][3] : SCM1[38].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[38].awoo[CHIP][0] = (Ull)(INIT0?SCM1[38].b[CHIP][0]:SCM1[38].awoo[CHIP][0]);
adr = (Uint)(SCM1[38].awoo[CHIP][0] + SCM1[38].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][1] = SCM1[38].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][1] = SCM1[38].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][1] = SCM1[38].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[38].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM0[38].b[CHIP][0]) : SCM0[38].awoo[CHIP][0];
SCM0[38].o[CHIP][0] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][3] : SCM0[38].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[38].awoo[CHIP][0] = (Ull)(INIT0?SCM0[38].b[CHIP][0]:SCM0[38].awoo[CHIP][0]);
adr = (Uint)(SCM0[38].awoo[CHIP][0] + SCM0[38].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0] = SCM0[38].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0] = SCM0[38].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0] = SCM0[38].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[38].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM1[38].b[CHIP][1]) : SCM1[38].awoo[CHIP][1];
SCM1[38].o[CHIP][1] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][3] : SCM1[38].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[38].awoo[CHIP][1] = (Ull)(INIT0?SCM1[38].b[CHIP][1]:SCM1[38].awoo[CHIP][1]);
adr = (Uint)(SCM1[38].awoo[CHIP][1] + SCM1[38].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][5] = SCM1[38].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][5] = SCM1[38].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][5] = SCM1[38].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[38].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM0[38].b[CHIP][1]) : SCM0[38].awoo[CHIP][1];
SCM0[38].o[CHIP][1] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][3] : SCM0[38].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[38].awoo[CHIP][1] = (Ull)(INIT0?SCM0[38].b[CHIP][1]:SCM0[38].awoo[CHIP][1]);
adr = (Uint)(SCM0[38].awoo[CHIP][1] + SCM0[38].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][4] = SCM0[38].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][4] = SCM0[38].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][4] = SCM0[38].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[38].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM1[38].b[CHIP][2]) : SCM1[38].awoo[CHIP][2];
SCM1[38].o[CHIP][2] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][7] : SCM1[38].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[38].awoo[CHIP][2] = (Ull)(INIT0?SCM1[38].b[CHIP][2]:SCM1[38].awoo[CHIP][2]);
adr = (Uint)(SCM1[38].awoo[CHIP][2] + SCM1[38].o[CHIP][2]);
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][2] : SCAR[38].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][9] : 0, 38);
ex3 = exm(SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][1], 38);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[38].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][6] : SCAR[38].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][9] : 0, 38);
ex3 = exm(SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][0], 38);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[38].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][10] : SCAR[38].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][9] : 0, 38);
ex3 = exm(SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][5], 38);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[38].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][14] : SCAR[38].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][9] : 0, 38);
ex3 = exm(SCBR[37].r[CHIP][SCBR[38].enq[CHIP]][4], 38);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[38].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][2] = SCAR[38].r[CHIP][0];
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][3] = SCBR[37].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][6] = SCAR[38].r[CHIP][1];
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][7] = SCBR[37].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][8] = SCBR[37].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][10] = SCAR[38].r[CHIP][2];
}
{
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][14] = SCAR[38].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((39 && SCBR[38].enq[CHIP]==SCBR[38].deq[CHIP]) || SCBR[38].deq[CHIP]!=SCBR[39].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[39].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM1[39].b[CHIP][0]) : SCM1[39].awoo[CHIP][0];
SCM1[39].o[CHIP][0] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][3] : SCM1[39].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[39].awoo[CHIP][0] = (Ull)(INIT0?SCM1[39].b[CHIP][0]:SCM1[39].awoo[CHIP][0]);
adr = (Uint)(SCM1[39].awoo[CHIP][0] + SCM1[39].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][1] = SCM1[39].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][1] = SCM1[39].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][1] = SCM1[39].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[39].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM0[39].b[CHIP][0]) : SCM0[39].awoo[CHIP][0];
SCM0[39].o[CHIP][0] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][3] : SCM0[39].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[39].awoo[CHIP][0] = (Ull)(INIT0?SCM0[39].b[CHIP][0]:SCM0[39].awoo[CHIP][0]);
adr = (Uint)(SCM0[39].awoo[CHIP][0] + SCM0[39].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0] = SCM0[39].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0] = SCM0[39].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0] = SCM0[39].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[39].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM1[39].b[CHIP][1]) : SCM1[39].awoo[CHIP][1];
SCM1[39].o[CHIP][1] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][3] : SCM1[39].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[39].awoo[CHIP][1] = (Ull)(INIT0?SCM1[39].b[CHIP][1]:SCM1[39].awoo[CHIP][1]);
adr = (Uint)(SCM1[39].awoo[CHIP][1] + SCM1[39].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][5] = SCM1[39].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][5] = SCM1[39].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][5] = SCM1[39].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[39].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM0[39].b[CHIP][1]) : SCM0[39].awoo[CHIP][1];
SCM0[39].o[CHIP][1] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][3] : SCM0[39].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[39].awoo[CHIP][1] = (Ull)(INIT0?SCM0[39].b[CHIP][1]:SCM0[39].awoo[CHIP][1]);
adr = (Uint)(SCM0[39].awoo[CHIP][1] + SCM0[39].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][4] = SCM0[39].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][4] = SCM0[39].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][4] = SCM0[39].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[39].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM1[39].b[CHIP][2]) : SCM1[39].awoo[CHIP][2];
SCM1[39].o[CHIP][2] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][7] : SCM1[39].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[39].awoo[CHIP][2] = (Ull)(INIT0?SCM1[39].b[CHIP][2]:SCM1[39].awoo[CHIP][2]);
adr = (Uint)(SCM1[39].awoo[CHIP][2] + SCM1[39].o[CHIP][2]);
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][2] : SCAR[39].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][9] : 0, 39);
ex3 = exm(SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][1], 39);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[39].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][6] : SCAR[39].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][9] : 0, 39);
ex3 = exm(SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][0], 39);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[39].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][10] : SCAR[39].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][9] : 0, 39);
ex3 = exm(SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][5], 39);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[39].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][14] : SCAR[39].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][9] : 0, 39);
ex3 = exm(SCBR[38].r[CHIP][SCBR[39].enq[CHIP]][4], 39);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[39].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][2] = SCAR[39].r[CHIP][0];
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][3] = SCBR[38].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][6] = SCAR[39].r[CHIP][1];
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][7] = SCBR[38].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][8] = SCBR[38].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][10] = SCAR[39].r[CHIP][2];
}
{
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][14] = SCAR[39].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((40 && SCBR[39].enq[CHIP]==SCBR[39].deq[CHIP]) || SCBR[39].deq[CHIP]!=SCBR[40].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[40].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM1[40].b[CHIP][0]) : SCM1[40].awoo[CHIP][0];
SCM1[40].o[CHIP][0] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][3] : SCM1[40].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[40].awoo[CHIP][0] = (Ull)(INIT0?SCM1[40].b[CHIP][0]:SCM1[40].awoo[CHIP][0]);
adr = (Uint)(SCM1[40].awoo[CHIP][0] + SCM1[40].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][1] = SCM1[40].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][1] = SCM1[40].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][1] = SCM1[40].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[40].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM0[40].b[CHIP][0]) : SCM0[40].awoo[CHIP][0];
SCM0[40].o[CHIP][0] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][3] : SCM0[40].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[40].awoo[CHIP][0] = (Ull)(INIT0?SCM0[40].b[CHIP][0]:SCM0[40].awoo[CHIP][0]);
adr = (Uint)(SCM0[40].awoo[CHIP][0] + SCM0[40].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0] = SCM0[40].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0] = SCM0[40].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0] = SCM0[40].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[40].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM1[40].b[CHIP][1]) : SCM1[40].awoo[CHIP][1];
SCM1[40].o[CHIP][1] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][3] : SCM1[40].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[40].awoo[CHIP][1] = (Ull)(INIT0?SCM1[40].b[CHIP][1]:SCM1[40].awoo[CHIP][1]);
adr = (Uint)(SCM1[40].awoo[CHIP][1] + SCM1[40].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][5] = SCM1[40].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][5] = SCM1[40].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][5] = SCM1[40].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[40].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM0[40].b[CHIP][1]) : SCM0[40].awoo[CHIP][1];
SCM0[40].o[CHIP][1] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][3] : SCM0[40].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[40].awoo[CHIP][1] = (Ull)(INIT0?SCM0[40].b[CHIP][1]:SCM0[40].awoo[CHIP][1]);
adr = (Uint)(SCM0[40].awoo[CHIP][1] + SCM0[40].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][4] = SCM0[40].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][4] = SCM0[40].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][4] = SCM0[40].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[40].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM1[40].b[CHIP][2]) : SCM1[40].awoo[CHIP][2];
SCM1[40].o[CHIP][2] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][7] : SCM1[40].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[40].awoo[CHIP][2] = (Ull)(INIT0?SCM1[40].b[CHIP][2]:SCM1[40].awoo[CHIP][2]);
adr = (Uint)(SCM1[40].awoo[CHIP][2] + SCM1[40].o[CHIP][2]);
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][2] : SCAR[40].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][9] : 0, 40);
ex3 = exm(SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][1], 40);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[40].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][6] : SCAR[40].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][9] : 0, 40);
ex3 = exm(SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][0], 40);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[40].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][10] : SCAR[40].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][9] : 0, 40);
ex3 = exm(SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][5], 40);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[40].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][14] : SCAR[40].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][9] : 0, 40);
ex3 = exm(SCBR[39].r[CHIP][SCBR[40].enq[CHIP]][4], 40);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[40].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][2] = SCAR[40].r[CHIP][0];
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][3] = SCBR[39].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][6] = SCAR[40].r[CHIP][1];
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][7] = SCBR[39].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][8] = SCBR[39].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][10] = SCAR[40].r[CHIP][2];
}
{
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][14] = SCAR[40].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((41 && SCBR[40].enq[CHIP]==SCBR[40].deq[CHIP]) || SCBR[40].deq[CHIP]!=SCBR[41].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[41].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM1[41].b[CHIP][0]) : SCM1[41].awoo[CHIP][0];
SCM1[41].o[CHIP][0] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][3] : SCM1[41].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[41].awoo[CHIP][0] = (Ull)(INIT0?SCM1[41].b[CHIP][0]:SCM1[41].awoo[CHIP][0]);
adr = (Uint)(SCM1[41].awoo[CHIP][0] + SCM1[41].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][1] = SCM1[41].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][1] = SCM1[41].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][1] = SCM1[41].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[41].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM0[41].b[CHIP][0]) : SCM0[41].awoo[CHIP][0];
SCM0[41].o[CHIP][0] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][3] : SCM0[41].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[41].awoo[CHIP][0] = (Ull)(INIT0?SCM0[41].b[CHIP][0]:SCM0[41].awoo[CHIP][0]);
adr = (Uint)(SCM0[41].awoo[CHIP][0] + SCM0[41].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0] = SCM0[41].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0] = SCM0[41].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0] = SCM0[41].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[41].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM1[41].b[CHIP][1]) : SCM1[41].awoo[CHIP][1];
SCM1[41].o[CHIP][1] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][3] : SCM1[41].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[41].awoo[CHIP][1] = (Ull)(INIT0?SCM1[41].b[CHIP][1]:SCM1[41].awoo[CHIP][1]);
adr = (Uint)(SCM1[41].awoo[CHIP][1] + SCM1[41].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][5] = SCM1[41].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][5] = SCM1[41].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][5] = SCM1[41].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[41].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM0[41].b[CHIP][1]) : SCM0[41].awoo[CHIP][1];
SCM0[41].o[CHIP][1] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][3] : SCM0[41].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[41].awoo[CHIP][1] = (Ull)(INIT0?SCM0[41].b[CHIP][1]:SCM0[41].awoo[CHIP][1]);
adr = (Uint)(SCM0[41].awoo[CHIP][1] + SCM0[41].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][4] = SCM0[41].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][4] = SCM0[41].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][4] = SCM0[41].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[41].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM1[41].b[CHIP][2]) : SCM1[41].awoo[CHIP][2];
SCM1[41].o[CHIP][2] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][7] : SCM1[41].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[41].awoo[CHIP][2] = (Ull)(INIT0?SCM1[41].b[CHIP][2]:SCM1[41].awoo[CHIP][2]);
adr = (Uint)(SCM1[41].awoo[CHIP][2] + SCM1[41].o[CHIP][2]);
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][2] : SCAR[41].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][9] : 0, 41);
ex3 = exm(SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][1], 41);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[41].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][6] : SCAR[41].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][9] : 0, 41);
ex3 = exm(SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][0], 41);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[41].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][10] : SCAR[41].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][9] : 0, 41);
ex3 = exm(SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][5], 41);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[41].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][14] : SCAR[41].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][9] : 0, 41);
ex3 = exm(SCBR[40].r[CHIP][SCBR[41].enq[CHIP]][4], 41);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[41].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][2] = SCAR[41].r[CHIP][0];
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][3] = SCBR[40].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][6] = SCAR[41].r[CHIP][1];
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][7] = SCBR[40].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][8] = SCBR[40].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][10] = SCAR[41].r[CHIP][2];
}
{
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][14] = SCAR[41].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((42 && SCBR[41].enq[CHIP]==SCBR[41].deq[CHIP]) || SCBR[41].deq[CHIP]!=SCBR[42].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[42].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM1[42].b[CHIP][0]) : SCM1[42].awoo[CHIP][0];
SCM1[42].o[CHIP][0] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][3] : SCM1[42].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[42].awoo[CHIP][0] = (Ull)(INIT0?SCM1[42].b[CHIP][0]:SCM1[42].awoo[CHIP][0]);
adr = (Uint)(SCM1[42].awoo[CHIP][0] + SCM1[42].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][1] = SCM1[42].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][1] = SCM1[42].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][1] = SCM1[42].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[42].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM0[42].b[CHIP][0]) : SCM0[42].awoo[CHIP][0];
SCM0[42].o[CHIP][0] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][3] : SCM0[42].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[42].awoo[CHIP][0] = (Ull)(INIT0?SCM0[42].b[CHIP][0]:SCM0[42].awoo[CHIP][0]);
adr = (Uint)(SCM0[42].awoo[CHIP][0] + SCM0[42].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0] = SCM0[42].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0] = SCM0[42].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0] = SCM0[42].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[42].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM1[42].b[CHIP][1]) : SCM1[42].awoo[CHIP][1];
SCM1[42].o[CHIP][1] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][3] : SCM1[42].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[42].awoo[CHIP][1] = (Ull)(INIT0?SCM1[42].b[CHIP][1]:SCM1[42].awoo[CHIP][1]);
adr = (Uint)(SCM1[42].awoo[CHIP][1] + SCM1[42].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][5] = SCM1[42].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][5] = SCM1[42].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][5] = SCM1[42].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[42].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM0[42].b[CHIP][1]) : SCM0[42].awoo[CHIP][1];
SCM0[42].o[CHIP][1] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][3] : SCM0[42].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[42].awoo[CHIP][1] = (Ull)(INIT0?SCM0[42].b[CHIP][1]:SCM0[42].awoo[CHIP][1]);
adr = (Uint)(SCM0[42].awoo[CHIP][1] + SCM0[42].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][4] = SCM0[42].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][4] = SCM0[42].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][4] = SCM0[42].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[42].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM1[42].b[CHIP][2]) : SCM1[42].awoo[CHIP][2];
SCM1[42].o[CHIP][2] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][7] : SCM1[42].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[42].awoo[CHIP][2] = (Ull)(INIT0?SCM1[42].b[CHIP][2]:SCM1[42].awoo[CHIP][2]);
adr = (Uint)(SCM1[42].awoo[CHIP][2] + SCM1[42].o[CHIP][2]);
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][2] : SCAR[42].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][9] : 0, 42);
ex3 = exm(SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][1], 42);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[42].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][6] : SCAR[42].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][9] : 0, 42);
ex3 = exm(SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][0], 42);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[42].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][10] : SCAR[42].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][9] : 0, 42);
ex3 = exm(SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][5], 42);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[42].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][14] : SCAR[42].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][9] : 0, 42);
ex3 = exm(SCBR[41].r[CHIP][SCBR[42].enq[CHIP]][4], 42);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[42].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][2] = SCAR[42].r[CHIP][0];
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][3] = SCBR[41].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][6] = SCAR[42].r[CHIP][1];
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][7] = SCBR[41].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][8] = SCBR[41].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][10] = SCAR[42].r[CHIP][2];
}
{
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][14] = SCAR[42].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((43 && SCBR[42].enq[CHIP]==SCBR[42].deq[CHIP]) || SCBR[42].deq[CHIP]!=SCBR[43].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[43].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM1[43].b[CHIP][0]) : SCM1[43].awoo[CHIP][0];
SCM1[43].o[CHIP][0] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][3] : SCM1[43].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[43].awoo[CHIP][0] = (Ull)(INIT0?SCM1[43].b[CHIP][0]:SCM1[43].awoo[CHIP][0]);
adr = (Uint)(SCM1[43].awoo[CHIP][0] + SCM1[43].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][1] = SCM1[43].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][1] = SCM1[43].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][1] = SCM1[43].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[43].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM0[43].b[CHIP][0]) : SCM0[43].awoo[CHIP][0];
SCM0[43].o[CHIP][0] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][3] : SCM0[43].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[43].awoo[CHIP][0] = (Ull)(INIT0?SCM0[43].b[CHIP][0]:SCM0[43].awoo[CHIP][0]);
adr = (Uint)(SCM0[43].awoo[CHIP][0] + SCM0[43].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0] = SCM0[43].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0] = SCM0[43].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0] = SCM0[43].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[43].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM1[43].b[CHIP][1]) : SCM1[43].awoo[CHIP][1];
SCM1[43].o[CHIP][1] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][3] : SCM1[43].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[43].awoo[CHIP][1] = (Ull)(INIT0?SCM1[43].b[CHIP][1]:SCM1[43].awoo[CHIP][1]);
adr = (Uint)(SCM1[43].awoo[CHIP][1] + SCM1[43].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][5] = SCM1[43].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][5] = SCM1[43].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][5] = SCM1[43].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[43].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM0[43].b[CHIP][1]) : SCM0[43].awoo[CHIP][1];
SCM0[43].o[CHIP][1] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][3] : SCM0[43].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[43].awoo[CHIP][1] = (Ull)(INIT0?SCM0[43].b[CHIP][1]:SCM0[43].awoo[CHIP][1]);
adr = (Uint)(SCM0[43].awoo[CHIP][1] + SCM0[43].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][4] = SCM0[43].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][4] = SCM0[43].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][4] = SCM0[43].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[43].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM1[43].b[CHIP][2]) : SCM1[43].awoo[CHIP][2];
SCM1[43].o[CHIP][2] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][7] : SCM1[43].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[43].awoo[CHIP][2] = (Ull)(INIT0?SCM1[43].b[CHIP][2]:SCM1[43].awoo[CHIP][2]);
adr = (Uint)(SCM1[43].awoo[CHIP][2] + SCM1[43].o[CHIP][2]);
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][2] : SCAR[43].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][9] : 0, 43);
ex3 = exm(SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][1], 43);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[43].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][6] : SCAR[43].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][9] : 0, 43);
ex3 = exm(SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][0], 43);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[43].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][10] : SCAR[43].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][9] : 0, 43);
ex3 = exm(SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][5], 43);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[43].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][14] : SCAR[43].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][9] : 0, 43);
ex3 = exm(SCBR[42].r[CHIP][SCBR[43].enq[CHIP]][4], 43);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[43].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][2] = SCAR[43].r[CHIP][0];
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][3] = SCBR[42].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][6] = SCAR[43].r[CHIP][1];
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][7] = SCBR[42].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][8] = SCBR[42].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][10] = SCAR[43].r[CHIP][2];
}
{
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][14] = SCAR[43].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((44 && SCBR[43].enq[CHIP]==SCBR[43].deq[CHIP]) || SCBR[43].deq[CHIP]!=SCBR[44].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[44].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM1[44].b[CHIP][0]) : SCM1[44].awoo[CHIP][0];
SCM1[44].o[CHIP][0] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][3] : SCM1[44].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[44].awoo[CHIP][0] = (Ull)(INIT0?SCM1[44].b[CHIP][0]:SCM1[44].awoo[CHIP][0]);
adr = (Uint)(SCM1[44].awoo[CHIP][0] + SCM1[44].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][1] = SCM1[44].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][1] = SCM1[44].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][1] = SCM1[44].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[44].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM0[44].b[CHIP][0]) : SCM0[44].awoo[CHIP][0];
SCM0[44].o[CHIP][0] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][3] : SCM0[44].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[44].awoo[CHIP][0] = (Ull)(INIT0?SCM0[44].b[CHIP][0]:SCM0[44].awoo[CHIP][0]);
adr = (Uint)(SCM0[44].awoo[CHIP][0] + SCM0[44].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0] = SCM0[44].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0] = SCM0[44].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0] = SCM0[44].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[44].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM1[44].b[CHIP][1]) : SCM1[44].awoo[CHIP][1];
SCM1[44].o[CHIP][1] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][3] : SCM1[44].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[44].awoo[CHIP][1] = (Ull)(INIT0?SCM1[44].b[CHIP][1]:SCM1[44].awoo[CHIP][1]);
adr = (Uint)(SCM1[44].awoo[CHIP][1] + SCM1[44].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][5] = SCM1[44].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][5] = SCM1[44].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][5] = SCM1[44].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[44].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM0[44].b[CHIP][1]) : SCM0[44].awoo[CHIP][1];
SCM0[44].o[CHIP][1] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][3] : SCM0[44].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[44].awoo[CHIP][1] = (Ull)(INIT0?SCM0[44].b[CHIP][1]:SCM0[44].awoo[CHIP][1]);
adr = (Uint)(SCM0[44].awoo[CHIP][1] + SCM0[44].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][4] = SCM0[44].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][4] = SCM0[44].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][4] = SCM0[44].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[44].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM1[44].b[CHIP][2]) : SCM1[44].awoo[CHIP][2];
SCM1[44].o[CHIP][2] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][7] : SCM1[44].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[44].awoo[CHIP][2] = (Ull)(INIT0?SCM1[44].b[CHIP][2]:SCM1[44].awoo[CHIP][2]);
adr = (Uint)(SCM1[44].awoo[CHIP][2] + SCM1[44].o[CHIP][2]);
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][2] : SCAR[44].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][9] : 0, 44);
ex3 = exm(SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][1], 44);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[44].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][6] : SCAR[44].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][9] : 0, 44);
ex3 = exm(SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][0], 44);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[44].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][10] : SCAR[44].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][9] : 0, 44);
ex3 = exm(SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][5], 44);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[44].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][14] : SCAR[44].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][9] : 0, 44);
ex3 = exm(SCBR[43].r[CHIP][SCBR[44].enq[CHIP]][4], 44);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[44].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][2] = SCAR[44].r[CHIP][0];
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][3] = SCBR[43].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][6] = SCAR[44].r[CHIP][1];
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][7] = SCBR[43].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][8] = SCBR[43].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][10] = SCAR[44].r[CHIP][2];
}
{
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][14] = SCAR[44].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((45 && SCBR[44].enq[CHIP]==SCBR[44].deq[CHIP]) || SCBR[44].deq[CHIP]!=SCBR[45].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[45].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM1[45].b[CHIP][0]) : SCM1[45].awoo[CHIP][0];
SCM1[45].o[CHIP][0] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][3] : SCM1[45].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[45].awoo[CHIP][0] = (Ull)(INIT0?SCM1[45].b[CHIP][0]:SCM1[45].awoo[CHIP][0]);
adr = (Uint)(SCM1[45].awoo[CHIP][0] + SCM1[45].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][1] = SCM1[45].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][1] = SCM1[45].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][1] = SCM1[45].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[45].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM0[45].b[CHIP][0]) : SCM0[45].awoo[CHIP][0];
SCM0[45].o[CHIP][0] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][3] : SCM0[45].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[45].awoo[CHIP][0] = (Ull)(INIT0?SCM0[45].b[CHIP][0]:SCM0[45].awoo[CHIP][0]);
adr = (Uint)(SCM0[45].awoo[CHIP][0] + SCM0[45].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0] = SCM0[45].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0] = SCM0[45].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0] = SCM0[45].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[45].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM1[45].b[CHIP][1]) : SCM1[45].awoo[CHIP][1];
SCM1[45].o[CHIP][1] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][3] : SCM1[45].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[45].awoo[CHIP][1] = (Ull)(INIT0?SCM1[45].b[CHIP][1]:SCM1[45].awoo[CHIP][1]);
adr = (Uint)(SCM1[45].awoo[CHIP][1] + SCM1[45].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][5] = SCM1[45].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][5] = SCM1[45].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][5] = SCM1[45].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[45].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM0[45].b[CHIP][1]) : SCM0[45].awoo[CHIP][1];
SCM0[45].o[CHIP][1] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][3] : SCM0[45].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[45].awoo[CHIP][1] = (Ull)(INIT0?SCM0[45].b[CHIP][1]:SCM0[45].awoo[CHIP][1]);
adr = (Uint)(SCM0[45].awoo[CHIP][1] + SCM0[45].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][4] = SCM0[45].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][4] = SCM0[45].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][4] = SCM0[45].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[45].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM1[45].b[CHIP][2]) : SCM1[45].awoo[CHIP][2];
SCM1[45].o[CHIP][2] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][7] : SCM1[45].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[45].awoo[CHIP][2] = (Ull)(INIT0?SCM1[45].b[CHIP][2]:SCM1[45].awoo[CHIP][2]);
adr = (Uint)(SCM1[45].awoo[CHIP][2] + SCM1[45].o[CHIP][2]);
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][2] : SCAR[45].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][9] : 0, 45);
ex3 = exm(SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][1], 45);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[45].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][6] : SCAR[45].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][9] : 0, 45);
ex3 = exm(SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][0], 45);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[45].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][10] : SCAR[45].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][9] : 0, 45);
ex3 = exm(SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][5], 45);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[45].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][14] : SCAR[45].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][9] : 0, 45);
ex3 = exm(SCBR[44].r[CHIP][SCBR[45].enq[CHIP]][4], 45);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[45].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][2] = SCAR[45].r[CHIP][0];
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][3] = SCBR[44].r[CHIP][SCBR[3].enq[CHIP]][0];
}
{
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][6] = SCAR[45].r[CHIP][1];
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][7] = SCBR[44].r[CHIP][SCBR[7].enq[CHIP]][0];
}
{
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][8] = SCBR[44].r[CHIP][SCBR[8].enq[CHIP]][0];
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][10] = SCAR[45].r[CHIP][2];
}
{
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][14] = SCAR[45].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((46 && SCBR[45].enq[CHIP]==SCBR[45].deq[CHIP]) || SCBR[45].deq[CHIP]!=SCBR[46].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[46].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM1[46].b[CHIP][0]) : SCM1[46].awoo[CHIP][0];
SCM1[46].o[CHIP][0] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][3] : SCM1[46].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[46].awoo[CHIP][0] = (Ull)(INIT0?SCM1[46].b[CHIP][0]:SCM1[46].awoo[CHIP][0]);
adr = (Uint)(SCM1[46].awoo[CHIP][0] + SCM1[46].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][1] = SCM1[46].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][1] = SCM1[46].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][1] = SCM1[46].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[46].b[CHIP][0] = (!(0&1)||INIT0) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM0[46].b[CHIP][0]) : SCM0[46].awoo[CHIP][0];
SCM0[46].o[CHIP][0] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][3] : SCM0[46].o[CHIP][0], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[46].awoo[CHIP][0] = (Ull)(INIT0?SCM0[46].b[CHIP][0]:SCM0[46].awoo[CHIP][0]);
adr = (Uint)(SCM0[46].awoo[CHIP][0] + SCM0[46].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0] = SCM0[46].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0] = SCM0[46].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0] = SCM0[46].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[46].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM1[46].b[CHIP][1]) : SCM1[46].awoo[CHIP][1];
SCM1[46].o[CHIP][1] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][3] : SCM1[46].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[46].awoo[CHIP][1] = (Ull)(INIT0?SCM1[46].b[CHIP][1]:SCM1[46].awoo[CHIP][1]);
adr = (Uint)(SCM1[46].awoo[CHIP][1] + SCM1[46].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][5] = SCM1[46].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][5] = SCM1[46].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][5] = SCM1[46].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[46].b[CHIP][1] = (!(0&1)||INIT0) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM0[46].b[CHIP][1]) : SCM0[46].awoo[CHIP][1];
SCM0[46].o[CHIP][1] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][3] : SCM0[46].o[CHIP][1], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM0[46].awoo[CHIP][1] = (Ull)(INIT0?SCM0[46].b[CHIP][1]:SCM0[46].awoo[CHIP][1]);
adr = (Uint)(SCM0[46].awoo[CHIP][1] + SCM0[46].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][4] = SCM0[46].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][4] = SCM0[46].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][4] = SCM0[46].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[46].b[CHIP][2] = (!(0&1)||INIT0) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM1[46].b[CHIP][2]) : SCM1[46].awoo[CHIP][2];
SCM1[46].o[CHIP][2] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][7] : SCM1[46].o[CHIP][2], 13);
mexdist = (0 || INIT0) ? 0 : 0;
SCM1[46].awoo[CHIP][2] = (Ull)(INIT0?SCM1[46].b[CHIP][2]:SCM1[46].awoo[CHIP][2]);
adr = (Uint)(SCM1[46].awoo[CHIP][2] + SCM1[46].o[CHIP][2]);
SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][9] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][2] : SCAR[46].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][9] : 0, 46);
ex3 = exm(SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][1], 46);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[46].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][6] : SCAR[46].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][9] : 0, 46);
ex3 = exm(SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][0], 46);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[46].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][10] : SCAR[46].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][9] : 0, 46);
ex3 = exm(SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][5], 46);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[46].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][14] : SCAR[46].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][9] : 0, 46);
ex3 = exm(SCBR[45].r[CHIP][SCBR[46].enq[CHIP]][4], 46);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[46].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][2] = SCAR[46].r[CHIP][0];
SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][3] = SCBR[45].r[CHIP][SCBR[8].enq[CHIP]][0];
}
{
SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][6] = SCAR[46].r[CHIP][1];
}
{
SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][10] = SCAR[46].r[CHIP][2];
}
{
SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][14] = SCAR[46].r[CHIP][3];
}
}}}
	rofs = (((0-736LL*4)<<32|((0-736LL*4)&0xffffffff)));
for (INIT1=1,uLOOP1=LOOP1; uLOOP1--; INIT1=0) {
	cofs = (((0-4LL*8)<<32|((0-4LL*8)&0xffffffff)));
for (INIT0=1,uLOOP0=LOOP0; uLOOP0--; INIT0=0) {
for (CHIP=0; CHIP<4; CHIP++) {
if ((47 && SCBR[46].enq[CHIP]==SCBR[46].deq[CHIP]) || SCBR[46].deq[CHIP]!=SCBR[47].enq[CHIP]) continue;
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Uint adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][2] : SCAR[47].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][9] : 0, 47);
ex3 = exm(SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][1], 47);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[47].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][6] : SCAR[47].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][9] : 0, 47);
ex3 = exm(SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][0], 47);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[47].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][10] : SCAR[47].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][9] : 0, 47);
ex3 = exm(SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][5], 47);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[47].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1&&INIT0)||((0&1)&&INIT0) ? SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][14] : SCAR[47].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0) ? SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][9] : 0, 47);
ex3 = exm(SCBR[46].r[CHIP][SCBR[47].enq[CHIP]][4], 47);
f1.i = (Uint)(ex1)>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[47].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][0] = SCBR[46].r[CHIP][SCBR[3].enq[CHIP]][0];
SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][2] = SCAR[47].r[CHIP][0];
}
{
SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][6] = SCAR[47].r[CHIP][1];
}
{
SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][10] = SCAR[47].r[CHIP][2];
}
{
SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][14] = SCAR[47].r[CHIP][3];
}
}}}
/* EMAXSC end */
#endif
#ifndef EMAXSC
	emax6.lmmio = emax6.lmmic;
	emax6.lmmic = 1-emax6.lmmic;
	emax6.mapdist = 0;
	*(Uint*)&emax6.lmmi[0][1][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][1][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][1][0][emax6.lmmic].top = b[0];
	*(Uint*)&emax6.lmmi[0][2][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][2][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][2][0][emax6.lmmic].top = b[1];
	*(Uint*)&emax6.lmmi[0][3][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][3][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][3][0][emax6.lmmic].top = b[2];
	*(Uint*)&emax6.lmmi[0][4][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][4][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][4][0][emax6.lmmic].top = b[3];
	*(Uint*)&emax6.lmmi[0][5][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][5][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][5][0][emax6.lmmic].top = b[4];
	*(Uint*)&emax6.lmmi[0][6][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][6][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][6][0][emax6.lmmic].top = b[5];
	*(Uint*)&emax6.lmmi[0][7][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][7][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][7][0][emax6.lmmic].top = b[6];
	*(Uint*)&emax6.lmmi[0][8][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][8][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][8][0][emax6.lmmic].top = b[7];
	*(Uint*)&emax6.lmmi[0][9][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][9][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][9][0][emax6.lmmic].top = b[8];
	*(Uint*)&emax6.lmmi[0][10][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][10][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][10][0][emax6.lmmic].top = b[9];
	*(Uint*)&emax6.lmmi[0][11][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][11][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][11][0][emax6.lmmic].top = b[10];
	*(Uint*)&emax6.lmmi[0][12][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][12][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][12][0][emax6.lmmic].top = b[11];
	*(Uint*)&emax6.lmmi[0][13][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][13][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][13][0][emax6.lmmic].top = b[12];
	*(Uint*)&emax6.lmmi[0][14][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][14][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][14][0][emax6.lmmic].top = b[13];
	*(Uint*)&emax6.lmmi[0][15][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][15][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][15][0][emax6.lmmic].top = b[14];
	*(Uint*)&emax6.lmmi[0][16][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][16][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][16][0][emax6.lmmic].top = b[15];
	*(Uint*)&emax6.lmmi[0][17][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][17][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][17][0][emax6.lmmic].top = b[16];
	*(Uint*)&emax6.lmmi[0][18][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][18][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][18][0][emax6.lmmic].top = b[17];
	*(Uint*)&emax6.lmmi[0][19][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][19][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][19][0][emax6.lmmic].top = b[18];
	*(Uint*)&emax6.lmmi[0][20][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][20][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][20][0][emax6.lmmic].top = b[19];
	*(Uint*)&emax6.lmmi[0][21][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][21][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][21][0][emax6.lmmic].top = b[20];
	*(Uint*)&emax6.lmmi[0][22][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][22][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][22][0][emax6.lmmic].top = b[21];
	*(Uint*)&emax6.lmmi[0][23][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][23][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][23][0][emax6.lmmic].top = b[22];
	*(Uint*)&emax6.lmmi[0][24][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][24][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][24][0][emax6.lmmic].top = b[23];
	*(Uint*)&emax6.lmmi[0][25][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][25][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][25][0][emax6.lmmic].top = b[24];
	*(Uint*)&emax6.lmmi[0][26][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][26][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][26][0][emax6.lmmic].top = b[25];
	*(Uint*)&emax6.lmmi[0][27][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][27][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][27][0][emax6.lmmic].top = b[26];
	*(Uint*)&emax6.lmmi[0][28][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][28][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][28][0][emax6.lmmic].top = b[27];
	*(Uint*)&emax6.lmmi[0][29][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][29][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][29][0][emax6.lmmic].top = b[28];
	*(Uint*)&emax6.lmmi[0][30][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][30][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][30][0][emax6.lmmic].top = b[29];
	*(Uint*)&emax6.lmmi[0][31][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][31][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][31][0][emax6.lmmic].top = b[30];
	*(Uint*)&emax6.lmmi[0][32][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][32][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][32][0][emax6.lmmic].top = b[31];
	*(Uint*)&emax6.lmmi[0][33][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][33][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][33][0][emax6.lmmic].top = b[32];
	*(Uint*)&emax6.lmmi[0][34][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][34][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][34][0][emax6.lmmic].top = b[33];
	*(Uint*)&emax6.lmmi[0][35][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][35][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][35][0][emax6.lmmic].top = b[34];
	*(Uint*)&emax6.lmmi[0][36][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][36][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][36][0][emax6.lmmic].top = b[35];
	*(Uint*)&emax6.lmmi[0][37][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][37][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][37][0][emax6.lmmic].top = b[36];
	*(Uint*)&emax6.lmmi[0][38][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][38][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][38][0][emax6.lmmic].top = b[37];
	*(Uint*)&emax6.lmmi[0][39][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][39][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][39][0][emax6.lmmic].top = b[38];
	*(Uint*)&emax6.lmmi[0][40][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][40][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][40][0][emax6.lmmic].top = b[39];
	*(Uint*)&emax6.lmmi[0][41][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][41][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][41][0][emax6.lmmic].top = b[40];
	*(Uint*)&emax6.lmmi[0][42][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][42][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][42][0][emax6.lmmic].top = b[41];
	*(Uint*)&emax6.lmmi[0][43][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][43][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][43][0][emax6.lmmic].top = b[42];
	*(Uint*)&emax6.lmmi[0][44][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][44][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][44][0][emax6.lmmic].top = b[43];
	*(Uint*)&emax6.lmmi[0][45][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][45][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][45][0][emax6.lmmic].top = b[44];
	*(Uint*)&emax6.lmmi[0][46][0][emax6.lmmic] = 0x02df0021|(0<<2);
	emax6.lmmi[0][46][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][46][0][emax6.lmmic].top = b[45];
	*(Uint*)&emax6.lmmi[0][46][2][emax6.lmmic] = 0x16ff1001|(0<<2);
	emax6.lmmi[0][46][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][46][2][emax6.lmmic].top = a0[0];
	*(Uint*)&emax6.lmmi[1][46][2][emax6.lmmic] = 0x16ff1001|(0<<2);
	emax6.lmmi[1][46][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[1][46][2][emax6.lmmic].top = a0[1];
	*(Uint*)&emax6.lmmi[2][46][2][emax6.lmmic] = 0x16ff1001|(0<<2);
	emax6.lmmi[2][46][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[2][46][2][emax6.lmmic].top = a0[2];
	*(Uint*)&emax6.lmmi[3][46][2][emax6.lmmic] = 0x16ff1001|(0<<2);
	emax6.lmmi[3][46][2][emax6.lmmic].ofs = 0;
	emax6.lmmi[3][46][2][emax6.lmmic].top = a0[3];
	*(Uint*)&emax6.lmmi[0][48][0][emax6.lmmic] = 0x16ff10e7|(1<<2);
	emax6.lmmi[0][48][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[0][48][0][emax6.lmmic].top = c0[0];
	*(Uint*)&emax6.lmmi[1][48][0][emax6.lmmic] = 0x16ff10e7|(1<<2);
	emax6.lmmi[1][48][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[1][48][0][emax6.lmmic].top = c0[1];
	*(Uint*)&emax6.lmmi[2][48][0][emax6.lmmic] = 0x16ff10e7|(1<<2);
	emax6.lmmi[2][48][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[2][48][0][emax6.lmmic].top = c0[2];
	*(Uint*)&emax6.lmmi[3][48][0][emax6.lmmic] = 0x16ff10e7|(1<<2);
	emax6.lmmi[3][48][0][emax6.lmmic].ofs = 0;
	emax6.lmmi[3][48][0][emax6.lmmic].top = c0[3];
	emax6.lmmi_bitmap[0] = 0x00017ffffffffffeLL;
	emax6.lmmi_bitmap[1] = 0x0000000000000000LL;
	emax6.lmmi_bitmap[2] = 0x0000400000000000LL;
	emax6.lmmi_bitmap[3] = 0x0000000000000000LL;
	emax6_pre_with_drain_cache();
	get_nanosec(NANOS_ARM);
	if (emax6.last_conf == emax6_conf_mm) {
	  emax6.status = STATUS_DRAIN;
	  emax6_check_lmmi_and_dma(0, 1, 0, 0, 48, 0);/*drain*/
	  emax6_check_lmmi_and_dma(0, 1, 0, 1, 48, 0);/*drain*/
	  emax6_check_lmmi_and_dma(0, 1, 0, 2, 48, 0);/*drain*/
	  emax6_check_lmmi_and_dma(0, 1, 0, 3, 48, 0);/*drain*/
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
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[0] = (((4LL)*(8))<<(32))|((4LL)*(8));
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[1] = rofs;
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].breg[63][1].br[2] = (((736LL)*(4))<<(32))|((736LL)*(4));
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][0].ea0b = (Ull)b1[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][0].ea1b = (Ull)b0[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][1].ea0b = (Ull)b3[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][1].ea1b = (Ull)b2[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[1][2].ea1b = (Ull)a[0][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[1][2].ea1b = (Ull)a[0][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[1][2].ea1b = (Ull)a[0][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[1][2].ea1b = (Ull)a[0][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][0].ea0b = (Ull)b1[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][0].ea1b = (Ull)b0[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][1].ea0b = (Ull)b3[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][1].ea1b = (Ull)b2[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[2][2].ea1b = (Ull)a[1][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[2][2].ea1b = (Ull)a[1][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[2][2].ea1b = (Ull)a[1][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[2][2].ea1b = (Ull)a[1][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][0].ea0b = (Ull)b1[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][0].ea1b = (Ull)b0[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][1].ea0b = (Ull)b3[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][1].ea1b = (Ull)b2[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[3][2].ea1b = (Ull)a[2][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[3][2].ea1b = (Ull)a[2][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[3][2].ea1b = (Ull)a[2][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[3][2].ea1b = (Ull)a[2][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][0].ea0b = (Ull)b1[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][0].ea1b = (Ull)b0[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][1].ea0b = (Ull)b3[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][1].ea1b = (Ull)b2[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[4][2].ea1b = (Ull)a[3][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[4][2].ea1b = (Ull)a[3][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[4][2].ea1b = (Ull)a[3][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[4][2].ea1b = (Ull)a[3][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][0].ea0b = (Ull)b1[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][0].ea1b = (Ull)b0[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][1].ea0b = (Ull)b3[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][1].ea1b = (Ull)b2[4];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[5][2].ea1b = (Ull)a[4][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[5][2].ea1b = (Ull)a[4][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[5][2].ea1b = (Ull)a[4][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[5][2].ea1b = (Ull)a[4][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][0].ea0b = (Ull)b1[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][0].ea1b = (Ull)b0[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][1].ea0b = (Ull)b3[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][1].ea1b = (Ull)b2[5];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[6][2].ea1b = (Ull)a[5][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[6][2].ea1b = (Ull)a[5][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[6][2].ea1b = (Ull)a[5][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[6][2].ea1b = (Ull)a[5][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][0].ea0b = (Ull)b1[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][0].ea1b = (Ull)b0[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][1].ea0b = (Ull)b3[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][1].ea1b = (Ull)b2[6];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[7][2].ea1b = (Ull)a[6][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[7][2].ea1b = (Ull)a[6][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[7][2].ea1b = (Ull)a[6][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[7][2].ea1b = (Ull)a[6][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][0].ea0b = (Ull)b1[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][0].ea1b = (Ull)b0[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][1].ea0b = (Ull)b3[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][1].ea1b = (Ull)b2[7];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[8][2].ea1b = (Ull)a[7][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[8][2].ea1b = (Ull)a[7][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[8][2].ea1b = (Ull)a[7][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[8][2].ea1b = (Ull)a[7][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][0].ea0b = (Ull)b1[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][0].ea1b = (Ull)b0[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][1].ea0b = (Ull)b3[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][1].ea1b = (Ull)b2[8];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[9][2].ea1b = (Ull)a[8][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[9][2].ea1b = (Ull)a[8][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[9][2].ea1b = (Ull)a[8][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[9][2].ea1b = (Ull)a[8][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][0].ea0b = (Ull)b1[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][0].ea1b = (Ull)b0[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][1].ea0b = (Ull)b3[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][1].ea1b = (Ull)b2[9];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[10][2].ea1b = (Ull)a[9][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[10][2].ea1b = (Ull)a[9][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[10][2].ea1b = (Ull)a[9][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[10][2].ea1b = (Ull)a[9][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][0].ea0b = (Ull)b1[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][0].ea1b = (Ull)b0[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][1].ea0b = (Ull)b3[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][1].ea1b = (Ull)b2[10];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[11][2].ea1b = (Ull)a[10][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[11][2].ea1b = (Ull)a[10][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[11][2].ea1b = (Ull)a[10][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[11][2].ea1b = (Ull)a[10][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][0].ea0b = (Ull)b1[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][0].ea1b = (Ull)b0[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][1].ea0b = (Ull)b3[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][1].ea1b = (Ull)b2[11];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[12][2].ea1b = (Ull)a[11][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[12][2].ea1b = (Ull)a[11][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[12][2].ea1b = (Ull)a[11][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[12][2].ea1b = (Ull)a[11][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][0].ea0b = (Ull)b1[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][0].ea1b = (Ull)b0[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][1].ea0b = (Ull)b3[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][1].ea1b = (Ull)b2[12];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[13][2].ea1b = (Ull)a[12][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[13][2].ea1b = (Ull)a[12][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[13][2].ea1b = (Ull)a[12][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[13][2].ea1b = (Ull)a[12][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][0].ea0b = (Ull)b1[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][0].ea1b = (Ull)b0[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][1].ea0b = (Ull)b3[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][1].ea1b = (Ull)b2[13];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[14][2].ea1b = (Ull)a[13][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[14][2].ea1b = (Ull)a[13][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[14][2].ea1b = (Ull)a[13][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[14][2].ea1b = (Ull)a[13][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][0].ea0b = (Ull)b1[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][0].ea1b = (Ull)b0[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][1].ea0b = (Ull)b3[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][1].ea1b = (Ull)b2[14];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[15][2].ea1b = (Ull)a[14][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[15][2].ea1b = (Ull)a[14][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[15][2].ea1b = (Ull)a[14][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[15][2].ea1b = (Ull)a[14][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][0].ea0b = (Ull)b1[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][0].ea1b = (Ull)b0[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][1].ea0b = (Ull)b3[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][1].ea1b = (Ull)b2[15];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[16][2].ea1b = (Ull)a[15][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[16][2].ea1b = (Ull)a[15][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[16][2].ea1b = (Ull)a[15][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[16][2].ea1b = (Ull)a[15][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][0].ea0b = (Ull)b1[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][0].ea1b = (Ull)b0[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][1].ea0b = (Ull)b3[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][1].ea1b = (Ull)b2[16];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[17][2].ea1b = (Ull)a[16][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[17][2].ea1b = (Ull)a[16][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[17][2].ea1b = (Ull)a[16][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[17][2].ea1b = (Ull)a[16][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][0].ea0b = (Ull)b1[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][0].ea1b = (Ull)b0[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][1].ea0b = (Ull)b3[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][1].ea1b = (Ull)b2[17];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[18][2].ea1b = (Ull)a[17][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[18][2].ea1b = (Ull)a[17][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[18][2].ea1b = (Ull)a[17][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[18][2].ea1b = (Ull)a[17][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][0].ea0b = (Ull)b1[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][0].ea1b = (Ull)b0[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][1].ea0b = (Ull)b3[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][1].ea1b = (Ull)b2[18];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[19][2].ea1b = (Ull)a[18][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[19][2].ea1b = (Ull)a[18][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[19][2].ea1b = (Ull)a[18][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[19][2].ea1b = (Ull)a[18][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][0].ea0b = (Ull)b1[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][0].ea1b = (Ull)b0[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][1].ea0b = (Ull)b3[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][1].ea1b = (Ull)b2[19];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[20][2].ea1b = (Ull)a[19][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[20][2].ea1b = (Ull)a[19][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[20][2].ea1b = (Ull)a[19][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[20][2].ea1b = (Ull)a[19][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][0].ea0b = (Ull)b1[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][0].ea1b = (Ull)b0[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][1].ea0b = (Ull)b3[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][1].ea1b = (Ull)b2[20];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[21][2].ea1b = (Ull)a[20][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[21][2].ea1b = (Ull)a[20][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[21][2].ea1b = (Ull)a[20][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[21][2].ea1b = (Ull)a[20][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][0].ea0b = (Ull)b1[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][0].ea1b = (Ull)b0[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][1].ea0b = (Ull)b3[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][1].ea1b = (Ull)b2[21];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[22][2].ea1b = (Ull)a[21][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[22][2].ea1b = (Ull)a[21][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[22][2].ea1b = (Ull)a[21][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[22][2].ea1b = (Ull)a[21][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][0].ea0b = (Ull)b1[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][0].ea1b = (Ull)b0[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][1].ea0b = (Ull)b3[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][1].ea1b = (Ull)b2[22];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[23][2].ea1b = (Ull)a[22][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[23][2].ea1b = (Ull)a[22][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[23][2].ea1b = (Ull)a[22][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[23][2].ea1b = (Ull)a[22][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][0].ea0b = (Ull)b1[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][0].ea1b = (Ull)b0[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][1].ea0b = (Ull)b3[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][1].ea1b = (Ull)b2[23];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[24][2].ea1b = (Ull)a[23][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[24][2].ea1b = (Ull)a[23][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[24][2].ea1b = (Ull)a[23][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[24][2].ea1b = (Ull)a[23][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][0].ea0b = (Ull)b1[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][0].ea1b = (Ull)b0[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][1].ea0b = (Ull)b3[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][1].ea1b = (Ull)b2[24];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[25][2].ea1b = (Ull)a[24][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[25][2].ea1b = (Ull)a[24][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[25][2].ea1b = (Ull)a[24][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[25][2].ea1b = (Ull)a[24][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][0].ea0b = (Ull)b1[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][0].ea1b = (Ull)b0[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][1].ea0b = (Ull)b3[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][1].ea1b = (Ull)b2[25];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[26][2].ea1b = (Ull)a[25][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[26][2].ea1b = (Ull)a[25][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[26][2].ea1b = (Ull)a[25][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[26][2].ea1b = (Ull)a[25][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][0].ea0b = (Ull)b1[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][0].ea1b = (Ull)b0[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][1].ea0b = (Ull)b3[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][1].ea1b = (Ull)b2[26];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[27][2].ea1b = (Ull)a[26][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[27][2].ea1b = (Ull)a[26][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[27][2].ea1b = (Ull)a[26][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[27][2].ea1b = (Ull)a[26][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][0].ea0b = (Ull)b1[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][0].ea1b = (Ull)b0[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][1].ea0b = (Ull)b3[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][1].ea1b = (Ull)b2[27];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[28][2].ea1b = (Ull)a[27][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[28][2].ea1b = (Ull)a[27][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[28][2].ea1b = (Ull)a[27][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[28][2].ea1b = (Ull)a[27][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][0].ea0b = (Ull)b1[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][0].ea1b = (Ull)b0[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][1].ea0b = (Ull)b3[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][1].ea1b = (Ull)b2[28];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[29][2].ea1b = (Ull)a[28][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[29][2].ea1b = (Ull)a[28][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[29][2].ea1b = (Ull)a[28][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[29][2].ea1b = (Ull)a[28][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][0].ea0b = (Ull)b1[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][0].ea1b = (Ull)b0[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][1].ea0b = (Ull)b3[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][1].ea1b = (Ull)b2[29];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[30][2].ea1b = (Ull)a[29][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[30][2].ea1b = (Ull)a[29][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[30][2].ea1b = (Ull)a[29][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[30][2].ea1b = (Ull)a[29][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][0].ea0b = (Ull)b1[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][0].ea1b = (Ull)b0[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][1].ea0b = (Ull)b3[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][1].ea1b = (Ull)b2[30];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[31][2].ea1b = (Ull)a[30][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[31][2].ea1b = (Ull)a[30][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[31][2].ea1b = (Ull)a[30][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[31][2].ea1b = (Ull)a[30][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][0].ea0b = (Ull)b1[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][0].ea1b = (Ull)b0[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][1].ea0b = (Ull)b3[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][1].ea1b = (Ull)b2[31];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[32][2].ea1b = (Ull)a[31][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[32][2].ea1b = (Ull)a[31][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[32][2].ea1b = (Ull)a[31][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[32][2].ea1b = (Ull)a[31][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][0].ea0b = (Ull)b1[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][0].ea1b = (Ull)b0[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][1].ea0b = (Ull)b3[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][1].ea1b = (Ull)b2[32];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[33][2].ea1b = (Ull)a[32][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[33][2].ea1b = (Ull)a[32][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[33][2].ea1b = (Ull)a[32][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[33][2].ea1b = (Ull)a[32][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][0].ea0b = (Ull)b1[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][0].ea1b = (Ull)b0[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][1].ea0b = (Ull)b3[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][1].ea1b = (Ull)b2[33];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[34][2].ea1b = (Ull)a[33][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[34][2].ea1b = (Ull)a[33][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[34][2].ea1b = (Ull)a[33][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[34][2].ea1b = (Ull)a[33][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][0].ea0b = (Ull)b1[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][0].ea1b = (Ull)b0[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][1].ea0b = (Ull)b3[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][1].ea1b = (Ull)b2[34];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[35][2].ea1b = (Ull)a[34][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[35][2].ea1b = (Ull)a[34][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[35][2].ea1b = (Ull)a[34][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[35][2].ea1b = (Ull)a[34][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][0].ea0b = (Ull)b1[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][0].ea1b = (Ull)b0[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][1].ea0b = (Ull)b3[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][1].ea1b = (Ull)b2[35];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[36][2].ea1b = (Ull)a[35][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[36][2].ea1b = (Ull)a[35][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[36][2].ea1b = (Ull)a[35][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[36][2].ea1b = (Ull)a[35][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][0].ea0b = (Ull)b1[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][0].ea1b = (Ull)b0[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][1].ea0b = (Ull)b3[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][1].ea1b = (Ull)b2[36];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[37][2].ea1b = (Ull)a[36][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[37][2].ea1b = (Ull)a[36][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[37][2].ea1b = (Ull)a[36][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[37][2].ea1b = (Ull)a[36][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][0].ea0b = (Ull)b1[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][0].ea1b = (Ull)b0[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][1].ea0b = (Ull)b3[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][1].ea1b = (Ull)b2[37];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[38][2].ea1b = (Ull)a[37][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[38][2].ea1b = (Ull)a[37][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[38][2].ea1b = (Ull)a[37][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[38][2].ea1b = (Ull)a[37][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][0].ea0b = (Ull)b1[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][0].ea1b = (Ull)b0[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][1].ea0b = (Ull)b3[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][1].ea1b = (Ull)b2[38];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[39][2].ea1b = (Ull)a[38][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[39][2].ea1b = (Ull)a[38][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[39][2].ea1b = (Ull)a[38][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[39][2].ea1b = (Ull)a[38][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][0].ea0b = (Ull)b1[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][0].ea1b = (Ull)b0[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][1].ea0b = (Ull)b3[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][1].ea1b = (Ull)b2[39];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[40][2].ea1b = (Ull)a[39][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[40][2].ea1b = (Ull)a[39][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[40][2].ea1b = (Ull)a[39][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[40][2].ea1b = (Ull)a[39][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][0].ea0b = (Ull)b1[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][0].ea1b = (Ull)b0[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][1].ea0b = (Ull)b3[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][1].ea1b = (Ull)b2[40];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[41][2].ea1b = (Ull)a[40][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[41][2].ea1b = (Ull)a[40][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[41][2].ea1b = (Ull)a[40][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[41][2].ea1b = (Ull)a[40][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][0].ea0b = (Ull)b1[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][0].ea1b = (Ull)b0[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][1].ea0b = (Ull)b3[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][1].ea1b = (Ull)b2[41];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[42][2].ea1b = (Ull)a[41][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[42][2].ea1b = (Ull)a[41][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[42][2].ea1b = (Ull)a[41][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[42][2].ea1b = (Ull)a[41][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][0].ea0b = (Ull)b1[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][0].ea1b = (Ull)b0[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][1].ea0b = (Ull)b3[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][1].ea1b = (Ull)b2[42];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[43][2].ea1b = (Ull)a[42][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[43][2].ea1b = (Ull)a[42][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[43][2].ea1b = (Ull)a[42][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[43][2].ea1b = (Ull)a[42][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][0].ea0b = (Ull)b1[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][0].ea1b = (Ull)b0[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][1].ea0b = (Ull)b3[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][1].ea1b = (Ull)b2[43];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[44][2].ea1b = (Ull)a[43][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[44][2].ea1b = (Ull)a[43][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[44][2].ea1b = (Ull)a[43][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[44][2].ea1b = (Ull)a[43][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][0].ea0b = (Ull)b1[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][0].ea1b = (Ull)b0[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][1].ea0b = (Ull)b3[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][1].ea1b = (Ull)b2[44];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[45][2].ea1b = (Ull)a[44][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[45][2].ea1b = (Ull)a[44][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[45][2].ea1b = (Ull)a[44][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[45][2].ea1b = (Ull)a[44][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][0].ea0b = (Ull)b1[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][0].ea1b = (Ull)b0[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][1].ea0b = (Ull)b3[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][1].ea1b = (Ull)b2[45];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[46][2].ea1b = (Ull)a[45][0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[46][2].ea1b = (Ull)a[45][1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[46][2].ea1b = (Ull)a[45][2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[46][2].ea1b = (Ull)a[45][3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][0].ea0o = (Ull)c00[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][0].ea0o = (Ull)c00[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][0].ea0o = (Ull)c00[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][0].ea0o = (Ull)c00[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][0].ea1b = (Ull)c00[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][0].ea1b = (Ull)c00[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][0].ea1b = (Ull)c00[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][0].ea1b = (Ull)c00[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][1].ea0o = (Ull)c01[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][1].ea0o = (Ull)c01[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][1].ea0o = (Ull)c01[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][1].ea0o = (Ull)c01[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][1].ea1b = (Ull)c01[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][1].ea1b = (Ull)c01[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][1].ea1b = (Ull)c01[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][1].ea1b = (Ull)c01[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][2].ea0o = (Ull)c02[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][2].ea0o = (Ull)c02[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][2].ea0o = (Ull)c02[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][2].ea0o = (Ull)c02[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][2].ea1b = (Ull)c02[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][2].ea1b = (Ull)c02[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][2].ea1b = (Ull)c02[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][2].ea1b = (Ull)c02[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][3].ea0o = (Ull)c03[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][3].ea0o = (Ull)c03[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][3].ea0o = (Ull)c03[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][3].ea0o = (Ull)c03[3];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].addr[48][3].ea1b = (Ull)c03[0];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[1].addr[48][3].ea1b = (Ull)c03[1];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[2].addr[48][3].ea1b = (Ull)c03[2];
	((struct reg_ctrl*)emax6.reg_ctrl)->i[3].addr[48][3].ea1b = (Ull)c03[3];
	get_nanosec(NANOS_REGV);
	emax6.status = STATUS_RANGE;
	{struct reg_ctrl *reg_ctrl = emax6.reg_ctrl;
	 Uint            lmmic     = emax6.lmmic;
	*(Ull*)&(reg_ctrl->i[0].addr[1][0].top) = ((Ull)(emax6.lmmi[0][1][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][1][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][1][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[1][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[1][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[1][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[1][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[2][0].top) = ((Ull)(emax6.lmmi[0][2][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][2][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][2][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[2][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[2][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[2][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[2][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[3][0].top) = ((Ull)(emax6.lmmi[0][3][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][3][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][3][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[3][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[3][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[3][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[3][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[4][0].top) = ((Ull)(emax6.lmmi[0][4][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][4][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][4][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[4][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[4][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[4][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[4][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[5][0].top) = ((Ull)(emax6.lmmi[0][5][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][5][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][5][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[5][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[5][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[5][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[5][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[6][0].top) = ((Ull)(emax6.lmmi[0][6][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][6][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][6][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[6][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[6][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[6][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[6][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[7][0].top) = ((Ull)(emax6.lmmi[0][7][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][7][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][7][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[7][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[7][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[7][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[7][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[8][0].top) = ((Ull)(emax6.lmmi[0][8][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][8][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][8][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[8][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[8][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[8][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[8][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[9][0].top) = ((Ull)(emax6.lmmi[0][9][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][9][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][9][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[9][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[9][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[9][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[9][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[10][0].top) = ((Ull)(emax6.lmmi[0][10][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][10][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][10][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[10][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[10][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[10][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[10][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[11][0].top) = ((Ull)(emax6.lmmi[0][11][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][11][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][11][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[11][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[11][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[11][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[11][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[12][0].top) = ((Ull)(emax6.lmmi[0][12][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][12][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][12][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[12][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[12][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[12][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[12][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[13][0].top) = ((Ull)(emax6.lmmi[0][13][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][13][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][13][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[13][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[13][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[13][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[13][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[14][0].top) = ((Ull)(emax6.lmmi[0][14][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][14][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][14][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[14][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[14][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[14][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[14][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[15][0].top) = ((Ull)(emax6.lmmi[0][15][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][15][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][15][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[15][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[15][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[15][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[15][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[16][0].top) = ((Ull)(emax6.lmmi[0][16][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][16][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][16][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[16][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[16][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[16][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[16][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[17][0].top) = ((Ull)(emax6.lmmi[0][17][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][17][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][17][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[17][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[17][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[17][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[17][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[18][0].top) = ((Ull)(emax6.lmmi[0][18][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][18][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][18][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[18][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[18][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[18][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[18][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[19][0].top) = ((Ull)(emax6.lmmi[0][19][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][19][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][19][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[19][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[19][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[19][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[19][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[20][0].top) = ((Ull)(emax6.lmmi[0][20][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][20][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][20][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[20][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[20][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[20][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[20][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[21][0].top) = ((Ull)(emax6.lmmi[0][21][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][21][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][21][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[21][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[21][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[21][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[21][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[22][0].top) = ((Ull)(emax6.lmmi[0][22][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][22][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][22][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[22][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[22][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[22][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[22][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[23][0].top) = ((Ull)(emax6.lmmi[0][23][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][23][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][23][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[23][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[23][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[23][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[23][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[24][0].top) = ((Ull)(emax6.lmmi[0][24][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][24][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][24][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[24][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[24][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[24][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[24][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[25][0].top) = ((Ull)(emax6.lmmi[0][25][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][25][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][25][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[25][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[25][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[25][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[25][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[26][0].top) = ((Ull)(emax6.lmmi[0][26][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][26][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][26][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[26][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[26][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[26][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[26][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[27][0].top) = ((Ull)(emax6.lmmi[0][27][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][27][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][27][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[27][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[27][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[27][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[27][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[28][0].top) = ((Ull)(emax6.lmmi[0][28][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][28][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][28][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[28][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[28][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[28][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[28][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[29][0].top) = ((Ull)(emax6.lmmi[0][29][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][29][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][29][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[29][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[29][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[29][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[29][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[30][0].top) = ((Ull)(emax6.lmmi[0][30][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][30][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][30][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[30][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[30][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[30][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[30][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[31][0].top) = ((Ull)(emax6.lmmi[0][31][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][31][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][31][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[31][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[31][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[31][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[31][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[32][0].top) = ((Ull)(emax6.lmmi[0][32][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][32][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][32][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[32][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[32][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[32][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[32][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[33][0].top) = ((Ull)(emax6.lmmi[0][33][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][33][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][33][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[33][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[33][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[33][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[33][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[34][0].top) = ((Ull)(emax6.lmmi[0][34][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][34][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][34][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[34][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[34][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[34][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[34][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[35][0].top) = ((Ull)(emax6.lmmi[0][35][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][35][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][35][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[35][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[35][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[35][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[35][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[36][0].top) = ((Ull)(emax6.lmmi[0][36][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][36][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][36][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[36][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[36][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[36][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[36][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[37][0].top) = ((Ull)(emax6.lmmi[0][37][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][37][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][37][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[37][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[37][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[37][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[37][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[38][0].top) = ((Ull)(emax6.lmmi[0][38][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][38][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][38][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[38][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[38][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[38][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[38][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[39][0].top) = ((Ull)(emax6.lmmi[0][39][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][39][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][39][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[39][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[39][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[39][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[39][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[40][0].top) = ((Ull)(emax6.lmmi[0][40][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][40][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][40][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[40][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[40][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[40][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[40][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[41][0].top) = ((Ull)(emax6.lmmi[0][41][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][41][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][41][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[41][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[41][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[41][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[41][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[42][0].top) = ((Ull)(emax6.lmmi[0][42][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][42][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][42][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[42][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[42][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[42][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[42][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[43][0].top) = ((Ull)(emax6.lmmi[0][43][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][43][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][43][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[43][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[43][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[43][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[43][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[44][0].top) = ((Ull)(emax6.lmmi[0][44][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][44][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][44][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[44][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[44][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[44][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[44][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[45][0].top) = ((Ull)(emax6.lmmi[0][45][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][45][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][45][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[45][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[45][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[45][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[45][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[46][0].top) = ((Ull)(emax6.lmmi[0][46][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[46][2].top) = ((Ull)(emax6.lmmi[0][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[0][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[46][2].top) = ((Ull)(emax6.lmmi[1][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[1][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[46][2].top) = ((Ull)(emax6.lmmi[2][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[2][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[46][2].top) = ((Ull)(emax6.lmmi[3][46][2][lmmic].top+*((Ushort*)&emax6.lmmi[3][46][2][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[48][0].top) = ((Ull)(emax6.lmmi[0][48][0][lmmic].top+*((Ushort*)&emax6.lmmi[0][48][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[0][48][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[1].addr[48][0].top) = ((Ull)(emax6.lmmi[1][48][0][lmmic].top+*((Ushort*)&emax6.lmmi[1][48][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[1][48][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[2].addr[48][0].top) = ((Ull)(emax6.lmmi[2][48][0][lmmic].top+*((Ushort*)&emax6.lmmi[2][48][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[2][48][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[3].addr[48][0].top) = ((Ull)(emax6.lmmi[3][48][0][lmmic].top+*((Ushort*)&emax6.lmmi[3][48][0][lmmic]+1)*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax6.lmmi[3][48][0][lmmic].top;
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
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 46, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 1, 46, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 2, 46, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 3, 46, 2);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 0, 48, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 1, 48, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 2, 48, 0);/*load*/
	emax6_check_lmmi_and_dma(0, 2, emax6.lastdist, 3, 48, 0);/*load*/
	get_nanosec(NANOS_LOAD);
	((struct reg_ctrl*)emax6.reg_ctrl)->i[0].cmd = 3LL; // EXEC
	{struct reg_ctrl *reg_ctrl = emax6.reg_ctrl;
	 Uint            lmmic     = emax6.lmmic;
	}
	emax6.lmmd[48][0] = 0xff>>4;
	while (((struct reg_ctrl*)emax6.reg_ctrl)->i[0].stat); //LMRING_BUSY|EXRING_BUSY
	get_nanosec(NANOS_EXEC);
asm volatile("b emax6_conf_end_mm\n"
".align 5\n"
".global emax6_conf_mm\n"
"emax6_conf_mm:\n"
"	.word	0x00224005, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00220005, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x008260ad, 0x00001000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0xffffffff, 0xffffffff\n"
"	.word	0x00c2a02d, 0x00002000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0141c0ad, 0x00000000\n"
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
"	.word	0x01202027, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x01200027, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00806000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120a027, 0x00000000\n"
"	.word	0xffff0000, 0x60d83000\n"
"	.word	0x00020002, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x01208027, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00807000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00020008, 0x0003007c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00808000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x30d81d81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x70d83000\n"
"	.word	0x00000000, 0x00030078\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11204021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00020003, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0120c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51214021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4121c021, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00200025, 0x00004000\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab826002, 0x0006811c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00a06025, 0x00004000\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab82e00a, 0x0006811c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x01208025, 0x00004000\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab020000, 0x0006801c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x01a0e025, 0x00004000\n"
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
#endif
    }
  }
#ifndef EMAXSC
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
#endif
}
