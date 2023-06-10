# C-ITS Message Craft
Random C-ITS message generator.
Based on [vlm/asn1c](https://github.com/vlm/asn1c) - [mouse07410's fork](https://github.com/mouse07410/asn1c).

Currently supported types:
- CAM v1.4.1
- DENM v1.3.1

Currently supported encodings:
- XML
- JSON
- UPER
- OER
- BER
- DER

## Build
Using CMake/Make: `mkdir build && cd build && cmake .. && make`. Can then be installed with: `sudo make install`.

## Usage
Run `cits-mc -m msg-type -e encoding-type`.

## Playground
A WebAssembly version of this application can be tested out in [craft.v0-e.cc](https://craft.v0-e.cc).
