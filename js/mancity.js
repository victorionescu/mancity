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

function setEventsListClickEvents() {
  $("#events-list a").click(function() {
    var li_parent = $(this).parent();
    if (li_parent.hasClass("active")) {
      li_parent.removeClass("active");
    } else {
      li_parent.addClass("active");
    }

    refreshSVG();
  })
}

function retrieveHeatmap(playerId) {
  $.ajax({
    url: "interface/getMatchEvents.php",
    type: "GET",
    cache: false,
    data: {
      matchId: parseInt($("#dashboard-overlay").attr("rel")), 
      playerIdList: [playerId]
    }, success: function(response) { 
      var config = {
        element: document.getElementById("heatmap-wrapper"),
        radius: 20,
        opacity: 100
      }

      var heatmap = h337.create(config);

      var dataSet = new Array();

      var events = $.parseJSON(response);

      for (var i = 0; i < events.length; i += 1) {
        var evtX = 8 + parseInt(events[i].startX * 331 / 100);
        var evtY = 8 + parseInt((100 - events[i].startY) * 182 / 100);
        dataSet.push({
          x: evtX,
          y: evtY,
          count: 10
        })
      }

      heatmap.store.setDataSet({
        max: 20,
        data: dataSet
      });
    }
  });
}

function removeHeatmap() {
  $("#heatmap-wrapper canvas").remove();
}

function setDashboardHoverEvents() {
  $("#home-players-table tbody tr").hover(function() {
    removeHeatmap();
    resetTracker();
    retrieveHeatmap(parseInt($(this).attr("rel")));
  }, function() {
    removeHeatmap();
  })

  $("#away-players-table tbody tr").hover(function() {
    removeHeatmap();
    resetTracker();
    retrieveHeatmap(parseInt($(this).attr("rel")));
  }, function() {
    removeHeatmap();
  })
}

function setSVGHoverEvents() {
  $("#fieldmap area").hover(function() {
    var eventId = parseInt($(this).attr("id").split("-")[1]);
    removeHeatmap();
    resetTracker();
    if ($(this).attr("rel") == "goal") {
      $.ajax({
        url: "interface/getGoalEvents.php",
        type: "GET",
        cache: false,
        data: {
          matchId: parseInt($("#dashboard-overlay").attr("rel")),
          eventId: eventId
        }, success: function(response) {
          //alert(response);
          refreshTrackerByEvents($.parseJSON(response));
        }
      })
    } else {
      refreshTrackerByEvent(eventId);
    }
  }, function() {
    resetTracker();
  })
}

function SVGArrow(startX, startY, endX, endY) {
  if (startX == endX) {
    startX -= 2;
    endX += 2;
  }
    
  var m = (endY - startY) / (endX - startX);

  var deltaX = Math.sqrt(16 / (1 + m * m));
  var deltaY = m * deltaX;

  var baseX, baseY;
  if (startX < endX) {
    baseX = endX - deltaX;
    baseY = endY - deltaY;
  } else {
    baseX = endX + deltaX;
    baseY = endY + deltaY;
  }

  var perpm = -1 / m;

  deltaX = Math.sqrt(9 / (1 + perpm * perpm));
  deltaY = perpm * deltaX;

  var x1, x2, x3, y1, y2, y3;

  x1 = baseX - deltaX;
  y1 = baseY - deltaY;

  x2 = endX;
  y2 = endY;

  x3 = baseX + deltaX;
  y3 = baseY + deltaY;

  return "<polygon points='" + x1 + "," + y1 +
         " " + x2 + "," + y2 +
         " " + x3 + "," + y3 + "' " +
         "fill='grey' stroke='grey' stroke-width='1'\/>";
}

function SVGEvent(startX, startY, endX, endY, success, shirtNumber) {
  var svg_content;

  var realStartX = 10 + parseInt(startX * 400 / 100);
  var realStartY = 10 + parseInt((100 - startY) * 220 / 100);

  if (endX >= 0 && endY >= 0) {
    var realEndX = 10 + parseInt(endX * 400 / 100);
    var realEndY = 10 + parseInt((100 - endY) * 220 / 100);

    var svg_line = "<line x1='" + realStartX + "' y1='" + realStartY + "' " +
                   "x2='" + realEndX + "' y2='" + realEndY + "' " +
                   "stroke-width='1' stroke='grey'\/>";
    svg_content += svg_line;
    svg_content += SVGArrow(realStartX, realStartY, realEndX, realEndY);
  }

  var svg_circle = "<circle stroke-width='1' stroke='red' r='5' " + 
                   "cx='" + realStartX + "' cy='" + realStartY + "' ";
  if (!success) {
    svg_circle += "fill='#880000'";
  } else {
    svg_circle += "fill='#1ABC9C'";
  }

  svg_circle += "\/>";

  svg_content += svg_circle;

  var svg_shirt;

  if (shirtNumber > 9) {
    svg_shirt = "<text x='" + (realStartX - 3) + " " + (realStartX) + "' " +
                "y='" + (realStartY + 2) + " " + (realStartY + 2) + "' " +
                "font-size='7' font-family='sans-serif'>" + shirtNumber + "<\/text>";
  } else {
    svg_shirt = "<text x='" + (realStartX - 2) + "' y='" + (realStartY + 2) + "' " +
                "font-size='7' font-family='sans-serif'>" + shirtNumber + "<\/text>";
  }

  svg_content += svg_shirt;

  return svg_content;
}

function SVGContent(events) {
  var svg_content = "<svg xmlns='http://www.w3.org/2000/svg' version='1.1' viewBox='0 0 420 240'>" +
                        "<rect x='0' y='0' width='420' height='240' style='fill:#27AE60;'\/>";

  svg_content += "<rect x='10' y='10' width='80' height='220' style='fill:#2ECC71'\/>";
  svg_content += "<rect x='170' y='10' width='80' height='220' style='fill:#2ECC71'\/>";
  svg_content += "<rect x='330' y='10' width='80' height='220' style='fill:#2ECC71'\/>";
  svg_content += "<line x1='10' y1='10' x2='410' y2='10' stroke='white'\/>";
  svg_content += "<line x1='410' y1='10' x2='410' y2='230' stroke='white'\/>";
  svg_content += "<line x1='410' y1='230' x2='10' y2='230' stroke='white'\/>";
  svg_content += "<line x1='10' y1='230' x2='10' y2='10' stroke='white'\/>";
  svg_content += "<line x1='210' y1='10' x2='210' y2='230' stroke='white'\/>";
  svg_content += "<circle cx='210' cy='120' r='3' fill='white'\/>";
  svg_content += "<circle cx='210' cy='120' r='25' fill='none' stroke-width='1' stroke='white'\/>";

  for (var i = 0; i < events.length; i += 1) {
    svg_content += SVGEvent(events[i].startX, events[i].startY,
                            events[i].endX, events[i].endY,
                            events[i].outcome == 1, events[i].shirtNumber);
  }

  svg_content = svg_content + "<\/svg>"; 

  return svg_content;
}

function refreshSVG() {
  var eventTypeList = new Array();
  var playerIdList = new Array();

  $("#events-list li.active").each(function() {
    eventTypeList.push(parseInt($(this).attr("rel")));
  })

  $("#home-players-table tbody tr.selected").each(function() {
    playerIdList.push(parseInt($(this).attr("rel")));
  })

  $("#away-players-table tr.selected").each(function() {
    playerIdList.push(parseInt($(this).attr("rel")));
  })

  if (playerIdList.length == 0 || eventTypeList.length == 0) {
    $("#svg-field").attr("src", "img/pitchsvg.svg");

    return;
  }

  $.ajax({
    url: "interface/getMatchEvents.php",
    type: "GET",
    cache: false,
    data: {
      matchId: parseInt($("#dashboard-overlay").attr("rel")), 
      eventTypeList: eventTypeList,
      playerIdList: playerIdList
    }, success: function(response) {
      var events = $.parseJSON(response);

      $("#svg-field").attr("src", "data:image/svg+xml;charset=utf-8," + SVGContent(events));

      var map_html = "";

      for (var i = 0; i < events.length; i += 1) {
        var mapX = 17 + parseInt(events[i].startX * 680 / 100);
        var mapY = 17 + parseInt((100 - events[i].startY) * 374 / 100);

        var relVal = "";
        if (events[i].eventType == 16) {
          relVal = "goal";
        }

        map_html += "<area shape='circle' coords='" + mapX + "," + mapY + ",8' " +
                    "href='javascript:void(0)' id='event-" + events[i].id + "' " +
                    "rel ='" + relVal + "'>";
      }

      $("#fieldmap").html(map_html);

      setSVGHoverEvents();
    }
  })
}

function refreshTrackerByEvent(eventId) {
  $.ajax({
    url: "interface/getEvent.php",
    type: "GET",
    cache: false,
    data: {
      matchId: parseInt($("#dashboard-overlay").attr("rel")),
      eventId: eventId
    }, success: function(response) {
      var evt = $.parseJSON(response);
      $("#tracker").attr("src", "data:image/svg+xml;charset=utf-8," + SVGContent([evt]));
      var infoboard_html = "";
      infoboard_html += "<h3>";

      if (evt.eventType == 1) {
        if (evt.outcome == 1) {
          infoboard_html += "Successful";
        } else {
          infoboard_html += "Failed";
        }

        if (evt.cross == 1) {
          infoboard_html += " Cross";
        } else {
          infoboard_html += " Pass";
        }
      } else {

      }

      infoboard_html += "<\/h3>";
      $("#infoboard").html(infoboard_html);
    }
  })
}

function refreshTrackerByEvents(eventList) {
  $("#tracker").attr("src", "data:image/svg+xml;charset=utf-8," + SVGContent(eventList));
  $("#infoboard").html("");
}

function resetTracker() {
  $("#tracker").attr("src", "data:image/svg+xml;charset=utf-8," + SVGContent([]));
  $("#infoboard").html("");
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

      $("#dashboard-overlay").attr("rel", matchId);

      setDashboardClickEvents();
      setDashboardHoverEvents();

      refreshSVG();

      overlayOn();
    }
  })
}

function overlayOff() {
  $("#dashboard-overlay").animate({
    right: "-5000px"
  }, 600)
}

function overlayOn() {
  $("#dashboard-overlay").css("right", "2000px")

  $("#dashboard-overlay").animate({
    right: "10px"
  }, 600)

}

$(document).ready(function() {
  $("#close-overlay").click(function() {
    overlayOff();
  })
  
  setEventsListClickEvents();

  getAllMatches();
})