# C-ITS Message Craft
Random C-ITS message generator.
Based on [vlm/asn1c](https://github.com/vlm/asn1c).

Currently supported types:
- CAM v1.4.1
- DENM v.1.3.1

Currently supported encodings:
- XML
- JSON
- UPER
- OER

## Build
Using CMake/Make: `mkdir build && cd build && cmake .. && make`. Can then be installed with: `sudo make install`.

## Usage
Run `cits-mc -m msg-type -e encoding-type`.
