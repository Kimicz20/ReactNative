// Definition of the ServerSocket class

#ifndef ServerSocket_class
#define ServerSocket_class

#include "Socket.h"
#include <stdlib.h>
#include "string.h"



class ServerSocket : private Socket
{
 public:

  ServerSocket ( int port );
  ServerSocket (){};
  virtual ~ServerSocket();

  const ServerSocket& operator << ( const std::string& ) const;
  const ServerSocket& operator >> ( std::string& ) const;

  void receive ( std::string &s);
  void receiveWithFile ();

  void accept ( ServerSocket& );

  //必须定义为静态成员函数,phread
  static void* serverReceive(void* arg);
};


#endif
