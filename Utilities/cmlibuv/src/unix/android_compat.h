#ifndef ANDROID_COMPAT_H
#define ANDROID_COMPAT_H
#if defined(__ANDROID__)
#include <unistd.h>
#include <fcntl.h>
static inline int pipe2(int pipefd[2], int flags) {
  int ret = pipe(pipefd);
  if (ret == 0) {
    if (flags & O_CLOEXEC) {
      fcntl(pipefd[0], F_SETFD, FD_CLOEXEC);
      fcntl(pipefd[1], F_SETFD, FD_CLOEXEC);
    }
    if (flags & O_NONBLOCK) {
      fcntl(pipefd[0], F_SETFL, O_NONBLOCK);
      fcntl(pipefd[1], F_SETFL, O_NONBLOCK);
    }
  }
  return ret;
}
#endif
#endif