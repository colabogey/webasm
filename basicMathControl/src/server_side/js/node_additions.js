/*

Add at the end of basicMathControl.js
Call your functions from node.
First attempt.
No clue is this is the way its supposed to be done.

*/

var factory = require('./basicMathControl.js');

factory().then((instance) => {
  var arguments_ = [];
  var method = "";
  var arg1 = "0";
  var arg2 = "0";
  arguments_ = process['argv'].slice(2);
  method = arguments_[0];
  arg1 = arguments_[1];
  arg2 = arguments_[2];
  //instance._basicMathAdd(5, 6); // direct calling works
  //var x = instance.ccall("basicMathAdd", "number", ["number", "number"], [4, 2]); // using ccall etc. also work
  var y = instance.ccall(method, "number", ["number", "number"], 
                          [arg1, arg2]); // using ccall etc. also work
  console.log(`${method} ${arg1} ${arg2}: ${y}`);
  //console.log(instance._basicMathAdd(7, 8)); // values can be returned, etc.
});