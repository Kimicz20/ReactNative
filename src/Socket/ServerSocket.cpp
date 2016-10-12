// Implementation of the ServerSocket class
#include "../../include/ServerSocket.h"
#include "../../include/Parameter.h"

using namespace std;

ServerSocket::ServerSocket ( int port )
{
  if ( ! Socket::create() )
    {
      throw SocketException ( "不能创建Socket连接." );
    }

  if ( ! Socket::bind ( port ) )
    {
      throw SocketException ( "不能绑定该端口." );
    }

  if ( ! Socket::listen() )
    {
      throw SocketException ( "不能监听该Socket端口." );
    }

}

ServerSocket::~ServerSocket()
{
}

const ServerSocket& ServerSocket::operator << ( const std::string& s ) const
{
  if ( ! Socket::send ( s ) )
    {
      throw SocketException ( "不能改写该Socket." );
    }

  return *this;

}

const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "不能读取该Socket." );
    }

  return *this;
}

void ServerSocket::receive ( std::string& s )
{
  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "不能读取该Socket." );
    }
}

void ServerSocket::receiveWithFile ( )
{
  if ( ! Socket::recvWithFile() )
    {
      throw SocketException ( "不能读取该Socket." );
    }
}

void ServerSocket::accept ( ServerSocket& sock )
{
  if ( ! Socket::accept ( sock ) )
    {
      throw SocketException ( "不能建立该Socket." );
    }
}

void* ServerSocket::serverReceive(void* arg){
   try
    {
      Parameter *supParam = (Parameter *)arg;
      int portnumber; //端口号
      
      //1.检验端口是否正确 
      if((portnumber=atoi("5555"))<0)
      {
        cout<<"端口号出错\n";
        exit(1);
      }
      cout<<"\n\t....等待连接....\n";
      //2.创建 socket连接
      ServerSocket server (portnumber);
      ServerSocket new_sock;
      server.accept ( new_sock );

      //3.
      string str;
      new_sock.recv(str);
      supParam->testCaseMap.insert(pair<string,string>("yaw_pwm",str));
      
      //new_sock.receiveWithFile();  
    }
  catch ( SocketException& e )
    {
      cout << "Exception was serversocket caught:" << e.description() << "\nExiting.\n";
    }
}