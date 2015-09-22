//var APIKey = 'cwoo09cvyzkujjxc';
//var user = 'auaudrey';
//var pass = 'apiSpider15';
var _img = document.getElementById('.imgbox');
var newImg = new Image;
newImg.onload = function() {
    _img.src = this.src;
}
newImg.src = 'http://digitalcollections.nypl.org/items/6a850105-e062-9088-e040-e00a18064ec8';


//
//var loadCat = function(response){
	//this is where I would load a random image from the results into the img box

	//var cat = 'http://digitalcollections.nypl.org/items/6a850105-e062-9088-e040-e00a18064ec8';//this is there the chosen img link will go
	//$('.imgbox').html('<img src="' + cat + '">');

//}

//var randomPussy = function(){
	//this is where the images are put into an array and one os chosen for the img box
//});

//getCats
//var getCat = function(){
	
	//var thisURL = 'http://api.repo.nypl.org/api/v1/items/search.xml?q=cat';
	
	//$.ajax({
		//url : thisURL,
		//dataType : "jsonp",
		//success : function(response){
			//loadCat(response);	
		//}
	//});

	//$( document ).ready(function(){
	
	//var init= function(){
		//console.log('Find Marissa an archived cat');
		//loadCat();


	//};

	//init();

