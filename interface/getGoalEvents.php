<?php
  require "../thrift/LibraryLoad.php";

  use Thrift\Transport\TSocket;
  use Thrift\Protocol\TBinaryProtocol;
  use mancity\DBWorkerClient;

  $transport = new TSocket("localhost", 9090);
  $transport -> open();

  $protocol = new TBinaryProtocol($transport);

  $client = new DBWorkerClient($protocol);

  $events = $client->getGoalEvents($_GET["matchId"], $_GET["eventId"]);

  for ($i = 0; $i < count($events); $i++) {
    $player = $client->getPlayer($events[$i]->teamId, $events[$i]->playerId);
    $events[$i]->shirtNumber = $player->shirtNumber;
  }

  echo json_encode($events);

  $transport->close();
?>