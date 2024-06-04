**[ES6](https://nodejs.org/en/learn/getting-started/ecmascript-2015-es6-and-beyond):** Ecma International standards for scripting language. ES6 (2015) was te biggest update made to the EcmaScript. ~= "Modern JavaScript"
**V8:** JavaScript engine, core of Google Chrome
 
## frameworks

- vue.js
- React.js

-------------------------------------------------

## Module import

See this beautifully explained de
scriptions from the [webmidi](https://github.com/djipco/webmidi) project:

#### Manual Install
	
> Obviously, you can also install **WEBMIDI.js** the old-fashioned way by downloading the [latest release](https://github.com/djipco/webmidi/releases) packaged as a zip file. Uncompress the package, grab the `./dist/iife/webmidi.iife.js` file and copy it to your project. Link to it from your HTML page using a `<script>` tag as usual.

https://nodejs.org/en/learn/getting-started/differences-between-nodejs-and-the-browser : 
> Node.js supports both the CommonJS and ES module systems (since Node.js v12), while in the browser we are starting to see the ES Modules standard being implemented. In practice, this means that you can use both `require()` and `import` in Node.js, while you are limited to `import` in the browser.

#### [NPM Install](https://github.com/djipco/webmidi/tree/develop#npm-install)

Arguably, the easiest approach is to install **WEBMIDI.js** with NPM (or Yarn). At the root of your project, simply issue the following command to perform the install:

```
npm install webmidi
```

Then, you can use any of those approaches depending on your environment:

```
// Script tag
<script src="node_modules/webmidi/dist/iife/webmidi.iife.js"></script>

// CommonJS require
const {WebMidi} = require("webmidi");

// ES module import in browser
import {WebMidi} from "node_modules/webmidi/dist/iife/webmidi.esm.js";

// ES module import in Node.js
import {WebMidi} from "webmidi";
```

------------------------------------------------------
## Modules

### Babel

> in Node.js you control the environment. Unless you are building an open source application that anyone can deploy anywhere, you know which version of Node.js you will run the application on. Compared to the browser environment, where you don't get the luxury to choose what browser your visitors will use, this is very convenient. This means that you can write all the modern ES2015+ JavaScript that your Node.js version supports. Since JavaScript moves so fast, but browsers can be a bit slow to upgrade, sometimes on the web you are stuck with using older JavaScript / ECMAScript releases. You can use Babel to transform your code to be ES5-compatible before shipping it to the browser.