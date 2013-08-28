namespace cpp mancity  // C++ namespace
namespace php mancity  // PHP namespace

struct Team {
  1: required i32 id,
  2: required string name
}

struct Player {
  1: required i32 id,
  2: required string firstName,
  3: required string lastName
}

typedef list<Team> TeamList

typedef list<Player> PlayerList

struct Match {
  1: required i32 id,
  2: required i32 homeId,
  3: required i32 awayId
}

typedef list<Match> MatchList

struct Event {
  1: required i32 id,
  2: required i32 eventType,
  3: required i32 playerId,
  4: required double startX,
  5: required double startY,
  6: optional double endX,
  7: optional double endY,
  8: optional double goalY,
  9: optional double goalZ
}

typedef list<Event> EventList

typedef list<i32> PlayerIdList
typedef list<i32> EventTypeList

service DBWorker {
  void ping(),

  MatchList getAllMatches(),

  Match getMatch(1: i32 matchId),

  string getTeamName(1: i32 teamId),

  PlayerList getTeamPlayers(1: i32 teamId),

  EventList getMatchEvents(1: i32 matchId, 2: PlayerIdList playerIdList, 3: EventTypeList eventTypeList)
}

service DBMaster {
  void ping(),

  MatchList getAllMatches(),

  PlayerList teamPlayers(1: i32 teamId),
}