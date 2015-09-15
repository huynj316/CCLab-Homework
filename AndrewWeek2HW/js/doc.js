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

// create a Matter.js engine
var engine = Engine.create(document.body);

// create two boxes and a ground
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



// add all of the bodies to the world
World.add(engine.world, [boxA, ball, elastic]);

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



var renderOptions = engine.render.options;
	renderOptions.wireframes = false;
	renderOptions.background = './js/matter/BG.png'

// run the engine
Engine.run(engine);