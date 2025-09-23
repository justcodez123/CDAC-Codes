// use http package and create server in node js

const http = require('http');
let port = 8080;
const server = http.createServer((req,res)=>{
    res.writeHead
    (200,{'content-Type':'text/html'});
    res.end('Hello, from Node Js Server!\n');
});
/* The if(server) block is redundant. The http.createServer() method returns a 
    serverobject, so server will always be a truthy value. */
server.listen(port, () => {console.log("Server Started : " + 
    `http://localhost:${port}/`);
});