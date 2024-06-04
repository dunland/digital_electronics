[Introduction to nodeJS](https://nodejs.org/en/learn/getting-started/introduction-to-nodejs)
- nodeJs runs in single process (no threads!)
- non-blocking JS operation by default
- responsive behavior (not blocking CPU while waiting for responses)
- Node.js supports both the CommonJS and ES module systems (since Node.js v12), while in the browser we are starting to see the ES Modules standard being implemented. In practice, this means that you can use both `require()` and `import` in Node.js, while you are limited to `import` in the browser.
[NodeJS Standard Library API](https://nodejs.org/api/)
[NodeJS examples on GitHub](https://github.com/nodejs/examples)

## Asynchronous Programming

- [ ] [Asynchronous programming and callbacks (mdn web docs)](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Asynchronous/Introducing)
- [ ] [Timers](https://developer.mozilla.org/en-US/docs/Web/API/setTimeout)
- [ ] [Promises](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Using_promises)
- [ ] [Async and Await](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/async_function)
- [ ] [Closures](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Closures)
- [ ] [The Event Loop](https://developer.mozilla.org/en-US/docs/Web/JavaScript/EventLoop)

## Differences between Node.js and the Browser

https://nodejs.org/en/learn/getting-started/differences-between-nodejs-and-the-browser

> In the browser, most of the time what you are doing is interacting with the DOM, or other Web Platform APIs like Cookies. Those do not exist in Node.js, of course. You don't have the `document`, `window` and all the other objects that are provided by the browser. And in the browser, we don't have all the nice APIs that Node.js provides through its modules, like the filesystem access functionality.

## installing a nodeJS project

``` bash
cd path/to/project
npm install
```
*it will install everything the project needs (as indicated in package.json), in the `node_modules` folder, creating it if it's not existing already.*
## starting a server
``` JavaScript
const http = require('node:http');

const hostname = '127.0.0.1';
const port = 3000;

/* Whenever a new request is received, the request event is called, providing two objects: a request (an http.IncomingMessage object) and a response (an http.ServerResponse object). In this simple example, the request object is not used, but you could access the request headers and request data. */
const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World\n');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});
```

## express

*crud* = create, read, update, delete

``` javascript
server.get('/', (req, res) => { /* req=request, res=response */
...
})
```

- **nodemon**: app stays activated & refreshes when file is saved.
`npm install nodemon`
→ in `package.json` → `server: "nodemon index.js"`

**[routing](https://expressjs.com/en/starter/basic-routing.html)**:
_Routing_ refers to determining how an application responds to a client request to a particular endpoint, which is a URI (or path) and a specific HTTP request method (GET, POST, and so on).
```javascript
app.METHOD(PATH, HANDLER)
```

