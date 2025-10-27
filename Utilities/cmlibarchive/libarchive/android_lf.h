#ifndef ANDROID_LF_H
#define ANDROID_LF_H
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#if defined(__ANDROID__)
#define lstat64 lstat
#define stat64 stat
#define fstat64 fstat
#define open64 open
#define lseek64 lseek
#define off64_t off_t
#define ftruncate64 ftruncate
#endif
#endif