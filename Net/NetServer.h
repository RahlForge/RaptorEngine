/*
 *  NetServer.h
 */

#pragma once
class NetServer;

#include "platforms.h"

#include <list>
#include <queue>
#include <stdexcept>
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_mutex.h>
#include <SDL_net/SDL_net.h>
#include "Packet.h"
#include "ConnectedClient.h"
#include "Mutex.h"


class NetServer
{
public:
	bool Initialized;
	volatile bool Listening;
	SDL_Thread *Thread;
	Mutex Lock;
	TCPsocket Socket;
	std::list<ConnectedClient*> Clients;
	std::list<ConnectedClient*> DisconnectedClients;
	double NetRate;
	bool UseOutThreads;
	int8_t Precision;
	
	
	NetServer( void );
	~NetServer();
	
	int Initialize( int port = 7000 );
	void DisconnectNice( const char *message );
	void Disconnect( void );
	
	void RemoveDisconnectedClients( void );
	void ProcessIn( void );
	void ProcessTop( void );
	
	void SendAll( Packet *packet );
	void SendAllExcept( Packet *packet, ConnectedClient *except );
	void SendAllReconnect( uint8_t seconds_to_wait = 3 );
	void SendUpdates( void );
	
	void SetNetRate( double netrate );
	
	static int NetServerThread( void *server );
};
