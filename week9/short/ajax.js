function cs50Info(name)
{
    // no name selected
    if(name == "")
        return;

    // create new AJAX object
    var ajax = new XMLHttpRequest();

    // when page is loaded, have callback fxn pre-fill div
    ajax.onreadystatechange = function() {
        if (ajax.readyState == 4 && ajax.status == 200) {
            $('#infodiv').html(ajax.responseText);
        }
    };

    // open requested file and transmit data
    ajax.open('GET', name + '.html', true);
    ajax.send();
}

