// Teacher Homepage

$(document).ready(function(){
      var i=1;
     $("#add_row").click(function(){
      $('#addr'+i).html("<td>"+ (i+1) +"</td><td><input name='name"+i+"' type='text' placeholder='Name' class='form-control input-md'  /> </td><td><input  name='mail"+i+"' type='text' placeholder='Last Name'  class='form-control input-md'></td>");

      $('#tab_logic').append('<tr id="addr'+(i+1)+'"></tr>');
      i++; 
  });
     $("#delete_row").click(function(){
    	 if(i>1){
		 $("#addr"+(i-1)).html('');
		 i--;
		 }
	 });

});

// Student Structure
  $(document).ready(function(){
      var i=1;
     $("#student-add_row").click(function(){
      $('#student-addr'+i).html("<td>"+ (i+1) +"</td><td><input name='name"+i+"' type='text' placeholder='Category' class='form-control input-md'  /> </td>");

      $('#student-tab_logic').append('<tr id="student-addr'+(i+1)+'"></tr>');
      i++; 
  });
     $("#student-delete_row").click(function(){
       if(i>1){
     $("#student-addr"+(i-1)).html('');
     i--;
     }
   });

});



// teacher create group
$(document).ready(function(){
      var i=1;
     $("#add_row").click(function(){
      $('#addr'+i).html("<td>"+ (i+1) +"</td><td><input name='name"+i+"' type='text' placeholder='Name' class='form-control input-md'  /> </td>");
      $('#tab_logic').append('<tr id="addr'+(i+1)+'"></tr>');
      i++; 
  });
     $("#delete_row").click(function(){
       if(i>1){
     $("#addr"+(i-1)).html('');
     i--;
     }
   });

});

// MAP

// MIND MAP
  // culture

$(document).ready(function(){
  $("#student-add_row1").click(function(){
    $("#hidecolumn2").slideToggle();
  });
});

$(document).ready(function(){
  $("#student-delete_row1").click(function(){
    $("#hidecolumn2").slideToggle();
  });
});
  // values

$(document).ready(function(){
  $("#student-add_row21").click(function(){
    $("#hidecolumn31").slideToggle();
  });
});
$(document).ready(function(){
  $("#student-delete_row21").click(function(){
    $("#hidecolumn32").slideToggle();
  });
});

// Beliefs

$(document).ready(function(){
  $("#student-add_row22").click(function(){
    $("#hidecolumn33").slideToggle();
  });
});
$(document).ready(function(){
  $("#student-delete_row22").click(function(){
    $("#hidecolumn34").slideToggle();
  });
});


// EXPERIENCES

$(document).ready(function(){
  $("#student-add_row23").click(function(){
    $("#hidecolumn35").slideToggle();
  });
});
$(document).ready(function(){
  $("#student-delete_row23").click(function(){
    $("#hidecolumn36").slideToggle();
  });
});

  //final column 
$(document).ready(function(){
  $("#student-add_row31").click(function(){
    $("#hidecolumn41").slideToggle();
  });
    });
  $(document).ready(function(){
  $("student-delete_row31").click(function(){
    $("#hidecolumn41").slideToggle();
  });
    });
    // split
  $(document).ready(function(){
  $("#student-add_row32").click(function(){
    $("#hidecolumn42").slideToggle();
  });
    });
  $(document).ready(function(){
  $("student-delete_row32").click(function(){
    $("#hidecolumn42").slideToggle();
  });
    });

  $(document).ready(function(){
  $("#student-add_row33").click(function(){
    $("#hidecolumn43").slideToggle();
  });
    });
  $(document).ready(function(){
  $("student-delete_row33").click(function(){
    $("#hidecolumn43").slideToggle();
  });
    });

  $(document).ready(function(){
  $("#student-add_row34").click(function(){
    $("#hidecolumn44").slideToggle();
  });
    });
  $(document).ready(function(){
  $("student-delete_row34").click(function(){
    $("#hidecolumn44").slideToggle();
  });
    });

$(document).ready(function(){
  $("#student-add_row35").click(function(){
    $("#hidecolumn45").slideToggle();
  });
    });
  $(document).ready(function(){
  $("student-delete_row35").click(function(){
    $("#hidecolumn45").slideToggle();
  });
    });

  $(document).ready(function(){
  $("#student-add_row36").click(function(){
    $("#hidecolumn46").slideToggle();
  });
    });
  $(document).ready(function(){
  $("student-delete_row36").click(function(){
    $("#hidecolumn46").slideToggle();
  });
    });

  $(document).ready(function(){
  $("#student-add_row37").click(function(){
    $("#hidecolumn47").slideToggle();
  });
    });
  $(document).ready(function(){
  $("student-delete_row38").click(function(){
    $("#hidecolumn48").slideToggle();
  });
    });
// TEACHER CLASS LIST

$(document).ready(function(){
  $("#classlist-add_row1").click(function(){
    $("#newStu2").slideToggle();
  });
    });
  $(document).ready(function(){
  $("#classlist-delete_row1").click(function(){
    $("#newStu2").slideToggle();
  });
    });

  $(document).ready(function(){
  $("#classlist-add_row2").click(function(){
    $("#newStu3").slideToggle();
  });
    });
  $(document).ready(function(){
  $("#classlist-delete_row2").click(function(){
    $("#newStu3").slideToggle();
  });
    });

  $(document).ready(function(){
  $("#classlist-add_row3").click(function(){
    $("#newStu4").slideToggle();
  });
    });
  $(document).ready(function(){
  $("#classlist-delete_row3").click(function(){
    $("#newStu4").slideToggle();
  });
    });


  // Create Group
  $(document).ready(function(){
  $("#group-add_row1").click(function(){
    $("#stu2").slideToggle();
  });
    });
  $(document).ready(function(){
  $("#group-delete_row1").click(function(){
    $("#stu2").slideToggle();
  });
    });

   $(document).ready(function(){
  $("#group-add_row2").click(function(){
    $("#stu3").slideToggle();
  });
    });
  $(document).ready(function(){
  $("#group-delete_row3").click(function(){
    $("#stu3").slideToggle();
  });
    });


   $(document).ready(function(){
  $("#group-add_row3").click(function(){
    $("#stu4").slideToggle();
  });
    });
  $(document).ready(function(){
  $("#group-delete_row3").click(function(){
    $("#stu4").slideToggle();
  });
    });

  $(document).ready(function(){
  $("#group-add_row4").click(function(){
    $("#stu5").slideToggle();
  });
    });
  $(document).ready(function(){
  $("#group-delete_row4").click(function(){
    $("#stu5").slideToggle();
  });
    });

// Suggestions
$(document).ready(function(){
  $("#suggnButton1").click(function(){
    $("#suggn1").slideToggle();
  });
    });

$(document).ready(function(){
  $("#suggnButton2").click(function(){
    $("#suggn2").slideToggle();
  });
    });

$(document).ready(function(){
  $("#suggnButton3").click(function(){
    $("#suggn3").slideToggle();
  });
    });

// // uploader
// $(document).ready(function(){
//     $('[data-toggle="tooltip"]').tooltip({
//         placement: 'top'
//     });   
// /* end dot nav */
// });
