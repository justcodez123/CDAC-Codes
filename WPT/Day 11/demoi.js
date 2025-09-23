// use http package and create server in node js

const http = require('http');
const server = http.createServer((req,res)=>{
    res.writeHead
    (200,{'content-Type':'text/html'});
    res.end('Hello, AASHISH KAALEY from Node Js Server!\n');
});
server.listen(8000);
console.log("Server Started");