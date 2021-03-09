#!/bin/sh
cat ../17-camelforth-b.d/pico-examples/build/camelforth-b/camelforth-b.uf2  > ./camelforth-b.uf2
md5sum ./camelforth-b.uf2 > ./camelforth-b.uf2.md5.txt
