/*

Add at the end of basicMathControl.js
Call your functions from node.
First attempt.
No clue is this is the way its supposed to be done.

*/

let factory = require('./basicMathControl.js');

factory().then((instance) => {
  let arguments_ = [];
  let method = "";
  let arg1 = "0";
  let arg2 = "0";
  arguments_ = process['argv'].slice(2);
  method = arguments_[0];
  arg1 = arguments_[1];
  arg2 = arguments_[2];
  let y = instance.ccall(method, "number", ["number", "number"], 
                          [arg1, arg2]); // using ccall etc. also work
  console.log(`${method} ${arg1} ${arg2}: ${y}`);
});
