#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>
#include <unistd.h>

#define MAXLINE 4096
#define BUFSIZE 1500
#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;
typedef	void Sigfunc(int);        /* for signal handlers */

/* the following are a few definitions from Stevens' unp.h */
char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
void sock_set_port(struct sockaddr *sa, socklen_t salen, int port);
Sigfunc *Signal(int signo, Sigfunc *func);

int sock_cmp_addr(const struct sockaddr *sa1,
		  const struct sockaddr *sa2, socklen_t salen);
void Write(int fd, void *ptr, size_t nbytes);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);

void *Calloc(size_t n, size_t size);
void Gettimeofday(struct timeval *tv, void *foo);
void Setsockopt(int fd, int level, int optname, const void *optval,
		socklen_t optlen);
void Pipe(int *fds);

void loop_ttl();

/* the following are prototypes for the Stevens utilities in util.c */
struct addrinfo *Host_serv(const char *host, const char *serv,
			   int family, int socktype);
void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	    const struct sockaddr *sa, socklen_t salen);

void err_sys (char *fmt, ...);
void err_quit (char *fmt, ...);


char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];

int max_ttl;
int datalen;
int sendfd, recvfd;
int pipefd[2];              /* the pipe for the alarm handler */

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;

socklen_t salen;                    /* length of a socket address */

u_short sport;                      /* source UDP port # */
                                    /* 668 = the neighbor of the beast */
Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];
