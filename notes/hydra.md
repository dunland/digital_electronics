pif camp workshop with blaŝ 2022-08-01

video modular synthesizers

https://hydra.ojack.xyz/

github.com/hydra-synth/hydra

**Documentation**: https://github.com/hydra-synth/hydra/blob/main/docs/funcs.md#functions

## use online!

## use with atom:

just look for `atom-hydra` package.

## offline usage

### Installation:
`git clone git@github.com:dunland/hydra.git`
`yarn install`
> error editorconfig@1.0.4: The engine "node" is incompatible with this module. Expected version ">=14". Got "12.22.9"
> error Found incompatible module.

`node --version`
>v12.22.9

**Upgrade using nvm:**
https://www.digitalocean.com/community/tutorials/how-to-install-node-js-on-ubuntu-20-04#option-3-installing-node-using-the-node-version-manager

``` bash
 2022  curl -sL https://deb.nodesource.com/setup_16.x -o /tmp/nodesource_setup.sh
 2023  nano /tmp/nodesource_setup.sh
 2024  sudo bash /tmp/nodesource_setup.sh
 2025  sudo apt install nodejs
```

> dpkg: error processing archive /var/cache/apt/archives/nodejs_16.20.2-deb-1nodes
ource1_amd64.deb (--unpack):
 trying to overwrite '/usr/include/node/common.gypi', which is also in package l
ibnode-dev 12.22.9~dfsg-1ubuntu3
dpkg-deb: error: paste subprocess was killed by signal (Broken pipe)
Errors were encountered while processing:
 /var/cache/apt/archives/nodejs_16.20.2-deb-1nodesource1_amd64.deb
E: Sub-process /usr/bin/dpkg returned an error code (1)

``` bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.3/install.sh | bash
source ~/.bashrc
nvm list-remote
nvm install v20.5.1
node --version
```
> v20.5.1

`yarn install` ✓

### Usage

- `yarn dev &`
- changes can be made in files `src` 
- bundle.js will be created automatically with `yarn dev`
- `yarn dev` does not have to be restarted! just **press ctrl+F5** in browser! (reload browser without cache)

### Serial messages

https://serialport.io/docs/guide-usage

``` bash
npm install serialport
yarn add serialport
```

``` javascript
const { SerialPort } = require('serialport') 
  
// Create a port  
const port = new SerialPort({  
path: '/dev/tty-usbserial1',  
baudRate: 57600,  
})
```

> Path must be a string. Received undefined
#### yarn bundles: 
https://yarnpkg.com/migration/guide#dont-use-bundledependencies

> The `bundleDependencies` field (or `bundledDependencies`) is an artifact of the past that used to let you define a set of packages that would be stored as-is within the package archive, `node_modules` and all. This feature has many problems:
> - It uses `node_modules`, which doesn't exist under Plug'n'Play installs.
> - It encodes the hoisting inside the package, messing with the hoisting from other packages.

