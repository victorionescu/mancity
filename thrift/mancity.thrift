namespace cpp mancity  // C++ namespace
namespace php mancity  // PHP namespace

struct Team {
  1: required string teamName;
}

typedef list<Team> TeamList

service DBWorker {
  
  void ping(),

  TeamList allTeams()

}