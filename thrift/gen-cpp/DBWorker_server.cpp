// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include <iostream>
#include "DBWorker.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "mongo/client/dbclient.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::mancity;
using namespace  ::bson;
using namespace  ::mongo;

class DBWorkerHandler : virtual public DBWorkerIf {
 public:
  DBWorkerHandler() {
    // Your initialization goes here
  }

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

  void getAllMatches(MatchList& _return) {
    printf("getAllMatches\n");
    try {
      mongo::DBClientConnection c;
      c.connect("localhost");

      BSONObj constraints = BSON("_id" << 0 << "id" << 1 << "homeId" << 1 << "awayId" << 1);
      auto_ptr<DBClientCursor> cursor = c.query("mancity.matches", BSONObj(), 0, 0, &constraints);

      while (cursor->more()) {
        bo obj = cursor->next();

        Match* match = new Match();

        match->__set_id(obj.getField("id").Int());
        match->__set_homeId(obj.getField("homeId").Int());
        match->__set_awayId(obj.getField("awayId").Int());

        _return.push_back(*match);
      }
    } catch (const mongo::DBException &e) {
      std::cout << "CAUGHT EXCEPTION IN DB INTERACTION\n";
    }

    printf("END getAllMatches\n");
  }

  void getMatch(Match& _return, const int32_t matchId) {
    printf("getMatch\n");
    try {
      mongo::DBClientConnection c;
      c.connect("localhost");

      BSONObj constraints = BSON("_id" << 0 << "id" << 1 << "homeId" << 1 << "awayId" << 1);
      auto_ptr<DBClientCursor> cursor =
          c.query("mancity.matches", QUERY("id" << matchId), 0, 0, &constraints);

      if (cursor->more()) {
        bo match = cursor->next();

        _return.__set_id(match.getField("id").Int());
        _return.__set_homeId(match.getField("homeId").Int());
        _return.__set_awayId(match.getField("awayId").Int());
      }
    } catch (const mongo::DBException &e) {
      std::cout << "CAUGHT EXCEPTION IN DB INTERACTION";
    }
    printf("END getMatch\n");
  }

  void getTeamName(std::string& _return, const int32_t teamId) {
    printf("getTeamName\n");
    try {
      mongo::DBClientConnection c;
      c.connect("localhost");

      BSONObj constraints = BSON("_id" << 0 << "name" << 1);
      auto_ptr<DBClientCursor> cursor =
          c.query("mancity.teams", QUERY("id" << teamId), 0, 0, &constraints);


      if (cursor->more()) {
        bo team = cursor->next();

        _return = team.getField("name").String();
      } else {
        _return = "undefined";
      }
    } catch (const mongo::DBException &e) {
      std::cout << "CAUGHT EXCEPTION IN DB INTERACTION\n";
    }
    printf("END getTeamName\n");
  }

  void getTeamPlayers(PlayerList& _return, const int32_t teamId) {
    printf("getTeamPlayers\n");
    try {
      mongo::DBClientConnection c;
      c.connect("localhost");

      BSONObj constraints = BSON("_id" << 0 << "players" << 1);
      auto_ptr<DBClientCursor> cursor =
          c.query("mancity.teams",
                  QUERY("id" << teamId).sort("lastName"),
                  0,
                  0,
                  &constraints
          );

      while (cursor->more()) {
        bo team = cursor->next();

        if (team.hasElement("players")) {
          std::vector<BSONElement> players = team.getField("players").Array();

          for (unsigned int i = 0; i < players.size(); i++) {
            BSONObj player = players[i].embeddedObject();

            Player* player_to_add = new Player();
            player_to_add->__set_id(player.getField("id").Int());
            player_to_add->__set_firstName(player.getField("firstName").String());
            player_to_add->__set_lastName(player.getField("lastName").String());
            player_to_add->__set_shirtNumber(player.getField("shirtNumber").Int());

            _return.push_back(*player_to_add);
          }
        }
      }
    } catch (const mongo::DBException &e) {
      std::cout << "CAUGHT EXCEPTION IN DB INTERACTION\n";
    }
    printf("END getTeamPlayers\n");
  }

  void getPlayer(Player& _return, const int32_t teamId, const int32_t playerId) {
    printf("getPlayer\n");
    try {
      mongo::DBClientConnection c;
      c.connect("localhost");

      BSONObj constraints = BSON("_id" << 0 << "players" << 1);
      auto_ptr<DBClientCursor> cursor =
          c.query("mancity.teams",
                  QUERY("id" << teamId).sort("lastName"),
                  0,
                  0,
                  &constraints
          );

      if (!cursor->more()) {
        return;
      }

      bo team = cursor->next();

      if (team.hasElement("players")) {
        std::vector<BSONElement> players = team.getField("players").Array();

        for (unsigned int i = 0; i < players.size(); i++) {
          BSONObj player = players[i].embeddedObject();

          int objId = player.getField("id").Int();

          if (objId == playerId) {
            _return.__set_id(player.getField("id").Int());
            _return.__set_firstName(player.getField("firstName").String());
            _return.__set_lastName(player.getField("lastName").String());
            _return.__set_shirtNumber(player.getField("shirtNumber").Int());

            break;
          }   
        }
      }
    } catch (const mongo::DBException &e) {
      std::cout << "CAUGHT EXCEPTION IN DB INTERACTION\n";
    }
    printf("END getPlayer\n");
  }

  void getMatchEvents(EventList& _return, const int32_t matchId, const PlayerIdList& playerIdList, const EventTypeList& eventTypeList) {
    printf("getMatchEvents\n");
    try {
      mongo::DBClientConnection c;
      c.connect("localhost");

      BSONObj constraints = BSON("_id" << 0 << "events" << 1);
      auto_ptr<DBClientCursor> cursor =
          c.query("mancity.matches",
                  QUERY("id" << matchId),
                  0,
                  0,
                  &constraints
          );

      while (cursor->more()) {
        bo match = cursor->next();

        if (match.hasElement("events")) {
          std::vector<BSONElement> events = match.getField("events").Array();

          for (unsigned int i = 0; i < events.size(); i++) {
            BSONObj event = events[i].embeddedObject();

            Event* event_to_add = new Event();
            event_to_add->__set_id((int)event.getField("id").Double());
            event_to_add->__set_eventType((int)event.getField("eventType").Double());
            event_to_add->__set_playerId((int)event.getField("playerId").Double());
            event_to_add->__set_teamId((int)event.getField("teamId").Double());
            event_to_add->__set_outcome((int)event.getField("outcome").Double());
            event_to_add->__set_startX(event.getField("startX").Double());
            event_to_add->__set_startY(event.getField("startY").Double());

            if (event.hasElement("endX")) {
              event_to_add->__set_endX(event.getField("endX").Double());
            } else {
              event_to_add->__set_endX(-1);
            }

            if (event.hasElement("endY")) {
              event_to_add->__set_endY(event.getField("endY").Double());
            } else {
              event_to_add->__set_endY(-1);
            }

            if (event.hasElement("goalY")) {
              event_to_add->__set_goalY(event.getField("goalY").Double());
              event_to_add->__set_endX(100);
              event_to_add->__set_endY(event.getField("goalY").Double());
            }

            if (event.hasElement("goalZ")) {
              event_to_add->__set_goalZ(event.getField("goalZ").Double());
            }

            if (event.hasElement("cross")) {
              event_to_add->__set_cross((int)event.getField("cross").Double());
            }


            if ((eventTypeList.size() == 0 ||
                contains((int)event.getField("eventType").Double(), eventTypeList)) &&
                contains((int)event.getField("playerId").Double(), playerIdList)) {
              _return.push_back(*event_to_add);
            }
          }
        }
      }

    } catch (const mongo::DBException &e) {
      std::cout << "CAUGHT EXCEPTION IN DB INTERACTION\n";
    }
    printf("END getMatchEvents\n");
  }

  void getEvent(Event& _return, const int32_t matchId, const int32_t eventId) {
    try {
      mongo::DBClientConnection c;
      c.connect("localhost");

      BSONObj constraints = BSON("_id" << 0 << "events" << 1);
      auto_ptr<DBClientCursor> cursor =
          c.query("mancity.matches",
                  QUERY("id" << matchId),
                  0,
                  0,
                  &constraints
          );

      while (cursor->more()) {
        bo match = cursor->next();

        if (match.hasElement("events")) {
          std::vector<BSONElement> events = match.getField("events").Array();

          for (unsigned int i = 0; i < events.size(); i++) {
            BSONObj event = events[i].embeddedObject();

            int evtId = (int)event.getField("id").Double();

            if (evtId == eventId) {

              _return.__set_id((int)event.getField("id").Double());
              _return.__set_eventType((int)event.getField("eventType").Double());
              _return.__set_playerId((int)event.getField("playerId").Double());
              _return.__set_teamId((int)event.getField("teamId").Double());
              _return.__set_outcome((int)event.getField("outcome").Double());
              _return.__set_startX(event.getField("startX").Double());
              _return.__set_startY(event.getField("startY").Double());


              if (event.hasElement("endX")) {
                _return.__set_endX(event.getField("endX").Double());
              } else {
                _return.__set_endX(-1);
              }

              if (event.hasElement("endY")) {
                _return.__set_endY(event.getField("endY").Double());
              } else {
                _return.__set_endY(-1);
              }

              if (event.hasElement("goalY")) {
                _return.__set_goalY(event.getField("goalY").Double());
                _return.__set_endX(100);
                _return.__set_endY(event.getField("goalY").Double());
              }

              if (event.hasElement("goalZ")) {
                _return.__set_goalZ(event.getField("goalZ").Double());
              }

              if (event.hasElement("cross")) {
                _return.__set_cross((int)event.getField("cross").Double());
              }

              return;
            }
          }
        }
      }

    } catch (const mongo::DBException &e) {
      std::cout << "CAUGHT EXCEPTION IN DB INTERACTION\n";
    }
  }

  void getGoalEvents(EventList& _return, const int32_t matchId, const int32_t eventId) {
    printf("getGoalEvents\n");
    try {
      mongo::DBClientConnection c;
      c.connect("localhost");

      BSONObj constraints = BSON("_id" << 0 << "events" << 1);
      auto_ptr<DBClientCursor> cursor =
          c.query("mancity.matches",
                  QUERY("id" << matchId),
                  0,
                  0,
                  &constraints
          );

      if (!cursor->more()) {
        return;
      }

      bo match = cursor->next();

      if (match.hasElement("events")) {
        std::vector<BSONElement> events = match.getField("events").Array();

        std::vector<Event> eventsUpToGoal;

        for (unsigned int i = 0; i < events.size(); i++) {
          BSONObj event = events[i].embeddedObject();

          Event* event_to_add = new Event();
          event_to_add->__set_id((int)event.getField("id").Double());
          event_to_add->__set_eventType((int)event.getField("eventType").Double());
          event_to_add->__set_playerId((int)event.getField("playerId").Double());
          event_to_add->__set_teamId((int)event.getField("teamId").Double());
          event_to_add->__set_outcome((int)event.getField("outcome").Double());
          event_to_add->__set_startX(event.getField("startX").Double());
          event_to_add->__set_startY(event.getField("startY").Double());

          if (event.hasElement("endX")) {
            event_to_add->__set_endX(event.getField("endX").Double());
          } else {
            event_to_add->__set_endX(-1);
          }

          if (event.hasElement("endY")) {
            event_to_add->__set_endY(event.getField("endY").Double());
          } else {
            event_to_add->__set_endY(-1);
          }

          if (event.hasElement("goalY")) {
            event_to_add->__set_goalY(event.getField("goalY").Double());
            event_to_add->__set_endX(100);
            event_to_add->__set_endY(event.getField("goalY").Double());
          }

          if (event.hasElement("goalZ")) {
            event_to_add->__set_goalZ(event.getField("goalZ").Double());
          }

          if (event.hasElement("cross")) {
            event_to_add->__set_cross((int)event.getField("cross").Double());
          }

          eventsUpToGoal.push_back(*event_to_add);

          if (event_to_add->id == eventId) {
            break;
          }
        }

        int current_index = eventsUpToGoal.size() - 1;
        int team_id = eventsUpToGoal[current_index].teamId;

        while (current_index >= 0 && eventsUpToGoal[current_index].teamId == team_id) {
          _return.push_back(eventsUpToGoal[current_index]);
          current_index--;
        }
      }

    } catch (const mongo::DBException &e) {
      std::cout << "CAUGHT EXCEPTION IN DB INTERACTION\n";
    }
    printf("END getGoalEvents\n");
  }

  bool contains(int element, const std::vector<int>& list) {
    for (unsigned int i = 0; i < list.size(); i ++) {
      if (list[i] == element) {
        return true;
      }
    }

    return false;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<DBWorkerHandler> handler(new DBWorkerHandler());
  shared_ptr<TProcessor> processor(new DBWorkerProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

