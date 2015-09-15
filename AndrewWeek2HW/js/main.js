//score board and timing code courtesy of: https://github.com/msmykowski/basketball-game-matter.js/blob/gh-pages/index.js

//basic layout provided by Matter.js documentation/elastic functions

//font: https://www.google.com/fonts#QuickUsePlace:quickUse/Family:VT323

//Background image and ball image from Google Images


// Matter.js module aliases
var Engine = Matter.Engine,
    World = Matter.World,
    Bodies = Matter.Bodies,    
    MouseConstraint = Matter.MouseConstraint,
    Composites = Matter.Composites,
    Common = Matter.Common,
    Constraint = Matter.Constraint,
    Events = Matter.Events,
    Body = Matter.Body;

var score = document.getElementsByClassName("score");

score[0].innerText = 0;

var timer = document.getElementsByClassName("timer")

// create a Matter.js engine
var engine = Engine.create(document.body, {
	render: {
		options: {
		
		wireframes:false}
	
	}});

var boxA = Bodies.rectangle(774, 195, 10, 80, {isStatic: true, render: { fillStyle: '#AAF4F7'}});


var ballOptions = 
			{density: 0.6, restitution: 0.8,  
					render: 
						{ sprite: 
							{ texture: './js/matter/ball.png' 

						}
					} 
				};


var	ball = Bodies.circle(190, 350, 16, ballOptions),
    anchor = { x: 190, y: 350 },
    elastic = Constraint.create({ 
        pointA: anchor, 
        bodyB: ball, 
        stiffness: 0.1,           
    });

 var ballPos = []


 var group =
 			particleOptions = { friction: 0.00001, render: { visible: false}},
            net = Composites.softBody(684, 220, 5, 5, 3, 8, false, 8, particleOptions);

        for (var i = 0; i < 1; i++) {
            net.bodies[i].isStatic = true;
        }

        for (var i = 4; i < 5; i++) {
            net.bodies[i].isStatic = true;
        }


//add mouse constraint
var mouseConstraint = MouseConstraint.create(engine);

// add all of the bodies to the world
World.add(engine.world, mouseConstraint);

World.add(engine.world,[boxA, ball, elastic, net]);


var offset = 5;
World.add(engine.world,[

	// top

	// Bodies.rectangle(400, -offset, 800 + 2 * offset, 50, { isStatic: true }),

	//bottom

	Bodies.rectangle(400, 600 + offset, 800 + 2 * offset, 50, { isStatic: true }),

	//right

	Bodies.rectangle(800 + offset, 300, 50, 600 + 2 * offset, { isStatic: true }),

	//left

	Bodies.rectangle(-offset, 300, 50, 600 + 2 * offset, { isStatic: true })
]);



Events.on(engine, 'tick', function(event) {
    if (engine.input.mouse.button === -1 && (ball.position.x > (ball.position.x + 20) || ball.position.y < 330)) {
        ball = Bodies.circle(190, 350,16, ballOptions);
        ballPos.push(elastic.bodyB)
        World.add(engine.world, ball);
        elastic.bodyB = ball;
    }
});




Events.on(engine, 'tick', function(event) {
	

  for (var i = 0; i < ballPos.length; i++) {
    if (ballPos[i].position.x > 684 && ballPos[i].position.x < 770 && ballPos[i].position.y > 200 && ballPos[i].position.y < 220) {
      score[0].innerText = parseInt(score[0].innerText) + 1
      
      
    }
  }
  });

function start(time) {
  if (time <= 0) {
    clearTimeout(timeKeep);
    World.clear(engine.world, {keepStatic: true});
    timer[0].innerText = "Your score: " + score[0].innerText;
  }
  else {
    timeKeep = setTimeout(function() {
      time = time - .015;
      timer[0].innerText = time.toFixed(2);
      start(time);
    }, 10);
  }

}

start(24)


var renderOptions = engine.render.options;
	renderOptions.wireframes = false;
	renderOptions.background = './js/matter/BG.png'

// run the engine
Engine.run(engine);