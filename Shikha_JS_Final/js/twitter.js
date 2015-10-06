$(document).ready(function () {
     
    createButton();
   document.getElementById('dbutton').addEventListener("click",    createButton);

    function createButton() {

        // Remove Whatever is in the tweeetbox div if theres somethign 
        //there to avoid adding multiple tweetbuttons

        
        var elem = document.getElementById('twitterbutton');
        if (elem != null) {
            elem.parentNode.removeChild(elem);
        }

        // Create a New Tweet Element
        msg  =  document.getElementById('msg').value;
        var link = document.createElement('a');
        link.setAttribute('href', 'https://twitter.com/share');
        link.setAttribute('class', 'twitter-share-button');
        link.setAttribute('style', 'margin-top:5px;');
        link.setAttribute('id', 'twitterbutton');
        link.setAttribute("data-text", "" + msg + "");
        link.setAttribute("data-via", "denvycom");
        link.setAttribute("data-size", "large");

       // Put it inside the twtbox div
        tweetdiv  =  document.getElementById('twtbox');
        tweetdiv.appendChild(link);

        twttr.widgets.load(); //very important
    }
});