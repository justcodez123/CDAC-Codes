const http = require('http');
const { URL } = require('url');

let todos = [
    { id: 1, task: 'Read Carefully' },
    { id: 2, task: 'Implement' }
];

let port = 8080;
const server = http.createServer(function (request, res) {
    const { method, url } = request;

    const parsedUrl =
        new URL(url, `http://${request.headers.host}`);
    const pathname = parsedUrl.pathname;
    console.log(parsedUrl.href, pathname);


    // /todos
    if (method === 'GET' && pathname === '/todos') {
        res.writeHead(200, { 'Content-Type': 'application/json' });
        res.end(JSON.stringify(todos));
        console.log(todos);
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('Not Found');
    }

})
server.listen(port)