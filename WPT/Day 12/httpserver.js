// 1) in http server pass data as query parameter 
//   and use that data to display on HTML Page 
//   fName=ABC&lName=XYZ

// 	o/p Hello <fName>

const h = require('http');
var url = require('url');

let port = 3000;
const server = h.createServer(
  function (request, response) {

    let d = request.url;// whole  url b.html?fName=abc 
    let d1 = url.parse(d, true).query;//object 

    response.writeHead(200, { 'content-type': 'text/html' });  // header 
    console.log(request.headers);
    if (d1.name == 'AA') {
      response.write("<h1>" + d1.name + "</h1>");
    } else
     // response.write(JSON.stringify({ message: "Hello \n" }));
    response.write("Hello World ");
    response.end();
  });

server.listen(port, () => 
    {console.log(`Server started at: http://localhost:${port}/`)
});