namespace cpp mancity  // C++ namespace
namespace php mancity  // PHP namespace

struct Team {
  1: required i32 teamId,
  2: required string teamName
}

struct Player {
  1: required string playerFirstName,
  2: required string playerLastName
}

struct PlayerAttributes {
  1: required i32 passesSuccess,
  2: required i32 passesFail,
  3: required i32 shotsOnTarget,
  4: required i32 shotsOffTarget,
}

typedef list<Team> TeamList

typedef list<Player> PlayerList

service DBWorker {
  
  void ping(),

  TeamList allTeams(),

  PlayerList teamPlayers(1: i32 team_id),

  PlayerAttributes playerAttributes(1: i32 team_id, 2: i32 player_id)
}

service DBMaster {
  void ping(),

  TeamList allTeams(),

  PlayerList teamPlayers(1: i32 team_id),

  PlayerAttributes playerAttributes(1: i32 team_id, 2: i32 player_id)
}