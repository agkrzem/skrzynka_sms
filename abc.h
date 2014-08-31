#ifndef ABC_H_INCLUDED
#define ABC_H_INCLUDED

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int net_init(string ipaddr, unsigned short port);
int net_send(string s);
void net_done();
void* net_receiver(void*);
void net_start_receiver( void (*listener)(string sender, string message) );

#endif // ABC_H_INCLUDED
