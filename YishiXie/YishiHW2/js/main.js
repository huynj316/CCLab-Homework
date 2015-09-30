//edit from source code: http://threejs.org/docs/#Manual/Introduction/Creating_a_scene

var scene = new THREE.Scene();
		var camera = new THREE.PerspectiveCamera( 30, window.innerWidth/window.innerHeight, 0.1, 1000 );

		var renderer = new THREE.WebGLRenderer();
		renderer.setSize( window.innerWidth, window.innerHeight );
		document.body.appendChild( renderer.domElement );

		var geometry = new THREE.BoxGeometry( 1, 1, 1 );
		var material = new THREE.MeshBasicMaterial( { color: 0x8b8682 } );
		var cube = new THREE.Mesh( geometry, material );
		scene.add( cube );

		camera.position.z = 5;

		var render = function () {
			requestAnimationFrame( render );

			cube.rotation.x += 0.01;
			cube.rotation.y += 0.01;

			renderer.render(scene, camera);
		};

		render();