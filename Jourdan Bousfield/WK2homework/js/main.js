//taskArray
var taskArray = [];


//deletetask
var deleteTask = function(e){

	//console.log('You want to delete me?');	
	
	var taskNumber = e.target.parentElement.id;
	taskArray.splice(taskNumber, 1);
	updateTasks();
	
};

//saveTask
var saveTask = function(){
	//define the task input form and value
	var newTask = $('#newTask').val();	
	
	//add the value to the task array
	taskArray.push(newTask);
	
	//clear the input
	$('#newTask').val('');
	
	//fire the updateTask
	updateTasks();
	
	//log the task array
	console.log(taskArray);
};


//updateTasks
var updateTasks = function(){

	$('#taskList').empty();
			
	$(taskArray).each(function(i){
		
		//console.log('task ' + i + ': ' + this);

		var deleteButton = $('<button/>');
		deleteButton.attr('id', 'deleteButton').text('X').click(function(e){
			deleteTask(e);
		});
		
		var newTask = $('<div/>');
		newTask.attr('id', i).addClass("task").html('<p>' + this + '</p>');
		
		newTask.append(deleteButton);
		
		$('#taskList').append(newTask);
	
	});	
	
	
};






//init
var init = function(){
	console.log('Heck yeah libraries!');
	
	$('#addButton').click(function(e){
		e.preventDefault();
		saveTask();
	});
	
};

//load listener
$(document).ready(init);