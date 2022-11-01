#include <stdio.h>
#include <sys/types.h>
#include <winsock2.h>

struct sockaddr
{
    unsigned short sa_family; // address family
    char sa_data[14];         // protocol specific address
};
struct in_adrr
{
    unsigned long s_address; // 32 bit ip in network byte order
};
struct sockaddr_in
{
    short int sin_family;        // address fomily
    unsigned short int sin_port; // service port
    struct in_adrr sin_adrr;     // ip addr
    unsigned char sin_zero[8];   // not used
};
struct hostent
{
    char *h_name;          // name of host
    char **h_aliases;      // list of aliases
    int h_adrr_type;       // address family
    int h_len;             // length of the ip
    char **h_addr_list[0]; // internet addresses
};
struct servant
{
    char *s_name;     // official name of the service
    char **s_aliases; // Alias
    int s_port;       // port numbers
    char *s_proto;    // protocols
};
// system calls
int socket(int fam, int type, int prot);                      // create endpont
int bind(int sockid, struct sockaddr *maddr, int addr);       // assign a unique address
int listen(int sockid, int backlog);                          // wait for connection
int connect(int sockid, struct sockaddr *maddr, int addrlen); // connect to address
int accept(int sockid, struct sockaddr *peer, int *addrlen);  // accept a connection
int send(int sockId, const void *msg);
int recv(int sockid, void *buf, int len, int flags);
int close(int sockid);
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *errorfds, struct timeval *timeout);

int main()
{

    return 0;
}