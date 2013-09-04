namespace cpp mancity  // C++ namespace
namespace php mancity  // PHP namespace

struct Team {
  1: required i32 id,
  2: required string name
}

struct Player {
  1: required i32 id,
  2: required string firstName,
  3: required string lastName,
  4: required i32 shirtNumber
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
  3: required i32 teamId,
  4: required i32 playerId,
  5: required i32 outcome,
  6: required double startX,
  7: required double startY,
  8: optional double endX,
  9: optional double endY,
  10: optional double goalY,
  11: optional double goalZ,
  12: optional i32 cross
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

  Player getPlayer(1: i32 teamId, 2: i32 playerId),

  EventList getMatchEvents(1: i32 matchId, 2: PlayerIdList playerIdList, 3: EventTypeList eventTypeList),

  Event getEvent(1: i32 matchId, 2: i32 eventId),

  EventList getGoalEvents(1: i32 matchId, 2: i32 eventId) 
}

service DBMaster {
  void ping(),

  MatchList getAllMatches(),

  PlayerList teamPlayers(1: i32 teamId),
}