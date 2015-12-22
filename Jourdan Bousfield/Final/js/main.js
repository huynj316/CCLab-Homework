$('#add-name').click(function() {
            var listvalue = $('#first-name').val();
                    $("#first-name").val("");
            var listvalue = $('#last-name').val();
                    $("#last-name").val("");
                $('ol').append('<li>' + listvalue + '</li>');
        });

        $('#first-name').keypress(function(event) {
            if(event.which === 13) {
                var listvalue = $('#first-name').val();
                    $('#first-name').val("");
                    $('ol').append('<li>' + listvalue + '</li>');
        $('#last-name').keypress(function(event) {
            if(event.which === 13) {
                var listvalue = $('#last-name').val();
                    $('#last-name').val("");
                    $('ol').append('<li>' + listvalue + '</li>');
            }
        });

        $('li').click(function(e) {
            $(e.target).remove();
        });