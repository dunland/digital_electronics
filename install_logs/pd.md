# pure-data / purr-data

## osc

from http://write.flossmanuals.net/pure-data/osc/

`import mrpeach` enables osc


# libpd

siehe https://github.com/libpd/libpd/issues/338

und tu (nach einigem Hin und Her):

```
git clone --recurse-submodules https://github.com/libpd/libpd.git
cd libpd
git checkout master
git submodule update
make clean && make UTIL=true EXTRA=true
```