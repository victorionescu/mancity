<?php
  require "../thrift/LibraryLoad.php";

  use Thrift\Transport\TSocket;
  use Thrift\Protocol\TBinaryProtocol;
  use mancity\DBWorkerClient;

  $transport = new TSocket("localhost", 9090);
  $transport -> open();

  $protocol = new TBinaryProtocol($transport);

  $client = new DBWorkerClient($protocol);

  $events = $client->getMatchEvents($_GET["matchId"], $_GET["playerIdList"], $_GET["eventTypeList"]);

  for ($i = 0; $i < count($events); $i++) {
    $player = $client->getPlayer($events[$i]->teamId, $events[$i]->playerId);
    $events[$i]->shirtNumber = $player->shirtNumber;
  }

  echo json_encode($events);

  $transport->close();
?>