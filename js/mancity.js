function setMatchesTableClickEvents() {
  $("#matches-table tbody tr").click(function() {
    var matchId = parseInt($(this).attr("rel"));
    getDashboard(matchId);
  })
}

function setDashboardClickEvents() {
  $("#home-players-table tbody tr").click(function() {
    if ($(this).hasClass("selected")) {
      $(this).removeClass("info");
      $(this).removeClass("selected");
    } else {
      $(this).addClass("info");
      $(this).addClass("selected");
    }

    refreshSVG();
  })

  $("#away-players-table tbody tr").click(function() {
    if ($(this).hasClass("selected")) {
      $(this).removeClass("info");
      $(this).removeClass("selected");
    } else {
      $(this).addClass("info");
      $(this).addClass("selected");
    }

    refreshSVG();
  })
}

function setEventsTableClickEvents() {
  $("#events-table tbody tr").click(function() {
    if ($(this).hasClass("selected")) {
      $(this).removeClass("info");
      $(this).removeClass("selected");
    } else {
      $(this).addClass("info");
      $(this).addClass("selected");
    }

    refreshSVG();
  })
}

function refreshSVG() {
  var eventTypeList = new Array();
  var playerIdList = new Array();

  $("#events-table tbody tr.selected").each(function() {
    eventTypeList.push(parseInt($(this).attr("rel")));
  })

  $("#home-players-table tbody tr.selected").each(function() {
    playerIdList.push(parseInt($(this).attr("rel")));
  })

  $("#away-players-table tr.selected").each(function() {
    playerIdList.push(parseInt($(this).attr("rel")));
  })

  $.ajax({
    url: "interface/getMatchEvents.php",
    type: "GET",
    cache: false,
    data: {
      matchId: parseInt($("#dashboard").attr("rel")), 
      eventTypeList: eventTypeList,
      playerIdList: playerIdList
    }, success: function(response) {
      var events = $.parseJSON(response);

      var svg_content = "<svg xmlns='http://www.w3.org/2000/svg' version='1.1' width='100%' viewBox='0 0 400 200'>" +
                        "<rect width='400' height='200' style='fill:#27AE60;'\/>";

      for (var i = 0; i < events.length; i += 1) {
        var realStartX = parseInt(4 * events[i].startX);
        var realStartY = 200 - parseInt(2 * events[i].startY);
        svg_content = svg_content + "<circle cx='" + realStartX + "' cy='" + realStartY +
                      "' r='2' fill='red'\/>";
      }

      svg_content = svg_content + "<\/svg>";

      //alert(svg_content);

      $("#football-field").html(svg_content);
    }
  })
}

function getAllMatches() {
  $.ajax({
    url: "interface/getAllMatches.php",
    type: "GET",
    cache: false,
    success: function(response) {
      var matches = $.parseJSON(response);

      var html_content = "";

      for (var i = 0; i < matches.length; i += 1) {
        html_content += "<tr rel='" + matches[i].id + "'><td>" + matches[i].homeName +
                        "<\/td><td>" + matches[i].awayName + "<\/td><\/tr>";
      }

      $("#matches-table tbody").html(html_content);

      setMatchesTableClickEvents();
    }
  })
}

function getDashboard(matchId) {
  $.ajax({
    url: "interface/getMatch.php",
    type: "GET",
    cache: false,
    data: {
      matchId: matchId
    }, success: function(response) {
      var match = $.parseJSON(response);

      var homePlayers = match.homePlayers;
      var awayPlayers = match.awayPlayers;

      var homePlayers_html = "";

      for (var i = 0; i < homePlayers.length; i += 1) {
        homePlayers_html += "<tr rel='" + homePlayers[i].id + "'><td>" + homePlayers[i].firstName +
                            "<\/td><td>" + homePlayers[i].lastName + "<\/td><\/tr>";
      }

      $("#home-players-table tbody").html(homePlayers_html);

      var awayPlayers_html = "";

      for (var i = 0; i < awayPlayers.length; i += 1) {
        awayPlayers_html += "<tr rel='" + awayPlayers[i].id + "'><td>" + awayPlayers[i].firstName +
                            "<\/td><td>" + awayPlayers[i].lastName + "<\/td><\/tr>";
      }

      $("#away-players-table tbody").html(awayPlayers_html);

      $("#dashboard").attr("rel", matchId);

      setDashboardClickEvents();
    }
  })
}

$(document).ready(function() {
  getAllMatches();
  setEventsTableClickEvents();
})