/*
 * Programmer: Matas Noreika
 * Purpose:
 * Nodejs web app that use expressJs as a backend framework.
 * This web server will accept POST and GET requests at the /echo 
 * endpoint.
*/
import express from 'express';
const app = express(); // create app handle for our server
const port = 3001; // port to listen on
let lastMsg = "hello"; // variable that hold the last post response or hello

// GET handler on /echo endpoint
app.get('/echo', (req, res) => {
  res.send(lastMsg);
});


// POST handler on /echo endpoint
app.post('/echo', (req, res) => {
  //TODO: implement
});

//start listening for clients
app.listen(port, () => {
  console.log(`listening on localhost:${port}`);
});
