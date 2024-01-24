## Module import

See this beautifully explained descriptions from the [webmidi](https://github.com/djipco/webmidi) project:

#### Manual Install

Obviously, you can also install **WEBMIDI.js** the old-fashioned way by downloading the [latest release](https://github.com/djipco/webmidi/releases) packaged as a zip file. Uncompress the package, grab the `./dist/iife/webmidi.iife.js` file and copy it to your project. Link to it from your HTML page using a `<script>` tag as usual.

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