$(function(){

var _playList;
function init(){
  _playList = [{name:'haha', url:'res/trip.mp4'}, {name:'haha', url:'res/9-11.mp4'}];
  
  $('body').click(onBodyClick);
  $(window).resize(onResize);
  onResize();
  //
  loadVideo(_playList[0].url);
}

function onResize(){
  var w = $(window).width();
  var h = $(window).height();
  $('#cao-video').prop('width', w);
  $('#cao-video').prop('height', h);
}

function onBodyClick(){
  playVideo();
}

function loadVideo(url){
  var video = $('#cao-video').get(0);
  video.src = url;
  video.load();
}

function playVideo(){
  var video = $('#cao-video').get(0);
  if(video.paused){
    video.play();
  }
}

function pauseVideo(){
  var video = $('#cao-video').get(0);
  if(!video.paused){
    video.pause();
  }
}


init();

});