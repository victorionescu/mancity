// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "DBMaster.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::mancity;

class DBMasterHandler : virtual public DBMasterIf {
 public:
  DBMasterHandler() {
    // Your initialization goes here
  }

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

  void allTeams(TeamList& _return) {
    // Your implementation goes here
    printf("allTeams\n");
  }

  void teamPlayers(PlayerList& _return, const int32_t team_id) {
    // Your implementation goes here
    printf("teamPlayers\n");
  }

  void playerAttributes(PlayerAttributes& _return, const int32_t team_id, const int32_t player_id) {
    // Your implementation goes here
    printf("playerAttributes\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<DBMasterHandler> handler(new DBMasterHandler());
  shared_ptr<TProcessor> processor(new DBMasterProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

