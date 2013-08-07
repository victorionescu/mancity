function setTeamClickEvents() {
  $('#teams-table tbody tr').click(function() {
    $('#teams-table tbody tr').removeClass('info');
    $(this).addClass('info');
    $.ajax({
      url: "players_client.php",
      data: {
        team_id: parseInt($(this).attr('rel'))
      },
      type: "GET",
      cache: false,
      success: function(response) {
        var players = $.parseJSON(response);

        var html_content = "";

        for (var i = 0; i < players.length; i = i + 1) {
          html_content += "<tr><td>" + players[i].playerFirstName + "<\/td><td>" +
              players[i].playerLastName + "<\/td><\/tr>";
        }

        $('#players-table tbody').html(html_content);
      }
    })
  })
}



$(document).ready(function() {
  $.ajax({
    url: "client.php",
    type: "GET",
    cache: false,
    success: function(response) {
      var teams = $.parseJSON(response);

      var html_content = "";

      for (var i = 0; i < teams.length; i = i + 1) {
        html_content += "<tr rel='" + teams[i].teamId + "'><td>" + teams[i].teamName + "<\/td><\/tr>";
      }

      $('#teams-table tbody').html(html_content);

      setTeamClickEvents();
    }
  })


})