///////////////////// loading modules //////////////////////////////////
const path = require('path');
var pathObj = path.parse(__filename);
console.log(pathObj);

/* returns
{ root: '/',
  dir: '/home/dunland/github/digital_electronics/javaScript',
  base: 'index.js',
  ext: '.js',
  name: 'index' }
*/

/////////////////////////// Events ////////////////////////////////////
const EventEmitter = require('events');
const emitter = new EventEmitter();

// --------------------- Register a listener --------------------------

// ----- using arrow function:
emitter.on('messageLogged', (arg) => {
    console.log('Listener called', arg);
});

// ----- without arrow function:
emitter.on('messageLogged', function(arg){
    console.log('Listener called', arg);
});

// ------------------------ Raise an event ----------------------------
emitter.emit('messageLogged', {id:1 , url: 'http://'});


//////////////////////// accessing files //////////////////////////////
const {readFile, readFileSync} = require('fs');

// why does this not work?
const txt = readFileSync('./hello.txt', 'utf8', (err, txt) => {
    if (err) {
        console.log(`Error reading file from disk: ${err}`);
        console.error(err);
        return;
    }
    else
    {
        console.log("successfully read hello.txt! it says:");
        console.log(txt);
    }
});

// this works:
const file_sync = readFileSync('./hello.txt', 'utf8');
console.log(file_sync);

console.log('do this ASAP');

// --------------------------- csv ------------------------------------
var csvdata = require('fs').readFileSync('test.csv', 'utf8');

for (let i of csvdata) {
    console.log(i);
}

// --------------------------- json -----------------------------------
readFile("simulation_df.json", (err, data) =>
{
    if (err)
    {
        console.log(`Error reading file from disk: ${err}`);
    }
    else{
        const jsonData = JSON.parse(data);

        jsonData.foreach(db =>
            {
                console.log(`${db.name}: ${db.type}`);
            });
    }
});

var simulation_df = readFileSync("simulation_df.json", 'utf8');
var jsonData = JSON.parse(simulation_df);
console.log(jsonData);

while(1);