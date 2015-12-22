var systems;
var radius;
var radius2;
var canvas;
var socket;

function setup() {
  
  canvas = createCanvas(1600, 400);
  
  canvas.position(0, 200);
  canvas.parent('myContainer');
  systems = new ParticleSystem(createVector([]));
  socket = io.connect('http://192.168.1.100:8000');

  socket.on('dustInfo', function (data) {
          console.log("p5 reading dust");

          if (data.dust > 700){
            systems.init();
            console.log("particles more");

          }else {
            systems.dead();
            console.log("particles none");

          }
      
          
        });
}

function draw() {
 
  background(2,30,45);
  systems.run();
  systems.addParticle();
  
  radius = random(1,10);
   radius2 = random(10,30);
  frameRate(5);
  
}

// function mouse() {
  
//   systems.init();


// }

// function mouseDragged() {
//   // Draw some white circles
//   fill(255);
//   noStroke();
//   ellipse(mouseX,mouseY,80,80);
//   // Send the mouse coordinates
//   sendmouse(mouseX,mouseY);
// }

// function sendmouse(xpos, ypos) {
//   // We are sending!
//   console.log("sendmouse: " + xpos + " " + ypos);
  
//   // Make a little object with  and y
//   var data = {
//     x: xpos,
//     y: ypos
//   };

//   // Send that object to the socket
//   socket.emit('mouse',data);
// }


var Particle = function(position) {

  this.position = position.copy();
  this.lifespan = 255.0;
};

Particle.prototype.run = function() {
  this.update();
  this.display();
};

Particle.prototype.update = function(){
  
  this.lifespan -= 2;
};


Particle.prototype.display = function () {
  
  noStroke();
  fill(random(0,255), this.lifespan);
  ellipse(random(0, displayWidth), random(0, displayHeight), radius, radius);
};


Particle.prototype.isDead = function () {
  if (this.lifespan < 0) {
    return true;
  } else {
    return false;
  }
};

var ParticleSystem = function (position) {
  this.origin = position.copy();
  this.particles = [];
};

ParticleSystem.prototype.addParticle = function () {
  
  this.particles.push(new Particle(this.origin));

};

ParticleSystem.prototype.init = function () {
  p = new CrazyParticle(this.origin);
  this.particles.push(p);
};


ParticleSystem.prototype.dead = function () {
  p = new CrazyParticle(this.origin);
  this.particles.splice(p);
};

ParticleSystem.prototype.run = function () {
  for (var i = this.particles.length - 1; i >= 0; i--) {
    var p = this.particles[i];
    p.run();
  }
};



function CrazyParticle(origin) {

  Particle.call(this, origin);

}


CrazyParticle.prototype = Object.create(Particle.prototype); 


CrazyParticle.prototype.constructor = CrazyParticle;

CrazyParticle.prototype.update=function() {
  Particle.prototype.update.call(this);

}


CrazyParticle.prototype.display=function() {

  Particle.prototype.display.call(this);

  push();
  translate(this.position.x, this.position.y);
  noStroke();
  fill(255,64,64);
 
  ellipse(random(0, displayWidth), random(0, displayHeight), radius2, radius2);
  pop();
}
